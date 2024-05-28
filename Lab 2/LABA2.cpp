#include <iostream>
#include <math.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
void getInput(int *input) {
    string inputString;
    getline(cin, inputString);
    istringstream iss(inputString);

    if (iss >> *input) {
        return;
    } else {
        cout << "Error input(you input char. TRY AGAIN)!" << "\t";
        getInput(input);     }
}
void getInput(double *input) {
    string inputString;
    getline(cin, inputString);
    istringstream iss(inputString);

    if (iss >> *input) {
          return;
    } else {

        cout << "Error input(you input char. TRY AGAIN)!" << "\t";
        getInput(input);
    }
}

class CARS{
private:
string name_of_car;
int amount_wheels;
double volume_tank;
double power;
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
double Get_speed(){
    return speed;

}


void calculating_speed(int amount_vehicles,CARS *vehicles)/////////////////////////////////////////////
{
   for(int i=0;i<amount_vehicles;i++)
    {
      vehicles[i].speed=fabs(((vehicles[i].power-(vehicles[i].power/2))*20)/pow(vehicles[i].amount_wheels,(double)2));
    }
}


friend void PrintSpeed(CARS *vehicles,int i)
{
  cout<<"Speed:"<<vehicles[i].speed<<"\n";
}



void calculating_fuel_consumption(int amount_vehicles,CARS *vehicles)//////////////////////////////
{
  for(int i=0;i<amount_vehicles;i++)
    {
       vehicles[i].fuel_consumption = fabs(pow((vehicles[i].power), 0.5) / pow((double)1.5,(vehicles[i].power / 1000)));//18,5

}
}
double Get_fuel_consumption()
{
   return fuel_consumption;
}

friend void Showfuelcons(CARS *vehicles,int i)
{
 cout<<"Fuel consumption:"<<vehicles[i].fuel_consumption<<"\n";
}
CARS( ){
  {
  cout<<"Vehicle created"<<"\n";
  }
}
~CARS( ){
  {
  cout<<"Vehicle delete"<<"\n";
  }
}

};
int refueling(int lenght_of_the_track, int amount_vehicles, CARS *vehicles, int i){
      int number_of_refuelings;
      number_of_refuelings=(int)(((lenght_of_the_track/double(100)) * vehicles[i].Get_fuel_consumption()) / vehicles[i].Get_volume_tank());
        return number_of_refuelings;
}
void PrintAndSortRaceResults(int amount_vehicles, double* time_of_the_race,CARS *vehicles,int lenght_of_the_track) {
    string name_v[amount_vehicles];
    for(int i = 0; i < amount_vehicles; i++){
        name_v[i] = vehicles[i].Get_name();
    }
    int num_refuelings[amount_vehicles];
    for (int i =0; i< amount_vehicles; i++){
        num_refuelings[i] = refueling(lenght_of_the_track, amount_vehicles,vehicles, i);
    }
    cout << "Determination complete!\n";
    for (int i = 0; i < amount_vehicles; i++) {
        for (int j = 0; j < amount_vehicles - 1; ++j) {
            if (time_of_the_race[j] > time_of_the_race[j + 1] || (time_of_the_race[j] == time_of_the_race[j + 1] && num_refuelings[j] > num_refuelings[j + 1])) {
                swap(time_of_the_race[j], time_of_the_race[j + 1]);
                swap(num_refuelings[j], num_refuelings[j + 1]);
                swap(name_v[j], name_v[j + 1]);
            }
        }
    }
    for (int i = 0; i < amount_vehicles; i++) {
        cout << "VEHICLE: " << name_v[i] << "\n";
        int hours = (int)(time_of_the_race[i]);
        int minutes = (int)((time_of_the_race[i] - hours) * 60);
        int seconds =(int)((time_of_the_race[i] * 3600) - (hours * 3600) - (minutes * 60));

        cout << "TIME OF THE RACE: " << hours << " hours " << minutes << " min " << seconds << " sec\n";
        cout << "AMOUNT REFUELING: " << num_refuelings[i] << "\n";
}
}
void Calculation_track(int lenght_of_the_track, CARS *vehicles, int amount_vehicles)
{
    int number_refills[amount_vehicles];
    string name_v[amount_vehicles];
    double time_of_race[amount_vehicles];
    for (int i =0; i< amount_vehicles; i++){
      time_of_race[i] = (lenght_of_the_track /vehicles[i].Get_speed());
    }
    PrintAndSortRaceResults(amount_vehicles, time_of_race,vehicles,lenght_of_the_track);
}


void new_page()
{
  for(int i=0;i<100;++i)
    {
      cout<<"\n";
    }
}
void output(int amount_vehicles,CARS *vehicles)
{
  for(int i=0;i<amount_vehicles;i++)
    {
      cout<<"NAME OF CAR: "<<vehicles[i].Get_name()<<"\n";
      cout<<"AMOUNT THE WHEELS: "<<vehicles[i].Get_amount_wheels()<<"\n";
      PrintSpeed(vehicles, i);
      cout<<"VOLUME OF TANK: "<<vehicles[i].Get_volume_tank()<<"\n";
      Showfuelcons(vehicles, i);
      cout<<"ENGINE POWER: "<<vehicles[i].Get_power()<<"\n";
    }
 }

CARS::CARS(int amount_vehicles, CARS* vehicles){
  for(int i=0;i<amount_vehicles;i++)
  {
    string carname;
    int amount_wheels;
    double volume_tank;
    double power;
    cout<<"\nCAR"<<i+1<<"\n";
    cout<<"Enter name of the car: ";
    getline(cin, carname);
    vehicles[i].Set_name(carname);
    cout<<"Enter amount of wheels: ";
    getInput(&amount_wheels);
    do
    {
      if(amount_wheels<=0)
      {
        cout<<"ERROR!TRY AGAIN(amount of wheels>0)"<<"\n";
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
        cout<<"ERROR!TRY AGAIN(volume tank>0)"<<"\n";
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
        cout<<"ERROR!TRY AGAIN(power>0)"<<"\n";
        getInput(&power);
      }
    } while(power<=0);
    vehicles[i].Set_power(power);
  }
}


void menu(int amount_vehicles,CARS *vehicles, int lenght_of_the_track)
{
  int choice;
  int exit=0;
  int flag=0;
  while (exit==0)
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
      for(int i=amount_vehicles-1;i<amount_vehicles;++i)
      {
      vehicles[i].calculating_fuel_consumption(amount_vehicles, vehicles);
      vehicles[i].calculating_speed(amount_vehicles, vehicles);
      }
      flag++;
      break;
      case 2:
      new_page();
      if(flag==0){
        cout<<"You have not entered the vehicles!(TRY AGAIN)"<<"\n";
        break;
      }
      output(amount_vehicles,vehicles);
      break;
      case 3:
      new_page();
      cout<<"Enter the lenght of the track: ";
      getInput(&lenght_of_the_track);

      case 4:
      new_page();
      if(flag==0){
        cout<<"YOU HAVE NOT ENTERED VEHICLE DATA";
        break;
      }
       if(lenght_of_the_track==0){
        cout<<"YOU HAVE NOT ENTERED LENGHT DATA";
        break;
      }
      new_page();
      Calculation_track(lenght_of_the_track,vehicles,amount_vehicles);
      break;
       case 5:
      new_page();
      cout<<"Are you sure to exit? 0-no\n";
      getInput(&exit);
      if(exit==1)
      {
        return;
      }
      break;
      default:
      cout<<"Error of menu! Try again"<<"\n";
      break;

    }
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
