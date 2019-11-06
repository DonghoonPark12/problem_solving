#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional> //내림차순
#include <vector>
using namespace std;

//https://www.acmicpc.net/blog/view/22

//(10 ≤ N ≤ 100)
//(1 ≤ K ≤ N)
//int vector<pair<int,int>> v[100];
float arr[100];
//vector<float> arr[100];
int main(void)
{
    int T, test_case;
    
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	char grade[10][3] = { "A+","A0","A-","B+","B0","B-","C+","C0","C-","D0" };
    scanf("%d", &T);
    for (test_case = 0; test_case < T; test_case++)
    {
        /////////////////////////////////////////////////////////////////////////////////////////////////
		int Ans = 0;
		int n,w; scanf(" %d %d",&n, &w); 
		float score;
		int tmp1= 0, tmp2 = 0, tmp3 = 0;
        for(int i=0;i<n;i++){
            scanf(" %d %d %d",&tmp1,&tmp2,&tmp3);
            score = tmp1 *(0.35) + tmp2 *(0.4) + tmp3 *(0.2);
            arr[i] = score;
        }

        float find = arr[w-1];

   //     sort(arr,arr+n, greater<float>());

   //     //w = find(arr.begin(),a.begin()+n)
   //     int Ans;
   //     for (int i = 0; i < n; i++){
			//if (find == arr[i]) {
			//	Ans = i / (n / 10);
			//	break;
			//}
   //     }
		for (int i = 0; i < n; i++) {
			if (arr[i] > arr[w - 1])
				Ans++;
		}

		for (int i = 0; i < n; i++) {arr[i] = 0; }
        /////////////////////////////////////////////////////////////////////////////////////////////////
        printf("#%d ", test_case + 1);
		//printf("%d\n", Ans);
		printf("%s",grade[Ans / (n/10)]);
        //if(Ans == 0) printf("A+"); else if(Ans ==1) printf("A0"); else if(Ans == 2) printf("A-");
        //else if (Ans == 3) printf("B+"); else if (Ans == 4) printf("B0"); else if (Ans == 5) printf("B-"); 
        //else if (Ans == 6) printf("C+"); else if (Ans == 7) printf("C0"); else if (Ans == 8) printf("C-");
        //else printf("D0");

		printf("\n");
    }

    return 0;
}