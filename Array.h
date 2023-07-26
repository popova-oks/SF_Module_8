#pragma once
#include <iostream>
#include <string>

template <typename T>
class Array
{   
    public:
        Array (int length);
        Array (T data[] = nullptr, int length = 0);
        Array (const Array <T>& other_arr);
        Array (Array <T>&& other_arr) noexcept;
        ~Array ();

        Array<T>& operator= (const Array<T>& other_arr);
        Array<T>& operator= (Array<T> &&other_arr) noexcept;

        void print_arr () noexcept;
        
        void push_back (const T &data);
        void push_front (const T &data);
        void pop_back ();
        void pop_front ();

        void insert (const T &data, const int index);
        void replace (const T &data, const int index);
        void clear ();

        const int get_length() { return length_; }
        T at(int index);
   
    private:
        T *data_ {};
        int length_;        

        T* allocate_memory (const int new_length);
        T* copy_array (const T *other_data, const int &other_length);
        //void copy_array (const T *other_data, const int &other_length);
        //void copy_array (T *data, const T *other_data, const int &other_length);        

        void test_length (const int length);
        void test_ptr (const T* data);
        void test_range(const int index);
};

/*
template <>
Array <std::string>::~Array() = default;
*/
