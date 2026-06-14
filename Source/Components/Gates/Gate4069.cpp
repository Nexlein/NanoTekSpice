/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** Gate4069
*/

#include "Components/Gates/Gate4069.hpp"

#include "Tools/ElementaryLogic.hpp"

nts::Gate4069::Gate4069() : AComponent(ComponentType::Gate4069Type) {}

nts::Tristate nts::Gate4069::computeComponent(std::size_t pin)
{
    switch (pin) {
        case 2:
            return computeNot(1);
        case 4:
            return computeNot(3);
        case 6:
            return computeNot(5);
        case 8:
            return computeNot(9);
        case 10:
            return computeNot(11);
        case 12:
            return computeNot(13);
        default:
            return nts::Tristate::Undefined;
    }
}

nts::Tristate nts::Gate4069::computeNot(std::size_t inputPin)
{
    return nts::ElementaryLogic::notGate(getLinkedPin(inputPin));
}
