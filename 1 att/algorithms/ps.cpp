#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct process{
	int id;
	int burst_time;
	int arr_time;
	int priority;

	

};
bool compare (process a, process b)
{
    if(a.arr_time == b.arr_time) 
{ 
return a.priority<b.priority; 
} 
else
{ 
    return a.arr_time<b.arr_time; 
} 
}


int main(){
	vector<process> q;
	while(true){
		process p;
		cin >> p.id;
		if (p.id == 0) {
			break;
		}
		cin >> p.burst_time;
		cin >>p.arr_time;
		cin>>p.priority;
		q.push_back(p);
	}




	
	sort(q.begin(), q.end(), compare);
	int n = q.size()+1;
	int w[n];
	w[0] = 0;
	int i = 1;
	float average = 0;
	while(i <= q.size()){
		process p = q[i-1];
		w[i] = w[i-1] + p.burst_time;
		i++;
	}

	string s ="";
	for(int i =0 ;i < n;i++){
		s+=to_string(w[i]);
		if(i != n-1){
			int y = w[i+1] - w[i];
			s+= string(y,'-');
			
		}
	}
	cout << string(s.length(),'-')<<endl;
	for(int i =0 ;i < n;i++){
		
		if(i != n-1){
			int y = w[i+1] - w[i];
			string ss = string(y/2,' ');
			cout << ss << "P" << q[i].id << ss;
			average += w[i];
		}
	}
	cout<<endl<<s;
	cout << "\nWaiting time for ";
	for(int i = 0;i < n-1;i++){
		cout << "P" << q[i].id << " = " << w[i] << "; ";
	}
	cout<< "\nAverage waitng time: " << average/(n-1) << endl;
	return 0;

}