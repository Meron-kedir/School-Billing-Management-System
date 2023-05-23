#include<iostream>
#include<string.h>
#include<cstdlib>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct record
{
	string name;
	string department;
	float dues;
	string month;
	int date, year;
	int roll_num;
	string fee_status;
};


//Capacity of Students
int cap_arts;
int cap_coms;
int cap_sciences;
int cap[3];

//Expensis of School
float teachers_salary;
float elect_bill=50;
float tax=70;
float staff_salary;
int exp[2];

//Dues for Each Department
float due_arts;
float due_coms;
float due_sciences;
int due[3];

//Number of Enrolled Students
int cnt_arts=0;
int cnt_coms=0;
int cnt_sciences=0;

//Array for Number of Students
record arts[50], coms[50], sciences[50];

void read();
void mainmenu();
void student();
void management();
void dept_capchange();
void arts_capchange();
void coms_capchange();
void sciences_capchange();
void sample();
void arts_duechange();
void coms_duechange();
void sciences_duechange();
void dept_duechange();
void change_salary();
void display();
void current_details();
void change_details();
void change_staffsalary();
void insert();
void new_arts();
void new_coms();
void new_sciences();
void del();
void del_arts();
void del_coms();
void del_sciences();
void search();
void search_arts();
void search_coms();
void search_sciences();
void update();
void update_arts();
void update_coms();
void update_sciences();
void sort(record *all[100],int size);
void merge();
void printArray(record all, int size);
void reciept();
void reciept_arts();
void reciept_coms();
void reciept_sciences();
template<class sdepartment>
void searchfor_all(sdepartment dep,int total);
int main()
{

 ifstream inputFile("capacity.txt");                   //Reading the values of capacity of students in different departments

    if (inputFile.good()) {
        int current_number = 0 , c=0;
        while (inputFile >> current_number){
            cap[c] = current_number ;
            c++;
        }
		inputFile.close();

		cap_arts = cap[0];
		cap_coms = cap[1];
		cap_sciences = cap[2];
}

 ifstream inputFile1("expenses.txt");       			//Reading the values of expensis of school

    if (inputFile1.good()) {
        int current_number = 0 , c=0;
        while (inputFile1 >> current_number){
            exp[c] = current_number ;
            c++;
        }
		inputFile1.close();

		teachers_salary = exp[0];
		staff_salary = exp[1];

}

 ifstream inputFile2("Dues.txt");       			//Reading the values of fees of students in different departments

    if (inputFile2.good()) {
        int current_number = 0 , c=0;
        while (inputFile2 >> current_number){
            due[c] = current_number ;
            c++;
        }
		inputFile2.close();

		due_arts = due[0];
		due_coms = due[1];
		due_sciences = due[2];

}


	sample();
	mainmenu();

//	display();
}

void reciept_arts()										//This method generates the reciept for arts student
{
	int roll,check=0;
	cout<<"Enter the Roll Number : ";
	cin>>roll;

	for(int i=0;i<cnt_arts;i++)
	{
		if(roll==arts[i].roll_num)													//Searching for the existance of record
		{
			cout<<"--------------------------------------------"<<endl;
			cout<<"-----------Arts Department Reciept-----------"<<endl<<endl;
			cout<<"Roll Number : "<<arts[i].roll_num<<endl;									//Printing reciept
			cout<<"Name : "<<arts[i].name<<endl;
			cout<<"Department : "<<arts[i].department<<endl;
			cout<<"Dues : "<<arts[i].dues<<endl;
			cout<<"Fee Status : "<<arts[i].fee_status<<endl;
			cout<<"Date to Pay Fees: "<<arts[i].date<<"th"<<endl<<endl;

			check++;
		}
	}

	if(check==0)
	{
		cout<<"No Record Found!\n\n";
	}
	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}

void reciept_coms()										//This method generates the reciept for commerce student
{
	int roll,check=0;
	cout<<"Enter the Roll Number : ";
	cin>>roll;

	for(int i=0;i<cnt_coms;i++)
	{
		if(roll==coms[i].roll_num)												//Searching for the existance of record
		{
			cout<<"--------------------------------------------"<<endl;
			cout<<"-----------Commerce Department Reciept-----------"<<endl<<endl;
			cout<<"Roll Number : "<<coms[i].roll_num<<endl;									//printing reciept
			cout<<"Name : "<<coms[i].name<<endl;
			cout<<"Department : "<<coms[i].department<<endl;
			cout<<"Dues : "<<coms[i].dues<<endl;
			cout<<"Fee Status : "<<coms[i].fee_status<<endl;
			cout<<"Date to Pay Fees: "<<coms[i].date<<"th"<<endl<<endl;

			check++;
		}
	}

	if(check==0)
	{
		cout<<"No Record Found!\n\n";
	}
	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}

void reciept_sciences()													//This method generates the reciept for sciences student
{
	int roll,check=0;
	cout<<"Enter the Roll Number : ";
	cin>>roll;

	for(int i=0;i<cnt_sciences;i++)
	{
		if(roll==sciences[i].roll_num)										//Searching for the existance of record
		{
			cout<<"--------------------------------------------"<<endl;
			cout<<"-----------Arts Department Reciept-----------"<<endl<<endl;
			cout<<"Roll Number : "<<sciences[i].roll_num<<endl;						//Printing reciept
			cout<<"Name : "<<sciences[i].name<<endl;
			cout<<"Department : "<<sciences[i].department<<endl;
			cout<<"Dues : "<<sciences[i].dues<<endl;
			cout<<"Fee Status : "<<sciences[i].fee_status<<endl;
			cout<<"Date to Pay Fees: "<<sciences[i].date<<"th"<<endl<<endl;

			check++;
		}
	}

	if(check==0)
	{
		cout<<"No Record Found!\n\n";
	}
	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}

void reciept()										//Getting department to generate reciept of specific department's student
{
	string choice;
	cout<<"Enter Department by Entering Option Number"<<endl;
	cout<<"1-> Arts"<<endl;
	cout<<"2-> Commerce"<<endl;
	cout<<"3-> Sciences"<<endl;
	cout<<"0-> Go back to Main Menu"<<endl<<endl;
	cin>>choice;

	system("cls");

	if(choice=="1")
	{
		reciept_arts();
	}
	else if(choice=="2")
	{
		reciept_coms();
	}
	else if(choice=="3")
	{
		reciept_sciences();
	}
	else if(choice=="0")
	{
		mainmenu();
	}
	else
	{
		reciept();
	}
}

