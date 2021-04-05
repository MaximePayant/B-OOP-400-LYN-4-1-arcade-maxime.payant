/*
** EPITECH PROJECT, 2021
** LibOuiModule.hpp.h
** File description:
** LibOuiModule.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE

#include <string>

#include "Color.hpp"

namespace arc
{
    class IDisplayModule
    {
    public:
        virtual ~IDisplayModule() = default;
        virtual std::string getName() const = 0;

        virtual void clearWindow() = 0;
        virtual void displayWindow() = 0;
        virtual void checkEvent() = 0;
        virtual bool isOk() = 0;

        virtual void drawText(const std::string& text, int characterSize, arc::Color color, std::pair<int, int> position) = 0;
        virtual void drawSquare(float size, arc::Color color, std::pair<int, int> position) = 0;
    };
}

#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE
