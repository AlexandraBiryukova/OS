#include <pthread.h>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int main(){

	int n; // processes number
	scanf("%d", &n);
	int m; // resources number
	scanf("%d", &m);
	int request[m+1];
	bool wrong=false;

	printf("%s\n", "");
	int allocation[n][m];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> allocation[i][j];
		}
	}
	int max[n][m];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> max[i][j];
		}
	}
	int available[m];
	for (int i = 0; i < m; i++){
		cin >> available[i];
	}
	while(true){
		int need[n][m];

		int safeSeq[n];

		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				need[i][j] = max[i][j] - allocation[i][j];
			}
		}

		int finish[n];
		for (int i = 0; i < n; i++){
			finish[i] = 0;
		}

		int work[m]; 
	    for (int i = 0; i < m ; i++){
	    	work[i] = available[i];
	    }

	    int program_counter = 0;
	    while(program_counter < n){
	    	bool exist = false;

	    	for (int i = 0; i < n; i++){
	    		if(finish[i]==0){
	    			
	    			int k;
	    			for (k = 0; k < m; k++){
	    				if(need[i][k] > work[k]){
	    					break;
	    				}
	    			}
	    			if(k==m){
	    				for (int l = 0; l < m; l++){
	    					work[l] += allocation[i][l];
	    				}
	    				safeSeq[program_counter++] = i;

	    				finish[i] = 1;
	    				exist = true;

	    			}


	    		}

	    	}
	    	if (exist == false) 
	        { 
	            cout << "System is not in safe state"; 
	            return 0; 
	        } 
	    }
	    if(!wrong){
		    cout << "System is in safe state.\nSafe sequence is: "; 
		    for (int i = 0; i < n ; i++){
		        cout << safeSeq[i] << " ";
		        if(i==n-1){
		        	cout << "\n";
		        } 
		    }
	}
	    for(int i=0;i<m+1;i++){
	    	if(i==0){
	    		cout<< "Request:\nProcess id:";
	    	}else{
	    		cout<<"Resource "<<i<<" number:";
	    	}
	    	cin>>request[i];
	    }
	    for(int i=0;i<m;i++){
	    	if(need[request[0]][i]<request[i+1]||available[i]<request[i+1]){
	    		cout<<"Wrong number of resources\n";
	    		wrong=true;
	    		break;
	    	}
	    	wrong=false;
	    	available[i]-=request[i+1];
	    	allocation[request[0]][i]+=request[i+1];
	    	need[request[0]][i]-=request[i+1];
	    }
	    if(!wrong){
		    
		    cout<<"Process"<<"   "<<"Allocation"<<"   "<<"Need"<<"   "<<"Available\n";
		    for(int i=0;i<n;i++){
		    	cout<<"P"<<i<<"        ";
		    	for(int j=0;j<m;j++){
		    		cout<<allocation[i][j]<<" ";
		    	}
		    	cout<<"     ";
		    	for(int j=0;j<m;j++){
		    		cout<<need[i][j]<<" ";
		    	}
		    	cout<<"      ";
		    	for(int j=0;j<m;j++){
		    		cout<<available[j]<<" ";
		    	}
		    	cout<<"\n";

		    }
	}
	    

}
   

	return 0;
}