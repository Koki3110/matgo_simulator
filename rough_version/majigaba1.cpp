// hanahuda2.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include"stdafx.h"



using namespace  std;

double kitai(int jotai[][4]);
double hanten(int jotai[][4]);

//�^�ʖڃo�[�W������6�t�F�C�Y��
template < class BidirectionalIterator >
bool next_combination(BidirectionalIterator first1,
	BidirectionalIterator last1,
	BidirectionalIterator first2,
	BidirectionalIterator last2)
{
	if ((first1 == last1) || (first2 == last2)) {
		return false;
	}
	BidirectionalIterator m1 = last1;
	BidirectionalIterator m2 = last2; --m2;
	while (--m1 != first1 && !(*m1 < *m2)) {
	}
	bool result = (m1 == first1) && !(*first1 < *m2);
	if (!result) {
		while (first2 != m2 && !(*m1 < *first2)) {
			++first2;
		}
		first1 = m1;
		std::iter_swap(first1, first2);
		++first1;
		++first2;
	}
	if ((first1 != last1) && (first2 != last2)) {
		m1 = last1; m2 = first2;
		while ((m1 != first1) && (m2 != last2)) {
			std::iter_swap(--m1, m2);
			++m2;
		}
		std::reverse(first1, m1);
		std::reverse(first1, last1);
		std::reverse(m2, last2);
		std::reverse(first2, last2);
	}
	return !result;
}

template < class BidirectionalIterator >
bool next_combination(BidirectionalIterator first,
	BidirectionalIterator middle,
	BidirectionalIterator last)
{
	return next_combination(first, middle, middle, last);
}

int kaijo(int x) {
	int i = 1;
	int re = 1;
	for (i = 2; i <= x; i++) {
		re *= i;
	}
	return re;
}


int comb(int x, int y) {
	int i;
	int re = 1;
	for (i = 0; i < y; i++) {
		re *= x - i;
	}
	re /= kaijo(y);
	return re;
}

int tensukansu(int jotai[][4], int num)//num=1..jisouten,2...tasouten,3..jiten,4..taten
{
	int me, en;
	if (num == 1 || num == 3) {
		me = 1;
		en = 2;
	}
	else if (num == 2 || num == 4) {
		me = 2;
		en = 1;
	}
	int bai = 0;
	int hikari[5] = { 1,3,8,12,11 };
	int fbai = 0;
	int s = 0;
	int i;
	for (i = 0; i < 4; i++) {
		if (jotai[hikari[i]][0] == me) {
			s = s + 1;
		}
	}
	int t = 0;
	if (jotai[11][0] == me) {
		t = 1;
	}
	int tensu = 0;
	switch (s) {
	case 2:
		if (t == 1) {
			fbai = 1;
			tensu = tensu + 2;
		}
		break;
	case 3:
		fbai = 1;
		if (t == 1) {
			tensu = tensu + 4;
		}
		else {
			tensu = tensu + 3;
		}
		break;
	case 4:
		fbai = 1;
		if (t == 1) {
			tensu = tensu + 15;
		}
		else {
			tensu = tensu + 4;
		}
		break;
	default:
		break;
	}
	for (i = 0; i < 5; i++) {
		if (jotai[hikari[i]][0] == en) {
			fbai = 0;
		}
	}
	if (fbai == 1) {
		bai++;
	}
	int tan1[9] = { 1,2,3,4,5,6,7,9,10 };
	s = 0;
	for (i = 0; i < 9; i++) {
		if (jotai[tan1[i]][1] == me) {
			s = s + 1;
		}
	}
	if (jotai[11][2] == me) {
		s++;
	}
	if (s > 4) {
		tensu = tensu + s - 4;
	}
	int tanyaku[9] = { 1,2,3,4,5,7,6,9,10 };
	for (i = 0; i < 9; i = i + 3) {
		if (jotai[tanyaku[i]][1] == me && jotai[tanyaku[i + 1]][1] == me && jotai[tanyaku[i + 2]][1] == me) {
			tensu = tensu + 3;
		}
	}
	if (jotai[6][0] == me && jotai[7][0] == me && jotai[10][0] == me) {
		tensu = tensu + 5;
	}

	int tane0[6] = { 2,4,5,6,7,10 };
	int tane1[2] = { 8,11 };

	if (jotai[9][0] != me) {
		s = 0;
		for (i = 0; i < 6; i++) {
			if (jotai[tane0[i]][0] == me) {
				s = s + 1;
			}
		}
		for (i = 0; i < 2; i++) {
			if (jotai[tane1[i]][1] == me) {
				s = s + 1;
			}
		}
		if (jotai[9][0] == 30 + me) {
			s++;
		}
		if (s > 4) {
			tensu = tensu + s - 4;
		}
		if (s > 6) {
			bai++;
		}

		s = 0;
		int j = 0;
		for (j = 2; j < 4; j++) {
			for (i = 1; i < 13; i++) {
				if (jotai[i][j] == me && i != 11) {
					s++;
				}
			}
		}
		if (jotai[0][0] == me) {
			s = s + 3;
		}
		if (jotai[0][1] == me) {
			s = s + 2;
		}
		if (jotai[9][0] == 20 + me) {
			s = s + 2;
		}
		if (jotai[11][3] == me) {
			s = s + 2;
		}
		if (jotai[12][1] == me) {
			s = s + 2;
		}
		fbai = 0;
		if (s > 9) {
			fbai = 1;
			tensu = tensu + s - 9;
		}
		s = 0;
		for (j = 2; j < 4; j++) {
			for (i = 1; i < 13; i++) {
				if (jotai[i][j] == en && i != 11) {
					s++;
				}
			}
		}
		if (jotai[0][0] == en) {
			s = s + 3;
		}
		if (jotai[0][1] == en) {
			s = s + 2;
		}
		if (jotai[9][0] == 20 + en || jotai[9][0] == en) {
			s = s + 2;
		}
		if (jotai[11][3] == en) {
			s = s + 2;
		}
		if (jotai[12][1] == en) {
			s = s + 2;
		}
		if (s == 0 || s > 7) {
			fbai = 0;
		}
		if (fbai == 1) {
			bai++;
		}
	}
	else {
		int p;
		int tensu2[2] = { tensu,tensu };//0_tane,1_2kasu
		int bai2[2] = { bai,bai };
		for (p = 0; p < 2; p++) {
			s = 0;
			for (i = 0; i < 6; i++) {
				if (jotai[tane0[i]][0] == me) {
					s = s + 1;
				}
			}
			for (i = 0; i < 2; i++) {
				if (jotai[tane1[i]][1] == me) {
					s = s + 1;
				}
			}
			if (p == 0) {
				s++;
			}
			if (s > 4) {
				tensu2[p] = tensu2[p] + s - 4;
			}
			if (s > 6) {
				bai2[p]++;
			}

			s = 0;
			int j = 0;
			for (j = 2; j < 4; j++) {
				for (i = 1; i < 13; i++) {
					if (jotai[i][j] == me && i != 11) {
						s++;
					}
				}
			}
			if (jotai[0][0] == me) {
				s = s + 3;
			}
			if (jotai[0][1] == me) {
				s = s + 2;
			}
			if (jotai[11][3] == me) {
				s = s + 2;
			}
			if (jotai[12][1] == me) {
				s = s + 2;
			}
			if (p == 1) {
				s = s + 2;
			}
			fbai = 0;
			if (s > 9) {
				fbai = 1;
				tensu2[p] = tensu2[p] + s - 9;
			}
			s = 0;
			for (j = 2; j < 4; j++) {
				for (i = 1; i < 13; i++) {
					if (jotai[i][j] == en && i != 11) {
						s++;
					}
				}
			}
			if (jotai[0][0] == en) {
				s = s + 3;
			}
			if (jotai[0][1] == en) {
				s = s + 2;
			}
			if (jotai[9][0] == 20 + en || jotai[9][0] == en) {
				s = s + 2;
			}
			if (jotai[11][3] == en) {
				s = s + 2;
			}
			if (jotai[12][1] == en) {
				s = s + 2;
			}
			if (s == 0 || s > 7) {
				fbai = 0;
			}
			if (fbai == 1) {
				bai2[p]++;
			}
		}


		if (bai2[0] > bai2[1]) {
			bai = bai2[0];
			tensu = tensu2[0];
		}
		else if (bai2[0]<bai2[1]) {
			bai = bai2[1];
			tensu = tensu2[1];
		}
		else {
			if (tensu2[0] > tensu2[1]) {
				bai = bai2[0];
				tensu = tensu2[0];
			}
			else {
				bai = bai2[1];
				tensu = tensu2[1];
			}
		}
	}
	tensu = tensu + jotai[15 + me][0] + jotai[15 + me][3];
	/*if (jotai[15 + me][0] > 2) {
	bai = bai + jotai[15 + me][0] - 2;
	}
	bai = bai + jotai[15 + me][1] + jotai[18][1];*/
	int souten = tensu;
	if (num < 3) {
		if (jotai[15 + me][0] > 2) {
			bai = bai + jotai[15 + me][0] - 2;
		}
		bai = bai + jotai[15 + me][1] + jotai[18][1];
		if (jotai[15 + en][0] > 0) {
			bai++;
		}
		for (i = 0; i < bai; i++) {
			souten = souten * 2;
		}
		souten = souten * jotai[15 + me][2];
	}
	return souten;
}

