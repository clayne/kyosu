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

namespace kyosu
{
  template<typename Options>
  struct fam_t : eve::strict_elementwise_callable<fam_t, Options>
  {
    template<concepts::cayley_dickson_like Z0, concepts::cayley_dickson_like Z1, concepts::cayley_dickson_like Z2>
    KYOSU_FORCEINLINE constexpr as_cayley_dickson_like_t<Z0, Z1, Z2> operator()(Z0 const& z0, Z1 const & z1, Z2 const & z2) const noexcept
    {
      return KYOSU_CALL(z0, z1, z2);
    }

    KYOSU_CALLABLE_OBJECT(fam_t, fam_);
};

//======================================================================================================================
//! @addtogroup functions
//! @{
//!   @var fam
//!   @brief  Computes fused add multiply.
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
//!     constexpr auto fam(auto z0, auto z1, auto z2) noexcept;
//!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * `z0`, `z1`,`z2`: Values to process.
//!
//!   **Return value**
//!
//!    The call is semantically equivalent to `z0+z1*z2`.
//!
//!  @groupheader{Example}
//!  @godbolt{doc/fam.cpp}
//======================================================================================================================
  inline constexpr auto fam = eve::functor<fam_t>;
//======================================================================================================================
//! @}
//======================================================================================================================
}

namespace kyosu::_
{
  template<typename Z0,  typename Z1,  typename Z2, eve::callable_options O>
  KYOSU_FORCEINLINE constexpr auto fam_(KYOSU_DELAY(), O const&, Z0 z0, Z1 z1, Z2 z2) noexcept
  {
    if constexpr(concepts::real<Z0> && concepts::real<Z1> && concepts::real<Z2>)
      return eve::fam(z0,z1,z2);
    else
      return z0+z1*z2;
  }
}
