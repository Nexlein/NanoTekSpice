/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** InputComponent
*/

#ifndef INPUTCOMPONENT_HPP
#define INPUTCOMPONENT_HPP

#include "Components/Special/ASpecial.hpp"

namespace nts {
    class InputComponent : public ASpecial {
        public:
        InputComponent();
        ~InputComponent() = default;

        Tristate computeComponent(std::size_t pin) override;
        void simulate(std::size_t tick) override;
    };
}  // namespace nts

#endif /* INPUTCOMPONENT_HPP */
