#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string counts[30];
struct file{
	string name;
	int index_block;
	int blocks[5];
};

int randomly(){
	int r=random()%29;
	while(counts[r]!=" "){
		r=random()%29;
	}
	cout<<"Random: "<<int(r)<<endl;
	return int(r);	
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
		cout<<"File index block: ";
		cin>>f.index_block;
		cout<<"File blocks (5): ";
		for(int i=0;i<5;i++){
			cin>>f.blocks[i];
		}
		directory.push_back(f);

	}
	cout<<endl;
	for(int i=0;i<directory.size();i++){
		if(counts[directory[i].index_block]!=" "){
			directory[i].index_block=randomly();
		}
		counts[directory[i].index_block]=directory[i].name;
		for(int j=0;j<5;j++){
			if(directory[i].blocks[j]!=-1){
				if(counts[directory[i].blocks[j]]!=" "){
					int r=randomly();
					while(r==directory[i].index_block){
						r=randomly();
					}
					directory[i].blocks[j]=r;
				}
				counts[directory[i].blocks[j]]=directory[i].name;
			}
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