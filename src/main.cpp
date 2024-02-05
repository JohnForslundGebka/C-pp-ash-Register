#include "databaseQueries.h"
#include "article.h"
#include "menu.h"
#include "databaseQueries.h"
#include "clothing.h"
#include <iostream>
#include <any>





int main()
{
    auto printProd = [](std::any &param){
        Clothing test(2005);

        std::cout << "Nu har vi testar kläder. artikeln är: " << test.getTitle() << " och den har märket " << test.getBrand() << " och den kostar " << test.getRetailPrice()
                  << "\n vi har " << test.getAmount() << "st i lager just nu";
        std::cout << "\npress 0 to exit";
        int choice{};
        std::cin >> choice;

    };



    Menu mainMenu;
   Menu manageProducts;
   Menu sale;
   Menu transactions;

   mainMenu.addSubMenu("Manage Products", &manageProducts);
   mainMenu.addSubMenu("Make A Sale", &sale);
   mainMenu.addSubMenu("Transaction History",&transactions);

   manageProducts.addMenuFunction("Show Info", printProd);





     mainMenu.run();




}