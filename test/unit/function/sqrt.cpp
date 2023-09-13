//======================================================================================================================
/*
  Kyosu - Complex Without Complexes
  Copyright : KYOSU Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <kyosu/kyosu.hpp>
#include <test.hpp>

TTS_CASE_WITH ( "Check kyosu::sqrt over real"
              , kyosu::real_types
              , tts::generate(tts::between(-10,10))
              )
  <typename T>  (T v)
{
  auto asq = eve::sqrt(eve::abs(v));
  TTS_RELATIVE_EQUAL(kyosu::sqrt(v),  kyosu::if_else(eve::is_gez(v)
                                                    , kyosu::to_complex(asq, T(0))
                                                    , kyosu::to_complex(T(0), asq)), 1.0e-5);
};

TTS_CASE_WITH ( "Check kyosu::sqrt over complex"
              , kyosu::real_types
              , tts::generate(tts::between(-10,10), tts::between(-10,10))
              )
(auto r, auto i)
{
  auto c = kyosu::to_complex(r,i);
  TTS_RELATIVE_EQUAL(kyosu::sqr(kyosu::sqrt(c)), c, 1e-5);
};

TTS_CASE_WITH ( "Check kyosu::sqrt over quaternion"
              , kyosu::real_types
              , tts::generate ( tts::between(-10,10), tts::between(-10,10)
                              , tts::between(-10,10), tts::between(-10,10)
                              )
              )
  <typename T>(T r, T i, T j, T k)
{
  using type = kyosu::as_quaternion_t<T>;
  auto q = type(r,i,j,k);
  TTS_RELATIVE_EQUAL(kyosu::sqr((kyosu::sqrt(q))), q, 1e-5);
};