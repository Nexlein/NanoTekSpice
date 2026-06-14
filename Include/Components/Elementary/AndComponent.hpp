/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** AndComponent
*/

#ifndef ANDCOMPONENT_HPP
#define ANDCOMPONENT_HPP

#include "Components/Elementary/AElementary.hpp"

namespace nts {
    class AndComponent : public AElementary {
        public:
        AndComponent();
        ~AndComponent() = default;
    };
}  // namespace nts

#endif /* !ANDCOMPONENT_HPP */
