/*
** EPITECH PROJECT, 2026
** projects
** File description:
** Parser
*/

#ifndef PARSER_HPP
#define PARSER_HPP

#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>


namespace nts
{
    class Parser {

        public:
            Parser() = default;
            ~Parser() = default;

            void parseFile(int ac, char **av);
            void createChipsets(std::ifstream& file);
            int createLinks(std::ifstream& file);

            /* Parsing Tools */
            int cleanLine(std::string& line);
            void cleanComments(std::string& line);
            bool validTokens(const std::vector<std::string>& tokens) const;

            const std::vector<std::pair<std::string, std::string>>& getLinks() const;
            const std::vector<std::pair<std::string, std::string>>& getChipsets() const;

            class ParserException : public std::exception {
                public:
                ParserException(const std::string& message);
                ~ParserException() = default;
                const char* what() const noexcept override;

                private:
                std::string _message;
            };

        private:
            std::vector<std::pair<std::string, std::string>> _links;
            std::vector<std::pair<std::string, std::string>> _chipsets;
            std::unordered_set<std::string> _componentNames;
    };
}

#endif /* !PARSER_HPP */
