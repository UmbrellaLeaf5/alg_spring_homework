// std libs:
#include <cmath>
#include <random>

// test lib:
#include <gtest/gtest.h>

// my libs:
#include "temperature.hpp"

// std usings:
using std::cout, std::cin, std::endl;

TEST(Temperature_test, Subtest_1) {
  auto t = Temperature();
  ASSERT_EQ(float(t), 0.f);
  ASSERT_EQ(std::string(t), "0 °C");
}

TEST(Temperature_test, Subtest_2) {
  auto t = Temperature(-10);
  ASSERT_EQ(float(t), -10.f);
  ASSERT_EQ(std::string(t), "-10 °C");
}

TEST(Temperature_test, Subtest_3) {
  auto t = Temperature(-273);
  ASSERT_EQ(float(t), -273.f);
  ASSERT_EQ(std::string(t), "-273 °C");
}

TEST(Temperature_test, Subtest_4) {
  auto t = Temperature(322.5);
  ASSERT_EQ(float(t), 322.5);
  ASSERT_EQ(std::string(t), "322.5 °C");
}

TEST(Temperature_test, Subtest_5) {
  EXPECT_THROW(Temperature(-274), std::logic_error);
}

TEST(Temperature_test, Subtest_6) {
  EXPECT_THROW(Temperature(-84303), std::logic_error);
}

TEST(Temperature_test, Subtest_7) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(-273, 1000);
  for (int i = 0; i < 1000; i++) {
    double x = dis(gen);
    Temperature t(x);

    EXPECT_TRUE(std::abs(float(t) - x) < 1.0E-3);  // приближенно равны
  }
}

TEST(Temperature_test, Subtest_8) {
  struct {
    double x_1, x_2;
  } cases[] = {{0, 1}, {1, 1}, {2, 3}, {2, 2}, {3, 4}, {5, 7}};

  for (auto c : cases) {
    Temperature t_1(c.x_1), t_2(c.x_2);

    ASSERT_EQ((t_1 != t_2), !(t_1 == t_2));
  }
}

TEST(Temperature_test, Subtest_9) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(-273, 1000);
  for (int i = 0; i < 1000; i++) {
    double x_1 = dis(gen);
    double x_2 = dis(gen);

    Temperature t_1(x_1), t_2(x_2);

    ASSERT_EQ((t_1 != t_2), !(t_1 == t_2));
  }
}

TEST(Temperature_test, Subtest_10) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(-273, 1000);
  for (int i = 0; i < 1000; i++) {
    double x_1 = dis(gen);
    double x_2 = dis(gen);

    Temperature t_1(x_1), t_2(x_2);

    EXPECT_TRUE(std::abs(float(t_1 + t_2) - (x_1 + x_2)) <
                1.0E-3);  // приближенно равны

    t_1 += t_2;
    EXPECT_TRUE(std::abs(float(t_1) - (x_1 + x_2)) <
                1.0E-3);  // приближенно равны
  }
}

TEST(Temperature_test, Subtest_11) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(-273, 1000);
  for (int i = 0; i < 1000; i++) {
    double x_1 = dis(gen);
    double x_2 = dis(gen);

    Temperature t_1(x_1), t_2(x_2);

    EXPECT_TRUE(std::abs(float(t_1 - t_2) - (x_1 - x_2)) <
                1.0E-3);  // приближенно равны

    t_1 -= t_2;
    EXPECT_TRUE(std::abs(float(t_1) - (x_1 - x_2)) <
                1.0E-3);  // приближенно равны
  }
}
