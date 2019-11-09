#include <iostream>
#include <vector>
using namespace std;
struct element{
	int pageID;
	int frameID;
};
int n=6,pn=12;


int main(){
	element TLB[n];
	element pageTable[pn];
	int count=0;
	for(int i=0;i<n;i++){
		if(i<3){
			TLB[i].pageID=i+1;
			TLB[i].frameID=i+2;
		}else{
			TLB[i].pageID=-1;
			TLB[i].frameID=-1;
		}
	}
	for(int i=0;i<pn;i++){
		pageTable[i].pageID=i+1;
		pageTable[i].frameID=i+2;
	}

	int p=0;
	while(p!=-1){
		cout<<"Page ID\tFrame ID\n";
		for(int i=0;i<n;i++){
			cout<<TLB[i].pageID<<"\t"<<TLB[i].frameID<<"\n";
		}
		int d=-1,f=-1;
		cout<<"Logical address:\np: ";
		cin>>p;
		if(p==-1){
			break;
		}
		cout<<"\nd: ";
		cin>>d;
		bool found=false,replaced=false;
		for(int i=0;i<n;i++){
			if(TLB[i].pageID==p){
				f=TLB[i].frameID;
				found=true;
				cout<<"TAKEN FROM TLB\n";
				break;

			}
		}
		if(!found){
			for(int i=0;i<pn;i++){
				if(pageTable[i].pageID==p){
					f=pageTable[i].frameID;
					found=true;
					cout<<"TAKEN FROM PAGE TABLE\n";
					for(int i=0;i<n;i++){
						if(TLB[i].pageID==-1){
							TLB[i].pageID=p;
							TLB[i].frameID=f;
							replaced=true;
							cout<<"ADDED ELEMENT TO TLB\n";
							break;

						}
					}
					if(!replaced){
						cout<<"REPLACED ELEMENT IN TLB\n";
						TLB[count].pageID=p;
						TLB[count].frameID=f;
						count=(count+1)%n;
					}

					break;
				}

			}
		}
		if(found){
			cout<<"Physical address:\nf: "<<f<<"\nd: "<<d<<endl;
		}else{
			cout<<"We can't fing physical address\n";
		}
}



}