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
    Article();

    //get functions
    std::string getTitle() const { return m_title; }
    int getArtNumber() const { return m_artNumber; }
    double getPurchasePrice() const { return m_purchasePrice; }
    double getRetailPrice() const { return m_retailPrice; }
    int getAmount() const { return m_amount; }

    // Setter functions
    void setTitle(const std::string& title) { m_title = title; }
    void setArtNumber(int artNumber) { m_artNumber = artNumber; }
    void setPurchasePrice(double purchasePrice) { m_purchasePrice = purchasePrice; }
    void setRetailPrice(double retailPrice) { m_retailPrice = retailPrice; }
    void setAmount(int amount) { m_amount = amount; }

};

#endif
