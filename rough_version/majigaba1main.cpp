#include"stdafx.h"
#pragma warning(disable : 4996)

using namespace  std;
int tensukansu(int jotai[][4], int num);
double kitai(int jotai[][4]);

int main()
{
	int jotai[23][4];//���{
	int i, j, k;

	do {
		cout << "0�͊��Ғl�A1�͎����̑f�_�A2�͑���̑f�_" << endl;
		cin >> k;
		if (k == 0 || k == 1 || k == 2) {
			FILE *fp;

			fp = fopen("test.txt", "r");

			if (fp == NULL) {
				printf("�t�@�C��������܂���\n");
				return -1;
			}

			for (i = 0; i < 23; i++) {
				for (j = 0; j < 4; j++) {
					fscanf(fp, "%d", &jotai[i][j]);
				}
			}
		}

		if (k == 0) {
			cout << kitai(jotai) << endl;
		}
		else if (k == 1) {
			cout << tensukansu(jotai, 3) << endl;
		}
		else if (k == 2) {
			cout << tensukansu(jotai, 4) << endl;
		}
		else {
			break;
		}
	} while (1);
	return 0;
}