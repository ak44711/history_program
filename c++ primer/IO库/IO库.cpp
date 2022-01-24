#include<iostream>	//对可见域的操作 常见的为屏幕 
#include<fstream>	//文件 
#include<sstream>	//对内存的操作 
#include<string>	

int main() {
	std::cout << "this is string\n";
	
	//std::ofstream ofs("1.txt");//自动打开，无需open 
	//std::ofstream ofs("1.txt", std::ofstream::out);	//第二个参数为使用文件的模式,覆盖之前的内容
	std::ofstream ofs("1.txt", std::ofstream::app);	//第二个参数为使用文件的模式,追加写入  
	/*文件模式 mode
	 std::fstream obj(filename, mode)
	 *in 		以读方式打开 
	 *out		以写方式打开 
	 *app		以追加写入模式打开 
	 *ate		打开文件后立刻定为到文件末尾 
	 *trunc		截断文件 
	 *bindary	以二进制方式进行io 
	*/ 
	
	//ofs << "helloworld" << std::endl;//以流的形式向文件写入内容 
	//ofs.close();//关闭文件 
	
	for(int i = 0; i < 10; i++){//向文件写入10行内容 
		ofs << __TIME__ << "helloworld - " << i << '\n';
	}
	
	ofs.close();//关闭文件 
	
	std::string ifile = "1.txt";
	std::ifstream in(ifile);
	
	return 0;
} 
