#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <stdio.h>
//#include "rect.h"
#include "math.h"
int	main(void)
{
	/*
	RECT	r = { 10, 10, 20, 20 }; //사각형 구조체 선언, 멤버에 값이 차례로 들어간다. 
	double area = 0.0;

	draw_rect(&r);
	move_rect(&r, 10, 20);
	draw_rect(&r);
	area = calc_area(&r);

	printf("%f\n", area);
	printf("%d\n", factorial(5));
	*/
	power(2, 3);

	return 0;
}

/*
int main(void)
{

    return 0;
}

문자열로 입력된 수를 정수로 반환
int __atoi(const char *str)
{
    //배열이 있는 것 처럼 str[11]이 있다고 생각하고 쓰면 된다.
    //먼저 문자열의 길이 부터 구해야 한다고???
    int i,dec=1;
    int sum=0;

    for(i=0;str[i];i++);//로 하면
    i--;

    for( ; i>=0;i--)
    {
        sum+=(str[i]-48)*dec;
        dec*=10;
    }

    return sum;

}
/*
int main(void)
{
    char numStr[11];

    int num;

    num=__atoi(numStr);

    printf("%d",num);

    return 0;
}

길이가 가장 긴 단어 찾기
int main(void)
{
    char ch;
    int cnt=0,max=0;
    int isFirstLine=1;

    while(  (   ch=getchar()    )!=-1  )
    {
        if(ch=='\n')
        {
            if(max<cnt)
            max=cnt;
            cnt=0;
            continue;

        //문자 갯수를 판별 할 수 있어야 할건데...

        }
        cnt++;
    }

    printf("%d",max);

    return 0;
}



int main(void)
{
    char ch;
    int cnt=0;

    while(1)
    {
        scanf("%c",&ch);

        if(ch=='\0')
        {
             break;
        }
        cnt++;
    }
    printf("%d",cnt);

    return 0;
}




/*
int dup_check(char **sp, char *temp, int i);
int main(void)
{
    char *p[100]={0};//포인터 배열 100개 생성, 포인터 배열이 가리키는 문자열은 일단 NULL로 초기화 시켜 놓는게 좋다.
    //포인터 상수를 0으로 초기화 한것이지 포인터 들이 가리키는 것들을 NULL로 한것은 아니다.
    char temp[80];//단어 저장할 임시 공간
    //char *cp, *tm;
    int i=0,cnt;

    while(1)
	{
       printf("단어 입력: ");
       gets(temp);//여기서 temp는 data? text 영역 중 어디 저장 되는 것일까? 동적 할당을 제외하고.
       //포인터에게 할당을 했으나 이미 포인터 자체가 배열의 한 원소인 상태.

       if(strcmp(temp,"end")==0)
       break;

       if((i != 0) && (  p[i - 1] [strlen(  p[i - 1]  ) - 1] != temp[0]))
		{
			printf("단어 잇기가 불가능합니다!\n");
			continue;
		}

        if (dup_check(p, temp, i))
		{
			printf("이미 존재하는 단어입니다!\n");
			continue;
		}

        p[i]=(char *)malloc(strlen(temp)+1); //NULL문자 공간까지 추가해서 공간 할당 받기.
       //가리키는 문자열들이 NULL로 초기화될 필요가 있다. 그래야만 이전 문자열의 마지막 문자와 들어오는 물자열의 첫번째 문자끼리 비교가능하다.
       //문자열 저장 공간 할당.
       //해당 포인터가 동적 할당된 메모리 공간을 가리키고 있다.
        if(p[i] == NULL)
		{
			printf(" 메모리 부족 \n");
			break;
		}
		strcpy(p[i],temp);//동적 할당된 공간에 문자열 복사.
        //동적 할당된 곳에 data영역에 저장된 문자열을 복사 가능한가?????
//결국엔 주소를 넘겨주는 것인데, 주소를 넘겨주면 동적할당된 공간을 안 가리키고 data 필드를 가리키게 되는 꼴이니까.
        i++;


       /*
		for(j=0;j<i;j++)
       {
           if(strcmp(p[j],temp)==0)
            printf("이미 존재하는 단어 입니다.\n");
       }
       */




       /*
       if(i>=1) //i가 0일때는 무시
       {

       cp=p[i-1]; //char형 포인터 cp에세 이전 문자열의 가리키는 포인터 상수의 주소값을 주었다.
       while(cp!=0)
       {
           cp++; //문자열 공간에 널로 초기화 해주는 것이 중요하겠다.
       }
       cp--; //cp가 이전 문자열의 마지막 단어를 가리키게 한다.



       if( *cp!=temp[0])//     p[i-1]문자열의 마지막 문자가 temp 문자열의 첫번째 문자와 같지 않으면
        printf("단어 잇기가 불가능 합니다.");
        }

    }
    cnt=i;

    for(i=0;i<cnt;i++)
    {
        printf("%s  ", p[i]);
    }

	for(i = 0; i < cnt; i++)
	{
		free(p[i]);
	}
    return 0;

}

int dup_check(char **sp, char *temp, int i)
{
	int j;

	for(j = 0; j < i; j++)
	{
		if(strcmp(temp, sp[j]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
/*
*/

