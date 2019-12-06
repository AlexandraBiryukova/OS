#include <iostream>
#include <queue>
using namespace std;
struct node{
	int number;
	int next_n;
	bool found;
};
vector<node> q;



void find_next(node x){
	int el = x.number;
	int next_n = x.next_n;
	int c =0;
	int cnt=0;
	for(int i=0;i< q.size();i++){
		if(q[i].number == x.number){
			cnt = i;
		}else{
			if(!q[i].found){
				if(abs(q[i].number-el) < abs(el-next_n)){
					next_n = q[i].number;
					c = i;
				// cout<<next_n<<" "<<abs(q[i].number-el)<<"--";
				}
			}

		}
		
	}
	q[c].found = true;
	q[cnt].next_n =next_n;
	// cout<<endl<<el<<" -> ";
	// return next_n;


}

int main(){
	int h,result=0,last;
	queue<int> res;
	int n = -2;
	cout<<"Head: ";
	cin>>h;
	node head;
	head.number = h;
	head.found = true;
	head.next_n = 10000;
	q.push_back(head);
	cout<<"Queue: ";
	cin>>n;
	last = head.number;
	while(n != -1){
		node el;
		el.number = n;
		el.found = false;
		el.next_n = 10000;
		q.push_back(el);
		cin>>n;
	}
	int  s = 0,cnt =0;
	vector<int> q2;
	q2.push_back(q[0].number);
	while(cnt!=q.size()-1){
		find_next(q[s]);
		q2.push_back(q[s].next_n);
		for(int i=0;i<q.size();i++){
			if(q[i].number==q[s].next_n){
				s=i;
				break;
			}
		}
		cnt++;

	}
		

	for(int i = 0; i <q2.size(); i++){
		int a = q2[i];
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