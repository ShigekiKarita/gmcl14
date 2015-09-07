#include <iostream>
#include <gmcl14/containers/dyn1d.hpp>
#include <gmcl14/containers/dyn2d.hpp>

#undef NDEBUG

int main()
{
    struct g
    {
        struct config
        {
            using index_type = int;
            using element_type = double;
        };
    };

    MatrixICCL::Dyn1DContainer<g> m1(2);
    m1.set_element(1, 0.5);
    assert(m1.get_element(1) == 0.5);

    MatrixICCL::Dyn2DCContainer<g> m2c(2, 3);
    m2c.set_element(1, 2, 0.5);
    assert(m2c.get_element(1, 2) == 0.5);

    MatrixICCL::Dyn2DFContainer<g> m2f(3, 2);
    m2f.set_element(2, 1, 0.5);
    assert(m2f.get_element(2, 1) == 0.5);
}