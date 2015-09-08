#pragma once

#include <cassert>
#include <memory>
#include <vector>

namespace MatrixICCL
{
    template < class Generator >
    class Dyn2DCContainer
    {
    public:
        using config = typename Generator::config;
        using element_type = typename config::element_type;
        using index_type = typename config::index_type;
        using storage_type = std::vector<element_type>;
    protected:
        index_type _rows, _cols;
        element_type* _elements_ptr;
        element_type** _rows_ptr;

        void check_bounds(const index_type& i, const index_type& j) const
        {
            assert(i >= 0 && i < rows());
            assert(j >= 0 && j < cols());
        }

    public:
        Dyn2DCContainer(const index_type& r, const index_type&c)
            : _rows(r), _cols(c)
        {
            std::cout << "create" << std::endl;
            assert(rows() > 0);
            assert(cols() > 0);

            _elements_ptr = new element_type[rows() * cols()];
            assert(_elements_ptr);
            _rows_ptr = new element_type*[rows()];
            assert(_rows_ptr);

            auto p = _elements_ptr;
            for (index_type i = 0; i < rows(); ++i, p += cols())
            {
                _rows_ptr[i] = p;
            }
        }

        virtual ~Dyn2DCContainer() {
            std::cout << "destory" << std::endl;
            delete[] _elements_ptr;
            delete[] _rows_ptr;
        }

        auto& set_element(const index_type& i, const index_type& j, const element_type& v)
        {
            check_bounds(i, j);
            _rows_ptr[i][j] = v;
            return *this;
        }

        const auto& get_element(const index_type& i, const index_type& j) const
        {
            check_bounds(i, j);
            return _rows_ptr[i][j];
        }

        const auto& rows() const { return _rows; }

        const auto& cols() const { return _cols; }

        auto& init_elements(const element_type& v=0)
        {
            for (auto i = rows(); --i;)
            {
                for (auto j = cols(); --j;)
                {
                    set_element(i, j, v);
                }
            }
            return *this;
        }
    };

    template < class Generator >
    class Dyn2DFContainer : public Dyn2DCContainer<Generator>
    {
    public:
        using base_type = Dyn2DCContainer<Generator>;
        using index_type = typename base_type::index_type;
        using element_type = typename base_type::element_type;

        Dyn2DFContainer(const index_type& r, const index_type& c)
            : base_type (c, r)
        {}

        auto& set_element(const index_type& i, const index_type& j, const element_type& v)
        {
            return base_type::set_element(j, i, v);
        }

        const auto& get_element(const index_type& i, const index_type& j) const
        {
            return base_type::get_element(j, i);
        }

        const auto& rows() const { return base_type::cols(); }
        const auto& cols() const { return base_type::rows(); }
    };
} // namespace MatrixICCL
