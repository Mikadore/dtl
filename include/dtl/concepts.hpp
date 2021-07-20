#pragma once
#include <dtl/typeops.hpp>
#include <concepts>
namespace dtl {
    template<typename T, typename U>
    concept same = dtl::is_same<T,U>;

    /**
     * @brief 
     * 
     * @tparam Iterator 
     * @tparam T the type the iterator yields
     */
    template<typename Iterator, typename T>
    concept iterator = requires (Iterator i) {
        i++;
    };
}