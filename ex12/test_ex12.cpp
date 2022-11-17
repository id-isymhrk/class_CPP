#include "MyHeader.h"
#include <vector>

void ShowPoints(vector<Point *> test);
void ShowCompare(bool flag);

int main()
{
    vector<Point *> test_point;
    test_point.push_back(new Point());
    test_point.push_back(new Point(1.0, 1.0, 1.0));
    ShowPoints(test_point);

    cout << "---compare---" << endl;
    ShowCompare(Compare(*test_point[1], *test_point[0]));

    return 0;
}

void ShowPoints(vector<Point *> test_point)
{
    for (size_t i = 0; i < test_point.size(); i++)
    {
        cout << "No." << i << ":" << test_point[i]->x
             << " " << test_point[i]->y
             << " " << test_point[i]->z << endl;
    }
}
void ShowCompare(bool b)
{
    if (b)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}