#include <dtl/integral.hpp>
#include <gtest/gtest.h>

TEST(integral, sizes_match) {
    ASSERT_EQ(sizeof(dtl::u64), 8);
    ASSERT_EQ(sizeof(dtl::u32), 4);
    ASSERT_EQ(sizeof(dtl::u16), 2);
    ASSERT_EQ(sizeof(dtl::u8 ), 1);
    
    ASSERT_EQ(sizeof(dtl::i64), 8);
    ASSERT_EQ(sizeof(dtl::i32), 4);
    ASSERT_EQ(sizeof(dtl::i16), 2);
    ASSERT_EQ(sizeof(dtl::i8 ), 1);
}