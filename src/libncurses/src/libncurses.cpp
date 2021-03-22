/*
** EPITECH PROJECT, 2021
** liboui.cpp.c
** File description:
** liboui.cpp.c
*/

#include <iostream>
#include <curses.h>
#include "../inc/NcursesModule.hpp"

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

NcursesModule::NcursesModule() : IDisplayModule(),
m_name("Ncurses")
{
    std::cout << this->getName() << " initializing..." << std::endl;
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();
    timeout(0);
    curs_set(false);
}

NcursesModule::~NcursesModule()
{
    std::cout << this->getName() << " stopping...\n";
    curs_set(true);
    endwin();
}

void NcursesModule::init()
{
    std::cout << this->getName() << " initializing..." << std::endl;
}

void NcursesModule::stop()
{
    std::cout << this->getName() << " stopping...\n";
}

std::string NcursesModule::getName() const
{
    return (std::string("[" + m_name + "]"));
}

bool NcursesModule::isOk()
{
    return (getch() != 'l');
}