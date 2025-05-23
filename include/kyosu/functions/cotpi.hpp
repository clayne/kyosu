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
#include <kyosu/functions/tanpi.hpp>

namespace kyosu
{
  template<typename Options>
  struct cotpi_t : eve::elementwise_callable<cotpi_t, Options>
  {
    template<concepts::cayley_dickson_like Z>
    KYOSU_FORCEINLINE constexpr Z operator()(Z const& z) const noexcept
    {
      return  KYOSU_CALL(z);
    }

    KYOSU_CALLABLE_OBJECT(cotpi_t, cotpi_);
  };

//======================================================================================================================
//! @addtogroup functions
//! @{
//!   @var cotpi
//!   @brief Computes the cotangent from the argument in \f$\pi\f$ multiples.
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
//!      template<kyosu::concepts::cayley_dickson T> constexpr T cotpi(T z) noexcept;
//!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * `z`: Value to process.
//!
//!   **Return value**
//!
//!     Returns the cotangent from the argument in \f$\pi\f$ multiples.
//!
//!  @groupheader{Example}
//!
//!  @godbolt{doc/cotpi.cpp}
//======================================================================================================================
  inline constexpr auto cotpi = eve::functor<cotpi_t>;
//======================================================================================================================
//! @}
//======================================================================================================================
}

namespace kyosu::_
{
  template<typename Z, eve::callable_options O>
  KYOSU_FORCEINLINE constexpr auto cotpi_(KYOSU_DELAY(), O const& o, Z z) noexcept
  {
    if constexpr(concepts::real<Z>)
      return eve::cotpi(z);
    else if constexpr(concepts::complex<Z> )
    {
      auto r = kyosu::tanpi(z);
      r = kyosu::if_else(kyosu::is_infinite(r), eve::zero, kyosu::rec(r));
      r = kyosu::if_else(kyosu::is_real(z) && eve::is_flint(kyosu::real(z)*2) && eve::is_not_flint(kyosu::real(z)), eve::zero, r);
      return  kyosu::if_else(kyosu::is_real(z), kyosu::complex(kyosu::real(r)), r);
    }
    else
    {
      return _::cayley_extend(kyosu::cotpi, z);
    }
  }
}
