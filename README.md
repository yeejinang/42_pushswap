# 42_push_swap

In this project, we are required to sort numbers input by user. Only two stacks (first in last out) and operations (push, swap, rotate, reverse rotate) are allowed. Our goal is to sort the numbers by minimal moves.

## Algorithms
1. The input numbers were stored in a circular doubly linked list
2. Used quicksort as sorting algorithm (divide and conquer)
3. In quicksort, I used median as the pivot, smaller half move to Stack B and larger half stay in Stack A
4. Keep dividing till the size <= 3
5. When the size <= 3, I sorted both stack by manual sorting way (why 3? Because by comparing all the operations, it ables to compare 3 numbers at once).
6. Push it back to Stack A and repeat it for Stack B

<img src="https://user-images.githubusercontent.com/81152890/143981126-02b4184d-0ecc-4090-9688-aac03b0db4a0.png" height="70%" width="70%">

## Instructions
### Push_Swap

