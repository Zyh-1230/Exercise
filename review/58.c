int main(int argc, char argv)
{
    int len;
    scanf("%d", &len);

    int* a = (int*)malloc(sizeof(int) * (len+1));
    a[0] = 0;
    int i;

    for(i=1; i<len+1; ++i)
    {
        int val;
        scanf("%d", &val);
        a[i] = a[i-1] + val;
    }

    int m, n;
    while(scanf("%d %d", &m, &n) == 2)
    {
        printf("%d", a[m+1]-a[n]);
    }

    free(a);
    return 0;
}