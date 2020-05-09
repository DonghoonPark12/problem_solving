#include <stdio.h> 
#include <stdlib.h>

//int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
//    int idx;
//    *returnSize = (1 << numsSize);
//
//    int** result = (int**)malloc( (*returnSize) * sizeof(int*));
//
//    /* Column */
//    *returnColumnSizes = (int*)calloc( (*returnSize), sizeof(int));
//
//    /* Make (8 by 3) array */
//    for (int i = 0; i < *returnSize; ++i) {
//        result[i] = (int*)malloc(sizeof(int) * numsSize);
//    }
//
//    for (int i = 0; i < *returnSize; ++i) { // 000 ~ 111
//        int tmp = i;
//        int col = 0;
//        //int pos = numsSize - 1; //2
//        int j = 0;
//        while (tmp) {
//            if (tmp & 1)
//                result[i][col++] = nums[j];
//            tmp >>= 1;
//            //pos--;
//            j++;
//        }
//        //(*returnColumnSizes)[i] = idx;
//    }
//    return result;
//}
//
//int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
//    *returnSize = 1 << numsSize;
// 
//    int** rv = malloc(sizeof(*rv) * (*returnSize));
//    *returnColumnSizes = malloc(sizeof(**returnColumnSizes) * (*returnSize));
//
//    for (int i = 0; i < *returnSize; ++i) { //000 ~ 111
//        /* popcount is an x86 instruction which returns the number of 1 bits in a register */
//        /* GCC compiler supports a similar instruction, regardless of platform */
//        (*returnColumnSizes)[i] = __builtin_popcount(i); // Let client know length of array
//
//        rv[i] = malloc( sizeof(*(rv[i])) * (*returnColumnSizes)[i] );
//        
//        int rvi_idx = 0; // Index into newly allocated rv[i] array
//
//        /* Each of the first numsSize bits of `i` is associated with an integer in nums */
//        for (int idx = 0; idx < numsSize; ++idx) { // 0 ~ 2
//
//            if ((1 << idx) & i) {
//                /* If the idx'th bit of `i` is 1, then we add the idx'th num to rv[i] */
//                rv[i][rvi_idx++] = nums[idx];
//            }
//
//        }
//    }
//
//    return rv;
//}

int singleNumber(int* nums, int numsSize) {
    // idea : iterate over all elements in array for every bit, get sum of all 1s, 
    // bits with sum not multiple of 3, are 1's bit in the single occurance element
    // e.g. , 5,5,5,2 - 101 101 101 010 - 313 - answer is 3%3,1%3,3%3 - 010

    int x, res = 0;

    for (int i = 0; i < sizeof(int) * 8; i++) {
        x = 1 << i;
        int sum = 0;
        for (int j = 0; j < numsSize; j++) {
            if (x & nums[j]) sum++;
        }

        if (sum % 3) res = res | x;
    }

    return res;
}

int main() {
    int arr[4] = { 3, 3, 3, 2 };
    printf("%d\n", singleNumber(arr, 4) );

    return 0;
}