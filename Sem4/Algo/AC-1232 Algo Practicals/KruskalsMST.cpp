//
// Pratham Sharma AC-1232
//

#include "iostream"
#include "unordered_map"

using namespace std;

class Edge{
public:
    int src;
    int dest;
    int weight;
    Edge(){
        this->src=0;
        this->dest=0;
        this->weight=0;
    }
    Edge(int src,int dest,int weight){
        this->src=src;
        this->dest=dest;
        this->weight=weight;
    }
};

class MST{
    int no_of_edges;
    unordered_map<int,int> child_parent;
    Edge *edge_list;
    Edge *mst_edges;
    int mst_weight;
public:
    MST(){
        cout<<"Enter no of edges : ";
        cin>>no_of_edges;
        edge_list=new Edge[no_of_edges];
        mst_weight=0;
    }
    void takeEdges(){
        cout<<"Enter edges : \n";
        cout<<"-----------------------------------------------------\n";
        for(int i=0;i<no_of_edges;i++){
            cout<<"src vertex : ";
            cin>>edge_list[i].src;
            cout<<"dest vertex : ";
            cin>>edge_list[i].dest;
            cout<<"weight : ";
            cin>>edge_list[i].weight;
            cout<<"-----------------------------------------------------\n";
            child_parent[edge_list[i].src]=edge_list[i].src;
            child_parent[edge_list[i].dest]=edge_list[i].dest;
        }
        mst_edges=new Edge[child_parent.size()];
        sortEdgeAsPerWeight();
    }
    void findMST(){
        int count=0;
        cout<<"MST is : \n";
        for(int i=0;i<no_of_edges;i++){
            if(count==child_parent.size()-1){
                break;
            }
            int srcParent=hasParent(edge_list[i].src);
            int destParent=hasParent(edge_list[i].dest);
            if(srcParent!=destParent){
                mst_edges[count]=edge_list[i];
                cout<<"Edge : ["<<edge_list[i].src<<","<<edge_list[i].dest<<"] Weight : "<<edge_list[i].weight<<"\n";
                child_parent[srcParent]=destParent;
                count++;
                mst_weight+=edge_list[i].weight;
            }
        }
        cout<<"Weight of MST : "<<mst_weight<<endl;
    }
    void printEdges(){
        cout<<"The edges in sorted weight order is : \n";
        for(int i=0;i<no_of_edges;i++){
            cout<<"Edge : ["<<edge_list[i].src<<","<<edge_list[i].dest<<"] Weight : "<<edge_list[i].weight<<"\n";
        }
    }
private :
    void sortEdgeAsPerWeight(){
        for(int i=0;i<no_of_edges-1;i++){
            for(int j=i+1;j<no_of_edges;j++){
                if(edge_list[i].weight > edge_list[j].weight){
                    Edge temp;
                    temp=edge_list[i];
                    edge_list[i]=edge_list[j];
                    edge_list[j]=temp;
                }
            }
        }
    }
    int hasParent(int vertex1){
        if(child_parent[vertex1]==vertex1){
            return vertex1;
        }
        return hasParent(child_parent[vertex1]);
    }
};

int main(){
    MST object;
    object.takeEdges();
    object.printEdges();
    object.findMST();
}