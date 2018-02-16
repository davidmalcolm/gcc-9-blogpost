namespace json
{
  enum class kind { OBJECT, ARRAY, NUMBER, STRING, TRUE, FALSE, NULL_ };

  struct value
  {
    virtual enum kind get_kind () const = 0;
  };

  void test (const json::value &v)
  {
    if (v.get_kind () == STRING)
      ;
  }
}
