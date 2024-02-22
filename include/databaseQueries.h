// ==============================================================================
// DatabaseQueries.h
// Header file for the DatabaseQueries class.
//
// The DatabaseQueries class provides an abstraction layer for all database interactions,
// encapsulating the functionality required to query and update the SQLite database.
// This includes operations such as retrieving article information and updating stock levels.
// The class utilizes SQLiteCpp, a C++ wrapper for SQLite, to manage database connections
// and execute SQL statements
//
// Features:
// - Manages a connection to the SQLite database using SQLiteCpp.
// - Provides methods to fetch data from the database based on article number and table name,
//   supporting dynamic retrieval of information for different types of inventory items.
// - Offers functionality to update the stock amount in the database, facilitating the sale
//   and restocking processes.
//
//
// Example:
// DatabaseQueries dbQueries;
// auto statement = dbQueries.getDataFromDb(articleNumber, "laptops_inventory");
// if (statement && statement->executeStep()) {
//     // Process the retrieved data
// }
//
// Author: John Forslund Gebka
// Date: 2024-02-01
// ==============================================================================
#ifndef C_PP_ASH_REGISTER_DATABASEQUERIES_H
#define C_PP_ASH_REGISTER_DATABASEQUERIES_H
#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>
#include <string>
#include <memory>


class DatabaseQueries
{
private:
    std::unique_ptr<SQLite::Database> db;
public:
    DatabaseQueries();

    //Member functions that creates a SQL query for that type of object
    std::unique_ptr<SQLite::Statement> getDataFromDb(int articleNumber,const std::string &table);
    bool updateAmountInDb(int articleNumber,const std::string &table, int newAmount);



};

#endif //C_PP_ASH_REGISTER_DATABASEQUERIES_H
