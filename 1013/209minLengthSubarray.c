int minSubArrayLen(int target, int* nums, int numsSize) {
    int minLength = INT_MAX;//INT_MAX代表了int类型的所能表示的最大值 以方便后续正确更新数组的长度
    int sum = 0;

    int left = 0;
    int right = 0;
    for(; right<numsSize; ++right)//右边界向右扩展
    {   sum += nums[right];
        while(sum >= target)
        {
            int subLength = right - left + 1;
            minLength = minLength < subLength ? minLength : subLength;//三元条件运算符 condition ? expression1 : expression2; condition是一个布尔表达式 若为真 则表达式的值时expression1 ； 若为假 则表达式的值是expression2
            sum -= nums[left++];//等价于 sum = sum - nums[left]; left++;

        }

        
    }

    return minLength == INT_MAX ? 0 : minLength;
}