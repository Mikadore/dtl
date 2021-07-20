#pragma once
#include <dtl/integral.hpp>
#include <dtl/concepts.hpp>

namespace dtl {
    /**
     *  A range of T represents a runtime-sized set of items of type T adjacent in memory
     *  A range must implement the following methods:
     *      - size() -> usize: get the number of elements in the range
     *      - operator[](usize N) -> T&: yield the Nth element, N is always < size()
     *      - begin() -> {random access iterator of T}: yield the front iterator
     *      - end() -> {random access iterator of T}: yield a past-the-end iterator
     *  @tparam T the type of the elements in the range
     */
    template<typename Range, typename T>
    concept range = requires (Range& r) {
        { r.size() } -> dtl::same<usize>;
    };
}