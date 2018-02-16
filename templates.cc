template<typename> struct vector {};
template<typename, typename> struct map {};

void fn_1(vector<int>);
void fn_2(map<int, int>);

void test()
{
  fn_1(vector<double> ());
  fn_2(map<int, double>());
}
