/*
Brief Description:
Create a program using threads to calculate average, minimum and maximum in the given array of size 'n'
*/

/*test cases:
Test Case 1:
4
1 2 3 4

Output:
the maximum number is 4 
the minimum number is 1 
the average of  numbers is 2.000000 

Test Case 2:
6
-11 20  3 49 0 1

Output:
the maximum number is 49 
the minimum number is -11 
the average of  numbers is 10.000000 
*/
#include<stdio.h>
#include<pthread.h>
using namespace std;
int maximum,minimum;
float average;
 int arr[100];
 int n;
void *print(void *args)
{
printf("the maximum number is %d \n",maximum);	
printf("the minimum number is %d \n",minimum);
printf("the average of  numbers is %f ",average);
}

void  *avg(void *args)
{
int sum=0;
for(int i=0;i<n;i++)
{
sum = sum+arr[i];	
}
average = sum/n;
}

void *min(void *args)
{
minimum  = arr[0];	
}

void *max(void *args)
{
for(int i=0;i<n-1;i++)
{
for(int j=i+1;j<n;j++)
{
if(arr[i]>arr[j])
{
int temp = arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
}
maximum = arr[n-1];
}

int main() 
{
printf("enter the size of array\n");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);	
}

pthread_t parent;
pthread_t one ,two, three;
pthread_create(&one,NULL,max,(void*)NULL);
pthread_join(one,NULL);
pthread_create(&two,NULL,min,(void*)NULL);
pthread_join(two,NULL);
pthread_create(&three,NULL,avg,(void*)NULL);
pthread_join(three,NULL);
pthread_create(&parent,NULL,print,(void*)NULL);
pthread_join(parent,NULL);

}
