#include<stdio.h>

int removeElement_1(int* nums, int numsSize, int val)
{
    int k = 0;
    int i;
    for(i=0; i<numsSize; ++i)
    {
        if(nums[i] != val)
        {
            nums[k] = nums[i];
            ++k;
        }
        
    }
    return k;
}

int removeElement_2(int* nums, int numsSize, int val)
{
    int i;
    int j = 0;
    int* pF = nums;
    int* pS = nums;
    for (i=0; i<numsSize; ++i)
    {
        if(pF[i] != val)
        {
            pS[j] = pF[i];
            ++j;
        }
        
    }
    return j;
}

int removeElement(int* nums, int numsSize, int val){
    int slow = 0;
    for(int fast = 0; fast < numsSize; fast++) {
        //若快指针位置的元素不等于要删除的元素
        if(nums[fast] != val) {
            //将其挪到慢指针指向的位置，慢指针+1
            nums[slow++] = nums[fast];
        }
    }
    //最后慢指针的大小就是新的数组的大小
    return slow;
}