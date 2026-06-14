/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Advanced4040
*/

#ifndef ADVANCED4040_HPP
#define ADVANCED4040_HPP

#include <cstdint>

#include "Interface/AComponent.hpp"

namespace nts {
    class Advanced4040 : public AComponent {
        public:
        Advanced4040();
        ~Advanced4040() = default;

        void simulate(std::size_t tick) override;
        nts::Tristate computeComponent(std::size_t pin) override;

        private:
        uint16_t _counter;
        Tristate _out[12];
        Tristate _lastClock;
        bool isFallingEdge(Tristate clock, Tristate lastClock);
        nts::Tristate returnManage(size_t pin);
    };
};

#endif /* !ADVANCED4040_HPP */
    