#include "book.hpp"
#include "inventory.hpp"
#include "library.hpp"
#include "shop.hpp"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;

TEST(Shop, add_author_first) {
  // Test Comment
  Shop shop(new ExternalDB(), new Inventory());

  author_id_t a_id = shop.add_author("Author 1");
  ASSERT_EQ(a_id, 0);
}
TEST(Shop, add_author_second) {
  // Test Comment
  Shop shop(new ExternalDB(), new Inventory());

  author_id_t a_id = shop.add_author("Author 1");
  ASSERT_EQ(a_id, 0);
  a_id = shop.add_author("Author 2");
  ASSERT_EQ(a_id, 1);
}

TEST(Shop, add_author_idempotent) {
  // Test Comment
  Shop shop(new ExternalDB(), new Inventory());

  author_id_t a_id = shop.add_author("Author 1");
  ASSERT_EQ(a_id, 0);
  a_id = shop.add_author("Author 1");
  ASSERT_EQ(a_id, 0);
  a_id = shop.add_author("Author 2");
  ASSERT_EQ(a_id, 1);
  a_id = shop.add_author("Author 1");
  ASSERT_EQ(a_id, 0);
}

TEST(Shop, add_publisher_first) {
  // Test Comment
  Shop shop(new ExternalDB(), new Inventory());

  publisher_id_t p_id = shop.add_publisher("Publisher 1");
  ASSERT_EQ(p_id, 0);
}

TEST(Shop, add_publisher_second) {
  // Test Comment
  Shop shop(new ExternalDB(), new Inventory());

  publisher_id_t p_id = shop.add_publisher("Publisher 1");
  ASSERT_EQ(p_id, 0);
  p_id = shop.add_publisher("Publisher 2");
  ASSERT_EQ(p_id, 1);
}

TEST(Shop, add_publisher_idempotent) {
  // Test Comment
  Shop shop(new ExternalDB(), new Inventory());

  publisher_id_t p_id = shop.add_publisher("Publisher 1");
  ASSERT_EQ(p_id, 0);
  p_id = shop.add_publisher("Publisher 1");
  ASSERT_EQ(p_id, 0);
  p_id = shop.add_publisher("Publisher 2");
  ASSERT_EQ(p_id, 1);
  p_id = shop.add_publisher("Publisher 1");
  ASSERT_EQ(p_id, 0);
}

TEST(Shop, add_book_first) {
  Shop shop(new ExternalDB(), new Inventory());
  Book b("Book 1", 100, shop.add_author("Author 1"),
         shop.add_publisher("Publisher 1"));

  book_id_t b_id = shop.add_book(b, 1);
  ASSERT_EQ(b_id, 0);
}

TEST(Shop, add_book_second) {
  Shop shop(new ExternalDB(), new Inventory());

  Book b = Book("Book 1", 100, shop.add_author("Author 1"),
                shop.add_publisher("Publisher 1"));

  book_id_t b_id = shop.add_book(b, 1);
  ASSERT_EQ(b_id, 0);

  b = Book("Book 2", 100, shop.add_author("Author 2"),
           shop.add_publisher("Publisher 2"));

  b_id = shop.add_book(b, 2);
  ASSERT_EQ(b_id, 1);
}

TEST(Shop, add_book_idempotent) {
  Shop shop(new ExternalDB(), new Inventory());

  Book b = Book("Book 1", 100, shop.add_author("Author 1"),
                shop.add_publisher("Publisher 1"));

  book_id_t b_id = shop.add_book(b, 1);
  ASSERT_EQ(b_id, 0);

  b = Book("Book 2", 100, shop.add_author("Author 2"),
           shop.add_publisher("Publisher 2"));

  b_id = shop.add_book(b, 2);
  ASSERT_EQ(b_id, 1);

  b_id = shop.add_book(b, 2);
  ASSERT_EQ(b_id, 1);
}

// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
