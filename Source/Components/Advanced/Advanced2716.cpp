/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** Advanced2716
*/

#include "Components/Advanced/Advanced2716.hpp"

#include <fstream>

nts::Advanced2716::Advanced2716()
    : AComponent(ComponentType::Advanced2716Type), _computed(false)
{
    std::ifstream file("./rom.bin", std::ios::binary);

    file.read(reinterpret_cast<char*>(&_memory), sizeof(_memory));
}

void nts::Advanced2716::simulate([[maybe_unused]] std::size_t tick)
{
    _computed = false;
    _enable = true;
}

nts::Tristate nts::Advanced2716::computeComponent([[maybe_unused]] std::size_t pin)
{
    if (!_computed) {
        Tristate enable = getLinkedPin(18);
        Tristate read = getLinkedPin(20);

        if (enable == False && read == False) {
            Tristate addr[11] = {
                getLinkedPin(8), getLinkedPin(7), getLinkedPin(6), getLinkedPin(5),
                getLinkedPin(4), getLinkedPin(3), getLinkedPin(2), getLinkedPin(1),
                getLinkedPin(23), getLinkedPin(22), getLinkedPin(19)
            };
            int address = 0;
            int power = 1;
            int data = 0;

            _enable = true;
            for (int i = 0; i < 11; i++) {
                address += addr[i] * power;
                power *= 2;
            }
            data = _memory[address];
            for (int i = 0; i < 8; i++ )
                _output[i] = (data & (1 << i)) ? True : False;
        } else
            _enable = false;
        _computed = true;
    }
    return returnManage(pin);
}

nts::Tristate nts::Advanced2716::returnManage(size_t pin)
{
    if (!_enable) return Undefined;

    switch (pin) {
        case 9:     return _output[0];
        case 10:    return _output[1];
        case 11:    return _output[2];
        case 13:    return _output[3];
        case 14:    return _output[4];
        case 15:    return _output[5];
        case 16:    return _output[6];
        case 17:    return _output[7];
        default: return Undefined;
    }
}
