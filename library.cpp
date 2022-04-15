#include "library.hpp"
using namespace std;

author_id_t ExternalDB::add_author(const string &a) {
  //
  auto row = authors_map.find(a);
  if (row == authors_map.end()) {
    authors_map[a] = authors.size();
    authors.push_back(Author(a));
  }
  return authors_map[a];
}

publisher_id_t ExternalDB::add_publisher(const string &p) {
  //
  auto row = publishers_map.find(p);
  if (row == publishers_map.end()) {
    publishers_map[p] = publishers.size();
    publishers.push_back(Publisher(p));
  }
  return publishers_map[p];
}
const std::vector<Author> &ExternalDB::get_authors() {
  //
  return authors;
}
const std::vector<Publisher> &ExternalDB::get_publishers() {
  //
  return publishers;
}

Author::Author(const string &n) {
  //
  name = n;
}

bool operator==(const Author &n1, const Author &n2) {
  return n1.name == n2.name;
}

Publisher::Publisher(const string &n) {
  //
  name = n;
}

bool operator==(const Publisher &p1, const Publisher &p2) {
  return p1.name == p2.name;
}