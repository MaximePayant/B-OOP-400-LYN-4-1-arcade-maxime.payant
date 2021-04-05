/*
** EPITECH PROJECT, 2021
** LibOuiModule.hpp.h
** File description:
** LibOuiModule.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE

#include <string>

class IDisplayModule
{
    public:
        virtual ~IDisplayModule() = default;
        virtual std::string getName() const = 0;

        virtual void init() = 0;
        virtual void stop() = 0;

        virtual void clearWindow() = 0;
        virtual void displayWindow() = 0;
        virtual void checkEvent() = 0;
        virtual bool isOk() = 0;

        virtual void drawText(const std::string& text, int characterSize, std::pair<int, int> position) = 0;
        virtual void drawSquare(int size, std::pair<int, int> position) = 0;
};

#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE
