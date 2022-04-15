#ifndef BOOK_HPP
#define BOOK_HPP

#include "main.hpp"

class Book {
  // TODO
private:
  std::string title;
  price_t price;
  author_id_t author_id;
  publisher_id_t publisher_id;

public:
  Book(const std::string &, price_t, author_id_t, publisher_id_t);
  const std::string &get_title() const;
  price_t get_price() const;
  friend bool operator==(const Book &, const Book &);
};
#endif