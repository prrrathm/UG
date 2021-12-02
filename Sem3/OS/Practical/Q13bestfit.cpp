#include <iostream>         
using namespace std;
void sort(int mem[], int a)     //method for sorting memory block size
{
    int j,k;
    int temp;
    for(j=1; j<a; j++)                  
    {
        temp=mem[j];
        for(k=j; k>0 && temp<mem[k-1]; k--)
        {
            mem[k]=mem[k-1];
        }
        
        mem[k]=temp;
    }
}

int main()
{
    int pro, memo;
    
    cout<<"\nEnter number of process: ";      //taking number of process
    cin>>pro;
    cout<<endl;
    int prs[pro];               //creating array for process        
    
    for(int i=0; i<pro; i++)            //taking size of each process
    {
        cout<<"Enter size of process P"<<i+1<<": ";
        cin>>prs[i];
    }
    
    cout<<"\nEnter number of memory blocks: ";        
    cin>>memo;
    cout<<endl;
    int mem[memo], temp_mem[memo];
    
    for(int i=0; i<memo; i++)            
    {
        cout<<"Enter size of memory block "<<i+1<<": ";
        cin>>mem[i];
        temp_mem[i]=mem[i];         //creating copy of mem[]

    }
    
    int val=0;
    cout<<"\nProcess No.\tProcess size\tBlock no."<<endl;
    
    for(int i=0;i<pro;i++)
        {
            sort(mem,memo);          //sorting memory blocks
                for(int j=0;j<memo;j++)
                                    { 
                     if(prs[i]<=mem[j]) //finding in which memory block process fits
                      {
                         for(int k=0;k<memo;k++)
                         {
                           if(temp_mem[k]==mem[j])
                           val=k; 
                         }
                        cout<<"P"<<i+1<<"\t\t"<<prs[i]<<"\t\t"<<val+1;
                        mem[j]=mem[j]-prs[i];
                                   prs[i]=0;
                                   break;
                                           
                    }
                }   
            cout<<endl;         
        }
    
    for(int i=0; i<pro; i++)                    
    {
        if(prs[i]!=0)
            cout<<"P"<<i+1<<"\t"<<"\t"<<prs[i]<<"\t"<<"\t"<<"Not Allocated"<<endl;
    }
    
    return 0;
}   
            
           
