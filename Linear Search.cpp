#include <stdio.h>
int main()
{
    int a[10], s, i, n;
    printf("Enter  number of elements n");
    scanf("%d",&n);
    printf("Enter %d numbers\n", n);
    for (i=0;i<n;i++ )
        scanf("%d",&a[i]);
    printf("Enter the number to search\n");
    scanf("%d",&s);
    for (i=0;i<n;i++ )
    {
        if (a[i]==s)  
        {
            printf("%d is present at %d.\n",s,i+1);
            break;
        }
    }
    if(i==n)
        printf("element not present",s);
    return 0;
}
