/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** LoggerComponent
*/

#include "Components/Advanced/LoggerComponent.hpp"

nts::LoggerComponent::LoggerComponent()
    : AComponent(ComponentType::LoggerType), _lastClock(Tristate::Undefined)
{}

nts::Tristate nts::LoggerComponent::computeComponent([[maybe_unused]] std::size_t pin)
{
    return nts::Tristate::Undefined;
}

void nts::LoggerComponent::simulate([[maybe_unused]] std::size_t tick)
{
    nts::Tristate currentValue = getLinkedPin(9);
    nts::Tristate inhibit = getLinkedPin(10);

    if (_lastClock == nts::Tristate::False &&
        currentValue == nts::Tristate::True &&
        inhibit == nts::Tristate::False) {
        unsigned char character = 0;
        bool isValid = true;

        for (std::size_t i = 1; i <= 8; ++i) {
            nts::Tristate bitState = getLinkedPin(i);

            if (bitState == nts::Tristate::Undefined) {
                isValid = false;
                break;
            }

            if (bitState == nts::Tristate::True) character |= (1 << (i - 1));
        }

        if (isValid) {
            std::ofstream logFile("./log.bin", std::ios_base::app);
            if (logFile.is_open()) {
                logFile.put(character);
                logFile.close();
            }
        }
    }

    _lastClock = currentValue;
}