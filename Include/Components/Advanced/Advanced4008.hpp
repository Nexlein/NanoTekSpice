/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Advanced4008
*/

#ifndef ADVANCED4008_HPP
#define ADVANCED4008_HPP

#include "Interface/AComponent.hpp"

namespace nts {
    class Advanced4008 : public AComponent {
        public:
        Advanced4008();
        ~Advanced4008() = default;

        void simulate(std::size_t tick) override;
        nts::Tristate computeComponent(std::size_t pin) override;

        private:
        bool _computed;
        Tristate _out0;
        Tristate _out1;
        Tristate _out2;
        Tristate _out3;
        Tristate _outC;
        void computeAllBits();
    };
};  // namespace nts

#endif /* !ADVANCED4008_HPP */
