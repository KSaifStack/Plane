#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
using namespace std;
struct Location {
    string name;
    double lat;
    double lon;
};
//void removestrs
void removestrs(vector<Location>& list, int index){
    vector<Location> nlist;
    for(int i=0;i<list.size();i++){
        if(i+1!=index){
            nlist.push_back(list[i]);
        }
    }
    list=nlist;
}
//double haversine
double haversine(double lat1, double long1, double lat2, double long2, double radius){
double rad =  M_PI / 180.0;
lat1=lat1*rad;
lat2=lat2*rad;
long1=long1*rad;
long2=long2*rad;

double lats=(lat2-lat1);
double longs=(long2-long1);
double a = pow(sin(lats/2),2)+cos(lat1)*cos(lat2)*pow(sin(longs/2),2);
double b = sqrt(a);
return 2*radius*asin(b);
}

//double flighttime (time=dis/speed)
double getFlightTime(double lat1, double long1, double lat2, double long2){
double rad = 3958.8;
double speed = 517; 
double distance= haversine(lat1,long1,lat2,long2,rad);
double time = distance/speed;
return time;
}

int main(){
bool picked =false;
string input;
int option;
int roption;
Location location1;
Location location2;
vector<Location> locations = {
		{"Starkville, MS, USA", 33.4504, -88.8184},
		{"Tupelo, MS, USA", 34.2576, -88.7034},
		{"Port Gibson, MS, USA", 31.9608, -90.9817},
		{"Philadelphia, MS, USA", 32.7715, -89.1167},
		{"Oxford, MS, USA", 34.3660, -89.5188},
		{"Ocean Springs, MS, USA", 30.4113, -88.8278},
		{"Natchez, MS, USA", 31.5604, -91.4032},
		{"Laurel, MS, USA", 31.6941, -89.1306},
		{"Holly Springs, MS, USA", 34.7676, -89.4487},
		{"Grenada, MS, USA", 33.7516, -89.8130}
	};
while(picked==false){
    cout << "----------------------------------------------------------------------------------" << endl;
		cout << "Welcome to Project: Flight Calculator!" << endl;
		cout << "Inside this project you should be able to:" << endl;
		cout << " - Pick two locations from the given options." << endl;
		cout << " - Find out how far apart they are and how long it would take to fly between them." << endl;
		cout << "Each location should be displayed in latitude/longitude format" << endl;
		cout << "Example: Miami Beach, FL, USA    25.793449    -80.139198" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
    cout<<"Pick a location!"<<endl;
    for(int i=0;i<locations.size();i++){
        cout<<i+1<<"."<<" ";
        cout<<locations[i].name<<"    ";
        cout<<locations[i].lat<<"    ";
        cout<<locations[i].lon<<endl;
    }
    cout<<"11. Exit Program"<<endl;
    cout << "----------------------------------------------------------------------------------" << endl;
    cout<<"Location: ";
    cin>>input;
    try{
    option=stoi(input);
    for(int i =0;i<locations.size();){
        if(option==11){
            cout<<"Goodbye!"<<endl;
            return 0;
        }
        if(option!=i+1){
            i++;
        }
        else if(option==i+1){
            cout<<"You picked option: "<<locations[i].name<<endl;
            location1=locations[i];
            roption=option;
            removestrs(locations,roption);
            picked=true;
            break;
        }
        
         if(option < 1 || option > locations.size()){
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"Please type a location number!(EX: 1. location you type 1)"<<endl;
            break;
        }
    }
}
        catch(const invalid_argument&){
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"Please type a location number!(EX: 1. location you type 1)"<<endl;
        }
}
//2nd part
while(picked==true){
cout<<"--------------------------------------------------------"<<endl;
cout<<"You have selected: "<<endl;
    cout<<"- "<<location1.name<<" As your location."<<endl;
cout<<"--------------------------------------------------------"<<endl;
cout<<"Pick one more location!"<<endl;
for(int i=0;i<locations.size();i++){
        cout<<i+1<<"."<<" ";
        cout<<locations[i].name<<"    ";
        cout<<locations[i].lat<<"    ";
        cout<<locations[i].lon<<endl;
    }
cout<<"Pick one more location: ";
cin>>input;
    try{
     option = stoi(input);
    for(int i =0;i<locations.size();){
        if(option!=i+1){
            i++;
        }
        else if(option==i+1){
            cout<<"--------------------------------------------------------"<<endl;
                cout<<"- Your 2nd location was: "<<locations[i].name<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            location2=locations[i];
            double har=haversine(location1.lat,location1.lon,location2.lat,location2.lon,3958.8);
            double time = getFlightTime(location1.lat,location1.lon,location2.lat,location2.lon);
            cout<<"The distance from: ";
            cout<<location1.name<<" and "<<location2.name<<endl;
            cout<<"is "<<har<<" miles ";
            cout<<"and it would take "<<time<<" hours to get there by plane!"<<endl;
            cout<<"Thank you for using Project: Flight Calculator!"<<endl;
            cout<<"--------------------------------------------------------"<<endl;
            return 0;
        }
        
         if(option < 1 || option > locations.size()){
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"Please type a location number!(EX: 1. location you type 1)"<<endl;
            break;
        }
    }
}
        catch(const invalid_argument&){
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"Please type a location number!(EX: 1. location you type 1)"<<endl;
        }
        



}

}
