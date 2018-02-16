enum struct json : int {
  string, object
};

struct foo {
  int e1, e2;
  json e3;
} arr[] = {
  { 1, 2, json::string },
  { 3, json::object },
  { 4, 5, json::string }
};

char buffers[3][5] = { "red", "green", "blue" };

class X {
  X() : one(42), two(42), three(42)
  { }
  void* one;
  int two;
  int three;
};
