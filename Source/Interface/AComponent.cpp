/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** AComponent
*/

#include "Interface/AComponent.hpp"

nts::AComponent::AComponent() : _name("Unknown"), _type(ComponentType::UnknowType) {}
nts::AComponent::AComponent(ComponentType type) : _name("Unknown"), _type(type) {}

void nts::AComponent::simulate([[maybe_unused]] std::size_t tick) {}

nts::Tristate nts::AComponent::compute(std::size_t pin)
{
    if (_isComputed[pin]) {
        if (_pinStates.find(pin) == _pinStates.end())
            return nts::Tristate::Undefined;
        return _pinStates[pin];
    }

    _isComputed[pin] = true;

    nts::Tristate result = computeComponent(pin);

    _pinStates[pin] = result;
    _isComputed[pin] = false;

    return result;
}

// Setters
void nts::AComponent::setName(const std::string &name) { _name = name; }

void nts::AComponent::setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin)
{
    _links[pin] = std::make_pair(&other, otherPin);
}

// Getters
std::string nts::AComponent::getName() const { return _name; }

nts::Tristate nts::AComponent::getLinkedPin(std::size_t pin)
{
    if (_links.find(pin) != _links.end()) {
        auto& [other, otherPin] = _links[pin];
        return other->compute(otherPin);
    }
    return nts::Tristate::Undefined;
}

std::unordered_map<std::size_t, std::pair<nts::IComponent*, std::size_t>> nts::AComponent::getLinks() const
{
    return _links;
}

nts::ComponentType nts::AComponent::getType() const { return _type; }
