#include<iostream>
#include<stdio.h>
#include<conio.h>
#include <string>
#include <cstdio>
#include <list>
#include <fstream>
#include <Windows.h>

using namespace std;

void inputList();
void displayList();
int checkID(int id);
void saveToFile();
void loadFromFile();
struct student
{
	int id;
	string name;
	float score;
};

typedef student *st;
list<student> listStudent;
// INPUT to LIST
void inputList() 
{
	int n;
	cout << "Enter number of student: ";
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cout << "\nStudent " << i << endl;
		st student1 = new(student);
		cout << "Enter ID " << i << " : ";
		cin >> student1->id;
		do
		{
			if (checkID(student1->id) == 1)
			{
				cout << "Enter again: ";
				cin >> student1->id;
			}
		} while (checkID(student1->id) == 1);

		cout << "Enter full name of student " << i << " : ";
		cin.ignore();
		getline(cin, student1->name);

		do
		{
			cout << "Enter score of student " << i << " : ";
			cin >> student1->score;
			if (student1->score > 10 || student1->score < 0)
			{
				cout << "Enter again: ";
				cin >> student1->score;
			}
		} while (student1->score > 10 || student1->score < 0);

		listStudent.push_back(*student1);
	}
}

void inputList(int id, string name, float score) {
	student s;
	s.id = id;
	s.name = name;
	s.score = score;
	listStudent.push_back(s);
}
// DISPLAY LIST
void displayList() 
{
	cout << "ID\tFULL NAME\t\tSCORE" << endl;
	list <student> ::iterator it;
	for (it = listStudent.begin(); it != listStudent.end(); ++it)
	{
		cout << "" << it->id << "\t" << it->name << "\t\t" << it->score << endl;
	}
}
// Funtion Check ID
int checkID(int id) 
{
	//system("cls");
	list <student> ::iterator it;
	for (it = listStudent.begin(); it != listStudent.end(); ++it)
	{
		if (it->id == id) return 1;
		else return 0;
	}
}
// SAVE TO FILE
void saveToFile() 
{
	ofstream outfile;
	outfile.open("Text.txt", ios::out);
	if (listStudent.empty())
	{
		cout << "No data to save";
		exit(0);
	}
	if (outfile.is_open())
	{
		list <student> ::iterator it;
		for (it = listStudent.begin(); it != listStudent.end(); ++it)
		{
			outfile << it->id << endl;
			outfile << it->name << endl;
			outfile << it->score << endl;
		}
		outfile.close();
	}
	cout << "Save to file!!" << endl;
}
// LOAD FROM FILE
void loadFromFile() 
{
	list<student> listStudents;

	ifstream infile;
	infile.open("Text.txt", ios::in);

	string line;

	while (getline(infile, line)) {
		student s;
		s.id = std::stoi(line);

		getline(infile, line);
		s.name = line;
		fflush(stdin);
		getline(infile, line);
		s.score = stof(line);
		listStudents.push_back(s);
	}
	for each (auto item in listStudents) {
		cout << item.id << "\t" << item.name << "\t" << item.score << endl;
	}
}

void menu()   // Creat MENNU
{
	cout << "---------------MENU-----------------" << endl;
	cout << "1.Input" << endl;
	cout << "        2.Dislay" << endl;
	cout << "        3.Save to file" << endl;
	cout << "        4.Load from file" << endl;
	cout << "        0.Exit" << endl;
	cout << "------------------------------------" << endl;
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		inputList();
		menu();
	case 2:
		displayList();
		menu();
	case 3:
		saveToFile();
		menu();
	case 4:
		loadFromFile();
		system("pause");
	case 0:
		exit(0);
	}
}

int main()
{
	menu();
	system("pause");
	return 0;
}
