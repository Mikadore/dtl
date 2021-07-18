#pragma once
namespace dtl
{
    namespace impl
    {
        // helpers
        template <typename T>
        struct type_provider {
            using type = T;
        };

        template <typename T, T v>
        struct value_provider {
            constexpr static T value = v;
        };
    }
    namespace impl
    {
        template <typename A, typename B>
        struct is_same_impl : public value_provider<bool, false> {
        };

        template <typename A>
        struct is_same_impl<A, A> : public value_provider<bool, true> {
        };
    }

    template <typename A, typename B>
    constexpr bool is_same = impl::is_same_impl<A, B>::value;

    namespace impl
    {
        template <typename T>
        struct remove_reference_impl : public type_provider<T> {
        };

        template <typename T>
        struct remove_reference_impl<T&> : public type_provider<T> {
        };

        template <typename T>
        struct remove_reference_impl<T&&> : public type_provider<T> {
        };
    }

    template <typename T>
    using remove_reference = impl::remove_reference_impl<T>::type;

    namespace impl
    {
        template <typename T>
        struct is_lval_impl : public value_provider<bool, false> {
        };

        template <typename T>
        struct is_lval_impl<T&> : public value_provider<bool, true> {
        };
    }

    template <typename T>
    constexpr bool is_lvalue_ref = impl::is_lval_impl<T>::value;

    namespace impl
    {
        template <typename T>
        struct is_rval_impl : public value_provider<bool, false> {
        };

        template <typename T>
        struct is_rval_impl<T&&> : public value_provider<bool, true> {
        };
    }

    template <typename T>
    constexpr bool is_rvalue_ref = impl::is_rval_impl<T>::value;

    template <typename T>
    constexpr bool is_reference = is_lvalue_ref<T> || is_rvalue_ref<T>;

    template<typename T>
    constexpr bool is_signed = T(-1) < T(0);

    template<typename T>
    constexpr bool is_unsigned = T(0) < T(-1);
}