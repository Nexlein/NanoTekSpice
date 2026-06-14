/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Advanced4017
*/

#include "Components/Advanced/Advanced4017.hpp"

nts::Advanced4017::Advanced4017()
    : AComponent(ComponentType::Advanced4017Type),
    _outSpecial(False),
    _state(0),
    _lastClock0(Undefined),
    _lastClock1(Undefined)
{
    for (int i = 0; i < 10; i++) _out[i] = False;
    _out[0] = True;
    _outSpecial = True;
}

void nts::Advanced4017::simulate([[maybe_unused]] std::size_t tick)
{
    Tristate clock0 = getLinkedPin(14);
    Tristate clock1 = getLinkedPin(13);
    Tristate mr = getLinkedPin(15);

    if (mr == True) _state = 0;
    else {
        if (isRisingEdge(clock0, _lastClock0) && clock1 == False)
            _state = (_state + 1) % 10;
        else if (isFallingEdge(clock1, _lastClock1) && clock0 == True)
            _state = (_state + 1) % 10;
    }

    _lastClock0 = clock0;
    _lastClock1 = clock1;

    for (int i = 0; i < 10; i++) _out[i] = (i == _state) ? True : False;
    _outSpecial = (_state < 5) ? True : False;
}

nts::Tristate nts::Advanced4017::computeComponent(std::size_t pin)
{
    return returnManage(pin);
}

bool nts::Advanced4017::isRisingEdge(Tristate clock, Tristate lastClock)
{
    return (lastClock == False && clock == True);
}

bool nts::Advanced4017::isFallingEdge(Tristate clock, Tristate lastClock)
{
    return (lastClock == True && clock == False);
}

nts::Tristate nts::Advanced4017::returnManage(size_t pin)
{
    switch (pin) {
        case 3:  return _out[0];
        case 2:  return _out[1];
        case 4:  return _out[2];
        case 7:  return _out[3];
        case 10: return _out[4];
        case 1:  return _out[5];
        case 5:  return _out[6];
        case 6:  return _out[7];
        case 9:  return _out[8];
        case 11: return _out[9];
        case 12: return _outSpecial;
        default: return Undefined;
    }
}
