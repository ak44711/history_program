//����������� 
//����β����ɾ���� 
#include<vector>
#include<iostream>

int main() {
	
	std::vector<int> v(3);
	v = {1,2,3};
	v.push_back(4);
	std::cout << v.capacity() << std::endl;
	
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	std::cout << v.capacity() << std::endl;
	return 0;
} 
