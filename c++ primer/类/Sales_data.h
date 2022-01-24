
#include <iostream>
#include <string>
 
class Sales_data
{
    //声明友元函数
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
public:
    //构造函数
    Sales_data ()://书上有个Sales_data () = default;的语句，不知道为啥我放在这里编译时就报错，无奈，去掉了
        bookNo(" "), units_sold(0), revenue(0) {}
    Sales_data(std::istream &is)//按照书上，这个是用来练习在类外部定义构造函数，课时我出错了，就把他放到类里面了
    {
        read(is, *this);
    }
 
    std::string isbn() const {return bookNo;}//返回isbn
    Sales_data& combine(const Sales_data&);//声明combine函数，函数功能是吧isbn相同的书的数据加到一块
    double avg_price() const//求平均价格，书上232页定义在了类的外部，240页又定义在了类的内部。。。我是定义在了内部
    {
        return units_sold ? revenue/units_sold : 0;
    }
private:
    std::string bookNo;//isbn
    unsigned units_sold = 0;//卖出的书的册数
    double revenue = 0.0;//总收益
};

//虽然类中声明了友元关系，但是函数还必须声明 
Sales_data add(const Sales_data&, const Sales_data&);//接受两个Sales_data对象，返回一个新的Sales_data对象，表示前两个对象之和
std::ostream &print(std::ostream&, const Sales_data&);//将数据读取到对象中
std::istream &read(std::istream&, Sales_data&);//将对象的内容打印到给定的流中
 
Sales_data& Sales_data::combine(const  Sales_data &rhs)//在类的外部定成员函数
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;//返回一个this对象
}

std::istream &read(std::istream &is, Sales_data &item)//额外引用实参接受输入 
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
