#include<stdio.h>
int main(){
    int arr[10],bur[10],star[10],finish[10],tat[10],wt[10],i,n;
    int totwt=0,tottat=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("Enter the Arrival Time & Burst Time: ");
        scanf("%d%d",&arr[i],&bur[i]);
    }
    for(i=0;i<n;i++) {
        if(i==0) {
            star[i]=arr[i];
            wt[i]=star[i]-arr[i];
            finish[i]=star[i]+bur[i];
            tat[i]=finish[i]-arr[i];
        } else {
            star[i]=finish[i-1];
            wt[i]=star[i]-arr[i];
            finish[i]=star[i]+bur[i];
            tat[i]=finish[i]-arr[i];
        }
    }
    printf("\nP Name\tArr time\tBurs time\tStart\tTAT\tFinish\n");
    for(i=0;i<n;i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,arr[i],bur[i],star[i],tat[i],finish[i]);
        totwt+=wt[i];
        tottat+=tat[i];
    }
    printf("\nAverage Waiting time: %f\n",(float)totwt/n);
    printf("Average turn around time: %f\n",(float)tottat/n);
}

/*
Enter the number of processes:4
Enter the Arrival Time & Burst Time: 0 5
Enter the Arrival Time & Burst Time: 1 3
Enter the Arrival Time & Burst Time: 2 4
Enter the Arrival Time & Burst Time: 4 1

P Name  Arr time        Burs time       Start   TAT     Finish
P0      0               5               0               5               5
P1      1               3               5               7               8
P2      2               4               8               10              12
P3      4               1               12              9               13

Average Waiting time: 4.500000
Average turn around time: 7.750000
*/