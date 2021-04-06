/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** SfmlKeyboard.hpp
*/

#ifndef __SFML_KEYBOARD_H__
#define __SFML_KEYBOARD_H__

#include <unordered_map>
#include <SDL2/SDL_keyboard.h>

#include "../../../inc/Keyboard.hpp"

namespace sdl
{

    static const std::unordered_map<arc::Keyboard, SDL_KeyCode> keyboardMap =
    {

        {arc::Keyboard::Unknown,    SDLK_UNKNOWN},
        {arc::Keyboard::A,          SDLK_UNKNOWN},
        {arc::Keyboard::B,          SDLK_UNKNOWN},
        {arc::Keyboard::C,          SDLK_UNKNOWN},
        {arc::Keyboard::D,          SDLK_UNKNOWN},
        {arc::Keyboard::E,          SDLK_UNKNOWN},
        {arc::Keyboard::F,          SDLK_UNKNOWN},
        {arc::Keyboard::G,          SDLK_UNKNOWN},
        {arc::Keyboard::H,          SDLK_UNKNOWN},
        {arc::Keyboard::I,          SDLK_UNKNOWN},
        {arc::Keyboard::J,          SDLK_UNKNOWN},
        {arc::Keyboard::K,          SDLK_UNKNOWN},
        {arc::Keyboard::L,          SDLK_UNKNOWN},
        {arc::Keyboard::M,          SDLK_UNKNOWN},
        {arc::Keyboard::N,          SDLK_UNKNOWN},
        {arc::Keyboard::O,          SDLK_UNKNOWN},
        {arc::Keyboard::P,          SDLK_UNKNOWN},
        {arc::Keyboard::Q,          SDLK_UNKNOWN},
        {arc::Keyboard::R,          SDLK_UNKNOWN},
        {arc::Keyboard::S,          SDLK_UNKNOWN},
        {arc::Keyboard::T,          SDLK_UNKNOWN},
        {arc::Keyboard::U,          SDLK_UNKNOWN},
        {arc::Keyboard::V,          SDLK_UNKNOWN},
        {arc::Keyboard::W,          SDLK_UNKNOWN},
        {arc::Keyboard::X,          SDLK_UNKNOWN},
        {arc::Keyboard::Y,          SDLK_UNKNOWN},
        {arc::Keyboard::Z,          SDLK_UNKNOWN},
        {arc::Keyboard::Num0,       SDLK_UNKNOWN},
        {arc::Keyboard::Num1,       SDLK_UNKNOWN},
        {arc::Keyboard::Num2,       SDLK_UNKNOWN},
        {arc::Keyboard::Num3,       SDLK_UNKNOWN},
        {arc::Keyboard::Num4,       SDLK_UNKNOWN},
        {arc::Keyboard::Num5,       SDLK_UNKNOWN},
        {arc::Keyboard::Num6,       SDLK_UNKNOWN},
        {arc::Keyboard::Num7,       SDLK_UNKNOWN},
        {arc::Keyboard::Num8,       SDLK_UNKNOWN},
        {arc::Keyboard::Num9,       SDLK_UNKNOWN},
        {arc::Keyboard::Escape,     SDLK_UNKNOWN},
        {arc::Keyboard::LControl,   SDLK_UNKNOWN},
        {arc::Keyboard::LShift,     SDLK_UNKNOWN},
        {arc::Keyboard::LAlt,       SDLK_UNKNOWN},
        {arc::Keyboard::LSystem,    SDLK_UNKNOWN},
        {arc::Keyboard::RControl,   SDLK_UNKNOWN},
        {arc::Keyboard::RShift,     SDLK_UNKNOWN},
        {arc::Keyboard::RAlt,       SDLK_UNKNOWN},
        {arc::Keyboard::RSystem,    SDLK_UNKNOWN},
        {arc::Keyboard::Menu,       SDLK_UNKNOWN},
        {arc::Keyboard::LBracket,   SDLK_UNKNOWN},
        {arc::Keyboard::RBracket,   SDLK_UNKNOWN},
        {arc::Keyboard::Semicolon,  SDLK_UNKNOWN},
        {arc::Keyboard::Comma,      SDLK_UNKNOWN},
        {arc::Keyboard::Period,     SDLK_UNKNOWN},
        {arc::Keyboard::Quote,      SDLK_UNKNOWN},
        {arc::Keyboard::Slash,      SDLK_UNKNOWN},
        {arc::Keyboard::Backslash,  SDLK_UNKNOWN},
        {arc::Keyboard::Tilde,      SDLK_UNKNOWN},
        {arc::Keyboard::Equal,      SDLK_UNKNOWN},
        {arc::Keyboard::Hyphen,     SDLK_UNKNOWN},
        {arc::Keyboard::Space,      SDLK_UNKNOWN},
        {arc::Keyboard::Enter,      SDLK_UNKNOWN},
        {arc::Keyboard::Backspace,  SDLK_UNKNOWN},
        {arc::Keyboard::Tab,        SDLK_UNKNOWN},
        {arc::Keyboard::PageUp,     SDLK_UNKNOWN},
        {arc::Keyboard::PageDown,   SDLK_UNKNOWN},
        {arc::Keyboard::End,        SDLK_UNKNOWN},
        {arc::Keyboard::Home,       SDLK_UNKNOWN},
        {arc::Keyboard::Insert,     SDLK_UNKNOWN},
        {arc::Keyboard::Delete,     SDLK_UNKNOWN},
        {arc::Keyboard::Add,        SDLK_UNKNOWN},
        {arc::Keyboard::Subtract,   SDLK_UNKNOWN},
        {arc::Keyboard::Multiply,   SDLK_UNKNOWN},
        {arc::Keyboard::Divide,     SDLK_UNKNOWN},
        {arc::Keyboard::Left,       SDLK_UNKNOWN},
        {arc::Keyboard::Right,      SDLK_UNKNOWN},
        {arc::Keyboard::Up,         SDLK_UNKNOWN},
        {arc::Keyboard::Down,       SDLK_UNKNOWN},
        {arc::Keyboard::Numpad0,    SDLK_UNKNOWN},
        {arc::Keyboard::Numpad1,    SDLK_UNKNOWN},
        {arc::Keyboard::Numpad2,    SDLK_UNKNOWN},
        {arc::Keyboard::Numpad3,    SDLK_UNKNOWN},
        {arc::Keyboard::Numpad4,    SDLK_UNKNOWN},
        {arc::Keyboard::Numpad5,    SDLK_UNKNOWN},
        {arc::Keyboard::Numpad6,    SDLK_UNKNOWN},
        {arc::Keyboard::Numpad7,    SDLK_UNKNOWN},
        {arc::Keyboard::Numpad8,    SDLK_UNKNOWN},
        {arc::Keyboard::Numpad9,    SDLK_UNKNOWN},
        {arc::Keyboard::F1,         SDLK_UNKNOWN},
        {arc::Keyboard::F2,         SDLK_UNKNOWN},
        {arc::Keyboard::F3,         SDLK_UNKNOWN},
        {arc::Keyboard::F4,         SDLK_UNKNOWN},
        {arc::Keyboard::F5,         SDLK_UNKNOWN},
        {arc::Keyboard::F6,         SDLK_UNKNOWN},
        {arc::Keyboard::F7,         SDLK_UNKNOWN},
        {arc::Keyboard::F8,         SDLK_UNKNOWN},
        {arc::Keyboard::F9,         SDLK_UNKNOWN},
        {arc::Keyboard::F10,        SDLK_UNKNOWN},
        {arc::Keyboard::F11,        SDLK_UNKNOWN},
        {arc::Keyboard::F12,        SDLK_UNKNOWN},
        {arc::Keyboard::F13,        SDLK_UNKNOWN},
        {arc::Keyboard::F14,        SDLK_UNKNOWN},
        {arc::Keyboard::F15,        SDLK_UNKNOWN},
        {arc::Keyboard::Pause,      SDLK_UNKNOWN}

    }; // keyboardMap

} // namespace sfml

#endif // __SFML_KEYBOARD_H__