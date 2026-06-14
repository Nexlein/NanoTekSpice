/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Advanced4514
*/

#ifndef ADVANCED4514_HPP
#define ADVANCED4514_HPP

#include "Interface/AComponent.hpp"

namespace nts {
    class Advanced4514 : public AComponent {
        public:
        Advanced4514();
        ~Advanced4514() = default;

        void simulate(std::size_t tick) override;
        nts::Tristate computeComponent(std::size_t pin) override;

        private:
        bool _isComputed;
        Tristate _in[4];
        Tristate _out[16];
        void strobeManage(Tristate in[]);
        nts::Tristate returnManage(size_t pin);
    };
}

#endif /* !ADVANCED4514_HPP */
