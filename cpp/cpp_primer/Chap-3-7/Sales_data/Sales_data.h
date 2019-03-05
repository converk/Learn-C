#include <iostream>
#include <string>

class Sales_data {
    //声明友元,使其可以访问私有的类的数据成员
    friend std::istream& read(std::istream& is, Sales_data& item);
    friend std::ostream& print(std::ostream& os, const Sales_data& item);

private:
    std::string bookNo; //书名
    unsigned units_sold = 0; //书卖了多少本
    double revenue = 0.0; //总共卖了多少钱
    double avg_price() const //计算单价
    {
        return units_sold == 0 ? 0 : revenue / units_sold;
    }
    /* data */
public:
    Sales_data() = default; //告诉编译器创建默认构造函数
    Sales_data(const std::string& s, unsigned n, double p)
        : bookNo(s)
        , units_sold(n)
        , revenue(n * p)
    {
    }
    std::string isbn() const //返回书名
    {
        return bookNo;
    }

    Sales_data& combine(const Sales_data&); //用来计算两个的和
};

Sales_data& Sales_data::combine(const Sales_data& rsh)
{
    units_sold += rsh.units_sold;
    revenue += rsh.revenue;
    return *this; //返回当前对象的引用
}

std::istream& read(std::istream& is, Sales_data& item)
{
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is; //返回输入流
}

std::ostream& print(std::ostream& os, const Sales_data& item)
{
    os << item.bookNo << " " << item.units_sold << " " << item.revenue << item.avg_price();
    return os; //返回输出流
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{ //将两个对象合在一起
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}