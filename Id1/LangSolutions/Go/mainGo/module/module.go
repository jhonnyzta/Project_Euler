package mylib

// Calculate the sum of all multiples of 'multiple' less than 'up_bound'.
// Acept two integer numbers and return the sum of multiples.
// Examples:
// 	sum := summation(10,3)
//	// sum it's 3+6+9=18
func Summation(up_bound, multiple int) int {
	result := multiple * (up_bound/multiple + 1) * (up_bound/multiple) / 2
		return result
}

// Find the greatest common divisor of two numbers.
// Examples:
// 	val := Gcd(3,5)
//	// val it's 1
func Gcd(number1, number2 int) int {
	for number2 != 0 {
		number1, number2 = number2, number1 % number2
	}
	return number1
}

// Find the least common multiple of two numbers.
// Examples:
// 	val := Lcm(3,5)
//	// val it's 15
func Lcm(number1, number2 int) int {
	result := number1 * number2 / Gcd(number1, number2)
	return result
}

// Receives two numbers and returns the smaller number
// Examples:
//	val := min(12,99)
//	// val it's 12
func min(number1, number2 int) int{
	if number1 > number2 {
		return number2
	}
	return number1
}

// Find the sum of the multiples of 'multiple1' and 'multiple2' below 'up_bound'
// Examples:
// 	val := Solve(10,2,7)
//	// val it's 2+4+6+8+7=27
func Solve(up_bound, multiple1, multiple2 int) int {
	up_bound -= 1
	if multiple1 % multiple2 == 0 || multiple2 % multiple1 == 0{
		multiple := min(multiple1, multiple2)
		result := Summation(up_bound, multiple)
		return result
	}
	sum1 := Summation(up_bound, multiple1)
	sum2 := Summation(up_bound, multiple2)
	sum1_2 := Summation(up_bound, Lcm(multiple1, multiple2))
	result := sum1 + sum2 - sum1_2
	return result
}
