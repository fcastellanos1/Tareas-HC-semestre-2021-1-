
#include <iostream>
#include <cmath>

double mysin(double x0, int N);
long long int factorial(long long int number); //cambio en el tipo de variable para evitar overflow rapidamente.

int main()
{
  std::cout.setf(std::ios::scientific);
  std::cout.precision(6); //cambio en las cifras significativas para mayor presicion de impresion.
  
  const double x = M_PI/3;
  const double exact = std::sin(x);
  
  for(int NMAX = 1; NMAX <= 20; NMAX++) { //cambio en el NMAX debido a que no se alcanza una precision en NMAX=1000.
    double diff = std::fabs(mysin(x, NMAX) - exact)/exact;
    std::cout << NMAX << "\t" << diff << "\n";
  }
  
  return 0;
}

double mysin(double x0, int N)
{
  double total_value = 0.0;
  double signo;
  for (int ii = 1; ii<= N; ii++){
    signo = std::pow(-1, ii-1);
    total_value +=  signo * ( std::pow(x0 , (2*ii)-1) / factorial((2*ii)-1) );
  }
  return total_value;
}

long long int factorial(long long int number)
{
  if (number>1){
    return number * factorial(number - 1);
  }
  else return 1;
}
