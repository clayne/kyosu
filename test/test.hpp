//======================================================================================================================
/*
  Kyosu - Complex Math Made Easy
  Copyright : KYOSU Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#define TTS_MAIN
#define TTS_CUSTOM_DRIVER_FUNCTION kyosu_entry_point
#include <tts/tts.hpp>

//==================================================================================================
// EVE Specific testing overloads
//==================================================================================================
#include <eve/arch/fundamental_cardinal.hpp>
#include <eve/module/core.hpp>
#include <eve/traits.hpp>
#include <eve/wide.hpp>
#include <kyosu/types.hpp>

namespace eve
{
  template<typename T, typename N>
  inline bool compare_equal(wide<T, N> const &l, wide<T, N> const &r)
  {
    return eve::all(l == r);
  }

  template<typename T>
  inline bool compare_equal(logical<T> const &l, logical<T> const &r)
  {
    if constexpr(eve::simd_value<T>)  return eve::all(l == r);
    else                              return l == r;
  }
}

namespace eve::detail
{
  template<typename T, typename V> auto as_value(callable_object<V> const& v)
  {
    return v(eve::as<T>{});
  }
}

namespace kyosu
{
  using scalar_real_types   = tts::types< float, double>;
  using simd_real_types     = tts::types< eve::wide<float>, eve::wide<double>
                                        , eve::wide<float , eve::wide<float>::cardinal_type::combined_type>
                                        , eve::wide<double, eve::wide<double>::cardinal_type::combined_type>
                                        >;
  using real_types          = tts::concatenate_t<scalar_real_types, simd_real_types>;

  template<typename T>    struct complex_t;
  template<typename... T> struct complex_t<tts::types<T...>> { using types_list = tts::types<as_complex_t<T>...>; };

  using scalar_complex_types = complex_t<scalar_real_types>;
  using simd_complex_types   = complex_t<simd_real_types>;
  using complex_types        = complex_t<real_types>;
}

//==================================================================================================
// KYOSU TTS Entrypoint
//==================================================================================================
#include <iostream>

int main(int argc, char const **argv)
{
  ::tts::initialize(argc,argv);
  auto seed = ::tts::random_seed(18102008);
#ifdef NDEBUG
  constexpr auto assert_status = "Disabled";
#else
  constexpr auto assert_status = "Enabled";
#endif

  std::cout << "[KYOSU] - Target: " << eve::current_api
            << " - Assertions: "    << assert_status
            << " - PRNG Seed: "     << seed
            << std::endl;

  kyosu_entry_point(argc, argv);
  return tts::report(0,0);
}

namespace tts
{
  //================================================================================================
  // Poison wide data when using sub-sized types
  //================================================================================================
  template<eve::simd_value W> auto poison(W data)
  {
    using v_t = eve::element_type_t<W>;

    // Add garbage at the end of sub-native registers
    // For emulated type, there is no such gap so we don't do anything
    if constexpr( (W::size() < eve::fundamental_cardinal_v<v_t>) && !eve::has_emulated_abi_v<W> )
    {
      using p_t   = eve::as_arithmetic_t<eve::as_integer_t<v_t, unsigned>>;
      using ftype = eve::as_wide_t<v_t, eve::fundamental_cardinal_t<v_t>>;

      ftype these(data.storage());

      // Compute a recognizable filler
      for(std::ptrdiff_t i=data.size();i<these.size();++i)
      {
        p_t filler = eve::Constant<p_t, static_cast<p_t>(0xDEADBEEFBABE0000)>() + p_t(i);
        these.set(i, eve::bit_cast(filler,eve::as<v_t>()) );
      }

      return W(these.storage());
    }
    else
    {
      return data;
    }
  }

  //================================================================================================
  // Customization point for argument building
  //================================================================================================
  template<eve::simd_value T>
  auto produce(type<T> const&, auto g, auto& rng, auto... args)
  {
    using e_t = eve::element_type_t<T>;
    auto data = produce(type<std::array<e_t,T::size()>>{},g,rng, args...);

    using v_t = typename decltype(data)::value_type;
    eve::as_wide_t<v_t, eve::cardinal_t<T>> that = eve::load(&data[0], eve::cardinal_t<T>{});

    return poison(that);
  }
}