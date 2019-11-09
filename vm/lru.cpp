#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

struct page_set
{
	int page;
	int last_use;
};

int main(){

	int n,p,count=0;
	vector<int> pages;
	cout<<"Print your reference string:\n( ends with -1 )\nPages: ";
	cin>>n;
	while(n!=-1){
		pages.push_back(n);
		cin>>n;
	}
	cout<<"How many pages can be in memory at a time per process?\nNumber of pages:";
	cin>>p;
	int size=pages.size();
	int final[size][p];
	vector<page_set> q;
	int cur_state = 0;
	int program_counter = 0;
	int page_faults = 0;

	for(int i=0;i<p;i++){
		for(int j=0;j<size;j++){
			final[j][i]=-1;
		}
			
	}

	for (int i = 0; i < pages.size(); i++){
			bool found = false;
			for (int j = 0; j < q.size(); j++){
				if(pages[i]==q[j].page){
					found = true;
					q[j].last_use = cur_state;
					cur_state += 1;
				}
			}
			if(found==false){
				if(q.size() < p){
					page_set p;
					p.page = pages[i];
					p.last_use = cur_state;
					q.push_back(p);
					cur_state += 1;
					page_faults += 1;
				}else{
					int num = q[0].last_use;
					int smallest_index = 0;
					for (int j = 0; j < q.size(); j ++){
						if(q[j].last_use < num){
							smallest_index = j;
							num = q[j].last_use;
						}
					}
					q[smallest_index].page = pages[i];
					q[smallest_index].last_use = cur_state;
					cur_state += 1;
					page_faults += 1;
				}

			for (int k = 0; k < q.size(); k++){
				final[i][k]=q[k].page;
			}
			
			
		}
		
			

			

		}

		for(int i=0;i<p;i++){
			for(int j=0;j<size;j++){
				if(final[j][i]!=-1){
					cout<<final[j][i]<<"  ";
				}else{
					cout<<"   ";
				}
			}
			cout<<endl;
		}
	
	cout << "Page Faults: "<<page_faults << '\n';




	return 0;
}