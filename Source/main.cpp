/*
** EPITECH PROJECT, 2026
** projects
** File description:
** main
*/

#include <iostream>

#include "Core/Circuit.hpp"
#include "Core/NanoTekSpice.hpp"
#include "Core/Parser.hpp"

int main(int ac, char** av)
{
    nts::Parser parser;
    nts::Circuit circuit;

    try {
        parser.parseFile(ac, av);

        for (const auto& [type, name] : parser.getChipsets())
            circuit.addComponent(type, name);
        for (const auto& [link1, link2] : parser.getLinks())
            circuit.addLink(link1, link2);
        circuit.applyLinks();

        nts::NanoTekSpice nanotekspice(std::move(circuit));
        nanotekspice.processUserInput();
    } catch (const nts::Parser::ParserException& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
    return 0;
}
