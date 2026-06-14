/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** FalseComponent
*/

#ifndef FALSECOMPONENT_HPP
#define FALSECOMPONENT_HPP

#include "Interface/AComponent.hpp"

namespace nts {
    class FalseComponent : public AComponent {
        public:
        FalseComponent();
        ~FalseComponent() = default;

        Tristate computeComponent(std::size_t pin) override;
    };
}  // namespace nts

#endif /* !FALSECOMPONENT_HPP */