void sort(record *all,int size)									//Sort the record with respect to the student name
{


	string choice;
	cout<<"Enter Order by Entering Option Number"<<endl;
	cout<<"1-> Ascending Order"<<endl;
	cout<<"2-> Descending Order"<<endl;
	cout<<"0-> Go back to Main Menu"<<endl<<endl;
	cin>>choice;

	system("cls");

	if(choice=="1")
	{
		int i, j, key1,key5,key7;
		float key2;
		string key,key3,key4,key6;
	    for (i = 1; i < size; i++)
	    {
	        key = all[i].name;
	        key1 = all[i].roll_num;
	        key2 = all[i].dues;
	        key3 = all[i].fee_status;
	        key4 = all[i].department;
	        key5 = all[i].date;
	        key6 = all[i].month;
	        key7 = all[i].year;

	        j = i - 1;

	        /* Move elements of arr[0..i-1], that are
	        greater than key, to one position ahead
	        of their current position */
	        while (j >= 0 && all[j].name > key)										//Using Insertion sort algorithm to sort record in ascending order
	        {
	            all[j + 1].name = all[j].name;
	            all[j + 1].dues = all[j].dues;
	            all[j + 1].year = all[j].year;
	            all[j + 1].date = all[j].date;
	            all[j + 1].month = all[j].month;
	            all[j + 1].roll_num = all[j].roll_num;
	            all[j + 1].fee_status = all[j].fee_status;
	            all[j + 1].department = all[j].department;
	            j = j - 1;
	        }
	        all[j + 1].name = key;
	        all[j + 1].roll_num = key1;
	        all[j + 1].dues = key2;
	        all[j + 1].fee_status = key3;
	        all[j + 1].department = key4;
	        all[j + 1].date = key5;
	        all[j + 1].month = key6;
	        all[j + 1].year = key7;
	    }
	}
	else if(choice=="2")
	{
		int i, j, key1,key5,key7;
		float key2;
		string key,key3,key4,key6;
	    for (i = 1; i < size; i++)
	    {
	        key = all[i].name;
	        key1 = all[i].roll_num;
	        key2 = all[i].dues;
	        key3 = all[i].fee_status;
	        key4 = all[i].department;
	        key5 = all[i].date;
	        key6 = all[i].month;
	        key7 = all[i].year;

	        j = i - 1;

	        /* Move elements of arr[0..i-1], that are
	        greater than key, to one position ahead
	        of their current position */
	        while (j >= 0 && all[j].name < key)										//Using Insertion sort algorithm to sort record in descending order
	        {
	            all[j + 1].name = all[j].name;
	            all[j + 1].dues = all[j].dues;
	            all[j + 1].year = all[j].year;
	            all[j + 1].date = all[j].date;
	            all[j + 1].month = all[j].month;
	            all[j + 1].roll_num = all[j].roll_num;
	            all[j + 1].fee_status = all[j].fee_status;
	            all[j + 1].department = all[j].department;
	            j = j - 1;
	        }
	        all[j + 1].name = key;
	        all[j + 1].roll_num = key1;
	        all[j + 1].dues = key2;
	        all[j + 1].fee_status = key3;
	        all[j + 1].department = key4;
	        all[j + 1].date = key5;
	        all[j + 1].month = key6;
	        all[j + 1].year = key7;
	    }
	}
	else if(choice=="0")
	{
		mainmenu();
	}
	else{
		mainmenu();
	}

	cout<<"Sorted By Name\n\n";													//Printing the sorted record
	for (int i = 0; i < size; i++)
	{
		cout<<"Roll Number : "<<all[i].roll_num<<endl;
		cout<<"Name : "<<all[i].name<<endl;
		cout<<"Department : "<<all[i].department<<endl;
		cout<<"Dues : "<<all[i].dues<<endl;
		cout<<"Fee Status : "<<all[i].fee_status<<endl;
		cout<<"Date : "<<all[i].date<<"-"<<all[i].month<<"-"<<all[i].year<<endl<<endl;
	}
	cout << endl;
}


void merge()														//To merge all the different arrays into one single array
{
	record all[100];
	int size=cnt_arts+cnt_sciences+cnt_coms;
	int count=0;
	for(int i=0;i<cnt_sciences;i++)
	{
		all[count].roll_num=sciences[i].roll_num;
		all[count].name=sciences[i].name;
		all[count].department=sciences[i].department;
		all[count].dues=sciences[i].dues;
		all[count].fee_status=sciences[i].fee_status;
		all[count].date=sciences[i].date;
		all[count].month=sciences[i].month;
		all[count].year=sciences[i].year;
		count++;
	}
	for(int i=0;i<cnt_coms;i++)
	{
		all[count].roll_num=coms[i].roll_num;
		all[count].name=coms[i].name;
		all[count].department=coms[i].department;
		all[count].dues=coms[i].dues;
		all[count].fee_status=coms[i].fee_status;
		all[count].date=coms[i].date;
		all[count].month=coms[i].month;
		all[count].year=coms[i].year;
		count++;
	}
	for(int i=0;i<cnt_arts;i++)
	{
		all[count].roll_num=arts[i].roll_num;
		all[count].name=arts[i].name;
		all[count].department=arts[i].department;
		all[count].dues=arts[i].dues;
		all[count].fee_status=arts[i].fee_status;
		all[count].date=arts[i].date;
		all[count].month=arts[i].month;
		all[count].year=arts[i].year;
		count++;
	}

	sort(all, size);												//passing in sort() to sort the record and print

	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}

void student()
{
	int choice;
	cout<<"Enter your choice by entering number"<<endl<<endl;
	cout<<"1-> Print All Entries"<<endl;
	cout<<"2-> Insert a New Record"<<endl;
	cout<<"3-> Delete a Record"<<endl;
	cout<<"4-> Search for Record"<<endl;
	cout<<"5-> Update Existing Student Record"<<endl;
	cout<<"6-> Sort Record"<<endl;
	cout<<"0-> Go back to Main Menu"<<endl<<endl;

	cin>>choice;
	system("cls");

	if(choice==1)
	{
		display();
	}
	else if (choice==2)
	{
		insert();
	}
	else if (choice==3)
	{
		del();
	}
	else if (choice==4)
	{
		search();
	}
	else if (choice==5)
	{
		update();
	}
	else if (choice==6)
	{
		merge();
	}
	else if (choice==0)
	{
		mainmenu();
	}
	else{
		dept_duechange();
	}
}

void del_arts()													//delete record from arts department
{
	int roll;

	cout<<"Enter the Roll Number : ";
	cin>>roll;

	int check=0;

	for(int i=0;i<cnt_arts;i++)
	{
		if(roll==arts[i].roll_num)										//Searching for record to be deleted
		{
			cout<<"The Data to be Deleted is :\n\n";
			cout<<"Roll No. : "<<arts[i].roll_num<<endl;
			cout<<"Name : "<<arts[i].name<<endl;
			cout<<"Department : "<<arts[i].department<<endl;				//Printing the deleted record
			cout<<"Dues : "<<arts[i].dues<<endl;
			cout<<"Fee Status : "<<arts[i].fee_status<<endl;
			cout<<"Date : "<<arts[i].date<<"-"<<arts[i].month<<"-"<<arts[i].year<<endl<<endl;
			check++;

			for(int j=i; j<cnt_arts; j++)
			{
				arts[j].roll_num=arts[j+1].roll_num;
				arts[j].name=arts[j+1].name;
				arts[j].department=arts[j+1].department;
				arts[j].dues=arts[j+1].dues;
				arts[j].fee_status=arts[j+1].fee_status;
				arts[j].date=arts[j+1].date;
				arts[j].month=arts[j+1].month;
				arts[j].year=arts[j+1].year;
			}

			cnt_arts--;
		}
	}
	if(check==0)
	{
		cout<<"No Record Found"<<endl<<endl;
	}
	else
	{
		cout<<"Record Deleted\n\n";
	}
	ofstream MyFile3("arts_record.txt");						//Opening the file

	for(int i=0;i<cnt_arts;i++)
	{
		MyFile3 << arts[i].name<<endl;
		  MyFile3 << arts[i].department<<endl;					//Writing the updated data into the file
		  MyFile3 << arts[i].dues<<endl;
		  MyFile3 << arts[i].date<<endl;
		  MyFile3 << arts[i].month<<endl;
		  MyFile3 << arts[i].year<<endl;
		  MyFile3 << arts[i].roll_num<<endl;
		  MyFile3 << arts[i].fee_status<<endl;
	}
  // Write to the file

	  MyFile3.close();
	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}

