#include <bits/stdc++.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/exception.h>
#include <termios.h>
#include <unistd.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <iomanip>

using namespace std;

string getPassword()
{
    string password;

    termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;

    newt.c_lflag &= ~ECHO;

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    cin >> password;

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return password;
}

int main()
{
    string db_username;
    string db_password;

    cout << "Enter Database Username: ";
    cin >> db_username;

    cout << "Enter Database Password: ";
    db_password = getPassword();

    cout << endl;


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

        cout << "Database Connected Successfully\n";


        sql::Statement *stmt;
        sql::ResultSet *res;


        stmt = connection->createStatement();


        res = stmt->executeQuery(
            "SELECT product_id, product_name, price, quantity FROM products"
        );


        cout << "\n========== INVENTORY ==========\n\n";

        cout << left
             << setw(10) << "ID"
             << setw(20) << "Name"
             << setw(15) << "Price"
             << setw(10) << "Stock"
             << endl;


        cout << "---------------------------------------------\n";


        while(res->next())
        {
            cout << left
                 << setw(10) << res->getInt("product_id")
                 << setw(20) << res->getString("product_name")
                 << setw(15) << res->getDouble("price")
                 << setw(10) << res->getInt("quantity")
                 << endl;
        }


        delete res;
        delete stmt;
        delete connection;
    }

    catch(sql::SQLException &e)
    {
        cout << "Database Error\n";
        cout << e.what() << endl;
    }


    return 0;
}