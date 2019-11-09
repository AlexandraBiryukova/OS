#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <set>

using namespace std;

struct process
{
	string id;
	int arrival_time;
	int burst_time;
	int on;
	int all_time;

	// bool operator<(const process& t) const
 //    { 
 //        return (this->arrival_time < t.arrival_time); 
 //    } 
};

bool sort_struct(process p1, process p2){
	return p1.burst_time < p2.burst_time;
}

bool sort_arrive(process p1, process p2){
	return p1.arrival_time < p2.arrival_time;
}

int main(){

	// multiset<struct process> pr;
	// multiset<struct process>::iterator it;
	cout << '\n';
	vector<process> pr;
	// process p;
	// cin >> p.id;
	// if(p.id=="0"){
	// 	return 0;
	// }
	// cin >> p.arrival_time >> p.burst_time;
	// pr.insert(p);
	int mx_arrival = 0;
	while(true){
		process p;
		cin >> p.id;
		if(p.id=="0"){
			break;
		}
		cin >> p.arrival_time >> p.burst_time;
		mx_arrival += p.burst_time;

		p.on = 0;
		p.all_time = p.burst_time;
		// p.start_time = 0;
		// mx_arrival = max(p.arrival_time, mx_arrival);		
		pr.push_back(p);
		// pr.insert(p);
	}
	// cout << mx_arrival << endl;

	sort(pr.begin(), pr.end(), sort_arrive);

	vector<string> ids;
	vector<int> counts;

	string prev_id = "";

	for (int i = 0; i < mx_arrival; i++){

		sort(pr.begin(), pr.end(), sort_arrive);
		int cur_index = 0;
		int minimal_value = 1000;

		for (int j = 0; j < pr.size(); j++){
			if(pr[j].arrival_time <= i){
				if(pr[j].burst_time!=0){
					pr[j].on += 1;
				}
				if (pr[j].burst_time <= minimal_value && pr[j].burst_time!=0){
					cur_index = j;
					minimal_value = pr[j].burst_time;
				}
			}
		}
		// pr[cur_index].arrival_time += 1;
		pr[cur_index].burst_time -= 1;

		if (prev_id == pr[cur_index].id){
			counts[counts.size()-1] += 1;
		}else{
			prev_id = pr[cur_index].id;
			ids.push_back(prev_id);
			counts.push_back(1);
		}
		// cout << pr[cur_index].id << " " << cur_index << " " << minimal_value << endl;	
		
	}

	cout << "0---";
	int tm = 0;
	for (int i = 0; i < ids.size(); i++){
		tm+= counts[i];
		cout << ids[i] << "---" << tm << "---";
	}
	cout << endl;

	float av = 0;

	cout << "Average waiting time: ";

	for (int i = 0;i < pr.size(); i++){
		if(i<pr.size()-1){
			av = av + (pr[i].on - pr[i].all_time);
			cout << "(" << pr[i].on << "-" << pr[i].all_time << ") + ";	
		}else{
			av = av + (pr[i].on - pr[i].all_time);
			cout << "(" << pr[i].on << "-" << pr[i].all_time << ")/" << pr.size() << " = " << av << "/" << pr.size() << "=" << av/pr.size() << '\n' << '\n';
		}
		
	}

  




	return 0;
}