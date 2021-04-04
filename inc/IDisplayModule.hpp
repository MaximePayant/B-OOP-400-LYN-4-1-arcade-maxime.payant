/*
** EPITECH PROJECT, 2021
** LibOuiModule.hpp.h
** File description:
** LibOuiModule.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE

#include <string>
#include "component.hpp"

namespace arc
{

    class IDisplayModule
    {

        public:
            virtual ~IDisplayModule() = default;
            virtual std::string getName() = 0;

            virtual void init() = 0;
            virtual void stop() = 0;

            virtual IText *createText(const std::string& cptName) = 0;
            virtual IText *getText(const std::string& cptName) = 0;
            virtual void deleteText(const std::string& cptName) = 0;

            virtual void clear() = 0;
            virtual void display() = 0;
            virtual bool pollEvent() = 0;
            virtual void closeWindow() = 0;
            virtual bool isOk() = 0;

    }; // class IDisplayModule

} // namespace arc

#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE
