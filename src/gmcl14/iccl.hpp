#pragma once

namespace MatrixICCL
{
    template < class OptBoundsCheckedMatrix > class Matrix;
    template < class OptSymmetricMatrix > class BoundsChecker;
    template < class MatrixContainer > class Symmetry;
    template < class Array > class ArrayFormat;
    template < class Vector > class LoTriangleVectorFormat;
    template < class Vector > class UpTriangleVectorFormat;
    template < class Generator > class Dyn2DCContainer;
    template < class Generator > class Dyn2DFContainer;
    template < class Generator > class Dyn1DContainer;
    template < class MatrixType > class DenseCCommaInitializer;
    template < class MatrixType > class DenseFCommaInitializer;
} // namespace MatrixICCL
