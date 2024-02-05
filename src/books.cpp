#include "books.h"



Books::Books(int articleNumber)
{
    DatabaseQueries q1;
    //create a pointer that points to a query from the DatabaseQueries class
    auto query = q1.getDataFromDb(articleNumber, m_table);

    if (query->executeStep())
    {
        setTitle(query->getColumn("name").getText());
        setArtNumber(articleNumber);
        setPurchasePrice(query->getColumn("purchase_price").getDouble());
        setRetailPrice(query->getColumn("retail_price").getDouble());
        setAmount(query->getColumn("amount_in_stock").getInt());
        m_author = (query->getColumn("author").getText());
        m_isbn = (query->getColumn("isbn").getInt());
    }
}

void Books::printInfo() const
{
    std::cout << "\nBook Information:\n";
    std::cout << "====================================\n";
    std::cout << "Title: " << getTitle() << "\n";
    std::cout << "Author: " << m_author << "\n";
    std::cout << "Article Number: " << getArtNumber() << "\n";
    std::cout << "ISBN: " << m_isbn << "\n";
    std::cout << "Purchase Price: $" << getPurchasePrice() << "\n";
    std::cout << "Retail Price: $" << getRetailPrice() << "\n";
    std::cout << "Amount in Stock: " << getAmount() << "\n";

}