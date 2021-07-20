#include <dtl/typeops.hpp>
#include <gtest/gtest.h>

TEST(typeops, is_same)
{
    ASSERT_TRUE((dtl::is_same<int, int>));
    ASSERT_TRUE((dtl::is_same<int[], int[]>));
    using my_int = int;
    ASSERT_TRUE((dtl::is_same<int (*)(int*), int (*)(int[])>));
    ASSERT_TRUE((dtl::is_same<int, my_int>));

    ASSERT_FALSE((dtl::is_same<int, int &>));
    ASSERT_FALSE((dtl::is_same<int, int const>));
    ASSERT_FALSE((dtl::is_same<int, int *>));
    ASSERT_FALSE((dtl::is_same<int, int[]>));
    ASSERT_FALSE((dtl::is_same<int[], int>));
    ASSERT_FALSE((dtl::is_same<int *, int[]>));
}

TEST(typeops, remove_reference) {
    ASSERT_TRUE((dtl::is_same<dtl::remove_reference<int>, int>));
    ASSERT_TRUE((dtl::is_same<dtl::remove_reference<int&>, int>));
    ASSERT_TRUE((dtl::is_same<dtl::remove_reference<int&&>, int>));
    ASSERT_TRUE((dtl::is_same<dtl::remove_reference<int const>, int const>));
    ASSERT_TRUE((dtl::is_same<dtl::remove_reference<int const&>, int const>));
    ASSERT_TRUE((dtl::is_same<dtl::remove_reference<int const&&>, int const>));
}

TEST(typeops, is_lvalue) {
    ASSERT_TRUE((dtl::is_lvalue_ref<int&>));
    ASSERT_FALSE((dtl::is_lvalue_ref<int>));
    ASSERT_FALSE((dtl::is_lvalue_ref<int&&>));
}

TEST(typeops, is_rvalue) {
    ASSERT_TRUE((dtl::is_rvalue_ref<int&&>));
    ASSERT_FALSE((dtl::is_rvalue_ref<int&>));
    ASSERT_FALSE((dtl::is_rvalue_ref<int>));
}

TEST(typeops, is_reference) {
    ASSERT_TRUE((dtl::is_reference<int&>));
    ASSERT_TRUE((dtl::is_reference<int&&>));
    ASSERT_FALSE((dtl::is_reference<int>));
}