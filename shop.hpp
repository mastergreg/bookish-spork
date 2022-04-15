#ifndef SHOP_HPP
#define SHOP_HPP

#include "main.hpp"
class Shop {
  // TODO
private:
  std::vector<Book> books;
  std::map<std::string, book_id_t> books_map;
  std::unique_ptr<ExternalDB> external_db;
  std::unique_ptr<Inventory> inventory;

public:
  Shop(ExternalDB *, Inventory *);
  book_id_t add_book(Book &, position_t);
  author_id_t add_author(const std::string &);
  publisher_id_t add_publisher(const std::string &);
};

#endif