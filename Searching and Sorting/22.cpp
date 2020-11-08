//Use binary search to find the pivoted element
//when a sorted array is rotated , pivot is the largest element
//so pivot has this property , arr[pivot] > arr[pivot+1]
//we need to find such index such as arr[index] > arr[index+1]

// use normal binary search
//if arr[mid] > arr[mid+1] return mid
//if arr[mid] < arr[mid-1] return mid-1
//if arr[mid] <= arr[low] search left
//else search right