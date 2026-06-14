/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** AGate
*/

#include "Components/Gates/AGate.hpp"

nts::AGate::AGate(ComponentType type, std::function<Tristate(Tristate, Tristate)> elementaryLogicFunction) : AComponent(type), _elementaryLogicFunction(std::move(elementaryLogicFunction)) {}

nts::Tristate nts::AGate::computeComponent(std::size_t pin)
{
    switch (pin) {
        case 3:
            return computeGate(1, 2);
        case 4:
            return computeGate(5, 6);
        case 10:
            return computeGate(8, 9);
        case 11:
            return computeGate(12, 13);
        default:
            return nts::Tristate::Undefined;
    }
}

nts::Tristate nts::AGate::computeGate(std::size_t pinLeft, std::size_t pinRight)
{
    nts::Tristate left = getLinkedPin(pinLeft);
    nts::Tristate right = getLinkedPin(pinRight);
    return _elementaryLogicFunction(left, right);
}
