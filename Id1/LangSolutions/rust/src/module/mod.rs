/// The set of functions for the callenge 1 of Project Euler

/// Return the sum of all multiples of 'num' less than 'up_bound'.
/// # Arguments
/// 
/// * `up_bound` - The upper bound for the multiples.
/// * `num` - The number whose multiples are to be summed.
/// # Returns
/// 
/// The sum of all multiples of 'num' less than 'up_bound'.
/// 
/// # Examples
///
/// ```
/// let result = summation(10, 3);
/// assert_eq!(result, 18); // Since 3 + 6 + 9 = 18
/// ```
/// ```
/// let result = summation(250, 19);
/// assert_eq!(result, 1729);
/// ```
fn summation(up_bound: i64, num: i64) -> i64 {
    num * (up_bound / num * (up_bound / num + 1)) / 2
}

/// Find the greatest common divisor of two numbers.
/// # Arguments
/// * `num1` - The first number.
/// * `num2` - The second number.
/// # Returns
/// The greatest common divisor of 'num1' and 'num2'.
/// # Examples
/// ```
/// let result = gcd(5,7);
/// assert_eq!(result,1); // Since 3 and 7 are primes then gcd(5,7)=1
/// ```
/// ```
/// let result = gcd(399, 56);
/// assert_eq!(result,7);
/// ```
fn gcd(mut num1: i64, mut num2: i64) -> i64 {
    while num2 != 0 {
        let temp = num1;
        num1 = num2;
        num2 = temp % num2;
    }
    num1
}

/// Find the least common multiple of two numbers.
/// # Arguments
/// * `num1` The first number.
/// * `num2` The second number.
/// # Returns
/// The least common multiple of 'a' and 'b'.
/// # Examples
/// ```
/// let result = lcm(2,9);
/// assert_eq!(result,18); // Since gcd(2,9)=1 are coprimes then lcm(2,9)=2*9=18
/// ```
/// ```
/// let result = lcm(1245,72);
/// assert_eq!(result, 29880);
/// ```
fn lcm(num1: i64, num2: i64) -> i64 {
    num1 * num2 / gcd(num1, num2)
}

/// Return the sum of the multiples of 'multiple1' and 'multiple2' below 'up_bound'.
/// # Arguments
/// * `up_bound` - The upper limit for considering multiples.
/// * `multiple1` - The first multiple to consider.
/// * `multiple2` - The second multiple to consider.
/// # Returns
/// The sum of the multiples of 'multiple1' and 'multiple2' that are less than 'up_bound'.
/// # Examples
/// ```
/// let result = solve(20,3,7);
/// assert_eq!(result,84); //since 3+6+7+9+12+14+15+18=84
/// ```
/// ```
/// let result = solve(97,3,9);
/// assert_eq!(result,1584);
/// ```
pub fn solve(up_bound: i64, multiple1: i64, multiple2: i64) -> i64 {
    //First, it is verified that the multiples entered are not multiples of each other.
    if multiple1 % multiple2 == 0 || multiple2 % multiple1 == 0 {
        let multiple: i64 = multiple1.min(multiple2);
        summation(up_bound, multiple)   
    } else {
        let sum1: i64 = summation(up_bound, multiple1);
        let sum2: i64 = summation(up_bound, multiple2);
        let sum1_2: i64 = summation(up_bound, lcm(multiple1, multiple2));
        sum1 + sum2 - sum1_2
    }
}
