/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** libLoadFunc.cpp
*/

#include "NcursesModule.hpp"

__attribute__((constructor))
void libNcurses_constructor()
{
    printf("[Ncurses Module] Starting Ncurses module...\n");
}

__attribute__((destructor))
void libNcurses_destructor()
{
    printf("[Ncurses Module] Ncurses module stopped.\n");
}

extern "C" void *entryPoint()
{
    auto *module = new NcursesModule();

    return (module);
}