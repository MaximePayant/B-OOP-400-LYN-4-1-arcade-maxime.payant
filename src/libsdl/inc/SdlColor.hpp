/*
** EPITECH PROJECT, 2021
** SfmlColor.hpp.h
** File description:
** SfmlColor.hpp.h
*/

#ifndef SDLCOLOR
#define SDLCOLOR

#include <unordered_map>
#include <SDL2/SDL.h>

#include "../../../inc/Color.hpp"

namespace sfml
{
    static const std::unordered_map<arc::Color, SDL_Color> sdlColorMap = {
            {arc::Color::BLACK, {0, 0, 0, 0}},
            {arc::Color::WHITE, {255, 255, 255, 0}},
            {arc::Color::RED, {255, 0, 0, 0}},
            {arc::Color::GREEN, {0, 255, 0, 0}},
            {arc::Color::BLUE, {0, 0, 255, 0}},
            {arc::Color::YELLOW, {255, 255, 255, 0}}, //TODO
            {arc::Color::MAGENTA, {255, 255, 255, 0}}, //TODO
            {arc::Color::CYAN, {255, 255, 255, 0}} //TODO
    }
}

#endif //SDLCOLOR
