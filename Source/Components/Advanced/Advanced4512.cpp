/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** Advanced4512
*/

#include "Components/Advanced/Advanced4512.hpp"

nts::Advanced4512::Advanced4512()
    : AComponent(ComponentType::Advanced4512Type),
      _isComputed(false),
      _output(Tristate::Undefined),
      _data{1, 2, 3, 4, 5, 6, 7, 9}
{}

void nts::Advanced4512::simulate([[maybe_unused]] std::size_t tick)
{
    _isComputed = false;
}

nts::Tristate nts::Advanced4512::computeComponent(std::size_t pin)
{
    if (pin != 14) return getLinkedPin(pin);

    if (!_isComputed) {
        updateOutput();
        _isComputed = true;
    }

    return _output;
}

void nts::Advanced4512::updateOutput()
{
    Tristate enablePin15 = getLinkedPin(15);

    if (enablePin15 == Tristate::Undefined) {
        _output = Tristate::Undefined;
        return;
    }
    if (enablePin15 == Tristate::True) {
        _output = Tristate::Undefined;
        return;
    }

    Tristate inhibitPin10 = getLinkedPin(10);

    if (inhibitPin10 == Tristate::Undefined) {
        _output = Tristate::Undefined;
        return;
    }
    if (inhibitPin10 == Tristate::True) {
        _output = Tristate::False;
        return;
    }

    Tristate aPin11 = getLinkedPin(11);
    Tristate bPin12 = getLinkedPin(12);
    Tristate cPin13 = getLinkedPin(13);

    if (aPin11 == Tristate::Undefined || bPin12 == Tristate::Undefined ||
        cPin13 == Tristate::Undefined) {
        _output = Tristate::Undefined;
        return;
    }

    int pinSelector = (aPin11 == Tristate::True ? 1 : 0) +
                      (bPin12 == Tristate::True ? 2 : 0) +
                      (cPin13 == Tristate::True ? 4 : 0);

    _output = getLinkedPin(_data[pinSelector]);
}
