#include <iostream>
using namespace std;

int factorial (int n){
  if (n == 0){
    return 1;
} else {
    return n*factorial(n-1); //This is an example of recursion, and must be implemented since the formula for the n factorial of any number
  }                          // requires the n-1 factorial of given number
}

long double euler_calc (long double prec)
{
  long double euler_sum = 0.0; //It's better to initialize this variable since we shouldn't asssume it will start at 0 by default
  long double prev_sum;        // Sometimes that might work but other times it could return junk memory
  int n = 0;

  do {

    prev_sum = euler_sum;
    euler_sum = euler_sum + 1.0/ (factorial(n)); // The "1.0" here is VERY important, otherwise it won´t compile correctly.
    n = n+1;                                    // A simple "1" won´t work because C++ will stupidly convert our long double variable into an int one, which we don´t want

  } while (euler_sum - prev_sum > prec);

  return euler_sum;
}

int main(){

long double precision;

cout << "Please input the value of precision:" << endl;
cin >> precision;

cout << "Result is: " << euler_calc(precision);
}
