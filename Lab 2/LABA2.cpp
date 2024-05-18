#include <iostream>
#include <math.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class CARS{
private:
string name_of_car;
int amount_wheels;
double kilometers;
double volume_tank;
double power;
double travel_time;
double speed;
double fuel_consumption;
public:
CARS(int amount_vehicles,CARS* vehicles);
void Set_name(string name_of_car) {
    this->name_of_car=name_of_car;
    }
string Get_name() {
    return name_of_car;
}
void Set_amount_wheels(int amount_wheels)
{
  this->amount_wheels=amount_wheels;
}
int Get_amount_wheels()
{
  return amount_wheels;
}
void Set_kilometrs(double kilometers)
{
  this->kilometers=kilometers;
}
double Get_kilometrs()
{
  return kilometers;
}
void Set_volume_tank(double volume_tank)
{
  this->volume_tank=volume_tank;
}
double Get_volume_tank()
{
  return volume_tank;
}
void Set_power(double power)
{
  this->power=power;
}
double Get_power()
{
  return power;
}
void Set_travel_time(double travel_time)
{
  this->travel_time=travel_time;
}
double Get_travel_time()
{
  return travel_time;
}
void calculating_speed(int amount_vehicles,CARS *vehicles)/////////////////////////////////////////////
{
   for(int i=0;i<amount_vehicles;i++)
    {
      vehicles[i].speed=fabs(((vehicles[i].power-(vehicles[i].power/2))*20)/pow((double)vehicles[i].amount_wheels,(double)2));
    }
}
friend void ShowSpeed(int amount_vehicles,CARS *vehicles,int i)
{
  cout<<"Speed:"<<vehicles[i].speed<<"\n";
}

double Get_speed(){
    return speed;

}

void calculating_fuel_consumption(int amount_vehicles,CARS *vehicles)//////////////////////////////
{
  for(int i=0;i<amount_vehicles;i++)
    {
       vehicles[i].fuel_consumption = fabs(pow((vehicles[i].power), 0.5) / pow((double)1.5, (double)(vehicles[i].power / 1000)));//18,5

}
}
double Get_fuel_consumption()
{
   return fuel_consumption;
}

friend void Showfuelcons(int amount_vehicles,CARS *vehicles,int i)
{
 cout<<"Fuel consumption:"<<vehicles[i].fuel_consumption<<"\n";
}
CARS( ){
  {
  cout<<"Vehicle created"<<"\n";
  }
}
};
int refueling(int lenght_of_the_track, int amount_vehicles, CARS *vehicles, int i){
      int number_of_refuelings;
      number_of_refuelings=(int)(((lenght_of_the_track/100)*vehicles[i].Get_fuel_consumption())/vehicles[i].Get_volume_tank());
  return number_of_refuelings;
}

void Calculation_track(int lenght_of_the_track, CARS *vehicles, int amount_vehicles)
{
    int number_refills[amount_vehicles];
    for (int i =0; i< amount_vehicles; i++){
        number_refills[i] = refueling(lenght_of_the_track, amount_vehicles,vehicles, i);
    }
    double time_of_race[amount_vehicles];
    for (int i =0; i< amount_vehicles; i++){
    time_of_race[i] = (lenght_of_the_track /double(vehicles[i].Get_speed()));
    }
}

void PrintAndSortRaceResults(int amount_vehicles, string* name_v, double* time_of_the_race, int* num_refuelings,CARS *vehicles) {
    string carname[amount_vehicles];
    for(int i = 0; i < amount_vehicles; i++){
        carname[i] = vehicles[i].Get_name();
    }
    cout << "Determination complete!\n";
    for (int i = 0; i < amount_vehicles; i++) {
        for (int j = 0; j < amount_vehicles - 1; ++j) {
            if (time_of_the_race[j] > time_of_the_race[j + 1] || (time_of_the_race[j] == time_of_the_race[j + 1] && num_refuelings[j] > num_refuelings[j + 1])) {
                swap(time_of_the_race[j], time_of_the_race[j + 1]);
                swap(num_refuelings[j], num_refuelings[j + 1]);
                swap(carname[j], carname[j + 1]);
            }
        }
    }
    for (int i = 0; i < amount_vehicles; i++) {
        cout << "VEHICLE: " << name_v[i] << "\n";
        int hours = (int)(time_of_the_race[i]);
        int minutes = (int)((time_of_the_race[i] - hours) * 60);
        int seconds =(int)((time_of_the_race[i] * 3600) - (hours * 3600) - (minutes * 60));

        cout << "TIME OF THE RACE: " << hours << " hours " << minutes << " min " << seconds << " sec\n";
        cout << "Amount_refuelings: " << num_refuelings[i] << "\n";
}
}
/*void delete_polygon(int& amount_polygons, polygon*& p_polygon)
{
  int number_polygon;
  cout << "Enter number of polygon: ";
  cin >> number_polygon;
  getInput(&number_polygon);
  if (number_polygon < 1 || number_polygon > amount_polygons)
  {
    cout << "No polygon with this number\n";
    return;
  }

  polygon* new_p_polygon = new polygon[amount_polygons - 1];

  for (int i = 0; i < number_polygon - 1; ++i)
  {
    new_p_polygon[i] = p_polygon[i];
  }

  for (int i = number_polygon; i < amount_polygons; ++i)
  {
    new_p_polygon[i - 1] = p_polygon[i];
  }

  delete[] p_polygon;
  p_polygon = new_p_polygon;
  amount_polygons--;
}*/

