#include<stdio.h>
struct process
{
	
	int pro,at,b_time,burst,p_arrived,complete;

	double pri;
	
}proce[4];
void Pri(struct process *p1,int t)//cal priority
{	
	if(t>=p1->at && p1->b_time!=(-1)) 
			{
				p1->pri=1+((t-p1->at)/p1->b_time);
			}
}
void Sort(struct process *p1,struct process *p2){
	if(p1->pri<p2->pri && p1->p_arrived!=0 && p2->p_arrived!=0)
				{
					double t1=p1->pri;
					p1->pri=p2->pri;
					p2->pri=t1;
					int t2=p1->p_arrived;
					p1->p_arrived=p2->p_arrived;
					p2->p_arrived=t2;
				}
				else if(p1->pri==p2->pri  && p1->p_arrived!=0 && p2->p_arrived!=0)
				{
					if(p1->b_time<p2->b_time)
					{
						int t=p1->p_arrived;
						p1->p_arrived=p2->p_arrived;
						p2->p_arrived=t;
					}
				}
			}

void main(){
	int time=0,i=0,bt=0,ii=0;
	for(i=0;i<4;i++)
	{
		printf("\nENTER PROCESS ID:-");
		scanf("%d",&proce[i].pro);
		printf("\nENTER PROCESS ARRIVAL:-");
		scanf("%d",&proce[i].at);
		printf("\nENTER PROCESS BURST TIME:-");
		scanf("%d",&proce[i].b_time);
		proce[i].burst=proce[i].b_time;
		proce[i].p_arrived=1;
		proce[i].complete=0;
		proce[i].pri=0;
	}
	while(1)
	{
		int te;
		for(te=0;te<4;te++)         //calling priority func
		{
			Pri(&proce[te],time);
	
		}
		int p,q;
		for(p=0;p<4;p++)                     //bubble sort based on priority
		{
			for(q=0;q<4-1-p;q++)  
			{
				Sort(&proce[q],&proce[q+1]);
			
			}
		}
		int y=proce[0].p_arrived;
		bt=proce[y-1].b_time;
		do
		{
		
			int x;
			for(x=0;x<4;x++)      //incrementing the time based on priority
			{
				if(time==proce[x].at)
				{		
					proce[x].p_arrived=x+1;
					printf("process %dhas  arrived\n",x);
				}	
			}
			bt=bt-1;
			time=time+1;
			if(bt==0)
			{
				printf("process %d has completed\n",y );
				proce[y-1].complete=time;
				ii=ii+1;                   
				proce[y-1].b_time=-1;
			
				for(x=0;x<4;x++)                       //for the processes which are still running
				{
					proce[x].pri=0;
					if(proce[x].p_arrived!=0)
					{
						proce[x].p_arrived=x+1;   // new priority 
					}
				}
				break;
			}
		}while(1);
		if(ii==4)
			break;

	}
	
	int tat[4]={0}, wt[4]={0};float awt,atat;
	for(i=0;i<4;i++)
	{
		tat[i]=proce[i].complete-proce[i].at;
		wt[i]=tat[i]-proce[i].burst;
	}
	printf("Process\tArrival time\tBurst time\tTurnaround time\tWaiting time\n");
	for(i=0;i<4;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t%d\n",i+1,proce[i].at,proce[i].burst,tat[i],wt[i]);
	}
	awt=wt[0]+wt[1]+wt[2]+wt[3];
	atat=tat[0]+tat[1]+tat[2]+tat[3];
	printf("\nAverage waiting time is %f .",awt/4.0);
	printf("\nAverage turnaround time is %f .",atat/4.0);
}
