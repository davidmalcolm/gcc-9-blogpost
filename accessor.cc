class foo
{
public:
  double get_ratio() const { return m_ratio; }

private:
  double m_ratio;
};

void test(foo *ptr)
{
  if (ptr->m_ratio >= 0.5)
    ;// etc
}
