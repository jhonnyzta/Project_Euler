package main

import (
	"fmt"
	"time"
	"eulertest.com/moduletest/module"
	"os"
	"strconv"
)

func convertir(cadena string) int{
	value, err := strconv.Atoi(cadena)
	if err != nil {
        return 0
    }
	return value
}

func main(){
	args := os.Args
	var up_bound int
	var multiple1 int
	var multiple2 int
	if len(args)==1{
		up_bound = 1000
		multiple1 = 3
		multiple2 = 5
	} else if len(args)==4{
		up_bound = convertir(args[1])
		multiple1 = convertir(args[2])
		multiple2 = convertir(args[3])
		
		if up_bound==0 || multiple1==0 || multiple2==0 {
			fmt.Println("Error al obtener datos")
			return
		}
	} else {
		fmt.Println("Error ome error")
		return
	}
	
	
	numExecutions := 100
	totalTime := time.Duration(0)
	result := mylibTest.Solve(up_bound, multiple1, multiple2)
	for i:=0; i<numExecutions;i++{
		start := time.Now()
		mylibTest.Solve(up_bound, multiple1, multiple2)
		totalTime += time.Since(start)
	}
	averageTime := totalTime / time.Duration(numExecutions)
	timereal := int(averageTime)
	fmt.Println(result)
	fmt.Println(timereal)	
}
