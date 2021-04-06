/*
** EPITECH PROJECT, 2021
** Interface.hpp
** File description:
** Interface.hpp
*/

#ifndef INTERFACE
#define INTERFACE

#include "../../../inc/IDisplayModule.hpp"
#include "../../../inc/IGame.hpp"
#include <vector>

class Interface : public arc::IGame
{
    int m_gameIndex;
    int m_libIndex;
    std::vector<std::string> m_lib;
    std::vector<std::string> m_game;

    void getList();
    void DrawText(arc::IDisplayModule *module, int index, const std::string &name, bool game) const;
public:
    Interface() = default;
    ~Interface() = default;

    void start(arc::IDisplayModule *) override;
    void update(arc::IDisplayModule *) override;

};

extern "C" void *entryPoint();


#endif //INTERFACE
