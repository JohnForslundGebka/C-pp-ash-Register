// ==============================================================================
// laptops.h
// Header file for the Laptops class
//
// The Laptops class represents laptop items in the inventory, extending the generic
// Article class to include specific attributes relevant to laptops, such as brand,
// RAM, CPU, and hard drive specifications.
//
// Features:
// - Inherits from Article to leverage common inventory item attributes.
// Usage:
// Utilized within the inventory management system for creating, updating,
// and displaying information specific to laptop inventory items. The Laptops
// class integrates seamlessly with the database for persistent storage and retrieval
// of item details.
//
// Author: John Forslund Gebka
// Date: 2024-02-01
// ==============================================================================
#ifndef C_PP_ASH_REGISTER_LAPTOPS_H
#define C_PP_ASH_REGISTER_LAPTOPS_H
#include "databaseQueries.h"
#include "article.h"

class Laptops :public Article
{
private:
      std::string m_brand{};
      std::string m_ram{};
      std::string m_cpu{};
      std::string m_hardDrive{};
    const std::string m_table{"laptops_inventory"}; //table in the database
public:
  Laptops() : m_brand(), m_ram(), m_cpu(), m_hardDrive() {} // default constructor
  explicit Laptops(int articleNumber);

   //getter functions
    std::string getBrand() const { return m_brand; }
    std::string getRam() const { return m_ram; }
    std::string getCpu() const { return m_cpu; }
    std::string getHardDrive() const { return m_hardDrive; }
    std::string getTable() const override { return m_table; }

    void printInfo() const override;


};


#endif //C_PP_ASH_REGISTER_LAPTOPS_H
