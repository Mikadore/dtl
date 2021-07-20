#pragma once
#include <dtl/integral.hpp>

namespace dtl {
    struct MD5Stream {
        private:
            u32 A = 0x01234567;
            u32 B = 0x89abcdef;
            u32 C = 0xfedcba98;
            u32 D = 0x76543210;

            u32 cache[15]; // holds any leftover from invoking update
        public:
            auto update() -> void;
    };
}