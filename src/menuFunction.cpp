#include "menuFunction.h"
#include "article.h"
#include "menu.h"
#include "databaseQueries.h"
#include "clothing.h"
#include "books.h"
#include "laptops.h"


void MenuFunction::printArticleInfo(std::any &param)
{
    std::unique_ptr<Article> article;
    while (true)
    {
        int userInputArticleNum{};
        int userChoice{};
        int typeOfArticle{};
        std::cout << "\n====================================\n";
        std::cout << "          Article Information         \n";
        std::cout << "====================================\n\n\n";
        std::cout << "Please enter article number:  ";
        std::cin >> userInputArticleNum;
        typeOfArticle = (userInputArticleNum / 1000);  //used to get the starting number of the article
        switch (typeOfArticle)
        {
            case 1:
                article = std::make_unique<Books>(userInputArticleNum);
                break;
            case 2:
                article = std::make_unique<Clothing>(userInputArticleNum);
                break;
            case 3:
                article = std::make_unique<Laptops>(userInputArticleNum);
                break;
            default:
                std::cout << "ERROR MED SWITCH";
                break;
        }

        Menu::clearScreen();
        article->printInfo();
        std::cout << "===================================="
                  << "\n1. Enter new article number 0. Exit";
        std::cout << "\nChoose an option: ";
        std::cin >> userChoice;
        if (userChoice==1)
            continue;
        else
            break;
    }
}

