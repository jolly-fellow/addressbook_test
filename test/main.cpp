#include <iostream>
#include <string>
#include "../addressbook.hpp"

using namespace std;
using namespace addressbook;

int main() {

    addressbook_t ab;

    cout << "\n add the records from stdin \n";

    while (!cin.eof()) {

        record_t r;
        cin >> r.first_name;
        cin >> r.last_name;
        cin >> r.phone;
        ab.add(r);

        /*
        getline(cin, r.first_name, '\t');
        getline(cin, r.last_name, '\t');
        getline(cin, r.phone, '\t');
        */

    }

    cout << "\n print the book sorted by first names \n";

    ab.print_sorted_by_fname();

    cout << "\n print the book sorted by last names \n";

    ab.print_sorted_by_lname();

    cout << "\n search in first names by prefix \"Ha\" and print out \n";

    ab.search_fname_by_prefix("Ha");

    cout << "\n search in last names by prefix \"S\" and print out \n";

    ab.search_lname_by_prefix("S");

    cout << "\n remove \"Zia Kleinert\" from the book and print it out  \n";

    ab.delete_record("Zia", "Kleinert");

    ab.print_sorted_by_fname();

    return 0;
}
