/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** Advanced2716
*/

#ifndef ADVANCED2716_HPP
#define ADVANCED2716_HPP

#include "Interface/AComponent.hpp"

namespace nts {
    class Advanced2716 : public AComponent {
        public:
        Advanced2716();
        ~Advanced2716() = default;

        void simulate(std::size_t tick) override;
        Tristate computeComponent(std::size_t pin) override;

        private:
        bool _computed;
        bool _enable;
        int8_t _memory[2048];
        Tristate _output[8];
        Tristate returnManage(size_t pin);
    };
}  // namespace nts

#endif /* !ADVANCED2716_HPP */
