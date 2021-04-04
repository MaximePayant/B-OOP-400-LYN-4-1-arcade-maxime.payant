/*
** EPITECH PROJECT, 2021
** LibFooModule.hpp.h
** File description:
** LibFooModule.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_LIBOUIMODULE
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_LIBOUIMODULE

#include "IDisplayModule.hpp"
#include "Text.hpp"

namespace ncs
{

    class Module :
        public arc::IDisplayModule
    {

        public:
            const std::string m_name;

            Module();
            ~Module() override;

            virtual void init() override;
            virtual void stop() override;

            arc::IText& createText(const std::string& cptName) override;
            arc::IText& getText(const std::string& cptName) override;
            void deleteText(const std::string& cptName) override;

    }; // class Module

    #include "createComponent.inl"

} // namespace ncs

extern "C" void *entryPoint();

#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE
