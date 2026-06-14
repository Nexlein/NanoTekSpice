/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** AElementary
*/

#include "Components/Elementary/AElementary.hpp"

#include <stdexcept>

nts::AElementary::AElementary(ComponentType type, std::function<Tristate(Tristate, Tristate)> elementaryLogicFunction) : AComponent(type), _elementaryLogicFunction(std::move(elementaryLogicFunction)) {}

nts::Tristate nts::AElementary::computeComponent(std::size_t pin)
{
    if (pin != 3)
        throw std::invalid_argument("AElementary: invalid pin number");
    nts::Tristate left = getLinkedPin(1);
    nts::Tristate right = getLinkedPin(2);
    return _elementaryLogicFunction(left, right);
}
