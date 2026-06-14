/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Advanced4017
*/

#ifndef ADVANCED4017_HPP_
#define ADVANCED4017_HPP_

#include "Interface/AComponent.hpp"

namespace nts {
    class Advanced4017 : public AComponent {
        public:
        Advanced4017();
        ~Advanced4017() = default;

        void simulate(std::size_t tick) override;
        nts::Tristate computeComponent(std::size_t pin) override;

        private:
        Tristate _out[10];
        Tristate _outSpecial;
        int _state;
        Tristate _lastClock0;
        Tristate _lastClock1;
        bool isRisingEdge(Tristate clock, Tristate lastClock);
        bool isFallingEdge(Tristate clock, Tristate lastClock);
        nts::Tristate returnManage(size_t pin);
    };
};

#endif /* !ADVANCED4017_HPP_ */
