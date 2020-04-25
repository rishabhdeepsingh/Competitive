#include "gtest/gtest.h"
#include "../../library/Point.hpp"

const Pint ZERO(0, 0, 0);
const Pint ONE(1, 1, 1);
const Pint TWO(2, 2, 2);
const Pint FOUR(4, 4, 4);

TEST(basic_check, test_sum){
  Pint a(1,1,1);
  a += ONE;
  EXPECT_EQ(a, TWO);
  a = ONE;
  a = ONE + ONE;
  EXPECT_EQ(a, TWO);
  Pint b(2,2,2);
  Pint c(4,4,4);
  a = ONE + ONE;
  EXPECT_EQ(a, TWO);
  a += a;
  EXPECT_EQ(a, c);
  
}

TEST(basic_check, test_sub){
  Pint a(1,1,1);
  a -= ONE;
  EXPECT_EQ(a, ZERO);
  a = ONE;
  a = ONE - ONE;
  EXPECT_EQ(a, ZERO);
  a = FOUR;
  a -= TWO;
  EXPECT_EQ(a, TWO);
  a = ONE + ONE;
}

TEST(basic_check, test_pro){
  Pint a = ONE;
  a *= 4;
  EXPECT_EQ(a, FOUR);
}