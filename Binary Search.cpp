#include <stdio.h>
int main()
{
int i,l, h,m,n,k,a[50];
printf("Enter number of elements");
scanf("%d",&n);
printf("Enter %d numbers", n);
for(i = 0; i < n; i++)
scanf("%d",&a[i]);
printf("Enter num to find ");
scanf("%d", &k);
l=0;
h=n-1;
m=(l+h)/2;
while (l<=h) {
if(a[m] < k)
l=m+1;
else if(a[m]==k) {
printf("%d found at %d",k,m+1);
break;
}
else
h=m-1;
m=(l+h)/2;
}
if(l>h)
{
	printf("element not found");
}
return 0;
}
