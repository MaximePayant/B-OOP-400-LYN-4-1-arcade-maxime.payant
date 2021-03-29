/*
** EPITECH PROJECT, 2021
** IGame.hpp.h
** File description:
** IGame.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IGAME
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IGAME

#include "IDisplayModule.hpp"

class IGame {
public:
    virtual ~IGame() = default;
    virtual void start(IDisplayModule *) = 0;
    virtual void update(IDisplayModule *) = 0;
};

#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IGAME
