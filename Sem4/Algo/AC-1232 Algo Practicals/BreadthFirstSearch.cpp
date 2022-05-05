//
// Pratham Sharma AC-1232
//

#include <iostream>
#include <list>
#include <queue>

using namespace std;

// template class for BFS Algo
class BFS {
private:
    list<int> *edges;
public:
    // creating necessary variables
    int noOfVertices;

    // constructor for initialization
    BFS(int n) {
        noOfVertices = n;
        edges = new list<int>[noOfVertices];
    }

    // input function
    void inputEdges() {
        int noOfEdges;
        cout << "Enter no of Edges: ";
        cin >> noOfEdges;
        for (int i = 0; i < noOfEdges; i++) {
            cout << "Enter Edge Pair: ";
            int v1, v2;
            cin >> v1 >> v2;
            edges[v1].push_back(v2);
        }
    }

    // BFS print function
    void printBFS() {
        bool visited[noOfVertices];
        for (int i = 0; i < noOfVertices; i++) {
            visited[i] = false;
        }
        int startVertex;
        cout << "Enter Start Vertex: ";
        cin >> startVertex;
        queue<int> vertex;
        vertex.push(startVertex);

        while (vertex.size()) {
            int topVertex = vertex.front();
            vertex.pop();
            if (!visited[topVertex]) {
                visited[topVertex] = true;
                cout << "Parent: " << topVertex;
                cout << "\nChild: ";
                list<int>::iterator it;
                for (it = edges[topVertex].begin(); it !=edges[topVertex].end(); it++) {
                    if (!visited[*it]) {
                        cout << *it << ", ";
                    }
                    vertex.push(*it);
                }
                cout << "\b\b";
                cout << endl;
            }
        }
    }

    void CallingFunctions() {
        inputEdges();
        cout << "---------------------------------------------------------\n";

        cout << "The BFS is \n";
        printBFS();
    }
};

int main() {
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\tProgram to implement Breadth First Search Algorithm\n";
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";

    cout << "Enter total no of Vertices: ";
    int n;
    cin >> n;

    BFS obj(n);
    obj.CallingFunctions();
    return 0;
}
