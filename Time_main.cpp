#include <iostream>
#include "Time.h"
using namespace std;
/*

����� ������ �� ����� (������ ����                 ) � �������� � ������ ����, ������������ ��� ���� ��� ������ �� �������
                                    2:56:16 example1
                                    1:2:36 example2

*/

int main() { //�������� ����� Time � ���������� + (int), +=(int), =, == , != , > , < , >= , <= , ++, --. (int)-�������.
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    Time t1, t2, answer;
    int a = 100;
    int b = 50;
    cout << "���� ������� Time" << endl;
    t1.set();

    cout << "���� ������� Time" << endl;
    t2.set();

    t1.get();
    cout << endl;
    t2.get();
    cout << endl; 

    answer = t1 + a;
    cout << t1 << " + " << a << " = " << answer << endl << endl;

    answer = t1 += b;
    cout << t1 << " += " << b << " = " << answer << endl << endl;

    answer = ++t1;
    cout << t1 << " ++ " << " = " << answer << endl << endl;

    answer = --t1;
    cout << t1 << " -- " << " = " << answer << endl << endl;

    cout << t1 << " < " << t2 << " : " << boolalpha << (t1 < t2) << endl << endl;
    cout << t1 << " == " << t2 << " : " << boolalpha << (t1 == t2) << endl << endl;
    cout << t1 << " != " << t2 << " : " << boolalpha << (t1 != t2) << endl << endl;
    cout << t1 << " > " << t2 << " : " << boolalpha << (t1 > t2) << endl << endl;
    cout << t1 << " >= " << t2 << " : " << boolalpha << (t1 >= t2) << endl << endl;
    cout << t1 << " <= " << t2 << " : " << boolalpha << (t1 <= t2) << endl << endl;





    printf("\n//////////////////DOP///////////////////\n");
    FILE* Time_0 = fopen("Time_0.txt", "r");
    if ((Time_0 = fopen("Time_0.txt", "r")) == 0) {
        return -1;
    }

    FILE* Time_Sort = fopen("Time_Sort.txt", "w");
    if ((Time_Sort = fopen("Time_Sort.txt", "w")) == 0) {
        return -1;
    }

    sort_func(Time_0, Time_Sort);

    fclose(Time_0);
    fclose(Time_Sort);
	return 0;
} // ��������� � -50

  // � ����� ������ (����� (___) ����������� � ��������� �������, 
 //���������� ������������� ��� ������ �� ����������� ������� � ������� � ����� ������