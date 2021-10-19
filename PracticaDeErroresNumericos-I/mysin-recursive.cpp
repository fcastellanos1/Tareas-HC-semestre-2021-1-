// calcular el sin(x = pi/3), usando la expansion matematica
// sin(x, N) = \sum_{n=1}^{N} (-1)^{n-1} x^{2n-1}/(2n-1)!

#include <iostream>
#include <cmath>

double mysin(double x0, int N); // declaration

int main()
{
    std::cout.setf(std::ios::scientific);
    std::cout.precision(6);

    const double x = M_PI/3;
    const double exact = std::sin(x);

    for(int NMAX = 1; NMAX <= 15; NMAX++) { //NMAX pequeño porque la precisión máxima se alcanza muy rápido, y no cambia ni hace overflow para NMAX más grandes.
        double diff = std::fabs(mysin(x, NMAX) - exact)/exact;
        std::cout << NMAX << "\t" << diff << "\n";
    }

    return 0;
}

double mysin(double x0, int N) // implementation
{
  double total_value = x0;
  double moment_value = x0;
  for(int ii=2; ii<=N; ii++){
    moment_value *= ( - std::pow(x0 , 2) ) / ( (2*ii-1)*(2*ii-2) );
    total_value += moment_value;
  }
  return total_value;
}
