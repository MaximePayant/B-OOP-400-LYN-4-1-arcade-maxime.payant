/*
** EPITECH PROJECT, 2021
** IGame.hpp.h
** File description:
** IGame.hpp.h
*/

#ifndef IGAME
#define IGAME

#include "IDisplayModule.hpp"

class IGame
{
    public:
        virtual ~IGame() = default;
        virtual void start(arc::IDisplayModule *) = 0;
        virtual void update(arc::IDisplayModule *) = 0;
};

#endif //IGAME