void del_coms()							//Deleting the record from commerce department
{
	int roll;

	cout<<"Enter the Roll Number : ";
	cin>>roll;

	int check=0;

	for(int i=0;i<cnt_coms;i++)
	{
		if(roll==coms[i].roll_num)								//Searching for record to be deleted
		{
			cout<<"The Data to be Deleted is :\n\n";
			cout<<"Roll No. : "<<coms[i].roll_num<<endl;
			cout<<"Name : "<<coms[i].name<<endl;
			cout<<"Department : "<<coms[i].department<<endl;						//Printing deleted record
			cout<<"Dues : "<<coms[i].dues<<endl;
			cout<<"Fee Status : "<<coms[i].fee_status<<endl;
			cout<<"Date : "<<coms[i].date<<"-"<<coms[i].month<<"-"<<coms[i].year<<endl<<endl;
			check++;

			for(int j=i; j<cnt_coms; j++)
			{
				coms[j].roll_num=coms[j+1].roll_num;
				coms[j].name=coms[j+1].name;
				coms[j].department=coms[j+1].department;
				coms[j].dues=coms[j+1].dues;										//Deleting Record
				coms[j].fee_status=coms[j+1].fee_status;
				coms[j].date=coms[j+1].date;
				coms[j].month=coms[j+1].month;
				coms[j].year=coms[j+1].year;
			}

			cnt_coms--;
		}
	}
	if(check==0)
	{
		cout<<"No Record Found"<<endl<<endl;
	}
	else
	{
		cout<<"Record Deleted\n\n";
	}
	ofstream MyFile3("coms_record.txt");								//Opening file

	for(int i=0;i<cnt_coms;i++)
	{
		MyFile3 << coms[i].name<<endl;
		  MyFile3 << coms[i].department<<endl;
		  MyFile3 << coms[i].dues<<endl;									//Writing updated record in file
		  MyFile3 << coms[i].date<<endl;
		  MyFile3 << coms[i].month<<endl;
		  MyFile3 << coms[i].year<<endl;
		  MyFile3 << coms[i].roll_num<<endl;
		  MyFile3 << coms[i].fee_status<<endl;
	}
  // Write to the file

	  MyFile3.close();
	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}

void del_sciences()											//Deleting record from sciences department
{
	int roll;

	cout<<"Enter the Roll Number : ";
	cin>>roll;

	int check=0;

	for(int i=0;i<cnt_sciences;i++)
	{
		if(roll==sciences[i].roll_num)								//Searching for the record to be deleted
		{
			cout<<"The Data to be Deleted is :\n\n";
			cout<<"Roll No. : "<<sciences[i].roll_num<<endl;
			cout<<"Name : "<<sciences[i].name<<endl;
			cout<<"Department : "<<sciences[i].department<<endl;				//Printing the deleted record
			cout<<"Dues : "<<sciences[i].dues<<endl;
			cout<<"Fee Status : "<<sciences[i].fee_status<<endl;
			cout<<"Date : "<<sciences[i].date<<"-"<<sciences[i].month<<"-"<<sciences[i].year<<endl<<endl;
			check++;

			for(int j=i; j<cnt_sciences; j++)
			{
				sciences[j].roll_num=sciences[j+1].roll_num;
				sciences[j].name=sciences[j+1].name;
				sciences[j].department=sciences[j+1].department;
				sciences[j].dues=sciences[j+1].dues;								//Deleting the record
				sciences[j].fee_status=sciences[j+1].fee_status;
				sciences[j].date=sciences[j+1].date;
				sciences[j].month=sciences[j+1].month;
				sciences[j].year=sciences[j+1].year;
			}

			cnt_sciences--;
		}
	}
	ofstream MyFile3("sciences_record.txt");									//Opening the file

	for(int i=0;i<cnt_sciences;i++)
	{
		MyFile3 << sciences[i].name<<endl;
		  MyFile3 << sciences[i].department<<endl;
		  MyFile3 << sciences[i].dues<<endl;
		  MyFile3 << sciences[i].date<<endl;									//Writing updated data into the file
		  MyFile3 << sciences[i].month<<endl;
		  MyFile3 << sciences[i].year<<endl;
		  MyFile3 << sciences[i].roll_num<<endl;
		  MyFile3 << sciences[i].fee_status<<endl;
	}
  // Write to the file

	  MyFile3.close();
	if(check==0)
	{
		cout<<"No Record Found"<<endl<<endl;
	}
	else
	{
		cout<<"Record Deleted\n\n";
	}
	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}

void del()												//Getting department name to delete data of
{
	string choice;
	cout<<"Enter the Department by Entering Option Number"<<endl;
	cout<<"1-> Arts"<<endl;
	cout<<"2-> Commerce"<<endl;
	cout<<"3-> Sciences"<<endl;
	cout<<"0-> Go back to Main Menu"<<endl<<endl;
	cin>>choice;

	system("cls");

	if(choice=="1")
	{
		del_arts();
	}
	else if(choice=="2")
	{
		del_coms();
	}
	else if(choice=="3")
	{
		del_sciences();
	}
	else if(choice=="0")
	{
		mainmenu();
	}
	else{
		del();
	}
}


void update_arts()										//To Update record in arts department
{
	int roll;

	cout<<"Enter the Roll Number : ";
	cin>>roll;

	int check=0;

	for(int i=0;i<cnt_arts;i++)
	{
		if(roll==arts[i].roll_num)							//Search for the data to be updated
		{
			cout<<"The Current Data is :\n\n";
			cout<<"Roll No. : "<<arts[i].roll_num<<endl;
			cout<<"Name : "<<arts[i].name<<endl;
			cout<<"Department : "<<arts[i].department<<endl;
			cout<<"Dues : "<<arts[i].dues<<endl;								//Printing the data to be updated
			cout<<"Fee Status : "<<arts[i].fee_status<<endl;
			cout<<"Date : "<<arts[i].date<<"-"<<arts[i].month<<"-"<<arts[i].year<<endl<<endl;
			check++;

			cout<<"Please Enter Updated Data\n\n";
			cout<<"Enter Updated Name : ";
			cin>>arts[i].name;												//Getting updated data
			cout<<"Enter Updated Date of Joining : ";
			cin>>arts[i].date;
			cout<<"Enter Updated Month of Joining : ";
			cin>>arts[i].month;
			cout<<"Enter Updated Year of Joining : ";
			cin>>arts[i].year;
			string choice;
			cout<<"Enter Updated Fee Status by Entering Number : \n1-> Paid\n2-> Unpaid";
			cin>>choice;
			if(choice=="1")
			{
				arts[i].fee_status="paid";
			}
			else
			{
				arts[i].fee_status="unpaid";
			}
		}
	}
	ofstream MyFile3("arts_record.txt");									//Opening file

	for(int i=0;i<cnt_arts;i++)
	{
		MyFile3 << arts[i].name<<endl;
		  MyFile3 << arts[i].department<<endl;
		  MyFile3 << arts[i].dues<<endl;									//Writing updated data into the file
		  MyFile3 << arts[i].date<<endl;
		  MyFile3 << arts[i].month<<endl;
		  MyFile3 << arts[i].year<<endl;
		  MyFile3 << arts[i].roll_num<<endl;
		  MyFile3 << arts[i].fee_status<<endl;
	}
  // Write to the file

	  MyFile3.close();													//Closing File
	if(check==0)
	{
		cout<<"No Record Found"<<endl<<endl;
	}
	else
	{
		cout<<"Record Updated\n\n";
	}
	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}

