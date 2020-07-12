#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

class PrayerTime{
private:
    double Long,Lat,timeZone,Height,GD,GN;
    int SH,dayOfYear;
    time_t getTime = time(0);
    tm *currentDate = localtime(&getTime);

public:
    PrayerTime(double newLong,double newLat,double newTimeZone,double newHeight,double,double newGD,double newGN,int newSH){
        Long = newLong;
        Lat = newLat;
        timeZone = newTimeZone;
        Height = newHeight;
        GD = newGD;
        GN = newGN;
        SH = newSH;
        dayOfYear = currentDate->tm_yday;
    }
    //Set & Get Longitude Of Your Country
    void setLong(double newLong){
        Long = newLong;
    }
    double getLong(){
        return Long;
    }
    //Set & Get latitude Of Your Country
    void setLat(double newLat){
        Lat = newLat;
    }
    double getLat(){
        return Lat;
    }
    //Set & Get Time Zone Of Your Country
    void setTimeZone(double newTimeZone){
        timeZone = newTimeZone;
    }
    double getTimeZone(){
        return timeZone;
    }
    //Set & Get Height Above See Of Your Country
    void setHeight(double newHeight){
        Height = newHeight;
    }
    double getHeight(){
        return Height;
    }
    //Set & Get Dawn’s Angle Twilight Of Your Country
    void setGD(double newGD){
        GD = newGD;
    }
    double getGD(){
        return GD;
    }
    //Set & Get Night’s Twilight Angle Of Your Country
    void setGN(double newGN){
        GN = newGN;
    }
    double getGN(){
        return GN;
    }
    //Set And Get The Choice Of Your Mazhab.
    void setSH(double newSH){
        SH = newSH;
    }
    double getSH(){
        return SH;
    }

    double convertRadiansToDegrees(double radians){  //Function that convert radians to degrees.
        return (radians*(180/M_PI));
    }
    double convertDegreesToRadians(double degrees){  //Function that convert degrees to radians.
        return (degrees*(M_PI/180));
    }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
