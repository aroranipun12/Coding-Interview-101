/*Max profit with at most two transactions =
       MAX {max profit with one transaction and subarray price[0..i] +
            max profit with one transaction and subarray price[i+1..n-1]  }
i varies from 0 to n-1. 
*/
//dono sub array ka profit add krke ans m store krke ans ko update krte jao for every i
//profit for each subarray can be calculated in O(n) 
//koi bhi 2 element m diff is sum of the differences of all elements in between them in input array
//https://www.geeksforgeeks.org/maximum-difference-between-two-elements/