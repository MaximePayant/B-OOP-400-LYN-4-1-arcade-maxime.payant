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
    start_color();
    init_pair(arc::BLACK, COLOR_WHITE, COLOR_BLACK);
    init_pair(arc::RED, COLOR_BLACK, COLOR_RED);
    init_pair(arc::GREEN, COLOR_BLACK, COLOR_GREEN);
    init_pair(arc::YELLOW, COLOR_BLACK, COLOR_YELLOW);
    init_pair(arc::BLUE, COLOR_BLACK, COLOR_BLUE);
    init_pair(arc::MAGENTA, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(arc::CYAN, COLOR_BLACK, COLOR_CYAN);
    init_pair(arc::WHITE, COLOR_BLACK, COLOR_WHITE);
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

void NcursesModule::drawText(const std::string& message, int size, arc::Color color, std::pair<int, int> position)
{
    (void)size;
    attron(COLOR_PAIR(color));
    mvprintw(position.first, position.second, message.c_str());
    attron(COLOR_PAIR(arc::BLACK));
}

void NcursesModule::drawSquare(int size, std::pair<int, int> position)
{
    for (int line = 0; line < size; line += 1)
        for (int col = 0; col < size; col += 1)
            mvprintw(position.first + line, position.second + col, "O");
}