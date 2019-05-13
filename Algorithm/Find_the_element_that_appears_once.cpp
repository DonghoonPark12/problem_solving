#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <set>
#include <AccumulatorClass.h>
using namespace std;

//#define INT_SIZE 32 
//
//int getSingle(int arr[], int n) {
//	// Initialize result 
//	int result = 0;
//	int x, sum;
//	// Iterate through every bit 
//	for (int i = 0; i < INT_SIZE; i++)
//	{
//		// Find sum of set bits at ith position in all  array elements 
//		sum = 0;
//		x = (1 << i);
//		for (int j = 0; j< n; j++) {
//			if (arr[j] & x) sum++;
//		}
//
//		// The bits with sum not multiple of 3, are the  bits of element with single occurrence. 
//		if (sum % 3)
//			result |= x;
//	}
// return result;
//}
//

int getSingle(int arr[], int n) {
	int ones = 0, twos = 0;
	int common_bit_mask;
	int x = 0;
	int not_threes = 0;
	
	for (int i = 0; i< 10; i++)
	{
		x = arr[i];
		twos |= ones & x;
		ones ^= x;
		not_threes = ~(ones & twos);
		ones &= not_threes;
		twos &= not_threes;
	}

	//// Let us take the example of {3, 3, 2, 3} to understand this 
	//for (int i = 0; i < n; i++)
	//{
	//	/* The expression "one & arr[i]" gives the bits that are
	//	there in both 'ones' and new element from arr[].  We
	//	add these bits to 'twos' using bitwise OR

	//	Value of 'twos' will be set as 0, 3, 3, 1 after 1st, 2nd, 3rd and 4th iterations respectively */
	//	twos |= (ones & arr[i]);

	//	/* XOR the new bits with previous 'ones' to get all bits appearing odd number of times

	//	Value of 'ones' will be set as 3, 0, 2, 3 after 1st, 2nd, 3rd and 4th iterations respectively */
	//	ones ^= arr[i];

	//	/* The common bits are those bits which appear third time
	//	So these bits should not be there in both 'ones' and 'twos'.
	//	common_bit_mask contains all these bits as 0, so that the bits can
	//	be removed from 'ones' and 'twos'

	//	Value of 'common_bit_mask' will be set as 00, 00, 01 and 10
	//	after 1st, 2nd, 3rd and 4th iterations respectively */
	//	common_bit_mask = ~(ones & twos);

	//	/* Remove common bits (the bits that appear third time) from 'ones'
	//	Value of 'ones' will be set as 3, 0, 0, 2 after 1st, 2nd, 3rd, 4th iterations respectively */
	//	ones &= common_bit_mask;


	//	/* Remove common bits (the bits that appear third time) from 'twos'
	//	Value of 'twos' will be set as 0, 3, 1, 0 after 1st, 2nd, 3rd, 4th itearations respectively */
	//	twos &= common_bit_mask;

	//	// uncomment this code to see intermediate values 
	//	printf (" %d %d \n", ones, twos); 
	//}
	return ones;
}

int getSingle(int a[], int n) {
	set<int> s(a, a + n);
	
	int arr_sum = accumulate(a, a + n, 0);//sum of array
	int set_sum = accumulate(s.begin(), s.end(), 0);//sum of set
	return (3 * set_sum - arr_sum) / 2;
}
int main()
{
	int arr[] = {3,3,2,3};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("The element with single occurrence is %d ", getSingle(arr, n));
	return 0;
}


