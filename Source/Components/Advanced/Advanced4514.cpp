/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Advanced4514
*/

#include "Components/Advanced/Advanced4514.hpp"

nts::Advanced4514::Advanced4514()
    : AComponent(ComponentType::Advanced4514Type), _isComputed(false)
{
    for (int i = 0; i < 4; i++) _in[i] = Undefined;
    for (int i = 0; i < 16; i++) _out[i] = Undefined;
}

void nts::Advanced4514::simulate([[maybe_unused]] std::size_t tick)
{
    _isComputed = false;
}

nts::Tristate nts::Advanced4514::computeComponent(std::size_t pin)
{
    if (!_isComputed) {
        Tristate inhibit = getLinkedPin(23);
        Tristate in[4];

        strobeManage(in);

        if (inhibit == True)
            for (int i = 0; i < 16; i++) _out[i] = False;
        else if (inhibit == Undefined)
            for (int i = 0; i < 16; i++) _out[i] = Undefined;
        else {
            if (in[0] == Undefined || in[1] == Undefined || in[2] == Undefined || in[3] == Undefined) {
                for (int i = 0; i < 16; i++) _out[i] = Undefined;
            } else {
                int decoded = in[0] * 1 + in[1] * 2 + in[2] * 4 + in[3] * 8;
                for (int i = 0; i < 16; i++) _out[i] = (i == decoded) ? True : False;
            }
        }
        _isComputed = true;
    }
    return returnManage(pin);
}

void nts::Advanced4514::strobeManage(Tristate in[])
{
    Tristate strobe = getLinkedPin(1);

    if (strobe == True) {
        in[0] = getLinkedPin(2);
        in[1] = getLinkedPin(3);
        in[2] = getLinkedPin(21);
        in[3] = getLinkedPin(22);
        for (int i = 0; i < 4; i++) _in[i] = in[i];
    } else if (strobe == False) {
        for (int i = 0; i < 4; i++) in[i] = _in[i];
    } else {
        for (int i = 0; i < 4; i++) {
            in[i] = Undefined;
            _in[i] = Undefined;
        }
    }
}

nts::Tristate nts::Advanced4514::returnManage(size_t pin)
{
    switch (pin) {
        case 11:    return _out[0];
        case 9:     return _out[1];
        case 10:    return _out[2];
        case 8:     return _out[3];
        case 7:     return _out[4];
        case 6:     return _out[5];
        case 5:     return _out[6];
        case 4:     return _out[7];
        case 18:    return _out[8];
        case 17:    return _out[9];
        case 20:    return _out[10];
        case 19:    return _out[11];
        case 14:    return _out[12];
        case 13:    return _out[13];
        case 16:    return _out[14];
        case 15:    return _out[15];
        default:    return Undefined;
    }
}
