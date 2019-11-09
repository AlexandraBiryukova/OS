#include <iostream>
#include <vector>
using namespace std;
vector<int> refString;

bool finding(int n,int a[n], int b){
	for(int i=0;i<n;i++){
		if(a[i]==b){
			return true;
		}
	}
	return false;
}
int main(){
	int n,p,count=0;
	cout<<"Print your reference string:\n( ends with -1 )\nPages: ";
	cin>>n;
	while(n!=-1){
		refString.push_back(n);
		cin>>n;
	}
	cout<<"How many pages can be in memory at a time per process?\nNumber of pages:";
	cin>>p;
	int size=refString.size();
	int frames[size][p];
	int fid=0,pid=0;
	for(int i=0;i<size;i++){
		for(int j=0;j<p;j++){
			frames[i][j]=-1;
		}
	}
	
	for(int i=0;i<size;i++){
		cout<<fid+1<<" "<<pid+1<<endl;
		bool f=true;
		if(fid>0&&finding(p,frames[fid-1],refString[i])){
			for(int pk=0;pk<p;pk++){
				frames[fid][pk]=frames[fid-1][pk];
			}
			fid++;
			count++;
		}else{
			for( int pk=0;pk<p;pk++){
				if(pk==pid&&f){
					frames[fid][pk]=refString[i];
					
					f=false;
				}else{
					if(fid>0){
						frames[fid][pk]=frames[fid-1][pk];
					}else{
						frames[fid][pk]=-1;
					}
				}
				
			}
			if(!f){
				pid=(pid+1)%p;
			}
			fid++;
			
		}
	}
   
	for(int i=0;i<p;i++){
		for(int j=0;j<size;j++){
			bool same=true;
			for(int k=0;k<p;k++){
				if(j>0&&frames[j-1][k]!=frames[j][k]){
					same=false;
				}
			}
			if(same&&j!=0){
				cout<<" "<<"  ";
			}else{
				if(frames[j][i]!=-1){
					cout<< frames[j][i]<<"  ";
				}else{
					cout<<"   ";
				}
			}
		}
		cout<<endl;
		
	}
	cout<<endl<<"Page Faults: "<<size-count<<endl;
	



	


	return 0;
}