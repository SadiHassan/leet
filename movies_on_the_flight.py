def flightDetails(arr, k):
    k-=30
    arr = sorted(arr)
    left = 0
    right = len(arr)-1
    max_val = 0
    while left<right:
        if arr[left]+arr[right]<=k:
            if max_val < arr[left]+arr[right]:
                max_val = arr[left]+arr[right]
                i = left
                j = right
            left+=1
        else:
            right-=1
    return(arr[i],arr[j])

arr = [90, 85, 75, 60, 120, 150, 125]
k = 250
print(flightDetails(arr,k))