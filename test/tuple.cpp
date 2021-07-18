#include <dtl/tuple.hpp>
#include <gtest/gtest.h>

TEST(tuple, empty) {
    dtl::tuple<> empty;
}

TEST(tuple, get) {
    dtl::tuple t(1, 2, 3, 4, 5, 6, 7, 8, 9);

    ASSERT_EQ(t.get<0>(), 1);
    ASSERT_EQ(t.get<1>(), 2);
    ASSERT_EQ(t.get<2>(), 3);
    ASSERT_EQ(t.get<3>(), 4);
    ASSERT_EQ(t.get<4>(), 5);
    ASSERT_EQ(t.get<5>(), 6);
    ASSERT_EQ(t.get<6>(), 7);
    ASSERT_EQ(t.get<7>(), 8);
    ASSERT_EQ(t.get<8>(), 9);
}

TEST(tuple, layout) {

    struct structT
    {
        int a;
        char b;
        char *c;
        float d;
        char str[512];
    };

    using tupleT = dtl::tuple<int, char, char *, float, char[512]>;

    ASSERT_EQ(sizeof(tupleT), sizeof(structT));
    ASSERT_EQ(alignof(tupleT), alignof(structT));
}