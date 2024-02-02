#ifndef C_PP_ASH_REGISTER_MENU_H
#define C_PP_ASH_REGISTER_MENU_H
#include <iostream>
#include <vector>
#include <string>
#include <variant>
#include <functional>
#include <any>

using function = std::function<void(std::any& param)>;

class Menu
{
private:
    struct MenuItem {
        std::string name{};
        std::variant<function, Menu*> func;
    };
    std::vector<MenuItem> items{};
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

};


#endif //C_PP_ASH_REGISTER_MENU_H
