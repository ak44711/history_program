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
	cout << "binary_search: " << binary_search(v.begin(), v.end(), 2) << endl;//����true or false 
	cout << "lower_bound: " << lower_bound(v.begin(), v.end(), 2) - v.begin()<< endl;//lower_bound���ص�����
	cout << "upper_bound: " << upper_bound(v.begin(), v.end(), 2) - v.begin()<< endl;//lower_bound���ص�����
	cout << lower_bound(v.begin(), v.end(), 2) - v.begin()<< endl;//��������������±� 
	*/
	cout << "lower_bound: " << lower_bound(v.begin(), v.end(), 1) - v.begin() << endl;//lower_bound���ص�����,�Ҳ�������β�� 
																						//���ҵ�ֵС������������С�ģ�����begin
																						//���ҵ�ֵ���������������ģ�����end 
																						//�ҵ�֮�󷵻�С�ڵ���Ŀ��ֵ���Ԫ�صĵ����� 
	cout << "upper_bound: " << upper_bound(v.begin(), v.end(), 3) - v.begin() << endl;	//lower_bound���ص�����
																						//���ҵ�ֵС������������С�ģ�����begin
																						//���ҵ�ֵ���������������ģ�����end
																						//�ҵ�֮�󷵻ر�Ŀ��ֵ�����СԪ�صĵ����� 
	cout << "bin_search: " <<  binary_search(v.begin(), v.end(), 3) << endl;// bool binary_search
	cout << "lower_bound - upper_bound: " << upper_bound(v.begin(), v.end(), 1) - lower_bound(v.begin(), v.end(), 1) << endl;//����˳��������Ŀ��ֵ�ĸ��� 
	cout << *v.end() << endl;
	return 0;
}
