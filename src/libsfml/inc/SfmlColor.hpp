/*
** EPITECH PROJECT, 2021
** SfmlColor.hpp.h
** File description:
** SfmlColor.hpp.h
*/

#ifndef SFMLCOLOR
#define SFMLCOLOR

#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "../../../inc/Color.hpp"

namespace sfml
{
    static const std::unordered_map<arc::Color, sf::Color> sfmlColorMap = {
            {arc::Color::BLACK, sf::Color::Black},
            {arc::Color::WHITE, sf::Color::White},
            {arc::Color::RED, sf::Color::Red},
            {arc::Color::GREEN, sf::Color::Green},
            {arc::Color::BLUE, sf::Color::Blue},
            {arc::Color::YELLOW, sf::Color::Yellow},
            {arc::Color::MAGENTA, sf::Color::Magenta},
            {arc::Color::CYAN, sf::Color::Cyan}
    };
}

#endif //SFMLCOLOR
