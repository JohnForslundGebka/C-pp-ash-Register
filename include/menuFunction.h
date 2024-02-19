// ==============================================================================
// MenuFunction.h
// Declaration of the MenuFunction class for the C-pp-ash-Register.
//
// This class provides static methods to handle various menu actions, including
// printing article information, handling sales, creating articles, managing
// transactions, and generating receipts. The class operates on a static vector
// of transaction numbers to track sales transactions within the application.
//
// Author: John Forslund Gebka
// Date: 2024-02-01
// ==============================================================================

#ifndef C_PP_ASH_REGISTER_MENUFUNCTION_H
#define C_PP_ASH_REGISTER_MENUFUNCTION_H
#include "article.h"  // Include the base Article class header
#include "menu.h"
#include "databaseQueries.h"
#include "clothing.h"
#include "books.h"
#include "laptops.h"
// System/Library headers
#include <any>
#include <iostream>
#include <vector>
#include <utility>
#include <random>
#include <fstream>
#include <string>
#include <ctime>

class MenuFunction
{
public:
    //A static vector that contains transaction numbers. Numbers are added when a sale is made
    static std::vector<std::string> transactionNumbers;

    static void printArticleInfo(std::any &param);

    static void sale(std::any &param);

    static std::unique_ptr<Article>createArticle(int articleNumber);

    static void createReceipt( std::vector<std::pair<std::unique_ptr<Article>, int>>&articles);

    static void manageTransactions (std::any &param);

    static bool printTransaction(std::string transaction);

};


#endif //C_PP_ASH_REGISTER_MENUFUNCTION_H


