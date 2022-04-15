#include "library.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;

TEST(ExternalDB, add_author_first) {
  // Test Comment
  ExternalDB db;

  author_id_t a_id = db.add_author("Author 1");
  ASSERT_EQ(a_id, 0);
}
TEST(ExternalDB, add_author_second) {
  // Test Comment
  ExternalDB db;

  author_id_t a_id = db.add_author("Author 1");
  ASSERT_EQ(a_id, 0);
  a_id = db.add_author("Author 2");
  ASSERT_EQ(a_id, 1);
}

TEST(ExternalDB, add_author_idempotent) {
  // Test Comment
  ExternalDB db;

  author_id_t a_id = db.add_author("Author 1");
  ASSERT_EQ(a_id, 0);
  a_id = db.add_author("Author 1");
  ASSERT_EQ(a_id, 0);
  a_id = db.add_author("Author 2");
  ASSERT_EQ(a_id, 1);
  a_id = db.add_author("Author 1");
  ASSERT_EQ(a_id, 0);
}
TEST(ExternalDB, add_and_get_authors) {
  // Test Comment
  ExternalDB db;

  db.add_author("Author 1");
  db.add_author("Author 2");

  const std::vector<Author> authors = db.get_authors();

  ASSERT_EQ(authors.size(), 2);

  const std::vector<Author> expected({Author("Author 1"), Author("Author 2")});

  for (size_t i = 0; i < authors.size(); ++i) {
    ASSERT_EQ(authors[i], expected[i]);
  }
}

TEST(ExternalDB, add_publisher_first) {
  // Test Comment
  ExternalDB db;

  publisher_id_t p_id = db.add_publisher("Publisher 1");
  ASSERT_EQ(p_id, 0);
}

TEST(ExternalDB, add_publisher_second) {
  // Test Comment
  ExternalDB db;

  publisher_id_t p_id = db.add_publisher("Publisher 1");
  ASSERT_EQ(p_id, 0);
  p_id = db.add_publisher("Publisher 2");
  ASSERT_EQ(p_id, 1);
}

TEST(ExternalDB, add_publisher_idempotent) {
  // Test Comment
  ExternalDB db;

  publisher_id_t p_id = db.add_publisher("Publisher 1");
  ASSERT_EQ(p_id, 0);
  p_id = db.add_publisher("Publisher 1");
  ASSERT_EQ(p_id, 0);
  p_id = db.add_publisher("Publisher 2");
  ASSERT_EQ(p_id, 1);
  p_id = db.add_publisher("Publisher 1");
  ASSERT_EQ(p_id, 0);
}

TEST(ExternalDB, add_and_get_publishers) {
  // Test Comment
  ExternalDB db;

  db.add_publisher("Publisher 1");
  db.add_publisher("Publisher 2");

  const std::vector<Publisher> publishers = db.get_publishers();

  ASSERT_EQ(publishers.size(), 2);

  const std::vector<Publisher> expected(
      {Publisher("Publisher 1"), Publisher("Publisher 2")});

  for (size_t i = 0; i < publishers.size(); ++i) {
    ASSERT_EQ(publishers[i], expected[i]);
  }
}
