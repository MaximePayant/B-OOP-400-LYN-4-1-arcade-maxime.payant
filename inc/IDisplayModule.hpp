/*
** EPITECH PROJECT, 2021
** LibOuiModule.hpp.h
** File description:
** LibOuiModule.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE

class IDisplayModule {
public:
    virtual ~IDisplayModule() = default;
    virtual void init() = 0;
    virtual void stop() = 0;
    virtual std::string getName() const = 0;
    virtual bool isOk() = 0;
    virtual void clearWindow() = 0;
    virtual void draw() = 0;
};

#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE
