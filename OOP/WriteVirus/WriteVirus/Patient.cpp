#include "Patient.h"
#include <iostream>
#include <list>
#include "Virus.h"
#include "FluVirus.h"




Patient::Patient(){
	this->InitResistance();
	this->DoStart();
}

Patient::~Patient(){}

enum {
	DIE = 0,
	ALIVE = 1
};
//set/get m_resistance and m_state
void Patient::set_m_resistance(int m_resistance)
{
	this->m_resistance = m_resistance;
}
int Patient::get_m_resistance() {
	return m_resistance;
}
void Patient::set_m_state(int m_state) {
	this->m_state;
}
int Patient::get_m_state() {
	return m_state;
}

void Patient::InitResistance() {
	int random = rand() % 8001 + 1000;
	
}
list<Virus*> Patient::DoStart() {
	list<Virus*> listVirus;
	int ramdom_v = rand() % 11 + 10;
	
}
void Patient::TakeMedicine() {
	
}
void Patient::DoDie() {
	this->m_state = 0;
}
