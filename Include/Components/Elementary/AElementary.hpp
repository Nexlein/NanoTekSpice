/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** AElementary
*/

#ifndef AElementary_HPP
#define AElementary_HPP

#include <functional>

#include "Interface/AComponent.hpp"
#include "Tools/ElementaryLogic.hpp"

namespace nts {
    class AElementary : public AComponent {
        public:
        AElementary(ComponentType type, std::function<Tristate(Tristate, Tristate)> elementaryLogicFunction);
        virtual ~AElementary() = default;

        nts::Tristate computeComponent(std::size_t pin) override;

        private:
        std::function<Tristate(Tristate, Tristate)> _elementaryLogicFunction;
    };
}  // namespace nts

#endif /* !AElementary_HPP */
