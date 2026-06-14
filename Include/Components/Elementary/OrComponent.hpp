/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** OrComponent
*/

#ifndef ORCOMPONENT_HPP
#define ORCOMPONENT_HPP

#include "Components/Elementary/AElementary.hpp"

namespace nts {
    class OrComponent : public AElementary {
        public:
        OrComponent();
        ~OrComponent() = default;
    };
}  // namespace nts

#endif /* !ORCOMPONENT_HPP */
