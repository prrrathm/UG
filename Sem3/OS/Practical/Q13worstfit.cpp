#include <iostream> //input output stream
using namespace std;
void sort(int m[], int block[], int x) //method for sorting memory block size
{
	int min, loc, i, j, temp1, temp2;

	for (i = 0; i < x - 1; i++)
	{
		min = m[i];
		loc = i;
		for (j = i + 1; j < x; j++)
		{
			if (min < m[j])
			{
				min = m[j];
				loc = j;
			}
		}
		temp1 = m[i];
		m[i] = m[loc];
		m[loc] = temp1;

		temp2 = block[i];
		block[i] = block[loc];
		block[loc] = temp2;
	}
}

int main()
{
	int process_num, memory_num;

	cout << "\nEnter number of process: "; //taking number of process
	cin >> process_num;
    cout<<endl;
	int process[process_num]; //creating array for process

	for (int i = 0; i < process_num; i++) //taking size of each process
	{
		cout << "Enter size of process P" << i + 1 << ": ";
		cin >> process[i];
	}

	cout << "\nEnter number of memory blocks: "; //taking number of memory blocks
	cin >> memory_num;
    cout<<endl;
	int memory[memory_num], block[memory_num];

	for (int i = 0; i < memory_num; i++) //taking size of each memory blocks
	{
		cout << "Enter size of memory block " << i + 1 << ": ";
		cin >> memory[i];
		block[i] = i + 1; //block[] to track each block after sorting
	}

	int val = 0;
	cout << "\nProcess No.\tProcess size\tBlock no." << endl;

	for (int i = 0; i < process_num; i++)
	{
		sort(memory, block, memory_num); //sorting memory blocks
		for (int j = 0; j < memory_num; j++)
		{
			if (process[i] <= memory[j]) //finding in which memory block process fits
			{
				cout << "P" << i + 1 << "\t\t" << process[i] << "\t\t" << block[j];
				memory[j] = memory[j] - process[i];
				process[i] = 0;
				break;
			}
		}
		cout<<endl;
	}

	for (int i = 0; i < process_num; i++) //printing process which are not allocated
	{
		if (process[i] != 0)
			cout << "P" << i + 1 << "\t"
				 << "\t" << process[i] << "\t"
				 << "\t"
				 << "Not Allocated" << endl;
	}

	return 0;
}
