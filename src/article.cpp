#include "article.h"
//constructor
Article::Article(std::string title, int artNumber, double purchasePrice, double retailPrice, int amount)
   : m_title(std::move(title))
   , m_artNumber(artNumber)
   , m_purchasePrice(purchasePrice)
   , m_retailPrice(retailPrice)
   , m_amount(amount)
{}


