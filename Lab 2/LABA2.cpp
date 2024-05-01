#include <iostream>
#include <math.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class CARS{
private:
char name_of_car[30];
int amount_wheels;
double kilometers;
double volume_tank;
double power;
double travel_time;
public:
double speed;
double fuel_consumption;
CARS(int amount_cars,CARS* vehicles);
void Set_name(char carname[30])
{
  strcpy(name,carname);
}
char Get_name()
{
  for(int i=0;i<30;i++)
    {
      cout<<name[i];
    }
  return 0;
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
void calculating_speed(int amount_vehicles,Vehicle *vehicles)/////////////////////////////////////////////
{
   for(int i=0;i<amount_vehicles;i++)
    {
      vehicles[i].speed=fabs(((vehicles[i].power-(vehicles[i].power/2))*20)/pow((double)vehicles[i].amount_wheels,(double)2));
    }
}
friend void ShowSpeed(int amount_vehicles,Vehicle *vehicles,int i)
{
  cout<<"Speed:"<<vehicles[i].speed<<"\n";
}

double Get_speed(){ 
    return speed; 
    
}
void calculating_fuel_consumption(int amount_vehicles,Vehicle *vehicles)//////////////////////////////
{
  for(int i=0;i<amount_vehicles;i++)
    {
       vehicles[i].fuel_consumption=fabs(sqrt(vehicles[i].power)/pow((double)1.5,(double)(vehicles[i].power/1000)));
    }
}
double Get_fuel_consumption()
{ 
    return fuel_consumption; 
}
friend void Showfuelcons(int amount_vehicles,Vehicle *vehicles,int i)
{
 cout<<"Fuel consumption:"<<vehicles[i].fuel_concumption<<"\n";
}

void max_S_or_P(int amount_polygons,polygon* p_polygon,int b)
{
  int arr = 0;
  int array_number_max[amount_polygons];
  if(b==1){
    double max_S=p_polygon[0].S;
    for (int j = 1; j < amount_polygons; j++){
        if(p_polygon[j].S - max_S > 0)
        {
            max_S = p_polygon[j].S;
        }
    }
    for (int k = 0; k < amount_polygons; k++){
        if(p_polygon[k].S == max_S){
            array_number_max[arr] = k;
            arr++;
        }
    }
  if(arr==0)
  {
    cout<<"Polygon with max square is polygon number: "<<arr+1<<"\n";
  }
  if(arr>0)
  {
    cout<<"Polygons with max square:\n";
    for(int z=0;z<arr;++z)
      {
        cout<<"Polygon number: "<<array_number_max[z]+1<<"\n";
      }
  }
  }
  if(b==0){
    double max_P=p_polygon[0].P;
    for (int j = 1; j < amount_polygons; j++){
        if(p_polygon[j].P - max_P > 0){
            max_P = p_polygon[j].P;
        }
    }
    for (int k = 0; k < amount_polygons; k++){
        if(p_polygon[k].P == max_P){
            array_number_max[arr] = k;
            arr++;
        }
    }
    if(arr==0)
    {
        cout<<"Polygon with max perimetr is polygon number:"<<arr+1<<"\n";
    }
    if(arr>0)
    {
        cout<<"Polygons with max perimetr:\n";
        for(int z=0;z<arr;++z)
        {
        cout<<"Polygon number:"<<array_number_max[z]+1<<"\n";
        }
    }
  }
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



