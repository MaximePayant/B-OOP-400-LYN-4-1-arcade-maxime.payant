/*
** EPITECH PROJECT, 2021
** LibFooModule.hpp.h
** File description:
** LibFooModule.hpp.h
*/

#ifndef NCURSESMODULE
#define NCURSESMODULE

#include <curses.h>
#include <unordered_map>
#include <memory>

#include "../../../inc/IDisplayModule.hpp"

class NcursesModule :
    public arc::IDisplayModule
{
    private:
        bool m_isOk;
        std::string m_name;

    public:
        NcursesModule();
        ~NcursesModule() override;
        std::string getName() const override;

        void init() override;
        void stop() override;

        void clearWindow() override;
        void displayWindow() override;
        void checkEvent() override;
        bool isOk() override;

        void drawText(const std::string& text, int characterSize, arc::Color color, std::pair<int, int> position) override;
        void drawSquare(float size, arc::Color color, std::pair<int, int> position) override;
};

extern "C" void *entryPoint();

#endif //NCURSESMODULE
