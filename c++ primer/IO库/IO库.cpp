#include<iostream>	//�Կɼ���Ĳ��� ������Ϊ��Ļ 
#include<fstream>	//�ļ� 
#include<sstream>	//���ڴ�Ĳ��� 
#include<string>	

int main() {
	std::cout << "this is string\n";
	
	//std::ofstream ofs("1.txt");//�Զ��򿪣�����open 
	//std::ofstream ofs("1.txt", std::ofstream::out);	//�ڶ�������Ϊʹ���ļ���ģʽ,����֮ǰ������
	std::ofstream ofs("1.txt", std::ofstream::app);	//�ڶ�������Ϊʹ���ļ���ģʽ,׷��д��  
	/*�ļ�ģʽ mode
	 std::fstream obj(filename, mode)
	 *in 		�Զ���ʽ�� 
	 *out		��д��ʽ�� 
	 *app		��׷��д��ģʽ�� 
	 *ate		���ļ������̶�Ϊ���ļ�ĩβ 
	 *trunc		�ض��ļ� 
	 *bindary	�Զ����Ʒ�ʽ����io 
	*/ 
	
	//ofs << "helloworld" << std::endl;//��������ʽ���ļ�д������ 
	//ofs.close();//�ر��ļ� 
	
	for(int i = 0; i < 10; i++){//���ļ�д��10������ 
		ofs << __TIME__ << "helloworld - " << i << '\n';
	}
	
	ofs.close();//�ر��ļ� 
	
	std::string ifile = "1.txt";
	std::ifstream in(ifile);
	
	return 0;
} 
