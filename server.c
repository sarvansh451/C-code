#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#define port 8080
int main()
{
	int sockfd;
       struct sockaddr_in my_addr;
       //socket creation//
       sockfd = socket(PF_INET, SOCK_STREAM, 0); 
       //structure//
       my_addr.sin_family = AF_INET;
       my_addr.sin_port = htons(port); 
       my_addr.sin_addr.s_addr = inet_addr("10.12.110.57");
       memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);  
       bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr);
       //listening to the port//
       int listening=listen(sockfd,2);
       //accepting the connnecction//
       int newsocket=accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
       //array//
       int n;
       printf("enter the size of the array\n");
       scanf("%d",&n);
       int arr[n];
       printf("enter the elements of the array");
       for(int i=0;i<sizeof(arr);i++)
       {
       	scanf("%d",&arr[i]);
	}
       int evensum=0;
       int oddsum=0;
       for(int i=0;i<sizeof(arr);i++)
       {
       	if(arr[i]%2==0)
       	{
       		evensum=evensum+arr[i];
		}
		else
		{
			oddsum=oddsum+arr[i];
		}
	}
	int result[2]={evensum,oddsum};
	
	//sending the array to the client//
       send(newsocket,arr, sizeof(arr),0);
       
       
       close(sockfd);
       close(newsocket);
       return 0;
       
} 