void update_coms()												//Updating commerce record
{
	int roll;

	cout<<"Enter the Roll Number : ";
	cin>>roll;

	int check=0;

	for(int i=0;i<cnt_coms;i++)
	{
		if(roll==coms[i].roll_num)											//Search for record
		{
			cout<<"The Current Data is :\n\n";
			cout<<"Roll No. : "<<coms[i].roll_num<<endl;
			cout<<"Name : "<<coms[i].name<<endl;
			cout<<"Department : "<<coms[i].department<<endl;				//Printing the data to be updated
			cout<<"Dues : "<<coms[i].dues<<endl;
			cout<<"Fee Status : "<<coms[i].fee_status<<endl;
			cout<<"Date : "<<coms[i].date<<"-"<<coms[i].month<<"-"<<coms[i].year<<endl<<endl;
			check++;

			cout<<"Please Enter Updated Data\n\n";
			cout<<"Enter Updated Name : ";
			cin>>coms[i].name;
			cout<<"Enter Updated Date of Joining : ";
			cin>>coms[i].date;
			cout<<"Enter Updated Month of Joining : ";							//Getting values to update
			cin>>coms[i].month;
			cout<<"Enter Updated Year of Joining : ";
			cin>>coms[i].year;
			string choice;
			cout<<"Enter Updated Fee Status by Entering Number : \n1-> Paid\n2-> Unpaid";
			cin>>choice;
			if(choice=="1")
			{
				coms[i].fee_status="paid";
			}
			else
			{
				coms[i].fee_status="unpaid";
			}
		}
	}

	ofstream MyFile3("coms_record.txt");										//Opening file

	for(int i=0;i<cnt_coms;i++)
	{
		MyFile3 << coms[i].name<<endl;
		  MyFile3 << coms[i].department<<endl;
		  MyFile3 << coms[i].dues<<endl;
		  MyFile3 << coms[i].date<<endl;										//Writing updated record into the file
		  MyFile3 << coms[i].month<<endl;
		  MyFile3 << coms[i].year<<endl;
		  MyFile3 << coms[i].roll_num<<endl;
		  MyFile3 << coms[i].fee_status<<endl;
	}
  // Write to the file

	  MyFile3.close();															//Closing file
	if(check==0)
	{
		cout<<"No Record Found"<<endl<<endl;
	}
	else
	{
		cout<<"Record Updated\n\n";
	}
	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}

void update_sciences()													//To update record in science department
{
	int roll;

	cout<<"Enter the Roll Number : ";
	cin>>roll;

	int check=0;

	for(int i=0;i<cnt_sciences;i++)
	{
		if(roll==sciences[i].roll_num)										//Searching for record
		{
			cout<<"The Current Data is :\n\n";
			cout<<"Roll No. : "<<sciences[i].roll_num<<endl;
			cout<<"Name : "<<sciences[i].name<<endl;
			cout<<"Department : "<<sciences[i].department<<endl;				//Printing data to be updated
			cout<<"Dues : "<<sciences[i].dues<<endl;
			cout<<"Fee Status : "<<sciences[i].fee_status<<endl;
			cout<<"Date : "<<sciences[i].date<<"-"<<sciences[i].month<<"-"<<sciences[i].year<<endl<<endl;
			check++;

			cout<<"Please Enter Updated Data\n\n";
			cout<<"Enter Updated Name : ";
			cin>>sciences[i].name;
			cout<<"Enter Updated Date of Joining : ";								//Getting values to be updated
			cin>>sciences[i].date;
			cout<<"Enter Updated Month of Joining : ";
			cin>>sciences[i].month;
			cout<<"Enter Updated Year of Joining : ";
			cin>>sciences[i].year;
			string choice;
			cout<<"Enter Updated Fee Status by Entering Number : \n1-> Paid\n2-> Unpaid";
			cin>>choice;
			if(choice=="1")
			{
				sciences[i].fee_status="paid";
			}
			else
			{
				sciences[i].fee_status="unpaid";
			}
		}
	}
	ofstream MyFile3("sciences_record.txt");									//Opening file

	for(int i=0;i<cnt_sciences;i++)
	{
		MyFile3 << sciences[i].name<<endl;
		  MyFile3 << sciences[i].department<<endl;							//Writing updated record into the file
		  MyFile3 << sciences[i].dues<<endl;
		  MyFile3 << sciences[i].date<<endl;
		  MyFile3 << sciences[i].month<<endl;
		  MyFile3 << sciences[i].year<<endl;
		  MyFile3 << sciences[i].roll_num<<endl;
		  MyFile3 << sciences[i].fee_status<<endl;
	}
  // Write to the file

	  MyFile3.close();															//Closing file
	if(check==0)
	{
		cout<<"No Record Found"<<endl<<endl;
	}
	else
	{
		cout<<"Record Updated\n\n";
	}
	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}

void update()													//Getting department name to update value
{
	string choice;
	cout<<"Enter the Department by Entering Option Number"<<endl;
	cout<<"1-> Arts"<<endl;
	cout<<"2-> Commerce"<<endl;
	cout<<"3-> Sciences"<<endl;
	cout<<"0-> Go back to Main Menu"<<endl<<endl;
	cin>>choice;

	system("cls");

	if(choice=="1")
	{
		update_arts();
	}
	else if(choice=="2")
	{
		update_coms();
	}
	else if(choice=="3")
	{
		update_sciences();
	}
	else if(choice=="0")
	{
		mainmenu();
	}
	else{
		update();
	}
}


void search_arts()
{
	searchfor_all(arts,cnt_arts);
}

void search_coms()
{
searchfor_all(coms,cnt_coms);
}

void search_sciences()
{
 searchfor_all(sciences,cnt_sciences);
}

template<class sdepartment>
void searchfor_all(sdepartment dep,int total)
{
	int roll;

	cout<<"Enter the Roll Number : ";
	cin>>roll;

	int check=0;


	for(int i=0;i<cnt_sciences;i++)
	{
		if(roll==dep[i].roll_num)
		{
			cout<<"Roll No. : "<<dep[i].roll_num<<endl;
			cout<<"Name : "<<dep[i].name<<endl;
			cout<<"Department : "<<dep[i].department<<endl;
			cout<<"Dues : "<<dep[i].dues<<endl;
			cout<<"Fee Status : "<<dep[i].fee_status<<endl;
			cout<<"Date : "<<dep[i].date<<"-"<<dep[i].month<<"-"<<dep[i].year<<endl<<endl;
			check++;
		}
	}
	if(check==0)
	{
		cout<<"No Record Found"<<endl<<endl;
	}
	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}


void search()							//getting department name to search data
{
	string choice;
	cout<<"Enter the Department by Entering Option Number"<<endl;
	cout<<"1-> Arts"<<endl;
	cout<<"2-> Commerce"<<endl;
	cout<<"3-> Sciences"<<endl;
	cout<<"0-> Go back to Main Menu"<<endl<<endl;
	cin>>choice;

	system("cls");

	if(choice=="1")
	{
		search_arts();
	}
	else if(choice=="2")
	{
		search_coms();
	}
	else if(choice=="3")
	{
		search_sciences();
	}
	else if(choice=="0")
	{
		mainmenu();
	}
	else{
		search();
	}
}

