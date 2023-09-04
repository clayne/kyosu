//======================================================================================================================
/*
  Kyosu - Complex Without Complexes
  Copyright : KYOSU Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <kyosu/details/invoke.hpp>

namespace kyosu::tags
{
  struct callable_hypot : eve::elementwise
  {
    using callable_tag_type = callable_hypot;

    KYOSU_DEFERS_CALLABLE(hypot_);

    static KYOSU_FORCEINLINE auto deferred_call(auto
                                               , eve::ordered_value auto const&... vs) noexcept
    {
      return eve::hypot(vs...);
    }

    KYOSU_FORCEINLINE auto operator()(auto const&... targets ) const noexcept
    -> decltype(eve::tag_invoke(*this, targets...))
    {
      return eve::tag_invoke(*this, targets...);
    }

//     template<typename... T>
//     eve::unsupported_call<callable_hypot(T&&...)> operator()(T&&... x) const
//     requires(!requires { eve::tag_invoke(*this, KYOSU_FWD(x)...); }) = delete;
  };
}

namespace kyosu
{
//======================================================================================================================
//! @addtogroup functions
//! @{
//!   @var hypot
//!   @brief Callable object computing the hypot operation.
//!
//!   **Defined in Header**
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
//!      template< floating_value P, typename ... Ts>
//!      auto operator()(Ts ... zi ) const noexcept
///!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * ` zi...` : Values to process.
//!
//!   **Return value**
//!
//!     Returns \f$ \sqrt\sum_{i = 0}^n//! |z_i|^2} \f$.
//!
//!  @groupheader{Example}
//!
//!  @godbolt{doc/hypot.cpp}
//! @}
//======================================================================================================================
inline constexpr tags::callable_hypot hypot = {};
}
