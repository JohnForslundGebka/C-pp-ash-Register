#include "menu.h"

//prints all the choices from the menu
void Menu::displayMenuItems() const
{
    int i = 0; // Start from 0
    for (const auto& temp : items)
    {
        std::cout << ++i << ". " << temp.name << std::endl;
    }
}

//main loop of the menu class
void Menu::run()
{
    while (true)
    {
        std::cout << "\nChoose an option (0 to exit):" << std::endl;
        displayMenuItems();

        int choice;
        std::cin >> choice;

        if (choice == 0) {
            break; // Exit the menu
        }

        if (choice >= 1 && choice <= items.size()) {
            MenuItem &selected = items[choice - 1];

            if (std::holds_alternative<function>(selected.func)) {

                std::any param;
                std::get<function>(selected.func)(param);

            } else if (std::holds_alternative<Menu *>(selected.func)) {
                Menu *submenu = std::get<Menu *>(selected.func);
                submenu->run();
            }
        } else
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

}

