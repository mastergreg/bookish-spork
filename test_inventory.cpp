#include "inventory.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;

TEST(Inventory, add_stock_single) {
  // Test Comment
  Inventory inventory;
  uint32_t count = 0;
  InventoryRow row = InventoryRow(0, 0);

  count = inventory.add_stock(0, 0);
  ASSERT_EQ(count, 1);
  row = inventory.get_stock_by_pid(0);
  ASSERT_EQ(row.get_count(), 1);

  count = inventory.add_stock(0, 0);
  ASSERT_EQ(count, 2);
  row = inventory.get_stock_by_pid(0);
  ASSERT_EQ(row.get_count(), 2);
  count = inventory.add_stock(0, 0);
  ASSERT_EQ(count, 3);
  row = inventory.get_stock_by_pid(0);
  ASSERT_EQ(row.get_count(), 3);
}

TEST(Inventory, add_stock_multiple) {
  // Test Comment
  Inventory inventory;
  uint32_t count = 0;

  count = inventory.add_stock(0, 0);
  ASSERT_EQ(count, 1);
  count = inventory.add_stock(1, 1);
  ASSERT_EQ(count, 1);
  count = inventory.add_stock(0, 0);
  ASSERT_EQ(count, 2);
  count = inventory.add_stock(1, 1);
  ASSERT_EQ(count, 2);
  count = inventory.add_stock(0, 0, 2);
  ASSERT_EQ(count, 4);
  count = inventory.add_stock(1, 1, 3);
  ASSERT_EQ(count, 5);
}

TEST(Inventory, add_stock_failure) {
  // Test Comment
  Inventory inventory;
  uint32_t count = 0;

  count = inventory.add_stock(0, 0);
  ASSERT_EQ(count, 1);
  try {
    count = inventory.add_stock(1, 0);
    FAIL() << "Expected runtime_error";
  } catch (std::runtime_error const &err) {
    EXPECT_EQ(err.what(),
              std::string("Position 0 is already taken by another: book_id 0"));
  } catch (...) {
    FAIL() << "Expected runtime_error";
  }
}