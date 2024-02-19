#ifndef C_PP_ASH_REGISTER_MENUFUNCTION_H
#define C_PP_ASH_REGISTER_MENUFUNCTION_H
#include "article.h"
#include "menu.h"
#include "databaseQueries.h"
#include "clothing.h"
#include "books.h"
#include "laptops.h"
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
    static std::vector<std::string> transactionNumbers;
    static void printArticleInfo(std::any &param);
    static void sale(std::any &param);
    static std::unique_ptr<Article>createArticle(int articleNumber);
    static void createReceipt( std::vector<std::pair<std::unique_ptr<Article>, int>>&articles);
    static void manageTransactions (std::any &param);
};


#endif //C_PP_ASH_REGISTER_MENUFUNCTION_H


