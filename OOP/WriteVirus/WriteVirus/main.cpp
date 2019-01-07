#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include "Patient.h"

using namespace std;

int main()
{
	Patient p;
	char t = 0;
	while (p.get_m_state == '1')
	{
		cout << "Take Medicine (0 = NO, 1 = YES) ";
		cin >> t;
		if (t == '1')
		{
			int min = 1;
			int max = 6;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			cout << "Medicine resistance = " << medicine_resistance << endl;

			if (medicine_resistance >= 30)
			{
				cout << "Virus all died: " << endl;

				break;
			}
			else
			{
				p.TakeMedicine(medicine_resistance);
			}
		}
		else exit(0);
	}
	

	system("pause");
	return 0;
}