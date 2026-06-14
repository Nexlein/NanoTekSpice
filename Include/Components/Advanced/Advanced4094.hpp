/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** Advanced4094
*/

#ifndef ADVANCED4094_HPP
#define ADVANCED4094_HPP

#include "Interface/AComponent.hpp"

namespace nts {
    class Advanced4094 : public AComponent {
        public:
        Advanced4094();
        ~Advanced4094() = default;

        void simulate(std::size_t tick) override;
        nts::Tristate computeComponent(std::size_t pin) override;

        private:
        Tristate _shiftReg[8];
        Tristate _savedValues[8];
        Tristate _outQs;
        Tristate _outQe;
        Tristate _oldClock;
        size_t _currentTick;
        bool _isComputed;

        void shiftRegister();
    };
}  // namespace nts

#endif /* !ADVANCED4094_HPP */
