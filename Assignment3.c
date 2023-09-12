#include<stdio.h>

struct pro{
	int P;
	int AT;
	int BT;
	int CT;
	int TT;
	int WT;
};
void sort(struct pro table[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(table[i].AT>table[j].AT)
			{
				int temp=table[i].AT;
				table[i].AT=table[j].AT;
				table[j].AT=temp;
				temp=table[i].P;
				table[i].P=table[j].P;
				table[j].P=temp;
				temp=table[i].BT;
				table[i].BT=table[j].BT;
				table[j].BT=temp;
			}
		}
	}
}

int main()
{
	int n;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	struct pro table[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter details for Process%d:",i+1);
		table[i].P=i+1;
		scanf("%d %d",&table[i].AT,&table[i].BT);
	}
/*	for(int i=0;i<n;i++)
	{
		printf("%d %d %d\n",table[i].P,table[i].AT,table[i].BT);
	}*/
	sort(table,n);
	printf("\n");
/*	for(int i=0;i<n;i++)
        {
                printf("%d %d %d\n",table[i].P,table[i].AT,table[i].BT);
        }*/
	int c=table[0].BT;
	table[0].CT=table[0].BT;
	for(int i=1;i<n;i++)
	{
		
		if(c>=table[i].AT)
		{
			c+=table[i].BT;
			table[i].CT=c;
		}
		else
		{
			c=table[i].AT+table[i].BT;
			table[i].CT=c;
		}
	}
	float totalt=0,totalw=0;
	for(int i=0;i<n;i++)
	{
		table[i].TT=table[i].CT-table[i].AT;
		totalt+=table[i].TT;
		table[i].WT=table[i].TT-table[i].BT;
		totalw+=table[i].WT;
	}
	printf("Process\tAT\tBT\tCT\tTT\tWT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",table[i].P,table[i].AT,table[i].BT,table[i].CT,table[i].TT,table[i].WT);
	}
	
	printf("Average TurnAround Time %.2f\n ",totalt/n);
	printf("Average turnaround time %.2f",totalw/n);

}
