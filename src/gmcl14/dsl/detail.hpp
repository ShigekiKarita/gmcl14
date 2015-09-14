#pragma once

namespace MatrixDSL
{
    struct whatever
    {
        enum class IDs {
            whatever_id = -1,
            rectangle_id, lower_triangle_id, upper_triangle_id, symmetry_id,
            speed_id, space_id,
            check_bounds_id, no_bounds_checking_id,
            array_id, vector_id,
            c_like_id, fortran_like_id
        };
        constexpr static auto id = IDs::whatever_id;
    };

    template<
        class ElementType = whatever,
        class ShapeType = whatever,
        class OptimizationFlag = whatever,
        class BoundsChecking = whatever,
        class FormatType = whatever,
        class IndexType = whatever
    >
    struct matrix {
        using element_type = ElementType;
        using shape = ShapeType;
        using optimization_flag = OptimizationFlag;
        using bounds_checking = BoundsChecking;
        using format = FormatType;
        using index_type = IndexType;
    };

    template<class _ = whatever>
    struct rectangle : whatever {
        constexpr static auto id = IDs::rectangle_id;
    };

    template<class _ = whatever>
    struct lower_triangle : whatever {
        constexpr static auto id = IDs::lower_triangle_id;
    };

    template<class _ = whatever>
    struct upper_triangle : whatever {
        constexpr static auto id = IDs::upper_triangle_id;
    };

    template<class _ = whatever>
    struct symmetry : whatever {
        constexpr static auto id = IDs::symmetry_id;
    };
}