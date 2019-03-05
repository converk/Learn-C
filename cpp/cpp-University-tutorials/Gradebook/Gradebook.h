#include <string>

class Gradebook {
private:
    std::string coursename;
    int maxGrade;
    /* data */
public:
    explicit Gradebook(std::string);
    void set_coursename(std::string);
    std::string get_coursename() const;
    void displayMessage() const;
    void deterclassaverage() const;
    void inputGrades(); //输入三个成绩
    void displayGradeReport() const; //展示成绩报告
    int maximum(int, int, int) const; //计算三个的最大值
};
