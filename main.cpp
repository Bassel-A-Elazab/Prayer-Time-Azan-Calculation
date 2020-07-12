#include <iostream>
#include <math.h>
#include <ctime>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979323846;

class PrayerTime{
private:
    double Long,Lat,timeZone,Height,GD,GN;
    int SH,dayOfYear;
    time_t getTime = time(0);
    tm *currentDate = localtime(&getTime);

public:
    PrayerTime(double newLong,double newLat,double newTimeZone,double newHeight,double newGD,double newGN,int newSH){
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
        return (radians*(180/PI));
    }
    double convertDegreesToRadians(double degrees){  //Function that convert degrees to radians.
        return (degrees*(PI/180));
    }

double *calculatePrayerTime(){
        double yearAngle,D,T,R,Z,U,VD,VN,W,Dawn,Sunrise,Noon,Afternoon,Sunset,Dusk;
        static double getPrayerTime[6];
        yearAngle = ((2*PI)*dayOfYear)/365;       //Calculate Year Angle.
        R = 15*timeZone;                                //Calculate Reference Longitude In Degrees.
        // Calculate Solar Declination In Degrees.
        D = convertRadiansToDegrees((0.006918 - (0.399912*cos(yearAngle))+(0.070257*sin(yearAngle)) - (0.0006758*cos(2*yearAngle))+(0.000907*sin(2*yearAngle)) - (0.002697*cos(3*yearAngle))+(0.001480*sin(2*yearAngle)) ));
        //Calculate Equation Of Time In Minutes.
        T = 229.18*(0.000075+(0.001868*cos(yearAngle)) - (0.032077*sin(yearAngle)) - (0.014615*cos(2*yearAngle))-(0.040849*sin(2*yearAngle)));

        Z = 12+((R-Long)/15)-(T/60);

        U = (180/(15*PI))*acos( (sin(convertDegreesToRadians((-0.8333-0.0347*sin(Height)*pow(abs(Height),0.05)))) - sin(convertDegreesToRadians(D)) * sin(convertDegreesToRadians(Lat))) / (cos(convertDegreesToRadians(D)) * cos(convertDegreesToRadians(Lat))) );

        VD = (180/(15*PI)) * acos( ( -sin(convertDegreesToRadians(GD)) - sin(convertDegreesToRadians(D)) * sin(convertDegreesToRadians(Lat)) ) / ( cos(convertDegreesToRadians(D)) * cos(convertDegreesToRadians(Lat)) ));

        VN = (180/(15*PI)) * acos( ( -sin(convertDegreesToRadians(GN)) - sin(convertDegreesToRadians(D)) * sin(convertDegreesToRadians(Lat)) ) / ( cos(convertDegreesToRadians(D)) * cos(convertDegreesToRadians(Lat)) ));

        W = (180/(15*PI)) * acos( (sin(atan(1/(SH+tan(convertDegreesToRadians(abs(Lat-D)))))) - sin(convertDegreesToRadians(D))) / ( cos(convertDegreesToRadians(D)) * cos(convertDegreesToRadians(Lat)) ));

        Dawn = Z - VD;                  //Prayer time 1
        getPrayerTime[0] = Dawn;

        Sunrise = Z-U;
        getPrayerTime[1] = Sunrise;

        Noon = Z;                       //Prayer time 2
        getPrayerTime[2] = Noon;

        Afternoon = Z+W;                //Prayer time 3
        getPrayerTime[3] = Afternoon;

        Sunset = Z+U;                   //Prayer time 4
        getPrayerTime[4] = Sunset;

        Dusk = Z+VN;                    //Prayer time 5
        getPrayerTime[5] = Dusk;
    return getPrayerTime;
    }

    void displayPrayerTime(){
        double *printPrayer = calculatePrayerTime();
        for(int i = 0; i < 6; i++){
            cout<<*(printPrayer+i)<<endl;
        }
    }
};
int main()
{

    return 0;
}
