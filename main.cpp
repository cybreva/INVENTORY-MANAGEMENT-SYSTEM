#include <bits/stdc++.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/exception.h>

using namespace std;

int main()
{
    string db_username;
    string db_password;

    cout << "Enter Database Username: ";
    cin >> db_username;

    cout << "Enter Database Password: ";
    cin >> db_password;


    try
    {
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *connection;

        driver = sql::mysql::get_mysql_driver_instance();

        connection = driver->connect(
            "tcp://127.0.0.1:3306",
            db_username,
            db_password
        );

        connection->setSchema("inventory_db");

        cout << "\nDatabase Connected Successfully\n";

        delete connection;
    }
    catch(sql::SQLException &e)
    {
        cout << "\nDatabase Connection Failed\n";
        cout << e.what() << endl;
    }

    return 0;
}