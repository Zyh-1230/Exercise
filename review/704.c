int search(int* nums, int numsSize, int target)//[left,right] 假设数列是升序排列
{
    int left = 0;
    int right = numsSize-1;
    int middle;

    while(left<=right)
    {
        middle = (left+right) / 2;
        
        if (nums[middle] > target)
        {
            right = middle - 1;
        }
        else if(nums[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
        return -1;
    }
}

int search(int* nums, int numsSize, int target)//[left,right)
{
    int left = 0;
    int right = numsSize;
    int middle;

    while(left < right)
    {
        middle = (left+right) / 2;

        if(nums[middle] < target)
            left = middle + 1; //写成left++;效率过低
        else if(nums[middle] < target)
            right = middle;
        else
            return middle;
    }
    return -1;
}