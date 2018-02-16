class mystring
{
public:
  int get_length () const { return m_length; }

private:
  int m_length;
};

void hangman (const mystring &str)
{
  if (str.get_length > 0)
    ;
}
