#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
	N개 사진틀 주어진다.

	최대 추천 1000번

	<학생 번호, 추천 횟수>
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
		/* 사진 틀이 비어 있을 경우 */
		int _size = vSRT.size();
		if (_size < n)
		{
			/* 처음에 아무 후보도 없다면 */
			if (_size == 0)
			{
				vSRT.push_back({ tmp, 1, t });
				cnt++;
			}
			else
			{
				/* 후보가 다 차진 않았지만 이미 있는 사람일 경우 */
				int i;
				for  (i = 0; i < cnt; i++)
				{
					if (vSRT[i].num == tmp)
					{
						vSRT[i].R++;
					}
				}
				/* 후보가 없다면 */
				if (i == cnt)
				{
					vSRT.push_back({ tmp, 1, t });
					cnt++;
				}
			}
		}
		/* 비어 있는 사진 틀 없는 경우 */
		else
		{
			int i;
			for ( i = 0; i < n; i++)
			{
				if (vSRT[i].num == tmp)
				{
					vSRT[i].R++;
					/*
						[버그]
						게시된 학생을 찾았다면, 마저 검사하지 않아야 아래의 if문을 통과하지 않는다.
					*/
					break;
				}
			}

			/* 게시된 학생이 아닐 경우 */
			if (i == n)
			{
				/* 가장 추천수 적은 학생 제거 */
				// 학생 번호가 아닌 추천 순으로 정렬(내림차순) 
				/* 
					[여기서 버그] 추천 수가 같다면, 가장 오래 있었던 것을 내보내기 때문에
					무작정 정렬하면 안된다.

					[수정]
					자료형을 구조체로 만들어서 시간도 정렬의 요소로 포함하였다.
				*/
				sort(vSRT.begin(), vSRT.end(), cmp);
				vSRT.pop_back();

				/* 새로운 학생 입성 */
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
	시간을 나타내는 age라면 변수를 또 추가한다?

	아니다. 그러면 시간 흘러가는걸 표현하기 힘들다.

	인덱스가 후보 번호고 인덱스를 참고해서 추천수 등가시켜준다. 

*/