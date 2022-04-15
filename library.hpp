#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "main.hpp"
class ExternalDB {
private:
  std::map<std::string, author_id_t> authors_map;
  std::map<std::string, publisher_id_t> publishers_map;
  std::vector<Author> authors;
  std::vector<Publisher> publishers;

public:
  author_id_t add_author(const std::string &);
  const std::vector<Author> &get_authors();
  const std::vector<Publisher> &get_publishers();
  publisher_id_t add_publisher(const std::string &);
};

class Author {
  // TODO
private:
  std::string name;

public:
  Author(const std::string &);
  friend bool operator==(const Author &, const Author &);
};

class Publisher {
  // TODO
private:
  std::string name;

public:
  Publisher(const std::string &);
  friend bool operator==(const Publisher &, const Publisher &);
};

#endif