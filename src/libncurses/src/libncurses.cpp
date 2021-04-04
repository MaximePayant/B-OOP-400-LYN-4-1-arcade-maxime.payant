/*
** EPITECH PROJECT, 2021
** liboui.cpp.c
** File description:
** liboui.cpp.c
*/

#include <iostream>
#include <curses.h>
#include "../inc/Module.hpp"

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
    auto *module = new ncs::Module();

    return (module);
}

ncs::Module::Module() :
    arc::ADisplayModule(),
    m_name("Ncurses")
{
    std::cout << m_name << " initializing..." << std::endl;
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();
    timeout(0);
    curs_set(false);
}

ncs::Module::~Module()
{
    std::cout << m_name << " stopping...\n";
    curs_set(true);
    endwin();
}

void ncs::Module::init()
{
    std::cout << m_name << " initializing..." << std::endl;
}

void ncs::Module::stop()
{
    std::cout << m_name << " stopping...\n";
}

/*
bool ncs::Module::isOk()
{
    return (getch() != 'l');
}

void ncs::Module::clearWindow()
{

}

void ncs::Module::draw()
{

}
*/