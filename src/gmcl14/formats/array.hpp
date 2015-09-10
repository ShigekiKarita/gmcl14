#pragma once

#include "nonzero.hpp"
#include <cassert>

namespace MatrixICCL
{
    template < class Array >
    class ArrayFormat
    {
    private:
        Array _elements;

    public:
        using config       = typename Array::config;
        using index_type   = typename config::index_type;
        using element_type = typename config::element_type;
        using matrix_type  = typename config::matrix_type;
        constexpr static auto zero = element_type(0);

        ArrayFormat(const index_type& r, const index_type& c) : _elements(r, c) {}
        const auto& rows() const { return _elements.rows(); }
        const auto& cols() const { return _elements.cols(); }

        auto& set_element(const index_type& i, const index_type& j, const element_type& v)
        {
            check_bounds(i, j);
            if (non_zero_region(i, j)) _elements.set_element(i, j, v);
            else assert(v == zero);
            return *this;
        }

        const auto& get_element(const index_type& i, const index_type& j) const
        {
            check_bounds(i, j);
            return non_zero_region(i, j) ? _elements.get_element(i, j) : zero;
        }

    protected:
        void check_bounds(const index_type& i, const index_type& j) const
        {
            assert(i < rows());
            assert(j < cols());
        }

        bool non_zero_region(const index_type& i, const index_type& j) const
        {
            return FormatNonZeroRegion_t<matrix_type>::non_zero_region(this, i, j);
        }
    };
} // namespace MatrixICCL
