#pragma once
#include "CircularBuffer.hpp"
#include <sstream>

namespace lfr {
    
    template<class T, std::size_t N>
    inline constexpr typename CircularBuffer<T, N>::reference
    CircularBuffer<T, N>::at( size_type pos )
    {
        if(pos >= size()) {
            throw std::out_of_range("Out of range");
        }
        return data.at((head + pos).get());
    }
    
    template<class T, std::size_t N>
    inline constexpr typename CircularBuffer<T, N>::const_reference
    CircularBuffer<T, N>::at( size_type pos ) const
    {
        if(pos >= size()) {
            throw std::out_of_range("Out of range");
        }
        return data.at((head + pos).get());
    }

    template<class T, std::size_t N>
    inline constexpr typename CircularBuffer<T, N>::reference
    CircularBuffer<T, N>::operator[]( size_type pos )
    {
        return at(pos);
    }

    template<class T, std::size_t N>
    inline constexpr typename CircularBuffer<T, N>::const_reference
    CircularBuffer<T, N>::operator[]( size_type pos ) const
    {
        return at(pos);
    }

    template<class T, std::size_t N>
    inline constexpr typename CircularBuffer<T, N>::reference
    CircularBuffer<T, N>::front()
    {
        if (empty()) {
            throw std::out_of_range("CircularBuffer is empty");
        }
        return data[head.get()];
    }

    template<class T, std::size_t N>
    inline constexpr typename CircularBuffer<T, N>::const_reference
    CircularBuffer<T, N>::front() const
    {
        if (empty()) {
            throw std::out_of_range("CircularBuffer is empty");
        }
        return data[head.get()];
    }

    template<class T, std::size_t N>
    inline constexpr typename CircularBuffer<T, N>::reference
    CircularBuffer<T, N>::back()
    {
        if (empty()) {
            throw std::out_of_range("CircularBuffer is empty");
        }
        return data[(tail-1).get()];
    }

    template<class T, std::size_t N>
    inline constexpr typename CircularBuffer<T, N>::const_reference
    CircularBuffer<T, N>::back() const
    {
        if (empty()) {
            throw std::out_of_range("CircularBuffer is empty");
        }
        return data[(tail - 1).get()];
    }

    template<class T, std::size_t N>
    inline constexpr typename CircularBuffer<T, N>::size_type
    CircularBuffer<T, N>::size() const noexcept
    {
        return items;
    }

    template<class T, std::size_t N>
    inline constexpr typename CircularBuffer<T, N>::size_type
    CircularBuffer<T, N>::max_size() const noexcept
    {
        return N;
    }

    template<class T, std::size_t N>
    inline constexpr void
    CircularBuffer<T, N>::clear() noexcept
    {
        head = 0;
        tail = 0;
        items = 0;
    }

    template<class T, std::size_t N>
    inline constexpr void
    CircularBuffer<T, N>::push_back(const T& value)
    {
        if (full()) {
            throw std::out_of_range("CircularBuffer is full");
        }
        else {
            data[tail.get()] = value;
            ++tail;
            ++items;
        }
    }

    template<class T, std::size_t N>
    inline constexpr void
    CircularBuffer<T, N>::push_back(T&& value)
    {
        if (full()) {
            throw std::out_of_range("CircularBuffer is full");
        }
        else {
            data[tail.get()] = value;
            ++tail;
            ++items;
        }
    }

    template<class T, std::size_t N>
    template<class ...Args>
    inline constexpr typename CircularBuffer<T, N>::reference
    CircularBuffer<T, N>::emplace_back(Args && ...args)
    {
        push_back(T(std::forward<Args>(args)...));
        return back();
    }

    template<class T, std::size_t N>
    inline constexpr void
    CircularBuffer<T, N>::pop_front()
    {
        if (!empty()) {
            ++head;
            --items;
        }
    }

    template<class T, std::size_t N>
    inline constexpr bool
    CircularBuffer<T, N>::empty() const noexcept
    {
        return items == 0;
    }

    template<class T, std::size_t N>
    inline constexpr bool
    CircularBuffer<T, N>::full() const noexcept
    {
        return items == N;
    }
    
    template<class T, std::size_t N>
    inline constexpr void
    CircularBuffer<T, N>::swap( CircularBuffer<T, N>& other ) noexcept
    {
        std::swap(data, other.data);
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(items, other.items);
    }
    
    template< class T, std::size_t N >
    inline constexpr typename CircularBuffer<T,N>::iterator
    CircularBuffer<T,N>::begin() noexcept
    {
        return iterator(this, head, items);
    }

    template< class T, std::size_t N >
    inline constexpr typename CircularBuffer<T,N>::const_iterator
    CircularBuffer<T,N>::begin() const noexcept
    {
        return cbegin();
    }

