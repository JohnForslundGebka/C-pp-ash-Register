#include "databaseQueries.h"
#include "article.h"
#include "menu.h"
#include "databaseQueries.h"
#include "clothing.h"
#include <iostream>
#include <any>

void printArticleInfo(std::any &param)
{
    int userInputArticleNum{};
    std::cout << "\n====================================\n";
    std::cout << "          Article Information         \n";
    std::cout << "====================================\n\n\n";
    std::cout << "Please enter article number:  ";
    std::cin >> userInputArticleNum;

    Clothing article(userInputArticleNum);





}




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