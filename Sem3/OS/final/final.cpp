// Write a program to search a number in a list using a thread.

#include <iostream>
#include <pthread.h>
using namespace std;

#define max 16
#define thread_max 4
bool flag = false;

struct thread_args {
    int a[max];
    int key;
    int flag;
    int current_thread = 0;
};


void* ThreadSearch(void* args) {
    struct thread_args *arg = (struct thread_args *)args;
	
    int num = arg->current_thread + 1;
	for (int i = num * (max / 4); i < ((num + 1) * (max / 4)); i++) {
		if (arg->a[i] == arg->key)
			// cout << arg->key << " is present in List";
            flag = true;
	}
    return args;
}

// Driver Code
int main() {
	pthread_t thread[thread_max];
    cout << "\nProgram to search an element in a list\n\n";
    cout << "Enter element to search in list =>";
    int key;
    cin >> key;


    struct thread_args arg1;
    arg1.key = key;
    arg1.current_thread = 0;
    arg1.a = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220 };

	for (int i = 0; i < thread_max; i++) {
		pthread_create(&thread[i], NULL, ThreadSearch, (void*)&arg1);
	}

	// for (int i = 0; i < thread_max; i++) {
	// 	pthread_join(thread[i], NULL);
	// }


	if (flag)
		cout << arg1.key << " is present in List" << endl;
	else
		cout << arg1.key << " is not present in List" << endl;
	return 0;
}
