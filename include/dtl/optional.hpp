#pragma once
namespace dtl {
    /**
     * @brief Optionally stores a value
     * 
     * The value can be either present or absent.
     * The interface offers various ways to check whether the value is present, and retrieve it.
     * 
     * Note:
     * Make no assumption about the layout of any instantiation. Some types
     * can be optimized in a way that will change the layout to be different from 
     * `struct { union { T }, bool }`
     * E.g.: absent pointers are stored as nullptr, ommitting the bool
     * @tparam T the type of the value
     */
    template<typename T>
    class optional {
        union {
            T held;
        };
        bool have_t;
        
        public:
    };
}