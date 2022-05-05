//
// Pratham Sharma AC-1232
//

#include <iostream>
#include <list>
#include <vector>

using namespace std;

// to store the weight of destination and source vertex,
// source vertex will be used as index and destination along with weight will be store in class.
// Next to store the address of next node connected to the source vertex
class Node {
public:
    int destination;
    int weight;

    Node *next;

    Node() {
        destination = 0;
        weight = 0;
        next = nullptr;
    }

    Node(int destination, int weight) {
        this->destination = destination;
        this->weight = weight;
        next = nullptr;
    }
};

// to maintain the list of all nodes of a source vertex to its destination
class ListNode {
    Node *head;
    Node *tail;
public:
    // function to insert destination and weight of the source vertex
    void insertEdges(int destination, int weight) {
        Node *newNode = new Node(destination, weight);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    // function to return head
    Node *getHead() {
        return head;
    }
};

// priority queue class to store vertex and their weight
class priorityQueue {
    vector<Node *> heap;
public:
    Node *getMin() {
        Node *returnVertex = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapify();
        return returnVertex;
    }

    void updateVertex(int vertex, int weight) {
        bool flag = false;
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i]->destination == vertex) {
                heap[i]->weight = weight;
                flag = true;
                break;
            }
        }
        if (!flag) {
            insertVertex(vertex, weight);
        }
        heapify();
    }

    // min heapify
    void heapify() {
        int left = 1;
        int right = 2;
        int current = 0;

        while (left < heap.size() && right < heap.size() &&
               heap[current]->weight > min(heap[left]->weight, heap[right]->weight)) {
            int swapIndex = heap[left]->weight > heap[right]->weight ? right : left;
            swap(heap[current], heap[swapIndex]);
            current = swapIndex;
            left = 2 * current + 1;
            right = 2 * current + 2;
        }

        if (left == heap.size() - 1) {
            if (heap[current]->weight > heap[left]->weight) swap(heap[current], heap[left]);
        }
    }

    void insertVertex(int vertex, int weight) {
        Node *newNode = new Node(vertex, weight);
        heap.push_back(newNode);
        int childIndex = heap.size()-1;
        int parentIndex = (childIndex-1)*0.5;
        while (heap[childIndex]->weight < heap[parentIndex]->weight && childIndex > 0) {
            swap(heap[childIndex], heap[parentIndex]);
            childIndex = parentIndex;
            parentIndex = (childIndex-1)*0.5;
        }
    }
};

class primsMST {
public:
    ListNode *edges;
    int noOfVertices;
    primsMST(int n) {
        noOfVertices = n;
        edges = new ListNode[noOfVertices];
    }

    // input function
    void inputEdges() const {
        int noOfEdges;
        cout << "Enter no of Edges: ";
        cin >> noOfEdges;
        for (int i = 0; i < noOfEdges; i++) {
            cout << "Enter Source, Destination: ";
            int source, destination;
            cin >> source >> destination;
            cout << "Enter weight for the above pair: ";
            int weight;
            cin >> weight;
            edges[source].insertEdges(destination, weight);
            edges[destination].insertEdges(source, weight);
        }
    }

    void primsAlgo() {
        bool *visited = new bool[noOfVertices];
        int *parent = new int[noOfVertices];
        int *weight = new int[noOfVertices];

        priorityQueue obj;

        obj.insertVertex(0, 0);
        weight[0] = 0;
        for (int i = 1; i < noOfVertices; i++) {
            weight[i] = INT16_MAX;
            obj.insertVertex(i, weight[i]);
        }
        parent[0] = -1;

        for (int i = 0; i < noOfVertices-1; i++) {
            Node *minVertex = obj.getMin();
            int minParent = minVertex->destination;
            visited[minParent] = true;

            Node *tempHead = edges[minParent].getHead();
            while (tempHead) {
                int childVertex = tempHead->destination;
                int childWeight = tempHead->weight;
                if (!visited[childVertex] && childWeight < weight[childVertex]) {
                    parent[childVertex] = minParent;
                    weight[childVertex] = childWeight;
                    obj.updateVertex(childVertex,childWeight);
                }
                tempHead = tempHead->next;
            }
        }
        print(parent, weight);
    }

    void print(int *parent, int *weight) const {
        int totWeight = 0;
        cout << "The Required Prim's MST for the given Graph is:\n";
        for (int i = 1; i < noOfVertices; i++) {
            cout << i << " ------------- " << parent[i] << " -> " << weight[i] << endl;
            totWeight += weight[i];
        }
        cout << "-----------------------------------\n";
        cout << "Total Cost: " << totWeight;
    }
};

int main() {
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\tProgram to implement Prims Minimum Spanning Tree Algorithm\n";
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";

    cout << "Enter total no of Vertices: ";
    int n;
    cin >> n;

    primsMST obj(n);
    obj.inputEdges();
    obj.primsAlgo();
}