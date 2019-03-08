#ifndef TIME_H
#define TIME_H

class Time {
public:
    Time(); //构造函数
    void setTime(int, int, int);
    void prtUniversal() const; //24小时
    void prtStandart() const; //12小时
private:
    unsigned hour;
    unsigned min;
    unsigned sec;
};

#endif