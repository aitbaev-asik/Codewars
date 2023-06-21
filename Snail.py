"""
Snail Sort
Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
For better understanding, please follow the numbers of the next array consecutively:

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]
This image will illustrate things more clearly:

"""

def snail(array):
    result = []
    while array:
        result.extend(array.pop(0))
        
        if array and array[0]:
            for row in array:
                result.append(row.pop())
        
        if array:
            result.extend(array.pop()[::-1])
        
        if array and array[0]:
            for row in array[::-1]:
                result.append(row.pop(0))
    
    return result