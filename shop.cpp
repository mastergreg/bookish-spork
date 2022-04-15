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

book_id_t Shop::find_book(const string &t) {
  //
  if (books_map.find(t) == books_map.end()) {
    return -1;
  }
  return books_map[t];
}

author_id_t Shop::add_author(const string &a) {
  //
  return external_db->add_author(a);
}

publisher_id_t Shop::add_publisher(const string &p) {
  //
  return external_db->add_publisher(p);
}

price_t Shop::buy_book(const string &t, uint32_t c) {
  //
  book_id_t b_id = find_book(t);
  Book b = books[b_id];
  if (b_id == -1) {
    throw runtime_error("Book " + t + " is not in stock");
  }
  InventoryRow row = inventory->get_stock_by_bid(b_id);
  if (row.get_count() < c) {
    throw runtime_error("Book " + t + " is not in stock");
  }
  row.dec_by(c);

  return b.get_price() * c;
}