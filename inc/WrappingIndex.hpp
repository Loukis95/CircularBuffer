#pragma once
#include <cstddef>

namespace lfr {
namespace internal {

    template< std::size_t N >
    struct WrappingIndex
    {
    public:
        constexpr WrappingIndex() noexcept = default;
        constexpr WrappingIndex(std::ptrdiff_t index) noexcept;
        constexpr WrappingIndex(const WrappingIndex& other) = default;
        constexpr WrappingIndex(WrappingIndex&& other) noexcept = default;

        constexpr ~WrappingIndex() noexcept = default;

        constexpr WrappingIndex& operator=(std::ptrdiff_t index) noexcept;
        constexpr WrappingIndex& operator=(const WrappingIndex& other) = default;
        constexpr WrappingIndex& operator=(WrappingIndex&& other) noexcept = default;

        constexpr auto operator<=>(const WrappingIndex&) const = default;
        constexpr bool operator==( const WrappingIndex& other) const;
        constexpr bool operator!=( const WrappingIndex& other) const;
        constexpr bool operator<( const WrappingIndex& other) const;
        constexpr bool operator<=( const WrappingIndex& other) const;
        constexpr bool operator>( const WrappingIndex& other) const;
        constexpr bool operator>=( const WrappingIndex& other) const;

        constexpr WrappingIndex& operator++() noexcept;
        constexpr WrappingIndex operator++(int) noexcept;
        constexpr WrappingIndex& operator--() noexcept;
        constexpr WrappingIndex operator--(int) noexcept;
        constexpr WrappingIndex& operator+=(const WrappingIndex<N>& rhs) noexcept;
        constexpr WrappingIndex& operator-=(const WrappingIndex<N>& rhs) noexcept;
        constexpr WrappingIndex& operator+=(std::ptrdiff_t rhs) noexcept;
        constexpr WrappingIndex& operator-=(std::ptrdiff_t rhs) noexcept;

        constexpr std::ptrdiff_t get() const noexcept;

    private:
        std::ptrdiff_t index = 0;

        template< std::size_t _N >
        friend constexpr WrappingIndex operator+(WrappingIndex lhs, const WrappingIndex<N>& rhs) noexcept;
        template< std::size_t _N >
        friend constexpr WrappingIndex operator-(WrappingIndex lhs, const WrappingIndex<N>& rhs) noexcept;
        template< std::size_t _N >
        friend constexpr WrappingIndex operator+(WrappingIndex lhs, std::ptrdiff_t rhs) noexcept;
        template< std::size_t _N >
        friend constexpr WrappingIndex operator-(WrappingIndex lhs, std::ptrdiff_t rhs) noexcept;
    };
}
}

#include "WrappingIndex.hh"
