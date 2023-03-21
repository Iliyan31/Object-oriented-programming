
#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

#include "Error.hpp"
#include "Optional.hpp"

template<typename T>

class Result {
public:
    Result();
    Result(const T& result);
    Result(const std::string& error_message);

    Optional<T> get_result() const;
    Optional<Error> get_error() const;

    bool operator==(const T& result) const;
    bool operator==(const Error& result) const;
private:
    Optional<T> result;
    Optional<Error> error;
};

template<typename T>
Result<T>::Result()
{
    this->result = T();
    this->error = Error();        
}

template<typename T>
Result<T>::Result(const T& result)
{
    this->result = result;
}

template<typename T>
Result<T>::Result(const std::string& error_message)
{
    Optional<Error> temp(error_message);
    this->error = temp;
}

template<typename T>
Optional<T> Result<T>::get_result() const
{
    return this->result.get_value();
}

template<typename T>
Optional<Error> Result<T>::get_error() const
{
    return this->error.get_value();
}

template<typename T>
bool Result<T>::operator==(const T& result) const
{
    if (this->result.is_none()) {        
        return false;
    }
    return true;
}

template<typename T>
bool Result<T>::operator==(const Error& result) const
{
    if (this->error.is_none()) {          
        return false;
    }
    return true;
}