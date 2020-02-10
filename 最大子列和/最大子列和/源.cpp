#include <iostream>
using namespace std;

int MaxSubseqSum1(int A[], int N)
{
	int ThisSum, MaxSum = 0;
	int i, j, k;

	for (i = 0; i < N; i++) {
		for (j = i; j < N; j++) {
			ThisSum = 0;
			for (k = i; k <= j; k++)
				ThisSum += A[k];
			if (ThisSum > MaxSum) {
				MaxSum = ThisSum;//�������ֵ
			}
		}
	}
	return MaxSum;
}


int MaxSubseqSum2(int A[], int N)
{
	int ThisSum, MaxSum = 0;
	int i, j;

	for (i = 0; i < N; i++) {
		ThisSum = 0;
		for (j = i; j < N; j++) {
			ThisSum += A[j];
		}
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
		}
	}
	return MaxSum;
}



/* ����3���ݹ�ֳ����ݣ��ֱ���ÿ���ָ��������кͣ�ʱ�临�Ӷ�Ϊ O(n*logn)*/
/* �������������ֵ*/
int Max3(int A, int B, int C) {
	return (A > B) ? ((A > C) ? A : C) : ((B > C) ? B : C);
}
/* ����*/
int DivideAndConquer(int a[], int left, int right) {

	/*�ݹ��������������ֻ��һ������*/
	// ������Ϊ����ʱ��������к�Ϊ�䱾��
	// ������Ϊ����ʱ��������к�Ϊ 0
	if (left == right) {
		if (0 < a[left])
			return a[left];
		return 0;
	}

	/* �ֱ�ݹ��ҵ�����������к�*/
	int center = (left + right) / 2;
	int MaxLeftSum = DivideAndConquer(a, left, center);
	int MaxRightSum = DivideAndConquer(a, center + 1, right);

	/* �ٷֱ������ҿ��������к�*/
	int MaxLeftBorderSum = 0;
	int LeftBorderSum = 0;
	for (int i = center; i >= left; i--) {  //Ӧ�ôӱ߽�����������
		LeftBorderSum += a[i];
		if (MaxLeftBorderSum < LeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	int MaXRightBorderSum = 0;
	int RightBorderSum = 0;
	for (int i = center + 1; i <= right; i++) {  // �ӱ߽�������ұ���
		RightBorderSum += a[i];
		if (MaXRightBorderSum < RightBorderSum)
			MaXRightBorderSum = RightBorderSum;
	}

	/*��󷵻طֽ�����������кͣ��ұ�������кͣ��Ϳ��������к�������������*/
	return Max3(MaxLeftSum, MaxRightSum, MaXRightBorderSum + MaxLeftBorderSum);
}
int MaxSubseqSum3(int a[], int n) {
	return DivideAndConquer(a, 0, n - 1);
}


int MaxSubseqSum4(int A[], int N)
{
	int ThisSum = 0, MaxSum = 0;
	int i;
	for (i = 0; i < N; i++) {
		ThisSum += A[i];
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		if (ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;
}

int main() {
	int n;
	int a[100000 + 5];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	MaxSubseqSum1(a, n);
	MaxSubseqSum2(a, n);
	MaxSubseqSum3(a, n);
	MaxSubseqSum4(a, n);
	return 0;
}
