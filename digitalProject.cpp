#include <iostream>
using namespace std;
#include <vector>

void print_map(int* arr)
{
	cout << "K-map=\n";

	cout << arr[0] << "\t\t" << arr[1] << "\t\t" << arr[3] << "\t\t" << arr[2] << "\t\t" << endl;
	cout << arr[4] << "\t\t" << arr[5] << "\t\t" << arr[7] << "\t\t" << arr[6] << "\t\t" << endl;
	cout << endl;
}

bool possibily(vector <vector <string>>& farr, vector <string>& inside, int* arr)
{
	if (arr[0] && arr[1] && arr[2] && arr[3] && arr[4] && arr[5] && arr[6] && arr[7])
	{
		cout << "F = Tautology\n";
		return false;
	}

	if (!(arr[0] || arr[1] || arr[2] || arr[3] || arr[4] || arr[5] || arr[6] || arr[7]))
	{
		cout << "F = 0\n";
		return false;
	}

	//rows
	if (arr[0] && arr[1] && arr[3] && arr[2])
	{
		inside.push_back("A'");
		farr.push_back(inside);
		inside.clear();
	}
	if (arr[4] && arr[5] && arr[7] && arr[6])
	{
		inside.push_back("A");
		farr.push_back(inside);
		inside.clear();
	}
	//squares
	if (arr[0] && arr[2] && arr[4] && arr[6])
	{
		inside.push_back("C'");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[0] && arr[1] && arr[4] && arr[5])
	{
		inside.push_back("B'");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[1] && arr[3] && arr[5] && arr[7])
	{
		inside.push_back("C");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[2] && arr[3] && arr[7] && arr[6])
	{
		inside.push_back("B");
		farr.push_back(inside);
		inside.clear();
	}

	//Horizontal twos

	if (arr[0] && arr[2])
	{
		inside.push_back("A'");
		inside.push_back("C'");
		farr.push_back(inside);
		inside.clear();
	}


	if (arr[0] && arr[1])
	{
		inside.push_back("A'");
		inside.push_back("B'");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[1] && arr[3])
	{
		inside.push_back("A'");
		inside.push_back("C");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[3] && arr[2])
	{
		inside.push_back("A'");
		inside.push_back("B");
		farr.push_back(inside);
		inside.clear();
	}


	if (arr[4] && arr[6])
	{
		inside.push_back("A");
		inside.push_back("C'");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[4] && arr[5])
	{
		inside.push_back("A");
		inside.push_back("B'");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[5] && arr[7])
	{
		inside.push_back("A");
		inside.push_back("C");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[6] && arr[7])
	{
		inside.push_back("A");
		inside.push_back("B");
		farr.push_back(inside);
		inside.clear();
	}

	//Vertical twos
	if (arr[0] && arr[4])
	{
		inside.push_back("B'");
		inside.push_back("C'");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[1] && arr[5])
	{
		inside.push_back("B'");
		inside.push_back("C");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[3] && arr[7])
	{
		inside.push_back("B");
		inside.push_back("C");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[2] && arr[6])
	{
		inside.push_back("B");
		inside.push_back("C'");
		farr.push_back(inside);
		inside.clear();
	}

	//ones
	if (arr[0])
	{
		inside.push_back("A'");
		inside.push_back("B'");
		inside.push_back("C'");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[1])
	{
		inside.push_back("A'");
		inside.push_back("B'");
		inside.push_back("C");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[2])
	{
		inside.push_back("A'");
		inside.push_back("B");
		inside.push_back("C'");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[3])
	{
		inside.push_back("A'");
		inside.push_back("B");
		inside.push_back("C");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[4])
	{
		inside.push_back("A");
		inside.push_back("B'");
		inside.push_back("C'");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[5])
	{
		inside.push_back("A");
		inside.push_back("B'");
		inside.push_back("C");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[6])
	{
		inside.push_back("A");
		inside.push_back("B");
		inside.push_back("C'");
		farr.push_back(inside);
		inside.clear();
	}

	if (arr[7])
	{
		inside.push_back("A");
		inside.push_back("B");
		inside.push_back("C");
		farr.push_back(inside);
		inside.clear();
	}
	return true;
}


void first_deletion(vector <vector <string>>& farr)
{
	//Deleting extra groups
	for (int i = 0; i < farr.size() - 1; i++)
	{
		for (int j = i + 1; j < farr.size(); j++)
		{
			int included = true;
			for (int k = 0; k < farr[i].size(); k++)
			{
				if (find(farr[j].begin(), farr[j].end(), farr[i][k]) == farr[j].end())
				{
					included = false;
					break;
				}
			}
			if (included)
			{
				farr.erase(farr.begin() + j);
				j--;
			}
		}
	}

}

void second_deletion(vector <vector <string>>& farr)
{
	//Deleting other extra groups
	for (int i = 0; i < farr.size(); i++)
	{
		bool* exist = new bool[farr[i].size()];
		for (int o = 0; o < farr[i].size(); o++) exist[o] = false;
		for (int j = 0; j < farr[i].size(); j++)
		{
			for (int k = 0; k < farr.size(); k++)
			{
				if (k == i)
					continue;

				if (find(farr[k].begin(), farr[k].end(), farr[i][j]) != farr[k].end())
				{
					exist[j] = true;
					break;
				}
			}
		}
		bool erased = true;
		for (int o = 0; o < farr[i].size(); o++)
		{
			if (!exist[o])
			{
				erased = false;
				break;
			}
		}
		if (erased)
		{
			farr.erase(farr.begin() + i);
			i--;
		}
	}
}


void print_function(vector <vector <string>>& farr)
{
	cout << "F = ";
	for (int i = 0; i < farr.size() - 1; i++)
	{
		for (int j = 0; j < farr[i].size(); j++)
			cout << farr[i][j];
		cout << " + ";
	}
	for (int j = 0; j < farr[farr.size() - 1].size(); j++)
		cout << farr[farr.size() - 1][j];

}


int main() {

	int x, arr[8] = { 0 };
	cout << "Enter the minterms of the funciton\n";
	cout << "*enter -1 when you finish\n";
	cout << "For example, the input 0 1 2 3 5 -1 represents the function m(0,1,2,3,5)\n";
	vector <vector<string>> farr;
	vector <string> inside;

	do
	{
		cin >> x;
		while (x < -1 || x > 7)
		{
			cout << "Invalid input\n";
			cout << "re-enter the minterm\n";
			cin >> x;
		}
		if (x == -1)
			break;
		arr[x] = 1;
	} while (true);

	cout << endl << endl;

	print_map(arr);
	if (!possibily(farr, inside, arr)) return 0;
	first_deletion(farr);
	second_deletion(farr);
	print_function(farr);
	return 0;
}