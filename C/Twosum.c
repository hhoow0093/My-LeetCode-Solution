/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

//solusiku
//menggunakan 2 pointer left dan right untuk cek target nomor.
//loop pertama akan dilakukan sebesar array
//index right akan selalu berkurang untuk membandingkan left index pada array
//loop kedua akan berjalan jika left < right, jika solusi ketemu, maka akan menghasilkan solusi index. Jika tidak, maka left akan digeser ke kanan.

#include <stdio.h>
#include <stdlib.h>

int *Twosum(int *nums, int numSize, int target){
    int return_size = 2;
    int *result = (int *)malloc(return_size * sizeof(int));
    int left = 0;
    int right = numSize - 1;
    for(int i = 0; i < numSize; i++){
        while(left < right){
            if(nums[left] + nums[right] == target){
                result[0] = left;
                result[1] = right;
                return result;
            }
            else{
                right--;
            }
        }
        left++;
        right = numSize - 1;
    }

    result[0] = -1;
    result[1] = -1;
    return result;  
}

int main(){
    int size;
    int Maintarget;
    printf("enter array size: ");
    scanf("%d", &size);
    int *array = (int *)malloc(size * sizeof(int));
    for(int i = 0; i <size ; i++ ){
        printf("enter number of index %d of array: ", i);
        scanf("%d", &array[i]);
    }
    
    printf("target: ");
    scanf("%d", &Maintarget);
    int *Mainresult = Twosum(array, size, Maintarget);
    
    if (Mainresult[0] != -1) {
        printf("Index od solution: %d, %d\n", Mainresult[0], Mainresult[1]);
    } else {
        printf("No two sum solution found.\n");
    }
    free(array);
    free(Mainresult);
    return 0;

}

//solusi internet

// int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//     int* result = (int*)malloc(2 * sizeof(int));
//     *returnSize = 2;
    
//     for (int i = 0; i < numsSize; i++) {
//         for (int j = i + 1; j < numsSize; j++) {
//             if (nums[i] + nums[j] == target) {
//                 result[0] = i;
//                 result[1] = j;
//                 return result;
//             }
//         }
//     }
    
//     result[0] = 0;
//     result[1] = 1;
//     return result;
// }
