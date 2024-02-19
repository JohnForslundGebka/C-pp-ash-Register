// ==============================================================================
// menu.h
// Header file for the Menu class used in the program.
//
// The Menu class provides a dynamic menu system for the console application, allowing
// for the creation of nested menus and the association of menu items with specific
// actions or submenus. This class supports adding menu functions for managing
// articles , processing sales, and viewing transaction history.
// It utilizes std::variant to associate each menu item with either a function call
// or a submenu.
//
// Features:
// - Dynamic menu creation with support for nested submenus.
// - Association of menu items with specific actions through std::function.
// - Clear and intuitive user interface for console-based interaction.
//
// Usage:
// The Menu class is utilized by creating instances for each menu and submenu,
// then adding menu items that trigger specific actions or lead to other submenus.
// The main menu is displayed and controlled through the run() member function.
//
// Author: John Forslund Gebka
// Date: 2024-02-01
// ==============================================================================
#ifndef C_PP_ASH_REGISTER_MENU_H
#define C_PP_ASH_REGISTER_MENU_H
#include <iostream>
#include <vector>
#include <string>
#include <variant>
#include <functional>
#include <any>

//function definition
using function = std::function<void(std::any& param)>;

class Menu
{
private:
    //Menuitem struct. This can either be pointer to a menu object, or a function
    struct MenuItem {
        std::string name{};
        std::variant<function, Menu*> func;
    };
    std::vector<MenuItem> items{};  //vector that contains all the menuitem structs
public:
    void displayMenuItems() const;

    void addMenuFunction(const std::string& name, function menuFunction)
    {
        items.push_back({name, menuFunction});
    }

    void addSubMenu(const std::string& name, Menu* submenu)
    {
        items.push_back({name, submenu});
    }

    void run();

    static void clearScreen();

};
#endif //C_PP_ASH_REGISTER_MENU_H
