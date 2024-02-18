package main

import (
	"fmt"
	"time"
)

func brute() int {
	accumulator := 0
	for i := 1; i < 1000; i++{
		if i % 3 == 0 || i % 5 == 0 {
			accumulator += i
		}
	}
	return accumulator
}

func main(){
	numExecutions := 100
	totalTime := time.Duration(0)
	result := brute()

	for i := 0; i < numExecutions; i++{
		start := time.Now()
		brute()
		totalTime += time.Since(start)
	}

	averageTime := totalTime / time.Duration(numExecutions)
	timereal := int(averageTime)
	
	fmt.Println(result)
	fmt.Println(timereal)
}