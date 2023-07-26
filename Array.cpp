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
        data_ = copy_array(data, length);
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
inline Array <T>::Array(const Array <T>& other_arr)
{
    if (other_arr.data_ == nullptr)
    {
        return;
    }
    else
    {         
        length_ = other_arr.length_;
        data_ = copy_array (other_arr.data_, other_arr.length_);
    }       
}

template <typename T>
Array<T>& Array<T>::operator= (const Array<T>& other_arr)
{
    if (other_arr.data_ == nullptr)
    {
        return *this;
    }
    else if (other_arr.data_ == data_)
    {
        return *this;
    }
    else
    {       
        length_ = other_arr.length_;
        data_ = copy_array (other_arr.data_, other_arr.length_);
        return *this;
    }
}

template <typename T>
inline Array<T>::Array (Array <T>&& other_arr) noexcept
{
    length_ = other_arr.length_;
    data_ = other_arr.data_;
    other_arr.length_ = 0;
    other_arr.data_ = nullptr;
}

template <typename T>
Array<T>& Array<T>::operator= (Array<T>&& other_arr) noexcept
{            
        clear();
        length_ = other_arr.length_;
        data_ = other_arr.data_;
        other_arr.length_ = 0;
        other_arr.data_ = nullptr;
        return *this;      
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
        std::cerr << ex.what() << "\n";
    }  
}

template<typename T>
inline T* Array<T>::copy_array(const T * other_data, const int & other_length)
{
    T *new_data = allocate_memory(other_length);
    for (int i = 0; i < other_length; ++i)
    {
        new_data[i] = other_data[i];
    }
    return new_data;
}

template<typename T>
void Array<T>::print_arr() noexcept
{
    if (data_ != nullptr)
    {       
        for (int i = 0; i < length_; ++i)
            std::cout << data_[i] << "\t";
        std::cout << "\n";
    }        
}

template<typename T>
void Array<T>::push_back(const T &data)
{    
    T *new_data = allocate_memory(length_ + 1);
    for (int i = 0; i < length_; ++i)
    {
        new_data[i] = data_[i];
    }    
    new_data[length_] = data;
    length_++;
    if (data_ != nullptr)
    {
        delete[] data_;
    }    
    data_ = new_data;
}

template<typename T>
void Array<T>::push_front(const T &data)
{            
        T *new_data = allocate_memory(length_ + 1);
        new_data[0] = data;
        for (int i = 1; i < length_ + 1; ++i)
        {
            new_data[i] = data_[i - 1];
        }
        length_++;
        if (data_ != nullptr)
        {
            delete[] data_;
        }        
        data_ = new_data;        
}

template <typename T>
void Array<T>::pop_back()
{
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
        T *new_data = copy_array(data_, length_ - 1);        
        length_--;
        delete[] data_;
        data_ = new_data;
    }
}

template<typename T>
void Array<T>::pop_front()
{
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

template<typename T>
void Array<T>::insert(const T &data, const int index)
{   
    if (index < 0)
        return;
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
        new_data = index < length_ ? allocate_memory(length_ + 1) 
                                    : allocate_memory(index);
        new_data[index - 1] = data;           
            
        if (index < length_)
        {
            for (int i = 0; i < index - 1; ++i)
            {
                new_data[i] = data_[i];
            }                
            for (int i = index; i < length_ + 1; ++i)
            {
                new_data[i] = data_[i - 1];
            }
            length_++;
        }
        else if (index > length_)
        {
            for (int i = 0; i < length_; ++i)
            {
                new_data[i] = data_[i];
            }
            length_ = index;
        }         
        delete[] data_;
        data_ = new_data;
    }     
}

template<typename T>
void Array<T>::replace(const T &data, const int index)
{       
    if (index < 0)
    {
        return;
    }
    if (data_ != nullptr)
    {
        if (index > length_)
        {
            insert (data, index);
        }
        else
        {
            data_[index - 1] = data; 
        }
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
        test_length(new_length);
        return new T [new_length]{};
    }
    catch (const std::bad_alloc &ex)
    {
        data_ = nullptr;
        std::cout << "Allocation failed: " << ex.what() << '\n';
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << '\n';
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
void Array<T>::test_range(const int index)
{
    if (index < 0 || index > length_)
    throw std::out_of_range("IntArray index out of range");
}

template class Array <int>;
template class Array <double>;
template class Array <std::string>;
