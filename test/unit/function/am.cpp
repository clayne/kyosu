//======================================================================================================================
/*
  Kyosu - Complex Without Complexes
  Copyright : KYOSU Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <iomanip>
#include <kyosu/kyosu.hpp>
#include <test.hpp>

TTS_CASE_TPL ( "Check jacobi_elliptic over complex"
             , kyosu::scalar_real_types
             )
  <typename T>(tts::type<T>)
{
  auto pr = tts::prec<T>(4.0e-2, 1.0e-8);
  using c_t = kyosu::complex_t<T>;
  using a_t  = std::array<T, 7 >;
  a_t phi= {0.000000000000000e+00, 1.346396851538483e+00, 2.692793703076966e+00, 4.039190554615448e+00, 5.385587406153931e+00, 6.731984257692414e+00, 8.078381109230897e+00, };
  a_t m= {0.000000000000000e+00, 1.428571428571428e-01, 2.857142857142857e-01, 4.285714285714285e-01, 5.714285714285714e-01, 7.142857142857143e-01, 8.571428571428572e-01, };
  a_t ramp = {                   0,   1.696717861493621,   0.853380674698701,   5.842387616977985,   4.900661768634335,   4.798157643305010, 5.063923053256403};
  a_t iamp = {8.078381109097574,  -1.545860408368032,  -1.126101384553287,  -0.192035497540286,   0.569586142084441,   0.611135912286602, 0};

  for(int i=0; i < 6; ++i)
  {
    c_t z(phi[i], phi[6-i]);
    auto amp = kyosu::am(z, eve::sqrt(m[i]));
    TTS_RELATIVE_EQUAL(amp, kyosu::complex(ramp[i], iamp[i]), pr);
  }
};
