#include <iostream>

using namespace std;

int ArraySize;


int Sum(int* Array) // 합계를 Return하는 함수
{
	int Result = 0;
	for (int i = 0; i < ArraySize; i++)
	{
		Result += Array[i];
	}

	return Result;
}

float Avg(int* Array) // 평균을 Return하는 함수
{
	float Result = 0;
	for (int i = 0; i < ArraySize; i++)
	{
		Result += Array[i];
	}

	return Result / ArraySize;
}


void Sort(int* Array, int ArraySize, bool(*Comp)(int, int)) // 삽입정렬
{
	for (int i = 0; i < ArraySize - 1; ++i)
	{
		for (int j = i + 1; j < ArraySize; ++j)
		{
			if (Comp(Array[j], Array[i]))  // 원하는 순서일 때 swap
			{
				int temp = Array[i];
				Array[i] = Array[j];
				Array[j] = temp;
			}
		}
	}
}


int main()
{
	ArraySize = 5; // 5개가 아닌 N개의 입력을 받는다고 가정하고 재사용성을 고려한 코드를 작성했는지 확인

	int* Array = new int[ArraySize];

	// 숫자를 입력받아 배열에 저장
	for (int i = 0; i < ArraySize; i++)
	{
		cout << "숫자를 입력해주세요: ";
		cin >> Array[i];
	}

	cout << "Sum: " << Sum(Array) << '\n';
	cout << "Avg: " << Avg(Array) << '\n';

	// 오름차순 람다
	auto asc = [](int a, int b) { return a < b; };
	// 내림차순 람다
	auto desc = [](int a, int b) { return a > b; };

	// 오름차순 정렬
	Sort(Array, ArraySize, asc);
	cout << "오름차순: ";
	for (int i = 0; i < ArraySize; ++i) cout << Array[i] << " ";
	cout << endl;

	// 내림차순 정렬
	Sort(Array, ArraySize, desc);
	cout << "내림차순: ";
	for (int i = 0; i < ArraySize; ++i) cout << Array[i] << " ";
	cout << endl;
}