    template< class T, std::size_t N >
    inline constexpr typename CircularBuffer<T,N>::const_iterator
    CircularBuffer<T,N>::cbegin() const noexcept
    {
        return const_iterator(this, head, items);
    }

    template< class T, std::size_t N >
    inline constexpr typename CircularBuffer<T,N>::iterator
    CircularBuffer<T,N>::end() noexcept
    {
        return iterator(this, tail, 0);
    }

    template< class T, std::size_t N >
    inline constexpr typename CircularBuffer<T,N>::const_iterator
    CircularBuffer<T,N>::end() const noexcept
    {
        return cend();
    }

    template< class T, std::size_t N >
    inline constexpr typename CircularBuffer<T,N>::const_iterator
    CircularBuffer<T,N>::cend() const noexcept
    {
        return const_iterator(this, tail, 0);
    }
    
    template< class T, std::size_t N >
    inline constexpr typename CircularBuffer<T,N>::reverse_iterator
    CircularBuffer<T,N>::rbegin() noexcept
    {
        return std::make_reverse_iterator(end());
    }

    template< class T, std::size_t N >
    inline constexpr typename CircularBuffer<T,N>::const_reverse_iterator
    CircularBuffer<T,N>::rbegin() const noexcept
    {
        return std::make_reverse_iterator(end());
    }

    template< class T, std::size_t N >
    inline constexpr typename CircularBuffer<T,N>::const_reverse_iterator
    CircularBuffer<T,N>::crbegin() const noexcept
    {
        return std::make_reverse_iterator(cend());
    }
    
    template< class T, std::size_t N >
    inline constexpr typename CircularBuffer<T,N>::reverse_iterator
    CircularBuffer<T,N>::rend() noexcept
    {
        return std::make_reverse_iterator(begin());
    }

    template< class T, std::size_t N >
    inline constexpr typename CircularBuffer<T,N>::const_reverse_iterator
    CircularBuffer<T,N>::rend() const noexcept
    {
        return std::make_reverse_iterator(begin());
    }

    template< class T, std::size_t N >
    inline constexpr typename CircularBuffer<T,N>::const_reverse_iterator
    CircularBuffer<T,N>::crend() const noexcept
    {
        return std::make_reverse_iterator(cbegin());
    }

    template< class T, std::size_t N >
    std::ostream& operator<<(std::ostream& os, const CircularBuffer< T, N >& obj)
    {
        std::size_t end;
        std::ostringstream oss;
        const auto pos = oss.tellp();
        std::array<std::size_t, N> indexes = { 0, };

        // Print the data
        oss << "[";
        for (std::size_t i = 0; i < N; ++i)
        {
            oss << " ";
            indexes[i] = oss.tellp() - pos;
            oss << obj.data[i] << " ";
            if (i + 1 < N) {
                oss << ",";
            }
        }
        oss << "]";
        end = oss.tellp() - pos;
        os << oss.str() << std::endl;

        // Print the first indicator line
        for (std::size_t i = 0; i < end; ++i) {
            if(obj.head == obj.tail)
            {
                if(i < indexes[obj.head.get()])         os << " ";
                else if(i == indexes[obj.head.get()])   os << "^";
                else                                    os << "-";
            }
            else if (obj.head < obj.tail)
            {
                if(i == indexes[obj.head.get()])        os << "^";
                else if(i < indexes[obj.tail.get()])    os << " ";
                else if(i == indexes[obj.tail.get()])   os << "^";
                else                                    os << "-";
            }
            else
            {
                if(i == indexes[obj.tail.get()])        os << "^";
                else if(i < indexes[obj.head.get()])    os << " ";
                else if(i == indexes[obj.head.get()])   os << "^";
                else                                    os << "-";
            }
        }
        if (obj.tail <= obj.head) {
            os << "-- head";
        }
        else {
            os << "-- tail";
        }
        os << std::endl;

        // Print the second indicator line
        for (std::size_t i = 0; i < end; ++i) {
            if(obj.head == obj.tail)
            {
                if(i < indexes[obj.head.get()])         os << " ";
                else if(i == indexes[obj.head.get()])   os << "^";
                else                                    os << "-";
            }
            else if (obj.head < obj.tail)
            {
                if(i < indexes[obj.head.get()])         os << " ";
                else if(i == indexes[obj.head.get()])   os << "^";
                else                                    os << "-";
            }
            else
            {
                if(i < indexes[obj.tail.get()])         os << " ";
                else if(i == indexes[obj.tail.get()])   os << "^";
                else                                    os << "-";
            }
        }
        if (obj.tail <= obj.head) {
            os << "-- tail";
        }
        else {
            os << "-- head";
        }

        return os;
    }
}
