//======================================================================================================================
/*
  Kyosu - Complex Without Complexes
  Copyright : KYOSU Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <kyosu/kyosu.hpp>
#include <test.hpp>

TTS_CASE_WITH ( "Check kyosu::cyl_bessel_j0 over real"
              , kyosu::scalar_real_types
              , tts::generate(tts::randoms(-10,10))
              )
<typename T>(T )
{
  using e_t = eve::element_type_t<T>;
  if constexpr(sizeof(e_t) == 8)
  {
    std::array<T, 16> re{-5.2999999999999998e+00, -4.5999999999999996e+00, -3.8999999999999999e+00, -3.2000000000000002e+00, -2.5000000000000000e+00, -1.7999999999999998e+00, -1.1000000000000005e+00, -4.0000000000000036e-01, 2.9999999999999982e-01, 1.0000000000000000e+00, 1.7000000000000002e+00, 2.3999999999999995e+00, 3.0999999999999988e+00, 3.7999999999999998e+00, 4.4999999999999991e+00, 5.2000000000000002e+00};
    std::array<T, 16> im{8.0000000000000000e+00, -7.0000000000000000e+00, 6.0000000000000000e+00, -5.0000000000000000e+00, 4.0000000000000000e+00, -3.0000000000000000e+00, 2.0000000000000000e+00, -1.0000000000000000e+00, -0.0000000000000000e+00, 1.0000000000000000e+00, -2.0000000000000000e+00, 3.0000000000000000e+00, -4.0000000000000000e+00, 5.0000000000000000e+00, -6.0000000000000000e+00, 7.0000000000000000e+00};
    std::array<T, 16> reres{2.1988399563106543e+02, 2.4475379403286627e-04, -1.0949275587116509e+02, 7.0926149688609519e-04, -1.2134577316119763e+01, -1.8269104646258683e-02, 2.9718238932026955e+00, -1.3938490578596488e-01, 9.7762624653829611e-01, 1.6477670588097639e+00, 5.7801144894856459e-02, -3.7706880470084005e+00, -1.7305844653144060e-03, -4.5587245103257374e+01, -7.0927339073308311e-04, 4.7382830132773599e+01};
    std::array<T, 16> imres{-7.4457014389297478e+02, 4.2222247912422257e-05, -5.4163840901549179e+01, -2.0501433281152636e-03, 1.6547181744548173e+01, -9.6142660041630447e-03, 2.9905093588667149e+00, 2.1994852133809409e-01, 8.0727357780451992e-01, -9.4200443654515464e-01, -2.8437721740099727e-02, -7.4893412346961954e+00, -6.1357907332358014e-03, 1.5088797239958149e+01, 7.1380035703526274e-05, 2.9602274269542443e+02};
    for(int i=0; i < 16; ++i)
    {
      auto c = kyosu::complex(re[i], im[i]);
      auto res = kyosu::complex(reres[i], imres[i]);
      TTS_RELATIVE_EQUAL(kyosu::cyl_bessel_h2_0(c), res, 1.0e-4) << i <<  " <- " << c << '\n';
    }
  }
};