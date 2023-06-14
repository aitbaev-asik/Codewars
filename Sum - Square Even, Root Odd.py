"""
DESCRIPTION:
Complete the function that takes a list of numbers (nums), as the only argument to the function. Take each number in the list and square it if it is even, or square root the number if it is odd. Take this new list and return the sum of it, rounded to two decimal places.

The list will never be empty and will only contain values that are greater than or equal to zero.

Good luck!
"""


def sum_square_even_root_odd(nums):
    new = []
    for num in nums:
        if num % 2 ==0:
            new.append(num ** 2)
        else:
            new.append(num ** 0.5) 
    total_sum = sum(new)
    rounded_sum = round(total_sum, 2)
    return rounded_sum