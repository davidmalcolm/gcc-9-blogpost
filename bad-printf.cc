#include <stdio.h>

void print_field (const char *fieldname, float value,
		  long column, long width)
{
  printf ("%s: %*ld ", fieldname, column - width, value);
}
