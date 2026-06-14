/*
** EPITECH PROJECT, 2026
** projects
** File description:
** Parser
*/

#include "Core/Parser.hpp"

#include <iostream>
#include <vector>

#include "Core/Circuit.hpp"

nts::Parser::ParserException::ParserException(const std::string& message)
    : _message(message) {}

const char* nts::Parser::ParserException::what() const noexcept { return _message.c_str(); }

void nts::Parser::cleanComments(std::string& line)
{
    size_t pos = line.find('#');
    if (pos != std::string::npos) line = line.substr(0, pos);
}

int nts::Parser::cleanLine(std::string& line)
{
    cleanComments(line);

    size_t end = line.find_last_not_of(" \t\r\n");
    if (end != std::string::npos)
        line = line.substr(0, end + 1);
    else
        line.clear();

    if (line.empty()) return 1;
    return 0;
}

int nts::Parser::createLinks(std::ifstream& file)
{
    std::string line;

    if (_chipsets.empty())
        throw ParserException("Parser: No components founded.");

    while (getline(file, line)) {
        if (cleanLine(line)) continue;

        std::istringstream iss(line);
        std::vector<std::string> tokens;
        std::string token;
        while (iss >> token) tokens.push_back(token);

        if (tokens.size() == 2) {
            auto it1 = tokens[0].find(":");
            auto it2 = tokens[1].find(":");

            if (it1 == std::string::npos && it2 == std::string::npos)
                throw ParserException("Parser: Invalid link format: " + line);

            std::string comp1 = tokens[0].substr(0, it1);
            std::string comp2 = tokens[1].substr(0, it2);

            if (!_componentNames.count(comp1) || !_componentNames.count(comp2))
                throw ParserException(
                    "Parser: Undefined component in link: " + line
                );

            _links.push_back({tokens[0], tokens[1]});
        } else
            throw ParserException("Parser: Invalid link format: " + line);
    }
    return 0;
}

const std::vector<std::pair<std::string, std::string>>& nts::Parser::getLinks()
    const
{
    return _links;
}

const std::vector<std::pair<std::string, std::string>>&
nts::Parser::getChipsets() const
{
    return _chipsets;
}

bool nts::Parser::validTokens(const std::vector<std::string>& tokens) const
{
    static const std::unordered_set<std::string> validTypes = {
        "and",   "not",   "or",   "xor",   "input", "output", "true",
        "false", "clock", "4001", "4011",  "4030",  "4069",   "4071",
        "4081",  "4008",  "4013", "4017",  "4040",  "4094",   "4512",
        "4514",  "4801",  "2716", "logger"
    };

    return (tokens.size() == 2 && validTypes.count(tokens[0])) && !_componentNames.count(tokens[1]);
}

void nts::Parser::createChipsets(std::ifstream& file)
{
    std::string line;

    while (getline(file, line)) {
        if (cleanLine(line)) continue;
        if (line.compare(0, 7, ".links:") == 0 && line.size() == 7) return;

        std::istringstream iss(line);
        std::vector<std::string> tokens;
        std::string token;
        while (iss >> token) tokens.push_back(token);

        if (validTokens(tokens)) {
            _chipsets.push_back({tokens[0], tokens[1]});
            _componentNames.insert(tokens[1]);
        } else
            throw ParserException("Parser: Invalid component: " + tokens[0]);
    }
}

/// @brief Parses a configuration file.
/// @param ac Argument count from the command line.
/// @param av Argument vector from the command line.
/// @return 0 on success, 84 on failure.
void nts::Parser::parseFile(int ac, char** av)
{
    std::string line;

    if (ac != 2) throw ParserException("Parser: Invalid number of arguments.");

    std::ifstream file(av[1]);
    if (!file.is_open())
        throw ParserException("Parser: Can't open file: " + std::string(av[1]));

    while (getline(file, line)) {
        if (cleanLine(line)) continue;
        if (line.compare(0, 10, ".chipsets:") == 0 && line.size() == 10) {
            createChipsets(file);
            break;
        }
    }
    createLinks(file);
}
