# def quicksort(arr):
# 	if len(arr) <= 1:
# 		return arr
# 	pivot = arr[len(arr) // 2]
# 	left = [x for x in arr if x < pivot]
# 	mid = [x for x in arr if x == pivot]
# 	right = [x for x in arr if x > pivot]
# 	return quicksort(left) + mid + quicksort(right)

def partition(arr, start, end):
    pi = i = start
    while i < end:
        if arr[i] <= arr[end]:
            arr[pi], arr[i] = arr[i], arr[pi]
            pi += 1
        i += 1
    arr[pi], arr[end] = arr[end], arr[pi]
    return pi

def _quicksort(arr, start, end):
    if start >= end:
        return
    p = partition(arr, start, end)
    _quicksort(arr, start, p-1)
    _quicksort(arr, p+1, end)
    
def quicksort_(arr):
    _quicksort(arr, 0, len(arr)-1)

a=[9, -3, 5, 2, 6, 8, -6, 1, 3]
quicksort_(a)
print(a)