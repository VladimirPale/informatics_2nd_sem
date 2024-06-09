 #include <iostream>
#include <math.h>
#include <iostream>
#include <string>
#include <random>
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

class WHEELS{
protected:
    double status;
    double wheel_mileage;
public:
    WHEELS( ){
  {
  cout<<"wheels created"<<"\n";
  }
}
void status_wheel(double wheel_mileage){
    int s =0;
    if(status!=0){
        s =rand() %99 + land*(rand()%100)*0.01;
    }
    if(s>100){ status = 1};
}
WHEELS(double mileage = 0, int status = 0) : mileage(mileage), status(status) {}

    double wheel_mileage() const {
        return mileage;
    }
};
class FUEL_SYSTEM{
protected:
    double volume;
    double current_volume;
public:
    FUEL_SYSTEM( ){
  {
  cout<<"fuel system created"<<"\n";
  }
}
 FUEL_SYSTEM(double volume_tank = 0) : volume_tank(volume_tank) {}

};

class ENGINE{
protected:
    double power ;
    double Fuel_consumption;
public:
    ENGINE(double power = 0) : power(power) {}

    void Set_power(double power) {
        this->power = power;
    }
  
    void calculating_fuel_consumption(double power)//////////////////////////////
    {
       return fabs(pow((vehicles[i].power), 0.5) / pow((double)1.5, (double)(vehicles[i].power / 1000)));
    }
     ENGINE(double power = 0) : power(power) {}

};


class CARS: public ENGINE, public FUEL_SYSTEM {
private:
string name_of_car;
double mileage;
int amount_wheels;
double current_speed;
public:
WHEELS* wheels;
CARS(int amount_wheels, double power, double volume_tank) : 
    ENGINE(power), FUEL_SYSTEM(volume_tank), 
amount_wheels(amount_wheels), wheels(new WHEELS[amount_wheels]) {}
CARS(int amount_vehicles, CARS* vehicles, double power, double volume_tank){
  for(int i=0;i<amount_vehicles;i++)
  {
    string carname;
    int amount_wheels;
    double volume_tank;
    double power;
    WHEELS wheels[amount_wheels];
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
 friend ostream& operator<<(ostream& out, const CARS& car) {
        out << "Car name: " << car.name_of_car << endl;
        out << "Number of wheels: " << car.amount_wheels << endl;
        out << "Mileage: " << fixed << setprecision(2) << car.mileage << endl;
        out << "Wheel status:\n";
        for (int i = 0; i < car.amount_wheels; i++) {
            out << "Wheel " << i + 1 << ": ";
            if (car.wheels[i].status == 1) {
                out << "Broken\n";
            } else if (car.wheels[i].status == 0) {
                out << "Good condition\n";
            }
        }
        out << "Volume tank: " << car.volume << endl;
        out << "Current volume: " << car.current_volume << endl;
        out << "Engine consumption: " << car.Fuel_consumption << endl;
        out << "Speed: " << car.current_speed << endl;

        return out;
    }
void Set_name(string name_of_car) {this->name_of_car=name_of_car;}

string Get_name() {return name_of_car;}

void Set_amount_wheels(int amount_wheels){this->amount_wheels=amount_wheels;}//сеттер для количесва колес 

int Get_amount_wheels(){return amount_wheels;}//геттер для количества колес

double Get_speed(){return speed;}// геттер для скорости 

void calculating_speed(int amount_vehicles,CARS *vehicles)/////////////////////////////////////////////
{
    wheel_status_
   for(int i=0;i<amount_vehicles;i++)
    {
      vehicles[i].speed=fabs(((vehicles[i].power-(vehicles[i].power/2))*20)/pow(vehicles[i].amount_wheels,(double)2));
    }
}


void PrintSpeed(CARS *vehicles,int i)
{
  cout<<"Speed:"<<vehicles[i].speed<<"\n";
}

void Showfuelcons(CARS *vehicles,int i)
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


void calculating_fuel_consumption(int amount_vehicles,CARS *vehicles)//////////////////////////////
{
  for(int i=0;i<amount_vehicles;i++)
    {
       vehicles[i].fuel_consumption = fabs(pow((vehicles[i].power), 0.5) / pow((double)1.5,(vehicles[i].power / 1000)));//18,5

}
int refueling(int lenght_of_the_track, int amount_vehicles, CARS *vehicles, int i){
      int number_of_refuelings;
      number_of_refuelings=(int)(((lenght_of_the_track/double(100)) * vehicles[i].Get_fuel_consumption()) / vehicles[i].Get_volume_tank());
        return number_of_refuelings;
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
    double first_time_of_race;
    double time_of_race[amount_vehicles];
    for (int i =0; i< amount_vehicles; i++){
    first_time_of_race = (lenght_of_the_track /vehicles[i].Get_speed());
      vehicles[i].Set_time_of_race(first_time_of_race);
    }
    for (int i =0; i< amount_vehicles; i++){
      time_of_race[i] = vehicles[i].Get_time_of_race();
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
      vehicles[i].PrintSpeed(vehicles, i);
      cout<<"VOLUME OF TANK: "<<vehicles[i].Get_volume_tank()<<"\n";
      vehicles[i].Showfuelcons(vehicles, i);
      cout<<"ENGINE POWER: "<<vehicles[i].Get_power()<<"\n";
    }
 }


void menu(int amount_vehicles,CARS *vehicles,double power, double volume_tank, int lenght_of_the_track)
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
      CARS(amount_vehicles,vehicles,power,volume_tank)
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