void new_arts()												//To enter new data in arts department
{
	cout<<"Enter Your Name : ";
	cin>>arts[cnt_arts].name;
	cout<<"Enter Date of Joining : ";
	cin>>arts[cnt_arts].date;
	cout<<"Enter Month of Joining : ";
	cin>>arts[cnt_arts].month;									//Getting data to save
	cout<<"Enter Year of Joining : ";
	cin>>arts[cnt_arts].year;
	string choice;
	cout<<"Enter Fee Status by Entering Number : \n1-> Paid\n2-> Unpaid";
	cin>>choice;
	if(choice=="1")
	{
		arts[cnt_arts].fee_status="paid";
	}
	else
	{
		arts[cnt_arts].fee_status="unpaid";
	}
	arts[cnt_arts].dues=due_arts;
	arts[cnt_arts].department="Arts";
	arts[cnt_arts].roll_num=cnt_arts;

	cnt_arts++;

	ofstream MyFile3("arts_record.txt");						//Opening file

	for(int i=0;i<cnt_arts;i++)
	{
		MyFile3 << arts[i].name<<endl;
		  MyFile3 << arts[i].department<<endl;
		  MyFile3 << arts[i].dues<<endl;
		  MyFile3 << arts[i].date<<endl;						//Writing data into the file
		  MyFile3 << arts[i].month<<endl;
		  MyFile3 << arts[i].year<<endl;
		  MyFile3 << arts[i].roll_num<<endl;
		  MyFile3 << arts[i].fee_status<<endl;
	}
  // Write to the file

	  MyFile3.close();												//Closing file

	system("cls");
	mainmenu();
}

void new_coms()										//Enter record into the commerce department
{
	cout<<"Enter Your Name : ";
	cin>>coms[cnt_coms].name;
	cout<<"Enter Date of Joining : ";
	cin>>coms[cnt_coms].date;
	cout<<"Enter Month of Joining : ";							//getting the record to save
	cin>>coms[cnt_coms].month;
	cout<<"Enter Year of Joining : ";
	cin>>coms[cnt_coms].year;
	string choice;
	cout<<"Enter Fee Status by Entering Number : \n1-> Paid\n2-> Unpaid";
	cin>>choice;
	if(choice=="1")
	{
		coms[cnt_coms].fee_status="paid";
	}
	else
	{
		coms[cnt_coms].fee_status="unpaid";
	}
	coms[cnt_coms].dues=due_coms;
	coms[cnt_coms].department="Commerce";
	coms[cnt_coms].roll_num=cnt_coms;

	cnt_coms++;

	ofstream MyFile3("coms_record.txt");						//Opening file

	for(int i=0;i<cnt_coms;i++)
	{
		MyFile3 << coms[i].name<<endl;
		  MyFile3 << coms[i].department<<endl;
		  MyFile3 << coms[i].dues<<endl;						//Writing data into the file
		  MyFile3 << coms[i].date<<endl;
		  MyFile3 << coms[i].month<<endl;
		  MyFile3 << coms[i].year<<endl;
		  MyFile3 << coms[i].roll_num<<endl;
		  MyFile3 << coms[i].fee_status<<endl;
	}
  // Write to the file

	  MyFile3.close();											//Closing file

	system("cls");
	mainmenu();
}

void new_sciences()												//Entering new record in science department
{
	cout<<"Enter Your Name : ";
	cin>>sciences[cnt_sciences].name;
	cout<<"Enter Date of Joining : ";
	cin>>sciences[cnt_sciences].date;
	cout<<"Enter Month of Joining : ";							//getting data to save into the file
	cin>>sciences[cnt_sciences].month;
	cout<<"Enter Year of Joining : ";
	cin>>sciences[cnt_sciences].year;
	string choice;
	cout<<"Enter Fee Status by Entering Number : \n1-> Paid\n2-> Unpaid";
	cin>>choice;
	if(choice=="1")
	{
		sciences[cnt_sciences].fee_status="paid";
	}
	else
	{
		sciences[cnt_sciences].fee_status="unpaid";
	}

	sciences[cnt_sciences].dues=due_sciences;
	sciences[cnt_sciences].department="Sciences";
	sciences[cnt_sciences].roll_num=cnt_sciences;

	cnt_sciences++;
	ofstream MyFile3("sciences_record.txt");						//Opening the file

	for(int i=0;i<cnt_sciences;i++)
	{
		MyFile3 << sciences[i].name<<endl;
		  MyFile3 << sciences[i].department<<endl;
		  MyFile3 << sciences[i].dues<<endl;
		  MyFile3 << sciences[i].date<<endl;							//Writing data into the file
		  MyFile3 << sciences[i].month<<endl;
		  MyFile3 << sciences[i].year<<endl;
		  MyFile3 << sciences[i].roll_num<<endl;
		  MyFile3 << sciences[i].fee_status<<endl;
	}
  // Write to the file

	  MyFile3.close();												//Closing te file



	system("cls");
	mainmenu();
}

void insert()																	//getting department name to enter new record
{
	string choice;
	cout<<"Enter your choice by entering number"<<endl<<endl;
	cout<<"Select the Department for Student"<<endl<<endl;
	cout<<"1-> Sciences"<<endl;
	cout<<"2-> Arts"<<endl;
	cout<<"3-> Commerce"<<endl;
	cout<<"0-> Go back to Main Menu"<<endl<<endl;

	cin>>choice;
	system("cls");

	if (choice=="1")
	{
		new_sciences();
	}
	else if (choice=="2")
	{
		new_arts();
	}
	else if (choice=="3")
	{
		new_coms();
	}
	else if (choice=="0")
	{
		mainmenu();
	}
	else
	{
		insert();
	}
}



void dept_duechange()								//To change the dues of departments
{
	int choice;
	cout<<"Enter your choice by entering number"<<endl<<endl;
	cout<<"1-> Change Due of Arts Department"<<endl;
	cout<<"2-> Change Due of Sciences Department"<<endl;
	cout<<"3-> Change Due of Commerce Department"<<endl;
	cout<<"0-> Go back to Main Menu"<<endl<<endl;

	cin>>choice;									//getting name of the department
	system("cls");

	if(choice==1)
	{
		arts_duechange();
	}
	else if (choice==2)
	{
		sciences_duechange();
	}
	else if (choice==3)
	{
		coms_duechange();
	}
	else if (choice==0)
	{
		mainmenu();
	}
	else{
		dept_duechange();
	}
}

void arts_capchange()							//To change the capacity of students in arts departments
{
	cout<<"Current Capacity of Students in Arts Dept. is "<<cap_arts<<endl<<endl;		//Printing old capacity of students

	float newamount;
	cout<<"Enter the New Capacity for the Arts Dept. : ";
	cin>>newamount;																	//Getting new capacity

	if(newamount<cnt_arts)
	{
		system("cls");
		cout<<"Error: New Capacity was Less than Already Enrolled Students. Please Try Again\n\n";			//Exception
		arts_capchange();
	}
	else
	{
		cap_arts=newamount;
		cap[0]= cap_arts ;

		ofstream capFile1 ("capacity.txt");								//Opening file
		  capFile1 << cap[0]<<"\n";
		  capFile1 << cap[1]<<"\n";										//Writing value in file
		  capFile1 << cap[2]<<"\n";
		capFile1.close();												//Closing file

		cout<<endl<<endl<<"\n\nCapacity Updated\n\n";
		string x;
		cout << "Enter any key to go back to Main Menu :";
		cin>>x;
		if (x == "a")
		{
			system("cls");
			mainmenu();
		}
		else {
			system("cls");
			mainmenu();
		}
	}
}

