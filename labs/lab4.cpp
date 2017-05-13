
#include <iostream>
#include <cmath>
#define WATER_WEIGHT  62.4; //Defines the specific weight of water
using namespace std;

int main(){
    float radius, b_force, volume, weight; //Variables needed to calculate buoyancy
    cout << "Please enter the weight (lbs): ";//Prompt user for weight and radius of sphere
    cin >> weight;
    cout << "Please enter the radius: ";
    cin >> radius;
    volume = 4./3. * M_PI * pow(radius, 3);    //Calculate the volume and buoyancy force
    b_force = volume * WATER_WEIGHT;
   
    if(b_force >= weight){  //Determine if the sphere will sink or float
        cout << "The sphere will float!\n";
    }
    else
        cout << "The sphere will sink!\n";
    return 0;
}