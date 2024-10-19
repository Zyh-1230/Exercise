/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;

    int left = 0;
    int right = numsSize-1;
    int* result = (int*)malloc(sizeof(int) * numsSize);
    int index = numsSize - 1;

    for(; index>0; --index)
    {
        int pX = nums[left] * nums[left];
        int pY= nums[right] * nums[right];
        if(pX > pY)
        { 
            result[index] = pX;
            left++;
        }
        else
        {
            result[index] = pY;
            right--;
        }
    }
    return result;
}