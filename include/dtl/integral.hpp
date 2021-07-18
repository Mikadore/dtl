#pragma once
namespace dtl
{
    using usize = decltype(sizeof(0));
    using isize = decltype("" - "");

    namespace impl
    {
        template <usize N, typename T, typename... Types>
        consteval auto integral_from_size()
        {
            if constexpr (sizeof(T) == N) {
                return T{};
            } else {
                return integral_from_size<N, Types...>();
            }
        }
        template <usize N>
        using unsigned_from_primitives =
            decltype(impl::integral_from_size<N, unsigned char, unsigned short,
                                              unsigned int, unsigned long,
                                              unsigned long long>());

        template <usize N>
        using signed_from_primitives =
            decltype(impl::integral_from_size<N, signed char, short, int, long,
                                              long long>());
    }

    using u64 = impl::unsigned_from_primitives<8>;
    using u32 = impl::unsigned_from_primitives<4>;
    using u16 = impl::unsigned_from_primitives<2>;
    using u8  = impl::unsigned_from_primitives<1>;

    using i64 = impl::signed_from_primitives<8>;
    using i32 = impl::signed_from_primitives<4>;
    using i16 = impl::signed_from_primitives<2>;
    using i8  = impl::signed_from_primitives<1>;
}