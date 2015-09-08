#pragma once

namespace MatrixICCL
{
    template < class OptBoundsCheckedMatrix > class Matrix;
    template < class OptSymmetricMatrix > class BoundsChecker;
    template < class Array > class ArrFormat;
    template < class Vector > class LoTriangVecFormat;
    template < class Vector > class UpTriangVecFormat;
    template < class Generator > class Dyn2DCContainer;
    template < class Generator > class Dyn2DFContainer;
    template < class Generator > class Dyn1DContainer;
    template < class MatrixType > class DenseCCommaInitializer;
    template < class MatrixType > class DenseFCommaInitializer;
} // namespace MatrixICCL
