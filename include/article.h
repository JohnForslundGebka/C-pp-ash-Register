#ifndef C_PP_ASH_REGISTER_ARTICLE_H
#define C_PP_ASH_REGISTER_ARTICLE_H
#include <string>

class Article
{
private:
    std::string m_title{};
    const int m_artNumber{};
    const double m_purchasePrice{};
    const double m_retailPrice{};
    int m_amount{};

public:
    Article(std::string title, int artNumber, double purchasePrice,  double retailPrice, int amount);

    //get functions
    std::string getTitle() const { return m_title; }
    int getArtNumber() const { return m_artNumber; }
    double getPurchasePrice() const { return m_purchasePrice; }
    double getRetailPrice() const { return m_retailPrice; }
    int getAmount() const { return m_amount; }

};

#endif
