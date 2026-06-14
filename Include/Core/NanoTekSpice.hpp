/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** NanoTekSpice
*/

#ifndef NANOTEKSPICE_HPP
#define NANOTEKSPICE_HPP

#include <string>

#include "Circuit.hpp"

namespace nts {
    class NanoTekSpice {
        public:
        NanoTekSpice(Circuit circuit);
        ~NanoTekSpice() = default;
        void processUserInput();

        private:
        void handleUserInput(const std::string& input);
        void handleAssignation(const std::string& input);
        void display() const;
        void loop();
        void simulate();
        void links();
        Circuit _circuit;
    };
}  // namespace nts

#endif /* !NANOTEKSPICE_HPP */
