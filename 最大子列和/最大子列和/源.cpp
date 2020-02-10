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
				MaxSum = ThisSum;//更新最大值
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



/* 方法3：递归分成两份，分别求每个分割后最大子列和，时间复杂度为 O(n*logn)*/
/* 返回三者中最大值*/
int Max3(int A, int B, int C) {
	return (A > B) ? ((A > C) ? A : C) : ((B > C) ? B : C);
}
/* 分治*/
int DivideAndConquer(int a[], int left, int right) {

	/*递归结束条件：子列只有一个数字*/
	// 当该数为正数时，最大子列和为其本身
	// 当该数为负数时，最大子列和为 0
	if (left == right) {
		if (0 < a[left])
			return a[left];
		return 0;
	}

	/* 分别递归找到左右最大子列和*/
	int center = (left + right) / 2;
	int MaxLeftSum = DivideAndConquer(a, left, center);
	int MaxRightSum = DivideAndConquer(a, center + 1, right);

	/* 再分别找左右跨界最大子列和*/
	int MaxLeftBorderSum = 0;
	int LeftBorderSum = 0;
	for (int i = center; i >= left; i--) {  //应该从边界出发向左边找
		LeftBorderSum += a[i];
		if (MaxLeftBorderSum < LeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	int MaXRightBorderSum = 0;
	int RightBorderSum = 0;
	for (int i = center + 1; i <= right; i++) {  // 从边界出发向右边找
		RightBorderSum += a[i];
		if (MaXRightBorderSum < RightBorderSum)
			MaXRightBorderSum = RightBorderSum;
	}

	/*最后返回分解的左边最大子列和，右边最大子列和，和跨界最大子列和三者中最大的数*/
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
