/*
** EPITECH PROJECT, 2021
** pacMan.hpp.h
** File description:
** pacMan.hpp.h
*/

#ifndef NIBBLER
#define NIBBLER

#include <memory>
#include "../../../inc/IDisplayModule.hpp"
#include "../../../inc/IGame.hpp"

class Nibbler : public arc::IGame {
public:
    Nibbler();
    ~Nibbler() override;
    void start(arc::IDisplayModule*) override;
    void update(arc::IDisplayModule*) override;
};

extern "C" void *entryPoint();

#endif //NIBBLER
