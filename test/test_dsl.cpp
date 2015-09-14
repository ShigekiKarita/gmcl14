#include "utils.hpp"

#include <gmcl14/dsl/detail.hpp>

TEST_CASE("DSL test", "[DSL]")
{
    using shape0 = MatrixDSL::rectangle<>;
    using shape1 = MatrixDSL::lower_triangle<>;
    using shape2 = MatrixDSL::lower_triangle<>;
    static_assert(shape0::id != shape1::id, "compare different ids");
    static_assert(shape1::id == shape2::id, "compare same ids");
}