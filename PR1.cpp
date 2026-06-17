#include <iostream>
using namespace std;

class TimeConverter
{
public:
    int h, m, s, total;

    void secondsToTime()
    {
        cout << "Enter total seconds: ";
        cin >> total;

        h = total / 3600;
        m = (total % 3600) / 60;
        s = total % 60;

        cout << "HH:MM:SS => " << h << ":" << m << ":" << s << endl;
    }

    void timeToSeconds()
    {
        cout << "Enter hours: ";
        cin >> h;
        cout << "Enter minutes: ";
        cin >> m;
        cout << "Enter seconds: ";
        cin >> s;

        total = h * 3600 + m * 60 + s;

        cout << "Total seconds: " << total << endl;
    }
};

int main()
{
    TimeConverter t;
    t.secondsToTime();
    t.timeToSeconds();
}
/*output
Enter total seconds: 4200
HH:MM:SS => 1:10:0
Enter hours: 4
Enter minutes: 34
Enter seconds: 30
Total seconds: 16470
*/