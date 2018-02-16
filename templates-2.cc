template<typename> struct vector {};
template<typename, typename> struct map {};

void fn_1(vector<int>);
void fn_2(map<map<int, vector<float>>, vector<float>>);

void test()
{
  fn_1(vector<double> ());
  fn_2(map<map<int, vector<double>>, vector<double>> ());
}
