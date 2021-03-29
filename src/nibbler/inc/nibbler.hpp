/*
** EPITECH PROJECT, 2021
** pacMan.hpp.h
** File description:
** pacMan.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_NIBBLER
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_NIBBLER

#include "../../../inc/IDisplayModule.hpp"
#include "../../../inc/IGame.hpp"

class PacMan : public IGame {
public:
    PacMan();
    ~PacMan() override;
    void start(IDisplayModule *) override;
    void update(IDisplayModule *) override;
};

extern "C" void *entryPoint();

#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_NIBBLER
