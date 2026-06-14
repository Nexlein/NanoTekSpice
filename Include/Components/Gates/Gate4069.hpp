/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** Gate4069
*/

#ifndef GATE4069_HPP
#define GATE4069_HPP

#include "Interface/AComponent.hpp"

namespace nts {
    class Gate4069 : public AComponent {
        public:
        Gate4069();
        ~Gate4069() = default;
        nts::Tristate computeComponent(std::size_t pin) override;

        private:
        nts::Tristate computeNot(std::size_t pin);
    };
}  // namespace nts

#endif /* !GATE4069_HPP */
