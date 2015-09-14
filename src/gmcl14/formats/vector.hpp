#pragma once

#include <cassert>
#include "nonzero.hpp"

namespace MatrixICCL
{
    template < class Vector >
    class LoTriangleVectorFormat
    {
    public:
        using config = typename Vector::config;
        using element_type = typename config::element_type;
        using index_type = typename config::index_type;
        constexpr static auto zero = element_type(0);

    private:
        const index_type _order;
        Vector _elements;

    protected:
        void check_bounds(const index_type& i __attribute__((unused)),
                          const index_type& j __attribute__((unused))) const
        {
            assert(i >= 0 && i < rows());
            assert(j >= 0 && j < rows());
        }

        index_type get_index(const index_type& i, const index_type& j) const
        {
            return (i + 1) * i * 0.5 + j;
        }

    public:
        explicit LoTriangleVectorFormat(const index_type& r)
            : _order(r), _elements(rows() * (rows() + 1) * 0.5)
        {
            assert(r > 0);
        }

        virtual ~LoTriangleVectorFormat() {}

        const auto& rows() const { return _order; }

        const auto& cols() const { return _order; }

        auto& set_element(const index_type& i, const index_type& j, const element_type& v)
        {
            check_bounds(i, j);
            if (i >= j) _elements.set_element(get_index(i, j), v);
            else assert(v == zero);
            return *this;
        }

        const auto& get_element(const index_type& i, const index_type& j) const
        {
            check_bounds(i, j);
            return i >= j ? _elements.get_element(get_index(i, j)) : zero;
        }

        void init_elements(const element_type& v) { _elements.init_elements(v); }
    };


    template < class Vector >
    class UpTriangleVectorFormat : public LoTriangleVectorFormat<Vector>
    {
    public:
        using base_type = LoTriangleVectorFormat<Vector>;
        using index_type = typename base_type::index_type;
        using element_type = typename base_type::element_type;

        explicit UpTriangleVectorFormat(const index_type& r)
            : base_type(r)
        {}

        auto& set_element(const index_type& i, const index_type& j, const element_type& v)
        {
            return base_type::set_element(j, i, v);
        }

        const auto& get_element(const index_type& i, const index_type& j) const
        {
            return base_type::get_element(j, i);
        }
    };
}