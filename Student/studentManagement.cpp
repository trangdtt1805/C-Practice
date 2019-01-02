#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

struct SinhVien
{
	int id;
	char Name[100];
	float score;
};

typedef struct SinhVien SINHVIEN;

struct Node
{
	SINHVIEN Data;
	struct Node* pNext;
};
typedef struct Node NODE;

struct List
{
	NODE* pHead, pTail;
};
typedef struct List LIST;

void Init(LIST &l)
{
	l.pHead == l.pTail;
	l.pTail = NULL;
}

NODE* GetNode(SINHVIEN student)
{
	NODE* p = new NODE;
	if (p == NULL){
		return NULL;
	}
	p->Data = student;
	p->pNext = NULL;
	return p;
}

void AddTail(LIST &l, NODE* p){
	if (l.pHead == NULL){
		l.pHead = l.pTail = p;
	}
	else{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

int ReadAndProcessFile(LIST &l, FILE* &pFile){
	pFile = fopen("DANHSACH.txt","r");
	int number = 0;
	char* pStr = new char[100];
	if (pFile == NULL){
		perror("ERROR,");
		return 0;
	}
	while (fgets(pStr,100,pFile) != NULL){
		char *str;
		NODE* p = new NODE;
		
		//get ID for students
		str =strtok(pStr,";");
		p->Data.id = atoi(str);
		
		//get name for students
		str = strtok(NULL,";");
		strcpy(p->Data.Name,str);
		//get sorce
		str = strtok(NULL,";");
		p->Data.score = atof(str);
		
		NPDE* q = GetNode(p->Data);
		AddTail(l,q);
		
		number++;
	}
	fclose(pFile);
	return number;
}

void Output(LIST l)
{
	cout<<"\n____________________CONTACT_______________________");
	cout<<"\n|  ID  |   NAME     | SCORE   |";
	for (NODE* p = l.pHead;p != NULL; p = p->pNext){
		cout<<"| % | %15s  |  %.2f  |",p->Data.id,p->Data.Name, p->Data.score;	
	}
}
int main()
{
	LIST 1;
	FILE* pFile;
	iNIT(1);
	int number = ReadAndProcessFile(l, File);
	cout<<"Number: "; cin>>number;
	Output(1);
	getch();
}
