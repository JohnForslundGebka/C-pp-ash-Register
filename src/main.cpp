#include "article.h"
#include "menu.h"
#include "databaseQueries.h"
#include "clothing.h"
#include "books.h"
#include "laptops.h"
#include "menuFunction.h"
#include <iomanip>
#include <iostream>
#include <memory>
#include <any>


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


   mainMenu.run();




}