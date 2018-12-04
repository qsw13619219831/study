#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
struct node
{
	int num;
	int is_data;
};
int main()
{
	vector<node> cluster;
	vector<node> TTemp;
	map <int, int> mp;
	mp.clear();
	node temp;
	int R_num;
	int curnum;

	temp.is_data = 0;
	temp.num = 10;
	cluster.push_back(temp);

	cout << "请使用add命令添加一个进程，delete命令删除一个进程!" << endl;
	while (1)
	{
		string s;
		cin >> s;
		if (s == "add")
		{
			cout << "请输入进程号及其的大小" << endl;
			cin >> R_num >> curnum;

			int flag = 0;
			int curIndex;

			int cmp = 11;
			for (int i = 0; i<cluster.size(); i++)
			{
				if (cluster[i].is_data == 0 && cluster[i].num >= curnum)
				{
					flag = 1;
					if (cluster[i].num - curnum<cmp)
					{
						curIndex = i;
						cmp = cluster[i].num - curnum;
					}
				}
			}
			if (flag)
			{
				cluster[curIndex].is_data = 1;
				mp[R_num] = curIndex;

				node op;
				TTemp.clear();
				int is_flag = 0;
				if (cluster[curIndex].num>curnum)
				{
					op.is_data = 0;
					op.num = cluster[curIndex].num - curnum;
					is_flag = 1;
				}

				for (int i = 0; i<cluster.size(); i++)
				{
					if (i == curIndex)
					{
						cluster[curIndex].num = curnum;
						TTemp.push_back(cluster[curIndex]);
						mp[R_num] = i;

						if (is_flag)
						{
							TTemp.push_back(op);
						}
					}
					else
						TTemp.push_back(cluster[i]);
				}

				cluster.swap(TTemp);


				for (int i = 0; i<cluster.size(); i++)
					cout << "大小 " << cluster[i].num << "  是否分配 " << cluster[i].is_data << endl;

			}
			else
			{
				cout << "内存不足！" << endl;
			}
		}

		else if (s == "delete")
		{
			int deletenum;
			cout << "请输入删除的进程：" << endl;
			cin >> deletenum;

			int i = mp[deletenum];
			while (--i >= 0 && cluster[i].is_data == 0)
			{

			}
			int j = mp[deletenum];
			while (++j<cluster.size() && cluster[j].is_data == 0)
			{

			}

			node kk;
			kk.num = 0;
			for (int e = i + 1; e <= j - 1; e++)
			{
				kk.num += cluster[e].num;
			}
			kk.is_data = 0;

			TTemp.clear();
			for (int p = 0; p<cluster.size();)
			{
				if (p == i + 1)
				{
					p = j;
					TTemp.push_back(kk);
				}
				else{
					TTemp.push_back(cluster[p]);
					p++;
				}

			}
			cluster.swap(TTemp);

			for (int i = 0; i<cluster.size(); i++)
				cout << "大小 " << cluster[i].num << "  是否分配 " << cluster[i].is_data << endl;

		}
	}
	return 0;
}
