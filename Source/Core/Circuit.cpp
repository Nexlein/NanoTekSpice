#include "Core/Circuit.hpp"

#include <functional>
#include <stdexcept>
#include <string>

#include "Interface/AComponent.hpp"

#include "Components/Advanced/Advanced2716.hpp"
#include "Components/Advanced/Advanced4008.hpp"
#include "Components/Advanced/Advanced4013.hpp"
#include "Components/Advanced/Advanced4017.hpp"
#include "Components/Advanced/Advanced4040.hpp"
#include "Components/Advanced/Advanced4094.hpp"
#include "Components/Advanced/Advanced4512.hpp"
#include "Components/Advanced/Advanced4514.hpp"
#include "Components/Advanced/Advanced4801.hpp"
#include "Components/Elementary/AndComponent.hpp"
#include "Components/Elementary/NotComponent.hpp"
#include "Components/Elementary/OrComponent.hpp"
#include "Components/Elementary/XorComponent.hpp"
#include "Components/Gates/Gate4001.hpp"
#include "Components/Gates/Gate4011.hpp"
#include "Components/Gates/Gate4030.hpp"
#include "Components/Gates/Gate4069.hpp"
#include "Components/Gates/Gate4071.hpp"
#include "Components/Gates/Gate4081.hpp"
#include "Components/Special/ClockComponent.hpp"
#include "Components/Special/FalseComponent.hpp"
#include "Components/Special/InputComponent.hpp"
#include "Components/Special/OutputComponent.hpp"
#include "Components/Special/TrueComponent.hpp"
#include "Components/Advanced/LoggerComponent.hpp"

nts::Circuit::Circuit()
    : _components(), _links(), _tick(0), _areComponentsSorted(false)
{}

void nts::Circuit::addComponent(std::string type, std::string name)
{
    _components[name] = createComponent(type);
    AComponent* aComponent = dynamic_cast<AComponent*>(_components[name].get());
    if (aComponent) aComponent->setName(name);
    _areComponentsSorted = false;
}

void nts::Circuit::addLink(std::string link1, std::string link2)
{
    _links.insert({link1, link2});
}

void nts::Circuit::applyLinks()
{
    for (const auto& [first, second] : _links) {
        auto leftSep = first.find(':');
        auto rightSep = second.find(':');
        std::string leftComponent = first.substr(0, leftSep);
        size_t leftPin = std::stoul(first.substr(leftSep + 1));
        std::string rightComponent = second.substr(0, rightSep);
        size_t rightPin = std::stoul(second.substr(rightSep + 1));
        _components.at(leftComponent)
            ->setLink(leftPin, *_components.at(rightComponent), rightPin);
        AComponent* aComponentLeft = dynamic_cast<AComponent*>(_components.at(leftComponent).get());
        AComponent* aComponentRight = dynamic_cast<AComponent*>(_components.at(rightComponent).get());
        if (aComponentLeft && aComponentRight && !(aComponentRight->getType() == Advanced4801Type && aComponentLeft->getType() == OutputType))
            _components.at(rightComponent)->setLink(rightPin, *_components.at(leftComponent), leftPin);
    }
}

std::unique_ptr<nts::IComponent> nts::Circuit::createComponent(
    const std::string& type)
{
    static const std::unordered_map<
        std::string, std::function<std::unique_ptr<nts::IComponent>()>>
        componentFactory = {
            {"and", []() { return std::make_unique<AndComponent>(); }},
            {"not", []() { return std::make_unique<NotComponent>(); }},
            {"or", []() { return std::make_unique<OrComponent>(); }},
            {"xor", []() { return std::make_unique<XorComponent>(); }},
            {"input", []() { return std::make_unique<InputComponent>(); }},
            {"output", []() { return std::make_unique<OutputComponent>(); }},
            {"true", []() { return std::make_unique<TrueComponent>(); }},
            {"false", []() { return std::make_unique<FalseComponent>(); }},
            {"clock", []() { return std::make_unique<ClockComponent>(); }},
            {"4001", []() { return std::make_unique<Gate4001>(); }},
            {"4011", []() { return std::make_unique<Gate4011>(); }},
            {"4030", []() { return std::make_unique<Gate4030>(); }},
            {"4069", []() { return std::make_unique<Gate4069>(); }},
            {"4071", []() { return std::make_unique<Gate4071>(); }},
            {"4081", []() { return std::make_unique<Gate4081>(); }},
            {"4008", []() { return std::make_unique<Advanced4008>(); }},
            {"4013", []() { return std::make_unique<Advanced4013>(); }},
            {"4017", []() { return std::make_unique<Advanced4017>(); }},
            {"4040", []() { return std::make_unique<Advanced4040>(); }},
            {"4094", []() { return std::make_unique<Advanced4094>(); }},
            {"4512", []() { return std::make_unique<Advanced4512>(); }},
            {"4514", []() { return std::make_unique<Advanced4514>(); }},
            {"4801", []() { return std::make_unique<Advanced4801>(); }},
            {"2716", []() { return std::make_unique<Advanced2716>(); }},
            {"logger", []() { return std::make_unique<LoggerComponent>(); }}
        };

    auto it = componentFactory.find(type);
    if (it != componentFactory.end()) return it->second();
    throw std::invalid_argument("Invalid component type: " + type);
}

/// @brief Returns a const reference to the internal map of components.
/// @return A const reference unordered_map: [component name, unique pointer to
/// component]
const std::unordered_map<std::string, std::unique_ptr<nts::IComponent>>&
nts::Circuit::getComponents() const
{
    return _components;
}

/// @brief Returns a map of components of a specific type.
/// @param searchedType The component type to search for.
/// @return A map of component names and pointers to components of the specified
/// type.
std::map<std::string, nts::IComponent*> nts::Circuit::getComponentsByType(
    ComponentType searchedType) const
{
    std::map<std::string, IComponent*> result;

    for (const auto& [name, component] : _components) {
        AComponent* aComponent = dynamic_cast<AComponent*>(component.get());
        if (aComponent && aComponent->getType() == searchedType)
            result[name] = component.get();
    }
    return result;
}

/// @brief Returns the current tick count.
/// @return The current tick count.
size_t nts::Circuit::getTick() const { return _tick; }

/// @brief Simulates a tick of the circuit.
void nts::Circuit::simulate()
{
    if (!_areComponentsSorted) {
        _inputs.clear();
        _outputs.clear();
        _others.clear();
        for (auto& [name, component] : _components) {

            AComponent* aComponent = dynamic_cast<AComponent*>(component.get());
            if (!aComponent) continue;

            ComponentType type = aComponent->getType();
            switch (type) {
                case ComponentType::InputType:
                case ComponentType::ClockType:
                    _inputs.push_back(component.get());
                    break;
                case ComponentType::OutputType:
                    _outputs.push_back(component.get());
                    break;
                default:
                    _others.push_back(component.get());
                    break;
            }
        }
        _areComponentsSorted = true;
    }

    for (IComponent* component : _inputs) component->simulate(_tick);
    for (IComponent* component : _others) component->simulate(_tick);
    for (IComponent* component : _outputs) component->simulate(_tick);

    _tick++;
}
