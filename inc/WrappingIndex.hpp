#pragma once
#include <cstddef>

namespace lfr {
namespace internal {

    template< std::size_t N >
    struct WrappingIndex
    {
    public:
        constexpr WrappingIndex() noexcept = default;
        constexpr WrappingIndex(std::size_t index) noexcept;
        constexpr WrappingIndex(const WrappingIndex& other) = default;
        constexpr WrappingIndex(WrappingIndex&& other) noexcept = default;

        constexpr ~WrappingIndex() noexcept = default;

        constexpr WrappingIndex& operator=(std::size_t index) noexcept;
        constexpr WrappingIndex& operator=(const WrappingIndex& other) = default;
        constexpr WrappingIndex& operator=(WrappingIndex&& other) noexcept = default;

        constexpr auto operator<=>(const WrappingIndex&) const = default;

        constexpr WrappingIndex& operator++() noexcept;
        constexpr WrappingIndex operator++(int) noexcept;
        constexpr WrappingIndex& operator--() noexcept;
        constexpr WrappingIndex operator--(int) noexcept;
        constexpr WrappingIndex& operator+=(std::size_t rhs) noexcept;
        constexpr WrappingIndex& operator-=(std::size_t rhs) noexcept;

        constexpr std::size_t get() const noexcept;

    private:
        std::size_t index = 0;

        template< std::size_t _N >
        friend constexpr WrappingIndex operator+(WrappingIndex lhs, std::size_t rhs) noexcept;

        template< std::size_t _N >
        friend constexpr WrappingIndex operator-(WrappingIndex lhs, std::size_t rhs) noexcept;
    };
}
}
