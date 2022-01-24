#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct cost{
	int size;
	int weight;
}; 

bool cmp(struct cost c1, struct cost c2){
	return c1.weight < c2.size;
}

int main(){
	int n;
	cin >> n;
	int size;
	int t;
	struct cost c;
	vector<struct cost> v;
	for(int i = 0; i < n; i++){
		cin >> size;
		c.size = size;
		for(int j = 0; j < size; j++){
			cin >> t;
		}
		v.push_back(c);
	}
	int weight;
	for(int i = 0; i < n; i++){
		cin >> weight;
		v[i].weight = weight;
	}
	sort(v.begin(), v.end(), cmp);
	int total_size = 0;
	int i = 0;
	int total_cost = 0;
	while(i < n){
		if(v[i].weight >= 0 && total_size >= n){
			break;
		}
		total_size += v[i].size;
		total_cost += v[i].weight;
		i++;
	}
	cout << i << " n : " << n << " " << total_cost << " " << total_size << endl;
	if(total_size < n || total_cost >= 0){
		cout << 0 << endl;
	}else{
		cout << total_cost << endl;
	}
	return 0;
}
