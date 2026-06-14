/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** ClockComponent
*/

#ifndef CLOCKCOMPONENT_HPP
#define CLOCKCOMPONENT_HPP

#include "Components/Special/ASpecial.hpp"

namespace nts {
    class ClockComponent : public ASpecial {
        public:
        ClockComponent();
        ~ClockComponent() = default;

        Tristate computeComponent(std::size_t pin) override;
        void simulate(std::size_t tick) override;

        private:
        void switchClock();
    };
}  // namespace nts

#endif /* !CLOCKCOMPONENT_HPP */
