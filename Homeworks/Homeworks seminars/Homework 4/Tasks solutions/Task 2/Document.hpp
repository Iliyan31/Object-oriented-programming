#pragma once
#include <vector>
#include <stdexcept>
#include "Object.hpp"
class Document : public Object {
public:
    Document(const std::string& name = " ", const std::string& location = " ", const std::string& extension = " ");

    void write_line(const std::string& line);

    std::string read_line();
    std::string read_line(const unsigned& line);

    bool operator==(const Comparable* c) const;
    bool operator!=(const Comparable* c) const;
    std::string debug_print() const;
    std::string to_string() const;
    void from_string(const std::string& str);
    Object* clone() const;

private:
    std::vector<std::string> document;
    unsigned int line = 1;
};