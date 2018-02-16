struct shape {};

template<typename T>
struct boxed_value
{
  boxed_value& operator* (const boxed_value& other) const;
};

boxed_value<double> width (const shape &s1);
boxed_value<double> height (const shape &s1);

int test (const shape &s1, const shape &s2)
{
  return (width(s1) * height(s1)
	  + width(s2) * height(s2));
}
