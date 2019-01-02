#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include<conio.h>
#include <cstdio>

using namespace std;

struct student
{
	int id;
	string name;
	float score;
};
typedef student *st;

list<student> ListStudent;

int checkID(int id)
{
	list<student> :: iterator it;
	for(it = ListStudent.begin(); it != ListStudent.end(); ++it) 
    {
		if (it->id == id) return 1;
		else 0; 
	}
}
void InputStudent()
{
	int n;
	float diem;
	cout<<"Enter number student: "; cin>>n;
	for (int i = 1; i<=n;i++)
	{
	    cout<<"\nStuden "<<i<<endl;
		st student1 = new(student);
		cout<<"Enter ID: "; 
		cin>>student1->id;
		do
		{
			if (checkID(student1->id) == 1)
			{
			 cout<<"Again: ";
			 cin>>student1->id;
	
			}
			
		} while (checkID(student1->id) == 1);
		
		cout<<"Enter name: ";
		cin.ignore();
		getline(cin,student1->name);
		do
		{
			cout<<"Enter score: "; cin>>diem;
		} while (diem >10 || diem <0);
		student1->score = diem;
		//add list
		ListStudent.push_back(*student1);
	}
}

void DislayStudent()
{
	system("cls");
	cout<<"ID\tName\tSCORE";
	list<student> :: iterator pst;
	for(pst = ListStudent.begin(); pst != ListStudent.end(); ++pst) 
    {
		cout<<endl;
		cout<<pst->id<<"\t"<<pst->name<<"\t"<<pst->score<<endl;

	}
}

int Menu()
{
	int choice;
	student st;
	string x;
	do
	{
		cout<<"-------------MENU-------------"<<endl;
		cout<<"1. Input"<<endl;//nhap
		cout<<"2. Dislay"<<endl;//hien thi
		cout<<"3. Save to file"<<endl;//luu tren file
		cout<<"4. Load from file"<<endl;//
		cout<<"0. Exit"<<endl;
		cout<<"------------------------------"<<endl;
		cout<<"Choose: "; cin>>choice;
		
		switch (choice)
		{
			case 1: 
				InputStudent();
				system("cls");
				Menu();
				break;
			case 2:
				DislayStudent();
				break;
			case 3: 
				break;
			case 4:
				break;
			case 0: 
				break;
		}
		cout<<"\nTiep tuc (y/n): ";cin>>x;
		
	} while(x == "y" || x == "Y");
}


int main()
{
	std::ifstream fileInput("E:/Internship.Tools/Train/C-Practice/Student/New.txt");
	Menu();
	return 0;
}
