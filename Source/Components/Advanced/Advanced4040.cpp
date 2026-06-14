/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Advanced4040
*/

#include "Components/Advanced/Advanced4040.hpp"

nts::Advanced4040::Advanced4040()
    : AComponent(ComponentType::Advanced4040Type),
      _counter(0),
      _lastClock(Undefined)
{
    for (int i = 0; i < 12; i++) _out[i] = False;
}

void nts::Advanced4040::simulate([[maybe_unused]] std::size_t tick)
{
    Tristate clock = getLinkedPin(10);
    Tristate reset = getLinkedPin(11);

    if (isFallingEdge(clock, _lastClock)) {
        _counter++;
        if (_counter >= 4096)
            _counter = 0;
    }

    if (reset == True) _counter = 0;

    _lastClock = clock;

    for (int i = 0; i < 12; i++) {
        bool isBitSet = (_counter & (1 << i));
        _out[i] = isBitSet ? True : False;
    }
}

nts::Tristate nts::Advanced4040::computeComponent(std::size_t pin)
{
    return returnManage(pin);
}

bool nts::Advanced4040::isFallingEdge(Tristate clock, Tristate lastClock)
{
    return (lastClock == True && clock == False);
}

nts::Tristate nts::Advanced4040::returnManage(size_t pin)
{
    switch (pin) {
        case 9:  return _out[0];
        case 7:  return _out[1];
        case 6:  return _out[2];
        case 5:  return _out[3];
        case 3:  return _out[4];
        case 2:  return _out[5];
        case 4:  return _out[6];
        case 13: return _out[7];
        case 12: return _out[8];
        case 14: return _out[9];
        case 15: return _out[10];
        case 1:  return _out[11];
        default: return Undefined;
    }
}
