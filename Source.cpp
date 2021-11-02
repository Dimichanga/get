#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector <double> table_val;
vector <double> table_time;
double get(double x)
{
	double bufftime, buffval;
	double val;
	ifstream fin("Left.txt");
	if (!fin.is_open())
		cout << "File is not open.";
	else
	{
		while (fin >> bufftime && fin >> buffval)
		{
			table_time.push_back(bufftime);
			cout << bufftime << '\t';
			table_val.push_back(buffval);
			cout << buffval << '\n';
		}
		fin.close();
		cout << '\n';

		int N = table_time.size();
		if (x >= table_time[N - 1])
			val = table_val[N - 1];
		else
		{
			int i = 0;
			while (table_time[i] < x) i++;
			val = table_val[i - 1] + ((table_val[i] - table_val[i - 1]) / (table_time[i] - table_time[i - 1])) * (x - table_time[i - 1]);
		}
		return val;

	}
}

int  main()
{
	double x;
	cout << "Enter time: " << '\n';
	cin >> x;
	cout << get(x);
	return 0;
}