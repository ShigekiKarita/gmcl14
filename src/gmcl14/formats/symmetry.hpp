#pragma once

namespace MatrixICCL
{
    template < class Format >
    class Symmetry : public Format
    {
    public:
        using config       = typename Format::config;
        using index_type   = typename config::index_type;
        using element_type = typename config::element_type;

        Symmetry(const index_type& rows, const index_type& cols)
            : Format(rows, cols)
        {}

        auto& set_element(const index_type& i, const index_type& j, const element_type& v)
        {
            return i >= j
                ? Format::set_element(i, j, v)
                : Format::set_element(j, i, v);
        }

        const auto& get_element(const index_type& i, const index_type& j)
        {
            return i >= j
                ? Format::get_element(i, j)
                : Format::get_element(j, i);
        }
    };
}