// Write a program to search a number in a list using a thread.

#include<iostream>
#include<thread>
#include<vector>
#include<math.h>
using namespace std;

vector<int> arr;
int  key;
int flag=-1;

void search(int p,int q) {
    for(auto i=p;i<=q && i<arr.size();i++) {
        if(arr[i]==key) {
            cout<<"Element found in the vector \n";
            exit(0);
            }
        }
    }

int main() {
    int  block_start=0,block_end,n,ele;
    // input variable
    cout<<"Enter the size of the array =>";
    cin>>n;
    cout<<"Enter the array elements \n";
    
    for(int i=0;i<n;i++) {
        cout << "=>";
        cin >> ele;
        arr.push_back(ele);
    }

    cout<<"Enter the key to be searched =>";
    cin>>key;
    
    unsigned long const length = arr.size();
    const int  min_per_thread = 3;
    // each thread will search in the block of size 3 
    // i.e first thread will search from index 0 to 2 
    const int  num_threads = length / min_per_thread;
    const int block_size = length / num_threads;
    cout << "Number of threads created : " << num_threads << "\n";

    //creating thread
    vector<thread> threads(num_threads);
    block_start = 0;
    for(int i = 0; i < num_threads; i++) {
        block_end = block_start;
        block_end = block_end + block_size;
        threads[i] = thread(search,block_start,block_end);
        block_start = block_end + 1;
        }




    for(auto& entry: threads) {
        if(entry.joinable())
            entry.join();
        //join is used to make sure that every thread 
        // will execute before the main() ends
        }
    if(flag==-1){
        cout<<"Element not present in the vector \n";
    }

    return 0;
}
