#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string counts[30];
struct Node { 
   int data; 
   struct Node *next; 
}; 

struct file{
	string name;
	int start;
	int end;
	int blocks[5];
	struct Node* head; 
};

int randomly(){
	int r=random()%29;
	while(counts[r]!=" "){
		r=random()%29;
	}
	return int(r);	
}

 
Node* insert(int new_data,Node* head) { 
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
   new_node->data = new_data; 
   new_node->next = head; 
   head = new_node; 
   return new_node;
} 
void display(Node* head) { 
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) { 
      cout<< ptr->data <<" "; 
      ptr = ptr->next; 
   } 
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
		cout<<"File end: ";
		cin>>f.end;
		f.head=NULL;
		directory.push_back(f);

	}
	cout<<endl;



	for(int i=0;i<directory.size();i++){
		if(counts[directory[i].start]!=" "){
			directory[i].start=randomly();
		}
		counts[directory[i].start]=directory[i].name;
		directory[i].head=insert(directory[i].start,directory[i].head);
		int r=randomly();
		for(int j=0;j<3;j++){
			r=randomly();
			while(r==directory[i].start){
				r=randomly();
			}
			directory[i].head=insert(r,directory[i].head);
			counts[r]=directory[i].name;
		}
		if(counts[directory[i].end]!=" "){
			directory[i].end=randomly();
		}
		directory[i].head=insert(directory[i].end,directory[i].head);
		counts[directory[i].end]=directory[i].name;
		
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

		for(int i=0;i<directory.size();i++){
			cout<<directory[i].name<<": ";
			display(directory[i].head);
			cout<<endl;
		}
	




	return 0;
}