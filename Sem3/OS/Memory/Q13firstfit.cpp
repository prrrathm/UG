#include <iostream> //input output stream
using namespace std;
int main()
{
	int process_num, memory_num;

	cout << "Enter number of process: "; //taking number of process
	cin >> process_num;
	cout << endl;
	int process[process_num]; //creating array for process

	for (int i = 0; i < process_num; i++) //taking size of each process
	{
		cout << "Enter size of process P" << i + 1 << ": ";
		cin >> process[i];
	}

	cout << "\nEnter number of memory blocks: "; //taking number of memory blocks
	cin >> memory_num;
	cout << endl;
	int memory[memory_num]; //creating array for memory blocks

	for (int i = 0; i < memory_num; i++) //taking size of each memory blocks
	{
		cout << "Enter size of memory block " << i + 1 << ": ";
		cin >> memory[i];
	}

	cout << "\nProcess No"
		 << "  Process size   "
		 << "Block No" << endl; //printing
	for (int i = 0; i < process_num; i++)
	{
		for (int j = 0; j < memory_num; j++)
		{
			if (process[i] <= memory[j]) //finding block in which process will fit
			{
				cout << i + 1 << "\t"
					 << "\t" << process[i] << "\t"
					 << "\t" << j + 1 << endl; //printing block in which process will fit
				memory[j] = memory[j] - process[i];
				process[i] = 0;
				break;
			}
		}
		cout << endl;
	}

	for (int i = 0; i < process_num; i++) //printing process which are not allocated
	{
		if (process[i] != 0)
			cout << i + 1 << "\t"
				 << "\t" << process[i] << "\t"
				 << "\t"
				 << "Not Allocated" << endl;
	}

	return 0;
}
