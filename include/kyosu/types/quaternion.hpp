//======================================================================================================================
/*
  Kyosu - Complex Math Made Easy
  Copyright : TTS Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <kyosu/types/caley_dickinson.hpp>
#include <eve/concept/value.hpp>

namespace kyosu
{
  template<typename T>
  using quaternion = caley_dickinson<T,4>;
}
