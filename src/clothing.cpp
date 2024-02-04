#include "clothing.h"
#include "databaseQueries.h"


Clothing::Clothing(std::string title, int artNumber, double purchasePrice, double retailPrice, int amount, std::string table, std::string size, std::string color)
: Article(title, artNumber, purchasePrice, retailPrice, amount), m_size(size), m_color(color) {}


Clothing::Clothing(int artNumber)
{
    DatabaseQueries q1;
    //create a pointer that points to a query from the DatabaseQueries class
    auto query = q1.getDataFromDb(artNumber, m_table);

    if (query->executeStep())
    {
        setTitle(query->getColumn("Title").getText());
        setArtNumber(artNumber);
        setPurchasePrice(query->getColumn("purchase_price").getDouble());
        setRetailPrice(query->getColumn("retail_price").getDouble());
        setAmount(query->getColumn("amount_in_stock").getInt());
        m_size = query->getColumn("size").getText();
        m_color = query->getColumn("color").getText();
    }



}

