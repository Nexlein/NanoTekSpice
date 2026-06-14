/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** ElementaryLogic
*/

#include "Tools/ElementaryLogic.hpp"

nts::Tristate nts::ElementaryLogic::andGate(nts::Tristate a, nts::Tristate b)
{
    if (a == False || b == False) return False;
    if (a == Undefined || b == Undefined) return Undefined;
    return True;
}

nts::Tristate nts::ElementaryLogic::orGate(nts::Tristate a, nts::Tristate b)
{
    if (a == True || b == True) return True;
    if (a == Undefined || b == Undefined) return Undefined;
    return False;
}

nts::Tristate nts::ElementaryLogic::xorGate(nts::Tristate a, nts::Tristate b)
{
    if (a == Undefined || b == Undefined) return Undefined;
    return (a != b) ? True : False;
}

nts::Tristate nts::ElementaryLogic::notGate(nts::Tristate a)
{
    if (a == True) return False;
    if (a == False) return True;
    return Undefined;
}

nts::Tristate nts::ElementaryLogic::nandGate(nts::Tristate a, nts::Tristate b)
{
    return notGate(andGate(a, b));
}

nts::Tristate nts::ElementaryLogic::norGate(nts::Tristate a, nts::Tristate b)
{
    return notGate(orGate(a, b));
}

nts::Tristate nts::ElementaryLogic::bitAdder(nts::Tristate a, nts::Tristate b, nts::Tristate& c_in)
{
    int sum = a + b + c_in;
    switch (sum) {
    case 0:
        c_in = False;
        return False;
    case 1:
        c_in = False;
        return True;
    case 2:
        c_in = True;
        return False;
    case 3:
        c_in = True;
        return True;
    default: return Undefined;
    }
}