int tukisu = 23;

int eneque(int jotai[][4], int n) {
	int ans = 0;
	switch (n) {
	case 0:
	{
	}
	break;
	case 1:
	{
	}
	break;
	case 2:
	{
	}
	break;
	default:
	{
		cout << "�_���݂����ł���" << endl;
	}
	break;
	}
	return ans;
}


double hanten(int jotai[][4]) {
	int i, j;
	double re = 0;
	int hanjo[23][4];
	for (i = 0; i < tukisu; i++) {
		for (j = 0; j < 4; j++) {
			if (i < 16) {
				switch (jotai[i][j]) {
				case 1:
					hanjo[i][j] = 2;
					break;
				case 2:
					hanjo[i][j] = 1;
					break;
				case 4:
					hanjo[i][j] = 11;
					break;
				case 5:
					hanjo[i][j] = 9;
					break;
				case 6:
					hanjo[i][j] = 10;
					break;
				case 7:
					hanjo[i][j] = 17;
					break;
				case 9:
					hanjo[i][j] = 5;
					break;
				case 14:
					hanjo[i][j] = 15;
					break;
				case 15:
					hanjo[i][j] = 14;
					break;
				case 17:
					hanjo[i][j] = 11;
					break;
				case 21:
					hanjo[i][j] = 22;
					break;
				case 22:
					hanjo[i][j] = 21;
					break;
				case 31:
					hanjo[i][j] = 32;
					break;
				case 32:
					hanjo[i][j] = 31;
					break;
				case 40:
					hanjo[i][j] = 6;
					break;
				case 41:
					hanjo[i][j] = 4;
					break;
				default:
					hanjo[i][j] = jotai[i][j];
					break;
				}
			}
			else if (i == 16) {
				hanjo[17][j] = jotai[i][j];
			}
			else if (i == 17) {
				hanjo[16][j] = jotai[i][j];
			}
			else {
				hanjo[i][j] = jotai[i][j];
			}
		}
	}
	hanjo[18][2] = jotai[18][3];
	hanjo[18][3] = jotai[18][2];
	hanjo[19][0] = jotai[19][1];
	hanjo[19][1] = jotai[19][0];
	hanjo[20][1] = jotai[20][2];
	hanjo[20][2] = jotai[20][1];
	hanjo[18][0] = 3;
	if (jotai[20][0] == 0) {
		hanjo[20][0] = 1;
	}
	else {
		hanjo[20][0] = 0;
	}
	re = kitai(hanjo);
	return re;
}

double kitaijijo(int jotai[][4]) {
	int i, j;
	double re = 0;
	int hanjo[23][4];
	for (i = 0; i < tukisu; i++) {
		for (j = 0; j < 4; j++) {
			if (i < 16) {
				switch (jotai[i][j]) {
				case 40:
					hanjo[i][j] = 10;
					break;
				case 41:
					hanjo[i][j] = 11;
					break;
				default:
					hanjo[i][j] = jotai[i][j];
					break;
				}
			}
			else {
				hanjo[i][j] = jotai[i][j];
			}
		}
	}
	hanjo[18][0] = 0;
	re = kitai(hanjo);
	return re;
}

