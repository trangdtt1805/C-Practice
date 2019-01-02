#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

struct student
{
	int id;
	char name[200];
	float score;
};

void input_Student(student &st)
{
	cout<<"Enter Id: "; cin>>st.id;
	cout<<"Enter Name: "; cin>>st.name;
//	fflush(stdin);
//	gets(st.name);
	cout<<"Enter score: "; cin>>st.score;
}
void show_Student(student st)
{
	cout<<"Id: "<<st.id<<endl;
	cout<<"Name: "<<st.name;
//	puts(st.name);
	cout<<endl;
	cout<<"Score: "<<st.score<<endl;
}

struct Node
{
	student Data;
	Node *Next;
};

struct List
{
	Node *Head;
	Node *Tail;
};

void create_List(List &l)
{
	l.Head = l.Tail = NULL;
}

Node* CreateNode(student sv)
{
	Node *p = new Node;
	p->Data = sv;
	p->Next = NULL;
	return p;
}

void AddHead(List &l, student sv)
{
	Node *p = CreateNode(sv);
	if(l.Head==NULL)
		l.Head=l.Tail=p;
		else
		{
			p->Next=l.Head;
			l.Head=p;
		}
}

void XemList(List l)
{
	Node *p = l.Head;
	while(p!=NULL)
	{
		show_Student(p->Data);
		cout<<endl;
		p=p->Next;
	}
}

int main()
{
	List l;
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
				input_Student(st);
				break;
			case 2:
				show_Student(st);
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
	return 0;
}
