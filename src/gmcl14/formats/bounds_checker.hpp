#pragma once

#include <string>

namespace MatrixICCL
{
    template < class OptSymmetryMatrix >
    class BoundsChecker : public OptSymmetryMatrix
    {
    public:
        using config       = typename OptSymmetryMatrix::config;
        using index_type   = typename config::index_type;
        using element_type = typename config::element_type;

    protected:
        void check_bounds(const index_type& i __attribute__((unused)),
                          const index_type& j __attribute__((unused))) const throw(std::string)
        {
            if (i < 0 || i >= rows() || j < 0 || j >= cols())
            {
                throw "subscript(s) out of bounds";
            }
        }

    public:
        BoundsChecker(const index_type& r, const index_type& c)
            : OptSymmetryMatrix(r, c)
        {}

        auto& set_element(const index_type& i, const index_type& j, const element_type& v)
        {
            check_bounds(i, j);
            return OptSymmetryMatrix::set_element(i, j, v);
        }

        const auto& get_element(const index_type& i, const index_type& j) const
        {
            check_bounds(i, j);
            return OptSymmetryMatrix::get_element(i, j);
        }
    };
}