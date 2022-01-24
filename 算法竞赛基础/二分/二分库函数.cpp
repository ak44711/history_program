#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
int main() {
	vector<int> v;
	//v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(5) ;
	v.push_back(2);
	v.push_back(1);
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	} 
	cout << endl << endl;
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	} 
	cout << endl << endl;
	/*
	cout << "binary_search: " << binary_search(v.begin(), v.end(), 2) << endl;//返回true or false 
	cout << "lower_bound: " << lower_bound(v.begin(), v.end(), 2) - v.begin()<< endl;//lower_bound返回迭代器
	cout << "upper_bound: " << upper_bound(v.begin(), v.end(), 2) - v.begin()<< endl;//lower_bound返回迭代器
	cout << lower_bound(v.begin(), v.end(), 2) - v.begin()<< endl;//输出被查找数的下标 
	*/
	cout << "lower_bound: " << lower_bound(v.begin(), v.end(), 1) - v.begin() << endl;//lower_bound返回迭代器,找不到返回尾后 
																						//所找的值小于有序容器最小的，返回begin
																						//所找的值大于有序容器最大的，返回end 
																						//找到之后返回小于等于目标值最大元素的迭代器 
	cout << "upper_bound: " << upper_bound(v.begin(), v.end(), 3) - v.begin() << endl;	//lower_bound返回迭代器
																						//所找的值小于有序容器最小的，返回begin
																						//所找的值大于有序容器最大的，返回end
																						//找到之后返回比目标值大的最小元素的迭代器 
	cout << "bin_search: " <<  binary_search(v.begin(), v.end(), 3) << endl;// bool binary_search
	cout << "lower_bound - upper_bound: " << upper_bound(v.begin(), v.end(), 1) - lower_bound(v.begin(), v.end(), 1) << endl;//返回顺序容器中目标值的个数 
	cout << *v.end() << endl;
	return 0;
}
