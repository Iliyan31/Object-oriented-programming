#pragma once
#include "Object.hpp"
#include <utility>
#include <vector>
#include <stdexcept>

class KeyValueDatabase : public Object{
public:
    KeyValueDatabase(const std::string& name = " ", const std::string& location = " ", const std::string& extension = " ");

    void add_entry(const std::pair<std::string, int>& entry);     
    int get_value(const std::string& key) const;

    bool operator==(const Comparable* c) const;
    bool operator!=(const Comparable* c) const;
    std::string debug_print() const;
    std::string to_string() const;
    void from_string(const std::string& str);
    Object* clone() const;

private:
    std::vector<std::pair<std::string, int>> database;      
    std::string key = " ";
    int value = 0;
};