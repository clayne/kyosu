#include <kyosu/kyosu.hpp>
#include <eve/wide.hpp>
#include <iostream>

int main()
{
  size_t n = 3;
  using kyosu::cyl_bessel_in;
  std::cout.precision(16);
  std::cout << std::scientific << std::endl;
  std::cout << "1.0             " << " -> " << cyl_bessel_in(n,1.0) << "\n";
  std::cout << "1+0i            " << " -> " << cyl_bessel_in(n,kyosu::complex(1.0, 0.0)) << "\n";
  std::cout << "15.0            " << " -> " << cyl_bessel_in(n,15.0) << "\n";
  std::cout << "15+0i           " << " -> " << cyl_bessel_in(n,kyosu::complex(15.0, 0.0)) << "\n";
  std::cout << "40.0            " << " -> " << cyl_bessel_in(n,40.0) << "\n";
  std::cout << "40+0i           " << " -> " << cyl_bessel_in(n,kyosu::complex(40.0, 0.0)) << "\n";
  std::cout << "60.0            " << " -> " << cyl_bessel_in(n,60.0) << "\n";
  std::cout << "60+0i           " << " -> " << cyl_bessel_in(n,kyosu::complex(60.0, 0.0)) << "\n";

  eve::wide<double, eve::fixed<4>> z(1.0, 15.0, 40.0, 60.0);
  auto zz = kyosu::complex(z);
  std::cout << z  << "\n -> " << cyl_bessel_in(n,z) << "\n";
  std::cout << zz << "\n -> " << kyosu::real(cyl_bessel_in(n,zz)) << "\n";

  std::cout << "1.0                 " << " -> " << cyl_bessel_in(n,1.0) << "\n";
  std::cout << "1.0+36.0i           " << " -> " << cyl_bessel_in(n,kyosu::complex(1.0, 36.0)) << "\n";
  std::cout << "1.0+36.0i+2.0j+1.5k " << " -> " << cyl_bessel_in(n,kyosu::quaternion(1.0, 36.0, 2.0, 1.5)) << "\n";


  eve::wide<double, eve::fixed<4>> z1(1.0, 2.0, 40.0, 0.0),  z2(36.0, 0.5, 0.0, 40.0);
  auto z0 = kyosu::complex(z1, z2);
  std::cout << z0 << " \n-> " << cyl_bessel_in(n,z0) << "\n";
  return 0;
}
