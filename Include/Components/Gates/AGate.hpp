/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** AGate
*/

#ifndef AGATE_HPP
#define AGATE_HPP

#include <functional>

#include "Interface/AComponent.hpp"
#include "Tools/ElementaryLogic.hpp"

namespace nts {
    class AGate : public AComponent {
        public:
        AGate(ComponentType type, std::function<Tristate(Tristate, Tristate)> elementaryLogicFunction);
        virtual ~AGate() = default;

        nts::Tristate computeComponent(std::size_t pin) override;

        private:
        std::function<Tristate(Tristate, Tristate)> _elementaryLogicFunction;
        nts::Tristate computeGate(std::size_t pinLeft, std::size_t pinRight);
    };
}  // namespace nts

#endif /* !AGATE_HPP */
