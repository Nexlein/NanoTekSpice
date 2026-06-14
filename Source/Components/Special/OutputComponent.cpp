/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** OutputComponent
*/

#include "Components/Special/OutputComponent.hpp"

nts::OutputComponent::OutputComponent()
    : AComponent(ComponentType::OutputType), _value(Tristate::Undefined)
{}

nts::Tristate nts::OutputComponent::computeComponent(std::size_t pin)
{
    _value = getLinkedPin(pin);
    return _value;
}

nts::Tristate nts::OutputComponent::getValue() const { return _value; }

void nts::OutputComponent::simulate([[maybe_unused]] std::size_t tick)
{
    if (!_links.empty()) {
        auto it = _links.begin();
        compute(it->first);
    } else
        _value = Tristate::Undefined;
}

void nts::OutputComponent::setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin)
{
    AComponent::setLink(pin, other, otherPin);

    AComponent* aComponent = dynamic_cast<AComponent*>(&other);
    if (aComponent && (aComponent->getType() == ComponentType::TrueType ||
        aComponent->getType() == ComponentType::FalseType))
        compute(pin);
}
