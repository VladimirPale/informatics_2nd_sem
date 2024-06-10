#include <iostream>
#include <math.h>
#include <iostream>
#include <string>
#include <random>
#include <sstream>
#include <cstdlib>
#include <ctime>
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

class WHEELS{
protected:
    double status;
    double mileage_wheel;
public:
    double get_mileage_wheel() {return mileage_wheel;}
    void set_status(double new_status) {status = new_status;}
    double get_status() const {return status;}
    void set_mileage(double new_mileage) {mileage_wheel = new_mileage;}

void status_wheel(double wheel_mileage){
    int s =0;
    if(status!=0){
        s =rand() %99 + wheel_mileage*(rand()%100)*0.01;
    }
    if(s>100){ status = 1;}
}
WHEELS(double mileage = 0, int status = 0) : mileage_wheel(mileage), status(status) {}

    double get_wheel_mileage() const { // Изменили имя метода
        return mileage_wheel;
    }
};
class FUEL_SYSTEM{
protected:
    double volume;
    double current_volume;
public:
 FUEL_SYSTEM(double volume_tank = 0) : volume(volume_tank) {}
    void set_volume(double new_volume) {volume = new_volume;}
    double get_volume() const {return volume;}
    void set_current_volume(double new_current_volume) {current_volume = new_current_volume;}
    double get_current_volume() const {return current_volume;}
};

class ENGINE{
protected:
    double power ;
    double Fuel_consumption;
public:
    ENGINE(double power = 0) : power(power) {}

    void Set_power(double power){this->power = power;}
    double Get_power() const {return power;}
    void Set_fuel_consumption(double Fuel_consumption) {this->Fuel_consumption = Fuel_consumption;}
    double Get_fuel_consumption() const {return Fuel_consumption;}

    double calculating_fuel_consumption(double power)//////////////////////////////
    {
       return fabs(pow((power), 0.5) / pow((double)1.5, (double)(power / 1000)));
    }

};


class CARS: public ENGINE, public FUEL_SYSTEM {
private:
string name_of_car;
double mileage;
int amount_wheels;
double current_speed;
double time_of_race;
public:
WHEELS* wheels;
 CARS(){
        cout << "Enter vehicle name: ";
        getline(cin, name_of_car); // Используем getline, чтобы ввести имя с пробелами
        cout << "Enter number of wheels for vehicle: ";
        cin >> amount_wheels;
        while ( amount_wheels <= 0) {
            cout << "Error! Please enter a positive integer for the number of wheels: ";
            getInput(&amount_wheels);
        }

        wheels = new WHEELS[amount_wheels];

        wheels = new WHEELS[amount_wheels];
        for (int i = 0; i < amount_wheels; i++) {
            wheels[i] = WHEELS();
        }

        mileage = 0;
        current_speed = 0;

        cout << "Enter the power of the car:\t";
        double Cpower;
        getInput(&Cpower);
        while ( Cpower <= 0) {
            cout << "Error! Please enter a positive number for the power: ";
            getInput(&Cpower);
        }
        Cpower = power;

        cout << "Enter the Volume of the tank:";
        double Volume_tank;
        getInput(&Volume_tank);
        while (Volume_tank <= 0) {
            cout << "Error! Please enter a positive number for the volume: ";
            getInput(&Volume_tank);
        }
        Volume_tank=volume;
        Volume_tank=Fuel_consumption;


    }
void Set_name(string name_of_car) {this->name_of_car=name_of_car;}

string Get_name() {return name_of_car;}

void Set_amount_wheels(int amount_wheels){this->amount_wheels=amount_wheels;}//сеттер для количесва колес

int Get_amount_wheels(){return amount_wheels;}//геттер для количества колес

double Get_speed(){return current_speed;}

double Get_time_of_race(){return time_of_race;}

void Set_time_of_race(int time_of_race){this->time_of_race=time_of_race;}

void calculating_speed()/////////////////////////////////////////////
{
    int brokenWheels=0;
    for(int t=0; t<amount_wheels; t++){brokenWheels += wheels[t].get_status();}
      current_speed=fabs(((power-(power/2))*20)/pow(amount_wheels,(double)2))/pow(2,double(brokenWheels));
}
void PrintSpeed(CARS *vehicles,int i)
{
  cout<<"Speed:"<<vehicles[i].current_speed<<"\n";
}

void Showfuelcons(CARS *vehicles,int i)
{
 cout<<"Fuel consumption:"<<vehicles[i].Fuel_consumption<<"\n";
}
~CARS( ){
  {
  cout<<"Vehicle delete"<<"\n";
  }
}
int refueling(int lenght_of_the_track, int amount_vehicles, CARS *vehicles, int i){
      int number_of_refuelings;
      number_of_refuelings=(int)(((lenght_of_the_track/double(100)) * vehicles[i].Fuel_consumption) / vehicles[i].volume);
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

};

void Calculation_track(int lenght_of_the_track, CARS *vehicles, int amount_vehicles)
{
    int number_refills[amount_vehicles];
    string name_v[amount_vehicles];
    double first_time_of_race;
    double time_of_race[amount_vehicles];
    for (int i =0; i< amount_vehicles; i++){
    first_time_of_race = (lenght_of_the_track /vehicles[i].Get_speed());
      vehicles[i].Set_time_of_race(first_time_of_race);
    }
    for (int i =0; i< amount_vehicles; i++){
      time_of_race[i] = vehicles[i].Get_time_of_race();
    }
    CARS myCar;
    myCar.PrintAndSortRaceResults(amount_vehicles, time_of_race, vehicles, lenght_of_the_track);
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
      vehicles[i].PrintSpeed(vehicles, i);
      cout<<"VOLUME OF TANK: "<<vehicles[i].get_volume()<<"\n";
      vehicles[i].Showfuelcons(vehicles, i);
      cout<<"ENGINE POWER: "<<vehicles[i].Get_power()<<"\n";
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
      for(int i=0;i<amount_vehicles;++i)
      {
       for (int i = 0; i < amount_vehicles; ++i) {
            vehicles[i] = CARS();
       }
        break;
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
      do
    {
      if(lenght_of_the_track<=0)
       {
          cout<<"Error, try again(track length must be positive) \n";
          getInput(&lenght_of_the_track);
      }
    } while(lenght_of_the_track<=0);
    break;
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
  srand(time(NULL));
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
