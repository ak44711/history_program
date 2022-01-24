
#include <iostream>
#include <string>
 
class Sales_data
{
    //������Ԫ����
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
public:
    //���캯��
    Sales_data ()://�����и�Sales_data () = default;����䣬��֪��Ϊɶ�ҷ����������ʱ�ͱ������Σ�ȥ����
        bookNo(" "), units_sold(0), revenue(0) {}
    Sales_data(std::istream &is)//�������ϣ������������ϰ�����ⲿ���幹�캯������ʱ�ҳ����ˣ��Ͱ����ŵ���������
    {
        read(is, *this);
    }
 
    std::string isbn() const {return bookNo;}//����isbn
    Sales_data& combine(const Sales_data&);//����combine���������������ǰ�isbn��ͬ��������ݼӵ�һ��
    double avg_price() const//��ƽ���۸�����232ҳ������������ⲿ��240ҳ�ֶ�����������ڲ����������Ƕ��������ڲ�
    {
        return units_sold ? revenue/units_sold : 0;
    }
private:
    std::string bookNo;//isbn
    unsigned units_sold = 0;//��������Ĳ���
    double revenue = 0.0;//������
};

//��Ȼ������������Ԫ��ϵ�����Ǻ������������� 
Sales_data add(const Sales_data&, const Sales_data&);//��������Sales_data���󣬷���һ���µ�Sales_data���󣬱�ʾǰ��������֮��
std::ostream &print(std::ostream&, const Sales_data&);//�����ݶ�ȡ��������
std::istream &read(std::istream&, Sales_data&);//����������ݴ�ӡ������������
 
Sales_data& Sales_data::combine(const  Sales_data &rhs)//������ⲿ����Ա����
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;//����һ��this����
}

std::istream &read(std::istream &is, Sales_data &item)//��������ʵ�ν������� 
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
 
std::ostream &print(std::ostream &os,const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold
        << " " << item.revenue << " " << item.avg_price();
    return os;
}
 
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
