/*
* a << b 는 a*2^b 인데 그러면 1 << n 은 2^n임!
*
* 예시를 1 2 1 2 이렇게 4개로 든다면
*/
int count = 0;


for (int i = 1; i < (1 << n); i++) { // 1 2 3 ... 15까지 이진수로 표현하면 0001 0010 0011 0100 0101 0110 .... 이런 식으로 4자리 수 모든 경우의 수가 표현!

	int sum = 0;
	for (int j = 0; j < n; j++) { // 4개면 4번 돌면서 자리수랑 매칭되는 값인 인덱스에 있는 값을 계속 합하면 부분 집합의 합을 다 구할 수 있다!

								  //            System.out.println(String.format(" i : %d, j : %d, ( i & ( 1 << j)) : %d", i, j, ( i & ( 1 << j))));
		if ((i & (1 << j)) > 0) { // i 랑 ( 1<< j) : 1*(2^j) 비트로 생각했을 때... 각 자리수랑 매칭되면 값이 0보다 클테니, 그 경우의 인덱스 값을 더해주면 됨!
			sum += sequences[j];
		}
	}

	//         System.out.println("SUM : "+ sum);

	if (sum == k) {
		count++;
	}
}

System.out.println("#" + testcase + " " + count);

