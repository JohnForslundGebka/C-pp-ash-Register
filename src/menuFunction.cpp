#include "menuFunction.h"

std::unique_ptr<Article> MenuFunction::createArticle(int articleNumber)
{
   int typeOfArticle = (articleNumber / 1000);  //used to get the starting number of the article
    switch (typeOfArticle)
    {
        case 1:
            return std::make_unique<Books>(articleNumber);

        case 2:
            return std::make_unique<Clothing>(articleNumber);

        case 3:
            return std::make_unique<Laptops>(articleNumber);

        default:
            std::cout << "ERROR MED SWITCH";
            return nullptr;

    }

}

void MenuFunction::printArticleInfo(std::any &param)
{

    while (true)
    {
        int userInputArticleNum{};
        int userChoice{};

        std::cout << "\n====================================\n";
        std::cout << "          Article Information         \n";
        std::cout << "====================================\n\n\n";
        std::cout << "Please enter article number:  ";
        std::cin >> userInputArticleNum;
        std::unique_ptr<Article> article = MenuFunction::createArticle(userInputArticleNum);

        if (!article)  // Check if article is nullptr
        {
            std::cout << "Invalid article number. Please try again.\n";
            continue;  // Prompt the user again
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


void MenuFunction::sale()
{
    std::cout << "\n====================================\n";
    std::cout << "          Make A Sale                 \n";
    std::cout << "====================================\n\n\n";
    std::cout << "Please enter article number:  ";

}

