#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <stdio.h>
//#include "rect.h"
#include "math.h"
int	main(void)
{
	/*
	RECT	r = { 10, 10, 20, 20 }; //�簢�� ����ü ����, ����� ���� ���ʷ� ����. 
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

���ڿ��� �Էµ� ���� ������ ��ȯ
int __atoi(const char *str)
{
    //�迭�� �ִ� �� ó�� str[11]�� �ִٰ� �����ϰ� ���� �ȴ�.
    //���� ���ڿ��� ���� ���� ���ؾ� �Ѵٰ�???
    int i,dec=1;
    int sum=0;

    for(i=0;str[i];i++);//�� �ϸ�
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

���̰� ���� �� �ܾ� ã��
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

        //���� ������ �Ǻ� �� �� �־�� �Ұǵ�...

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
    char *p[100]={0};//������ �迭 100�� ����, ������ �迭�� ����Ű�� ���ڿ��� �ϴ� NULL�� �ʱ�ȭ ���� ���°� ����.
    //������ ����� 0���� �ʱ�ȭ �Ѱ����� ������ ���� ����Ű�� �͵��� NULL�� �Ѱ��� �ƴϴ�.
    char temp[80];//�ܾ� ������ �ӽ� ����
    //char *cp, *tm;
    int i=0,cnt;

    while(1)
	{
       printf("�ܾ� �Է�: ");
       gets(temp);//���⼭ temp�� data? text ���� �� ��� ���� �Ǵ� ���ϱ�? ���� �Ҵ��� �����ϰ�.
       //�����Ϳ��� �Ҵ��� ������ �̹� ������ ��ü�� �迭�� �� ������ ����.

       if(strcmp(temp,"end")==0)
       break;

       if((i != 0) && (  p[i - 1] [strlen(  p[i - 1]  ) - 1] != temp[0]))
		{
			printf("�ܾ� �ձⰡ �Ұ����մϴ�!\n");
			continue;
		}

        if (dup_check(p, temp, i))
		{
			printf("�̹� �����ϴ� �ܾ��Դϴ�!\n");
			continue;
		}

        p[i]=(char *)malloc(strlen(temp)+1); //NULL���� �������� �߰��ؼ� ���� �Ҵ� �ޱ�.
       //����Ű�� ���ڿ����� NULL�� �ʱ�ȭ�� �ʿ䰡 �ִ�. �׷��߸� ���� ���ڿ��� ������ ���ڿ� ������ ���ڿ��� ù��° ���ڳ��� �񱳰����ϴ�.
       //���ڿ� ���� ���� �Ҵ�.
       //�ش� �����Ͱ� ���� �Ҵ�� �޸� ������ ����Ű�� �ִ�.
        if(p[i] == NULL)
		{
			printf(" �޸� ���� \n");
			break;
		}
		strcpy(p[i],temp);//���� �Ҵ�� ������ ���ڿ� ����.
        //���� �Ҵ�� ���� data������ ����� ���ڿ��� ���� �����Ѱ�?????
//�ᱹ�� �ּҸ� �Ѱ��ִ� ���ε�, �ּҸ� �Ѱ��ָ� �����Ҵ�� ������ �� ����Ű�� data �ʵ带 ����Ű�� �Ǵ� ���̴ϱ�.
        i++;


       /*
		for(j=0;j<i;j++)
       {
           if(strcmp(p[j],temp)==0)
            printf("�̹� �����ϴ� �ܾ� �Դϴ�.\n");
       }
       */




       /*
       if(i>=1) //i�� 0�϶��� ����
       {

       cp=p[i-1]; //char�� ������ cp���� ���� ���ڿ��� ����Ű�� ������ ����� �ּҰ��� �־���.
       while(cp!=0)
       {
           cp++; //���ڿ� ������ �η� �ʱ�ȭ ���ִ� ���� �߿��ϰڴ�.
       }
       cp--; //cp�� ���� ���ڿ��� ������ �ܾ ����Ű�� �Ѵ�.



       if( *cp!=temp[0])//     p[i-1]���ڿ��� ������ ���ڰ� temp ���ڿ��� ù��° ���ڿ� ���� ������
        printf("�ܾ� �ձⰡ �Ұ��� �մϴ�.");
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
    int year;//���� �⵵
    int price;
    struct NODE *link;
}NODE;

int main(void)
{
    NODE *list=NULL; //��� ������
    NODE *prev, *p, *next;
    char buffer[S_SIZE];
    int year;

    while(1)
    {
        printf("å�� ������ �Է��Ͻÿ�: (���� �Ϸ��� ����)");
        gets(buffer);
        if(buffer[0]=='\0') //���͸� �Է��ϸ�
        //gets�Լ��� ����('\n') �Է��� '\0'���� ��ȯ�ؼ� ������ �ش�.
        break;

        p=(NODE*)malloc(sizeof(NODE));
        strcpy(p->title,buffer);
        printf("���� �⵵�� �Է��ϼ���: ");
        gets(buffer);//�Էµ� ���ڵ� ���ڿ��� �ν��Ѵ�.
        p->year=atoi(buffer);
        printf("å�� ������ �����ϼ���: ");
        gets(buffer); //�̷��� �ϸ� buffer�� ���� ���� ����� ����???
        p->price=atoi(buffer);
        if(list==NULL) //ó�� �ԷµǴ� �����̶��
            list=p; //p�� �ּҸ� list���� �Ѱ� �ش�.
        else
            prev->link=p; //ó�� �ԷµǴ� ������ �ƴ϶�� ���� ����� ��ũ�� p����ü�� �ּҸ� ���Խ��� �����Ѵ�.
        p->link=NULL; //p����ü�� �׻� ������ ��� �̹Ƿ� p����ü�� link�� �׻� Null�� ����Ű���� �Ѵ�.
        prev=p; //prev �����ʹ� p�� ����Ű�� �Ѵ�.
    }
    printf("\n");

    p=list;//list�� �ּҸ� p���� �ٽ� �Ѱ��ְ�.
    while(p!=NULL) //p�� null�� �ƴ���.
    {
        printf("å�� ����:%s ���� �⵵: %d å�� ����: %d",p->title,p->year,p->price);
        p=p->link;//���� p�� link���� �״��� ����� �ּҰ� ���� �Ǿ� �ִ�. p���� �ּҸ� �Ѱ��־� p�� �� ���� ��带 ����Ű�� �Ѵ�.
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
            fprintf(stderr,"�޸��� �Ҵ� ����\n");
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

    test.num=0x12345678; //data[0]�� 0x78 ����~~data[3]�� 0x12�� ������� ���� �ȴ�. (��Ʋ �ε��)

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
        printf("���ڿ��� �Է��ϼ���: ");
        gets(temp);
        if(temp[0]=='\0') break;

        str[i]=(char *)malloc(strlen(temp)+1);
        strcpy(str[i],temp);
        i++;

        if(i==max)
        {
            printf("���ڿ� �Է��� �ִ��� ��� ä�����ϴ�.\n");
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
    my_gets(str,sizeof(str)); //�迭 ��ü�� ũ�� 7
    printf("�Է��� ���ڿ�: %s\n",str);

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
