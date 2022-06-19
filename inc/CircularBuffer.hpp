#pragma once
#include <cstddef>
#include <array>
#include <iostream>
#include "WrappingIndex.hpp"
#include "CircularBufferIterator.hpp"

namespace lfr {

    template<class T, std::size_t N>
    class CircularBuffer
    {
    public:
        using value_type             = T;
        using size_type              = std::size_t;
        using difference_type        = std::ptrdiff_t;
        using reference              = value_type&;
        using const_reference        = const value_type&;
        using pointer                = value_type*;
        using const_pointer          = const value_type*;
        using iterator               = internal::CircularBuffer_raw_iterator<T, N, T&, T*, CircularBuffer<T,N>>;
        using const_iterator         = internal::CircularBuffer_raw_iterator<T, N, const T&, const T*, const CircularBuffer<T,N>>;
        using reverse_iterator       = std::reverse_iterator< iterator >;
        using const_reverse_iterator = std::reverse_iterator< const_iterator >;

        constexpr CircularBuffer() noexcept = default;
        constexpr CircularBuffer( const CircularBuffer& other ) = default;
        constexpr CircularBuffer( CircularBuffer&& other ) noexcept = default;

        constexpr ~CircularBuffer() = default;

        constexpr CircularBuffer& operator=( const CircularBuffer& other ) = default;
        constexpr CircularBuffer& operator=( CircularBuffer&& other ) noexcept = default;

        constexpr reference at( size_type pos );
        constexpr const_reference at( size_type pos ) const;

        constexpr reference operator[]( size_type pos );
        constexpr const_reference operator[]( size_type pos ) const;

        constexpr reference front();
        constexpr const_reference front() const;

        constexpr reference back();
        constexpr const_reference back() const;

        constexpr iterator begin() noexcept;
        constexpr const_iterator begin() const noexcept;
        constexpr const_iterator cbegin() const noexcept;

        constexpr iterator end() noexcept;
        constexpr const_iterator end() const noexcept;
        constexpr const_iterator cend() const noexcept;

        constexpr reverse_iterator rbegin() noexcept;
        constexpr const_reverse_iterator rbegin() const noexcept;
        constexpr const_reverse_iterator crbegin() const noexcept;

        constexpr reverse_iterator rend() noexcept;
        constexpr const_reverse_iterator rend() const noexcept;
        constexpr const_reverse_iterator crend() const noexcept;

        [[nodiscard]]
        constexpr bool empty() const noexcept;

        [[nodiscard]]
        constexpr bool full() const noexcept;
    
        constexpr size_type size() const noexcept;
        constexpr size_type max_size() const noexcept;

        constexpr void clear() noexcept;
        
        constexpr void push_back( const T& value );
        constexpr void push_back( T&& value );
        
        template< class... Args >
        constexpr reference emplace_back( Args&&... args );

        constexpr void pop_front();

        constexpr void swap( CircularBuffer& other ) noexcept;

    private:
        using underlying_container = std::array<T, N>;

        underlying_container data;
        internal::WrappingIndex<N> head = 0;
        internal::WrappingIndex<N> tail = 0;
        size_type items = 0;

        template< class _T, std::size_t _N >
        friend std::ostream& operator<<(std::ostream& os, const CircularBuffer< _T, _N >& obj);
    };
}

#include "CircularBuffer.hh"
