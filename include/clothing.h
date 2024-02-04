#ifndef C_PP_ASH_REGISTER_CLOTHING_H
#define C_PP_ASH_REGISTER_CLOTHING_H
#include <string>
#include "article.h"

class Clothing : public Article
{
private:
    std::string m_size{};
    std::string m_color{};
    const std::string m_table{"clothes"};
public:
    Clothing(std::string title, int artNumber, double purchasePrice, double retailPrice, int amount, std::string table, std::string size, std::string color);
    explicit Clothing(int artNumber);


    std::string getSize() const { return m_size; }
    std::string getColor() const { return m_color; }

};


#endif //C_PP_ASH_REGISTER_CLOTHING_H
