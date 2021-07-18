#pragma once
#include <dtl/typeops.hpp>
namespace dtl
{
    template <class T>
    [[nodiscard]] constexpr T&& forward(remove_reference<T>& t) noexcept
    {
        return static_cast<T&&>(t);
    }

    template <class T>
    [[nodiscard]] constexpr T&& forward(remove_reference<T>&& t) noexcept
    {
        static_assert(!is_lvalue_ref<T>, "Cannot forward rvalue as lvalue");
        return static_cast<T&&>(t);
    }

}