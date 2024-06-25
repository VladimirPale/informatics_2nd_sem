#include <iostream>
#include <math.h>
#include <iostream>
#include <string>
#include <random>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
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
public:
    double mileage_wheel;
    int status;
    int past_status;
    double get_status() const {return status;}

void status_wheel(){
    int s =0;
    past_status=status;
    if(status==0){
        s =rand() %99 + mileage_wheel*(rand()%100)*0.002;
    }
    if(s>100){ status = 1;}
}
WHEELS() {status=0;mileage_wheel=0;};
    double get_wheel_mileage() const {
        return mileage_wheel;
    }
};
class FUEL_SYSTEM{
protected:
    double volume;
    double current_volume;
public:
 FUEL_SYSTEM() {volume = 0;current_volume=0;};
 void calc_current_volume(double Volume_tank, double lenght_of_the_track,int num_ref,double consumption)
{
  current_volume= Volume_tank + num_ref * Volume_tank - lenght_of_the_track / 100 * consumption;
}
    double get_volume() {return volume;}
};

class ENGINE{
protected:
    double power ;
    double Fuel_consumption;
public:
    ENGINE() {power = 0;Fuel_consumption=0;};

    double Get_power() const {return power;}
    double Get_fuel_consumption() const {return Fuel_consumption;}

