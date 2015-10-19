#include <chrono>
#include <ratio>
#include <iostream>
#include <cstdlib>

using namespace std;

int main () {

  /** Duration */
  chrono::duration<int> twentySeconds(20);  // ������ �� - �������
  cout << twentySeconds.count() << endl;

  /** ���������� ������������ �����, � ����� ������������� �������� duration � ������ �� ������� */
  chrono::duration<double,ratio<60>> halfAMinute(0.5);    // 0.5 * ratio<60,1>
  cout << halfAMinute.count() << endl;

  chrono::duration<long,ratio<1,1000>> oneMillisecond(1);
  cout << oneMillisecond.count() << endl;

  // �����: 29999 ms
  cout << "diff: " << (halfAMinute - oneMillisecond).count() << " ms" << endl;


  /** �� �������� ��������� � ���� ������������ ���� chrono */
  /** ��������: typedef duration<signed int-type>=29 bits, ratio<60>> minutes; */
  chrono::minutes threeHours(180);  // ��� ����
  cout << chrono::duration_cast<chrono::hours>(threeHours).count() << "hours" << endl;

  exit(EXIT_SUCCESS);

}

/** ����������� ����� ��� duration */
