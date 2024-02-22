// ==============================================================================
// clothing.h
// Header file for the Clothing class
//
// The Clothing class represents clothing items in the inventory,
//
// Features:
// - Inherits from Article to leverage common inventory item attributes.
// Usage:
// Utilized within the inventory management system for creating, updating,
// and displaying information specific to laptop clothing items.
//
// Author: John Forslund Gebka
// Date: 2024-02-01
// ==============================================================================
#ifndef C_PP_ASH_REGISTER_CLOTHING_H
#define C_PP_ASH_REGISTER_CLOTHING_H
#include <string>
#include "article.h"

class Clothing : public Article
{
private:
    std::string m_brand{};
    std::string m_size{};
    std::string m_color{};
    const std::string m_table{"clothes_inventory"};
public:
    //constructor
    Clothing(std::string title, int artNumber, double purchasePrice, double retailPrice, int amount, std::string table, std::string size, std::string color, std::string brand);
    explicit Clothing(int artNumber);

   //getter functions
    std::string getBrand() const { return m_brand; }
    std::string getSize() const { return m_size; }
    std::string getColor() const { return m_color; }
    std::string getTable() const override { return m_table; }

    void printInfo()const override;

};


#endif //C_PP_ASH_REGISTER_CLOTHING_H
