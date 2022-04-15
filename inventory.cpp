#include "inventory.hpp"
using namespace std;

InventoryRow::InventoryRow(book_id_t b_id, uint32_t c) {
  //
  book_id = b_id;
  count = c;
}

void InventoryRow::inc_by(uint32_t c) {
  //
  count += c;
}

book_id_t InventoryRow::get_book_id() const {
  //
  return book_id;
}

uint32_t InventoryRow::get_count() const {
  //
  return count;
}

uint32_t Inventory::add_stock(book_id_t b_id, position_t p, uint32_t c) {
  //
  auto row = stock.find(p);
  if (row == stock.end()) {
    stock[p] = unique_ptr<InventoryRow>(new InventoryRow(b_id, c));
  } else {
    if (row->second->book_id == b_id) {
      row->second->inc_by(c);
    } else {
      throw runtime_error("Position " + to_string(p) +
                          " is already taken by another: book_id " +
                          to_string(stock[p]->book_id));
    }
  }
  return stock[p]->count;
}