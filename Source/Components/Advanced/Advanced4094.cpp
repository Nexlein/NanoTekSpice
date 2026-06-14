/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** Advanced4094
*/

#include "Components/Advanced/Advanced4094.hpp"

nts::Advanced4094::Advanced4094()
    : AComponent(ComponentType::Advanced4094Type),
      _outQs(Undefined),
      _outQe(Undefined),
      _oldClock(Undefined),
      _currentTick(0),
      _isComputed(false)
{
    for (int i = 0; i < 8; i++) {
        _shiftReg[i] = Undefined;
        _savedValues[i] = Undefined;
    }
}

void nts::Advanced4094::simulate(std::size_t tick)
{
    _currentTick = tick;
    _isComputed = false;
}

nts::Tristate nts::Advanced4094::computeComponent(std::size_t pin)
{
    shiftRegister();

    Tristate outputEnable = getLinkedPin(15);

    if (pin == 9) return _outQs;
    if (pin == 10) return _outQe;

    if (outputEnable != True) return Undefined;

    switch (pin) {
        case 4: return _savedValues[0];
        case 5: return _savedValues[1];
        case 6: return _savedValues[2];
        case 7: return _savedValues[3];
        case 14: return _savedValues[4];
        case 13: return _savedValues[5];
        case 12: return _savedValues[6];
        case 11: return _savedValues[7];
        default: return Undefined;
    }
}

void nts::Advanced4094::shiftRegister()
{
    if (_isComputed) return;

    Tristate strobe = getLinkedPin(1);
    Tristate data = getLinkedPin(2);
    Tristate clock = getLinkedPin(3);

    bool risingEdge = (_oldClock == False && clock == True);
    bool fallingEdge = (_oldClock == True && clock == False);

    if (risingEdge) {
        for (int i = 7; i > 0; --i) _shiftReg[i] = _shiftReg[i - 1];
        _shiftReg[0] = data;
        _outQs = _shiftReg[7];
    }

    if (fallingEdge) _outQe = _shiftReg[7];

    _oldClock = clock;
    if (strobe == True)
        for (int i = 0; i < 8; ++i) _savedValues[i] = _shiftReg[i];
    _isComputed = true;
}
