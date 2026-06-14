/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP
#define ACOMPONENT_HPP

#include <unordered_map>

#include "IComponent.hpp"

namespace nts {
    class AComponent : public IComponent {
        public:
        AComponent();
        AComponent(ComponentType type);
        virtual ~AComponent() = default;

        nts::Tristate compute(std::size_t pin) override;
        virtual nts::Tristate computeComponent(std::size_t pin) = 0;

        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) override;

        /// Setters
        void setName(const std::string &name);

        /// Getters
        std::string getName() const;
        nts::Tristate getLinkedPin(std::size_t pin);
        std::unordered_map<std::size_t, std::pair<nts::IComponent*, std::size_t>> getLinks() const;
        ComponentType getType() const;

        protected:
        std::string _name;
        std::unordered_map<std::size_t, std::pair<nts::IComponent*, std::size_t>> _links;
        ComponentType _type;
        std::unordered_map<std::size_t, bool> _isComputed;
        std::unordered_map<std::size_t, nts::Tristate> _pinStates;
    };
}  // namespace nts

#endif /* !ACOMPONENT_HPP */
