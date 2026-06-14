/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** ASpecial
*/

#ifndef ASPECIAL_HPP
#define ASPECIAL_HPP

#include "Interface/AComponent.hpp"

namespace nts {
    class ASpecial : public AComponent {
        public:
        ASpecial(ComponentType type);
        virtual ~ASpecial() = default;

        virtual nts::Tristate computeComponent(std::size_t pin) override = 0;

        // Setters
        void setValue(Tristate value);
        void setNextValue(Tristate value);

        // Getters
        Tristate getValue() const;
        Tristate getNextValue() const;

        bool updateValue();

        protected:
        Tristate _value;
        Tristate _nextValue;
        bool _hasAssignation;
    };
}  // namespace nts

#endif /* !ASPECIAL_HPP */
