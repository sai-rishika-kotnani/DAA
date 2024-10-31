#include <stdio.h>
#include<bits/stdc++.h>
int main()
{
	int a[50],i,n,f,s;
	printf("enter number of elements");
	scanf("%d", &n);
	printf("\nenter numbers in array", n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
    }
	 f=s= INT_MIN;
	for (i=0; i <n;i++)
	{
		if(a[i]>f)
		{
			s=f;
			f=a[i];
		}
		else if(a[i]>s&&a[i]<f)
		{
			s=a[i];
		}	
	}
	printf("\nsecond largest element =  %d", s);
	return 0;
}
