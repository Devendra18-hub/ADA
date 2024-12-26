#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Max 50000
int main()
{
	int i,a[Max],index=0;
	clock_t t1,t2;
	
	
	printf("Enter the elements\n");
	for(i=0;i<Max;i++){
	 a[i]=rand();
 }
	 
   int key=rand();
   t1=clock();
   for( i=0;i<Max;i++)
   {
	   if(a[i]==key)
	   {
		   index=i;
		   printf("%d is found at index %d\n",key,index);
		   break;
	   }
   }
    t2=clock();
   if (index==0)
   printf("%d does not found\n",key);
  
	
	
	float sec=(float)(t2-t1)/CLK_TCK;
	printf("Runtime of program:%f\n",sec);
	
	return 0;
}
