extern int callee(int one, const char *two, float three);

int caller(int first, int second, float third)
{
  return callee(first, second, third);
}
