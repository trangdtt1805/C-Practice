#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include<conio.h>
#include <cstdio>

using namespace std;

struct student
{
	int id;
	char name[200];
	float score;
};
typedef student *st;

list<student> ListStudent;

void InputStudent()
{
	int n;
	cout<<"Enter number student: "; cin>>n;
	for (int i = 1; i<=n;i++)
	{
		cout<<"Studen "<<i<<endl;
		st student1 = new(student);
		cout<<"Enter ID: "; cin>>student1->id;
		cout<<"\nEnter name: "; cin>>student1->name;
		cout<<"\nEnter score: "; cin>>student1->score;
		
		
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
	//ListStudent l;
	Menu();
	return 0;
}
