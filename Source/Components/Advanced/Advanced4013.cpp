/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Advanced4013
*/

#include "Components/Advanced/Advanced4013.hpp"
#include "Components/Special/ASpecial.hpp"

nts::Advanced4013::Advanced4013()
    : AComponent(ComponentType::Advanced4013Type),
    _currentTick(0),
    _risingEdgeTick1(-1),
    _risingEdgeTick2(-1)
{
    for (int i = 0; i < 2; i++) {
        _out1[i] = False;
        _out2[i] = False;
    }
}

void nts::Advanced4013::simulate(std::size_t tick) { _currentTick = tick; }

nts::Tristate nts::Advanced4013::computeComponent(std::size_t pin)
{
    if (pin == 1 || pin == 2)
        return computeFlipFlop1(5, 6, 4, 3, pin);
    else if (pin == 13 || pin == 12)
        return computeFlipFlop2(9, 8, 10, 11, pin);
    return Undefined;
}

bool nts::Advanced4013::isRisingEdge(size_t clockPin, Tristate set, Tristate reset, int& risingEdgeTick)
{
    const auto& clockIt = _links.find(clockPin);
    if (clockIt == _links.end()) return false;

    ASpecial* clock = dynamic_cast<ASpecial*>(clockIt->second.first);
    if (!clock) return false;

    if (clock->getValue() == False && clock->getNextValue() == True)
        risingEdgeTick = _currentTick + 1;
    else if (clock->getValue() == True
            && _currentTick == risingEdgeTick
            && set != True && reset != True) {
                risingEdgeTick = -1;
                return true;
    }
    return false;
}

nts::Tristate nts::Advanced4013::computeFlipFlop1(size_t dataPin, size_t setPin, size_t resetPin, size_t clockPin, size_t outputPin)
{
    Tristate data = getLinkedPin(dataPin);
    Tristate set = getLinkedPin(setPin);
    Tristate reset = getLinkedPin(resetPin);


    if (set == True && reset == True) _out1[0] = _out1[1] = True;
    else if (set == True) {
        _out1[0] = True;
        _out1[1] = False;
    } else if (reset == True) {
        _out1[0] = False;
        _out1[1] = True;
    } else if (set != True && reset != True && isRisingEdge(clockPin, set, reset, _risingEdgeTick1)) {
        _out1[0] = data;
        _out1[1] = (data == True) ? False : True;
    }
    return outputPin == 1 ? _out1[0] : _out1[1];
}

nts::Tristate nts::Advanced4013::computeFlipFlop2(size_t dataPin, size_t setPin, size_t resetPin, size_t clockPin, size_t outputPin)
{
    Tristate data = getLinkedPin(dataPin);
    Tristate set = getLinkedPin(setPin);
    Tristate reset = getLinkedPin(resetPin);


    if (set == True && reset == True) _out2[0] = _out2[1] = True;
    else if (set == True) {
        _out2[0] = True;
        _out2[1] = False;
    } else if (reset == True) {
        _out2[0] = False;
        _out2[1] = True;
    } else if (set != True && reset != True && isRisingEdge(clockPin, set, reset, _risingEdgeTick2)) {
        _out2[0] = data;
        _out2[1] = (data == True) ? False : True;
    }
    return outputPin == 13 ? _out2[0] : _out2[1];
}