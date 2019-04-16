#include<iostream>
#include<stdio.h>
using namespace std;
const double N=1e-6;
void cla(int length)
{
	double fee = 0.0;
	while (length > 0)
	{
		if (length >= 13)
		{
			fee += 18;
			length -= 8;//结束的时候此时13>length>5
		}
		else if (length >8)
		{
			fee += 18 + 2.4*(length - 8);
			length = 0;
		}
		else if(length>5)
		{
			fee += 10 + 2 * (length - 4);
			length = 0;
		}
		else if(length>4&&length<=5)
		{
			fee += 10+2*(length-4);
			length = 0;
		}
		else
		{
			fee += 10;
			length = 0;
		}
		
	}
	if ((fee - (int)fee) < N)//是整数
		 cout<<(int)fee;
	else
	printf("%.1f", fee);

}
int main()
{
	int length = 0;
	while (cin >> length)
	{
		if (length == 0)
			return 0;
		 cla(length);
		 cout << endl;
	}
}