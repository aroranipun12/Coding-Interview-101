// CPP program to find middle of three distinct 
// numbers 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find the middle of three numbers 
int middleOfThree(int a, int b, int c) 
{ 
	// Compare each three number to find middle 
	// number. Enter only if a > b 
	if (a > b) 
	{ 
		if (b > c) 
			return b; 
		else if (a > c) 
			return c; 
		else
			return a; 
	} 
	else
	{ 
		// Decided a is not greater than b. 
		if (a > c) 
			return a; 
		else if (b > c) 
			return c; 
		else
			return b; 
	} 
} 

// Driver Code 
int main() 
{ 
	int a = 20, b = 30, c = 40; 
	cout << middleOfThree(a, b, c); 
	return 0; 
} 
