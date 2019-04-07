#include<stdio.h>
#include<unistd.h>
struct resources
{
	int p;
	int pp;
	int q_pp;
	int allot_id;

};
struct resource_count{
	
	int p_count ;
	int pp_count ;
	int q_pp_count ;
}; 

struct resource_count c[3];

void allot(struct resource r)
{
	
			
	if(r.allot_id == 0)
	{
		r.p=1;
	}
	else if(r.allot_id == 1)
	{
		r.pp=1;
	}
	else if(r.allot_id == 2)
	{
		r.q_pp=1;
	}
	
}
int main()
{
	struct resource r[3];
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
		r[i].allot_id=i;
		allot(r[i]);
	}
		printf("\nResources alloted to students are:");
	for(i=0;i<3;i++)
	{
		if(r[i].p == 1)
		printf("\nResources alloted to student %d are:pen ",i+1);
		
		if(r[i].pp==1)
		printf("\nResources alloted to student %d are:paper ",i);
		
		if(r[i].q_pp == 1)
		printf("\nResources alloted to student %d are:question paper ",i+1);
	}
		while(count != 3)
		{
			for(i=0;i<3;i++)
			{
				switch{
					case 0:
				
					c[i].pp_count=1;
					c[i].p_count=1;
					for(j=0;j<3;j++)
					{
						if(s[j].q_pp==1)
						{
						printf("\nStudent %d has completed his job !",j+1);
						count++;
						}
					}
				break;
					case 1:
			
				c[i].q_pp_count=1;
				c[i].p_count=1;
				for(j=0;j<3;j++)
				{
					if(r[j].pp==1)
					{
						printf("\nStudent %d has completed his job !",j+1);
						count++;
					}
				}
			break;
		
					case 2:
			
				c[i].pp_count=1;
				c[i].q_pp_count=1;
				for(j=0;j<3;j++)
				{
					if(r[j].p==1)
					{
						printf("\nStudent %d has completed his job !",j+1);
						count++;
					}
				}
			break:
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
	for(i=1;i<4;i++)
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
