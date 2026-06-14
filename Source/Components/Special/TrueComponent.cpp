/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** TrueComponent
*/

#include "Components/Special/TrueComponent.hpp"

nts::TrueComponent::TrueComponent() : AComponent(ComponentType::TrueType) {}

nts::Tristate nts::TrueComponent::computeComponent([[maybe_unused]] std::size_t pin)
{
    return Tristate::True;
}
