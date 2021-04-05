/*
** EPITECH PROJECT, 2021
** pacMan.hpp.h
** File description:
** pacMan.hpp.h
*/

#ifndef NIBBLER
#define NIBBLER

#include "../../../inc/IDisplayModule.hpp"
#include "../../../inc/IGame.hpp"

class PacMan : public IGame {
public:
    PacMan();
    ~PacMan() override;
    void start(arc::IDisplayModule *) override;
    void update(arc::IDisplayModule *) override;
};

extern "C" void *entryPoint();

#endif //NIBBLER
