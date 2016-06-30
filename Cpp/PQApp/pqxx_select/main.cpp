/** Example of using MPL algorithms */
#include <iostream>
#include <cstdlib>
#include <string>

#include <pqxx/pqxx>
#include <pqxx/nontransaction>


int main()
{

  pqxx::connection c("dbname=sandbox");
  
  try 
    {
      // example 1
      pqxx::work w(c);
      pqxx::result r = w.exec("SELECT 1");

      w.commit();

      std::cout << r[0][0].as<int>() << std::endl;
      
  } 
  catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
      exit(EXIT_FAILURE);
  }

  try {
      // example 2
      pqxx::work w(c);

      std::string text = "Some little message";

      pqxx::result r = w.exec("SELECT" + w.quote(text));
      w.commit();

      std::cout << r[0][0].c_str() << std::endl;

  }  catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
      exit(EXIT_FAILURE);
  }

  try {
    // example 3
    pqxx::nontransaction w(c);
    pqxx::result r;
    
     r = w.exec("SELECT 1;");
     std::cout << r[0][0].c_str() << std::endl;

     r = w.exec("SELECT 2;");
     std::cout << r[0][0].c_str() << std::endl;
     
     //w.exec("commit;");

  } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
      exit(EXIT_FAILURE);    
  }
  
  try {
    if (c.is_open()) {
      
      std::string sql = "SELECT * FROM COMPANY";
      
      pqxx::nontransaction w(c);

      // Execute sql 
      pqxx::result r(w.exec(sql));

      // Loot at all records
      for (pqxx::result::const_iterator it = r.begin(); it != r.end(); it++) {
        std::cout << "ID = " << it[0].as<int>() << std::endl;
        std::cout << "Name = " << it[1].as<std::string>() << std::endl;
        std::cout << "Age = " << it[2].as<int>() << std::endl;
        std::cout << "Address = " << it[3].as<std::string>() << std::endl;
        std::cout << "Salary = " << it[4].as<float>() << std::endl;
      }
      
      std::cout << "Selection done." << std::endl;

    } else {
      std::cout << "Can`t open database";
      exit(EXIT_FAILURE);
    }
      
  } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
      exit(EXIT_FAILURE);    
  }


  c.disconnect();

  exit(EXIT_SUCCESS);
}
