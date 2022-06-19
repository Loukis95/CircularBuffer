#pragma once
#include "WrappingIndex.hpp"
#include <algorithm>
#include <utility>

namespace lfr {
namespace internal {

    template<std::size_t N>
    inline constexpr
    WrappingIndex<N>::WrappingIndex(std::ptrdiff_t index) noexcept :
        index(index)
    {}

    template<std::size_t N>
    inline constexpr WrappingIndex<N>&
    WrappingIndex<N>::operator=(std::ptrdiff_t index) noexcept
    {
        this->index = index;
        return *this;
    };

    template<std::size_t N>
    inline constexpr WrappingIndex<N>&
    WrappingIndex<N>::operator++() noexcept
    {
        if (++index >= N) {
            index = 0;
        }
        return *this;
    }

    template<std::size_t N>
    inline constexpr WrappingIndex<N>
    WrappingIndex<N>::operator++(int) noexcept
    {
        WrappingIndex old = *this;
        operator++();
        return old;
    }

    template<std::size_t N>
    inline constexpr WrappingIndex<N>&
    WrappingIndex<N>::operator--() noexcept
    {
        if (index != 0) {
            --index;
        }
        else {
            index = N - 1;
        }
        return *this;
    }

    template<std::size_t N>
    inline constexpr WrappingIndex<N>
    WrappingIndex<N>::operator--(int) noexcept
    {
        WrappingIndex old = *this;
        operator--();
        return old;
    }
    
    template<std::size_t N>
    inline constexpr WrappingIndex<N>&
    WrappingIndex<N>::operator+=(const WrappingIndex<N>& rhs) noexcept
    {
        return operator+=(rhs.get());
    }

    template<std::size_t N>
    inline constexpr WrappingIndex<N>&
    WrappingIndex<N>::operator-=(const WrappingIndex<N>& rhs) noexcept
    {
        return operator-=(rhs.get());
    }

    template<std::size_t N>
    inline constexpr WrappingIndex<N>&
    WrappingIndex<N>::operator+=(std::ptrdiff_t rhs) noexcept
    {
        index += rhs;
        index %= static_cast<std::ptrdiff_t>(N);
        if(index < 0) index += N;
        return *this;
    }

    template<std::size_t N>
    inline constexpr WrappingIndex<N>&
    WrappingIndex<N>::operator-=(std::ptrdiff_t rhs) noexcept
    {
        index -= rhs;
        index %= static_cast<std::ptrdiff_t>(N);
        if(index < 0) index += N;
        return *this;
    }
    
    template<std::size_t N>
    inline constexpr bool
    WrappingIndex<N>::operator==( const WrappingIndex& other) const
    {
        return index == other.index;
    }

    template<std::size_t N>
    inline constexpr bool
    WrappingIndex<N>::operator!=( const WrappingIndex& other) const
    {
        return !operator==(other);
    }

    template<std::size_t N>
    inline constexpr bool
    WrappingIndex<N>::operator<( const WrappingIndex& other) const
    {
        return index < other.index;
    }

    template<std::size_t N>
    inline constexpr bool
    WrappingIndex<N>::operator<=( const WrappingIndex& other) const
    {
        return index <= other.index;
    }

    template<std::size_t N>
    inline constexpr bool
    WrappingIndex<N>::operator>( const WrappingIndex& other) const
    {
        return index > other.index;
    }

    template<std::size_t N>
    inline constexpr bool
    WrappingIndex<N>::operator>=( const WrappingIndex& other) const
    {
        return index >= other.index;
    }

    template<std::size_t N>
    inline constexpr std::ptrdiff_t
    WrappingIndex<N>::get() const noexcept
    {
        return index;
    }

    template<std::size_t N>
    inline constexpr WrappingIndex<N>
    operator+(WrappingIndex<N> lhs, const WrappingIndex<N>& rhs) noexcept
    {
        lhs += rhs;
        return lhs;
    }
    
    template<std::size_t N>
    inline constexpr WrappingIndex<N>
    operator-(WrappingIndex<N> lhs, const WrappingIndex<N>& rhs) noexcept
    {
        lhs -= rhs;
        return lhs;
    }
    
    template<std::size_t N>
    inline constexpr WrappingIndex<N>
    operator+(WrappingIndex<N> lhs, std::ptrdiff_t rhs) noexcept
    {
        lhs += rhs;
        return lhs;
    }

    template<std::size_t N>
    inline constexpr WrappingIndex<N>
    operator-(WrappingIndex<N> lhs, std::ptrdiff_t rhs) noexcept
    {
        lhs -= rhs;
        return lhs;
    }
}
}
