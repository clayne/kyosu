//======================================================================================================================
/*
  Kyosu - Complex Without Complexes
  Copyright : KYOSU Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <kyosu/kyosu.hpp>
#include <test.hpp>

TTS_CASE_WITH ( "Check kyosu::trunc over real"
              , kyosu::real_types
              , tts::generate(tts::between(-10,10))
              )
(auto data)
{
  TTS_EQUAL(kyosu::trunc(data), eve::trunc(data));
};

TTS_CASE_WITH ( "Check kyosu::trunc over complex"
              , kyosu::real_types
              , tts::generate(tts::between(-10,10), tts::between(-10,10))
              )
(auto r, auto i)
{
  TTS_EQUAL(kyosu::trunc(kyosu::to_complex(r,i)), kyosu::to_complex(eve::trunc(r),eve::trunc(i)));
};

TTS_CASE_WITH ( "Check kyosu::trunc over quaternion"
              , kyosu::real_types
              , tts::generate ( tts::between(-10,10), tts::between(-10,10)
                              , tts::between(-10,10), tts::between(-10,10)
                              )
              )
  <typename T>(T r, T i, T j, T k)
{
  using type = kyosu::as_quaternion_t<T>;
  TTS_EQUAL(kyosu::trunc(type(r,i,j,k)), type(eve::trunc(r), eve::trunc(i), eve::trunc(j), eve::trunc(k)));
};

TTS_CASE_WITH ( "Check kyosu::trunc over octonion"
              , kyosu::real_types
              , tts::generate ( tts::between(-10,10), tts::between(-10,10)
                              , tts::between(-10,10), tts::between(-10,10)
                              , tts::between(-10,10), tts::between(-10,10)
                              , tts::between(-10,10), tts::between(-10,10)                              )
              )
  <typename T>(T r, T i, T j, T k, T l, T li, T lj, T lk)
{
  using type = kyosu::as_octonion_t<T>;
  TTS_EQUAL(kyosu::trunc(type(r,i,j,k,l,li,lj,lk)), type(eve::trunc(r), eve::trunc(i), eve::trunc(j), eve::trunc(k)
                                                       , eve::trunc(l), eve::trunc(li), eve::trunc(lj), eve::trunc(lk) ));
};
