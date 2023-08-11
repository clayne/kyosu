//======================================================================================================================
/*
  Kyosu - Complex Math Made Easy
  Copyright : KYOSU Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <eve/traits.hpp>
#include <type_traits>

namespace kyosu::concepts
{
  /// General Caley-Dickinson concept
  template<typename T>
  concept caley_dickinson = requires(T const&)
  {
    typename eve::element_type_t<std::remove_cvref_t<T>>::is_caley_dickinson;
  };

  /// Complex number concept
  template<typename T>
  concept complex     = caley_dickinson<T> && eve::element_type_t<std::remove_cvref_t<T>>::static_size == 2;

  /// Quaternion concept
  template<typename T>
  concept quaternion  = caley_dickinson<T> && eve::element_type_t<std::remove_cvref_t<T>>::static_size == 4;

  /// Octonion concept
  template<typename T>
  concept octonion    = caley_dickinson<T> && eve::element_type_t<std::remove_cvref_t<T>>::static_size == 8;
}