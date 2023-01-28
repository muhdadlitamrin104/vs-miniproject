#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
using namespace std;

const int MAX_EMPLOYEES = 100;
const float OVERTIME_RATE = 1.5;
const int REGULAR_HOURS = 208; // 26 days * 8 hours per day in every month

struct Employee
{
    string name;
    float baseWage;
    float overtimeWage;
    float totalWage;
    float overtimeHours;
    float absentWage;
    int absentDays;
};

void inputEmployeeData(Employee employees[], int numEmployees,int j);
void calculateWages(Employee employees[], int numEmployees,int j);
void displayPayslip(Employee employees[], int numEmployees);
void printToFile(Employee employees[], int numEmployees);
void calculateAbsentWages(Employee employees[], int numEmployees, int j) ;
class welcome //welcome class
{
	public:
	int welcum()
	{
 ifstream in("welcome.txt"); //displaying welcome ASCII image text on output screen fn1353

  if(!in) 
  {
    cout << "Cannot open input file.\n";
  }
  char str[1000];
  while(in) 
  {
    in.getline(str, 1000);  // delim defaults to '\n' cp
    if(in) cout << str << endl;
  }
  in.close();
  sleep(1);
  cout<<"\nStarting the program please wait....."<<endl;
  sleep(1);
  cout<<"\nloading up files....."<<endl;
  sleep(1); //function which waits for (n) seconds
  system ("CLS"); //cleares screen
  return 0;
	}
};
int main()
 {
 	welcome obj1; //object created for welcome class
	obj1.welcum(); //welcum function is called
 	string pass ="";
   char ch;
   cout<<"\n\n\n\n\n\n\n\n\t\t\t\t     PROGRAMMING 4LIFE SDN.BHD HUMANS' RESOURCES' \n\n";
   cout<<"\t\t\t\t\t------------------------------";
   cout<<"\n\t\t\t\t\t\t     LOGIN \n";	
   cout<<"\t\t\t\t\t------------------------------\n\n";	
   cout << "\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13)//character 13 is enter
   {
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "4life")
   {
      cout << "\n\n\n\t\t\t\t\t\tAccess Granted! \n";
      system("PAUSE");
      system ("CLS");
   }else{
      cout << "\n\n\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again\n\n";
      system("PAUSE");
      system("CLS");
      main();
   }
    Employee employees[MAX_EMPLOYEES];
    int numEmployees;
	int j=0;
    cout << "Enter how many employees you want to generate a payslip. "<<endl;
    cout << "Enter 1 for 1 employess(MAXIMUM EMPLOYESS = 100)        : ";
    cin >> numEmployees;
    cout <<"\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (numEmployees > MAX_EMPLOYEES|| numEmployees <0) 
	{
        cout << "Error: maximum number of employees is " << MAX_EMPLOYEES << " or musy be greater than negative value. Please re-enter: \n";        
        cin >>numEmployees;
    }
			for (int i = 0; i < numEmployees; i++) 
				{
   					 inputEmployeeData(employees, numEmployees,j);
   					 calculateWages(employees, numEmployees,j);
    				 calculateAbsentWages(employees, numEmployees,j);
   					 j++;
				}
displayPayslip(employees, numEmployees);
printToFile(employees, numEmployees);
    return 0;
}

void inputEmployeeData(Employee employees[], int numEmployees,int j)
{
   
        cout << "Enter employee " << j+1 << " name: ";
		getline(cin >> std::ws, employees[j].name);
		 cout <<"\n";
        cout << "Enter basic salary for " << employees[j].name << ": RM ";       
        cin >>employees[j].baseWage;
         cout <<"\n";
        while (employees[j].baseWage < 0)
	 {
            cout << "Error: base wage cannot be negative. Please re-enter: \n";           
            cin >>employees[j].baseWage;

     }
}

void calculateWages(Employee employees[], int numEmployees,int j) 
{

        float overtimeHours, overtimePay;
        
        cout << "Enter number of overtime hours done by " << employees[j].name<<endl ;
		cout << "in this month " << ": ";     
        cin >>overtimeHours;
         cout <<"\n";
        while (overtimeHours < 0) 
		{
            cout << "Error: overtime hours cannot be negative. Please re-enter: \n";            
            cin >>overtimeHours;
        }
        if (overtimeHours > 0) 
		{
            overtimePay = (employees[j].baseWage / REGULAR_HOURS) * OVERTIME_RATE * overtimeHours;
            employees[j].overtimeWage = overtimePay;
            employees[j].totalWage = employees[j].baseWage + overtimePay;
        } else {
            employees[j].overtimeWage = 0;
            employees[j].totalWage = employees[j].baseWage;
        }
    employees[j].overtimeHours= overtimeHours;
}

void calculateAbsentWages(Employee employees[], int numEmployees, int j) 
{
    int absentDays;
    float absentWage;
    cout << "Enter number of absent days for " << employees[j].name<<endl;
    cout << "ENTER 0 if this workers has no absent days" <<": ";
	cin >> absentDays;
	
	 cout <<"\n";
    while (absentDays < 0 || absentDays > 26) 
	{
        cout<< "Error: absent days cannot be negative or greater than 26. Please re-enter: \n";
		cin >> absentDays;
    }
    absentWage =  (absentDays*(employees[j].baseWage)/26);
    employees[j].totalWage -= absentWage;
    employees[j].absentDays = absentDays;
    employees[j].absentWage = absentWage;
}
void displayPayslip(Employee employees[], int numEmployees) 
{
    cout <<setw(15)<< "Payslip" << endl;
    cout <<"________________________________________________________________________________________________"<<endl;
    cout << setw(10) << "Name" << setw(15) << "Base Wage" << setw(15) << "Overtime Wage" << setw(15) << "Total Wage" << endl;
    cout <<"________________________________________________________________________________________________"<<endl;
    
    
    for (int i = 0; i < numEmployees; i++)
	{
        cout << setw(10) << employees[i].name << setw(15) << employees[i].baseWage << setw(15) << employees[i].overtimeWage << setw(15) << employees[i].totalWage << endl;
    	cout <<"_____________________________________________________________________________________________"<<endl;
    	cout <<"_____________________________________________________________________________________________"<<endl;
	} 
	
}

void printToFile(Employee employees[], int numEmployees) 
{
    ofstream myFile;
    myFile.open("wages.txt"); 
   	for (int i = 0; i < numEmployees; i++)
	{
	 for (int i = 0; i < numEmployees; i++) 
	 	{
	 		myFile << "\n\t\t                       PROGRAMMING 4LIFE SDN.BHD.                              "<<endl;
    	    myFile << "\n\t\t                      monthly payslip                              "<<endl;
    myFile << "\t\t	/////////////////////////////////////////////////////////////////////////////////////"<<endl;
    myFile << "\t\t	| Workers  Name   :"<<"------------------------------------|"<<employees[i].name  <<endl;            
    myFile << "\t\t	| Basic salary    :"<<"------------------------------------|"<<"RM "<<employees[i].baseWage   <<endl;  
    myFile << "\t\t	| overtime hours  :"<<"------------------------------------|"<< employees[i].overtimeHours   <<endl;  
    myFile << "\t\t	| overtime salary :"<<"------------------------------------|"<<"RM "<<employees[i].overtimeWage   <<endl; 
    myFile << "\t\t	| Absent days     :"<<"------------------------------------|"<<employees[i].absentDays  <<endl; 
	myFile << "\t\t	| Absent deductions:"<<"-----------------------------------|"<<"RM"<<employees[i].absentWage   <<endl;  
    myFile << "\t\t	| total salary    :"<<"------------------------------------|"<<"RM "<<employees[i].totalWage     <<endl;    
    myFile << "\t\t	 _____________________________________________________________________________________"<<endl;
    myFile << "\t\t	 # This is a computer generated payslip and it does not"<<endl;
    myFile << "\t\t	 require an authorised signture #"<<endl;
    myFile <<" "<<endl;
    myFile << "\t\t	//////////////////////////////////////////////////////////////////////////////////////"<<endl;
    myFile << "\t\t	keep the hardwork and dont ever give up in your life       "<<endl;
    myFile << "\t\t	thank you"<<endl;
    myFile << "\t\t	//////////////////////////////////////////////////////////////////////////////////////"<<endl;

		}
    myFile.close();
	}
}