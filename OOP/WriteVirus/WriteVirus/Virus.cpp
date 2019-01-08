#include "Virus.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Virus::Virus(){
	this->m_resistance = rand() % 21 + 10;
}

Virus::Virus(const Virus *virus)
{
	this->m_dna = new char[250];
	/*m_dna[0] = 'a';
	m_dna[1] = '\0';*/
	this->m_resistance = virus->m_resistance;
}

Virus::~Virus(){
	delete m_dna;
}

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
	
	this->m_dna = new char[255];

	if (infile)
	{
		infile >> this->m_dna;
	}

	infile.close();
}

int Virus::ReduceResistance​(int medicine_resistance)
{
	return this->m_resistance = this->m_resistance - medicine_resistance;
}
