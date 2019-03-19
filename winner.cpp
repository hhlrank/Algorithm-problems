#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	
	string str1, str2;
	vector<string> success, failure;
	cin >> n;
	if (n == 0)
		return 0;
	for (int i = 0; i < n; i++)
	{
		cin >> str1 >> str2;
		if (success.empty() && failure.empty())
		{
			success.push_back(str1);
			failure.push_back(str2);
		}
		  if(find(success.begin(), success.end(), str1)==success.end())
			success.push_back(str1);
		  if (find(failure.begin(), failure.end(), str1)== failure.end())
			failure.push_back(str2);
	}
	//for (vector<string>::iterator it = success.begin(); it != success.end(); it++)
		//cout << *it << " ";
	for (vector<string>::iterator iter = failure.begin(); iter != failure.end(); iter++)
	{
		vector<string>::iterator iter_temp = find(success.begin(), success.end(), *iter);
		if (iter_temp == success.end())
		continue;
		else
		success.erase(iter_temp);
	}
	
	if (success.size() == 1)
		cout << "Yes";
	else
		cout << "No";
		
	system("pause");
}