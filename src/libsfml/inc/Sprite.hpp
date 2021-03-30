/*
** EPITECH PROJECT, 2021
** Sprite.hpp.h
** File description:
** Sprite.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_SPRITE
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_SPRITE

#include "../../../inc/ISprite.hpp"
#include <SFML/Graphics.hpp>

class Sprite : public ISprite
{
    sf::Sprite m_sprite;
    sf::Texture m_texture;
public:
    Sprite() = default;
    ~Sprite() override = default;
    void setTexture(std::string path, char c, int x, int y) override
    {
        (void) path;
        (void) c;
        (void) x;
        (void) y;
    };
};


#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_SPRITE
