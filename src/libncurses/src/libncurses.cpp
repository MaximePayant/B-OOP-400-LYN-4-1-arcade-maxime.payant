/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** libncurses.cpp
*/

#include <iostream>
#include <curses.h>

#include "../inc/NcursesModule.hpp"

ncs::NcursesModule::NcursesModule() :
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

ncs::NcursesModule::~NcursesModule()
{
    std::cout << this->getName() << " stopping...\n";
    curs_set(true);
    endwin();
}

std::string ncs::NcursesModule::getName() const
{
    return (std::string("[" + m_name + "]"));
}

void ncs::NcursesModule::clearWindow()
{
    clear();
}

void ncs::NcursesModule::displayWindow()
{
    refresh();
}

void ncs::NcursesModule::checkEvent()
{
    char c = getch();

    if (c == 'l')
        m_isOk = false;
}

bool ncs::NcursesModule::isOk()
{
    return (m_isOk);
}

void ncs::NcursesModule::drawText(const std::string& message, int size, arc::Color color, std::pair<int, int> position)
{
    (void)size;
    attron(COLOR_PAIR(color));
    mvprintw(position.first, position.second, message.c_str());
    attron(COLOR_PAIR(arc::BLACK));
}

void ncs::NcursesModule::drawSquare(float size, arc::Color color, std::pair<int, int> position)
{
    for (int line = 0; line < size; line += 1)
        for (int col = 0; col < size; col += 1) {
            attron(COLOR_PAIR(color));
            mvprintw(position.first + line, position.second + col, "O");
            attron(COLOR_PAIR(arc::BLACK));
        }
}