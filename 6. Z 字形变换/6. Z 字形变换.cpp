// 6. Z 字形变换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//我们可以使用 \text{min}( \text{numRows}, \text{len}(s))min(numRows,len(s)) 个列表来表示 Z 字形图案中的非空行。

//从左到右迭代 ss，将每个字符添加到合适的行。可以使用当前行和当前方向这两个变量对合适的行进行跟踪。
//
//只有当我们向上移动到最上面的行或向下移动到最下面的行时，当前方向才会发生改变。
string convert1(string s, int numRows)
{
	if (numRows == 1) return s;

	vector<string> rows(min(numRows, int(s.size())));
	int curRow = 0;
	bool goingDown = false;

	for (char c : s) {
		rows[curRow] += c;
		if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
		curRow += goingDown ? 1 : -1;
	}

	string ret;
	for (string row : rows) ret += row;
	return ret;
}
string convert(string s, int numRows)
{
	string sout;
	if (numRows > 1)
	{
		int colum = (numRows - 1)*(s.length() / (2 * numRows - 2));
		if (s.length() % (2 * numRows - 2) != 0)
			colum++;
		vector<vector<char>> out(numRows, vector<char>(colum));
		for (int i = 0; i < numRows; i++)
			for (int j = 0; j < colum; j++)
			{
				out[i][j] = '\0';
			}
		int flag = 0;
		int tw = s.length();
		for (int col = 0, i = 0; i < s.length() && col < colum; col++)
		{
			if (col == 0 || col % (numRows - 1) == 0)//可以整除，该列为numrows个
			{
				for (int j = 0; j < numRows; j++)
				{
					out[j][col] = s[i++];
				}
				flag = numRows - 2;
			}
			else if (i >= s.length() - (s.length() % (2 * numRows - 2)))
			{
				for (int j = 0; j < s.length() % (2 * numRows - 2); j++)
				{
					out[j][col] = s[i++];
				}
			}
			else
			{
				out[flag][col] = s[i++];
				flag--;
			}
		}
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < colum; j++)
			{
				if (out[i][j] != '\0')
					sout.push_back(out[i][j]);
			}
		}
	}
	else
	{
		sout = s;
	}
	return sout;

}
int main()
{
	string out=convert1("PAHNAPLSIIGYIR", 2);
	int length =out.length();
	std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
