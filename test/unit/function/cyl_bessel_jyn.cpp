//======================================================================================================================
/*
  Kyosu - Complex Without Complexes
  Copyright : KYOSU Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <kyosu/kyosu.hpp>
#include <test.hpp>

TTS_CASE_WITH ( "Check kyosu::cyl_bessel_jn over real"
              , kyosu::scalar_real_types
              , tts::generate(tts::randoms(-10,10))
              )
<typename T>(T )
{
  if constexpr(sizeof(T) == 8)
  {
    std::array<T, 16> re{-5.2999999999999998e+00, -4.5999999999999996e+00, -3.8999999999999999e+00, -3.2000000000000002e+00, -2.5000000000000000e+00, -1.7999999999999998e+00, -1.1000000000000005e+00, -4.0000000000000036e-01, 2.9999999999999982e-01, 1.0000000000000000e+00, 1.7000000000000002e+00, 2.3999999999999995e+00, 3.0999999999999988e+00, 3.7999999999999998e+00, 4.4999999999999991e+00, 5.2000000000000002e+00};
    std::array<T, 16> im{8.0000000000000000e+00, -7.0000000000000000e+00, 6.0000000000000000e+00, -5.0000000000000000e+00, 4.0000000000000000e+00, -3.0000000000000000e+00, 2.0000000000000000e+00, -1.0000000000000000e+00, -0.0000000000000000e+00, 1.0000000000000000e+00, -2.0000000000000000e+00, 3.0000000000000000e+00, -4.0000000000000000e+00, 5.0000000000000000e+00, -6.0000000000000000e+00, 7.0000000000000000e+00};
    std::array<T, 16> reres2{-1.3031496812979023e+02, 3.2945269613043862e+01, 3.8719363779645107e+01, 1.8406121149842818e+01, 5.5045646155744805e+00, 7.7822409981718632e-01, -1.8002082625311086e-01, -1.0534140052268921e-01, 1.1165861949063953e-02, 4.1579886943962120e-02, 3.6939751351770811e-01, 2.0935865359340018e+00, 7.1209313192735504e+00, 1.5895620959999437e+01, 1.7204532188423347e+01, -3.7739577283583174e+01};
    std::array<T, 16> imres2{2.9762783830780870e+02, -1.2028097202919852e+02, 2.8265837203765557e+01, 5.5795755603181973e-01, -4.3525806756942647e+00, 2.4615846625086828e+00, -8.0817621263627215e-01, 1.1438546592087158e-01, 0.0000000000000000e+00, 2.4739764151330637e-01, -9.0634595724225331e-01, 1.7700507509640206e+00, -7.5554463467919764e-01, -9.4917405155340564e+00, 4.4701251488144443e+01, -1.1836380787572048e+02};
    std::array<T, 16> reres3{-2.1919605735188543e+02, -9.5960840979291248e+01, -2.6247738329194586e+01, -2.7378058103703271e+00, 1.5393339343214520e+00, 1.0202733252675829e+00,2.8997624765608049e-01, 2.5475755042412361e-02, 5.5934304774884547e-04, -3.6205278008366759e-02, -2.3537006102627681e-01, -4.0238692508157325e-01, 1.0681429205300328e+00, 9.5538393761653744e+00, 3.5934587414803339e+01, 8.6383536700968776e+01};
    std::array<T, 16> imres3{-1.3958411626024673e+02, -8.6886578512935824e+00, 2.3632376115841012e+01, -1.2354529719447493e+01, 4.0308286393366100e+00, -8.2073931887899532e-01,5.9773558011556975e-02, 1.0169309231131291e-02, 0.0000000000000000e+00, 4.6607480311600599e-02, -3.3645309594598694e-01, 1.4894318344022419e+00, -4.5830124453744201e+00, 9.2272714145788921e+00, -5.4326147358923178e+00, -4.6395096888105925e+01};

    std::vector<kyosu::complex_t<T>> js(6), ys(6);
    for (int k = 0; k < 16; ++k)
    {
      auto c = kyosu::complex(re[k], im[k]);
      kyosu::cyl_bessel_jyn(3, c, js, ys);
//       for(int i=0; i < 2; ++i)
//       {
      int i = 0;
      TTS_RELATIVE_EQUAL(kyosu::cyl_bessel_j0(c), js[0], 1.0e-7) << "i " << i  << " c "<< c << '\n';
      i = 1;
      TTS_RELATIVE_EQUAL(kyosu::cyl_bessel_j1(c), js[1], 1.0e-7) << "i " << i  << " c "<< c << '\n';
      i = 2;
      auto ref2 =  kyosu::complex_t<T>(reres2[k], imres2[k]);
      TTS_RELATIVE_EQUAL(ref2, js[2], 1.0e-7) << "i " << i  << " c "<< c << '\n';
      i = 3;
      auto ref3 =  kyosu::complex_t<T>(reres3[k], imres3[k]);
      TTS_RELATIVE_EQUAL(ref3, js[3], 1.0e-7) << "i " << i  << " c "<< c << '\n';

//     }
    }
  }
};


TTS_CASE_WITH ( "Check kyosu::cyl_bessel_jn over real"
              , kyosu::scalar_real_types
              , tts::generate(tts::randoms(-10,10))
              )
<typename T>(T )
{
  if constexpr(sizeof(T) == 8)
  {
    std::array<T, 16> re{-5.2999999999999998e+00, -4.5999999999999996e+00, -3.8999999999999999e+00, -3.2000000000000002e+00, -2.5000000000000000e+00, -1.7999999999999998e+00, -1.1000000000000005e+00, -4.0000000000000036e-01, 2.9999999999999982e-01, 1.0000000000000000e+00, 1.7000000000000002e+00, 2.3999999999999995e+00, 3.0999999999999988e+00, 3.7999999999999998e+00, 4.4999999999999991e+00, 5.2000000000000002e+00};
    std::array<T, 16> im{8.0000000000000000e+00, -7.0000000000000000e+00, 6.0000000000000000e+00, -5.0000000000000000e+00, 4.0000000000000000e+00, -3.0000000000000000e+00, 2.0000000000000000e+00, -1.0000000000000000e+00, -0.0000000000000000e+00, 1.0000000000000000e+00, -2.0000000000000000e+00, 3.0000000000000000e+00, -4.0000000000000000e+00, 5.0000000000000000e+00, -6.0000000000000000e+00, 7.0000000000000000e+00};
    std::array<T, 16> reres2{-2.9762775424767278e+02, -1.2028088593877092e+02, -2.8266190690561899e+01, 5.5544747986204690e-01, 4.3434904347597794e+00, 2.4402863252057978e+00, 8.0059379319725266e-01, 6.7176889968254105e-01, -1.4480094011452358e+01, -4.7336802053449323e-01, -9.8830057072931921e-01, -1.7988688832372615e+00, -7.6317842152824589e-01,9.4906183603062093e+00, 4.4701463687243219e+01, 1.1836404066466213e+02};
    std::array<T, 16> imres2{-1.3031491164249709e+02, -3.2945558528775152e+01, 3.8720206627664581e+01, -1.8407463166947977e+01, 5.5028557396442608e+00, -7.5377667674934246e-01,-3.1356235386620857e-01, 8.2398784962920835e-01, 0.0000000000000000e+00, 5.7733695758049497e-01, -4.4451806514302838e-01, 2.0980922018840360e+00, -7.1169346878646786e+00, 1.5893162976210826e+01, -1.7203680564977855e+01, -3.7739753070724930e+01};
    std::array<T, 16> reres3{1.3958417197710105e+02, -8.6883096628337686e+00, -2.3631195977314693e+01, -1.2352010359832823e+01, -4.0302717962534498e+00, -8.5196208880386270e-01, -3.3849774094703877e-01, -3.4588704199830058e+00, -1.9077481501430970e+02, 8.6563240968334842e-01, -2.6730571856144153e-01, -1.4969677000121437e+00, -4.5914157362414194e+00, -9.2308592187965992e+00, -5.4336540845736305e+00, 4.6394923953405495e+01};
    std::array<T, 16> imres3{-2.1919616943417924e+02, 9.5961003073477983e+01, -2.6247460558083521e+01, 2.7347064607671414e+00, 1.5534314105179585e+00, -1.0675005055809359e+00, 4.0136093823646224e-01, 1.1898693688647326e+00, 0.0000000000000000e+00, 1.4716089522370916e+00, 2.7277617257286835e-02, -3.5557851239194410e-01, -1.0774854268796867e+00, 9.5546455890845188e+00, -3.5934122187452630e+01, 8.6383214741966171e+01};

    std::vector<kyosu::complex_t<T>> js(6), ys(6);
    for (int k = 0; k < 16; ++k)
    {
      auto c = kyosu::complex(re[k], im[k]);
      kyosu::cyl_bessel_jyn(3, c, js, ys);

      for(int i=0; i <= 3 ; ++i)
      {
        std::cout << "ys[" << i << "] = "<< ys[i] << std::endl;
      }
      int i = 0;
      TTS_RELATIVE_EQUAL(kyosu::cyl_bessel_j0(c), js[0], 1.0e-6) << "i " << i  << " c "<< c << '\n';
      i = 1;
      TTS_RELATIVE_EQUAL(kyosu::cyl_bessel_j1(c), js[1], 1.0e-6) << "i " << i  << " c "<< c << '\n';
      i = 2;
      auto ref2 =  kyosu::complex_t<T>(reres2[k], imres2[k]);
      TTS_RELATIVE_EQUAL(ref2, ys[2], 1.0e-6) << "i " << i  << " c "<< c << '\n';
      i = 3;
      auto ref3 =  kyosu::complex_t<T>(reres3[k], imres3[k]);
      TTS_RELATIVE_EQUAL(ref3, ys[3], 1.0e-6) << "i " << i  << " c "<< c << '\n';

    }
  }
};