/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** Advanced4801
*/

#ifndef ADVANCED4801_HPP
#define ADVANCED4801_HPP

#include "Interface/AComponent.hpp"

namespace nts {
    class Advanced4801 : public AComponent {
        public:
        Advanced4801();
        ~Advanced4801() = default;

        void simulate(std::size_t tick) override;
        Tristate computeComponent(std::size_t pin) override;

        private:
        bool _idle;
        bool _read;
        Tristate _outputs[8];
        u_int8_t _memory[1024];
        u_int8_t _data;
        u_int16_t _address;
        void getInput();
        void writeInput();
        void getAddress();
        void readData();
        nts::Tristate returnManage(size_t outputPin);
    };
}  // namespace nts

#endif /* !ADVANCED4801_HPP */
