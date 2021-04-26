# -*- coding: utf-8 -*-
"""
Created on Sun Apr 25 22:13:23 2021

@author: sadi
"""

from typing import List
def count_smaller(nums: List[int]) -> List[int]:
    smaller_arr = [0] * len(nums)
    
    def merge_sort(nums):
        if len(nums) <= 1:
            return nums
        mid = len(nums) // 2
        left = merge_sort(nums[:mid])
        right = merge_sort(nums[mid:])
        return merge(left, right)
    def merge(left, right):
        print(left)
        print(right)
        print('-------')
        result = []
        l, r = 0, 0
        while l < len(left) or r < len(right):
            if r >= len(right) or (l < len(left) and left[l][1] <= right[r][1]):
                result.append(left[l])
                smaller_arr[left[l][0]] += r   # left[l][0] ---> index; left[l][1] ---> val
                #print(smaller_arr)
                l += 1
            else:
                result.append(right[r])
                r += 1
        return result
    merge_sort(list(enumerate(nums)))
    return smaller_arr

if __name__ == '__main__':
    nums = [int(x) for x in input().split()]
    res = count_smaller(nums)
    print(' '.join(map(str, res)))