    double calculating_fuel_consumption(double power)
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
double start_speed;
bool speed_s;
double time_of_race;
public:
int brokenwheels=0;
WHEELS* wheels;
CARS(){
    cout<<"Created\n";
}
 CARS(string vehicle_name){
        Set_name(vehicle_name);
        cout << "Enter number of wheels for vehicle: ";
        getInput(&amount_wheels);
        while ( amount_wheels <= 0) {
            cout << "Error! Please enter a positive integer for the number of wheels: ";
            getInput(&amount_wheels);
        }

        wheels = new WHEELS[amount_wheels];

        for (int i = 0; i < amount_wheels; i++) {
            wheels[i] = WHEELS();
        }

        cout << "Enter the power of the car:\t";
        double Cpower;
        getInput(&Cpower);
        speed_s=NULL;
        while ( Cpower <= 0) {
            cout << "Error! Please enter a positive number for the power: ";
            getInput(&Cpower);
        }
        power = Cpower;

        cout << "Enter the Volume of the tank:";
        double Volume_tank;
        getInput(&Volume_tank);
        while (Volume_tank <= 0) {
            cout << "Error! Please enter a positive number for the volume: ";
            getInput(&Volume_tank);
        }
        volume= Volume_tank;
        current_volume=Volume_tank;
        Fuel_consumption=calculating_fuel_consumption(power);
        calculating_speed();


    }
      friend ostream& operator<<(ostream& out, const CARS& car) {


        out << "Car name: " << car.name_of_car << endl;
        out << "Number of wheels: " << car.amount_wheels << endl;
        out << "Wheel status:\n";
        for (int i = 0; i < car.amount_wheels; i++) {
            out << "Wheel " << i + 1 << ": ";
            if (car.wheels[i].status == 1) {
                out << "Broken/";
                if (car.wheels[i].past_status == 1) {out << "(in past track-Broken)\n";}
                if (car.wheels[i].past_status == 0) {out << "(in past track-Good condition)\n";}
            } else if (car.wheels[i].status == 0) {
                out << "Good condition\n";
            }
        }
        out << "Volume tank: " << car.volume << endl;
        out << "Current volume: " << car.current_volume << endl;
        out << "Engine consumption: " << car.Fuel_consumption << endl;
         out << "Speed: " << car.current_speed << " (Initial speed:" << car.start_speed << ")" << endl;

        return out;
    }
    void Wheel_mileage(CARS* &vehicles, int amount_vehicles, double length_of_the_track) {
    for (int i = 0; i < amount_vehicles; i++) {
        for (int j = 0; j < vehicles[i].Get_amount_wheels(); j++) {
            vehicles[i].wheels[j].mileage_wheel += length_of_the_track;
        }
    }
}

void Set_name(string name_of_car) {this->name_of_car=name_of_car;}

string Get_name() {return name_of_car;}

int Get_amount_wheels(){return amount_wheels;}

double Get_speed(){return current_speed;}

double Get_time_of_race(){return time_of_race;}

void Set_time_of_race(double time_of_race){this->time_of_race=time_of_race;}

void calculating_speed() {
  brokenwheels = 0;
  for (int t = 0; t < amount_wheels; t++) {
    brokenwheels += wheels[t].get_status();
  }
  double s = 0.0;
  if ((amount_wheels - brokenwheels) == 0) {
    s = 1.0 / amount_wheels;
  }
  current_speed = fabs((((double)(power) - ((double)(power) / 2.0)) * 20.0) / pow(amount_wheels, 2.0)) * (((amount_wheels - brokenwheels) + s) / amount_wheels);
  if(!speed_s){start_speed=current_speed; speed_s=1;}
}

void PrintSpeed(CARS* &vehicles,int i)
{
  cout<<"Speed:"<<vehicles[i].current_speed<<"\n";
}

void Showfuelcons(CARS* &vehicles,int i)
{
 cout<<"Fuel consumption:"<<vehicles[i].Fuel_consumption<<"\n";
}
~CARS( ){
  {
      //cout<<"\n1234\n";//delete[] wheels////////////////передача по const

  }
}
double refueling(int lenght_of_the_track, int amount_vehicles, CARS* &vehicles, int i){
      double number_of_refuelings;
      number_of_refuelings=(floor)(((lenght_of_the_track/double(100)) * vehicles[i].Fuel_consumption) / vehicles[i].volume);
        return number_of_refuelings;
}
void PrintAndSortRaceResults(int amount_vehicles, double* time_of_the_race,CARS* &vehicles,int lenght_of_the_track) {
    string name_v[amount_vehicles];
    for(int i = 0; i < amount_vehicles; i++){
        name_v[i] = vehicles[i].Get_name();
    }
    double num_refuelings[amount_vehicles];
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
        double hours = (floor)(time_of_the_race[i]);
        double minutes = (floor)((time_of_the_race[i] - hours) * 60);
        double seconds =(floor)((time_of_the_race[i] * 3600) - (hours * 3600) - (minutes * 60));
        if ((hours==0)&&(minutes==0)){ cout << "TIME OF THE RACE: "<< seconds << " sec\n";}
        else if (hours==0){ cout << "TIME OF THE RACE:" << minutes << " min "<<seconds << " sec\n";}
        else{cout << "TIME OF THE RACE: " << hours << " hours " << minutes << " min " << seconds << " sec\n";}


        cout << "AMOUNT REFUELING: " << num_refuelings[i] << "\n";
}
}
void after_track() {
    for (int i = 0; i < amount_wheels; i++) {
        wheels[i].status_wheel();
    }
}
};
void Wheel_mileage(CARS* &vehicles, int amount_vehicles, double length_of_the_track) {
    for (int i = 0; i < amount_vehicles; i++) {
        for (int j = 0; j < vehicles[i].Get_amount_wheels(); j++) {
            vehicles[i].wheels[j].mileage_wheel += length_of_the_track;
        }
    }
}
void Calculation_track(double lenght_of_the_track, CARS* &vehicles, int amount_vehicles)
{
    long int number_refills[amount_vehicles];
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
void output(int amount_vehicles,CARS* &vehicles)
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


void menu(int amount_vehicles,CARS* &vehicles, double lenght_of_the_track)
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
  cout<<"3.Input the length of track"<<"\n";;
  cout<<"4.Calculation_track"<<"\n";
  cout<<"5.Exit"<<"\n";
  getInput(&choice);
  switch(choice){
    case 1:{
      new_page();
       string vehicle_name;
       for (int i = 0; i < amount_vehicles; ++i) {
            cout << "Enter vehicle name " << ": ";
            getline(cin, vehicle_name);
            vehicles[i] = CARS(vehicle_name);
      }
      flag++;
      break;
    }
    case 2:{
      new_page();
      if(flag==0){
        cout<<"You have not entered the vehicles!(TRY AGAIN)"<<"\n";
        break;
        }
       for(int i=0;i<amount_vehicles;++i)
        {
      cout<<vehicles[i];
        }
      break;
    }
    case 3:{
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
    }
      case 4:{
        new_page();
        if(flag==0){
        cout<<"YOU HAVE NOT ENTERED VEHICLE DATA";
        break;
        }
        if(lenght_of_the_track==0){
            cout<<"YOU HAVE NOT ENTERED LENGТН DATA";
            break;
            }
        if(lenght_of_the_track==0)
          {
            cout<<"ENTER LENGHT OF THE TRACK , before determinate track!"<<"\n";
            break;
          }
          Calculation_track(lenght_of_the_track, vehicles, amount_vehicles);
          Wheel_mileage(vehicles,amount_vehicles,lenght_of_the_track);
         for (int k = 0; k < amount_vehicles; ++k) {
            bool needsAfterTrack = false;

            for (int j = 0; j < vehicles[k].Get_amount_wheels(); ++j) {
                if (vehicles[k].wheels[j].status == 0) {
                    needsAfterTrack = true;
                break;
            }
            }

        if (needsAfterTrack) {
            vehicles[k].after_track();
        }
        }
          for(int i=0;i<amount_vehicles;++i)
            {
                vehicles[i].calculating_speed();
                vehicles[i].calc_current_volume(vehicles[i].get_volume(),lenght_of_the_track,vehicles[i].refueling(lenght_of_the_track,amount_vehicles, vehicles, i), vehicles[i].Get_fuel_consumption());
            }
          break;

      }
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
        continue;

    }
  }
}


int main() {
  srand(time(NULL));
  int amount_vehicles;
  double lenght_of_the_track;
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
