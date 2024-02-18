#include <jni.h>
#include "Mymodule.h"

// Prototipos de funciones
long long summation(long long up_bound, long long num);
long long gcd(long long num1, long long num2);
long long lcm(long long num1, long long num2);
long long minor(long long num1, long long num2);
long long solve(long long up_bound, long long multiple1, long long multiple2);

// Implementación de las funciones
long long summation(long long up_bound, long long num) {
    long long num * (up_bound / num * (up_bound / num + 1)) / 2;
    return result;
}

long long gcd(long long num1, long long num2) {
    while (num2 != 0) {
        long long temp = num1;
        num1 = num2;
        num2 = temp % num2;
    }
    return num1;
}

long long lcm(long long num1, long long num2) {
    return num1 * num2 / gcd(num1, num2);
}

long long minor(long long num1, long long num2) {
    if (num1 > num2) {
        return num2;
    } else {
        return num1;
    }
}

long long solve(long long up_bound, long long multiple1, long long multiple2) {
    up_bound -= 1;
    if (multiple1 % multiple2 == 0 || multiple2 % multiple1 == 0) {
        long long multiple = minor(multiple1, multiple2);
        return summation(up_bound, multiple);
    }
    long long sum1 = summation(up_bound, multiple1);
    long long sum2 = summation(up_bound, multiple2);
    long long sum1_2 = summation(up_bound, lcm(multiple1, multiple2));
    return sum1 + sum2 - sum1_2;
}

JNIEXPORT jlong JNICALL Java_Mymodule_summation(JNIEnv *env, jobject obj, jlong up_bound, jlong num) {
    return summation(up_bound, num);
}

JNIEXPORT jlong JNICALL Java_Mymodule_gcd(JNIEnv *env, jobject obj, jlong num1, jlong num2) {
    return gcd(num1, num2);
}

JNIEXPORT jlong JNICALL Java_Mymodule_lcm(JNIEnv *env, jobject obj, jlong num1, jlong num2) {
    return lcm(num1, num2);
}

JNIEXPORT jlong JNICALL Java_Mymodule_minor(JNIEnv *env, jobject obj, jlong num1, jlong num2) {
    return minor(num1, num2);
}

JNIEXPORT jlong JNICALL Java_Mymodule_solve(JNIEnv *env, jobject obj, jlong up_bound, jlong multiple1, jlong multiple2) {
    return solve(up_bound, multiple1, multiple2);
}
