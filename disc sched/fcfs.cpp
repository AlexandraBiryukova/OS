#include <iostream>
#include <queue>
using namespace std;
int main(){
	int head,result=0,last;
	queue<int> q;
	queue<int> res;
	int n = -2;
	cout<<"Head: ";
	cin>>head;
	q.push(head);
	cout<<"Queue: ";
	cin>>n;
	last = head;
	while(n != -1){
		q.push(n);
		cin>>n;
	}
	while(!q.empty()){
		int a = q.front();
		res.push(a);
		result += abs(a -last);
		last = a;
		q.pop();
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