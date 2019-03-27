#include<string>
#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<stdlib.h>
#include<math.h>
using namespace std;

int get(string temp)
{
	int len = temp.length();
	int x = 0;
	for (int i=len-1;i>=0;i--)
		x += (temp[len-i-1]-'0')*pow(10,i);
	return (int)x;
}


void cut_str(string str)
{
	int count = 0;
	string* temp=new string [str.length()];
	string::size_type second=0,first=0;
	second = str.find('5');
	
	//vector<string> vc;
	
	/*
	cout << first << " " << second;
	int third = str.find('5', second + 1);
	cout << endl << third;
	*/

	
	while (first != str.npos)
	{
		if (second != 0 && second != str.npos)//第一个5不在开头
		{
			if (first == 0)
				temp[count++] = str.substr(first, second - first);
			else
			{
				
				
					if (second - first > 1)
						temp[count++] = str.substr(first + 1, second - first - 1);
				
			}
			first = second;
			second = str.find('5', first + 1);
		}

		else if (second == 0)//开头是5
		{
			second = str.find('5', first + 1);
			if (second - first >1)
			temp[count++] = str.substr(first + 1, second - first - 1);
			first = second;
		}
		else if(first<str.length())
		{
			
			int m = first, n = str.length();
			//cout << m << " " << n;
			//cout << first+1<<" ";
			//cout << (unsigned int)(str.length() - 2)-first ;
			if(m!=(n-1))
			temp[count++]=str.substr(first+1);
			break;
		}
		
	}



	
	for(int i=0;i<count;i++)
		if (temp[i][0] == '0')
		{
			string::size_type loc_0 = 0;
			while (temp[i][loc_0] == '0')loc_0++;
			temp[i] = temp[i].substr(loc_0);
			if (temp[i].empty())
				temp[i] = "0";
		}


	int* a = new int[count];
	/*
	int* a = new int[count];
	for (int i = 0; i < count; i++)
		a[i] = temp[i].length();

	int x = count + 1;
	while (x)
	{
		int k = 0;
		int min = a[0];
		for (int j = 1; j < count; j++)
		{
			if (min >= a[j])
			{
				min = a[j];
				k = j;
			}
		}
		a[k] = 99999;
		cout << temp[k] << " ";
		x--;
	}
	*/

	for (int i = 0; i < count; i++)
		a[i] = get(temp[i]);
	 sort(a,a+count);
	
	for (int i = 0; i < count; i++)
		cout << a[i] << " ";
	/*
	multimap<int,string> mapstr;
	for (int i = 0; i < count; i++)
		//cout << temp[i] << " ";
		//mapstr[temp[i].length()] = temp[i];
		mapstr.insert(pair<int, string>(temp[i].length(), temp[i]));

	multimap<int, string>::iterator iter = mapstr.begin();
	//cout <<iter->second<<" ";
	//iter++;  这里有错误点
	
	while (iter != mapstr.end())
	{
		cout << iter->second<<" ";
		iter++;
	}
	*/
	
}

int main()
{
	string str;
	cin >> str;


	cut_str(str);

		system("pause");
	
}