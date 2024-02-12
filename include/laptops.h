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
    const std::string m_table{"laptops_inventory"};
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
