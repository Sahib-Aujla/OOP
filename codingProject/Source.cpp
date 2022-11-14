
#include <iostream>
using namespace std;

class Table {
    int area_;
    int height_;
public:
    Table() :area_{ 0 }, height_{ 0 }{}
    Table(int area, int height) :area_{ area }, height_{ height }{}

    void display() {
        cout << "(height:" << height_ << ", area: " << area_ << ")" << endl;
    }
    int getArea() const{ return area_; }
    int getHeight() const{ return height_; }

};

// TODO: implement areIdentical and operator== functions
bool areIdentical(const Table& t1, const Table& t2) {
    bool ok = false;
    if (t1.getArea() == t2.getArea()) ok = true;
    bool isOk = false;
    if (t1.getHeight() == t2.getHeight()) ok = true;

    return ok && isOk;
}
bool operator==(const Table& t1, const Table& t2) {
    bool ok = false;
    if (t1.getArea() == t2.getArea()) ok = true;
    bool isOk = false;
    if (t1.getHeight() == t2.getHeight()) ok = true;

    return ok && isOk;
}
int main()
{
    Table t1(101, 5), t2(100, 5);

    if (areIdentical(t1, t2))
        cout << "The tables are identical" << endl;
    else
        cout << "The tables are not identical" << endl;
    if (t1 == t2)
        cout << "The tables are identical" << endl;
    else
        cout << "The tables are not identical" << endl;
}