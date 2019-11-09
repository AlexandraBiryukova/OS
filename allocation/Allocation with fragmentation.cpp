#include <iostream> 
using namespace std; 
int m=0;
int n=0;
bool fr=false;
void printing(int processes[n],int alloc[n],int blocks[m]){
	for (int i = 0; i < n; i++) { 
		if (alloc[i] == -1 || abs(alloc[i])>m ){
			if(!fr){
				for(int i=0;i<m-1;i++){
					blocks[m-1]+=blocks[i];
				}
			}
			if(blocks[m-1]>=processes[i]){
				alloc[i]=m;
				fr=true;
				blocks[m-1]-=processes[i];
			}

		}
	}
	cout << "\nProcess\tSize\tBlock\n"; 
	for (int i = 0; i < n; i++) { 
		cout << " " << i + 1 << "\t" << processes[i] << "\t"; 
		if (alloc[i] != -1 && abs(alloc[i])<=m ) 
			if(alloc[i]==m&&fr){
				cout<<"New";
			}else{
				cout << alloc[i] + 1; 
			}
		else
			cout << "Not Allocated"; 
		cout << endl; 
	} 

}
void NextFit(int blocks[m], int processes[n]) 
{ 
	
	int alloc[n], j = 0; 
	for (int i = 0; i < n; i++) { 

		while (j < m) { 

			if (blocks[j] >= processes[i]) { 
				alloc[i] = j; 
				blocks[j] -= processes[i]; 
				break; 
			} 
			j = (j + 1) % m; 
		} 
	} 

	printing(processes,alloc,blocks);

} 
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

	printing(processes,alloc,blocks);
} 
void worstFit(int blocks[], int processes[]) 
{  
	int alloc[n];  
	for (int i=0; i<n; i++) 
	{ 
		int maxim = -1; 
		for (int j=0; j<m; j++) 
		{ 
			if (blocks[j] >= processes[i]) 
			{ 
				if (maxim == -1) 
					maxim = j; 
				else if (blocks[maxim] < blocks[j]) 
					maxim = j; 
			} 
		} 
		if (maxim != -1) 
		{ 
			alloc[i] = maxim; 

			blocks[maxim] -= processes[i]; 
		} 
	} 

	printing(processes,alloc,blocks);

}
void bestFit(int blocks[], int processes[]) 
{ 
	
	int alloc[n]; 

	for (int i=0; i<n; i++) { 
		int minim = -1; 
		for (int j=0; j<m; j++) { 
			if (blocks[j] >= processes[i]) 
			{ 
				if (minim == -1) 
					minim = j; 
				else if (blocks[minim] > blocks[j]) 
					minim = j; 
			} 
		} 

		
		if (minim != -1) 
		{ 
			alloc[i] = minim; 
			blocks[minim] -= processes[i]; 
		} 
	} 
	printing(processes,alloc,blocks);

} 

int main() 
{ 
	cout<<"Number of processes: ";
	cin>>n;
	cout<<"Number of blocks: ";
	cin>>m;
	m++;
	int blocks[m];
	int processes[n];
	for(int i=0;i<n;i++){
		cout<<"Size of process "<<i+1<<": ";
		cin>>processes[i];
		cout<<endl;
	}
	for(int i=0;i<m-1;i++){
		cout<<"Size of block "<<i+1<<": ";
		cin>>blocks[i];
		cout<<endl;
	}
	blocks[m-1]=0;
	int choice;
	cout<<"Algorithm to use:\n1. First Fit\n2. Best Fit\n3. Next Fit\n4. Worst Fit\nYour choice:";
	cin>>choice;
	switch(choice){
		case 1:
		firstFit(blocks,processes);
		break;
		case 2:
		bestFit(blocks,processes);
		break;
		case 3:
		NextFit(blocks,processes);
		break;
		case 4:
		worstFit(blocks,processes);
		break;

	}

	return 0 ; 
} 

