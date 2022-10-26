#include "rectangle.h"
#include "disk.h"

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<Shape *> test;

    cout << "-----input-----" << endl;
    test.push_back(new Disk());
    test.push_back(new Disk(Point(0, 0), 2));
    test.push_back(new Rectangle());
    test.push_back(new Rectangle(Point(0, 0), 2, 2));
    cout << "-----result-----" << endl;
    for (size_t i = 0; i < test.size(); i++)
    {
        cout << "Name:" << test[i]->get_name() << endl;
        cout << "Area:" << test[i]->compute_area() << endl;
    }
    return 0;
}