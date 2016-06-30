#include <tuple>
#include <iostream>

using namespace std;

// helper: print element with index IDX of tuple with MAX elements
template<int IDX, int MAX, typename... Args>
  struct PRINT_TUPLE {
    static void print (ostream& strm, const tuple<Args...>& t) {
      strm << get<IDX>(t) << (IDX+1 == MAX ? "" : ",");
      PRINT_TUPLE<IDX+1,MAX,Args...>::print(strm,t);
    }
  };

// partial specialization for end of recursion
template<int MAX, typename... Args>
  struct PRINT_TUPLE<MAX, MAX, Args...> {
  static void print(ostream& strm, const tuple<Args...>& t) { }
};

// output operator for tuples
template<typename... Args>
ostream& operator << (ostream& strm, const tuple<Args...>& t) {
  // result into ostream
  strm << "[";
  PRINT_TUPLE<0,sizeof...(Args),Args...>::print(strm,t);
  return strm << "]";
}
