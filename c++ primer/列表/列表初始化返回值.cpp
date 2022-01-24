#include<iostream> 
#include<vector> 
#include<string>

using namespace std;

vector<string> process()
{
	string expected = "sa";
	string actual = "sb";
	if(expected.empty()){
		return {};
	}else if(expected == actual){
		return {"functionX", "okay"};
	}else{
		return {"functionX",expected, actual};
	}
}

int main() {
	vector<string> v = process();
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << endl;
	}
	
	return 0;
}
