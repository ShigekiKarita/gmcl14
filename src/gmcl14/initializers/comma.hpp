#pragma once

#include <cassert>
#include <initializer_list>

namespace MatrixICCL
{
    template < class Generator >
    class DenseCCommaInitializer
    {
    public:
        using config       = typename Generator::config;
        using index_type   = typename config::index_type;
        using element_type = typename config::element_type;
        using matrix_type  = typename config::matrix_type;

    private:
        matrix_type& _matrix;
        index_type _i, _j;

    protected:
        void insert(const element_type& v)
        {
            assert(_i < _matrix.rows());
            assert(_j < _matrix.cols());

            _matrix.set_element(_i, _j, v);
            ++_j;

            if (_j == _matrix.cols())
            {
                _j = 0;
                ++_i;
            }
        }

    public:
        DenseCCommaInitializer(matrix_type& m, const element_type& first_val)
            : _matrix(m), _i(0), _j(0)
        {
            insert(first_val);
        }

        auto& operator,(const element_type& v)
        {
            insert(v);
            return *this;
        }

        auto& operator=(std::initializer_list<element_type> init_list)
        {
            for (auto&& i : init_list)
            {
                insert(i);
            }
        }
    };
}