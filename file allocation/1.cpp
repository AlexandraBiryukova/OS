#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string counts[30];
struct file{
	int start;
	int length;
	string name;
};
void segmentation(){
	string count[30];
	for(int i=0;i<30;i++){
		count[i]=" ";
	}
	int i=0;
	for(int j=0;j<30;j++){
		if(counts[j]!=" "){
			count[i]=counts[j];
			i++;
		}
	}

	copy(count,count+30,counts);

}
int main(){
	vector<file> directory;
	
	for(int i=0;i<30;i++){
		counts[i]=" ";
	}
	while(true){
		file f;
		cout<<"File name: ";
		cin>>f.name;
		if(f.name=="stop"){
			break;
		}
		cout<<"File start: ";
		cin>>f.start;
		cout<<"File length: ";
		cin>>f.length;
		directory.push_back(f);

	}
	cout<<endl;
	bool segm_needed=false;
	for(int i=0;i<directory.size();i++){
		int l=-1;
		int paused=0;
		int emp=0;
		for( int c=0;c<30;c++){
			if(counts[c]==" "){
				emp++;
			}
		}
		if(emp<directory[i].length){
			cout<<"File < "<< directory[i].name<<" > can't be allocated\n";
			continue;
		}
		while(l!=0){
			l=directory[i].length;
			for(int j=directory[i].start;0<l;j++){
				if(counts[j]==" "){
					l--;
				}else{
					// cout<<"paused";
					paused=j;
					break;

				}
			}
			if(l!=0){
				if(paused<29){
					// cout<<paused<<endl;
					directory[i].start=paused+1;
				}else{
					// cout<<"segment\n";
					segmentation();
					directory[i].start=0;
					paused=0;
				}
			}
		}
		
		l=directory[i].length;
		for(int j=directory[i].start;0<l;j++){
			counts[j]=directory[i].name;
			l--;
		}
		

		
		}
	


		int t=4;
		for(int i=0;i<30;i++){
			cout<<i<<"["<<counts[i]<<"]\t";
			if(i==t){
				t+=5;
				cout<<endl;
			}
		}
		cout<<endl;
	




	return 0;
}