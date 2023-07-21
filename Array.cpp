#pragma once
#include "Array.h"
#include "Array_def.h"
#include "MyException.h"

template <typename T>
inline Array <T>::Array (int length) : length_ (length)
{
    try
    {
       test_length (length);
       data_ = allocate_memory (length);
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }    
}

template <typename T>
inline Array <T>::Array(T data[], int length) : length_(length)
{
    try
    {
        test_length (length);
        data_ = allocate_memory (length);
        copy_array (data, length);
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }
    
}

template <typename T>
inline Array <T>::~Array ()
{
    if (data_ == nullptr)
        return;
    else
    {
        delete [] data_;
    }
}

template<typename T>
inline Array <T>::Array(Array <T>& other_arr)
{
    try
    {
        test_ptr (other_arr.data_);
        data_ = allocate_memory (other_arr.get_length());    
        length_ = other_arr.get_length();
        copy_array (other_arr.data_, other_arr.length_);
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }    
}

template<typename T>
inline T Array <T>::at(int index)
{
    try
    {
        test_range(index);
        return data_[index - 1];
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }  
}

template<typename T>
inline void Array<T>::copy_array(const T * other_data, const int & other_length)
{
    try
    {
        test_ptr (data_);
        test_ptr (other_data);
        test_length (other_length);
        for (int i = 0; i < other_length; ++i)
        {
            data_[i] = other_data[i];
        }
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }  
}

template<typename T>
inline void Array<T>::copy_array(T * data, const T * other_data, const int & other_length)
{
    try
    {
        test_ptr(data);
        test_ptr(other_data);
        test_length(other_length);
        for (int i = 0; i < other_length; ++i)
        {
            data[i] = other_data[i];
        }
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }  
}

template<typename T>
void Array<T>::print_arr()
{
    try
    {
        test_ptr(data_);
        for (int i = 0; i < length_; ++i)
            std::cout << data_[i] << "\t";
        std::cout << "\n";
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }    
}

template<typename T>
void Array<T>::push_back(const T &data)
{
    try
    {        
        test_ptr(data_);
        T* new_data = allocate_memory (length_+1);
        copy_array (new_data, data_, length_);
        new_data[length_] = data;
        length_++;
        delete [] data_;
        data_ = new_data;    
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }    
}

template<typename T>
void Array<T>::push_front(const T &data)
{
    try
    {
        test_ptr (data_);
        T *new_data = allocate_memory(length_ + 1);
        new_data[0] = data;
        for (int i = 1; i < length_ + 1; ++i)
        {
            new_data[i] = data_[i - 1];
        }
        length_++;
        delete[] data_;
        data_ = new_data;
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }     
}

template<typename T>
void Array<T>::pop_back()
{
    try
    {
        test_ptr (data_);
        if (length_ == 0)
        {
            return;
        }
        else if (length_ == 1)
        {
            clear();
        }
        else 
        {
            T *new_data = allocate_memory(length_ - 1);
            copy_array(new_data, data_, length_ - 1);
            length_--;
            delete[] data_;
            data_ = new_data;
        }
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }    
}

template<typename T>
void Array<T>::pop_front()
{
    try
    {
        test_ptr (data_);
        if (length_ == 0)
        {
            return;
        }
        else if (length_ == 1)
        {
            clear();
        }
        else 
        {
            T *new_data = allocate_memory(length_ - 1);
            for (int i = 0; i < length_ - 1; ++i)
            {
                new_data[i] = data_[i + 1];
            }
            length_--;
            delete[] data_;
            data_ = new_data;
        }
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << '\n';
    } 
}

template<typename T>
void Array<T>::insert(const T &data, const int index)
{
    try
    {
        test_ptr (data_);
        if (index == length_)
        {
            push_back(data);
        }
        else if (index == 1)
        {
            push_front(data);
        }
        else
        {
            T *new_data = nullptr;
            if (index < length_)
            {
                new_data = allocate_memory(length_ + 1);
                copy_array(new_data, data_, index);
                new_data[index - 1] = data;
                for (int i = index; i < length_ + 1; ++i)
                {
                    new_data[i] = data_[i - 1];
                }
                length_++;
            }
            else if (index > length_)
            {
                new_data = allocate_memory(index);
                copy_array(new_data, data_, length_);
                new_data[index - 1] = data;
                length_ = index;
            }
            delete[] data_;
            data_ = new_data;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
}

template<typename T>
void Array<T>::clear()
{
    if (data_ == nullptr)
        return;
    else
    {
        length_ = 0;
        delete [] data_;
        data_ = nullptr;
    }
}

template<typename T>
T* Array<T>::allocate_memory(const int new_length)
{
    try
    {
        return new T [new_length]{};
    }
    catch (const std::bad_alloc &ex)
    {
        data_ = nullptr;
        std::cout << "Allocation failed: " << ex.what() << '\n';
    }    
}

template<typename T>
void Array<T>::test_length(const int length)
{
    if (length < 0)
    {
        throw MyException("IntArray length must be positive", ERROR_LENGTH_TOO_SMALL);
    }
}

template<typename T>
void Array<T>::test_ptr (const T* data)
{
    if (data == nullptr)
    {
        throw MyException("IntArray called on nullptr", ERROR_NULLPTR);
    }
}

template<typename T>
void Array<T>::test_range(const int index)
{
    if (index < 0 || index > length_)
    throw std::out_of_range("IntArray index out of range");
}

template class Array <int>;
template class Array <double>;
template class Array <std::string>;
