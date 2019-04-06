#include<stdio.h>
#include<unistd.h>
struct resource
{
	int pen;
	int paper;
	int q_paper;
	int allot_id;

};
struct resource_count{
	
	int pen_count ;
	int paper_count ;
	int q_paper_count ;
}; 

struct resource_count c[3];

void allotment(struct resource a)
{
	if(a.allot_id == 0)
	{
		a.pen=1;
	}
	else if(a.allot_id == 1)
	{
		a.paper=1;
	}
	else if(a.allot_id == 2)
	{
		a.q_paper=1;
	}
	
}
int main()
{
	struct resource s[3];
	int i,j,count=0;
	int p[20],bt[20], su[20], wt[20],tat[20], k, n, temp;
	float wtavg, tatavg;
	printf("************************we have 1 teacher process and 3 student process******************************\n");
	printf("\t\n");
	for(i=0;i<4;i++)
	{
		p[i]=1;
		printf("enter the burst time for %d process:",i);
		scanf("%d",&bt[i]);
		if(i==0)
		{
			printf("teacher process burst time is %d \n",bt[i]);
		}
		else
		{
			printf("student %d process burst time is %d\n ",i,bt[i]);
		}
	}
	for(i=0;i<3;i++)
	{
		s[i].allot_id=i;
		allotment(s[i]);
	}
		printf("\nResources alloted to students are:");
	for(i=0;i<3;i++)
	{
		if(s[i].pen == 1)
		printf("\nResources alloted to student %d are:pen ",i+1);
		
		if(s[i].paper==1)
		printf("\nResources alloted to student %d are:paper ",i);
		
		if(s[i].q_paper == 1)
		printf("\nResources alloted to student %d are:question paper ",i+1);
	}
		while(count != 3)
		{
			for(i=0;i<3;i++)
			{
				if(i=0)
				{
					c[i].paper_count=1;
					c[i].pen_count=1;
					for(j=0;j<3;j++)
					{
						if(s[j].q_paper==1)
						{
						printf("\nStudent %d has completed his job !",j+1);
						count++;
						}
					}
				}
			if(i=1)
			{
				c[i].q_paper_count=1;
				c[i].pen_count=1;
				for(j=0;j<3;j++)
				{
					if(s[j].paper==1)
					{
						printf("\nStudent %d has completed his job !",j+1);
						count++;
					}
				}
			}
		
			if(i=2)
			{
				c[i].paper_count=1;
				c[i].q_paper_count=1;
				for(j=0;j<3;j++)
				{
					if(s[j].pen==1)
					{
						printf("\nStudent %d has completed his job !",j+1);
						count++;
					}
				}
			}
	}	}	
	for(i=0;i<4;i++)
	{
		for(k=i+1;k<4;k++)
		{
			if(su[i] > su[k])
			{
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
				
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;
				
				temp=su[i];
				su[i]=su[k];
				su[k]=temp;
			}
		}
	}
	wtavg = wt[0] = 0;
	tatavg = tat[0] = bt[0];
	for(i=1;i<n;i++)
	{
		wt[i] = wt[i-1] + bt[i-1];
		tat[i] = tat[i-1] + bt[i];
		wtavg = wtavg + wt[i];
		tatavg = tatavg + tat[i];
	}
	printf("\nPROCESS\t\t   BURST TIME\t\t\tWAITING TIME\t\t TURNAROUND TIME");
	
	for(i=0;i<4;i++)
	{
		printf("\n%d \t\t\t %d \t\t %d \t\t\t %d \t\t ",i,bt[i],wt[i],tat[i]);
	}

	printf("\nAverage Waiting Time is --- %f",wtavg/n);
	printf("\nAverage Turnaround Time is --- %f",tatavg/n);

	return 0;

}
