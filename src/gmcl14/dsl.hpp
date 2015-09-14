#pragma once

namespace MatrixDSL
{
    template < class element_type, class shape, class optimization,
               class bounds_checking, class format, class index_type >
    struct matrix;

    // element_type : built-in types

    // shape
    template < class > struct rectangle;
    template < class > struct lower_triangle;
    template < class > struct upper_triangle;
    template < class > struct symmetry;

    // optimization
    template < class > struct speed;
    template < class > struct space;

    // bounds_checking
    template < class array_order > struct array;
    template < class > struct vector;

    // array_order
    template < class > struct c_like;
    template < class > struct fortran_like;

    // index_type : built-in types
    struct whatever;
}