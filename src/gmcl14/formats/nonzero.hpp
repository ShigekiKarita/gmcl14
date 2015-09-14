#pragma once

#include <type_traits>

namespace MatrixICCL
{
    template < class M >
    using itype = const typename M::config::index_type&;

    struct RectNonZeroRegion
    {
        template < class M >
        static bool non_zero_region(const M*, itype<M> i, itype<M> j) { return true; }
    };

    struct LowerTriangleNonZeroRegion
    {
        template < class M >
        static bool non_zero_region(const M*, itype<M> i, itype<M> j) { return i >= j; }
    };

    struct UpperTriangleNonZeroRegion
    {
        template < class M >
        static bool non_zero_region(const M*, itype<M> i, itype<M> j) { return i <= j; }
    };

    template < class MatrixType >
    struct FormatNonZeroRegion
    {
        using shape = typename MatrixType::config::DSLFeatures::shape;
        using type =
        std::conditional_t<
            shape::id == shape::lower_triangle_id ||
            shape::id == shape::symmetry_id,
            LowerTriangleNonZeroRegion,
            std::conditional_t<
                shape::id == shape::upper_triangle_id,
                UpperTriangleNonZeroRegion,
                RectNonZeroRegion
            >
        >;
    };

    template < class MatrixType >
    using FormatNonZeroRegion_t = typename FormatNonZeroRegion<MatrixType>::type;
}