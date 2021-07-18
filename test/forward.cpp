#include <dtl/forward.hpp>
#include <dtl/typeops.hpp>
#include <gtest/gtest.h>

template <typename T>
decltype(auto) fwd(T&& t)
{
    return dtl::forward<T>(t);
}

TEST(forward, types) {
    auto x = 0; // variables are lvalues
    ASSERT_TRUE((dtl::is_same<decltype(fwd(x)), decltype(x)&>));
    ASSERT_TRUE((dtl::is_same<decltype(fwd(0)), decltype(x)&&>));
}