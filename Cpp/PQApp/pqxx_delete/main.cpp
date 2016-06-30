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
    
    /* Create a transactional object. */
    work W(C);
    
    /* Create a sql update statement */
    string sql = "DELETE from COMPANY WHERE ID=2";
    /* Execute query */
    W.exec(sql);
    W.commit();

    cout << "recors updated successfully" << endl;

    /** Create sqlselect statement */

    sql = "SELECT * FROM COMPANY;";
    /** Create nontransactional object */
    nontransaction N(C);

    /** Execute SQL query */
    result R(N.exec(sql));

      // Loot at all records
      for (result::const_iterator it = R.begin(); it != R.end(); it++) {
        cout << "ID = " << it[0].as<int>() << std::endl;
        cout << "Name = " << it[1].as<std::string>() << std::endl;
        cout << "Age = " << it[2].as<int>() << std::endl;
        cout << "Address = " << it[3].as<std::string>() << std::endl;
        std::cout << "Salary = " << it[4].as<float>() << std::endl;     }

    C.disconnect();
  } catch (const std::exception& e) {
    cerr << e.what() << endl;
   exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}
