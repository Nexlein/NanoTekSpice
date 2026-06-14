/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** Advanced4801
*/

#include "Components/Advanced/Advanced4801.hpp"

nts::Advanced4801::Advanced4801()
    : AComponent(ComponentType::Advanced4801Type),
    _idle(false),
    _read(false),
    _data(0),
    _address(0)
{
    for (int i = 0; i < 1024; i++)
        _memory[i] = Undefined;
}

void nts::Advanced4801::simulate([[maybe_unused]] std::size_t tick)
{
    Tristate read = getLinkedPin(20);
    Tristate enable = getLinkedPin(18);
    Tristate write = getLinkedPin(21);

    if (enable != True || (write == True && read == True)) _idle = true;
    else if (write == True) {
        getInput();
        writeInput();
    } else if (read == True) {
        getAddress();
        readData();
    }
}

nts::Tristate nts::Advanced4801::computeComponent([[maybe_unused]] std::size_t pin)
{
    return returnManage(pin);
}

void nts::Advanced4801::getInput()
{
    int power = 1;
    Tristate input[8] = {
        getLinkedPin(9), getLinkedPin(10), getLinkedPin(11),
        getLinkedPin(13), getLinkedPin(14), getLinkedPin(15),
        getLinkedPin(16), getLinkedPin(17)
    };

    _data = 0;
    for (int i = 0; i < 8; i++) {
        _data += input[i] * power;
        power *= 2;
    }
}

void nts::Advanced4801::writeInput()
{
    Tristate addr[10] = {
        getLinkedPin(8), getLinkedPin(7), getLinkedPin(6),
        getLinkedPin(5), getLinkedPin(4), getLinkedPin(3),
        getLinkedPin(2), getLinkedPin(1), getLinkedPin(23),
        getLinkedPin(22)
    };
    int power = 1;

    _address = 0;
    for (int i = 0; i < 10; i++) {
        _address += addr[i] * power;
        power *= 2;
    }
    _memory[_address] = _data;
}

void nts::Advanced4801::getAddress()
{
    Tristate addr[10] = {
        getLinkedPin(8), getLinkedPin(7), getLinkedPin(6),
        getLinkedPin(5), getLinkedPin(4), getLinkedPin(3),
        getLinkedPin(2), getLinkedPin(1), getLinkedPin(23),
        getLinkedPin(22)
    };
    int power = 1;

    _address = 0;
    for (int i = 0; i < 10; i++) {
        _address += addr[i] * power;
        power *= 2;
    }
}

void nts::Advanced4801::readData()
{
    _read = true;
    _data = _memory[_address];
    for (int i = 0; i < 8; i++)
        _outputs[i] = (_data & (1 << i)) ? True : False;
}

nts::Tristate nts::Advanced4801::returnManage(size_t outputPin)
{
    if (_read != True) return False;

    switch (outputPin) {
        case 9:     return _outputs[0];
        case 10:    return _outputs[1];
        case 11:    return _outputs[2];
        case 13:    return _outputs[3];
        case 14:    return _outputs[4];
        case 15:    return _outputs[5];
        case 16:    return _outputs[6];
        case 17:    return _outputs[7];
        default:    return Undefined;
    }
}
