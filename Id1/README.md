# Project Euler Id1: Multiples of 3 or 5
#### <p align="right">by: Effe Zapata</p>

### Statement

If we list all natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all multiples of 3 or 5 below 1000.

### Brute force

As an initial step we can observe the result obtained if we carry out the challenge by brute force, for this here is the code used in Python and the result in different languages.

#### Code: Brute force

```python
def brute() -> int:
    accumulator = 0
    for i in range(1, 1000):
        if i % 3 == 0 or i % 5 == 0:
            accumulator += i
    return accumulator

```

#### Time result: Brute force

The results obtained in the different programming languages ​​are reported below. It should be noted that the measured time corresponds to the average of 100 executions and is reported in nanoseconds.

<div  align="center">

| |Language | Time (ns) |
|:-:|:--|:--: | 
|![go](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/8e4f4251-2d53-4c3b-bdab-2665577f1cf4) |Go | 848|
|![julia](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/64449037-acae-4f72-a49a-d4b587b1b638)  |Julia |8579 |
|![cpp](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/168fd9cb-5554-441b-9d17-71642b3ac956)|C++ | 9946 |
|![rust](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/38212ef8-b357-4ded-b852-dd5530a2b3d3)  |Rust| 53483 |
|![java](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/a6f44277-4820-4a11-b6d4-8567f129b2b0) |Java | 68987 |
|![python](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/ba32a2c1-8535-4d50-85ac-8e7e96a3a6aa) |Python |240346|


</div>



### Mathematical method

> ⚠️ **Remember** x,y &#x2208; &#8484;&#x207A; and the expresion &#x23A3; &#x2022; &#x23A6; it's the floor function.

If we need to add all the numbers that are multiples of an integer x less than M, then we have the following:

$$ x+2x+3x+4x+.... m \cdot x$$

where $m= \lfloor \frac{M-1}{x} \rfloor$, then we have:

$$ x \cdot (1+2+3+ \cdots+m) = x\cdot \sum_{i=1}^{m} {i} = x \left(\frac{m(m+1)}{2}\right)$$

But we need to add all the numbers that are multiples of two integers x,y less than M, we cannot add directly $x \cdot \sum {i}$ and $y \cdot \sum {j}$ because there can be numbers that are both multiples of $x$ and $y$, that is, the multiples of $z=gcd(x,y)$ are being added twice. So it is necessary to subtract the multiples of z less than M. Let S be the sum of the multiples of $x$ and $y$ that are less than M, then:

$$ S = x \cdot \sum_{i=1}^{m}{i}+y \cdot \sum_{j=1}^{n}{j}-z\sum_{k=i}^{r}{k}$$

Where we have $m= \lfloor \frac{M-1}{x} \rfloor$, $n= \lfloor \frac{M-1}{y} \rfloor$ and $r= \lfloor \frac{M-1}{z} \rfloor$, therefore:

$$\begin{equation} S= x \cdot \frac{n(n+1)}{2}+y\frac{m(m+1)}{2}-z\frac{r(r+1)}{2} \end{equation}$$


#### Code

Below is the python code of the functions used. For more information, go to the folder of the programming language of interest.

```python
"""The library of functions for the callenge 1 of Project Euler"""

def summation(up_bound :int, multiple: int) -> int:
    result = multiple * (up_bound//multiple) * (up_bound//multiple + 1) // 2
    return result

def gcd(number1: int, number2: int) -> int:
    while number2 != 0:
        number1, number2 = number2, number1 % number2
    return number1

def lcm(number1: int, number2: int) -> int:
    result = number1 * number2 // gcd(number1, number2)
    return result

def solve(up_bound: int, multiple1: int, multiple2: int) -> int:
    up_bound -= 1
    if multiple1 % multiple2 == 0 or multiple2 % multiple1 == 0:
        multiple = min(multiple1, multiple2)
        return summation(up_bound, multiple)
    sum1 = summation(up_bound, multiple1)
    sum2 = summation(up_bound, multiple2)
    sum1_2 = summation(up_bound, lcm(multiple1, multiple2))
    result = sum1 + sum2 - sum1_2
    return result

```
#### Results

