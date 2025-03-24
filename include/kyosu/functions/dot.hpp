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
  struct dot_t : eve::strict_elementwise_callable<dot_t, Options>
  {
    template<typename Z0, typename Z1>
    requires(concepts::cayley_dickson_like<Z0> || concepts::cayley_dickson_like<Z1>)
      KYOSU_FORCEINLINE constexpr auto operator()(Z0 const& z0, Z1 const & z1) const noexcept -> decltype(z0+z1)
    {
      if constexpr(concepts::real<Z0> && concepts::real<Z1>)
        return z0*z1;
      else
        return z0*conj(z1);
    }

    KYOSU_CALLABLE_OBJECT(dot_t, dot_);
};

//======================================================================================================================
//! @addtogroup functions
//! @{
//!   @var dot
//!   @brief Computes elementwise the dot product of the coordinates of the corresponding element.
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
//!      constexpr auto dot(auto z0,  auto z1) noexcept;
//!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * `z0`, `z1`: Values to process.
//!
//!   **Return value**
//!
//!     Returns the dot product of `z0` and `z1`: `z0*conj(z1)`.
//!     Arguments can be a mix of floating or Cayley-Dickson values.
//!     for real typed inputs the result is real typed.
//!
//!  @groupheader{Example}
//!
//!  @godbolt{doc/dot.cpp}
//======================================================================================================================
  inline constexpr auto dot = eve::functor<dot_t>;
//======================================================================================================================
//! @}
//======================================================================================================================
}
