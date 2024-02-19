#include "menu.h"
#include "menuFunction.h"
#include <vector>
#include <iostream>
#include <string>



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
    transactions.addMenuFunction("Trans List",MenuFunction::manageTransactions);

    mainMenu.run();




}