/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** FalseComponent
*/

#include "Components/Special/FalseComponent.hpp"

nts::FalseComponent::FalseComponent() : AComponent(ComponentType::FalseType) {}

nts::Tristate nts::FalseComponent::computeComponent([[maybe_unused]] std::size_t pin)
{
    return Tristate::False;
}
