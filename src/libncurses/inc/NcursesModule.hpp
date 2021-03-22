/*
** EPITECH PROJECT, 2021
** LibFooModule.hpp.h
** File description:
** LibFooModule.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_LIBOUIMODULE
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_LIBOUIMODULE

#include "../../../inc/IDisplayModule.hpp"

class NcursesModule : public IDisplayModule {
private:
    std::string m_name;
public:
    NcursesModule();
    ~NcursesModule() override;
    virtual void init() override;
    virtual void stop() override;
    virtual std::string getName() const override;
    virtual bool isOk() override;
};

extern "C" void *entryPoint();

#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE
