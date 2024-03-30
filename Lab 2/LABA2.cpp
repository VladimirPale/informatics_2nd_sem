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


void S (int amount_polygons,polygon* p_polygon){
    for(int i=0;i<amount_polygons;++i)
      {
        if(p_polygon[i].amount_angles==3)
        {
          p_polygon[i].S=sqrt(3)/4*pow(p_polygon[i].modul_side,2);
        }
        if(p_polygon[i].amount_angles==4)
        {
          p_polygon[i].S=pow(p_polygon[i].modul_side,2);
        }
        if(p_polygon[i].amount_angles>4)
        {
          p_polygon[i].S=p_polygon[i].amount_angles*pow(p_polygon[i].modul_side,2)/(4*tan(M_PI/p_polygon[i].amount_angles));
        }
      }
}
void P(int amount_polygons,polygon* p_polygon){
    for(int i =0; i<amount_polygons; i++){
        p_polygon[i].P = p_polygon[i].amount_angles*p_polygon[i].modul_side;
    }
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

void submenu(int amount_polygons,polygon *p_polygon)
{
  int exit_sub=0;
  while(exit_sub==0)
  {
  int choice_submenu;
  cout<<"1.Determine polygon with max square\n";
  cout<<"2.Determine polygon with max perimeter\n";
  cout<<"3.Return to previous menu\n";
  getInput(&choice_submenu);
  switch(choice_submenu)
    {
      case 1:
      new_page();
      max_S_or_P (amount_polygons,p_polygon,1);
      break;

      case 2:
      new_page();
      max_S_or_P(amount_polygons,p_polygon,0);
      break;

      case 3:
      new_page();
      exit_sub++;
      break;

      default:
      cout<<"Error of submenu\n";

    }
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
int main(){
    int amount_polygons=0;
    polygon *p_polygon=NULL;
    menu(amount_polygons,p_polygon);
}

