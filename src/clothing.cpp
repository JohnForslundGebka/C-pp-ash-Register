#include "clothing.h"
#include "databaseQueries.h"


Clothing::Clothing(std::string title, int artNumber, double purchasePrice, double retailPrice, int amount, std::string table, std::string size, std::string color, std::string brand)
: Article(title, artNumber, purchasePrice, retailPrice, amount), m_size(size), m_color(color), m_brand(brand) {}


Clothing::Clothing(int artNumber)
{
    DatabaseQueries q1;
    //create a pointer that points to a query from the DatabaseQueries class
    auto query = q1.getDataFromDb(artNumber, m_table);

    if (query->executeStep())
    {
        //fill the object with data from the database
        setTitle(query->getColumn("name").getText());
        setArtNumber(artNumber);
        setPurchasePrice(query->getColumn("purchase_price").getDouble());
        setRetailPrice(query->getColumn("retail_price").getDouble());
        setAmount(query->getColumn("amount_in_stock").getInt());
        m_size = query->getColumn("size").getText();
        m_color = query->getColumn("color").getText();
        m_brand = query->getColumn("brand").getText();
    }
}


void Clothing::printInfo() {
    std::cout << "Clothing Information:" << std::endl;
    std::cout << "Title: " << getTitle() << std::endl;
    std::cout << "Article Number: " << getArtNumber() << std::endl;
    std::cout << "Purchase Price: $" << getPurchasePrice() << std::endl;
    std::cout << "Retail Price: $" << getRetailPrice() << std::endl;
    std::cout << "Amount in Stock: " << getAmount() << std::endl;
    std::cout << "Size: " << getSize() << std::endl;
    std::cout << "Color: " << getColor() << std::endl;
    std::cout << "Brand: " << getBrand() << std::endl;
}

