/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** OutputComponent
*/

#ifndef OUTPUTCOMPONENT_HPP
#define OUTPUTCOMPONENT_HPP

#include "Interface/AComponent.hpp"

namespace nts {
    class OutputComponent : public AComponent {
        public:
        OutputComponent();
        ~OutputComponent() = default;

        Tristate computeComponent(std::size_t pin) override;
        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) override;

        /// Getters
        Tristate getValue() const;

        private:
        Tristate _value;
    };
}  // namespace nts

#endif /* !OUTPUTCOMPONENT_HPP */
