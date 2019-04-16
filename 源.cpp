#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int l, n;
	bool flag = false;
	while (cin >> l >> n)
	{
		int count = 0, len = 0;
		int* block = new int[n];
		for (int i = 0; i < n; i++)
			cin >> block[i];
		sort(block, block + n);
		for (int i = n-1; i>=0; i--)
			if (len < l)
			{
				len += block[i];
				count++;
				if (len >= l)
					flag = true;
			}
			else
				break;
		if (flag)
			cout << count;
		else
			cout << "impossible";

	}
}