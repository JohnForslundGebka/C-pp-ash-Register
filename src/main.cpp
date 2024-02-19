// ==============================================================================
// main.cpp
// Entry point for the Inventory Management System application.
//
// This application provides a console-based interface for managing a store's
// inventory, including books, clothing, and laptops. It demonstrates usage of
// object-oriented programming principles, database integration with SQLiteCpp,
//
// Author: John Forslund Gebka
// Date: 2024-02-01
// ==============================================================================

// Local project headers
#include "menu.h"
#include "menuFunction.h"

int main()
{
    Menu mainMenu;
    Menu manageProducts;
    Menu sale;
    Menu transactions;

    mainMenu.addSubMenu("Manage Products", &manageProducts);
    mainMenu.addSubMenu("Make A Sale", &sale);
    mainMenu.addSubMenu("Transaction History",&transactions);

    manageProducts.addMenuFunction("See Article Info",MenuFunction::printArticleInfo);
    sale.addMenuFunction("Make a sale",MenuFunction::sale);
    transactions.addMenuFunction("Transaction History",MenuFunction::manageTransactions);

    mainMenu.run();

}