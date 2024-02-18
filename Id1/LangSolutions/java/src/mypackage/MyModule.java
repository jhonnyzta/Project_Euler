package mypackage;
/**
 * The library of functions for the callenge 1 of Project Euler
 */
public class MyModule {
    /**
     * Return the sum of all multiples of 'num' less than 'up_bound'.
     * @param up_bound The upper bound for the multiples.
     * @param num The number whose multiples are to be summed.
     * @return The sum of all multiples of 'num' less than 'up_bound'.
     * 
     * <p style="font-family: 'DejaVu Sans', Arial, Helvetica, sans-serif;  font-size: 12px;  font-weight: bold; color: #4E4E4E;">Example:</p>
     * <pre>{@code
     * let up_bound = 120
     * let num = 12
     * let result = summation(up_bound, num)
     * // After calling summation(120,12), result will be 540
     * }</pre>
     */
    public static long summation(long up_bound, long num) {
        long result = num * (up_bound / num * (up_bound/num + 1)) / 2;
        return result;
    }

    /**
     * Find the greatest common divisor of two numbers.
     * @param num1 The first number.
     * @param num2 The second number.
     * @return The greatest common divisor of 'num1' and 'num2'.
     * 
     * <p style="font-family: 'DejaVu Sans', Arial, Helvetica, sans-serif;  font-size: 12px;  font-weight: bold; color: #4E4E4E;">Example:</p>
     * <pre>{@code
     * let num1 = 18
     * let num2 = 39
     * let result = gcd(num1, num2)
     * // After calling gcd(18,39), result will be 3
     * }</pre>
     */
    public static long gcd(long num1, long num2) {
        while (num2 != 0) {
            long temp = num1;
            num1 = num2;
            num2 = temp % num2;
        }
        return num1;
    }
    /**
     * Find the least common multiple of two numbers.
     * @param num1 The first number.
     * @param num2 The second number.
     * @return The least common multiple of 'a' and 'b'.
     * 
     * <p style="font-family: 'DejaVu Sans', Arial, Helvetica, sans-serif;  font-size: 12px;  font-weight: bold; color: #4E4E4E;">Example:</p>
     * <pre>{@code
     * let num1 = 123
     * let num2 = 38
     * let result = lcm(num1, num2)
     * // After calling lcm(123, 38), result will be 4674
     * }</pre>
     */
    public static long lcm(long num1, long num2) {
        long result = num1 * num2 / gcd(num1, num2);
        return result;
    }
    /**
     * Return the sum of the multiples of 'multiple1' and 'multiple2' below 'up_bound'.
     * @param up_bound The upper limit for considering multiples.
     * @param multiple1 The first multiple to consider.
     * @param multiple2 The second multiple to consider.
     * @return The sum of the multiples of 'multiple1' and 'multiple2' that are less than 'up_bound'.
     * 
     * <p style="font-family: 'DejaVu Sans', Arial, Helvetica, sans-serif;  font-size: 12px;  font-weight: bold; color: #4E4E4E;">Example:</p>
     * <pre>{@code
     * let up_bound = 3000
     * let multiple1 = 3
     * let multiple2 = 6
     * let result = solve(up_bound, multiple1, multiple2)
     * // After calling solve(3000, 3, 6), result will be 1498500
     * }</pre>
     */
    public static long solve(long up_bound, long multiple1, long multiple2) {
        //First, it is verified that the multiples entered are not multiples of each other.
        up_bound -= 1;
        if (multiple1 % multiple2 == 0 || multiple2 % multiple1 == 0){
            long multiple = Math.min(multiple1, multiple2);
            long result = summation(up_bound, multiple);
            return result;
        }
        long sum1 = summation(up_bound, multiple1);
        long sum2 = summation(up_bound, multiple2);
        long sum1_2 = summation(up_bound, lcm(multiple1, multiple2));
        return sum1 + sum2 - sum1_2;
    }
}