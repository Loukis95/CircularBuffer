#pragma once
#include <cstddef>
#include <iterator>
#include "WrappingIndex.hpp"

namespace lfr {

    template<class T, std::size_t N>
    class CircularBuffer;

    namespace internal {

        template<class T, std::size_t N, class R = T&, class P = T*, class C = CircularBuffer<T,N>>
        class CircularBuffer_raw_iterator
        {
        public:
            using iterator_category = std::random_access_iterator_tag;
            using value_type        = T;
            using difference_type   = std::ptrdiff_t;
            using pointer           = P;
            using reference         = R;
            using container_type    = C;

            constexpr CircularBuffer_raw_iterator( const CircularBuffer_raw_iterator& other ) = default;
            constexpr CircularBuffer_raw_iterator( CircularBuffer_raw_iterator&& other ) noexcept = default;
            
            constexpr ~CircularBuffer_raw_iterator() = default;

            constexpr CircularBuffer_raw_iterator& operator=( const CircularBuffer_raw_iterator& other ) = default;
            constexpr CircularBuffer_raw_iterator& operator=( CircularBuffer_raw_iterator&& other ) noexcept = default;

            constexpr auto operator<=>( const CircularBuffer_raw_iterator& other) const;
            constexpr bool operator==( const CircularBuffer_raw_iterator& other) const;
            constexpr bool operator!=( const CircularBuffer_raw_iterator& other) const;
            constexpr bool operator<( const CircularBuffer_raw_iterator& other) const;
            constexpr bool operator<=( const CircularBuffer_raw_iterator& other) const;
            constexpr bool operator>( const CircularBuffer_raw_iterator& other) const;
            constexpr bool operator>=( const CircularBuffer_raw_iterator& other) const;
            
            constexpr CircularBuffer_raw_iterator& operator++() noexcept;
            constexpr CircularBuffer_raw_iterator  operator++(int) noexcept;
            constexpr CircularBuffer_raw_iterator& operator--() noexcept;
            constexpr CircularBuffer_raw_iterator  operator--(int) noexcept;
            constexpr CircularBuffer_raw_iterator& operator+=( difference_type rhs ) noexcept;
            constexpr CircularBuffer_raw_iterator& operator-=( difference_type rhs ) noexcept;

            constexpr difference_type operator-( const CircularBuffer_raw_iterator& other ) const noexcept;

            constexpr reference operator*() const;
            constexpr reference operator[]( difference_type pos ) const;
            constexpr reference operator->() const;

        private:
            friend class CircularBuffer<T,N>;

            using index_type = internal::WrappingIndex<N>;

            container_type* buffer;
            index_type index;
            std::size_t items;
            
            constexpr explicit CircularBuffer_raw_iterator( container_type* buffer, index_type index, std::size_t items );
            
            template<class _T, std::size_t _N, class _R, class _P>
            friend constexpr CircularBuffer_raw_iterator operator+( CircularBuffer_raw_iterator lhs, difference_type rhs ) noexcept;
            
            template<class _T, std::size_t _N, class _R, class _P>
            friend constexpr CircularBuffer_raw_iterator operator+( difference_type lhs, CircularBuffer_raw_iterator rhs ) noexcept;
            
            template<class _T, std::size_t _N, class _R, class _P>
            friend constexpr CircularBuffer_raw_iterator operator-( CircularBuffer_raw_iterator lhs, difference_type rhs ) noexcept;
        };
    }

    
}

#include "CircularBufferIterator.hh"
