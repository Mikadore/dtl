#pragma once
#include <dtl/integral.hpp>

namespace dtl {
    template<typename T, usize N>
    class array {
        T data[N];
    public:
        T& operator[](usize n) {
            return data[n];
        }
        T const& operator[](usize n) const;
    };

    template<typename T>
    class array<T, 0> {
        
    };
}