/** Example of using MPL algorithms */
#include <iostream>
#include <cstdlib>
#include <string>

#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

int main(int argc, char* argv[])
{
  
  try {
    // Create connection object
    connection C("dbname=sandbox user=rhexo hostaddr=127.0.0.1 port=5432"); //password=...

    if (C.is_open()){
      cout << "Opened database successfuly : " << C.dbname() << endl;
    } else {
      cout << "can`t open database." << endl;
      exit(EXIT_FAILURE);
    }
    
    /** Create sql statement */

    string sql = "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) " \
      "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
      "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) " \
      "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); " \
      "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) " \
      "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 ); " \
      "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) " \
      "VALUES (4, 'Mark', 25, 'Rich-Mond', 65000.00 );";

    /** Create transactional object */
    work W(C);

    /** Execute SQL query */
    W.exec(sql);
    W.commit();

    cout << "Records created successfully" << endl;

    C.disconnect();
  } catch (const std::exception& e) {
    cerr << e.what() << endl;
   exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}
