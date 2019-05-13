#include<deque>
#include<stdio.h>
	using namespace std;
struct Doc
{
	int idx;
	int weight;
};
int main()
{
	int input;
	scanf("%d", &input);
	for (int i = 0; i < input; i++)
	{
		deque<Doc> q;
		int size, idx;
		scanf("%d %d", &size, &idx);
		for (int ii = 0; ii < size; ii++)
		{
			Doc d;
			d.idx = ii;
			scanf("%d", &d.weight);
			q.push_back(d);
		}
		int output = 0;
		while (!q.empty())
		{
			auto val = q.front();
			bool isMax = false;
			for (int ii = 1; ii < q.size(); ii++)
			{
				if (val.weight < q[ii].weight)
				{
					q.pop_front();
					q.push_back(val);
					isMax = true;
					break;
				}
			}
			if (isMax) continue;
			q.pop_front();
			output++;
			if (val.idx == idx)
			{
				printf("%d\n", output);
				break;
			}
		}
	}
	return 0;
}
