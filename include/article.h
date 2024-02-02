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
    std::string getTitle() { return m_title; }
    int getArtNumber() { return m_artNumber; }


};

#endif
