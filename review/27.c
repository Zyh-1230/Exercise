int removeElement(int* nums, int numsSize, int val)
{
    int slow = 0;
    int fast;

    for(fast=0; fast<numsSize; ++fast)
    {
        if(nums[fast] != val)
        {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}