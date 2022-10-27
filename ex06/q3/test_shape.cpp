#include "rectangle.h"
#include "disk.h"

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<Shape *> test;

    vector<Disk *> disks = {new Disk(), new Disk(Point(0, 0), 2)};
    vector<Rectangle *> rects = {new Rectangle(), new Rectangle(Point(0, 0), 2, 2)};
    vector<Shape *> test2;

    cout << "-----input-----" << endl;
    test.push_back(new Disk());
    test.push_back(new Disk(Point(0, 0), 2));
    test.push_back(new Rectangle());
    test.push_back(new Rectangle(Point(0, 0), 2, 2));
    cout << "-----result-----" << endl;
    for (size_t i = 0; i < test.size(); i++)
    {
        cout << i << endl;
        cout << "Name:" << test[i]->get_name() << endl;
        cout << "Area:" << test[i]->compute_area() << endl;
    }
    cout << endl;
    cout << "-----copied-----" << endl;
    test2.resize(test.size());
    for (size_t i = 0; i < test.size(); i++)
    {
        test2[i] = test[i];
    }

    test[1] = test[0]->clone();
    // test2.push_back(test[0]->clone());
    test[3] = test[2]->clone();
    // test2.push_back(test[2]->clone());
    cout << "-----result(test)-----" << endl;
    for (size_t i = 0; i < test.size(); i++)
    {
        cout << i << endl;
        cout << "Name:" << test[i]->get_name() << endl;
        cout << "Area:" << test[i]->compute_area() << endl;
    }
    cout << "-----result(test2)-----" << endl;
    for (size_t i = 0; i < test2.size(); i++)
    {
        cout << i << endl;
        cout << "Name:" << test2[i]->get_name() << endl;
        cout << "Area:" << test2[i]->compute_area() << endl;
    }
    return 0;
}