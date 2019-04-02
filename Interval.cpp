#include<iostream>
#include<queue>
using namespace std;
struct Program{
	int start, end;
	Program(int x = 0, int y = 0) :start(x), end(y) {}
	friend bool operator<(Program a, Program b)
	{
		return a.end > b.end;
	}
};
priority_queue<Program> pq;

int main()
{
	int n;
	while (cin >> n)
	{
		int a, b;
		if (n != 0)
		{
			for (int i = 0; i < n; i++)
			{
				cin >> a >> b;
				Program temp(a, b);
				pq.push(temp);
			}

			int maxend = 0,count=1;
			maxend = pq.top().end;
			pq.pop();
			while (!pq.empty())
			{
				if (pq.top().start >= maxend)
				{
					count++; maxend = pq.top().end;
				}
				pq.pop();
			}
			cout << count << endl;
		}
		else
			break;
	}
}



