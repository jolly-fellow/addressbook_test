#include "addressbook.hpp"

#include <string>
#include <memory>
#include <algorithm>

namespace addressbook {

    using namespace std;

    void print_record(const record_t & r) {
        std::cout << r.first_name << " " << r.last_name  << " " << r.phone  << "\n";
    }

    void addressbook_t::print_sorted_by_fname() const {
        for( auto & lnames: fn_map ) {
            for(auto & r : lnames.second ) {
                print_record(*r);
            }
        }
    }

    void addressbook_t::print_sorted_by_lname() const {
        for( auto & fnames: ln_map ) {
            for(auto & r : fnames.second ) {
                print_record(*r);
            }
        }
    }


    addressbook_t::addressbook_t() {

    }

    void addressbook_t::add(const record_t & rec) {

        auto r = make_shared<record_t>(rec);

        fn_map[rec.first_name].insert(r);
        ln_map[rec.last_name].insert(r);

    }

    void addressbook_t::add(const std::string & fn, const std::string & ln, const std::string & num) {

        auto r = make_shared<record_t>(fn, ln, num);

        fn_map[fn].insert(r);
        ln_map[ln].insert(r);

    }

    void addressbook_t::search_fname_by_prefix(const std::string & prefix) const {
        auto it = fn_map.lower_bound(prefix);
        int prefix_size = prefix.size();
        for(; it != fn_map.end() && (it->first.compare(0, prefix_size, prefix) == 0); ++it ) {
            for (auto &r : it->second) {
                print_record(*r);
            }
        }
    }

    void addressbook_t::search_lname_by_prefix(const std::string & prefix) const {
        auto it = ln_map.lower_bound(prefix);
        int prefix_size = prefix.size();
        for(; it != ln_map.end() && (it->first.compare(0, prefix_size, prefix) == 0); ++it ) {
            for (auto &r : it->second) {
                print_record(*r);
            }
        }
    }

    bool addressbook_t::delete_record(const std::string & fname, const std::string & lname) {

        auto fname_it = fn_map.find(fname);
        auto lname_it = ln_map.find(lname);

        if(fname_it != fn_map.end() && lname_it != ln_map.end()) {

            std::set<std::shared_ptr<record_t>> intersect;

            set_intersection(fname_it->second.begin(), fname_it->second.end(), lname_it->second.begin(), lname_it->second.end(),
                             std::inserter(intersect, intersect.begin()));

            for (auto &r : intersect) {
                fname_it->second.erase(r);
                lname_it->second.erase(r);
            }
            return true;
        }
        else {
            return false;
        }
    }
};
