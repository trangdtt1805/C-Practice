#include <iostream>
#include <fstream>
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include "Patient.h"

using namespace std;

int main()
{
	
	Patient *p = new Patient;
	char t = '1';
	while ((p->get_m_state() == 1) && t == '1' )
	{
		cout << "Take Medicine (0 = NO, 1 = YES) ";
		cin >> t;
		if (t == '1')
		{
			p->TakeMedicine();
		}
	}

	system("pause");
	return 0;
}