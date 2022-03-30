#ifndef addressbook_HPP
#define addressbook_HPP

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <memory>


namespace addressbook {

    struct record_t {
        std::string first_name;
        std::string last_name;
        std::string phone;
        record_t() {};
        record_t(const std::string & fn, const std::string & ln, const std::string & num) :
         first_name(fn), last_name(ln), phone(num) {

        }
    };


    class addressbook_t {

        std::map<std::string, std::set<std::shared_ptr<record_t>>> fn_map, ln_map;

    public:

        addressbook_t();

        void add(const std::string & fn, const std::string & ln, const std::string & num);
        void add(const record_t &);

        void print_sorted_by_fname() const;
        void print_sorted_by_lname() const;
        void search_fname_by_prefix(const std::string & prefix) const;
        void search_lname_by_prefix(const std::string & prefix) const;
        bool delete_record(const std::string & fname, const std::string & lname);

    };

}
#endif //addressbook_HPP
