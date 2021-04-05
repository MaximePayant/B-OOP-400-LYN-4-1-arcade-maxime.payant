/*
** EPITECH PROJECT, 2021
** liboui.cpp.c
** File description:
** liboui.cpp.c
*/

#include <iostream>
#include <curses.h>
#include "../inc/NcursesModule.hpp"

NcursesModule::NcursesModule() :
    m_isOk(true),
    m_name("Ncurses")
{
    std::cout << this->getName() << " initializing..." << std::endl;
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();
    timeout(0);
    curs_set(true);
}

NcursesModule::~NcursesModule()
{
    std::cout << this->getName() << " stopping...\n";
    curs_set(true);
    endwin();
    for (auto& [_, obj] : m_TextMap)
        delete (obj);
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

void NcursesModule::clearWindow()
{
    clear();
}

void NcursesModule::displayWindow()
{
    refresh();
}

void NcursesModule::checkEvent()
{
    char c = getch();

    if (c == 'l')
        m_isOk = false;
}

bool NcursesModule::isOk()
{
    return (m_isOk);
}