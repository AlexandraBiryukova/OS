#include <iostream>
#include <queue>
using namespace std;

int main(){
	int head,result=0,last;
	vector<int> q;
	queue<int> res;
	int n = -2;
	cout<<"Head: ";
	cin>>head;
	q.push_back(head);
	cout<<"Queue: ";
	cin>>n;
	last = head;
	while(n != -1){
		q.push_back(n);
		cin>>n;
	}
	q.push_back(0);
	sort(q.begin(),q.end());

	int start = 0;
	int end = q[q.size()-1] +16;
	q.push_back(end);
	for(int i=0;i<q.size();i++){
		if(q[i] == head){
			start = i;
		}
	}
	// cout<<(start);
	for(int i = start; i <q.size(); i++){
		int a = q[i];
		res.push(a);
		result += abs(a -last);
		last = a;
	}
	result+=end;
	for(int i = 0; i <start; i++){
		int a = q[i];
		res.push(a);
		result += abs(a -last);
		last = a;
	}
	
	while(!res.empty()){
		int a = res.front();
		if(res.size() > 1){
			cout<<a<<" -> ";
		}else{
			cout<<a<<endl;
		}
		res.pop();
	}
	cout<<"Total head movement: "<< result<<endl;






	return 0;
}