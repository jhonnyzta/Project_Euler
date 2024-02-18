package main

import (
	"fmt"
	"time"
	"euler.com/modules/module"
)

func main(){
	const up_bound = 1000
	const multiple1 = 3
	const multiple2 = 5
	numExecutions := 100
	totalTime := time.Duration(0)
	result := mylib.Solve(up_bound, multiple1, multiple2)
	for i:=0; i<numExecutions;i++{
		start := time.Now()
		mylib.Solve(up_bound, multiple1, multiple2)
		totalTime += time.Since(start)
	}
	averageTime := totalTime / time.Duration(numExecutions)
	timereal := int(averageTime)
	fmt.Println("Resultado:", result)
	fmt.Println("Tiempo promedio: ", timereal)	
}
