
#ifndef MYLIB_H
#define MYLIB_H

/**
  * \brief Return the sum of all multiples of 'num' less than 'up_bound'.
 * \param up_bound The upper bound for the multiples.
 * \param num The number whose multiples are to be summed.
 * \return The sum of all multiples of 'num' less than 'up_bound'.
 * <p> <b> Example </b> </p>
 * \code
 * long long up_bound = 3000;
 * long long num = 13;
 * long long result = summation(up_bound, num);
 * // After calling summation(3000, 13) result will be 345345
 * \endcode

*/
long long summation(long long up_bound, long long num);


long long minor(long long num1, long long num2);

/**
 * \brief Find the greatest common divisor of two numbers.
 * \param num1 The first number.
 * \param num2 The second number.
 * \return The greatest common divisor of 'num1' and 'num2'.
 * <p> <b> Example </b> </p>
 * \code
 * long long num1 = 19;
 * long long num2 = 13;
 * long long result = gcd(num1, num2);
 * // After calling gcd(19,13) result will be 1
 * \endcode
*/
long long gcd(long long num1, long long num2);

/**
 * \brief Find the least common multiple of two numbers.
 * \param num1 The first number.
 * \param num2 The second number.
 * \return The least common multiple of 'a' and 'b'.
 * <p> <b> Example </b> </p>
 * \code
 * long long num1 = 31;
 * long long num2 = 13;
 * long long result = lcm(num1, num2);
 * // After calling lcm(31, 13) result will be 403
 * \endcode
*/
long long lcm(long long num1, long long num2);

/**
 * \brief Return the sum of the multiples of 'multiple1' and 'multiple2' below 'up_bound'.
 * \param up_bound The upper limit for considering multiples.
 * \param multiple1 The first multiple to consider.
 * \param multiple2 The second multiple to consider.
 * \return The sum of the multiples of 'multiple1' and 'multiple2' that are less than 'up_bound'.
 * <p> <b> Example </b> </p>
 * \code
 * long long up_bound = 1500;
 * long long multiple1 = 3;
 * long long multiple2 = 7;
 * long long result = solve(up_bound, multiple1, multiple2);
 * // After calling solve(1500, 3, 7) result will be 481609
 * \endcode
*/
long long solve(long long up_bound, long long multiple1, long long multiple2);

#endif  // MYLIB_H
