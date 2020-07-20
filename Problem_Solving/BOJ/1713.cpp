#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
	N�� ����Ʋ �־�����.

	�ִ� ��õ 1000��

	<�л� ��ȣ, ��õ Ƚ��>
*/
//vector<pair<int, int>> SR;

typedef struct _SRT
{
	int num;
	int R;
	int T;
}SRT;

vector<SRT> vSRT;

//bool cmp(pair<int, int> l, pair<int, int> r)
//{
//	return l.second > r.second;
//}

bool cmp(SRT l, SRT r)
{
	if (l.R == r.R)
		return l.T > r.T;
	else
		return l.R > r.R;
}


int main()
{
	int n; cin >> n;
	int m; cin >> m;
	//int* arr = (int *)malloc(sizeof(int) * n);

	//memset(arr, -1, n);

	int tmp;
	int cnt = 0;
	for(int t = 0; t<m; t++)
	{
		cin >> tmp;
		/* ���� Ʋ�� ��� ���� ��� */
		int _size = vSRT.size();
		if (_size < n)
		{
			/* ó���� �ƹ� �ĺ��� ���ٸ� */
			if (_size == 0)
			{
				vSRT.push_back({ tmp, 1, t });
				cnt++;
			}
			else
			{
				/* �ĺ��� �� ���� �ʾ����� �̹� �ִ� ����� ��� */
				int i;
				for  (i = 0; i < cnt; i++)
				{
					if (vSRT[i].num == tmp)
					{
						vSRT[i].R++;
					}
				}
				/* �ĺ��� ���ٸ� */
				if (i == cnt)
				{
					vSRT.push_back({ tmp, 1, t });
					cnt++;
				}
			}
		}
		/* ��� �ִ� ���� Ʋ ���� ��� */
		else
		{
			int i;
			for ( i = 0; i < n; i++)
			{
				if (vSRT[i].num == tmp)
				{
					vSRT[i].R++;
					/*
						[����]
						�Խõ� �л��� ã�Ҵٸ�, ���� �˻����� �ʾƾ� �Ʒ��� if���� ������� �ʴ´�.
					*/
					break;
				}
			}

			/* �Խõ� �л��� �ƴ� ��� */
			if (i == n)
			{
				/* ���� ��õ�� ���� �л� ���� */
				// �л� ��ȣ�� �ƴ� ��õ ������ ����(��������) 
				/* 
					[���⼭ ����] ��õ ���� ���ٸ�, ���� ���� �־��� ���� �������� ������
					������ �����ϸ� �ȵȴ�.

					[����]
					�ڷ����� ����ü�� ���� �ð��� ������ ��ҷ� �����Ͽ���.
				*/
				sort(vSRT.begin(), vSRT.end(), cmp);
				vSRT.pop_back();

				/* ���ο� �л� �Լ� */
				vSRT.push_back({ tmp, 1, t });
			}
		}
	}
	vector<int> vtmp;
	for (int i = 0; i < n; i++)
	{
		vtmp.push_back(vSRT[i].num);
	}
	sort(vtmp.begin(), vtmp.end());

	for (int i = 0; i < n; i++)
	{
		printf("%d", vtmp[i]);
		if (i != n - 1)
			printf(" ");
	}
	return 0;
}

/*
	�ð��� ��Ÿ���� age��� ������ �� �߰��Ѵ�?

	�ƴϴ�. �׷��� �ð� �귯���°� ǥ���ϱ� �����.

	�ε����� �ĺ� ��ȣ�� �ε����� �����ؼ� ��õ�� ������ش�. 

*/