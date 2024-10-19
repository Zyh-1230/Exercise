#include <limits.h>

int minSubArrayLen(int target, int* nums, int numsSize)
{
    int left = 0;
    int right = 0;
    int minlength = INT_MAX;
    int sum = 0;

    for(; right<numsSize; ++right)
    {
        sum += nums[right];
        while(sum >= target)
        {
            int sublength = right - left + 1;
            minlength = minlength < sublength ? minlength : sublength;
            sum -= nums[left++];
        }
    }

    return minlength = INT_MAX ? 0 : minlength; 
}