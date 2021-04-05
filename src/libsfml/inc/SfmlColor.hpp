/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** SfmlColor.hpp
*/

#ifndef __SFML_COLOR_HPP__
#define __SFML_COLOR_HPP__

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


#endif // __SFML_COLOR_HPP__