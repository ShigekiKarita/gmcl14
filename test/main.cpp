#include <iostream>
#include <gmcl14/containers/dyn1d.hpp>
#include <gmcl14/containers/dyn2d.hpp>

#define CATCH_CONFIG_MAIN
#include "utils.hpp"

struct Mtype
{
    struct config
    {
        using index_type = int;
        using element_type = double;
    };
};


TEST_CASE("Dynamic container", "[dynamic, container]")
{
    for ( auto _ : 1000_ )
    {
        const auto r = test::rrand<double>();

        MatrixICCL::Dyn1DContainer<Mtype> m1(2);
        m1.set_element(1, r);
        REQUIRE(m1.get_element(1) == r);

        MatrixICCL::Dyn2DCContainer<Mtype> m2c(2, 3);
        m2c.set_element(1, 2, r);
        REQUIRE(m2c.get_element(1, 2) == r);

        MatrixICCL::Dyn2DFContainer<Mtype> m2f(3, 2);
        m2f.set_element(2, 1, r);
        REQUIRE(m2f.get_element(2, 1) == r);
    }
}
