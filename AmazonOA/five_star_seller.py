# -*- coding: utf-8 -*-
"""
Created on Sun Apr 25 22:13:23 2021

@author: sadi

Amazon Online Assessment (OA) - Five Star Seller
An arborist that operates a plant store in Brooklyn, NY would like to improve their online sales by improving their ratings.

In order to become a five-star store, they must maintain a certain threshold percentage of five-star ratings. Given their current situation, find the minimum number of additional five-star ratings they must receive to meet the threshold. The overall online store percentage is calculated by taking the sum of percentages of five-star ratings for each product.

Examples
Example 1:
Input:
productCount = 3

productRatings = [[4,4],[1,2],[3,6]] where each entry is [five-star reviews, total reviews]

threshold = 77

Output: 3
Explanation :
We need the sum of the percentages of five-star ratings for each product to add up to the threshold.

The current percentage of five-star ratings for this seller is ((4/4) + (1/2) + (3/6))/3 = 66.66%

If we add a five star review to product #2, their threshold becomes ((4/4) + (2/3) + (3/6))/3 = 72.22%

If we add another five star review to product #2, their threshold becomes ((4/4) + (3/4) + (3/6))/3 = 75%

If we add a five star review to product #3, their threshold becomes ((4/4) + (3/4) + (4/7))/3 = 77.38%

At this point, the 77% threshold is met. The answer is 3, because there is no other way to add less ratings and achieve 77% or more.

Constraints:
There is always at least one product, and the threshold is between 1 and 99 inclusive. All values are positive.
"""

from heapq import heapify, heappop, heappush
from typing import List
class Rating:
    def __init__(self, num, den):
        self.num = num
        self.den = den
    def __float__(self):
        return self.num / self.den
    def __lt__(self, other):
        return self.gain > other.gain
    @property
    def succ(self):
        return Rating(self.num + 1, self.den + 1)
    @property
    def gain(self):
        '''How much do we gain by adding one five star review to this product
        '''
        return float(self.succ) - float(self)
def five_star_reviews(ratings: List[List[int]], threshold: int) -> int:
    # WRITE YOUR BRILLIANT CODE HERE
    num_rats = len(ratings)
    
    # priority queue ordered by gain descending
    rats = [Rating(n, d) for n, d in ratings]
    #print(rats)
    #return 0;
    heapify(rats)
    # how much more do we need to reach threshold
    diff = threshold / 100 - sum(float(r) for r in rats) / num_rats
    # count of five star reviews added
    count = 0
    while diff > 0:
        s = heappop(rats)
        heappush(rats, s.succ)
        diff -= s.gain / num_rats
        count += 1
    return count
if __name__ == '__main__':
    ratings = [[int(x) for x in input().split()] for _ in range(int(input()))]
    threshold = int(input())
    res = five_star_reviews(ratings, threshold)
    print(res)