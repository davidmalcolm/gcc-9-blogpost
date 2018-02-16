struct foo
{
  static int member_1 (int one, const char **two, float three);
};

int test (int first, const char *second, float third)
{
  return foo::member_1 (first, second, third);
}
