
#include<iostream>
using namespace std; 
int m=0;
int n=0;
void firstFit(int blocks[], int processes[]) 
{ 
 
	int alloc[n]; 
	for (int i = 0; i < n; i++) 
	{ 
		for (int j = 0; j < m; j++) 
		{ 
			if (blocks[j] >= processes[i]) 
			{ 
				alloc[i] = j; 
				blocks[j] -= processes[i]; 
				break; 
			} 
		} 
	} 

	cout << "\nProcess\tSize\tBlock\n"; 
	for (int i = 0; i < n; i++) { 
		cout << " " << i + 1 << "\t" << processes[i] << "\t"; 
		if (alloc[i] != -1&&abs(alloc[i])<=m) 
			cout << alloc[i] + 1; 
		else
			cout << "Not Allocated"; 
		cout << endl; 
	} 
} 

int main() 
{ 
	cout<<"Number of processes: ";
	cin>>n;
	cout<<"Number of blocks: ";
	cin>>m;
	int blocks[m];
	int processes[n];
	for(int i=0;i<n;i++){
		cout<<"Size of process "<<i+1<<": ";
		cin>>processes[i];
		cout<<endl;
	}
	for(int i=0;i<m;i++){
		cout<<"Size of block "<<i+1<<": ";
		cin>>blocks[i];
		cout<<endl;
	}

	firstFit(blocks, processes); 

	return 0 ; 
} 

