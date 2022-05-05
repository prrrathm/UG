//
// Pratham Sharma AC-1232
//

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class KnapSack {
    vector<int> weight;
    vector<int> values;
    int max_weight;

public:
    KnapSack() {
        cout << "Enter max weight knapsack can hold : ";
        cin >> max_weight;
    }

    void input() {
        int size = 0;
        cout << "Enter the size : ";
        cin >> size;
        for (int i = 0; i < size; i++) {
            int w, v;
            cout << "Enter weight and value for index [" << i << "] : ";
            cin >> w >> v;
            weight.push_back(w);
            values.push_back(v);
        }
    }

    void callingFunction() {
        input();
        cout << "The maximum value that is possible is : " << knapSackWeight() << endl;
    }

private:
    int knapSackWeight() {
        int knapSack[weight.size() + 1][max_weight + 1];
        for (int i = 0; i <= weight.size(); i++) {
            for (int wt = 0; wt <= max_weight; wt++) {
                if (i == 0 || wt == 0) {
                    knapSack[i][wt] = 0;
                } else if (weight[i - 1] <= wt) {
                    knapSack[i][wt] = max(values[i - 1] + knapSack[i - 1][wt - weight[i - 1]], knapSack[i - 1][wt]);
                } else {
                    knapSack[i][wt] = knapSack[i - 1][wt];
                }
            }
        }
        return knapSack[weight.size()][max_weight];
    }
};

int main() {
    KnapSack ob;
    ob.callingFunction();
    return 0;
}