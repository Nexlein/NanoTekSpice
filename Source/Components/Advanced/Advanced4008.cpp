/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Advanced4008
*/

#include "Components/Advanced/Advanced4008.hpp"

#include "Tools/ElementaryLogic.hpp"

nts::Advanced4008::Advanced4008() : AComponent(ComponentType::Advanced4008Type), _computed(false) {}

void nts::Advanced4008::simulate([[maybe_unused]] std::size_t tick) { _computed = false; }

nts::Tristate nts::Advanced4008::computeComponent(std::size_t pin)
{
    if (!_computed) {
        computeAllBits();
        _computed = true;
    }

    switch (pin) {
        case 10: return _out0;
        case 11: return _out1;
        case 12: return _out2;
        case 13: return _out3;
        case 14: return _outC;
        default: return Undefined;
    }
}

void nts::Advanced4008::computeAllBits()
{
    Tristate a1 = getLinkedPin(7);
    Tristate b1 = getLinkedPin(6);
    Tristate a2 = getLinkedPin(5);
    Tristate b2 = getLinkedPin(4);
    Tristate a3 = getLinkedPin(3);
    Tristate b3 = getLinkedPin(2);
    Tristate a4 = getLinkedPin(1);
    Tristate b4 = getLinkedPin(15);

    Tristate carry = getLinkedPin(9);

    if (carry == Undefined) carry = False;

    if (a1 == Undefined || b1 == Undefined || a2 == Undefined ||
        b2 == Undefined || a3 == Undefined || b3 == Undefined ||
        a4 == Undefined || b4 == Undefined) {
        _out0 = _out1 = _out2 = _out3 = _outC = Undefined;
        return;
    }

    _out0 = ElementaryLogic::bitAdder(a1, b1, carry);
    _out1 = ElementaryLogic::bitAdder(a2, b2, carry);
    _out2 = ElementaryLogic::bitAdder(a3, b3, carry);
    _out3 = ElementaryLogic::bitAdder(a4, b4, carry);
    _outC = carry;
}
