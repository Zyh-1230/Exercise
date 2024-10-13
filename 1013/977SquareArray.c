/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;//返回的数组大小必须和原数组大小相同
    int Left = 0;
    int Right = numsSize - 1;

    int* result = (int*)malloc(sizeof(int) * numsSize);//定义返回最终结果的数组
    int index;//index代表索引

    for (index = numsSize-1;index >= 0;--index)//index从新数组的末尾添加元素 题目要求是单调增排列元素
    {
        int lP = nums[Left] * nums[Left];//左指针
        int rP = nums[Right] * nums[Right];//右指针

        if(lP > rP)//考虑数组中有负数 如果该负数的平方大于该正数的平方 则先于它放进新数组
        {
            result[index] = lP;
            Left++;
        }
        else
        {
            result[index] = rP;
            Right--;
        }
    }

    return result;
}
