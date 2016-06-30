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
    
    C.disconnect();
  } catch (const std::exception& e) {
    cerr << e.what() << endl;
   exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}
