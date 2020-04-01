#include<cstdio>
#include<stack>
#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	stack<int> st;
	int user;
	cin >> user;

	for (int i = 0; i < user; i++)
	{
		string s;
		cin >> s;
		if (s == "pop")
		{
			if (st.empty() != true)
			{
				printf("%d\n", st.top());
				st.pop();
			}
			else
				cout << -1 << "\n";

		}
		else if (s == "size")
		{
			cout << st.size() << "\n";
		}
		else if (s == "empty")
		{
			if (st.empty() == true)
			{
				cout << 1 << "\n";
			}
			else
				cout << 0 << "\n";
		}
		else if (s == "push")
		{
			int x;
			cin >> x;
			st.push(x);
		}
		else if (s == "top")
		{
			if (st.empty() != true)
			{
				cout << st.top() << "\n";
			}
			else
				cout << -1 << "\n";
		}
	}
	return 0;
}