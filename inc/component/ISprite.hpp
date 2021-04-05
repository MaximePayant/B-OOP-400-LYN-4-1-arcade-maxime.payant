/*
** EPITECH PROJECT, 2021
** ISprite.hpp.h
** File description:
** ISprite.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_ISPRITE
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_ISPRITE

#include <string>

class ISprite
{
public:
    virtual ~ISprite() = default;
    virtual void setTexture(std::string path, char c, int x, int y) = 0;
    virtual void display() = 0;
};

#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_ISPRITE
