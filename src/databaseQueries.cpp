#include "databaseQueries.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include <memory>

//constructor for the DBquery class
DatabaseQueries::DatabaseQueries()
: db(std::make_unique<SQLite::Database>("/Users/John/CLionProjects/C-pp-ash-Register/db/CashRegisterDB.db", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE)) {}

//returns a pointer to that specific query. which can then be used to fill article objects with data
std::unique_ptr<SQLite::Statement> DatabaseQueries::getDataFromDb(int articleNumber, const std::string &table) {
    try {
        //string with the SQL query
        std::string sql = "SELECT * FROM " + table + " WHERE article_number = ?";

        auto query = std::make_unique<SQLite::Statement>(*db, sql);
        query->bind(1, articleNumber);
        return query;
    } catch (const std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
        return nullptr;
    }
}

//function that changes the amount of the article in stock
bool DatabaseQueries::updateAmountInDb(int articleNumber, const std::string &table, int newAmount)
{
   try {
       std::string sql = "UPDATE " + table + " SET amount_in_stock = ? WHERE article_number = ?";
       SQLite::Statement query(*db, sql);  //create the SQL statement

       // Bind parameters to the query
       query.bind(1, newAmount);
       query.bind(2, articleNumber);

       // exec() executes the query and returns the number of affected rows
       return (query.exec() > 0);

   } catch (const std::exception& e)
   {

       std::cerr << "Database error: " << e.what() << "\n";
   }



}