void coms_capchange()										//Changing capacity of students in commerce department
{
	cout<<"Current Capacity of Students in Commerce Dept. is "<<cap_coms<<endl<<endl;		//Printing old capacity of students

	float newamount;
	cout<<"Enter the New Capacity for the Arts Dept. : ";
	cin>>newamount;																//getting new value for capacity

	if(newamount<cnt_coms)
	{
		system("cls");
		cout<<"Error: New Capacity was Less than Already Enrolled Students. Please Try Again\n\n";					//Exception
		coms_capchange();
	}
	else
	{
		cap_coms=newamount;                             						//Setting new value

		cap[1]= cap_coms ;

		ofstream capFile2 ("capacity.txt");										//Opening file
		  capFile2 << cap[0]<<"\n";
		  capFile2 << cap[1]<<"\n";												//Writing updated value in file
		  capFile2 << cap[2]<<"\n";
		capFile2.close();														//Closing file
		cout<<endl<<endl<<"\n\nCapacity Updated\n\n";
		string x;
		cout << "Enter any key to go back to Main Menu :";
		cin>>x;
		if (x == "a")
		{
			system("cls");
			mainmenu();
		}
		else {
			system("cls");
			mainmenu();
		}
	}
}

void sciences_capchange()														//Chaning the capacity of students in sciences department
{
	cout<<"Current Capacity of Students in Commerce Dept. is "<<cap_sciences<<endl<<endl;				//Displaying old capacity of students

	float newamount;																			//getting new capacity to be updated
	cout<<"Enter the New Capacity for the Arts Dept. : ";
	cin>>newamount;

	if(newamount<cnt_sciences)
	{
		system("cls");
		cout<<"Error: New Capacity was Less than Already Enrolled Students. Please Try Again\n\n";				//excpetion
		sciences_capchange();
	}
	else
	{
		cap_sciences=newamount;                             			//setting new capacity

		cap[2]= cap_sciences ;

		ofstream capFile3 ("capacity.txt");									//Opening file
		  capFile3 << cap[0]<<"\n";
		  capFile3 << cap[1]<<"\n";											//Writing value into the file
		  capFile3 << cap[2]<<"\n";
		capFile3.close();													//Closing file
		cout<<endl<<endl<<"\n\nCapacity Updated\n\n";
		string x;
		cout << "Enter any key to go back to Main Menu :";
		cin>>x;
		if (x == "a")
		{
			system("cls");
			mainmenu();
		}
		else {
			system("cls");
			mainmenu();
		}
	}
}

void dept_capchange()															//Change the capacity of different departments
{
	int choice;
	cout<<"Enter your choice by entering number"<<endl<<endl;
	cout<<"1-> Change Student Capacity of Arts Department"<<endl;
	cout<<"2-> Change Student Capacity of Sciences Department"<<endl;
	cout<<"3-> Change Student Capacity of Commerce Department"<<endl;
	cout<<"0-> Go back to Main Menu"<<endl<<endl;

	cin>>choice;															//getting name of department
	system("cls");

	if(choice==1)
	{
		arts_capchange();
	}
	else if (choice==2)
	{
		sciences_capchange();
	}
	else if (choice==3)
	{
		coms_capchange();
	}
	else if (choice==0)
	{
		mainmenu();
	}
	else
	{
		dept_capchange();
	}
}

void change_details()									//Chaning details main menu
{
	int choice;
	cout<<"Enter your choice by entering number"<<endl<<endl;
	cout<<"1-> Change Dues of Departments"<<endl;
	cout<<"2-> Change Salary of Teachers"<<endl;
	cout<<"3-> Change Salary of Staffs"<<endl;
	cout<<"4-> Change Capacity of Students"<<endl;
	cout<<"0-> Go back to Main Menu"<<endl<<endl;


	cin>>choice;											//Getting choice
	system("cls");

	if(choice==1)
	{
		dept_duechange();
	}
	else if (choice==2)
	{
		change_salary();
	}
	else if (choice==3)
	{
		change_staffsalary();
	}
	else if (choice==4)
	{
		dept_capchange();
	}
	else if (choice==0)
	{
		mainmenu();
	}
	else
	{
		change_details();
	}
}

void management()									//main menu as a dashboard
{
	int choice;
	cout<<"Enter your choice by entering number"<<endl<<endl;
	cout<<"1-> Check Current Details"<<endl;
	cout<<"2-> Change Existing Details"<<endl;
	cout<<"3-> Generate Reciept"<<endl;
	cout<<"0-> Go back to Main Menu"<<endl<<endl;

	cin>>choice;												//Enter choice
	system("cls");

	if(choice==1)
	{
		current_details();
	}
	else if (choice==2)
	{
		change_details();
	}
	else if (choice==3)
	{
		reciept();
	}
	else if (choice==0)
	{
		mainmenu();
	}
	else{
		management();
	}
}

void mainmenu()
{
	int count=0;
	for(int i=0;i<cnt_arts;i++)									//checking if there is any unpaid dues in arts department
	{
		if(arts[i].fee_status=="unpaid")
		{
			count++;
		}
	}

	for(int i=0;i<cnt_coms;i++)									//checking if there is any unpaid dues in commerce department
	{
		if(coms[i].fee_status=="unpaid")
		{
			count++;
		}
	}

	for(int i=0;i<cnt_sciences;i++)								////checking if there is any unpaid dues in sciences department
	{
		if(sciences[i].fee_status=="unpaid")
		{
			count++;
		}
	}

	if(count>0)
	{
		cout<<"---------------------------------------------------------------------\n";
		cout<<"Note: "<<count<<" Students Dues are Unpaid. Enter 0 for Details\n";								//Displaing note on main menu
		cout<<"---------------------------------------------------------------------\n\n";
	}

	int choice;
	cout<<"Enter your choice by entering number"<<endl<<endl;
	cout<<"1-> Student Records"<<endl;
	cout<<"2-> School Managment"<<endl<<endl;

	cin>>choice;
	system("cls");

	if(choice==1)
	{
		student();
	}
	else if (choice==2)
	{
		management();
	}
	else if (choice==0)
	{
		display();
	}
	else{
		mainmenu();
	}
}

void change_salary(){															//Changing value of teachers salary
	cout<<"Current Salary of Teachers is $"<<teachers_salary<<endl<<endl;		//Displaying old salary

	float newsalary;
	cout<<"Enter the New Salary for the Teachers : ";
	cin>>newsalary;																//Getting new value to update

	teachers_salary=newsalary;

	exp[0]= teachers_salary;
		ofstream expFile1 ("expenses.txt");										//Opening file
		  expFile1 << exp[0]<<"\n";
		  expFile1 << exp[1]<<"\n";												//Writing into the file

		expFile1.close();														//Closing the file

	cout<<endl<<endl<<"\n\nSalary Updated\n\n";
	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}

void change_staffsalary(){													//To change non teaching staffs salary
	cout<<"Current Salary of Staffs is $"<<staff_salary<<endl<<endl;		//Displaying old record

	float newsalary;
	cout<<"Enter the New Salary for the Teachers : ";
	cin>>newsalary;															//Getting new value of salary

	staff_salary=newsalary;

	exp[1]= staff_salary;
		ofstream expFile2 ("expenses.txt");									//Opening file
		  expFile2 << exp[0]<<"\n";
		  expFile2 << exp[1]<<"\n";											//Writing into the file

		expFile2.close();													//Closing file
	cout<<endl<<endl<<"\n\nSalary Updated\n\n";
	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}

void arts_duechange()									//To change dues for arts department
{
	cout<<"Current Fees of Students is $"<<due_arts<<endl<<endl;		//Printing old data

	float newamount;
	cout<<"Enter the Fee Amount for the Arts : ";
	cin>>newamount;												//get new value for dues

	due_arts=newamount;
	due[0]= due_arts;
		ofstream dueFile1 ("Dues.txt");							//Open file
		  dueFile1 << due[0]<<"\n";
		  dueFile1 << due[1]<<"\n";								//Writing into te file
		  dueFile1 << due[2]<<"\n";
		dueFile1.close();										//Closing file
	cout<<endl<<endl<<"\n\nDues Updated\n\n";
	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}

