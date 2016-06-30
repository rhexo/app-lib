template <typename T1, typename T2>
struct data
{
  data(T1 t1, T2 t2) : _t1(t1), _t2(t2) {}
  T1 _t1;
  T2 _t2;
};

int main ()
{
  data<int,long> t1(10, 20);
};
