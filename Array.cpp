#pragma once
#include "Array.h"
#include "Array_def.h"

template <typename T>
inline Array <T>::Array (int length) : length_ (length)
{
    data_ = new T[length]{};
}


template <typename T>
inline Array <T>::Array(T data[], int length) : length_(length)
{
    data_ = new T[length];
    for (int i = 0; i < length; ++i)
    {
        data_[i] = data[i];
    }
}

template<typename T>
inline Array <T>::Array(Array <T>& other_arr)
{
    data_ = new T[other_arr.get_length()];
    length_ = other_arr.get_length();
    //copy_arr (const T &other_arr->data_);
}

template<typename T>
inline T Array <T>::at(int index)
{
    return data_[index];
}

template class Array <int>;
template class Array <double>;
template class Array <std::string>;

/*
void temporary_function ()
{
    Array <int> testObj_int;
    Array <double> testObj_double;
    Array <std::string> testObj_str;
    Array <char> testObj_char;
    Array <long> testObl_long;
    Array <float> testObj_float;
}
*/