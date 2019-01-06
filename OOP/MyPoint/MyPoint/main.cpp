#include "MyPoint.h"

int main()
{
	//Input A(mPosX,mPosY);
	int A_mPosX, A_mPosY;
	MyPoint *A = new MyPoint;

	cout << "Input A_mPosX: "; 
	cin >> A_mPosX;
	A->setX(A_mPosX);

	cout << "Input A_mPosY: "; 
	cin >> A_mPosY;
	A->setY(A_mPosY);

	//Input B(mPosX,mPosY)
	int B_mPosX, B_mPosY;
	MyPoint *B = new MyPoint;

	cout << endl;
	cout<<"Input B_mPosX: ";
	cin >> B_mPosX;
	B->setX(B_mPosX);

	cout << "Input B_mPosY: ";
	cin >> B_mPosY;
	B->setY(B_mPosY);

	cout << "A(";
	A->display();
	cout<< ")" << endl;

	cout << "B(";
	B->display();
	cout<< ")" << endl;

	cout << "Distance is: "<<A->distance(B)<<endl;

	system("pause");
	return 0;
}