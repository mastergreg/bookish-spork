
#include "book.hpp"
using namespace std;

Book::Book(const string &t, price_t p, author_id_t a_id, publisher_id_t p_id) {
  title = t;
  price = p;
  author_id = a_id;
  publisher_id = p_id;
  //
}
bool operator==(const Book &b1, const Book &b2) {
  return b1.title == b2.title && b1.price == b2.price &&
         b1.author_id == b2.author_id && b1.publisher_id == b2.publisher_id;
}
const string &Book::get_title() const { return title; }

price_t Book::get_price() const { return price; }