void coms_duechange()												//Changing the dues commerce department
{
	cout<<"Current Fees of Students is $"<<due_coms<<endl<<endl;	//Prinitng the old data

	float newamount;
	cout<<"Enter the Fee Amount for the Arts : ";
	cin>>newamount;													//getting the value of new dues

	due_coms=newamount;

	due[1]= due_coms;
		ofstream dueFile2 ("Dues.txt");								//Opening file
		  dueFile2 << due[0]<<"\n";
		  dueFile2 << due[1]<<"\n";									//Entering record in file
		  dueFile2 << due[2]<<"\n";
		dueFile2.close();											//Closing file
	cout<<endl<<endl<<"\n\nDues Updated\n\n";
	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}

void sciences_duechange()									//To change the dues of sciences department
{
	cout<<"Current Fees of Students is $"<<due_sciences<<endl<<endl;		//Displaying the prevoius dues

	float newamount;
	cout<<"Enter the Fee Amount for the Sciences : ";
	cin>>newamount;														//Getting new value for capacity

	due_sciences=newamount;

	due[2]= due_sciences;
		ofstream dueFile3 ("Dues.txt");									//Opening file
		  dueFile3 << due[0] <<"\n";
		  dueFile3 << due[1]<<"\n";										//Writing in file
		  dueFile3 << due[2]<<"\n";
		dueFile3.close();												//Closing file

	cout<<endl<<endl<<"\n\nDues Updated\n\n";
	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}

void current_details()   						//To print all the stats in group level as well as individual
{
	float exp=teachers_salary+elect_bill+staff_salary+tax;
	float income= (due_arts*cnt_arts)+(due_sciences*cnt_sciences)+(due_coms*cnt_coms);

	cout<<"--------------------------------------------"<<endl;
	cout<<"-----------Arts Department-----------"<<endl<<endl;
	cout<<"Students Enrolled : "<<cnt_arts<<endl;
	cout<<"Fees : $"<<due_arts<<endl;
	cout<<"Student Total Capacity : "<<cap_arts<<endl;
	cout<<"Availability for More Number of Students :"<< cap_arts-cnt_arts<<endl<<endl;

	cout<<"--------------------------------------------"<<endl;
	cout<<"-----------Commerce Department-----------"<<endl<<endl;
	cout<<"Students Enrolled : "<<cnt_coms<<endl;
	cout<<"Fees : $"<<due_coms<<endl;
	cout<<"Student Total Capacity : "<<cap_coms<<endl;
	cout<<"Availability for More Number of Students :"<< cap_coms-cnt_coms<<endl<<endl;

	cout<<"--------------------------------------------"<<endl;
	cout<<"-----------Sciences Department-----------"<<endl<<endl;
	cout<<"Students Enrolled : "<<cnt_sciences<<endl;
	cout<<"Fees : $"<<due_sciences<<endl;
	cout<<"Student Total Capacity : "<<cap_sciences<<endl;
	cout<<"Availability for More Number of Students :"<< cap_sciences-cnt_sciences<<endl<<endl;

	cout<<"--------------------------------------------"<<endl;
	cout<<"-----------All Department-----------"<<endl<<endl;
	cout<<"Students Enrolled : "<<cnt_sciences+cnt_coms+cnt_arts<<endl;
	cout<<"Student Total Capacity : "<<cap_sciences+cap_coms+cap_arts<<endl;
	cout<<"Availability for More Number of Students :"<< (cap_sciences-cnt_sciences)+(cap_coms-cnt_coms)+(cap_arts-cnt_arts)<<endl;
	cout<<"Total Expensis : $"<<exp<<endl;
	cout<<"Total Income : $"<<income<<endl;
	cout<<"Profit/Loss : $"<<income-exp<<endl<<endl;

	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}

void display()
{
	cout<<"--------------------------------------------"<<endl;
	cout<<"-----------Science Department-----------"<<endl<<endl;
	for(int i=0;i<cnt_sciences;i++)
	{
		cout<<"Roll No. : "<<sciences[i].roll_num<<endl;
		cout<<"Name : "<<sciences[i].name<<endl;
		cout<<"Department : "<<sciences[i].department<<endl;
		cout<<"Dues : "<<sciences[i].dues<<endl;
		cout<<"Fee Status : "<<sciences[i].fee_status<<endl;
		cout<<"Date : "<<sciences[i].date<<"-"<<sciences[i].month<<"-"<<sciences[i].year<<endl<<endl;
	}

	cout<<"--------------------------------------------"<<endl;
	cout<<"-----------Commerce Department-----------"<<endl<<endl;
	for(int i=0;i<cnt_coms; i++)
	{
		cout<<"Roll No. : "<<coms[i].roll_num<<endl;
		cout<<"Name : "<<coms[i].name<<endl;
		cout<<"Department : "<<coms[i].department<<endl;
		cout<<"Dues : "<<coms[i].dues<<endl;
		cout<<"Fee Status : "<<coms[i].fee_status<<endl;
		cout<<"Date : "<<coms[i].date<<"-"<<coms[i].month<<"-"<<coms[i].year<<endl<<endl;
	}

	cout<<"--------------------------------------------"<<endl;
	cout<<"-----------Arts Department-----------"<<endl<<endl;

	for(int i=0;i<cnt_arts;i++)
	{
		cout<<"Roll Number : "<<arts[i].roll_num<<endl;
		cout<<"Name : "<<arts[i].name<<endl;
		cout<<"Department : "<<arts[i].department<<endl;
		cout<<"Dues : "<<arts[i].dues<<endl;
		cout<<"Fee Status : "<<arts[i].fee_status<<endl;
		cout<<"Date : "<<arts[i].date<<"-"<<arts[i].month<<"-"<<arts[i].year<<endl<<endl;
	}

	string x;
	cout << "Enter any key to go back to Main Menu :";
	cin>>x;
	if (x == "a")
	{
		system("cls");
		mainmenu();
	}
	else {
		system("cls");
		mainmenu();
	}
}