/*
#define S_SIZE 50

typedef struct NODE
{
    char title[S_SIZE];
    int year;//출판 년도
    int price;
    struct NODE *link;
}NODE;

int main(void)
{
    NODE *list=NULL; //헤드 포인터
    NODE *prev, *p, *next;
    char buffer[S_SIZE];
    int year;

    while(1)
    {
        printf("책의 제목을 입력하시오: (종료 하려면 엔터)");
        gets(buffer);
        if(buffer[0]=='\0') //엔터만 입력하면
        //gets함수는 엔터('\n') 입력을 '\0'으로 전환해서 저장해 준다.
        break;

        p=(NODE*)malloc(sizeof(NODE));
        strcpy(p->title,buffer);
        printf("출판 년도를 입력하세요: ");
        gets(buffer);//입력된 숫자도 문자열로 인식한다.
        p->year=atoi(buffer);
        printf("책의 가격을 입혁하세요: ");
        gets(buffer); //이렇게 하면 buffer의 값이 새로 만들어 지나???
        p->price=atoi(buffer);
        if(list==NULL) //처음 입력되는 시점이라면
            list=p; //p의 주소를 list에게 넘겨 준다.
        else
            prev->link=p; //처음 입력되는 시점이 아니라면 이전 노드의 링크에 p구조체의 주소를 대입시켜 연결한다.
        p->link=NULL; //p구조체는 항상 마지막 노드 이므로 p구조체의 link는 항상 Null을 가르키도록 한다.
        prev=p; //prev 포인터는 p를 가르키게 한다.
    }
    printf("\n");

    p=list;//list의 주소를 p에게 다시 넘겨주고.
    while(p!=NULL) //p가 null이 아닌한.
    {
        printf("책의 제목:%s 출판 년도: %d 책의 가격: %d",p->title,p->year,p->price);
        p=p->link;//현재 p의 link에는 그다음 노드의 주소가 저장 되어 있다. p에게 주소를 넘겨주어 p가 그 다음 노드를 가리키게 한다.
    }
    p=list; //
    while(p!=NULL)
    {
        next=p->link;
        free(p);
        p=next;
    }

    }

*/
/*



#define INCREMENT 100;
double *scores =NULL;
int add_score(double new_score)
{
    static int limit=0;
    static int count=0;
    if(count<limit)
    {
        scores[count++]=new_score;
     }
     else
     {
        int new_limit=limit+INCREMENT;
        double *new_array=realloc(scores,new_limit*sizeof(double));
        if(new_array==NULL)
        {
            fprintf(stderr,"메모이 할당 오류\n");
        }
        else
        {
            scores=new_array;
            limit=new_limit;
            scores[count++]=new_score;
        }
        return count;
     }
}


*/
/*


typedef union _data
{
    unsigned char data[4];
    unsigned int num;
}Data;

int main(void)
{
    int i;
    Data test;

    test.num=0x12345678; //data[0]에 0x78 부터~~data[3]에 0x12가 순서대로 저장 된다. (리틀 인디언)

    for(i=0;i<4;i++)
        printf("%#x \n",test.data[i]);

    return 0;
}


void printf_str(char **);

int main(int argc,char **argv)
{
    char temp[80];
    char **str;
    int max;
    int i;

    max=atoi(argv[1]);
    str=(char**)malloc((max+1)*sizeof(char*));
    i=0;

    while(1)
    {
        printf("문자열을 입력하세요: ");
        gets(temp);
        if(temp[0]=='\0') break;

        str[i]=(char *)malloc(strlen(temp)+1);
        strcpy(str[i],temp);
        i++;

        if(i==max)
        {
            printf("문자열 입력이 최댓값을 모두 채웠습니다.\n");
            break;
        }
    }
    str[i]=0;
    print_str(str);

    i=0;
    while(str[i]!=0)
    {
        free(str[i]);
        i++;
    }
    free(str);
    return 0;

}

void print_str(char **ps)
{
    while(*ps !=0)
    {
        printf("%s\n",*ps);
        ps++;
    }
}



void my_gets(char *str,int size);

int main(void)
{

    char str[7];
    my_gets(str,sizeof(str)); //배열 전체의 크기 7
    printf("입력한 문자열: %s\n",str);

    return 0;
}

void my_gets(char *str, int size)
{
    char ch; int i=0;
    ch=getchar();
    while((ch!='\n')&&(i<size-1))
    {
        str[i]=ch;
        i++;
        ch=getchar();
    }
    str[i]='\0';
}


*/
