#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "main.hpp"

class InventoryRow {
private:
  book_id_t book_id;
  uint32_t count;

public:
  InventoryRow(book_id_t, uint32_t);
  void inc_by(uint32_t = 1);
  void dec_by(uint32_t = 1);
  book_id_t get_book_id() const;
  uint32_t get_count() const;
};

class Inventory {
  // TODO
private:
  std::map<position_t, std::unique_ptr<InventoryRow>> stock;
  std::map<book_id_t, position_t> stock_map;

public:
  uint32_t add_stock(book_id_t, position_t, uint32_t = 1);
  InventoryRow get_stock_by_bid(book_id_t);
  InventoryRow get_stock_by_pid(position_t);
  void remove_stock(book_id_t, position_t, uint32_t = 1);
};

#endif