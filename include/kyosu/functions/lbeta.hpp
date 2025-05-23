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
#include <kyosu/functions/log.hpp>
#include <kyosu/functions/beta.hpp>

namespace kyosu
{
  template<typename Options>
  struct lbeta_t : eve::strict_elementwise_callable<lbeta_t, Options>
  {
    template<concepts::cayley_dickson_like Z0, concepts::cayley_dickson_like Z1>
    KYOSU_FORCEINLINE constexpr auto  operator()(Z0 const& z0, Z1 const & z1) const noexcept -> complexify_t<decltype(z0+z1)>
    {
      if constexpr(concepts::real<Z0> && concepts::real<Z1>) return (*this)(complex(z0), complex(z1));
      else return KYOSU_CALL(z0, z1);
    }

    KYOSU_CALLABLE_OBJECT(lbeta_t, lbeta_);
  };

//======================================================================================================================
//! @addtogroup functions
//! @{
//!   @var lbeta
//!   @brief Computes the principal branch of the natural logarithm of the `beta` function.
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
//!      tauto lbeta(auto x,auto y) noexcept;
//!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * `x`,`y` : Values to process.
//!
//!   **Return value**
//!
//!     - Real typed entries are treated as complex ones.
//!     - Returns `log(beta(x, y))`.
//!
//!  @groupheader{External references}
//!   *  [Wolfram MathWorld: Beta Function](https://mathworld.wolfram.com/BetaFunction.html)
//!
//!  @groupheader{Example}
//!  @godbolt{doc/lbeta.cpp}
//======================================================================================================================
  inline constexpr auto lbeta = eve::functor<lbeta_t>;
//======================================================================================================================
//! @}
//======================================================================================================================
}

namespace kyosu::_
{
  template<typename Z0,  typename Z1, eve::callable_options O>
  KYOSU_FORCEINLINE constexpr auto lbeta_(KYOSU_DELAY(), O const&, Z0 z0, Z1 z1) noexcept
  {
    if constexpr(kyosu::concepts::complex_like<Z0> && kyosu::concepts::complex_like<Z1>)
    {
      return kyosu::log(kyosu::beta(z0, z1));
    }
    else return kyosu::_::cayley_extend2(kyosu::lbeta, z0, z1);
  }
}
