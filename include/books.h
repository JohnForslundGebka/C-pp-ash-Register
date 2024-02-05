#ifndef C_PP_ASH_REGISTER_BOOKS_H
#define C_PP_ASH_REGISTER_BOOKS_H
#include "databaseQueries.h"
#include "article.h"
#include <iostream>


class Books : public Article
{
private:
   std::string m_author{};
   long m_isbn{};
   const std::string m_table{"books_inventory"};
public:
    Books() : m_author(0), m_isbn(0), m_table(0){}
    Books(int articleNumber);

    //getter function
    std::string getAuthor() const { return m_author; }
    long getIsbn() const { return m_isbn; }

    void printInfo() const override;

};


#endif //C_PP_ASH_REGISTER_BOOKS_H
