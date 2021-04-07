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
    void start(std::shared_ptr<arc::IDisplayModule>) override;
    void update(std::shared_ptr<arc::IDisplayModule>) override;
};

extern "C" void *entryPoint();

#endif //NIBBLER
