#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

class PrayerTime{
private:
    double Long,Lat,timeZone,H,GD,GN;
    int SH,dayOfYear;
    time_t getTime = time(0);
    tm *currentDate = localtime(&getTime);

public:
    PrayerTime(double newLong,double newLat,double newTimeZone,double newH,double,double newGD,double newGN,int newSH){
        Long = newLong;
        Lat = newLat;
        timeZone = newTimeZone;
        H = newH;
        GD = newGD;
        GN = newGN;
        SH = newSH;
        dayOfYear = currentDate->tm_yday;
    }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
