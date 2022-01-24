#include<iostream>
#include<string>

using namespace std;
using uint = unsigned int;

struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main() {
	Sales_data data1, data2;
	double price = 0;
	//0-201-78345-X 3 20.00
	cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;
	//0-201-78345-X 2 25.00
	cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;
	
	if (data1.bookNo == data2.bookNo) {
		uint totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;
		//0-201-78345-X 5 110 22
		cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
		if (totalCnt != 0) {
			cout << totalRevenue / totalCnt << endl;
		}else{
			cout << "(no sales)" << endl;
		}
		return 0;
	} else {
		cerr << "Data must refer to the same ISBN" << endl;
		return -1;
	}

}
