
# Bitnine Coding Test 






## Installation

Check if gcc is installed

```bash
  gcc --version
```
If gcc is not available, install gcc with following command

```bash
sudo apt install gcc
```

## Compilation

Comiple question_1 and question_2 with following commands

```bash
gcc -o q1 question_1.c
```

```bash
gcc -o q2 question_2.c
```

## Execution
After succesful Compilation, following command can be used to run executable:

```bash
./q1
```
```bash
./q2
```

## Question-1

For the question 1, I have modified the Node struct which takes `value`,`Node * num1`, and `Node* num2` where nested nodes are for constant. To implement dynamic programming, I have incorporated pointer to a function which invokes the respective function based on the entered enum `TypeTage`.


## Question-2

For the question 2, I have implemented following recurrence appraoches:\
1)Recursive appraoch.\
2)Memoization appraoch.\
3)Tabulation appraoch.

### 1)Recursive Appraoch

#### Advantages:
* Easier to implement.
* The algorithm is readible and simple.

#### Disadvantages:
* Redundant calculations are required.
* It may cause stack overflow for higher number of `n` or lager compute time(time complexity).
* End conditions should be met properly and tested thoroughly.

### 2)Memoization Appraoch

#### Advantages:
* Similar to Recursive appraoch but stores the results of sub problem in array/hash.
* Data is cached for `n` such that the result less than `n` can be directly fetched without calculations.
* Improved performance compared to Recursive Appraoch.

#### Disadvantages:
* Requires a memory to store the cached data which may increase over time or the values stored in that cache(higher space complexity).
* It can result in to Memory Allocation problem if the value of `n` is higher hence it is recommended to be used with relatively smaller value of `n`.

### 3)Tabulation Appraoch

#### Advantages:
* It has better compute time as this approach does not include Recursion. It first calculates the smallest possible first and then reaches upto `n`.
* It can be used for values that have a higher value of `n`.

#### Disadvantages:
*  Not suitable for complex recursive problems which have have underlying conditions that are be solved.





## Authors

- [@hussainnaqvee](https://www.github.com/hussainnaqvee)

