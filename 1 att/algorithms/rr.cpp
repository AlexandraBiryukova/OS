#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct process{
	int id;
	int burst_time;
	int arr_time;
	int priority;

};

int main(){
	vector <process> q;
	vector <process> f;
	vector <process> q_copy;
	while(true){
		process p;
		cin >> p.id;
		if (p.id == 0) {
			break;
		}
		cin >> p.burst_time>>p.arr_time>>p.priority;
		q.push_back(p);
	}
	int quantum;
	cout<<"Quantum: ";
	cin>>quantum;
	q_copy=q;

while(!q.empty())
	for(int i=0;i<q.size();i++){
		if(q[i].burst_time>quantum){
			process p;
			p.id=q[i].id;
			p.burst_time=quantum;
			f.push_back(p);
			q[i].burst_time-=quantum;
		}else{
			f.push_back(q[i]);
			q.erase(q.begin()+i);
							i--;
			
		}

	}
	
	int n = f.size()+1;
	int w[n];
	w[0] = 0;
	int i = 1;
	
	
	while(i <= f.size()){
		process p = f[i-1];
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
			cout << ss << "P" << f[i].id << ss;
			
		}
	}
	cout<<endl<<s<<endl;
	vector<int> cur_time_proc;

	for (int i = 0; i < n - 1; i++){
		for(int j = 0; j < (w[i+1] - w[i]); j++){
			// cur_time_proc.push_back(f[].id);
			cur_time_proc.push_back(f[i].id);
			// cout << f[i].id << " ";
		}
		// cout << w[i] << " ";
	}

	// cout << endl;
	// for (int i = 0; i < q_copy.size(); i++){
	// 	cout << q_copy[i].id << " ";
	// }
	// cout << endl;


	vector<int> waits;
	int smm = 0;
	for (int i = 0; i < q_copy.size(); i++){
		int cur_process_id = q_copy[i].id;
		int cur_process_wait_time = 0;

		int last_appear = 0;

		for (int j = 0; j < cur_time_proc.size(); j++){
			if(cur_time_proc[j] == cur_process_id){
				last_appear = j;
			}
		}
		// cout <<"last_appear:"<< last_appear;

		for (int j = 0; j < last_appear; j++){
			if (cur_process_id != cur_time_proc[j]){
				cur_process_wait_time ++;
			}
		}
		waits.push_back(cur_process_wait_time);
		smm += cur_process_wait_time;
		// cout << cur_process_wait_time << " ";
	}
	// cout << endl;
	// cout << smm;
	cout << "Average waiting time: (";
	for (int i = 0; i < waits.size(); i++){
		if(i!=waits.size()-1){
			cout << waits[i] << "+";	
		}else{
			cout << waits[i] << ")/" << waits.size() << " = " << smm / waits.size() << endl;
		}
		
	}
	

	

	return 0;

}