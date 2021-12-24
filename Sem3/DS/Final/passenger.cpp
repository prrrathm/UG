#include "List.h"
void Person::ListInitiate(Flight **head)
{
 int count=0;
 *head = (Flight *)malloc(sizeof(Flight));
 (*head)->PersonHead=(Ticket *)malloc(sizeof(Ticket));
 (*head)->PersonHead->next=NULL;
 (*head)->next=NULL;
 for(int i=0;i<50;i++)
 {
 (*head)->Seat[i]=0;
 }
}
 
bool Person::Check(int *Seat,int Ch)
{
 int i;
 for(int i=0;i<50;i++)
 {
 if(Ch==i&&Seat[i]!=1)return 1;
 }
 return 0;
}
Flight* Index(Flight *head,char *Id)
{
 Flight *p=head->next;
 
 while(p)
 {
 if(strcmp(p->FlightId,Id)==0)
 {
 return p;
 }
 p=p->next;
 }
 
 return NULL;
}
/ ***************** scheduled***********************/
void Person::Insert(Flight *head)
{
 int count=0;
 int Ch;
 Flight *s=head;
 
 if(s->next==NULL)
 {
 Cout < < "No flights yet! "Endl;
 return ;
 }
 Cout < <Flight List:> endl;
 s=s->next;
 while(s!=NULL)
 {
 puts(s->FlightId);
 count++;
 if(count%5==0)
 cout<<"\n";
 s=s->next;
 }
 count=0;
 char FID[10];
 Court < < "Enter flight ID:";
 gets(FID);
 s=Index(head,FID);
 if(s==NULL)
 {
 Cout < <Error in Input ID> endl;
 return;
 }
 cout<<endl;
 Cout < < "There are the following seats to choose from:""endl;
 for(int i=0;i<50;i++)
 {
 if(s->Seat[i]!=1)
 {
 Cout < I < < number < <  t;;
 count++;
 if(count%5==0)
 cout<<"\n";
 }
 }
 cout<<endl;
 Court < <Enter the seat number: \ n;
 cin>>Ch;
 getchar();
 if(!Check(head->Seat,Ch))
 {
 cout<<"This Seat have been booked or it is non-existent";
 return ;
 }
 s->Seat[Ch]=1;
 char name[20];
 cout<<endl;
 cout<<"Input your Name:";
 gets(name);
 Ticket *p=s->PersonHead,*q;
 
 while(p->next!=NULL)
 { 
 if(strcmp(p->next->Name,name)>0)
 break;
 p=p->next;
 }
 
 q=(Ticket *)malloc(sizeof(Ticket));
 q->next=p->next;
 p->next=q;
 strcpy(q->Name,name);
 q->SeatId=Ch;
}
 
/ ***************** Cancel the Reservation of *************************/
int Person::Delete(Flight *head)
{
 char name[20],FID[10];
 cout<<"Input your Name:";
 gets(name);
 getchar();
 Flight *s;
 cout<<"Input the Flight ID:";
 gets(FID);
 s=Index(head,FID);
 if(s==NULL)
 {
 Cout < <Error in Input ID> endl;
 return 0;
 }
 
 Ticket *p=s->PersonHead->next,*pre=s->PersonHead;
 int flag=0;
 while(p!=NULL)
 {
 if(strcmp(p->Name,name)==0){
 flag=1;
 break; 
 }
 pre=p;
 p=p->next;
 }
 if(flag==1){
 pre->next=p->next;
 s->Seat[p->SeatId]=0;
 free(p);
 Cout < < "Your ticket has been cancelled successfully";
 }
 else 
 {
 Cout < <You haven't booked a ticket yet \n;"
 return 0; 
 }
 return 1;
}
/ ***************** Display Information********************************/
void Person::show(Flight *head)
{
 Flight *s;
 char FID[10];
 cout<<"Input The Flight ID:";
 gets(FID);
 s=Index(head,FID);
 if(s==NULL)
 {
 Cout < <Error in Input ID> endl;
 return;
 }
 Ticket *p=s->PersonHead->next;
 if(p==NULL)
 {
 Cout < < "No passengers booked yet"> endl;
 return;
 }
 while(p!=NULL)
 {
 Cout < < Passenger: > p - > Name < < seat number: > p - > SeatId;
 p=p->next;
 }
}
 
/ ****************** Query for relevant information************************/
void Person::Search(Flight *head)
{
 char name[20];
 cout<<"Input Your Name:";
 gets(name);
 Flight *s;
 char FID[10];
 cout<<"Input The Flight ID:";
 gets(FID);
 s=Index(head,FID);
 if(s==NULL)
 {
 Cout < <Error in Input ID> endl;
 return;
 }
 Ticket *p=s->PersonHead->next;
 int flag=0;
 while(p!=NULL)
 {
 if(strcmp(p->Name,name)==0){
 flag=1;
 break; 
 }
 p=p->next;
 }
 if(flag==1){
 Cout < name < < booked ticket < endl;
 }
 else 
 {
 Cout < name < < booked ticket < endl;
 }
}
/ ***************** Increase flights*************************/
void Person::AddFlght(Flight *head)
{
 char FlightID[10];
 Flight *p=head,*q;
 Court < < "Enter flight ID:";
 gets(FlightID);
 while(p->next)
 {
 p=p->next;
 }
 
 ListInitiate(&q);
 p->next=q;
 strcpy(q->FlightId,FlightID);
 Court <"- Flight has been added successfully! ";
}
/ ************************ Delete flights*************************/
void Person::DeleteFlght(Flight *head)
{
 char FlightID[10];
 int flag=0;
 Flight *p=head->next,*q=head;
 
 int count=0;
 Flight *s=head;
 
 if(s->next==NULL)
 {
 Cout < < "No flights yet! "Endl;
 return ;
 }
 Cout < <Flight List:> endl;
 s=s->next;
 while(s!=NULL)
 {
 cout<<s->FlightId<<endl;
 count++;
 if(count%5==0)
 cout<<"\n";
 s=s->next;
 }
 Court < < "Enter flight ID:";
 gets(FlightID);
 while(p)
 {
 if(strcmp(p->FlightId,FlightID)==0)
 {
 flag=1;break;
 }
 q=p;
 p=p->next;
 }
 if(flag==0)
 {
 Court < < "The flight ID does not exist! ";
 return ;
 }
 q->next=q->next->next;
 free(p);
 Cout < < "Flight deleted! \n ";
}