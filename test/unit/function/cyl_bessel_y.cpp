//======================================================================================================================
/*
  Kyosu - Complex Without Complexes
  Copyright : KYOSU Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <kyosu/kyosu.hpp>
#include <test.hpp>

TTS_CASE_WITH ( "Check kyosu::cyl_bessel_k over real"
              , kyosu::scalar_real_types
              , tts::generate(tts::randoms(-10,10))
              )
  <typename T>(T )
{
  if constexpr(sizeof(T) == 8)
  {
    std::array<T, 16> re{-5.2999999999999998e+00, -4.5999999999999996e+00, -3.8999999999999999e+00, -3.2000000000000002e+00
        , -2.5000000000000000e+00, -1.7999999999999998e+00, -1.1000000000000005e+00, -4.0000000000000036e-01
        , 2.9999999999999982e-01, 1.0000000000000000e+00, 1.7000000000000002e+00, 2.3999999999999995e+00
        , 3.0999999999999988e+00, 3.7999999999999998e+00, 4.4999999999999991e+00, 5.2000000000000002e+00};
    std::array<T, 16> im{8.0000000000000000e+00, -7.0000000000000000e+00, 6.0000000000000000e+00, -5.0000000000000000e+00
        , 4.0000000000000000e+00, -3.0000000000000000e+00, 2.0000000000000000e+00, -1.0000000000000000e+00
        , -0.0000000000000000e+00, 1.0000000000000000e+00, -2.0000000000000000e+00, 3.0000000000000000e+00
        , -4.0000000000000000e+00, 5.0000000000000000e+00, -6.0000000000000000e+00, 7.0000000000000000e+00};

    constexpr int N = 0;
    T v1 = 1.0/3;
    std::cout << "v1 " << v1 << std::endl;
    auto n = int(v1);
    using vc_t = std::array<T, 16>;
    using a_t = std::array<vc_t, N+1>;
    a_t reresi_03{
      vc_t{2.6513657493935034e+02, 1.5122843619345218e+02, 5.0648789106855794e+01, 7.0207071123160771e+00, -4.0157239964866642e+00, -3.8818208974565880e+00, -1.9700774006295092e+00, -8.8015136866517407e-01, -1.2133448538831417e+00, -4.7036021607109069e-02, 1.3293987996432377e+00, 4.1474049533381976e+00, 7.7005870282777540e+00, 4.6857906393290154e+00, -2.8742001471989823e+01, -1.3952369860713620e+02}
    };
    a_t imresi_03{
      vc_t{2.8090371647178273e+02, -1.7536301901048642e+01, -3.3401195686627879e+01, 2.3525800606543957e+01, -9.3284782480155641e+00, 1.9546375587054139e+00, 5.0096629910926505e-01, -9.8992537961477600e-01, 0.0000000000000000e+00, 8.4240922212198033e-01, -1.2574860466731328e+00, 1.8207337449423835e-01, 6.0487612323155489e+00, -2.3373344181702222e+01, 5.1769001839281714e+01, -5.2626238180368290e+01}
    };

    std::vector<kyosu::complex_t<T>> is_03(N+2);
    for (int k = 0; k < 16; ++k)
    {
      auto c = kyosu::complex(re[k], im[k]);
      kyosu::cyl_bessel_y(v1, c, is_03);
      auto vv = T(N+1.0/3);
      for (n = 0; n <= N; ++n)
      {
         auto refi_03=  kyosu::complex_t<T>(reresi_03[n][k], imresi_03[n][k]);
        TTS_RELATIVE_EQUAL(refi_03, is_03[n], 1.e-2) << "n " << n  << " k " << k  << " c "<< c << " arg(c) "<< kyosu::arg(kyosu::conj(c)) << " < 1.57" << '\n';
        TTS_RELATIVE_EQUAL(refi_03,  kyosu::cyl_bessel_y(vv, c), 1.e-2) << "n " << n  << " k " << k  << " c "<< c <<'\n';
      }
    }
  }
};


TTS_CASE_WITH ( "Check kyosu::cyl_bessel_k over real"
              , kyosu::scalar_real_types
              , tts::generate(tts::randoms(-10,10))
              )
  <typename T>(T )
{
  if constexpr(sizeof(T) == 8)
  {
    std::array<T, 16> re{-5.2999999999999998e+00, -4.5999999999999996e+00, -3.8999999999999999e+00, -3.2000000000000002e+00
        , -2.5000000000000000e+00, -1.7999999999999998e+00, -1.1000000000000005e+00, -4.0000000000000036e-01
        , 2.9999999999999982e-01, 1.0000000000000000e+00, 1.7000000000000002e+00, 2.3999999999999995e+00
        , 3.0999999999999988e+00, 3.7999999999999998e+00, 4.4999999999999991e+00, 5.2000000000000002e+00};
    std::array<T, 16> im{8.0000000000000000e+00, -7.0000000000000000e+00, 6.0000000000000000e+00, -5.0000000000000000e+00
        , 4.0000000000000000e+00, -3.0000000000000000e+00, 2.0000000000000000e+00, -1.0000000000000000e+00
        , -0.0000000000000000e+00, 1.0000000000000000e+00, -2.0000000000000000e+00, 3.0000000000000000e+00
        , -4.0000000000000000e+00, 5.0000000000000000e+00, -6.0000000000000000e+00, 7.0000000000000000e+00};

    constexpr int N = 0;
    T v1 = -1.0/3;
    std::cout << "v1 " << v1 << std::endl;
    auto n = int(v1);
    using vc_t = std::array<T, 16>;
    using a_t = std::array<vc_t, N+1>;
    a_t reresi_03{
      vc_t{3.7583805458938821e+02, 9.0801266745274788e+01, -3.6012541742235697e+00, -1.6862151475581715e+01, -1.0085674143682983e+01, -3.6432335856963327e+00, -6.0906440868768552e-01, 2.0873153295804381e-01, -1.0003474349638408e-01, 8.6097480021168360e-01, 1.8102650205095943e+00, 2.2453391061314565e+00, -1.3867486242808820e+00, -1.7899822024160851e+01, -5.9204838602123715e+01, -1.1533771231556815e+02}
    };
    a_t imresi_03{
      vc_t{-8.9163224441390696e+01, 1.2219965550991174e+02, -6.0563732479780832e+01, 1.7841777572774447e+01, -1.1808300271084744e+00, -2.3998139242391443e+00, 1.9741006840075483e+00, -1.1510312786004779e+00, 0.0000000000000000e+00, 3.2456737045081957e-01, 5.2569711539964548e-01, -3.4904700264222477e+00, 9.6878805608040661e+00, -1.5743030177502007e+01, 9.9294471444101262e-01, 9.4517889913758978e+01}
    };

    std::vector<kyosu::complex_t<T>> is_03(N+2);
    for (int k = 0; k < 16; ++k)
    {
      auto c = kyosu::complex(re[k], im[k]);
      kyosu::cyl_bessel_y(v1, c, is_03);
      auto vv = -T(N+1.0/3);
      for (n = 0; n <= N; ++n)
      {
         auto refi_03=  kyosu::complex_t<T>(reresi_03[n][k], imresi_03[n][k]);
        TTS_RELATIVE_EQUAL(refi_03, is_03[n], 1.e-2) << "n " << n  << " k " << k  << " c "<< c << " arg(c) "<< kyosu::arg(kyosu::conj(c)) << " < 1.57" << '\n';
        TTS_RELATIVE_EQUAL(refi_03,  kyosu::cyl_bessel_y(vv, c), 1.e-2);
      }
    }
  }
};
