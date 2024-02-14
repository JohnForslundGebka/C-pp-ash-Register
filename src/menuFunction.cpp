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

//function that prints out the info about selected article, name, price and so on
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

    auto errorMsg = [](){

    };

    // Vector with std::pair with articles and amount to sell
    std::vector<std::pair<std::unique_ptr<Article>, int>> articles;
    int userInputArticleNum{};
    bool wrongArtNumber{false};
    int userChoice{};
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
        int amountToSell{};
        Menu::clearScreen();
        printSaleHeader();
        //print out article information
        for (auto &article: articles)
        {
            std::cout << std::left
                      << std::setw(10) << article.first->getArtNumber() << " | "
                      << std::setw(25) << article.first->getTitle() << " | "
                      << std::setw(15) << article.first->getAmount() << " | "
                      << std::setw(15) << article.second << " | "
                      << "$" << std::setw(9) << std::fixed << std::setprecision(2) << article.first->getRetailPrice()
                      << "\n";
          if (!wrongArtNumber)
              totalPrice += (article.first->getRetailPrice() * article.second);
        }

        std::cout << "\nTOTAL: " << totalPrice;
        std::cout << "\n--------------------------------------------------------------------------------------\n";
        if (wrongArtNumber) std::cout << "Article number does not exist";
        std::cout << "\nPlease enter article number, or enter 1 to make a sale (0 to exit) :  ";
        std::cin >> userInputArticleNum;

        if (userInputArticleNum==0)
            break;
        else if (userInputArticleNum==1)
        {
            //create a database query object that will be used to make a query to DB and update amount
            DatabaseQueries q1;
            for (auto &article: articles)
            {
                //update the amount of an article in the DB
                q1.updateAmountInDb(article.first->getArtNumber(),article.first->getTable(),
                                    (article.first->getAmount() - article.second));
            }
            MenuFunction::createReceipt(articles); //create and "print" a receipt
            return; //exit function when done updating the amount of articles in DB
        }

        //create a pointer that points to an article subclass (laptop, books, or clothes)
        auto article = MenuFunction::createArticle(userInputArticleNum);
        if (!article)   // Check if article is nullptr aka wrong article number was entered
        {
            std::cout << "Invalid article number. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(256, '\n'); // Ignores the rest of the incorrect input
            wrongArtNumber = true;
            continue;  // Skip adding to the vector and prompt again
        }
        //checks how many to sell
        std::cout << "\nAmount to sell: ";
        std::cin >> amountToSell;
        articles.emplace_back(std::move(article), amountToSell);  //add the new article pointer to vector
        wrongArtNumber = false;
    }
}

//creates a .txt with the receipt for the sale
void MenuFunction::createReceipt(std::vector<std::pair<std::unique_ptr<Article>, int>> &articles)
{
    // Get the current date and time
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    // Random number engine
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator

    // Define the range
    std::uniform_int_distribution<> distrib(10000000, 99999999);
    //create number
    long recNumber{distrib(gen)};
    //create a string that will be the number/name of the receipt
    std::string recName = "r" + std::to_string(recNumber) + ".txt";

    //check if file could be created
    std::ofstream outf{ recName };
    if (!outf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, .txt could not be opened for writing!\n";
        return;
    }

    // Print the header of the receipt
    outf      << "John's Capital Ventures\n"
              << "Fjallgatan,\n"
              << "Gothenburg, SWE, 06119\n"
              << "(203) 333-2478\n"
              << "-------------------------------------------------\n"
              << std::put_time(&tm, "%a %b %d %H:%M:%S %Y") << std::endl // Formats the date and time
              << "\nCASHIER: John\n"
              << "Receipt Number:" << std::to_string(recNumber) << "\n\n"
              << "  Item              QTY  Unit Price    Total\n"
              << "-------------------------------------------------\n";

    double totalPrice{};
    // Print the items, quantities, unit prices, and totals
    for (auto &article: articles)
    {
        double totPriceOfArticles = (article.first->getRetailPrice() * article.second);

        outf << std::left << std::setw(20) << article.first->getTitle()
             << std::setw(7) << article.second
             << std::setw(10) << std::fixed << std::setprecision(2) << article.first->getRetailPrice()  << "$"
             << std::setw(12) << totPriceOfArticles  << "$" << std::endl;
        totalPrice += totPriceOfArticles;
    }

    // Print the footer of the receipt
    outf << "=================================================\n"
         << std::right << std::setw(30) << "Total:" << std::setw(15) << totalPrice  << "$" << std::endl;


}