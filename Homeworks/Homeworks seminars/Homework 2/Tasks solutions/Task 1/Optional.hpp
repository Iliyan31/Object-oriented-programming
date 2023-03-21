#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too
#include "Error.hpp"


template <typename T>

class Optional {
public:
    Optional();
    Optional(const T& value);

    bool is_none() const;
    T get_value() const;

    bool operator==(const T & opt) const;
private:
    T option;
};

template<typename T>
Optional<T>::Optional()
{
    this->option = T();
}

template<typename T>
Optional<T>::Optional(const T& value)
{
    this->option = value;
}

template<typename T>
bool Optional<T>::is_none() const
{
    if (this->option == T()) {
        return true;
    }
    return false;
}

template<>
bool Optional<Error>::is_none() const
{
    if (this->option.get_message() == Error().get_message()) {
        return true;
    }
    return false;
}

template<typename T>
T Optional<T>::get_value() const
{
    return this->option;            
}

template<typename T>
bool Optional<T>::operator==(const T& opt) const
{
    return (this->option == opt);
}
