int search_1(int* nums, int numsSize, int target) {
    int i = 0;
    while(target != nums[i] && i < numsSize-1)//i<numsSize-1是为了防止当target在数组中不存在时，++i后i= numsSize，而这样越界访问了数组元素
    {
        ++i;
    }
    if(target == nums[i])
        return i;
    else
        return -1;
}

int search_2(int* nums, int numsSize, int target) //[Left , Right]左闭右闭
{
    int Left = 0;
    int Right = numsSize - 1;
    int Middle;

    while(Left <= Right)
    {
        Middle = ( Left + Right ) / 2;
        
        if(nums[Middle] < target)
            Left = Middle + 1;
        else if(nums[Middle] > target)
            Right = Middle-1;
        else
            return Middle;
    }
    return -1;
}

int search_3(int* nums, int numsSize, int target) //[Left , Right)
{
    int Left = 0;
    int Right = numsSize;
    int Middle;

    while(Left < Right)
    {
        Middle = Left + (Right - Left) / 2;

        if(nums[Middle] < target)
            Left = Middle + 1;
        else if(nums[Middle] > target)
            Right = Middle;
        else
            return Middle;
    }

    return -1;
}