void new_page()
{
  for(int i=0;i<100;++i)
    {
      cout<<"\n";
    }
}

CARS::CARS(int amount_vehicles, CARS* vehicles){
  for(int i=0;i<amount_vehicles;i++)
  {
    string carname;
    int amount_wheels;
    double volume_tank;
    double power;
    cout<<"\nCAR №"<<i+1<<"\n";
    cout<<"Enter name of the car: ";
    cin>>carname;
    vehicles[i].Set_name(carname);
    cout<<"Enter amount of wheels: ";
    getInput(&amount_wheels);
    do
    {
      if(amount_wheels<=0)
      {
        cout<<"Error! Try again(amount wheels>0)"<<"\n";
        getInput(&amount_wheels);
      }
    } while(amount_wheels<=0);
    vehicles[i].Set_amount_wheels(amount_wheels);
    cout<<"Enter volume of tank: ";
    getInput(&volume_tank);
    do
    {
      if(volume_tank<=0)
      {
        cout<<"Error! Try again(volume tank>0)"<<"\n";
        getInput(&volume_tank);
      }
    } while(volume_tank<=0);
    vehicles[i].Set_volume_tank(volume_tank);
    cout<<"Enter power: ";
    getInput(&power);
    do
    {
      if(power<=0)
      {
        cout<<"Error! Try again(power>0)"<<"\n";
        getInput(&power);
      }
    } while(power<=0);
    vehicles[i].Set_power(power);
  }
}


void menu(int amount_venicles,CARS *vehicles, int lenght_of_the_track)
{
  int choice;
  int exit=0;
  int cars=0;
  {
  int choice;
  cout<<"MENU\n";
  cout<<"1.Input information about vehicles"<<"\n";
  cout<<"2.Output information about vehicles"<<"\n";
  cout<<"3.Input the lenght of track"<<"\n";;
  cout<<"4.Calculation_track"<<"\n";
  cout<<"5.Exit"<<"\n";
  getInput(&choice);
  switch(choice)
    {

      case 1:
      new_page();
      CARS(amount_vehicles,vehicles);
      for(int i=cars-1;i<cars;++i)
      {
      vehicles[i].calculating_fuel_consumption(amount_vehicles, vehicles);
      vehicles[i].calculating_speed(amount_vehicles, vehicles);
      }
      cars++;
      break;

      break;

      case 2:
      new_page();

      break;


    default:
      cout<<"Error! Try again"<<"\n";

    }
  }
}




void getInput(int *input) {
    string inputString;
    getline(cin, inputString);
    istringstream iss(inputString);

    if (iss >> *input) {
        return;
    } else {
        cout << "Error input!" << "\t";
        getInput(input);     }
}
void getInput(double *input) {
    string inputString;
    getline(cin, inputString);
    istringstream iss(inputString);

    if (iss >> *input) {
          return;
    } else {

        cout << "Error input!" << "\t";
        getInput(input);
    }
}

int main() {
  int amount_vehicles=0;
  int lenght_of_the_track=0;
  cout << "How many vehicles do you want to create?";
  getInput(&amount_vehicles);
  do
    {
      if(amount_vehicles<=0)
       {
          cout<<"Error, try again \n";
          getInput(&amount_vehicles);
      }
    } while(amount_vehicles<=0);
  CARS *vehicles=new CARS[amount_vehicles];
  menu(amount_vehicles, vehicles, lenght_of_the_track);
  delete [] vehicles;
  return 0;
}
