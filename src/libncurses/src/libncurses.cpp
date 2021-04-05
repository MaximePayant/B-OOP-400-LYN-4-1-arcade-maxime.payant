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

void NcursesModule::drawText(const std::string& message, int size, std::pair<int, int> position)
{
    (void)size;
    mvprintw(position.first, position.second, message.c_str());
}

void NcursesModule::drawSquare(int size, std::pair<int, int> position)
{
    for (int line = 0; line < size; line += 1)
        for (int col = 0; col < size; col += 1)
            mvprintw(position.first + line, position.second + col, "O");
}