#pragma once

#include <random>
#include <limits>

namespace test
{
    std::mt19937_64 mtgen;

    template < typename T >
    auto int_udist = std::uniform_int_distribution<>
    (
     std::numeric_limits<T>::min(),
     std::numeric_limits<T>::max()
     );

    template < typename T >
    auto real_udist = std::uniform_real_distribution<>
    (
     std::numeric_limits<T>::min(),
     std::numeric_limits<T>::max()
     );

    template < typename T = int >
    T irand() {
        return int_udist<T>(mtgen);
    }

    template < typename T = float >
    T rrand() {
        return real_udist<T>(mtgen);
    }

}
