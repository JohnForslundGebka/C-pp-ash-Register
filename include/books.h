// ==============================================================================
// books.h
// Header file for the Books class
//
// The Books class represents book items in the inventory,
//
// Features:
// - Inherits from Article to leverage common inventory item attributes.
// Usage:
// Utilized within the inventory management system for creating, updating,
// and displaying information specific to Books  items.
//
// Author: John Forslund Gebka
// Date: 2024-02-01
// ==============================================================================
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
    Books() : m_author(), m_isbn(0){}   //default constructor
    explicit Books(int articleNumber);

    //getter function
    std::string getAuthor() const { return m_author; }
    long getIsbn() const { return m_isbn; }
    std::string getTable() const override { return m_table; }

    void printInfo() const override;

};


#endif //C_PP_ASH_REGISTER_BOOKS_H