void sample()
{

	//Arts Sample data

	 ofstream MyFile("arts_record.txt");

  // Write to the file
  MyFile << "student1\n";
  MyFile << "Arts\n";
  MyFile << due_arts << "\n";
  MyFile << 15 << "\n";
  MyFile << "aug\n";
  MyFile << 2021<< "\n";
  MyFile << cnt_arts<< "\n";
    MyFile << "paid\n";

  cnt_arts++;

  MyFile << "student2\n";
  MyFile << "Arts\n";
  MyFile << due_arts << "\n";
  MyFile << 10 << "\n";
  MyFile << "june\n";
  MyFile << 2018<< "\n";
  MyFile << cnt_arts<< "\n";
  MyFile << "unpaid\n";

    cnt_arts++;

  MyFile << "student3\n";
  MyFile << "Arts\n";
  MyFile << due_arts << "\n";
  MyFile << 17 << "\n";
  MyFile << "feb\n";
  MyFile << 2019<< "\n";
  MyFile << cnt_arts<< "\n";
  MyFile << "paid\n";

  // Close the file
  MyFile.close();


 ifstream inputFile4("arts_record.txt");       				//Opening file

    if (inputFile4.good()) {
        string current_number = "" ;
		int c=0 ;
		int cnt_=0;
        while (inputFile4 >> current_number){						//To write data in file

            if (c==0 ) { arts[cnt_].name=current_number; c++;}
			else if (c==1 ) { arts[cnt_].department=current_number; c++;}
			else if (c==2 ) { arts[cnt_].dues=atoi(current_number.c_str()); c++;}
			else if (c==3 ) {arts[cnt_].date=atoi(current_number.c_str()); c++;}
			else if (c==4 ) {arts[cnt_].month=current_number; c++;}
			else if (c==5 ) {arts[cnt_].year=atoi(current_number.c_str()); c++;}
			else if (c==6 ) {arts[cnt_].roll_num=atoi(current_number.c_str()); c++;}
			else if (c==7 ) {arts[cnt_].fee_status=current_number; c=0; cnt_++; cnt_arts++;}

        }

}
inputFile4.close();


//Commerce Sample Data
	//---------------------------------


ofstream MyFile2("coms_record.txt");

//   Write to the file
  MyFile2 << "student4\n";
  MyFile2 << "Arts\n";
  MyFile2 << due_coms << "\n";
  MyFile2 << 15 << "\n";
  MyFile2 << "aug\n";
  MyFile2 << 2021<< "\n";
  MyFile2 << cnt_coms<< "\n";
  MyFile2 << "paid\n";

  cnt_coms++;
   MyFile2 << "student5\n";
  MyFile2 << "Arts\n";
  MyFile2 << due_coms << "\n";
  MyFile2 << 15 << "\n";
  MyFile2 << "aug\n";
  MyFile2 << 2021<< "\n";
  MyFile2 << cnt_coms<< "\n";
  MyFile2 << "paid\n";

    cnt_coms++;
   MyFile2 << "student6\n";
  MyFile2 << "Arts\n";
  MyFile2 << due_coms << "\n";
  MyFile2 << 15 << "\n";
  MyFile2 << "aug\n";
  MyFile2 << 2021<< "\n";
  MyFile2 << cnt_coms<< "\n";
    MyFile2 << "paid\n";

  // Close the file
  MyFile2.close();

 ifstream inputFile5("coms_record.txt");       		//Opening files

    if (inputFile5.good()) {
        string current_number = "" ;
		int c=0 ;
		int cnt_=0;
        while (inputFile5 >> current_number){

            if (c==0 ) { coms[cnt_].name=current_number; c++;}
			else if (c==1 ) { coms[cnt_].department=current_number; c++;}
			else if (c==2 ) { coms[cnt_].dues=atoi(current_number.c_str()); c++;}		//getting data as an input
			else if (c==3 ) {coms[cnt_].date=atoi(current_number.c_str()); c++;}
			else if (c==4 ) {coms[cnt_].month=current_number; c++;}
			else if (c==5 ) {coms[cnt_].year=atoi(current_number.c_str()); c++;}
			else if (c==6 ) {coms[cnt_].roll_num=atoi(current_number.c_str()); c++;}
			else if (c==7 ) {coms[cnt_].fee_status=current_number; c=0; cnt_++;
			cnt_coms++;}

        }

}
inputFile5.close();

	coms[cnt_coms].name="student 4";
	coms[cnt_coms].department="Commerce";
	coms[cnt_coms].dues=due_coms;
	coms[cnt_coms].date=17;
	coms[cnt_coms].month="jan";
	coms[cnt_coms].year=2011;
	coms[cnt_coms].roll_num=cnt_coms;
	coms[cnt_coms].fee_status="paid";

	cnt_coms++;

	coms[cnt_coms].name="student 5";
    coms[cnt_coms].department="Commerce";
    coms[cnt_coms].dues=due_coms;
	coms[cnt_coms].date=5;
	coms[cnt_coms].month="oct";
	coms[cnt_coms].year=2012;
	coms[cnt_coms].roll_num=cnt_coms;
	coms[cnt_coms].fee_status="unpaid";

	cnt_coms++;

	coms[cnt_coms].name="student 6";
    coms[cnt_coms].department="Commerce";
	coms[cnt_coms].dues=due_coms;
	coms[cnt_coms].date=21;
	coms[cnt_coms].month="dec";
	coms[cnt_coms].year=2016;
	coms[cnt_coms].roll_num=cnt_coms;
	coms[cnt_coms].fee_status="unpaid";

	cnt_coms++;

	//Science Sample Data
	//---------------------------------

	ofstream MyFile3("sciences_record.txt");

  // Write to the file
  MyFile3 << "student7\n";
  MyFile3 << "Arts\n";
  MyFile3 << due_sciences << "\n";
  MyFile3 << 15 << "\n";
  MyFile3 << "aug\n";
  MyFile3 << 2021<< "\n";
  MyFile3 << cnt_sciences<< "\n";
  MyFile3 << "paid\n";
//
  cnt_coms++;
   MyFile3 << "student8\n";
  MyFile3<< "Arts\n";
  MyFile3 << due_sciences << "\n";
  MyFile3 << 15 << "\n";
  MyFile3 << "aug\n";
  MyFile3 << 2021<< "\n";
  MyFile3 << cnt_sciences<< "\n";
  MyFile3 << "paid\n";
//
    cnt_sciences++;
   MyFile3 << "student9\n";
   MyFile3 << "Arts\n";
   MyFile3 << due_sciences << "\n";
   MyFile3 << 15 << "\n";
   MyFile3 << "aug\n";
   MyFile3 << 2021<< "\n";
   MyFile3 << cnt_sciences<< "\n";
   MyFile3 << "paid\n";

  // Close the file
   MyFile3.close();




//
	sciences[cnt_sciences].name="student 7";
	sciences[cnt_sciences].department="Sceinces";
	sciences[cnt_sciences].dues=due_sciences;
	sciences[cnt_sciences].date=23;
	sciences[cnt_sciences].month="feb";
	sciences[cnt_sciences].year=2021;
	sciences[cnt_sciences].roll_num=cnt_sciences;
	sciences[cnt_sciences].fee_status="paid";
//
	cnt_sciences++;
//
	sciences[cnt_sciences].name="student 8";
	sciences[cnt_sciences].department="Sceinces";
	sciences[cnt_sciences].dues=due_sciences;
	sciences[cnt_sciences].date=25;
	sciences[cnt_sciences].month="mar";
	sciences[cnt_sciences].year=2017;
	sciences[cnt_sciences].roll_num=cnt_sciences;
	sciences[cnt_sciences].fee_status="paid";
//
	cnt_sciences++;
//
	sciences[cnt_sciences].name="student 9";
	sciences[cnt_sciences].department="Sceinces";
	sciences[cnt_sciences].dues=due_sciences;
	sciences[cnt_sciences].date=21;
	sciences[cnt_sciences].month="nov";
	sciences[cnt_sciences].year=2019;
	sciences[cnt_sciences].roll_num=cnt_sciences;
	sciences[cnt_sciences].fee_status="paid";
//
	cnt_sciences++;

 ifstream inputFile6("sciences_record.txt");       		//Opening the file
    if (inputFile6.good()) {
        string current_number = "" ;
		int c=0 ;
		int cnt_=0;
        while (inputFile6 >> current_number){
            if (c==0 ) { sciences[cnt_].name=current_number; c++;}
			else if (c==1 ) { sciences[cnt_].department=current_number; c++;}
			else if (c==2 ) { sciences[cnt_].dues=atoi(current_number.c_str()); c++;}
			else if (c==3 ) {sciences[cnt_].date=atoi(current_number.c_str()); c++;}
			else if (c==4 ) {sciences[cnt_].month=current_number; c++;}								//To write into the farak
			else if (c==5 ) {sciences[cnt_].year=atoi(current_number.c_str()); c++;}
			else if (c==6 ) {sciences[cnt_].roll_num=atoi(current_number.c_str()); c++;}
			else if (c==7 ) {sciences[cnt_].fee_status=current_number; c=0; cnt_++; cnt_sciences++;}
        }
}
inputFile6.close();
}

