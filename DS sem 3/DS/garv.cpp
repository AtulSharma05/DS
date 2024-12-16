#include<iostream>
using namespace std;
class user{
public:
string username;
string password;

};
class passenger{
public:
string name;
int age;
string gender;
string seatprefernece;
double mobileno;
string mailid;
};
class ticket : public passenger{
public:
double trainno;
double tickectno;
string bookingdate;
string dateofjourneyandtime;
string arrivaldateandtime;
double price;
string seatno;
string coach;
string classs;
string quota;
string originstation;
string finalstation;
};
class station{
    
};
class train : public ticket{





};
