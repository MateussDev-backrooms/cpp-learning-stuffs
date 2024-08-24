#include <iostream>
#include <cmath>
using namespace std;

double lineLength(double x1, double y1, double x2, double y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = lineLength(x1, y1, x2, y2);
    double b = lineLength(x2, y2, x3, y3);
    double c = lineLength(x3, y3, x1, y1);
    double SP = (a+b+c)/2;

    return sqrt(SP*(SP-a)*(SP-b)*(SP-c));
}

int main()
{
    double x1, y1;
    double x2, y2;
    double x3, y3;

    cout << "Insert the locations of the points of the triangle: \n";
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    cout << "Insert the point to check if it's inside the triangle: \n";
    int xa, ya;
    cin >> xa >> ya;

    //collision

    //idea - calculate the area of the triangles with one of the edges being the test point
    //then compare it to the area of the whole triangle
    //if the combined area of the smaller triangles is equal to the whole triangle, then
    //the point is inside. Otherwise, it is outside

    double area1, area2, area3;
    double areaWhole;

    area1 = triangleArea(x1, y1, x2, y2, xa, ya);
    area2 = triangleArea(x2, y2, x3, y3, xa, ya);
    area3 = triangleArea(x3, y3, x1, y1, xa, ya);
    areaWhole = triangleArea(x1, y1, x2, y2, x3, y3);

    if((area1+area2+area3)==areaWhole) {
        cout << "Point is inside of the triangle";
    } else {
        cout << "Point is outside the triangle";
    }

    return 0;
}