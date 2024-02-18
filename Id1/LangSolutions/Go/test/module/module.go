package mylibTest

func Summation(up_bound, multiple int) int{
	if up_bound % multiple ==0{
		result := multiple * (up_bound/multiple-1)*(up_bound/multiple)/2
		return result
	} else {
		result := multiple * (up_bound/multiple+1)*(up_bound/multiple)/2
		return result
	}
}

func Gcd(number1, number2 int) int {
	for number2 !=0{
		number1, number2 = number2, number1%number2
	}
	return number1
}

func Lcm(number1, number2 int) int {
	result := number1*number2/Gcd(number1, number2)
	return result
}

func min(number1, number2 int) int{
	if number1>number2{
		return number2
	}
	return number1
}

func Solve(up_bound, multiple1, multiple2 int) int{
	if multiple1%multiple2==0 || multiple2%multiple1==0{
		multiple := min(multiple1, multiple2)
		return Summation(up_bound, multiple)
	}
	sum1 := Summation(up_bound, multiple1)
	sum2 := Summation(up_bound, multiple2)
	sum1_2 := Summation(up_bound, Lcm(multiple1,multiple2))
	result := sum1+sum2-sum1_2
	return result
}


