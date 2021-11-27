#include<iostream>
using namespace std;
int main() {
  char ch='Y';
  do {
    cout<<"\nChoose :-";
    cout<<"\n1.Pre-emptive priority";
    cout<<"\n2.non-preemptive priority\n";
    int choice ;
    cin>>choice;
  switch(choice) {
    case 1: {
      int number_of_processes;
      cout<<"\nEnter the number of prcoesses to be scheduled : ";
      cin>>number_of_processes;
      int arrivalTime[number_of_processes] , burstTime[number_of_processes] , priority[number_of_processes+1] , x[number_of_processes] , waitingTime[number_of_processes] , turnAroundTime[number_of_processes] , completionTime[number_of_processes];
      int smallest , number_of_processes_completed = 0  ;
      double average = 0 , tt=0 , end;

      for(int i=0 ; i<number_of_processes;i++)
      {
        cout<<"Enter arrival time "<<i+1<< " : ";
        cin>>arrivalTime[i];
      }

      for(int i=0 ; i<number_of_processes;i++)
      {
        cout<<"Enter burst time "<<i+1<< " : ";
        cin>>burstTime[i];
      }

      for(int i=0 ; i<number_of_processes;i++)
      {
        cout<<"Enter priority "<<i+1<< " : ";
        cin>>priority[i];
      }

      for(int i=0 ; i<number_of_processes ; i++)
      {
        x[i]=burstTime[i];
      }

      priority[number_of_processes]=10000;

      for(int time=0; number_of_processes_completed!=number_of_processes; time++)
      {
        smallest = number_of_processes;
        for(int i=0;i<number_of_processes;i++)
        {
          if(arrivalTime[i]<=time && priority[i]<priority[smallest] && burstTime[i]>0)
          {
            smallest = i;
          }
        }
        burstTime[smallest]--;
        if(burstTime[smallest]==0)
        {
          number_of_processes_completed++;
          end=time+1;
          completionTime[smallest]=end;
          waitingTime[smallest]=end-arrivalTime[smallest]-x[smallest];
          turnAroundTime[smallest]=end-arrivalTime[smallest];
        }
      }
      cout<<"\nProcess";
      cout<<"\t burst-time \t arrival-time \t waiting-time \t turnaround-time \t completion-time \t   priority \n";
      for(int i=0;i<number_of_processes;i++)
      {
        cout<<endl;
        cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<arrivalTime[i]<<"\t\t"<<waitingTime[i]<<"\t\t"<<turnAroundTime[i]<<"\t\t\t"<<completionTime[i]<<"\t\t\t"<<priority[i];
        average=average+waitingTime[i];
        tt=tt+turnAroundTime[i];
      }
      cout<<"\nAverage waitingTime : "<<average;
      cout<<"\nAverage turnAroundTime : "<<tt;
    }
case 2:
{
  int number_of_processes ,cpuCurrentTime=0 , allTime=0 ;
  int arrivalTime[number_of_processes] , burstTime[number_of_processes] , priority[number_of_processes+1] , ATt[number_of_processes] ,  ppt[number_of_processes] , waitingTime[number_of_processes] , turnAroundTime[number_of_processes];
  int nop=number_of_processes;
  for(int i=0 ; i<number_of_processes;i++)
  {
    cout<<"Enter arrival time "<<i+1<< " : ";
    cin>>arrivalTime[i];
  }

  for(int i=0 ; i<number_of_processes;i++)
  {
    cout<<"Enter burst time "<<i+1<< " : ";
    cin>>burstTime[i];
  }

  for(int i=0 ; i<number_of_processes;i++)
  {
    cout<<"Enter priority "<<i+1<< " : ";
    cin>>priority[i];
  }

  for(int i=0 ; i<number_of_processes;i++)
  {
    ppt[i]=priority[i];
    ATt[i]=arrivalTime[i];
  }

  int lastArrivalTime = 0 ;
  for(int i=0 ; i<number_of_processes;i++)
  {
    if(arrivalTime[i]>lastArrivalTime)
    {
      lastArrivalTime=arrivalTime[i];
    }
  }

  int maxPriority = 0 ;
  for(int i=0 ; i<number_of_processes;i++)
  {
    if(ppt[i]>maxPriority)
    {
      maxPriority=ppt[i];
    }
  }

  int ArrivalTimeIn=0;
  int P1=ppt[0];
  int P2=ppt[0];
  int j=-1;
  while(nop>0 && cpuCurrentTime<=1000)
  {
    for(int i=0 ; i<number_of_processes ; i++)
    {
      if((ATt[i]<=cpuCurrentTime) && (ATt[i]!=(lastArrivalTime+10)))
      {
        if(ppt[i]!=(maxPriority+1))
        {
          P2=ppt[i];
          j=1;
          if(P2<P1)
          {
            j=1;
            ArrivalTimeIn=i;
            P1=ppt[i];
            P2=ppt[i];
          }
        }
      }
    }
    if(j==-1)
    {
      cpuCurrentTime=cpuCurrentTime+1;
      continue;
    }
    else
    {
      waitingTime[ArrivalTimeIn]=cpuCurrentTime-ATt[ArrivalTimeIn];
      cpuCurrentTime=cpuCurrentTime+burstTime[ArrivalTimeIn];
      turnAroundTime[ArrivalTimeIn]=cpuCurrentTime-ATt[ArrivalTimeIn];
      ATt[ArrivalTimeIn]=lastArrivalTime+10;
      j=-1;
      ppt[ArrivalTimeIn]=maxPriority+1;
      ArrivalTimeIn=0;
      P1 = maxPriority+1;
      P2 = maxPriority+1;
      nop=nop-1;
    }
  }
  cout<<"\nProcesses\tBurst Time\tPriority\tArrival Time\tWaiting TIme\tTurnAround Time\n\n";
  for(int i=0 ; i<number_of_processes ; i++)
  {
    cout<<"p"<<i+1<<"\t\t"<<burstTime[i]<<"\t\t"<<priority[i]<<"\t\t"<<arrivalTime[i]<<"\t\t"<<waitingTime[i]<<"\t\t"<<turnAroundTime[i]<<endl;
  }

  int averageWaitingTime = 0 ;
  int averageTurnAroundTime=0 ;
  for(int i=0 ; i<number_of_processes ; i++)
  {
      averageWaitingTime=waitingTime[i]+averageWaitingTime;
      averageTurnAroundTime=turnAroundTime[i]+averageTurnAroundTime;
  }
  cout<<"\nAverage Waiting Time : "<<averageWaitingTime;
  cout<<"\nAverage turnAroundTime : "<<averageTurnAroundTime;
}
}
cout<<"Do you want to perform again ?(y/n)";
cin>>ch;
}while(ch=='Y' || ch=='y');
}