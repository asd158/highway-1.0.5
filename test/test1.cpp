#include <gtest/gtest.h>

class my {
 public:
  void getAA() { std::cout << 11; }
};
TEST(test_my, getAA) {
  my a;
  a.getAA();
}