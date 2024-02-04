#include "databaseQueries.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include <memory>

//constructor for the DBquery class
DatabaseQueries::DatabaseQueries()
: db(std::make_unique<SQLite::Database>("/db/CashRegisterDB.db", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE)) {}

//returns a pointer to that specefic query. which can then be used to fill article objects with data
std::unique_ptr<SQLite::Statement> DatabaseQueries::getDataFromDb(int articleNumber, const std::string &table) {
    try {

        std::string sql = "SELECT * FROM " + table + " WHERE ArticleNumber = ?";

        auto query = std::make_unique<SQLite::Statement>(*db, sql);
        query->bind(1, articleNumber);
        return query;
    } catch (const std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
        return nullptr;
    }
}
