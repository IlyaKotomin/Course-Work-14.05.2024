
# sum_two_lists Function

## Overview

The `sum_two_lists` function is designed to calculate the sum of two integers represented by linked lists, where each node in the list contains a single digit of the integer.

## Function Signature

```cpp
list_element* sum_two_lists(const list_element* num1, const list_element* num2);
```

- **Input**:
    - `num1`: Pointer to the head of the first linked list representing the first integer.
    - `num2`: Pointer to the head of the second linked list representing the second integer.
- **Output**:
    - Returns a pointer to the head of the resulting linked list representing the sum of the two input integers.

## Explanation

The function traverses both input lists simultaneously, starting from the least significant digit, and performs digit-by-digit addition. It maintains a carry variable to handle any carry-over from addition.

1. **Initialization**: Initializes the result pointer (`result`) to `nullptr`, which will eventually hold the result of the sum.
2. **Variable Declaration**: Declares variables for carry-over (`carry`) and pointers to traverse the input lists (`ptr1` and `ptr2`).
3. **Main Loop**: Enters a loop that continues until both input lists are exhausted and there's no carry-over left.
4. **Digit Sum Calculation**: At each iteration, calculates the sum of digits from the corresponding positions in the input lists along with any carry-over from the previous addition.
5. **Update Carry and Result**: Updates the carry-over for the next iteration and calculates the actual digit to be added to the result list.
6. **Updating Result List**: Adds the calculated digit to the result list.
7. **Return Result**: Returns the pointer to the head of the result list, which represents the sum of the two input lists.

## Example

Input:
- List 1: 1 -> 2 -> 3 (represents the integer 123)
- List 2: 4 -> 5 -> 6 (represents the integer 456)

Output:
- Sum: 5 -> 7 -> 9 (represents the integer 579)