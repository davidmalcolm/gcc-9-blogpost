extern void log (const char *);
struct boxed_ptr {
  void *m_ptr;
  boxed_ptr& operator=(const boxed_ptr& other) {
    log ("operator=\n");
    m_ptr = other.m_ptr;
  }
};
