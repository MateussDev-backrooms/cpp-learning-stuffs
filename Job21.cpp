#include <iostream>
#include <cmath>
#include <cstdlib>  
#include <ctime>    

using namespace std;

int main()
{
    srand(time(0)); 

    double x1 = -15;
    double y1  = rand() % 14;
    double x2 = 45;
    double y2 = rand() % 14;
    double dir1 = 1;
    double dir2 = -1;
    double r1 = 4 + rand() % 8;
    double r2 = 4 + rand() % 8;

    for(double n = 0; n < 60; n++) {
        x1 += dir1;
        x2 += dir2;

        for(double i = 0; i < 14; i++) {
            for(double j = 0; j < 30; j++) {
                double dist1 = sqrt((i-y1)*(i-y1)*3.4 + (j-x1)*(j-x1));
                double dist2 = sqrt((i-y2)*(i-y2)*3.4 + (j-x2)*(j-x2));

                if(dist1 < r1) {
                    cout << "🟦";
                } else if(dist2 < r2) {
                    cout << "🟥";
                } else {
                    cout << " ";
                }

                double dist3 = sqrt((y2-y1)*(y2-y1)*3.4 + (x2-x1)*(x2-x1));
                if(dist3 < r1 + r2) {
                    dir1 = -1;
                    dir2 = 1;
                }
            }
            cout << endl;
        }
    }

    return 0;
}

