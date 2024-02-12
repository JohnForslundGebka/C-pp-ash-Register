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


class MenuFunction
{
public:
    static void printArticleInfo(std::any &param);
    static void sale(std::any &param);
    static std::unique_ptr<Article>createArticle(int articleNumber);

};


#endif //C_PP_ASH_REGISTER_MENUFUNCTION_H


