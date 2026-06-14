/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** ElementaryLogic
*/

#ifndef ELEMENTARYLOGIC_HPP
#define ELEMENTARYLOGIC_HPP

#include "Interface/IComponent.hpp"

namespace nts {
    class ElementaryLogic {
        public:
        /* Gates */
        static nts::Tristate andGate(nts::Tristate a, nts::Tristate b);
        static nts::Tristate orGate(nts::Tristate a, nts::Tristate b);
        static nts::Tristate xorGate(nts::Tristate a, nts::Tristate b);
        static nts::Tristate notGate(nts::Tristate a);
        static nts::Tristate nandGate(nts::Tristate a, nts::Tristate b);
        static nts::Tristate norGate(nts::Tristate a, nts::Tristate b);

        /* Bits Adder */
        static nts::Tristate bitAdder(nts::Tristate a, nts::Tristate b, nts::Tristate& c_in);
    };
}  // namespace nts

#endif /* !ELEMENTARYLOGIC_HPP */
