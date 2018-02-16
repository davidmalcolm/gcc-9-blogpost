#define N 1024

void test (int *p, int *q)
{
  int i;

  for (i = 0; i < N; i++)
    {
      p[i] = q[i];
      asm volatile ("" ::: "memory");
    }
}
