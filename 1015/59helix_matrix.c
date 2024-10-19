/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    //初始化返回的结果数组的大小
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    //初始化返回结果数组ans
    int** ans = (int*)malloc(sizeof(int*) * n);
    int i;
    for(i = 0; i < n; ++i)
    {
        ans[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    //设置每次循环的起始位置
    int startX = 0;
    int startY = 0;
    //设置二维数组的中间值 若n为奇数 则最后需要在中间添加元素
    int mid = n/2;
    int loop = n/2;//需要转的圈数
    int offset = 1;//偏移数
    int count = 1;//当前要添加的元素

    while(loop)
    {
        int i = startX;
        int j = startY;
        
        for(; j<startY+n-offset; ++j)//从左上至右上
        {
            ans[startX][j] = count++;
        }

        for(; i<startX+n-offset; ++i)//从右上至右下
        {
            ans[startY][i] = count++;
        }

        for(; j>startY; --j)//从右下至左下
        {
            ans[i][j] = count++;
        }

        for(; i>startX; --i)//左下至左上
        {
            ans[i][j] = count++;
        }
        //偏移值每次加2
        offset += 2;
        startX++;
        startY++;
        loop--;
    }

    if(n%2)
    {
        ans[mid][mid] = count;
    }

    return ans;
}