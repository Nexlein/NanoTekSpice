/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** ClockComponent
*/

#include "Components/Special/ClockComponent.hpp"

nts::ClockComponent::ClockComponent() : ASpecial(ComponentType::ClockType) {}

nts::Tristate nts::ClockComponent::computeComponent([[maybe_unused]] std::size_t pin)
{
    return _value;
}

void nts::ClockComponent::simulate([[maybe_unused]] std::size_t tick)
{
    if (!updateValue()) switchClock();

    if (_value == Tristate::True)
        _nextValue = Tristate::False;
    else if (_value == Tristate::False)
        _nextValue = Tristate::True;
    else
        _nextValue = Tristate::Undefined;
}

void nts::ClockComponent::switchClock()
{
    if (_value == Tristate::Undefined) return;
    _value = (_value == Tristate::True) ? Tristate::False : Tristate::True;
}
