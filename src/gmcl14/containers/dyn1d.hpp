#pragma once

#include <cassert>
#include <memory>

namespace MatrixICCL
{
    template < class Generator >
    class Dyn1DContainer
    {
    public:
        using config = typename Generator::config;
        using element_type = typename config::element_type;
        using index_type = typename config::index_type;

    protected:
        index_type _size;
        std::unique_ptr<element_type[]> _data_ptr;

        void check_bounds(const index_type& i) const
        {
            assert(i >= 0 && i < size());
        }

    public:
        explicit Dyn1DContainer(const index_type& s) : _size(s)
        {
            assert(size() > 0);
            _data_ptr.reset(new element_type[size()]);
            assert(_data_ptr);
        }

        auto& set_element(const index_type& i, const element_type& v)
        {
            check_bounds(i);
            _data_ptr[i] = v;
            return *this;
        }

        const element_type& get_element(const index_type& i) const
        {
            check_bounds(i);
            return _data_ptr[i];
        }

        const index_type& size() const
        {
            return _size;
        }

        void init_elements(const element_type& v)
        {
            for (auto i = size(); --i;)
            {
                set_element(i, v);
            }
        }
    };
} // namespace MatrixICCL
