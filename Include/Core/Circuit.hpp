/*
** EPITECH PROJECT, 2026
** projects
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "Interface/IComponent.hpp"

namespace nts {
    class Circuit {
        public:
        Circuit();

        void addComponent(std::string type, std::string name);
        std::unique_ptr<IComponent> createComponent(const std::string& type);
        void addLink(std::string link1, std::string link2);
        void applyLinks();
        void simulate();

        /// Getters
        const std::unordered_map<std::string, std::unique_ptr<IComponent>>&
        getComponents() const;
        std::map<std::string, IComponent*> getComponentsByType(
            ComponentType type) const;
        size_t getTick() const;

        protected:
        std::unordered_map<std::string, std::unique_ptr<IComponent>>
            _components;

        private:
        std::multimap<std::string, std::string> _links;
        size_t _tick;
        std::vector<IComponent*> _inputs;
        std::vector<IComponent*> _outputs;
        std::vector<IComponent*> _others;
        bool _areComponentsSorted;
    };
}  // namespace nts

#endif /* !CIRCUIT_HPP_ */
