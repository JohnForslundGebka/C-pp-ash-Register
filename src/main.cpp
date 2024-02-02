#include "article.h"
#include "menu.h"
#include <iostream>



int main()
{

   Menu mainMenu;
   Menu manageProducts;
   Menu sale;
   Menu transactions;

   mainMenu.addSubMenu("Manage Products", &manageProducts);
   mainMenu.addSubMenu("Make A Sale", &sale);
   mainMenu.addSubMenu("Transaction History",&transactions);

   mainMenu.run();




}