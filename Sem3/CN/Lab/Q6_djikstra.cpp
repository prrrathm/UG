#include<iostream>
#include<cstdio>
using namespace std;

#define INFINITY 9999
#define max 5

void dijkstra(int node[max][max],int n,int startnode);

int main() {
	int node[max][max];
	cout<<"Enter the cost matrix for each node:-\n";
	for(int i=0; i<max; i++){
		for(int j=0; j<max; j++){
			cin>>node[i][j];
		}
	}	//={{0,2,0,9,0},{2,0,4,0,0},{0,4,0,3,0},{9,0,3,0,6},{0,0,0,6,0}};
	int n=max;
	int u;
	cout<<"Enter source node: ";
	cin>>u;
	dijkstra(node, n, u-1);
return 0;
}

void dijkstra(int node[max][max],int n,int startnode) {

	int cost[max][max];
	
	int distance[max], pred[max], visited[max];
	
	int count, mindistance, nextnode, i, j;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(node[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=node[i][j];
		}		
	}
				
	for(i=0;i<n;i++) {
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count<n-1) {
		mindistance=INFINITY;
		for(i=0;i<n;i++)
			if(distance[i]<mindistance && !visited[i]) {
				mindistance=distance[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=0;i<n;i++){
			if(!visited[i]){
				if(mindistance+cost[nextnode][i]<distance[i]) {
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			}
		}		
		count++;
	}
	for(i=0;i<n;i++)
	if(i!=startnode) {
		cout<<"\nDistance from node "<<i+1<<" = "<<distance[i];
		cout<<"\nPath="<<i+1;
		j=i;
		do {
			j=pred[j];
			cout<<"<-"<<j+1;
		}while(j!=startnode);
	}
	cout<<endl;
}
