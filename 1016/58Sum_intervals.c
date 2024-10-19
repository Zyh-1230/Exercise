#include <stdio.h>

int main(int argc, char argv)
{
    int num;
    scanf("%d", &num);//获取用户需要的数组的长度
    
    int* a = (int*)malloc(sizeof(int) * (num+1));//再定义一个数组用于存放原数组中元素的总和
    a[0] = 0;//初始化前缀与数组的第一个元素为0 方便后续建立新数组与前一项的关系
    
    int i;
    for(i=1; i<num+1; ++i)
    {
        int val;//用于存放用户输入的数组元素
        scanf("%d", &val);
        a[i] = a[i-1] + val;
    }
    
    int b, c;
    while(scanf("%d%d", &b, &c) == 2)
    {
        printf("%d", a[c+1]-a[b]);//b+1是因为新数组是从1开始索引的 该区间为[a,b)左闭右开
    }
    
    free(a);
    return 0;
}