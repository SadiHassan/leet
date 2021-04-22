'''
A warehouse has one loading dock that workers use to load and unload goods.

Warehouse workers carrying the goods arrive at the loading dock at different times. They form two queues, a "loading" queue and an "unloading" queue. Within each queue, the workers are ordered by the time they arrive at the dock.

The arrival time (in minutes) array stores the minute the worker arrives at the loading dock. The direction array stores whether the worker is "loading" or "unloading", 
a value of 
0 ---> loading and 
1 ---> unloading. 

Loading/unloading takes 1 minute.

When a worker arrives at the loading dock, if no other worker is at the dock at the same time, then the worker can use the dock.

If a "loading" worker and an "unloading" worker arrive at the dock at the same time, then we decide who can use the dock with these rules:

if the loading dock was not in use in the previous minute, then the unloading worker can use the dock.
if the loading dock was just used by another unloading worker, then the unloading worker can use the dock.
if the loading dock was just used by another loading worker, then the loading worker can use the dock.
Return an array of the time (in minute) each worker uses the dock.

Examples
Example 1:
Input:
time = [0, 0, 1, 6] direction = [0, 1, 1, 0]

Output:
[2, 0, 1, 6]

Explanation:
At time 0, worker 0 and 1 want to use the dock. Worker 0 wants to load and worker 1 wants to unload. The dock was not used in the previous minute, so worker 1 unload first.
At time 1, workers 0 and 2 want to use the rock. Worker 2 wants to unload, and at the previous minute the dock was used to unload, so worker 2 uses the dock.
At time 2, worker 0 is the only worker at the dock, so he uses the dock.
At time 6, worker 3 arrives at the empty dock and uses the dock.
We return [2, 0, 1, 6].
'''

from typing import List
from collections import deque

def getTimes(numCustomers: int, arrTime: List[int], direction: List[int]) -> List[int]:
    
    load_queue = deque() # customers in the enter queue
    unload_queue = deque()  # customers in the exit queue
    cur_time = -1
    last_used_type = 'UNLOAD'
    
    for i in range(numCustomers):
        if direction[i] == 0:
            load_queue.append((arrTime[i], i)) # push (arrival time, custom id) into the queue
        else:
            unload_queue.append((arrTime[i], i))
    
    ans = [-1] * numCustomers
    
    while load_queue and unload_queue:
        if load_queue[0][0] <= cur_time and unload_queue[0][0] <= cur_time:  # both customers are at the turnstile
            if cur_time == -1 or last_used_type == 'UNLOAD':   # prev sec not used or last used as exit
                cur_queue = unload_queue
            else:
                cur_queue = load_queue
        elif load_queue[0][0] < unload_queue[0][0]: # only customer from enter queue at turnstile
            cur_queue = load_queue
        else: # only customer from exit queue at turnstile
            # when both arrive at the same time, OR unload arrives before load
            cur_queue = unload_queue
        time, i = cur_queue.popleft()
        if cur_queue == load_queue:
            last_used_type = 'LOAD'
        else:
            last_used_type = 'UNLOAD'
        cur_time = max(time, cur_time)
        ans[i] = cur_time
        cur_time += 1
    
    remaining_queue = load_queue if load_queue else unload_queue
    
    while remaining_queue:
        time,  i = remaining_queue.popleft()
        cur_time = max(time, cur_time)
        ans[i] = cur_time
        cur_time += 1
    
    return ans

if __name__ == "__main__":
    numCustomers  = int(input())
    arrTime = [int(y) for y in input().split()]
    direction = [int(z) for z in input().split()]
    res = getTimes(numCustomers, arrTime, direction)
    print(' '.join(str(e) for e in res))