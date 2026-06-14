/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** ASpecial
*/

#include "Components/Special/ASpecial.hpp"

nts::ASpecial::ASpecial(ComponentType type)
    : AComponent(type),
      _value(Tristate::Undefined),
      _nextValue(Tristate::Undefined),
      _hasAssignation(false)
{}

// Setters
void nts::ASpecial::setValue(Tristate value) { _value = value; }
void nts::ASpecial::setNextValue(Tristate value)
{
    _nextValue = value;
    _hasAssignation = true;
}

// Getters
nts::Tristate nts::ASpecial::getValue() const { return _value; }
nts::Tristate nts::ASpecial::getNextValue() const { return _nextValue; }

bool nts::ASpecial::updateValue()
{
    if (!_hasAssignation) return false;
    _value = _nextValue;
    _hasAssignation = false;
    return true;
}
