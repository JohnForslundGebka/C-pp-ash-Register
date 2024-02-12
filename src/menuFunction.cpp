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

void MenuFunction::sale(std::any &param)
{

    std::vector<std::pair<std::unique_ptr<Article>, int>> articles;  // Vector with pair of articles and amount to sell
    int userInputArticleNum{};
    int userChoice{};
    int amountToSell{0};
    double totalPrice{};
    Menu::clearScreen();

    //lambda function for storing the print header
    auto printSaleHeader = [](){
        std::cout << "\n====================================\n";
        std::cout << "          Make A Sale                 \n";
        std::cout << "====================================\n\n\n";
        std::cout << std::left << std::setw(10) << "ArtNumber" << " | "
                  << std::setw(25) << "Name" << " | "
                  << std::setw(15) << "Amount in Stock" << " | "
                  << std::setw(15) << "Amount to Sell" << " | "
                  << std::setw(10) << "Price"
                  << "\n--------------------------------------------------------------------------------------\n";
    };

    while (true)
    {
        Menu::clearScreen();
        printSaleHeader();
        for (auto &article: articles)
        {
            std::cout << std::left
                      << std::setw(10) << article.first->getArtNumber() << " | "
                      << std::setw(25) << article.first->getTitle() << " | "
                      << std::setw(15) << article.first->getAmount() << " | "
                      << std::setw(15) << amountToSell << " | "
                      << "$" << std::setw(9) << std::fixed << std::setprecision(2) << article.first->getRetailPrice()
                      << "\n";
            totalPrice += (article.first->getRetailPrice() * amountToSell);
        }
        std::cout << "\nTOTAL: " << totalPrice;
        std::cout << "\n--------------------------------------------------------------------------------------\n";
        std::cout << "\nPlease enter article number (0 to exit):  ";
        std::cout << "\nOr enter 1 to make a sale : ";
        std::cin >> userInputArticleNum;
        if (userInputArticleNum==0)
            break;
        else if (userInputArticleNum==1)
        {
            DatabaseQueries q1;
            for (auto &article: articles)
            {
                q1.updateAmountInDb(article.first->getArtNumber(),article.first->getTable(),
                                    (article.first->getAmount() - article.second));
            }
            return;
        }

        auto article = MenuFunction::createArticle(userInputArticleNum);
        if (!article)   // Check if article is nullptr
        {
            std::cout << "Invalid article number. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(256, '\n'); // Ignores the rest of the incorrect input
            continue;  // Skip adding to the vector and prompt again
        }
        std::cout << "\nAmount to sell: ";
        std::cin >> amountToSell;
        articles.emplace_back(std::move(article), amountToSell);
    }







}

