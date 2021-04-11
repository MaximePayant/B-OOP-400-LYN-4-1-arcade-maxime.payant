/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** NcursesKeyboard.hpp
*/

#ifndef __NCURSESKEYBOARD_H__
#define __NCURSESKEYBOARD_H__

#include <unordered_map>

#include "../../../inc/Keyboard.hpp"

namespace ncs
{

    static const std::unordered_map<arc::Keyboard, int> keyboardMap =
    {
        {arc::Keyboard::Unknown,    -1},
        {arc::Keyboard::A,          'a'},
        {arc::Keyboard::B,          'b'},
        {arc::Keyboard::C,          'c'},
        {arc::Keyboard::D,          'd'},
        {arc::Keyboard::E,          'e'},
        {arc::Keyboard::F,          'f'},
        {arc::Keyboard::G,          'g'},
        {arc::Keyboard::H,          'h'},
        {arc::Keyboard::I,          'i'},
        {arc::Keyboard::J,          'j'},
        {arc::Keyboard::K,          'k'},
        {arc::Keyboard::L,          'l'},
        {arc::Keyboard::M,          'm'},
        {arc::Keyboard::N,          'n'},
        {arc::Keyboard::O,          'o'},
        {arc::Keyboard::P,          'p'},
        {arc::Keyboard::Q,          'q'},
        {arc::Keyboard::R,          'r'},
        {arc::Keyboard::S,          's'},
        {arc::Keyboard::T,          't'},
        {arc::Keyboard::U,          'u'},
        {arc::Keyboard::V,          'v'},
        {arc::Keyboard::W,          'w'},
        {arc::Keyboard::X,          'x'},
        {arc::Keyboard::Y,          'y'},
        {arc::Keyboard::Z,          'z'},
        {arc::Keyboard::Num0,       -1},
        {arc::Keyboard::Num1,       -1},
        {arc::Keyboard::Num2,       -1},
        {arc::Keyboard::Num3,       -1},
        {arc::Keyboard::Num4,       -1},
        {arc::Keyboard::Num5,       -1},
        {arc::Keyboard::Num6,       -1},
        {arc::Keyboard::Num7,       -1},
        {arc::Keyboard::Num8,       -1},
        {arc::Keyboard::Num9,       -1},
        {arc::Keyboard::Escape,     -27},
        {arc::Keyboard::LControl,   -1},
        {arc::Keyboard::LShift,     -1},
        {arc::Keyboard::LAlt,       -1},
        {arc::Keyboard::LSystem,    -1},
        {arc::Keyboard::RControl,   -1},
        {arc::Keyboard::RShift,     -1},
        {arc::Keyboard::RAlt,       -1},
        {arc::Keyboard::RSystem,    -1},
        {arc::Keyboard::Menu,       -1},
        {arc::Keyboard::LBracket,   -1},
        {arc::Keyboard::RBracket,   -1},
        {arc::Keyboard::Semicolon,  -1},
        {arc::Keyboard::Comma,      -1},
        {arc::Keyboard::Period,     -1},
        {arc::Keyboard::Quote,      -1},
        {arc::Keyboard::Slash,      -1},
        {arc::Keyboard::Backslash,  -1},
        {arc::Keyboard::Tilde,      -1},
        {arc::Keyboard::Equal,      -1},
        {arc::Keyboard::Hyphen,     -1},
        {arc::Keyboard::Space,      ' '},
        {arc::Keyboard::Enter,      '\n'},
        {arc::Keyboard::Backspace,  KEY_BACKSPACE},
        {arc::Keyboard::Tab,        -1},
        {arc::Keyboard::PageUp,     KEY_PPAGE},
        {arc::Keyboard::PageDown,   KEY_NPAGE},
        {arc::Keyboard::End,        -1},
        {arc::Keyboard::Home,       KEY_HOME},
        {arc::Keyboard::Insert,     -1},
        {arc::Keyboard::Delete,     -1},
        {arc::Keyboard::Add,        -1},
        {arc::Keyboard::Subtract,   -1},
        {arc::Keyboard::Multiply,   -1},
        {arc::Keyboard::Divide,     -1},
        {arc::Keyboard::Left,       KEY_LEFT},
        {arc::Keyboard::Right,      KEY_RIGHT},
        {arc::Keyboard::Up,         KEY_UP},
        {arc::Keyboard::Down,       KEY_DOWN},
        {arc::Keyboard::Numpad0,    -1},
        {arc::Keyboard::Numpad1,    -1},
        {arc::Keyboard::Numpad2,    -1},
        {arc::Keyboard::Numpad3,    -1},
        {arc::Keyboard::Numpad4,    -1},
        {arc::Keyboard::Numpad5,    -1},
        {arc::Keyboard::Numpad6,    -1},
        {arc::Keyboard::Numpad7,    -1},
        {arc::Keyboard::Numpad8,    -1},
        {arc::Keyboard::Numpad9,    -1},
        {arc::Keyboard::F1,         -1},
        {arc::Keyboard::F2,         -1},
        {arc::Keyboard::F3,         -1},
        {arc::Keyboard::F4,         -1},
        {arc::Keyboard::F5,         -1},
        {arc::Keyboard::F6,         -1},
        {arc::Keyboard::F7,         -1},
        {arc::Keyboard::F8,         -1},
        {arc::Keyboard::F9,         -1},
        {arc::Keyboard::F10,        -1},
        {arc::Keyboard::F11,        -1},
        {arc::Keyboard::F12,        -1},
        {arc::Keyboard::F13,        -1},
        {arc::Keyboard::F14,        -1},
        {arc::Keyboard::F15,        -1},
        {arc::Keyboard::Pause,      -1},
    };

}

#endif // __NCURSESKEYBOARD_H__