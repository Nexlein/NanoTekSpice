/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** NotComponent
*/

#ifndef NOTCOMPONENT_HPP
#define NOTCOMPONENT_HPP

#include "Interface/AComponent.hpp"

namespace nts {
    class NotComponent : public AComponent {
        public:
        NotComponent();
        ~NotComponent() = default;

        nts::Tristate computeComponent(std::size_t pin) override;
    };
}  // namespace nts

#endif /* !NOTCOMPONENT_HPP */
