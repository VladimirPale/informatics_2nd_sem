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
public:
double speed;
double fuel_consumption;
CARS(int amount_cars,CARS* vehicles);

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
};
void calculating_fuel_consumption(int amount_vehicles,CARS *vehicles)//////////////////////////////
{
  for(int i=0;i<amount_vehicles;i++)
    {
       vehicles[i].fuel_consumption=fabs(pow((vehicles[i].power),0.5)/pow((double)1.5,(double)(vehicles[i].power/1000)));
    }
}
double Get_fuel_consumption()
{
    return fuel_consumption;
}
friend void Showfuelcons(int amount_vehicles,CARS *vehicles,int i)
{
 cout<<"Fuel consumption:"<<vehicles[i].fuel_concumption<<"\n";
}
int refueling(int lenght_of_the_track, int amount_vehicles, Vehicle *vehicles, int i){
      int number_of_refuelings;
      number_of_refuelings=(int)(((lenght_of_the_track/100)*vehicles[i].Get_fuel_consumption())/vehicles[i].Get_volume_tank());
  return number_of_refuelings;
}




void Calculation_track(int lenght_of_the_track, CARS *vehicles, int amount_vehicles)
{
    int number_refills[amount_vehicles];
    for (int i =0; i< amount_vehicles; i++){
        number_refills[i] = refueling(lenght_of_the_track, amount_vehicles,vehicles, i)
    }
    double time_of_race[amount_vehicles];
    for (int i =0; i< amount_vehicles; i++){
     time_of_race[i] = (lenght_of_the_track/ vehicles[i].Get_speed)
    }
}

void PrintAndSortRaceResults(int amount_vehicles, string* name_v, double* time_of_the_race, int* num_refuelings) {
    string carname[amount_vehicles];
    for(int i = 0; i < amount_vehicles; i++){
        carname[i] = vehicles[i].Get_name
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

void delete_polygon(int& amount_polygons, polygon*& p_polygon)
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
}

void new_page()
{
  for(int i=0;i<100;++i)
    {
      cout<<"\n";
    }
}

void menu(int amount_polygons,polygon *p_polygon)
{
  int exit=0;
  int current=0;
  while(exit==0)
  {
  int choice;
  cout<<"MENU\n";
  cout<<"1.Input new polygon\n";
  cout<<"2.Output information about all polygons\n";
  cout<<"3.Delete polygon\n";
  cout<<"4.Submenu max square and max perimetr\n";
  cout<<"5.Exit\n";
  getInput(&choice);
  switch(choice)
    {

      case 1:
      new_page();
      current++;
      input(current,amount_polygons,p_polygon);
      S(amount_polygons,p_polygon);
      P(amount_polygons,p_polygon);
      break;

      case 2:
      new_page();
      output(current,amount_polygons,p_polygon);
      break;

      case 3:
      new_page();
      delete_polygon(amount_polygons,p_polygon);
      current--;
      break;

      case 4:
      new_page();
      submenu(amount_polygons,p_polygon);
      break;

      case 5:
      new_page();
      cout<<"Are you sure to exit? If yes press 1 if no press 2\n";
      int choice_exit;
      getInput(&choice_exit);
      if(choice_exit==1)
      {
        exit++;
      }
      if(choice_exit==2)
      {
        new_page();
        menu(amount_polygons,p_polygon);
      }
      break;
      default:
      cout<<"Error of menu\n";

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
  int amount_vehicles;
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
  Vehicle *vehicles=new Vehicle[amount_vehicles];
  menu(amount_vehicles, vehicles, lenght_of_the_track);
  delete [] vehicles;
  return 0;
}



