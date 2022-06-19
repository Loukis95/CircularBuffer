#pragma once
#include "CircularBufferIterator.hpp"

namespace lfr {
namespace internal {

    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr CircularBuffer_raw_iterator<T,N,R,P,C>::CircularBuffer_raw_iterator(container_type* buffer, index_type index, std::size_t items) :
        buffer(buffer),
        index(index),
        items(items)
    {}
    
    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr auto
    CircularBuffer_raw_iterator<T,N,R,P,C>::operator<=>(const CircularBuffer_raw_iterator& other) const
    {
        if(buffer != other.buffer) {
            return std::partial_ordering::unordered;
        }
        return index == other.index && items == other.items ? std::partial_ordering::equivalent :
               index < other.index  ? std::partial_ordering::less :
               other.index < index  ? std::partial_ordering::greater :
                                      std::partial_ordering::unordered;
    }
    
    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr bool
    CircularBuffer_raw_iterator<T,N,R,P,C>::operator==( const CircularBuffer_raw_iterator& other) const
    {
        return buffer == other.buffer && index == other.index && items == other.items;
    }

    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr bool
    CircularBuffer_raw_iterator<T,N,R,P,C>::operator!=( const CircularBuffer_raw_iterator& other) const
    {
        return !operator==(other);
    }

    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr bool
    CircularBuffer_raw_iterator<T,N,R,P,C>::operator<( const CircularBuffer_raw_iterator& other) const
    {
        return buffer == other.buffer && items > other.items && index <= other.index;
    }

    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr bool
    CircularBuffer_raw_iterator<T,N,R,P,C>::operator<=( const CircularBuffer_raw_iterator& other) const
    {
        return buffer == other.buffer && items >= other.items && index <= other.index;
    }

    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr bool
    CircularBuffer_raw_iterator<T,N,R,P,C>::operator>( const CircularBuffer_raw_iterator& other) const
    {
        return buffer == other.buffer && items < other.items && index >= other.index;
    }

    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr bool
    CircularBuffer_raw_iterator<T,N,R,P,C>::operator>=( const CircularBuffer_raw_iterator& other) const
    {
        return buffer == other.buffer && items <= other.items && index >= other.index;
    }

    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr CircularBuffer_raw_iterator<T,N,R,P,C>& 
    CircularBuffer_raw_iterator<T,N,R,P,C>::operator++() noexcept
    {
        ++index;
        --items;
        return *this;
    }
    
    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr CircularBuffer_raw_iterator<T,N,R,P,C> 
    CircularBuffer_raw_iterator<T,N,R,P,C>::operator++(int) noexcept
    {
        CircularBuffer_raw_iterator old = *this;
        operator++();
        return old;
    }
    
    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr CircularBuffer_raw_iterator<T,N,R,P,C>& 
    CircularBuffer_raw_iterator<T,N,R,P,C>::operator--() noexcept
    {
        --index;
        ++items;
        return *this;
    }
    
    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr CircularBuffer_raw_iterator<T,N,R,P,C> 
    CircularBuffer_raw_iterator<T,N,R,P,C>::operator--(int) noexcept
    {
        CircularBuffer_raw_iterator old = *this;
        operator--();
        return old;
    }
    
    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr CircularBuffer_raw_iterator<T,N,R,P,C>& 
    CircularBuffer_raw_iterator<T,N,R,P,C>::operator+=(difference_type rhs) noexcept
    {
        index += rhs;
        items -= rhs;
        return *this;
    }
    
    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr CircularBuffer_raw_iterator<T,N,R,P,C>& 
    CircularBuffer_raw_iterator<T,N,R,P,C>::operator-=(difference_type rhs) noexcept
    {
        index -= rhs;
        items += rhs;
        return *this;
    }

    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr typename CircularBuffer_raw_iterator<T,N,R,P,C>::difference_type
    CircularBuffer_raw_iterator<T,N,R,P,C>::operator-( const CircularBuffer_raw_iterator& other ) const noexcept
    {
        return other.items - items;
    }
    
    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr typename CircularBuffer_raw_iterator<T,N,R,P,C>::reference 
    CircularBuffer_raw_iterator<T,N,R,P,C>::operator*() const
    {
        return buffer->at(index.get());
    }

    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr typename CircularBuffer_raw_iterator<T,N,R,P,C>::reference 
    CircularBuffer_raw_iterator<T,N,R,P,C>::operator->() const
    {
        return operator*();
    }

    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr typename CircularBuffer_raw_iterator<T,N,R,P,C>::reference 
    CircularBuffer_raw_iterator<T,N,R,P,C>::operator[](difference_type pos) const
    {
        return buffer->at((index + pos).get());
    }

    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr CircularBuffer_raw_iterator<T,N,R,P,C>
    operator+(CircularBuffer_raw_iterator<T,N,R,P,C> lhs, typename CircularBuffer_raw_iterator<T,N,R,P,C>::difference_type rhs) noexcept
    {
        lhs += rhs;
        return lhs;
    }
    
    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr CircularBuffer_raw_iterator<T,N,R,P,C>
    operator+(typename CircularBuffer_raw_iterator<T,N,R,P,C>::difference_type lhs, CircularBuffer_raw_iterator<T,N,R,P,C> rhs) noexcept
    {
        rhs += lhs;
        return rhs;
    }

    template<class T, std::size_t N, class R, class P, class C>
    inline constexpr CircularBuffer_raw_iterator<T,N,R,P,C>
    operator-(CircularBuffer_raw_iterator<T,N,R,P,C> lhs, typename CircularBuffer_raw_iterator<T,N,R,P,C>::difference_type rhs) noexcept
    {
        lhs -= rhs;
        return lhs;
    }
}
}
