//======================================================================================================================
/*
  Kyosu - Complex Without Complexes
  Copyright: KYOSU Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#include <kyosu/details/callable.hpp>
#include <kyosu/details/cayleyify.hpp>

namespace kyosu
{
  template<typename Options>
  struct sinhc_t : eve::elementwise_callable<sinhc_t, Options>
  {
    template<concepts::cayley_dickson Z>
    KYOSU_FORCEINLINE constexpr Z operator()(Z const& z) const noexcept
    {
      if constexpr(concepts::complex<Z> )
      {
        auto s = kyosu::sinh(z);
        using u_t = eve::underlying_type_t<Z>;
        return kyosu::if_else(kyosu::abs(z) < eve::eps(eve::as(u_t())), eve::one(eve::as(u_t())), s/z);
      }
      else
      {
        return _::cayley_extend(*this, z);
      }
    }

    template<concepts::real V>
    KYOSU_FORCEINLINE constexpr V operator()(V v) const noexcept
    { return eve::sinhc(v); }

    KYOSU_CALLABLE_OBJECT(sinhc_t, sinhc_);
};

//======================================================================================================================
//! @addtogroup functions
//! @{
//!   @var sinhc
//!   @brief Computes the hyperbolic sine cardinal of the argument.
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
//!      template<kyosu::concepts::cayley_dickson T> constexpr auto sinhc(T z) noexcept;
//!      template<eve::floating_ordered_value T>     constexpr auto sinhc(T z) noexcept;
//!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * `z`: Value to process.
//!
//!   **Return value**
//!
//!     Returns the hyperbolic sine cardinal of the argument.
//!
//!  @groupheader{Example}
//!
//!  @godbolt{doc/sinhc.cpp}
//======================================================================================================================
  inline constexpr auto sinhc = eve::functor<sinhc_t>;
//======================================================================================================================
//! @}
//======================================================================================================================
}
