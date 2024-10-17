#include<stdio.h>
int main()
{
   int n,at[10],bt[10],wt[10],tat[10],ct[10],sum,i,j,k;
   float totaltat=0,totalwt=0;
   int p[10];
   printf("enter the total number of processes:");
   scanf("%d",&n);
   printf("enter the process number\n");
   for(int i=0;i<n;i++)
   {
   	scanf("%d",&p[i]);
   }
    printf("\nEnter The Process Arrival Time & Burst Time\n");
    for(i=0;i<n;i++)
    {        printf("Enter Arrival time of process[%d]:",p[i]);
             scanf("%d",&at[i]);
            printf("Enter Burst time of process[%d]:",p[i]);
             scanf("%d",&bt[i]);
    }
    int temp;
    //sorting of process according to the burst time//
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n-i-1;j++)
    	{
	if(at[j]>at[j+1])
	{
		temp=at[j+1];
		at[j+1]=at[j];
		at[j]=temp;
		temp=p[j+1];
		p[j+1]=p[j];
		p[j]=temp;
	     	
	}
	
       }
    }
    
   //Calculate completion time of processes
   
  sum=at[0];
  for(j=0;j<n;j++)
  {
          sum=sum+bt[j];
          ct[j]=sum;
  }
   //Calculate Turn Around time 
  for(k=0;k<n;k++)
  {
           tat[k]=ct[k]-at[k];
           totaltat=totaltat+tat[k];
  }
     //Calculate Waiting time  
  for(k=0;k<n;k++)
  {
           wt[k]=tat[k]-bt[k];
    totalwt=totalwt+wt[k];
  }

   printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n\n\n");
 for(i=0;i<n;i++)
 {
      printf("\nP%d\t %d\t %d\t %d\t %d\t %d\t\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
} 
    printf("\nAverage TurnaroundTime:%f\n",totaltat/n);
    printf("\nAverage Waiting Time:%f",totalwt/n);
 
    return 0;
}
