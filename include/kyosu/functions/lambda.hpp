//======================================================================================================================
/*
  Kyosu - Complex Without Complexes
  Copyright: KYOSU Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#include <kyosu/details/callable.hpp>
#include <kyosu/functions/to_complex.hpp>
#include <kyosu/functions/exp2.hpp>
#include <kyosu/functions/deta.hpp>

namespace kyosu
{
  template<typename Options>
  struct lambda_t : eve::elementwise_callable<lambda_t, Options>
  {
    template<concepts::cayley_dickson Z>
    KYOSU_FORCEINLINE constexpr Z operator()(Z const& z) const noexcept
    {
      if constexpr(concepts::complex<Z> )
      {
        auto zz = exp2(z);
        auto k = (z-1)/(z-2);
        auto r = if_else(z == complex(eve::one(eve::as(real(z)))), complex(eve::inf(eve::as(real(z)))), k*deta(1u, zz));
        imag(r) = eve::if_else(is_real(z), eve::zero, imag(r));
        return r;
      }
      else
      {
        return kyosu::_::cayley_extend(*this, z);
      }
    }

    template<concepts::real V>
    KYOSU_FORCEINLINE constexpr complex_t<V> operator()(V v) const noexcept
    { return (*this)(complex(v)); }

    KYOSU_CALLABLE_OBJECT(lambda_t, lambda_);
};
//======================================================================================================================
//! @addtogroup functions
//! @{
//!   @var lambda
//! @brief Callable object computing The Dirichlet \f$ \displaystyle \lambda(z) = \sum_0^\infty \frac{1}{(2n+1)^z}\f$
//!
//! This function can be extended to the whole complex plane as \f$\lambda(z) = \zeta(z)(1-2^{-z})\f$
//! (where \f$\zeta\f$ is the Riemann zeta function). It coincides with the serie where the serie converges.
//! However for `z = 1` the result is \f$\infty\f$.
//! The usual extension mechanism is used for general Cayley-dickson input values.
//!
//!   @groupheader{Header file}
//!
//!   @code
//!   #include <kyosu/functions.hpp>
//!   @endcode
//!
//!   @groupheader{Callable Signatures}
//!
//!   @code
//!   namespace kyosu
//!   {
//!      template<unsigned_scalar_value K, eve::ordered_value T>              constexpr auto lambda(T z) noexcept;  //1
//!      template<unsigned_scalar_value K, kyosu::concepts::cayley-dickson T> constexpr auto lambda(T z) noexcept;  //2
//!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * `z` : cayley_dickson or real value to process.
//!
//! **Return value**
//!
//!    Returns the Dirichlet sum \f$  \displaystyle \sum_0^\infty \frac{1}{(2n+1)^z}\f$
//!
//!  @groupheader{External references}
//!   *  [Wolfram MathWorld: Dirichlet lambda](https://mathworld.wolfram.com/DirichletLambdaFunction.html)
//!   *  [Wikipedia: Dirichlet series](https://en.wikipedia.org/wiki/Dirichlet_series)
//!
//!  @groupheader{Example}
//!  @godbolt{doc/lambda.cpp}
//======================================================================================================================
  inline constexpr auto lambda = eve::functor<lambda_t>;
//======================================================================================================================
//! @}
//======================================================================================================================
}
