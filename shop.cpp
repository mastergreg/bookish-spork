#include "shop.hpp"
#include "book.hpp"
#include "inventory.hpp"
#include "library.hpp"

using namespace std;
Shop::Shop(ExternalDB *x_db, Inventory *i) {
  //
  external_db.reset(x_db);
  inventory.reset(i);
}

book_id_t Shop::add_book(Book &b, position_t p) {
  //
  if (books_map.find(b.get_title()) == books_map.end()) {
    books_map[b.get_title()] = books.size();
    books.push_back(b);
  }
  inventory->add_stock(books_map[b.get_title()], p);
  return books_map[b.get_title()];
}

author_id_t Shop::add_author(const string &a) {
  //
  return external_db->add_author(a);
}

publisher_id_t Shop::add_publisher(const string &p) {
  //
  return external_db->add_publisher(p);
}