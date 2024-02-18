#include "../include/mylib.h"

long long summation(long long up_bound, long long num) {
    long long result = num * (up_bound / num* (up_bound/num + 1)) / 2;
    return result;
};

long long gcd(long long num1, long long num2) {
    while (num2!=0){
        long long temp = num1;
        num1 = num2;
        num2 = temp % num2;
    }
    return num1;
};

long long lcm(long long num1, long long num2) {
    return num1 * num2 / gcd(num1, num2);
};

long long minor(long long num1, long long num2) {
    if (num1 > num2){
        return num2;
    } else {
        return num1;
    }
}

long long solve(long long up_bound, long long multiple1, long long multiple2) {
    //First, it is verified that the multiples entered are not multiples of each other.
    up_bound -= 1;
    if (multiple1 % multiple2 == 0 || multiple2 % multiple1 == 0){
        long long multiple = minor(multiple1, multiple2);
        return summation(up_bound, multiple);
    }
    long long sum1 = summation(up_bound, multiple1);
    long long sum2 = summation(up_bound, multiple2);
    long long sum1_2 = summation(up_bound, lcm(multiple1, multiple2));
    return sum1 + sum2 - sum1_2;
};