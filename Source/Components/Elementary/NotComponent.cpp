/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** NotComponent
*/

#include "Components/Elementary/NotComponent.hpp"

#include <stdexcept>

#include "Tools/ElementaryLogic.hpp"

nts::NotComponent::NotComponent() : AComponent(ComponentType::NotType) {}

nts::Tristate nts::NotComponent::computeComponent(std::size_t pin)
{
    if (pin != 2)
        throw std::invalid_argument("NotComponent: invalid pin number");
    return nts::ElementaryLogic::notGate(getLinkedPin(1));
}
