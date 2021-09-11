#include <iostream>
#include <cmath>

using namespace std;

struct info
{
	string status, status_v;
	int weight;
	int weight_v, metabolism_v;
}Dessi;

void dietWeight(int W0, int I0, int T, int D, int I, int A)
{
	Dessi.weight_v = W0;
	Dessi.weight = W0;
	Dessi.metabolism_v = I0;
	while (D--)
	{
		Dessi.weight_v += (I - (A + Dessi.metabolism_v));
		Dessi.weight += (I - (A + I0));
		// float 형태로 꼭 바꿔준다
		if (abs(I - (A + Dessi.metabolism_v)) > T)
			Dessi.metabolism_v += floor(((float)(I - (A + Dessi.metabolism_v))) / 2);
		if (Dessi.weight_v <= 0 || Dessi.metabolism_v <= 0)
			Dessi.status_v = "Danger Diet";
		if (Dessi.weight <= 0)
			Dessi.status = "Danger Diet";
	}
}

int main()
{
	int W0, I0, T, D, I, A, A0=0;
	cin >> W0 >> I0 >> T >> D >> I >> A;
	dietWeight(W0, I0, T, D, I, A);
	// 일일 기초 대사량 고려 X
	if (Dessi.status=="Danger Diet")
		cout << Dessi.status<<'\n';
	else
		cout << Dessi.weight << ' ' << I0<<'\n';
	// 일일 기초 대사량 고려 O
	if (Dessi.status_v == "Danger Diet")
		cout << Dessi.status_v << '\n';
	else
	{
		cout << Dessi.weight_v << ' ' << Dessi.metabolism_v << ' ';
		if (I0 - (A0 + Dessi.metabolism_v) > 0)
			cout << "YOYO";
		else
			cout << "NO";
	}
}