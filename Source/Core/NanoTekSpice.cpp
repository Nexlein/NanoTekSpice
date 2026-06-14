/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** NanoTekSpice
*/

#include "Core/NanoTekSpice.hpp"

#include <csignal>
#include <functional>
#include <iostream>
#include <map>

#include "Core/Circuit.hpp"
#include "Interface/AComponent.hpp"
#include "Components/Special/ASpecial.hpp"
#include "Components/Special/OutputComponent.hpp"

static bool isLoopRunning = false;

static void signalHandler([[maybe_unused]] int sigId) { isLoopRunning = false; }

nts::NanoTekSpice::NanoTekSpice(Circuit circuit) : _circuit(std::move(circuit))
{
}

/// @brief Processes user input in a loop until the user exits.
void nts::NanoTekSpice::processUserInput()
{
    std::string userInput;

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, userInput)) break;
        if (userInput.empty()) continue;
        if (userInput == "exit") break;
        handleUserInput(userInput);
    }
}

/// @brief Handles user input commands.
/// @param input The user input string to process.
void nts::NanoTekSpice::handleUserInput(const std::string& input)
{
    static const std::unordered_map<std::string, std::function<void()>>
        userCommand = {{"display", [this]() { return display(); }},
                       {"simulate", [this]() { return simulate(); }},
                       {"loop", [this]() { return loop(); }},
                       {"links", [this]() { return links(); }}};

    auto commandIt = userCommand.find(input);
    if (commandIt != userCommand.end())
        commandIt->second();
    else if (input.find('=') != std::string::npos)
        handleAssignation(input);
    else
        std::cerr << "handleUserInput: Unknown command: " << input << std::endl;
}

/// @brief Handles assignation commands (to set input or clock values).
/// @param input The input string containing the assignment command.
void nts::NanoTekSpice::handleAssignation(const std::string& input)
{
    std::size_t eqPos = input.find('=');
    std::string inputName = input.substr(0, eqPos);
    std::string value = input.substr(eqPos + 1);
    Tristate state;

    if (value == "0")
        state = Tristate::False;
    else if (value == "1")
        state = Tristate::True;
    else if (value == "U" || value == "u")
        state = Tristate::Undefined;
    else {
        std::cout << "handleAssignation: Invalid value : " << value
                  << std::endl;
        return;
    }

    const auto& allComponents = _circuit.getComponents();
    auto componentIt = allComponents.find(inputName);
    if (componentIt == allComponents.end()) {
        std::cout << "handleAssignation: Component not found : " << inputName
                  << std::endl;
        return;
    }

    IComponent* componentToAssign = componentIt->second.get();

    AComponent* aComponent = dynamic_cast<AComponent*>(componentToAssign);
    if (!aComponent) return;

    ComponentType type = aComponent->getType();
    if (type == ComponentType::InputType || type == ComponentType::ClockType) {
        ASpecial* aSpecial = dynamic_cast<ASpecial*>(aComponent);
        if (aSpecial) aSpecial->setNextValue(state);
        return;
    }
    std::cout << "handleAssignation: Impossible on " << inputName << std::endl;
}

/// @brief display command (Displays the current state of the circuit).
void nts::NanoTekSpice::display() const
{
    std::unordered_map<Tristate, std::string> stateToString = {
        {Tristate::Undefined, "U"},
        {Tristate::True, "1"},
        {Tristate::False, "0"}};

    std::map<std::string, Tristate> allInputs;
    for (const auto& [name, component] : _circuit.getComponentsByType(ComponentType::InputType)) {
        ASpecial* aSpecial = dynamic_cast<ASpecial*>(component);
        if (aSpecial) allInputs[name] = aSpecial->getValue();
    }
    for (const auto& [name, component] : _circuit.getComponentsByType(ComponentType::ClockType)) {
        ASpecial* aSpecial = dynamic_cast<ASpecial*>(component);
        if (aSpecial) allInputs[name] = aSpecial->getValue();
    }

    std::cout << "tick: " << _circuit.getTick() << std::endl;

    std::cout << "input(s):" << std::endl;
    for (const auto& [name, value] : allInputs)
        std::cout << "  " << name << ": " << stateToString[value] << std::endl;

    std::cout << "output(s):" << std::endl;
    for (const auto& [name, component] : _circuit.getComponentsByType(ComponentType::OutputType)) {
        OutputComponent* output = dynamic_cast<OutputComponent*>(component);
        if (output)
            std::cout << "  " << name << ": " << stateToString[output->getValue()] << std::endl;
    }
}

/// @brief loop command (Starts an infinite loop (simulate and display)).
void nts::NanoTekSpice::loop()
{
    isLoopRunning = true;
    std::signal(SIGINT, signalHandler);
    while (isLoopRunning) {
        simulate();
        display();
    }
    std::signal(SIGINT, SIG_DFL);
}

void nts::NanoTekSpice::simulate() { _circuit.simulate(); }

void nts::NanoTekSpice::links()
{
    const std::unordered_map<ComponentType, std::string> typeNames = {
        {ComponentType::InputType, "Input"},
        {ComponentType::ClockType, "Clock"},
        {ComponentType::OutputType, "Output"},
        {ComponentType::TrueType, "True"},
        {ComponentType::FalseType, "False"},
        {ComponentType::AndType, "And"},
        {ComponentType::OrType, "Or"},
        {ComponentType::NotType, "Not"},
        {ComponentType::XorType, "Xor"},
        {ComponentType::Gate4001Type, "4001_NOR"},
        {ComponentType::Gate4011Type, "4011_NAND"},
        {ComponentType::Gate4030Type, "4030_XOR"},
        {ComponentType::Gate4069Type, "4069_NOT"},
        {ComponentType::Gate4071Type, "4071_OR"},
        {ComponentType::Gate4081Type, "4081_AND"},
        {ComponentType::Advanced4008Type, "4008_Adder"},
        {ComponentType::Advanced4013Type, "4013_FlipFlop"},
        {ComponentType::Advanced4017Type, "4017_Johnson"},
        {ComponentType::Advanced4040Type, "4040_Counter"},
        {ComponentType::Advanced4094Type, "4094_Shift_Register"},
        {ComponentType::Advanced4512Type, "4512_Data_Selector"},
        {ComponentType::Advanced4514Type, "4514_Decoder"},
        {ComponentType::Advanced4801Type, "4801_Ram"},
        {ComponentType::UnknowType, "Unknown"}
    };

    for (const auto& [name, component] : _circuit.getComponents()) {

        AComponent* aComponent = dynamic_cast<AComponent*>(component.get());
        if (!aComponent) continue;

        std::cout << "Component: " << name << " ("
                  << typeNames.at(aComponent->getType()) << ")"
                  << std::endl;
        for (const auto& [pinNumber, link] : aComponent->getLinks()) {
            AComponent* linkedComp = dynamic_cast<AComponent*>(link.first);
            if (!linkedComp) continue;
            std::cout << "  Pin " << pinNumber << " -> "
                      << (linkedComp ? linkedComp->getName() : "Unknown") << " (Pin " << link.second << ")"
                      << std::endl;
        }
    }
}
