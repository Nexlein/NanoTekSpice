/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

#include <cstddef>
#include <string>
#include <unordered_map>

namespace nts {
    enum Tristate { Undefined = (-true), True = true, False = false };
    enum ComponentType {
        InputType,
        ClockType,
        OutputType,
        TrueType,
        FalseType,
        AndType,
        OrType,
        NotType,
        XorType,
        Gate4001Type,
        Gate4011Type,
        Gate4030Type,
        Gate4069Type,
        Gate4071Type,
        Gate4081Type,
        Advanced4008Type,
        Advanced4013Type,
        Advanced4017Type,
        Advanced4040Type,
        Advanced4094Type,
        Advanced4512Type,
        Advanced4514Type,
        Advanced4801Type,
        Advanced2716Type,
        LoggerType,
        UnknowType
    };

    class IComponent {
        public:
        virtual ~IComponent() = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) = 0;
    };
}  // namespace nts

#endif /* !ICOMPONENT_HPP */
