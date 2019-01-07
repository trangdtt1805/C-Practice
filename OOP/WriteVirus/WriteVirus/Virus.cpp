#include "Virus.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Virus::Virus(){
	// the virus resistance ability (10 – 30) 
	this->m_resistance = rand() % 21 + 10;
}

Virus::~Virus(){}

void Virus::set_m_dna(char* m_dna)
{
	this->m_dna = m_dna;
}
char* Virus::get_m_dna()
{
	return m_dna;
}
void Virus::set_m_resistance(int m_resistance)
{
	this->m_resistance = m_resistance;
}
int Virus::get_m_resistance()
{
	return m_resistance;
}


void Virus::LoadADNInformation​()
{
	std::fstream infile;
	infile.open("E:/Internship.Tools/Train/C-Practice/OOP/WriteVirus/ATGX.bin", std::ios::in);
	
	if (infile.fail()) cout << "Don't find file";
	while (!infile.eof())
	{
		string c;
		getline(infile, c);
		const char* str_adn = c.c_str();
		m_dna = const_cast<char*>(str_adn);
	}

	infile.close();
}

int Virus::ReduceResistance​(int medicine_resistance)
{
	return this->m_resistance = this->m_resistance - medicine_resistance;
}
