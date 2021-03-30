/*
** EPITECH PROJECT, 2021
** LibFooModule.hpp.h
** File description:
** LibFooModule.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_LIBOUIMODULE
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_LIBOUIMODULE

#include <unordered_map>
#include <memory>
#include "../../../inc/IDisplayModule.hpp"
#include "Text.hpp"

class NcursesModule : public IDisplayModule {
private:
    std::string m_name;
    std::unordered_map<std::string, Text*> m_TextMap;
public:
    NcursesModule();
    ~NcursesModule() override;
    virtual void init() override;
    virtual void stop() override;
    virtual std::string getName() const override;
    virtual bool isOk() override;
    void clearWindow() override;
    void draw() override;
    IText *createText(std::string name, std::string text, unsigned int size, std::string font) override;
    IText *getText(std::string name) override;
    void displayText(IText *text) override;
};

extern "C" void *entryPoint();

#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE
