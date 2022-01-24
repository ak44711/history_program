#include<iostream>
#include<set>

using namespace std; 

typedef struct stu{
	int num;
	int age;
	students() {}
	stu(int n, int a) {
		num = n;
		age = a;
	}
	bool operator <(const struct stu& s) const{
		if(this ->age != s.age){
			return this ->age < s.age;
		}else{
			return this ->num < s.num;
		}
	}
	bool operator ()(const struct stu&s1, const struct stu& s2) const {
		if(s1.age != s2.age) {
			return s1.age < s2.age;
		}else{
			return s1.num < s2.num;
		}
	}
}stu;

int main(){
	set<stu> s;
	s.insert(stu(104,21));
	s.insert(stu(101,21));
	s.insert(stu(102,22));
	s.insert(stu(103,23));
	s.insert(stu(106,51));
	for(set<stu>::iterator it = s.begin(); it != s.end(); it++) {
		cout << it ->num << " " << it ->age << endl;
	}
	
	return 0;
} 
