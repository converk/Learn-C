#include <string>

class Gradebook {
private:
    std::string coursename;
    /* data */
public:
    explicit Gradebook(std::string);
    void set_coursename(std::string);
    std::string get_coursename() const;
    void displayMessage() const;
    void deterclassaverage() const;
};
