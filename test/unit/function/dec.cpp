//======================================================================================================================
/*
  Kyosu - Complex Without Complexes
  Copyright : KYOSU Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <kyosu/kyosu.hpp>
#include <test.hpp>

TTS_CASE_WITH ( "Check kyosu::dec over real"
              , kyosu::real_types
              , tts::generate(tts::randoms(-10,10))
              )
(auto data)
{
  TTS_EQUAL(kyosu::dec(data), eve::dec(data));
};

TTS_CASE_WITH ( "Check kyosu::dec over complex"
              , kyosu::real_types
              , tts::generate(tts::randoms(-10,10), tts::randoms(-10,10))
              )
<typename T>(T r, T i)
{
  using type = kyosu::complex_t<T>;
  TTS_EQUAL(kyosu::dec(type(r,i)), type(r-1,i));
};

TTS_CASE_WITH ( "Check kyosu::dec over quaternion"
              , kyosu::real_types
              , tts::generate ( tts::randoms(-10,10), tts::randoms(-10,10)
                              , tts::randoms(-10,10), tts::randoms(-10,10)
                              )
              )
<typename T>(T r, T i, T j, T k)
{
  using type = kyosu::quaternion_t<T>;
  TTS_EQUAL(kyosu::dec(type(r,i,j,k)), type(r-1,i,j,k));
};
