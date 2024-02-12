#include "laptops.h"

Laptops::Laptops(int articleNumber)
{
    DatabaseQueries q1;
    //create a pointer that points to a query from the DatabaseQueries class
    auto query = q1.getDataFromDb(articleNumber, m_table);

    //get data from database to fill member values
    if (query->executeStep())
    {
        setTitle(query->getColumn("name").getText());
        setArtNumber(articleNumber);
        setPurchasePrice(query->getColumn("purchase_price").getDouble());
        setRetailPrice(query->getColumn("retail_price").getDouble());
        setAmount(query->getColumn("amount").getInt());
        m_brand  = (query->getColumn("brand").getText());
        m_ram  = (query->getColumn("ram").getText());
        m_cpu  = (query->getColumn("cpu").getText());
        m_hardDrive  = (query->getColumn("hard_drive").getText());
    }
}

void Laptops::printInfo() const
{
    std::cout << "\nLaptop Information:\n";
    std::cout << "====================================\n";
    std::cout << std::left << std::setw(20) << "Title: " << getTitle() << "\n";
    std::cout << std::setw(20) << "Brand: " << m_brand << "\n";
    std::cout << std::setw(20) << "RAM: " << m_ram << "\n";
    std::cout << std::setw(20) << "CPU: " << m_cpu << "\n";
    std::cout << std::setw(20) << "Hard Drive: " << m_hardDrive << "\n";
    std::cout << std::setw(20) << "Article Number: " << getArtNumber() << "\n";
    std::cout << std::setw(20) << "Purchase Price: " << "$" << getPurchasePrice() << "\n";
    std::cout << std::setw(20) << "Retail Price: " << "$" << getRetailPrice() << "\n";
    std::cout << std::setw(20) << "Amount in Stock: " << getAmount() << "\n";
}
