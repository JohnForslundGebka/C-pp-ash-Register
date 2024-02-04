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


    std::unique_ptr<SQLite::Statement> getDataFromDb(int articleNumber,const std::string &table);
    void updateAmountInDb(int articleNumber,const std::string &table);



};

#endif //C_PP_ASH_REGISTER_DATABASEQUERIES_H
