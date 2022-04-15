#include "book.hpp"
#include "inventory.hpp"
#include "library.hpp"
#include "main.hpp"
#include "shop.hpp"
int main(int argc, char *argv[]) {
  // TODO
  using namespace std;
  Shop s(new ExternalDB(), new Inventory());

  while (true) {
    string author;
    position_t position;
    price_t price;
    string publisher;
    string title;

    cout << "Enter author name: ";
    cin >> author;
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter publisher name: ";
    cin >> publisher;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter Stock Position: ";
    cin >> position;

    author_id_t a_id = s.add_author(author);
    publisher_id_t p_id = s.add_publisher(publisher);

    Book b(title, price, a_id, p_id);

    s.add_book(b, position);
    cout << "Book added.\n";
  }

  return 0;
}
