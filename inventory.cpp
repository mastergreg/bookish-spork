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
void InventoryRow::dec_by(uint32_t c) {
  //
  count -= c;
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
    if (row->second->get_book_id() == b_id) {
      row->second->inc_by(c);
    } else {
      throw runtime_error("Position " + to_string(p) +
                          " is already taken by another: book_id " +
                          to_string(stock[p]->get_book_id()));
    }
  }
  stock_map[b_id] = p;
  return stock[p]->get_count();
}
InventoryRow Inventory::get_stock_by_bid(book_id_t b_id) {
  //
  position_t p = stock_map[b_id];
  return *stock[p];
}
InventoryRow Inventory::get_stock_by_pid(position_t p) {
  //
  return *stock[p];
}

void Inventory::remove_stock(book_id_t b_id, position_t p, uint32_t c) {
  //
  auto row = stock.find(p);
  if (row == stock.end()) {
    throw runtime_error("Position " + to_string(p) + " is not in stock");
  } else {
    if (row->second->get_book_id() == b_id) {
      row->second->dec_by(c);
      if (row->second->get_count() == 0) {
        stock.erase(p);
        stock_map.erase(b_id);
      }
    } else {
      throw runtime_error("Position " + to_string(p) +
                          " is already taken by another: book_id " +
                          to_string(stock[p]->get_book_id()));
    }
  }
}