Once the previous method was applied in the different programming languages, the following time results were obtained. In the third box, the percentage of optimization achieved comparing the brute force method vs mathematical method is reported.

<div align="center">

| |Language | Time (ns) | vs brute |
|:-:|:--|:--: | :--: |
|![go](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/8e4f4251-2d53-4c3b-bdab-2665577f1cf4) |Go | 291| 65.68% |
|![julia](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/64449037-acae-4f72-a49a-d4b587b1b638)  |Julia |202 | 97.64%|
|![cpp](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/168fd9cb-5554-441b-9d17-71642b3ac956)|C++ | 275 | 97.23% |
|![rust](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/38212ef8-b357-4ded-b852-dd5530a2b3d3)  |Rust| 512 | 99.04% |
|![java](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/a6f44277-4820-4a11-b6d4-8567f129b2b0) |Java | 7994 | 88.41% |
|![python](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/ba32a2c1-8535-4d50-85ac-8e7e96a3a6aa) |Python | 4094| 98.30% |

</div>

> ⚠️ **Remember** To measure optimization, the following equation is used:

$$ optimization = \frac{\left( timeBruteForce - timeMathematical \right)}{timeBruteForce} \times 100 \% $$

### Extra tests

Now, to gain a better understanding of the functioning of each script, we evaluate them using the following sequence of tests.

<div align="center">

|Variable | Test1 |Test2 |Test3 |Test4 |Test5 |Test6 |
|:--|:--:|:--:|:--:|:--:|:--:|:--:|
|Up_bound| 1000 | 2000 | 5000 | 9000 | 10000 | 20000 | 
|Multiple1| 3 | 3 | 5 | 7 | 13 | 15 | 
|Multiple2| 5 | 6 | 7 | 19 | 19 | 23 | 

</div>

The total time taken by each language to perform the entire test sequence is reported below.

<div align="center">

|  |Language | Time (ns)| Note |
|:----:|:--- | :---: | :---:|
| ![julia](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/64449037-acae-4f72-a49a-d4b587b1b638) | Julia| 1157 | &#129395; | 
| ![cpp](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/168fd9cb-5554-441b-9d17-71642b3ac956) | C++| 1553 | &#129325; | 
| ![go](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/8e4f4251-2d53-4c3b-bdab-2665577f1cf4) | Go| 1641 | &#129299; | 
| ![rust](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/38212ef8-b357-4ded-b852-dd5530a2b3d3) | Rust| 3266 | &#128526; | 
| ![python](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/ba32a2c1-8535-4d50-85ac-8e7e96a3a6aa) | Python| 22404 | &#128561; | 
| ![java](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/a6f44277-4820-4a11-b6d4-8567f129b2b0) | Java| 30764 | &#129398; | 

</div>

On the other hand, there is also the report obtained for the Java and Python languages ​​using modules in C, and the optimization achieved with this method vs the pure language is also reported.

<div align="center">

|  |Language | Time (ns)| Note |Optimization|
|:----:|:--- | :---: | :---:|:--:|
| ![javac](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/ea322cef-dde0-4acc-9747-e5ff1e8e0426) | Java+C| 3868 | &#129400; | 87.43% |
| ![pythonc](https://github.com/jhonnyzta/ProjectEuler/assets/70600594/15fdc43d-d714-4392-86f1-6cb66caacd0d) | Python+C| 6384 | &#129400; | 71.51% |

</div>

In the following graph, the x-axis represents the number of the test conducted, and the y-axis represents the cumulative time. This means that for the third test, it displays the total time taken to perform tests 1, 2, and 3.

<p align="center">
<img src="https://github.com/jhonnyzta/ProjectEuler/assets/70600594/8a5a7419-cf16-49e0-a9e8-406c12492530" alt="Graphic 1" width="400" height="300">
</p>

To observe in greater detail, we have removed the results of Python and Java from the list, resulting in the following graph.


<p align="center">
<img src="https://github.com/jhonnyzta/ProjectEuler/assets/70600594/ceff4234-ba31-4be5-b65d-c19132037d90" alt="Graphic 2" width="400" height="300">
</p>

