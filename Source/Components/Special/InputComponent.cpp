/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** InputComponent
*/

#include "Components/Special/InputComponent.hpp"

nts::InputComponent::InputComponent() : ASpecial(ComponentType::InputType) {}

nts::Tristate nts::InputComponent::computeComponent([[maybe_unused]] std::size_t pin)
{
    return _value;
}

void nts::InputComponent::simulate([[maybe_unused]] std::size_t tick)
{
    updateValue();
    _nextValue = _value;
}
