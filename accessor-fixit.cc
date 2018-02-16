/* Misspelling (by omitting a leading "m_") of a private member for which
   there's a public accessor.

   We expect a fix-it hint suggesting the accessor.  */

class t
{
public:
  int get_ratio () const { return m_ratio; }

private:
  int m_ratio;
};

int test (t *ptr)
{
  return ptr->ratio;
}
