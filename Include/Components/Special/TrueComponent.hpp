/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** TrueComponent
*/

#ifndef TRUECOMPONENT_HPP
#define TRUECOMPONENT_HPP

#include "Interface/AComponent.hpp"

namespace nts {
    class TrueComponent : public AComponent {
        public:
        TrueComponent();
        ~TrueComponent() = default;

        Tristate computeComponent(std::size_t pin) override;
    };
}  // namespace nts

#endif /* !TRUECOMPONENT_HPP */
