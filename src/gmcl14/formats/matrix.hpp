#pragma once

#include <ostream>

template < class Expr > class BinaryExpression;

namespace MatrixICCL
{
    template < class OptBoundCheckedMatrix >
    class Matrix : public OptBoundCheckedMatrix
    {
    public:
        using config       = typename OptBoundCheckedMatrix::config;
        using index_type   = typename config::index_type;
        using element_type = typename config::element_type;

        Matrix(const index_type& rows = 0, const index_type& cols = 0, const element_type& init = element_type(0))
        {
            init_elements(init);
        }

        auto operator=(const element_type& v)
        {
            return CommaInitializer(*this, v);
        }

        template < class Expr >
        auto& operator=(const BinaryExpression<Expr>& expr)
        {
            expr.assign(this);
            return *this;
        }

        template < class T >
        auto& operator=(const Matrix<T>& that)
        {
            MatrixAssignmet<T>::assign(this, that);
            return *this;
        }

        template < class T >
        auto& display(std::ostream& out, const Matrix<T>& m)
        {
            for (index_type i = 0; i < rows(); ++i)
            {
                for (index_type j = 0; j < cols(); ++j)
                {
                    out << get_element(i, j) << "\t";
                    out << std::endl;
                }
            }
            return out;
        }
    };
} // namespace MatrixICCL

template < class T >
auto& operator<<(std::ostream& out, const MatrixICCL::Matrix<T>& m)
{
    return m.display(out);
}