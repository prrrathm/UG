//
// Pratham Sharma AC-1232
//

#include <iostream>
#include <list>
#include <stack>

using namespace std;

// template class for DFS Algo
class DFS {
private:
    list<int> *edges;
public:
    // creating necessary variables
    int noOfVertices;

    // constructor for initialization
    DFS(int n) {
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

    // DFS print function
    void printDFS() {
        bool visited[noOfVertices];
        for (int i = 0; i < noOfVertices; i++) {
            visited[i] = false;
        }
        int startVertex;
        cout << "Enter Start Vertex: ";
        cin >> startVertex;
        stack<int> vertex;
        vertex.push(startVertex);

        while (vertex.size()) {
            int topVertex = vertex.top();
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

        cout << "The DFS is \n";
        printDFS();
    }
};

int main() {
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\tProgram to implement Depth First Search Algorithm\n";
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";

    cout << "Enter total no of Vertices: ";
    int n;
    cin >> n;

    DFS obj(n);
    obj.CallingFunctions();
    return 0;
}
