//======================================================================================================================
/*
  Kyosu - Complex Without Complexes
  Copyright : KYOSU Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <kyosu/kyosu.hpp>
#include <test.hpp>
#include <complex>

template < typename T >
auto cv(std::complex < T > const &sc)
{
  return kyosu::complex(sc.real(), sc.imag());
}

TTS_CASE_WITH( "Check behavior of cot on scalar"
        , tts::bunch<kyosu::scalar_real_types>
        , tts::generate( tts::randoms(-3, 3), tts::randoms(-3, 3))
        )
  <typename T>(T const& a0, T const& a1 )
{
  auto prec = sizeof(eve::element_type_t<T>) == 8 ?  1e-7 : 1.e-3;
  using e_t = typename T::value_type;
  using c_t = std::complex<e_t>;
  using kc_t = kyosu::complex_t<e_t>;
  for(size_t i = 0; i < a0.size(); ++i)
  {
    auto e = a0[i];
    auto f = a1[i];
    TTS_RELATIVE_EQUAL(kyosu::cot(kc_t(e, f)),  kyosu::rec(cv(std::tan(c_t(e, f)))), prec);
  }
};

TTS_CASE_WITH( "Check behavior of cot on wide"
             , kyosu::simd_real_types
             , tts::generate( tts::randoms(1, 10)
                            , tts::randoms(-3, 3))
             )
  <typename T>(T const& a0, T const& a1 )
{
  auto prec = sizeof(eve::element_type_t<T>) == 8 ?  1e-7 : 1.e-2;
  using e_t = T;
  using ke_t = kyosu::complex_t<e_t>;
  using c_t = std::complex<eve::element_type_t<e_t>>;
  ke_t e([&](auto i, auto){return kyosu::rec(cv(std::tan(c_t(a0.get(i), a1.get(i))))); });
  TTS_RELATIVE_EQUAL(kyosu::cot(ke_t{a0,a1}), e, prec);
};
