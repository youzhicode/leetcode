#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int *result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i=0; i<numsSize-1; i++) {
        for (int j=i+1; j<numsSize; j++) {
            if (nums[i] + nums[j] == target && nums[i] != nums[j]) {
                result[0] = i;
                result[1] = j;
                break;
            }
        }
    }
    return result;
}

int* twoSum2(int* nums, int numsSize, int target, int* returnSize) {
    int i=0; // 定义左边第一个指针
    int j=numsSize - 1; // 定义右边第一个指针
    int step = 1;
    *returnSize = 2;
    int *result = (int*)malloc(sizeof(int) * 2);
    while (i <= j) {
        step = i+1;
        while (step < numsSize) {
            if (nums[step] + nums[i] == target) {
                result[0] = i;
                result[1] = step; 
                return result;
            }
            if (nums[j - step + i] + nums[j] == target) {
                result[0] = j;
                result[1] = j - step + i;
                return result;
            }
            ++step;
        }
        ++i;
        --j;
    }
    return result;
}

int main() 
{

    int numbers[] = {-11,7,3,2,1,7,-10,11,21,3};
    int target = 11;
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int returnSize = 0;

    int *result = twoSum2(numbers, size, target, &returnSize);

    for(int i=0; i<returnSize; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");
    free(result);

    return 0;
}