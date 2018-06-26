/*Best Method for LIS(better than DP) length of Longest Increasing Subsequence (LIS)
Cpp practice code
Author- Ritesh Aggarwal
Compexity=O(nLogK)  n=length of array , k=length of LIS
*/

#include<iostream>
using namespace std;

const int inf = 2000000000; // a large value as infinity
int n; // the number of items in the sequence
int Sequence[32]; // the sequence of integers
int L[32]; // L[] as described in the algorithm
int I[32]; // I[] as described in the algorithm
int LisSequence[32]; // for storing the sequence


void takeInput() 
{
	scanf("%d", &n); // how many numbers in the sequence ?
	for( int i = 0; i < n; i++ ) // take the sequence
		scanf("%d", &Sequence[i]);
}

// which runs the NlogK LIS algorithm
int LisNlogK() 
{ 
	int i; // auxilary variable for iteration
	for( i = 0; i < n; i++ )
		L[i] = 1;
	I[0] = -inf; // I[0] = -infinite
	for( i = 1; i <= n; i++ ) // observe that i <= n are given
		I[i] = inf; // I[1 to n] = infinite
	int LisLength = 0; // keeps the maximum position where a data is inserted
	for( i = 0; i < n; i++ ) 
	{ 	// iterate left to right
		int low, high, mid; // variables to perform binary search
		low = 0; // minimum position where we to put data in I[]
		high = LisLength; // the maximum position
		while( low <= high ) 
		{ // binary search to find the correct position
			mid = ( low + high ) / 2;
			if( I[mid] < Sequence[i] )
				low = mid + 1;
			else
				high = mid - 1;
		}
		// observe the binary search carefully, when the binary search ends
		// low > high and we put our item in I[low]
		I[low] = Sequence[i];
		L[i]=low;
		if( LisLength < low ) // LisLength contains the maximum position
		LisLength = low;
	}
	return LisLength; // return the result
}

// finds a valid sequence
void findSequence( int maxLength ) 
{	
	int i, j; // variable used for iteration
	// at first find the position of the item whose L[] is maximum
	i = 0;
	for( j = 1; j < n; j++ )
	{
		if( L[j] > L[i] )
		i = j;
	}
	// initialize the position in LisSequence where the items can be added.
	// observe that the data are saving from right to left!
	int top = L[i] - 1;
	// insert the item in i-th position to LisSequence
	LisSequence[top] = Sequence[i];
	top--; // is decreasing such that a new item can be added in a new place
	// now find the other valid numbers to form the sequence
	for( j = i - 1; j >= 0; j-- ) 
	{
		if( Sequence[j] < Sequence[i] && L[j] == L[i] - 1 )
		{
			// we have found a valid item so, we will save it
			i = j; // as in our algorithm
			LisSequence[top] = Sequence[i]; // stored
			top--; // decreased for new items
		}
	}
	// so, we have got the sequence, now we want to print it
	printf("LIS is");
	for( i = 0; i < maxLength; i++ ) 
	{
		printf(" %d", LisSequence[i]);
	}
	puts("");
}


//Driver
int main() 
{
	takeInput();
	int result = LisNlogK();
	printf("The LIS length is %d\n", result);
	findSequence(result);
	return 0;
}
//ReContrustion is same in O(n)
