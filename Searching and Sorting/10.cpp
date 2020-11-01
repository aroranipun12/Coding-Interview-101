//step 1 -> sort the array (O(nlogn))
//step 2 -> for each arr[i] binary search for target - array[i] (O(nlogn))

//overall time complexity is O(nlogn)

//other method is to use hash array(hashmap)
//step 1-> insert elements into the hash as keys
//step 2-> iterate over the hash and use hash.find(target + *itr)
