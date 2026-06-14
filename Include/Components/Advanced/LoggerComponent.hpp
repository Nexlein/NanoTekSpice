/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** Logger
*/

#ifndef LOGGERCOMPONENT_HPP
#define LOGGERCOMPONENT_HPP

#include <fstream>
#include "Interface/AComponent.hpp"

namespace nts {
    class LoggerComponent : public AComponent {
        public:
        LoggerComponent();
        ~LoggerComponent() = default;

        Tristate computeComponent(std::size_t pin) override;
        void simulate(std::size_t tick) override;

        private:
        Tristate _lastClock;
    };
}  // namespace nts

#endif /* !LOGGERCOMPONENT_HPP */
