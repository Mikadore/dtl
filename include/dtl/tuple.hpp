#pragma once
#include <dtl/forward.hpp>
namespace dtl
{
    using usize = decltype(sizeof(0));
    namespace impl
    {
        template <typename First, typename... Rest>
        class tuple_impl : public tuple_impl<Rest...>
        {
            First current;

            template <typename F, typename... R>
            friend class tuple_impl;

            template <usize N>
            constexpr decltype(auto) reverse_get()
            {
                if constexpr (N == sizeof...(Rest))
                {
                    return current;
                }
                else
                {
                    return tuple_impl<Rest...>::template reverse_get<N>();
                }
            }

        public:
            tuple_impl(First first, Rest... rest) : current(first), tuple_impl<Rest...>(rest...) {}

            template <usize N>
            constexpr decltype(auto) get()
            {
                static_assert(N <= sizeof...(Rest), "Index too big");
                return reverse_get<sizeof...(Rest) - N>();
            }
        };

        template <typename T>
        class tuple_impl<T>
        {
            T last;

            template <typename F, typename... Types>
            friend class tuple_impl;

            template <usize N>
            constexpr decltype(auto) reverse_get()
            {
                static_assert(N == 0, "Index too big");
                return last;
            }

        public:
            tuple_impl(T last) : last(last) {}

            template <usize N>
            decltype(auto) get()
            {
                static_assert(N == 0, "Index too big");
                return last;
            }

            consteval decltype(auto) operator[](usize index) { return get<index>(); }
        };
    }

    template <typename... Types>
    class tuple : public impl::tuple_impl<Types...>
    {
    public:
        tuple(Types &&...args) : impl::tuple_impl<Types...>(dtl::forward<Types>(args)...) {}
    };

    template <>
    class tuple<>
    {
    };

    template <typename... Types>
    [[nodiscard]] auto size(const tuple<Types...> &) -> usize {
        return sizeof...(Types);
    }

}