double kitai(int jotai[][4]) {
	double re = 0;
	int i, j, k;

	int phase = jotai[19][3];
	switch (phase) {
	case 1:
	{

		if (jotai[20][3] != 0) {

			int count10 = 0, count11 = 0, count1718 = 0;
			if (jotai[18][0] == 0) {
				for (i = 0; i < 16; i++) {
					for (j = 0; j < 4; j++) {
						if (jotai[i][j] == 10) {
							count10++;
						}
						else if (jotai[i][j] == 11) {
							count11++;
						}
						else if (jotai[i][j] == 18 || jotai[i][j] == 17) {
							count1718++;
						}
					}
				}
			}
			int countall;
			if (jotai[18][0] == 0) {
				countall = count10 + count11 + count1718;
			}
			else {
				countall = jotai[20][3];
			}


			double *p;
			p = new double[countall];
			int(*douteki)[23][4];
			douteki = new int[countall][23][4];
			int loopcount = 0;

			if (jotai[18][0] == 0) {
				if (count1718 < jotai[20][3]) {
					loopcount = countall;
					double p10, p11, p1718 = 0;
					p1718 = 1.0 / jotai[20][3];
					p10 = ((1.0 * jotai[20][3] - count1718) / (1.0 * 10 + jotai[20][3] - count1718)) / jotai[20][3];
					if (count11 != 0) {
						p11 = (1.0 - 1.0 * count1718 * p1718 - count10 * p10) / count11;
						if (p11 > p1718) {
							p11 = p1718;
							if (count10 != 0) {
								p10 = (1.0 - 1.0 * count1718 * p1718 - count11 * p11) / count10;
							}
						}
					}
					else if (count10 != 0) {
						p10 = (1 - count1718 * p1718) / count10;
					}


					for (k = 0; k < countall; k++) {
						int count2 = 0;
						int karituki = 0;
						int kariban = 0;
						for (i = 0; i < tukisu; i++) {
							for (j = 0; j < 4; j++) {
								if ((jotai[i][j] == 17 || jotai[i][j] == 18) && i < 16) {
									if (count2 == k) {
										douteki[k][i][j] = 13;
										karituki = i;
										kariban = j;
										p[k] = p1718;
									}
									else {
										douteki[k][i][j] = jotai[i][j];
									}
									count2++;
								}
								else if (jotai[i][j] == 10 && i < 16) {
									if (count2 == k) {
										douteki[k][i][j] = 13;
										karituki = i;
										kariban = j;
										p[k] = p10;
									}
									else {
										douteki[k][i][j] = jotai[i][j];
									}
									count2++;
								}
								else if (jotai[i][j] == 11 && i < 16) {
									if (count2 == k) {
										douteki[k][i][j] = 13;
										karituki = i;
										kariban = j;
										p[k] = p11;
									}
									else {
										douteki[k][i][j] = jotai[i][j];
									}
									count2++;
								}
								else {
									douteki[k][i][j] = jotai[i][j];
								}
							}
						}
						douteki[k][20][3] -= 1;
						douteki[k][21][2] = karituki;
						douteki[k][21][3] = kariban;
					}
				}
				else {
					loopcount = jotai[20][3];

					for (k = 0; k < jotai[20][3]; k++) {
						int count2 = 0;
						int karituki = 0;
						int kariban = 0;
						for (i = 0; i < tukisu; i++) {
							for (j = 0; j < 4; j++) {
								if ((jotai[i][j] == 17 || jotai[i][j] == 18) && i < 16) {
									if (count2 == k) {
										douteki[k][i][j] = 13;
										karituki = i;
										kariban = j;
										p[k] = 1.0 / count1718;
									}
									else {
										douteki[k][i][j] = jotai[i][j];
									}
									count2++;
								}
								else if ((jotai[i][j] == 10 || jotai[i][j] == 11) && i < 16) {
									douteki[k][i][j] = 9;
								}
								else {
									douteki[k][i][j] = jotai[i][j];
								}
							}
						}
						douteki[k][20][3] -= 1;
						douteki[k][21][2] = karituki;
						douteki[k][21][3] = kariban;
					}
				}
				//����
			}
			else {
				loopcount = jotai[20][3];

				for (k = 0; k < jotai[20][3]; k++) {
					int count2 = 0;
					int karituki = 0;
					int kariban = 0;
					for (i = 0; i < tukisu; i++) {
						for (j = 0; j < 4; j++) {
							if ((jotai[i][j] == 17 || jotai[i][j] == 18 || jotai[i][j] == 10 || jotai[i][j] == 11) && i < 16) {
								if (count2 == k) {
									douteki[k][i][j] = 13;
									karituki = i;
									kariban = j;
									p[k] = 1.0 / jotai[20][3];
								}
								else {
									douteki[k][i][j] = jotai[i][j];
								}
								count2++;
							}
							else {
								douteki[k][i][j] = jotai[i][j];
							}
						}
					}
					douteki[k][20][3] -= 1;
					douteki[k][21][2] = karituki;
					douteki[k][21][3] = kariban;
				}
			}
			re = 0;
			for (k = 0; k < loopcount; k++) {
				if (douteki[k][21][2] == 0) {
					re += p[k] * kitai(douteki[k]);
				}
				else {
					int jtuki = douteki[k][21][0];
					int jban = douteki[k][21][1];
					int ytuki = douteki[k][21][2];
					int yban = douteki[k][21][3];
					if (douteki[k][21][0] == douteki[k][21][2]) {
						int countc = 0;
						int bundori = 0;
						int hari = 0;
						for (i = 0; i < 4; i++) {
							if (douteki[k][jtuki][i] == 3) {
								countc++;
							}
						}
						switch (countc) {
						case 0:
							douteki[k][jtuki][jban] = 1;
							douteki[k][ytuki][yban] = 1;
							bundori++;
							break;
						case 1:
							if (douteki[k][20][1] != 0) {
								for (i = 0; i < 4; i++) {
									if (douteki[k][jtuki][i] == 3) {
										douteki[k][jtuki][i] = 14;
									}
								}
								douteki[k][jtuki][jban] = 14;
								douteki[k][ytuki][yban] = 14;
								douteki[k][18][2] += 1;
								hari++;
								for (i = 0; i < 2; i++) {
									if (douteki[k][0][i] == 13) {
										douteki[k][0][i] = 14;
										douteki[k][22][i] = jtuki;
									}
								}
							}
							else {
								for (i = 0; i < 4; i++) {
									if (douteki[k][jtuki][i] == 3) {
										douteki[k][jtuki][i] = 1;
									}
								}
								douteki[k][jtuki][jban] = 1;
								douteki[k][ytuki][yban] = 3;
							}
							break;
						case 2:
							for (i = 0; i < 4; i++) {
								douteki[k][jtuki][i] = 1;
							}
							bundori++;
							break;
						default:
							break;
						}

						if (hari == 0) {
							if (douteki[k][20][1] != 0) {
								for (i = 0; i < 2; i++) {
									if (douteki[k][0][i] == 13) {
										bundori++;
										douteki[k][0][i] = 1;
									}
								}
								//�����ɑS����
								int bacount = 0;
								for (i = 0; i < 13; i++) {
									for (j = 0; j < 4; j++) {
										if (douteki[k][i][j] == 3 || douteki[k][i][j] == 14 || douteki[k][i][j] == 15 || douteki[k][i][j] == 16) {
											bacount++;
										}
									}
								}
								if (bacount == 0) {
									bundori++;
								}

								for (j = 2; j < 4; j++) {
									for (i = 1; i < 13; i++) {
										if (douteki[k][i][j] == 2 && i != 11 && bundori>0) {
											douteki[k][i][j] = 1;
											bundori -= 1;
										}
									}
								}
							}
							else {
								for (i = 0; i < 2; i++) {
									if (douteki[k][0][i] == 13) {
										douteki[k][0][i] = 1;
									}
								}
							}
						}
						douteki[k][19][3] = 2;
						re += p[k] * kitai(douteki[k]);
					}
					else {
						int countc = 0, countd = 0;
						int bundori = 0;
						for (i = 0; i < 4; i++) {
							switch (douteki[k][jtuki][i]) {
							case 3:
								countc++;
								break;
							case 14:
								countc++;
								bundori += 2;
								break;
							case 15:
							case 16:
								countc++;
								bundori++;
								break;
							default:
								break;
							}
							switch (douteki[k][ytuki][i]) {
							case 3:
								countd++;
								break;
							case 14:
								countd++;
								bundori += 2;
								break;
							case 15:
							case 16:
								countd++;
								bundori++;
								break;
							default:
								break;
							}
						}

						if (douteki[k][20][1] != 0) {
							bundori /= 3;
							for (i = 0; i < 2; i++) {
								if (douteki[k][0][i] == 13) {
									bundori++;
									douteki[k][0][i] = 1;
								}
								if (douteki[k][22][i] == jtuki || douteki[k][22][i] == ytuki) {
									bundori++;
									douteki[k][0][i] = 1;
									douteki[k][22][i] = 0;
								}
							}
							for (j = 2; j < 4; j++) {
								for (i = 1; i < 13; i++) {
									if (douteki[k][i][j] == 2 && i != 11 && bundori>0) {
										douteki[k][i][j] = 1;
										bundori -= 1;
									}
								}
							}
						}
						else {
							for (i = 0; i < 2; i++) {
								if (douteki[k][0][i] == 13) {
									douteki[k][0][i] = 1;
								}
								if (douteki[k][22][i] == jtuki || douteki[k][22][i] == ytuki) {
									douteki[k][0][i] = 1;
									douteki[k][22][i] = 0;
								}
							}
						}

						if (countc != 2 && countd != 2) {
							int kaishuc = 0;
							int kaishud = 0;
							for (i = 0; i < 4; i++) {
								if (douteki[k][jtuki][i] == 3 || (douteki[k][jtuki][i] >= 14 && douteki[k][jtuki][i] <= 16)) {
									douteki[k][jtuki][i] = 1;
									kaishuc++;
								}
								if (douteki[k][ytuki][i] == 3 || (douteki[k][ytuki][i] >= 14 && douteki[k][ytuki][i] <= 16)) {
									douteki[k][ytuki][i] = 1;
									kaishud++;
								}
							}
							if (kaishuc == 0) {
								douteki[k][jtuki][jban] = 3;
							}
							else {
								douteki[k][jtuki][jban] = 1;
							}
							if (kaishud == 0) {
								douteki[k][ytuki][yban] = 3;
							}
							else {
								douteki[k][ytuki][yban] = 1;
							}
							//�S�����ƕ��߂�
							if (douteki[k][20][1] != 0) {
								int bacount = 0;
								for (i = 0; i < 13; i++) {
									for (j = 0; j < 4; j++) {
										if (douteki[k][i][j] == 3 || douteki[k][i][j] == 14 || douteki[k][i][j] == 15 || douteki[k][i][j] == 16) {
											bacount++;
										}
									}
								}
								if (bacount == 0) {
									for (j = 2; j < 4; j++) {
										for (i = 1; i < 13; i++) {
											if (bacount == 0 && douteki[k][i][j] == 2 && i != 11) {
												douteki[k][i][j] = 1;
												bacount -= 1;
											}
										}
									}
								}
							}

							douteki[k][19][3] = 2;
							re += p[k] * kitai(douteki[k]);
						}
						else if (countc == 2 && countd != 2) {

							int kaishud = 0;
							double hikaku[2] = { 0,0 };
							for (i = 0; i < 4; i++) {
								if (douteki[k][ytuki][i] == 3 || (douteki[k][ytuki][i] >= 14 && douteki[k][ytuki][i] <= 16)) {
									douteki[k][ytuki][i] = 1;
									kaishud++;
								}
							}
							if (kaishud == 0) {
								douteki[k][ytuki][yban] = 3;
							}
							else {
								douteki[k][ytuki][yban] = 1;
							}
							douteki[k][jtuki][jban] = 1;
							douteki[k][19][3] = 2;
							j = 0;
							if (jotai[18][0] != 1) {
								for (i = 0; i < 4; i++) {
									if (douteki[k][jtuki][i] == 3) {

										douteki[k][jtuki][i] = 1;
										hikaku[j] = kitai(douteki[k]);
										douteki[k][jtuki][i] = 3;
										j++;
									}
								}
								if (hikaku[0] > hikaku[1]) {
									re += p[k] * hikaku[0];
								}
								else {
									re += p[k] * hikaku[1];
								}
							}
							else {
								int jihai[2] = { 0,0 };
								for (i = 0; i < 4; i++) {
									if (douteki[k][jtuki][i] == 3) {
										jihai[j] = i;
										douteki[k][jtuki][i] = 1;
										hikaku[j] = kitaijijo(douteki[k]);
										douteki[k][jtuki][i] = 3;
										j++;
									}
								}
								if (hikaku[0] >= hikaku[1]) {
									douteki[k][jtuki][jihai[0]] = 1;
									re += p[k] * kitai(douteki[k]);
								}
								else if (hikaku[0] < hikaku[1]) {
									douteki[k][jtuki][jihai[1]] = 1;
									re += p[k] * kitai(douteki[k]);
								}
								/*
								else {
								douteki[k][jtuki][jihai[0]] = 1;
								re += 0.5 * p[k] * kitai(douteki[k]);
								douteki[k][jtuki][jihai[0]] = 3;
								douteki[k][jtuki][jihai[1]] = 1;
								re += 0.5 * p[k] * kitai(douteki[k]);
								}
								*/
							}
						}
						else if (countc != 2 && countd == 2) {

							int kaishud = 0;
							double hikaku[2] = { 0,0 };
							for (i = 0; i < 4; i++) {
								if (douteki[k][jtuki][i] == 3 || (douteki[k][jtuki][i] >= 14 && douteki[k][jtuki][i] <= 16)) {
									douteki[k][jtuki][i] = 1;
									kaishud++;
								}
							}
							if (kaishud == 0) {
								douteki[k][jtuki][jban] = 3;
							}
							else {
								douteki[k][jtuki][jban] = 1;
							}
							douteki[k][ytuki][yban] = 1;
							douteki[k][19][3] = 2;
							j = 0;
							if (jotai[18][0] != 1) {
								for (i = 0; i < 4; i++) {
									if (douteki[k][ytuki][i] == 3) {

										douteki[k][ytuki][i] = 1;
										hikaku[j] = kitai(douteki[k]);
										douteki[k][ytuki][i] = 3;
										j++;
									}
								}
								if (hikaku[0] > hikaku[1]) {
									re += p[k] * hikaku[0];
								}
								else {
									re += p[k] * hikaku[1];
								}
							}
							else {
								int jihai[2] = { 0,0 };
								for (i = 0; i < 4; i++) {
									if (douteki[k][jtuki][i] == 3) {
										jihai[j] = i;
										douteki[k][jtuki][i] = 1;
										hikaku[j] = kitaijijo(douteki[k]);
										douteki[k][jtuki][i] = 3;
										j++;
									}
								}
								if (hikaku[0] >= hikaku[1]) {
									douteki[k][jtuki][jihai[0]] = 1;
									re += p[k] * kitai(douteki[k]);
								}
								else if (hikaku[0] < hikaku[1]) {
									douteki[k][jtuki][jihai[1]] = 1;
									re += p[k] * kitai(douteki[k]);
								}
								/*
								else {
								douteki[k][jtuki][jihai[0]] = 1;
								re += 0.5 * p[k] * kitai(douteki[k]);
								douteki[k][jtuki][jihai[0]] = 3;
								douteki[k][jtuki][jihai[1]] = 1;
								re += 0.5 * p[k] * kitai(douteki[k]);
								}
								*/
							}
						}
						else if (countc == 2 && countd == 2) {
							int l = 0;
							douteki[k][jtuki][jban] = 1;
							douteki[k][ytuki][yban] = 1;
							douteki[k][19][3] = 2;
							double hikaku[4] = { 0,0,0,0 };
							if (jotai[18][0] != 1) {
								for (i = 0; i < 4; i++) {
									if (douteki[k][jtuki][i] == 3) {
										douteki[k][jtuki][i] = 1;
										for (j = 0; j < 4; j++) {
											if (douteki[k][ytuki][j] == 3) {
												douteki[k][ytuki][i] = 1;
												hikaku[l] = kitai(douteki[k]);
												douteki[k][ytuki][i] = 3;
												l++;
											}
										}
										douteki[k][jtuki][i] = 3;
									}
								}
								double max;
								//int maxi;
								//maxi = 0;
								max = hikaku[0];
								for (i = 1; i < 4; i++) {
									if (max < hikaku[i]) {
										max = hikaku[i];
										//maxi = i;
									}
								}
								re += p[k] * max;
							}
							else {
								//koko
								int jkari[4] = { 0,0,0,0 };
								int ykari[4] = { 0,0,0,0 };
								for (i = 0; i < 4; i++) {
									if (douteki[k][jtuki][i] == 3) {

										douteki[k][jtuki][i] = 1;
										for (j = 0; j < 4; j++) {
											if (douteki[k][ytuki][j] == 3) {
												jkari[l] = i;
												ykari[l] = j;
												douteki[k][ytuki][i] = 1;
												hikaku[l] = kitaijijo(douteki[k]);//moso
												douteki[k][ytuki][i] = 3;
												l++;
											}
										}
										douteki[k][jtuki][i] = 3;
									}
								}
								double max;
								int maxi;
								maxi = 0;
								max = hikaku[0];
								for (i = 1; i < 4; i++) {
									if (max < hikaku[i]) {
										max = hikaku[i];
										maxi = i;
									}
								}
								douteki[k][jtuki][jkari[maxi]] = 1;
								douteki[k][ytuki][ykari[maxi]] = 1;
								re += p[k] * kitai(douteki[k]);

							}
						}


					}
					//�I���\����Ɗ��Ғl�v�Z�̓t�F�C�Y2��


				}
			}
			delete[] douteki;
			delete[] p;
			/*int max, maxi;
			maxi = 0;
			max = kitai(douteki[0]);
			for (i = 1; i < count; i++) {
			double qq = 0;
			qq = kitai(douteki[i]);
			if (max < qq) {
			max = qq;
			maxi = i;
			}
			}
			re = max;*/


		}


		else
		{
			re = tensukansu(jotai, 1);
			cout << "�R�D�������R�D�t�F�C�Y" << endl;
		}
	}
	break;

	case 2:
	{
		int tenj3 = tensukansu(jotai, 3);
		if (tenj3 > jotai[19][0]) {
			re = tensukansu(jotai, 1);
			if (jotai[18][0] != 1) {
				if (jotai[20][1] > 0) {
					jotai[16][0] += 1;
					jotai[19][0] = tenj3 + 1;
					jotai[19][3] = 3;
					double koica = kitai(jotai);
					if (koica > re) {
						re = koica;
					}
				}
			}
			else {
				if (jotai[20][1] > 0) {
					jotai[16][0] += 1;
					jotai[19][0] = tenj3 + 1;
					jotai[19][3] = 3;
					double koica = kitaijijo(jotai);
					if (koica > re) {
						re = kitai(jotai);
					}
				}
			}
		}
		else {
			if (jotai[20][1] > 0 || jotai[20][0] == 0) {
				jotai[19][3] = 3;
				re = kitai(jotai);
			}
			else {
				re = 0.0;
			}
		}
	}
	break;

	case 3://�ǂ����Ɍ�T�[�����Z����
	{
		if (jotai[20][2] == 0) {
			cout << "����̎�D�̂Ȃ�����̎�D�t�F�C�Y" << endl;
			re = tensukansu(jotai, 1);
		}
		else {
			int count9 = 0, count1718 = 0, count10 = 0, count11 = 0;
			if (jotai[18][0] == 0 || jotai[18][0] == 3) {
				for (i = 0; i < 16; i++) {
					for (j = 0; j < 4; j++) {
						if (jotai[i][j] == 9) {
							count9++;
						}
						else if (jotai[i][j] == 17 || jotai[i][j] == 18) {
							count1718++;
						}
						else if (jotai[i][j] == 10) {
							count10++;
						}
						else if (jotai[i][j] == 11) {
							count11++;
						}
					}
				}
			}
			int s = jotai[20][3] - count1718;
			int t = jotai[20][2] - count9;
			int sousu;
			if (jotai[18][0] == 0 || jotai[18][0]==3) {
				if (s < 0) {
					cout << "s < 0" << endl;
				}
				sousu = comb(s + t, t);
			}
			else {
				sousu = 1;
			}
			double *p;
			p = new double[sousu];
			for (i = 0; i < sousu; i++) {
				p[i] = 1.0;
			}
			int(*douteki)[23][4];
			douteki = new int[sousu][23][4];
			int(*douteki3)[23][4];
			douteki3 = new int[sousu][23][4];
			if (jotai[18][0] < 3) {
				if (t != 0 && jotai[18][0] == 0) {

					double p10, p11;
					/*
					p10 = 1.0 * 10 / (10 + s);
					if (p10 * count10 > t) {
					p10 = 1.0 * t / count10;
					}
					if (count11 != 0) {
					p11 = (t - count10 * p10) / count11;
					}
					*/
					if (count10 > t) {
						int bunbo = 0, bunshi = 0, iremono = 0;
						for (i = 0; i <= count10; i++) {
							if (i <= s && (count10 - i) <= t) {
								iremono = comb(s, i) * comb(10 - count9, count10 - i);
								bunbo += iremono;
								bunshi += (count10 - i) * iremono;
							}
						}
						p10 = (1.0*bunshi / bunbo) / t;
						if (count11 != 0) {
							p11 = (t - t * p10) / count11;
						}
					}
					else {
						p10 = 1.0 * (10.0 - count9) / (10.0 + s - count9);
						if (count11 != 0) {
							p11 = (t - count10 * p10) / count11;
						}
					}

					int l;//int l, m;

					for (k = 0; k < sousu; k++) {
						for (i = 0; i < tukisu; i++) {
							for (j = 0; j < 4; j++) {
								douteki[k][i][j] = jotai[i][j];
								douteki3[k][i][j] = jotai[i][j];
							}
						}
					}


					vector<int> data;
					for (int i = 0; i < s + t; ++i) {
						data.push_back(i);
					}
					k = 0;
					do {
						int counta = 0;
						for (i = 0; i < 13; i++) {
							for (j = 0; j < 4; j++) {

								if (jotai[i][j] == 10) {
									int b = 0;
									for (l = 0; l < t; l++) {
										if (counta == data[l]) {
											b = 1;
											break;
										}
									}

									if (b == 1) {
										douteki[k][i][j] = 40;
										p[k] *= p10;
										counta++;
									}
									else {
										counta++;
									}
								}
								else if (jotai[i][j] == 11) {
									int b = 0;
									for (l = 0; l < t; l++) {
										if (counta == data[l]) {
											b = 1;
											break;
										}
									}
									if (b == 1) {
										douteki[k][i][j] = 41;
										p[k] *= p11;
										counta++;
									}
									else {
										counta++;
									}
								}

							}
						}
						k++;
					} while (next_combination(data.begin(), data.begin() + t, data.end()));
					/*A��for (i = 0; i < sousu; i++) {
					for (l = 0; l < tukisu; l++) {
					for (m = 0; m < 4; m++) {
					douteki[i][l][m] = jotai[l][m];
					}
					}
					int karii = i, bangocount = 0, ro = s + t;
					for (j = 0; j < t; j++) {
					int fac = 0;
					for (k = 0; k < t; k++) {
					int comb1 = comb(ro - 1 - k, t - 1 - j);
					if (karii < fac + comb1) {

					int counta = 0;
					int l = 0, m = 0;
					for (l = 0; l < 13; l++) {
					for (m = 0; m < 4; m++) {
					if (douteki[i][l][m] == 10 ) {
					if (counta == bangocount) {
					douteki[i][l][m] = 9;
					p[i] *= p10;
					counta++;
					}
					else {
					counta++;
					}
					}
					else if (douteki[i][l][m] == 11 ) {
					if (counta == bangocount) {
					douteki[i][l][m] = 9;
					p[i] *= p11;
					counta++;
					}
					else {
					counta++;
					}
					}
					}
					}

					karii -= fac;
					ro += -1 - k;
					break;
					}
					else {
					fac += comb1;
					bangocount++;
					}
					}
					}
					}*/
					double psou = 0.0;
					for (i = 0; i < sousu; i++) {
						psou += p[i];
					}
					for (i = 0; i < sousu; i++) {
						p[i] /= psou;
					}
					/*
					for (k = 0; k < sousu; k++) {
					for (i = 0; i < 13; i++) {
					for (j = 0; j < 4; j++) {
					if ((douteki[k][i][j] == 10 || douteki[k][i][j] == 11)) {
					douteki[k][i][j] = 17;
					}
					}
					}
					douteki[k][18][0] = 1;//3.����̎�D�����̏I��
					}*/
					//tuika
					for (k = 0; k < sousu; k++) {
						douteki[k][18][0] = 1;
					}

				}
				else {
					for (i = 0; i < tukisu; i++) {
						for (j = 0; j < 4; j++) {

							douteki[0][i][j] = jotai[i][j];
							douteki3[0][i][j] = jotai[i][j];
						}
					}
					jotai[18][0] = 2;//3.����̎�D�����̏I��
					douteki[0][18][0] = 2;
				}

				for (k = 0; k < sousu; k++) {
					int l = 0;
					douteki[k][19][3] = 1;
					douteki[k][20][2] -= 1;
					double *hikaku;
					hikaku = new double[jotai[20][2]];
					for (i = 0; i < 16; i++) {
						for (j = 0; j < 4; j++) {
							if (douteki[k][i][j] == 9) {
								douteki[k][i][j] = 12;
								douteki[k][21][0] = i;
								douteki[k][21][1] = j;
								hikaku[l] = hanten(douteki[k]);
								douteki[k][i][j] = 9;
								l++;
							}
							else if (douteki[k][i][j] == 40) {
								douteki[k][i][j] = 12;
								douteki[k][21][0] = i;
								douteki[k][21][1] = j;
								hikaku[l] = hanten(douteki[k]);
								douteki[k][i][j] = 40;
								l++;
							}
							else if (douteki[k][i][j] == 41) {
								douteki[k][i][j] = 12;
								douteki[k][21][0] = i;
								douteki[k][21][1] = j;
								hikaku[l] = hanten(douteki[k]);
								douteki[k][i][j] = 41;
								l++;
							}
						}
					}
					/*
					for (i = 0; i < 4; i++) {
					if (douteki[k][jtuki][i] == 3) {
					douteki[k][jtuki][i] = 2;
					for (j = 0; j < 4; j++) {
					if (douteki[k][ytuki][j] == 3) {
					douteki[k][ytuki][i] = 2;
					hikaku[l] = kitai(douteki[k]);//moso
					douteki[k][ytuki][i] = 3;
					l++;
					}
					}
					douteki[k][jtuki][i] = 3;
					}
					}
					*/
					double max;
					//int maxi;
					int *maxihai;
					maxihai = new int[jotai[20][2]];
					int maxikosu = 1;
					//maxi = 0;
					max = hikaku[0];
					maxihai[0] = 0;
					for (i = 1; i < jotai[20][2]; i++) {
						if (max < hikaku[i]) {
							max = hikaku[i];
							//maxi = i;
							maxikosu = 1;
							maxihai[0] = i;
						}
						else if (max == hikaku[i]) {
							maxihai[maxikosu] = i;
							maxikosu++;
						}
					}
					delete[] hikaku;
					douteki[k][19][3] = 4;//3->4
					l = 0;
					int maxicount = 0;
					for (i = 0; i < 16; i++) {
						for (j = 0; j < 4; j++) {
							if (douteki[k][i][j] == 9 || douteki[k][i][j] == 40 || douteki[k][i][j] == 41) {
								if (maxicount < maxikosu && l == maxihai[maxicount]) {
									int dkij = douteki[k][i][j];
									int dk210 = douteki[k][21][0];
									int dk211 = douteki[k][21][1];
									douteki[k][i][j] = 12;
									douteki[k][21][0] = i;
									douteki[k][21][1] = j;
									re += (1.0 / maxikosu) * p[k] * kitai(douteki[k]);//
									douteki[k][i][j] = dkij;
									douteki[k][21][0] = dk210;
									douteki[k][21][1] = dk211;

									douteki3[k][i][j] = 12;
									douteki3[k][21][0] = i;
									douteki3[k][21][1] = j;
								}
								l++;
							}
						}
					}
					//douteki3[k][19][3] = 4;
					delete[] maxihai;
					douteki3[k][20][2] -= 1;
					//douteki[k][20][2] -= 1;//tuika

					//phase4start

					//phase4end


				}
			}
			else {

				if (t != 0 && jotai[18][0] == 3) {

					double p10, p11;
					if (count10 > t) {
						int bunbo = 0, bunshi = 0, iremono = 0;
						for (i = 0; i <= count10; i++) {
							if (i <= s && (count10 - i) <= t) {
								iremono = comb(s, i) * comb(10 - count9, count10 - i);
								bunbo += iremono;
								bunshi += (count10 - i) * iremono;
							}
						}
						p10 = (1.0*bunshi / bunbo) / t;
						if (count11 != 0) {
							p11 = (t - t * p10) / count11;
						}
					}
					else {
						p10 = 1.0 * (10.0 - count9) / (10.0 + s - count9);
						if (count11 != 0) {
							p11 = (t - count10 * p10) / count11;
						}
					}

					int l;//int l, m;

					for (k = 0; k < sousu; k++) {
						for (i = 0; i < tukisu; i++) {
							for (j = 0; j < 4; j++) {
								if (jotai[i][j] >= 4 && jotai[i][j] <= 7 && i<16) {
									douteki[k][i][j] = 5;
									douteki3[k][i][j] = 5;
								}
								else if ((jotai[i][j] == 10 || jotai[i][j] == 11 || jotai[i][j] == 17 || jotai[i][j] == 18) && i < 16) {
									douteki[k][i][j] = 18;
									douteki3[k][i][j] = 18;
								}
								else {
									douteki[k][i][j] = jotai[i][j];
									douteki3[k][i][j] = jotai[i][j];
								}
							}
						}
					}


					vector<int> data;
					for (int i = 0; i < s + t; ++i) {
						data.push_back(i);
					}
					k = 0;
					do {
						int counta = 0;
						for (i = 0; i < 13; i++) {
							for (j = 0; j < 4; j++) {

								if (jotai[i][j] == 10) {
									int b = 0;
									for (l = 0; l < t; l++) {
										if (counta == data[l]) {
											b = 1;
											break;
										}
									}

									if (b == 1) {
										douteki[k][i][j] = 9;
										p[k] *= p10;
										counta++;
									}
									else {
										counta++;
									}
								}
								else if (jotai[i][j] == 11) {
									int b = 0;
									for (l = 0; l < t; l++) {
										if (counta == data[l]) {
											b = 1;
											break;
										}
									}
									if (b == 1) {
										douteki[k][i][j] = 9;
										p[k] *= p11;
										counta++;
									}
									else {
										counta++;
									}
								}

							}
						}
						k++;
					} while (next_combination(data.begin(), data.begin() + t, data.end()));
					
					double psou = 0.0;
					for (i = 0; i < sousu; i++) {
						psou += p[i];
					}
					for (i = 0; i < sousu; i++) {
						p[i] /= psou;
					}
					for (k = 0; k < sousu; k++) {
						douteki[k][18][0] = 4;
					}

				}
				else {
					for (i = 0; i < tukisu; i++) {
						for (j = 0; j < 4; j++) {

							if (jotai[i][j] >= 4 && jotai[i][j] <= 7 && i<16) {
								douteki[0][i][j] = 5;
								douteki3[0][i][j] = 5;
							}
							else if ((jotai[i][j] == 10 || jotai[i][j] == 11 || jotai[i][j] == 17 || jotai[i][j] == 18) && i < 16) {
								douteki[0][i][j] = 18;
								douteki3[0][i][j] = 18;
							}
							else {
								douteki[0][i][j] = jotai[i][j];
								douteki3[0][i][j] = jotai[i][j];
							}
						}
					}
					jotai[18][0] = 4;//3.����̎�D�����̏I��
					douteki[0][18][0] = 4;
				}

				for (k = 0; k < sousu; k++) {
					int l = 0;
					//douteki[k][18][0] = 4;
					douteki[k][19][3] = 4;
					douteki[k][20][2] -= 1;
					double *hikaku;
					hikaku = new double[jotai[20][2]];
					for (i = 0; i < 16; i++) {
						for (j = 0; j < 4; j++) {
							if (douteki[k][i][j] == 9) {
								douteki[k][i][j] = 12;
								douteki[k][21][0] = i;
								douteki[k][21][1] = j;
								hikaku[l] = kitai(douteki[k]);
								douteki[k][i][j] = 9;
								l++;
							}

						}
					}
					double min;
					//int	mini;
					//mini = 0;
					min = hikaku[0];
					for (i = 1; i < jotai[20][2]; i++) {
						double qq = 0;
						qq = hikaku[i];
						if (min > qq) {
							min = qq;
							//mini = i;
						}
					}
					re += p[k] * min;
					delete[] hikaku;
				}
			}
			delete[] p;
			delete[] douteki;
			delete[] douteki3;
			//�����܂�
		}
	}
	break;

	case 4:
	{
		{
			int kp4;
			if (jotai[20][3] != 0) {
				int countall = jotai[20][3];
				//double *p;
				//p = new double[countall];
				int(*doutekip4)[23][4];
				doutekip4 = new int[countall][23][4];
				int loopcount = 0;

				{
					loopcount = jotai[20][3];

					for (kp4 = 0; kp4 < jotai[20][3]; kp4++) {
						int count2 = 0;
						int karituki = 0;
						int kariban = 0;
						for (i = 0; i < tukisu; i++) {
							for (j = 0; j < 4; j++) {
								if ((jotai[i][j] == 17 || jotai[i][j] == 18 || jotai[i][j] == 10 || jotai[i][j] == 11) && i < 16) {
									if (count2 == kp4) {
										doutekip4[kp4][i][j] = 13;
										karituki = i;
										kariban = j;
									}
									else {
										doutekip4[kp4][i][j] = jotai[i][j];
									}
									count2++;
								}
								else {
									doutekip4[kp4][i][j] = jotai[i][j];
								}
							}
						}
						doutekip4[kp4][20][3] -= 1;
						doutekip4[kp4][21][2] = karituki;
						doutekip4[kp4][21][3] = kariban;
					}
				}
				/*
				int(*douteki)[23][4];
				douteki = new int[jotai[20][3]][23][4];
				for (k = 0; k < jotai[20][3]; k++) {
				int count2 = 0;
				int karituki = 0;
				int kariban = 0;
				for (i = 0; i < tukisu; i++) {
				for (j = 0; j < 4; j++) {
				if ((jotai[i][j] == 17 || jotai[i][j] == 18) && i < 16) {
				if (count2 == k) {
				jotai[i][j] = 13;
				karituki = i;
				kariban = j;
				}
				else {
				jotai[i][j] = jotai[i][j];
				}
				count2++;
				}
				else {
				jotai[i][j] = jotai[i][j];
				}
				}
				}
				jotai[20][3] -= 1;
				jotai[21][2] = karituki;
				jotai[21][3] = kariban;
				}
				*/
				//re = 0;
				double rekp4sum = 0.0;
				for (kp4 = 0; kp4 < loopcount; kp4++) {

					if (jotai[21][2] == 0) {
						rekp4sum += kitai(jotai);
					}

					else {
						int jtuki = doutekip4[kp4][21][0];
						int jban = doutekip4[kp4][21][1];
						int ytuki = doutekip4[kp4][21][2];
						int yban = doutekip4[kp4][21][3];
						if (doutekip4[kp4][21][0] == doutekip4[kp4][21][2]) {
							int countc = 0;
							int bundori = 0;
							int hari = 0;
							for (i = 0; i < 4; i++) {
								if (doutekip4[kp4][jtuki][i] == 3) {
									countc++;
								}
							}
							switch (countc) {
							case 0:
								doutekip4[kp4][jtuki][jban] = 2;
								doutekip4[kp4][ytuki][yban] = 2;
								bundori++;
								break;
							case 1:
								if (doutekip4[kp4][20][2] != 0) {
									for (i = 0; i < 4; i++) {
										if (doutekip4[kp4][jtuki][i] == 3) {
											doutekip4[kp4][jtuki][i] = 15;
										}
									}
									doutekip4[kp4][jtuki][jban] = 15;
									doutekip4[kp4][ytuki][yban] = 15;
									doutekip4[kp4][18][3] += 1;
									hari++;
									for (i = 0; i < 2; i++) {
										if (doutekip4[kp4][0][i] == 13) {
											doutekip4[kp4][0][i] = 15;
											doutekip4[kp4][22][i] = jtuki;
										}
									}
								}
								else {
									for (i = 0; i < 4; i++) {
										if (doutekip4[kp4][jtuki][i] == 3) {
											doutekip4[kp4][jtuki][i] = 2;
										}
									}
									doutekip4[kp4][jtuki][jban] = 2;
									doutekip4[kp4][ytuki][yban] = 3;
								}
								break;
							case 2:
								for (i = 0; i < 4; i++) {
									doutekip4[kp4][jtuki][i] = 2;
								}
								bundori++;
								break;
							default:
								break;
							}

							if (hari == 0) {
								if (doutekip4[kp4][20][2] != 0) {
									for (i = 0; i < 2; i++) {
										if (doutekip4[kp4][0][i] == 13) {
											bundori++;
											doutekip4[kp4][0][i] = 2;
										}
									}

									//�����ɑS����
									int bacount = 0;
									for (i = 0; i < 13; i++) {
										for (j = 0; j < 4; j++) {
											if (doutekip4[kp4][i][j] == 3 || doutekip4[kp4][i][j] == 14 || doutekip4[kp4][i][j] == 15 || doutekip4[kp4][i][j] == 16) {
												bacount++;
											}
										}
									}
									if (bacount == 0) {
										bundori++;
									}

									for (j = 2; j < 4; j++) {
										for (i = 1; i < 13; i++) {
											if (doutekip4[kp4][i][j] == 1 && i != 11 && bundori>0) {
												doutekip4[kp4][i][j] = 2;
												bundori -= 1;
											}
										}
									}
								}
								else {
									for (i = 0; i < 2; i++) {
										if (doutekip4[kp4][0][i] == 13) {
											doutekip4[kp4][0][i] = 2;
										}
									}
								}
							}
							//doutekip4[kp4][19][3] = 5;
							//re += p[kp4] * kitai(doutekip4[kp4]);
						}
						else {
							int countc = 0, countd = 0;
							int bundori = 0;
							for (i = 0; i < 4; i++) {
								switch (doutekip4[kp4][jtuki][i]) {
								case 3:
									countc++;
									break;
								case 14:
									countc++;
									bundori += 1;
									break;
								case 15:
									countc++;
									bundori += 2;
									break;
								case 16:
									countc++;
									bundori++;
									break;
								default:
									break;
								}
								switch (doutekip4[kp4][ytuki][i]) {
								case 3:
									countd++;
									break;
								case 14:
									countd++;
									bundori += 1;
									break;
								case 15:
									countd++;
									bundori += 2;
									break;
								case 16:
									countd++;
									bundori++;
									break;
								default:
									break;
								}
							}

							if (doutekip4[kp4][20][2] != 0) {
								bundori /= 3;
								for (i = 0; i < 2; i++) {
									if (doutekip4[kp4][0][i] == 13) {
										bundori++;
										doutekip4[kp4][0][i] = 2;
									}
									if (doutekip4[kp4][22][i] == jtuki || doutekip4[kp4][22][i] == ytuki) {
										bundori++;
										doutekip4[kp4][0][i] = 2;
										doutekip4[kp4][22][i] = 0;
									}
								}
								for (j = 2; j < 4; j++) {
									for (i = 1; i < 13; i++) {
										if (doutekip4[kp4][i][j] == 1 && i != 11 && bundori>0) {
											doutekip4[kp4][i][j] = 2;
											bundori -= 1;
										}
									}
								}
							}
							else {
								for (i = 0; i < 2; i++) {
									if (doutekip4[kp4][0][i] == 13) {
										doutekip4[kp4][0][i] = 2;
									}
									if (doutekip4[kp4][22][i] == jtuki || doutekip4[kp4][22][i] == ytuki) {
										doutekip4[kp4][0][i] = 2;
										doutekip4[kp4][22][i] = 0;
									}
								}
							}

							if (countc != 2 && countd != 2) {
								int kaishuc = 0;
								int kaishud = 0;
								for (i = 0; i < 4; i++) {
									if (doutekip4[kp4][jtuki][i] == 3 || (doutekip4[kp4][jtuki][i] >= 14 && doutekip4[kp4][jtuki][i] <= 16)) {
										doutekip4[kp4][jtuki][i] = 2;
										kaishuc++;
									}
									if (doutekip4[kp4][ytuki][i] == 3 || (doutekip4[kp4][ytuki][i] >= 14 && doutekip4[kp4][ytuki][i] <= 16)) {
										doutekip4[kp4][ytuki][i] = 2;
										kaishud++;
									}
								}
								if (kaishuc == 0) {
									doutekip4[kp4][jtuki][jban] = 3;
								}
								else {
									doutekip4[kp4][jtuki][jban] = 2;
								}
								if (kaishud == 0) {
									doutekip4[kp4][ytuki][yban] = 3;
								}
								else {
									doutekip4[kp4][ytuki][yban] = 2;
								}

								//�S�����ƕ��߂�
								if (doutekip4[kp4][20][2] != 0) {
									int bacount = 0;
									for (i = 0; i < 13; i++) {
										for (j = 0; j < 4; j++) {
											if (doutekip4[kp4][i][j] == 3 || doutekip4[kp4][i][j] == 14 || doutekip4[kp4][i][j] == 15 || doutekip4[kp4][i][j] == 16) {
												bacount++;
											}
										}
									}
									if (bacount == 0) {
										for (j = 2; j < 4; j++) {
											for (i = 1; i < 13; i++) {
												if (bacount == 0 && doutekip4[kp4][i][j] == 1 && i != 11) {
													doutekip4[kp4][i][j] = 2;
													bacount -= 1;
												}
											}
										}
									}
								}

								//doutekip4[kp4][19][3] = 5;
								//re += p[kp4] * kitai(doutekip4[kp4]);
							}
							else if (countc == 2 && countd != 2) {

								int kaishud = 0;
								double hikaku[2] = { 0,0 };
								for (i = 0; i < 4; i++) {
									if (doutekip4[kp4][ytuki][i] == 3 || (doutekip4[kp4][ytuki][i] >= 14 && doutekip4[kp4][ytuki][i] <= 16)) {
										doutekip4[kp4][ytuki][i] = 2;
										kaishud++;
									}
								}
								if (kaishud == 0) {
									doutekip4[kp4][ytuki][yban] = 3;
								}
								else {
									doutekip4[kp4][ytuki][yban] = 2;
								}
								doutekip4[kp4][jtuki][jban] = 2;
								doutekip4[kp4][19][3] = 5;
								j = 0;
								int ijkari[2] = { 0,0 };
								for (i = 0; i < 4; i++) {
									if (doutekip4[kp4][jtuki][i] == 3) {
										ijkari[j] = i;
										doutekip4[kp4][jtuki][i] = 2;
										doutekip4[kp4][19][3] = 2;

										hikaku[j] = hanten(doutekip4[kp4]);//hikaku[j]=moso(doutekip4[kp4]);
										doutekip4[kp4][jtuki][i] = 3;
										doutekip4[kp4][19][3] = 3;
										j++;
									}
								}
								if (hikaku[0] < hikaku[1]) {
									/*j = 0;
									for (i = 0; i < 4; i++) {
									if (doutekip4[kp4][jtuki][i] == 3) {
									if (j == 0) {
									doutekip4[kp4][jtuki][i] = 2;
									}
									j++;
									}
									}
									re += p[kp4] * kitai(doutekip4[kp4]);*/
									//re += p[kp4] * hikaku[0]; //kokokara
									doutekip4[kp4][jtuki][ijkari[1]] = 2;
								}
								else {
									/*j = 0;
									for (i = 0; i < 4; i++) {
									if (doutekip4[kp4][jtuki][i] == 3) {
									if (j == 1) {
									doutekip4[kp4][jtuki][i] = 2;
									}
									j++;
									}
									}
									re += p[kp4] * kitai(doutekip4[kp4]);*/
									//re += p[kp4] * hikaku[1];
									doutekip4[kp4][jtuki][ijkari[0]] = 2;
								}

							}
							else if (countc != 2 && countd == 2) {

								int kaishud = 0;
								double hikaku[2] = { 0,0 };
								for (i = 0; i < 4; i++) {
									if (doutekip4[kp4][jtuki][i] == 3 || (doutekip4[kp4][jtuki][i] >= 14 && doutekip4[kp4][jtuki][i] <= 16)) {
										doutekip4[kp4][jtuki][i] = 2;
										kaishud++;
									}
								}
								if (kaishud == 0) {
									doutekip4[kp4][jtuki][jban] = 3;
								}
								else {
									doutekip4[kp4][jtuki][jban] = 2;
								}
								doutekip4[kp4][ytuki][yban] = 2;
								//doutekip4[kp4][19][3] = 5;
								j = 0;
								int ijkari[2] = { 0,0 };
								for (i = 0; i < 4; i++) {
									if (doutekip4[kp4][ytuki][i] == 3) {
										ijkari[j] = i;
										doutekip4[kp4][19][3] = 2;
										doutekip4[kp4][ytuki][i] = 2;
										hikaku[j] = hanten(doutekip4[kp4]);//moso(doutekip4[kp4]);
										doutekip4[kp4][ytuki][i] = 3;
										doutekip4[kp4][19][3] = 3;
										j++;
									}
								}
								if (hikaku[0] < hikaku[1]) {
									/*j = 0;
									for (i = 0; i < 4; i++) {
									if (doutekip4[kp4][jtuki][i] == 3) {
									if (j == 0) {
									doutekip4[kp4][jtuki][i] = 2;
									}
									j++;
									}
									}
									re += kitai(doutekip4[kp4]);*/
									//re += p[kp4] * hikaku[0];
									doutekip4[kp4][ytuki][ijkari[1]] = 2;
								}
								else {
									/*
									j = 0;
									for (i = 0; i < 4; i++) {
									if (doutekip4[kp4][jtuki][i] == 3) {
									if (j == 1) {
									doutekip4[kp4][jtuki][i] = 2;
									}
									j++;
									}
									}
									re += kitai(doutekip4[kp4]);*/
									//re += p[kp4] * hikaku[1];
									doutekip4[kp4][ytuki][ijkari[0]] = 2;
								}


							}
							else if (countc == 2 && countd == 2) {
								int l = 0;
								doutekip4[kp4][jtuki][jban] = 2;
								doutekip4[kp4][ytuki][yban] = 2;
								//doutekip4[kp4][19][3] = 5;
								double hikaku[4] = { 0,0,0,0 };
								int jkari[4] = { 0,0,0,0 };
								int ykari[4] = { 0,0,0,0 };
								for (i = 0; i < 4; i++) {
									if (doutekip4[kp4][jtuki][i] == 3) {

										doutekip4[kp4][jtuki][i] = 2;
										for (j = 0; j < 4; j++) {
											if (doutekip4[kp4][ytuki][j] == 3) {
												jkari[l] = i;
												ykari[l] = j;
												doutekip4[kp4][19][3] = 2;
												doutekip4[kp4][ytuki][i] = 2;
												hikaku[l] = hanten(doutekip4[kp4]);//moso
												doutekip4[kp4][ytuki][i] = 3;
												doutekip4[kp4][19][3] = 3;
												l++;
											}
										}
										doutekip4[kp4][jtuki][i] = 3;
									}
								}
								double max;
								int maxi;
								maxi = 0;
								max = hikaku[0];
								for (i = 1; i < 4; i++) {
									if (max < hikaku[i]) {
										max = hikaku[i];
										maxi = i;
									}
								}
								/*
								l = 0;
								for (i = 0; i < 4; i++) {
								if (doutekip4[kp4][jtuki][i] == 3) {
								for (j = 0; j < 4; j++) {
								if (doutekip4[kp4][ytuki][j] == 3) {
								if (l == mini) {
								doutekip4[kp4][jtuki][i] = 2;
								doutekip4[kp4][ytuki][i] = 2;
								}
								l++;
								}
								}
								}
								}
								re += kitai(doutekip4[kp4]);
								*/
								//re += p[kp4] * hikaku[maxi];
								doutekip4[kp4][jtuki][jkari[maxi]] = 2;
								doutekip4[kp4][ytuki][ykari[maxi]] = 2;

							}


						}
						//�I���\����Ɗ��Ғl�v�Z�̓t�F�C�Y2��
						doutekip4[kp4][19][3] = 5;
						rekp4sum += kitai(doutekip4[kp4]);
					}
					//kokoni phase5


					//kokomade phase5
				}
				delete[] doutekip4;

				re += (1.0 / jotai[20][3])*rekp4sum;
			}


			else
			{
				re = (-1)* tensukansu(jotai, 2);
				cout << "�R�D�������R�D�t�F�C�Y" << endl;
			}
		}
	}
	break;

	case 5:
	{
		int tenj4 = tensukansu(jotai, 4);
		if (tenj4 > jotai[19][1]) {
			double tenj2 = tensukansu(jotai, 2);
			if (jotai[18][0] < 3) {
				if (jotai[20][2] > 0) {
					jotai[17][0] += 1;
					jotai[19][1] = tenj4 + 1;
					jotai[19][3] = 3;
					//douteki���쐬

					if (hanten(jotai) > tenj2) {
						jotai[19][3] = 6;
						re = kitai(jotai);
					}
					else {
						re = (-1.0) * tenj2;
					}
				}
				else {
					re = (-1.0) * tenj2;
				}
			}
			else {
				if (jotai[20][2] > 0) {
					jotai[17][0] += 1;
					jotai[19][1] = tenj4 + 1;
					jotai[19][3] = 6;
					//douteki���쐬
					double koica = kitai(jotai);
					if (koica < (-1.0) * tenj2) {
						re = koica;
					}
					else {
						re = (-1.0) * tenj2;
					}
				}
				else {
					re = (-1.0) * tenj2;
				}
			}
		}
		else {
			if (jotai[20][2] > 0 || jotai[20][0] == 1) {
				jotai[19][3] = 6;
				re = kitai(jotai);
			}
			else {
				re = 0.0;
			}
		}

	}
	break;

	default:
	{
		int count = 0;
		for (i = 0; i < 16; i++) {
			for (j = 0; j < 4; j++) {
				if (jotai[i][j] == 4 || jotai[i][j] == 5 || jotai[i][j] == 6 || jotai[i][j] == 7) {
					count++;
				}
			}
		}
		if (count != 0) {
			int(*douteki)[23][4];
			douteki = new int[count][23][4];
			for (k = 0; k < count; k++) {
				int count2 = 0;
				int karituki = 0;
				int kariban = 0;
				for (i = 0; i < tukisu; i++) {
					for (j = 0; j < 4; j++) {
						if ((jotai[i][j] == 4 || jotai[i][j] == 5 || jotai[i][j] == 6 || jotai[i][j] == 7) && i < 16 && count2 == k) {
							douteki[k][i][j] = 12;
							karituki = i;
							kariban = j;
						}
						else {
							douteki[k][i][j] = jotai[i][j];
						}
						if ((jotai[i][j] == 4 || jotai[i][j] == 5 || jotai[i][j] == 6 || jotai[i][j] == 7) && i < 16) {
							count2++;
						}
					}
				}
				douteki[k][20][1] -= 1;
				douteki[k][19][3] = 1;//1..���͎��^�[���R�D�t�F�C�Y
				douteki[k][21][0] = karituki;
				douteki[k][21][1] = kariban;
			}

			if (jotai[18][0] != 1) {
				double max;
				//int	maxi;
				//maxi = 0;
				max = kitai(douteki[0]);
				for (i = 1; i < count; i++) {
					double qq = 0;
					qq = kitai(douteki[i]);
					if (max < qq) {
						max = qq;
						//maxi = i;
					}
				}
				re = max;
			}
			else {
				/*
				double max;
				int	maxi;
				maxi = 0;
				max = kitaijijo(douteki[0]);
				for (i = 1; i < count; i++) {
				double qq = 0;
				qq = kitaijijo(douteki[i]);
				if (max < qq) {
				max = qq;
				maxi = i;
				}
				}
				re = kitai(douteki[maxi]);
				*/

				double max;
				//int maxi;
				int *maxihai;
				maxihai = new int[jotai[20][1]];
				int maxikosu = 1;
				//maxi = 0;
				max = kitaijijo(douteki[0]);
				maxihai[0] = 0;
				for (i = 1; i < count; i++) {
					double qq = kitaijijo(douteki[i]);
					if (max < qq) {
						max = qq;
						//maxi = i;
						maxikosu = 1;
						maxihai[0] = i;
					}
					else if (max == qq) {
						maxihai[maxikosu] = i;
						maxikosu++;
					}
				}

				for (i = 0; i < maxikosu; i++) {
					re += (1.0 / maxikosu) * kitai(douteki[maxihai[i]]);
				}
				delete[] maxihai;
			}
			delete[] douteki;

		}

		else
		{
			cout << "��D�̂Ȃ���D�t�F�C�Y" << endl;
			re = tensukansu(jotai, 1);
		}
	}
	break;
	}
	//cout << "�Ԃ��l" << re << endl;
	return re;
}

int que(int jotai[][4], int n) {
	int ans = 0;
	switch (n) {
	case 0:
	{
	}
	break;
	case 1:
	{
	}
	break;
	case 2:
	{
	}
	break;
	default:
	{
		cout << "�_���݂����ł���" << endl;
	}
	break;
	}
	return ans;
}








