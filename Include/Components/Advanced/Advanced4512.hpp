/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** Advanced4512
*/

#ifndef ADVANCED4512_HPP
#define ADVANCED4512_HPP

#include "Interface/AComponent.hpp"

namespace nts {
    class Advanced4512 : public AComponent {
        public:
        Advanced4512();
        ~Advanced4512() = default;

        void simulate(std::size_t tick) override;
        Tristate computeComponent(std::size_t pin) override;

        private:
        bool _isComputed;
        Tristate _output;
        std::size_t _data[8];
        void updateOutput();
    };
}  // namespace nts

#endif /* !ADVANCED4512_HPP */
