// ==============================================================================
// Article.h
// Defines the abstract base class Article.
//
// Represents a general article in inventory with common attributes such as title,
// article number, purchase price, retail price, and stock amount. Serves as a
// foundation for more specific article types (e.g., books, clothing, laptops) with
// additional attributes and behaviors. Includes basic getters and setters, and
// requires derived classes to implement getTable() and printInfo() methods.
//
// Author: John Forslund Gebka
// Date: 2024-02-01
// ==============================================================================
#ifndef C_PP_ASH_REGISTER_ARTICLE_H
#define C_PP_ASH_REGISTER_ARTICLE_H
#include <string>

class Article
{
private:
    std::string m_title;
    int m_artNumber;
    double m_purchasePrice;
    double m_retailPrice;
    int m_amount;


public:
    Article(std::string title, int artNumber, double purchasePrice,  double retailPrice, int amount);
    Article() : m_artNumber(0), m_purchasePrice(0.0), m_retailPrice(0.0), m_amount(0) {}  //default constructor

    //get functions
    std::string getTitle() const { return m_title; }
    int getArtNumber() const { return m_artNumber; }
    double getPurchasePrice() const { return m_purchasePrice; }
    double getRetailPrice() const { return m_retailPrice; }
    int getAmount() const { return m_amount; }
    virtual std::string getTable() const = 0;  // Pure virtual function

    // Setter functions
    void setTitle(const std::string& title) { m_title = title; }
    void setArtNumber(int artNumber) { m_artNumber = artNumber; }
    void setPurchasePrice(double purchasePrice) { m_purchasePrice = purchasePrice; }
    void setRetailPrice(double retailPrice) { m_retailPrice = retailPrice; }
    void setAmount(int amount) { m_amount = amount; }


    virtual void printInfo() const = 0; // Pure virtual function

};

#endif
