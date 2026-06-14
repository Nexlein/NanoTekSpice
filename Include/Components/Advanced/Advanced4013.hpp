/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Advanced4013
*/

#ifndef ADVANCED4013_HPP
#define ADVANCED4013_HPP

#include "Interface/AComponent.hpp"

// Tester la truth table
namespace nts {
    class Advanced4013 : public AComponent {
        public:
        Advanced4013();
        ~Advanced4013() = default;

        void simulate(std::size_t tick) override;
        nts::Tristate computeComponent(std::size_t pin) override;

        private:
        Tristate _out1[2];
        Tristate _out2[2];
        int _currentTick;
        int _risingEdgeTick1;
        int _risingEdgeTick2;

        bool isRisingEdge(size_t clockPin, Tristate set, Tristate reset, int& risingEdgeTick);
        nts::Tristate computeFlipFlop1(size_t dataPin, size_t setPin, size_t resetPin, size_t clockPin, size_t outputPin);
        nts::Tristate computeFlipFlop2(size_t dataPin, size_t setPin, size_t resetPin, size_t clockPin, size_t outputPin);
    };
};
#endif /* !ADVANCED4013_HPP */
