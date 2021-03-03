#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<math.h>


/*
����ѧ����Ϣ
test1 101 192 0 0
test2 102 191 0 0
test3 103 192 0 0
test4 105 192 0 0
test5 106 191 0 0
test6 107 191 0 0
test7 108 192 0 0
test8 109 193 0 0
test9 110 193 0 0
*/
typedef struct
{
    char name[50];
    char id[50];
    char class_[50];
    int right;
    int wrong;
}student;
student s[100];
int num = 0;

//�����ȡѧ���ش�����
void random_question()
{
    char c[10];
    int choice = rand()%num;
    system("color F3");
    srand((int)time(0));
    printf("***********************\n");
    printf("����: %s", s[choice].name);
    printf("\n");
    printf("ѧ��: %s", s[choice].id);
    printf("\n");
    printf("***********************\n");
    printf("�Ƿ���?\nr(���)    w(���)\n");
    scanf("%s", c);
    do
    {
        if(strcmp(c, "r") == 0)
        {
            s[choice].right++;
            break;
        }
        else if(strcmp(c, "w") == 0)
        {
            s[choice].wrong++;
            break;
        }
        else
        {
            printf("������� ����������\n");
            scanf("%s", c);
        }
    }
    while(1);
    printf("�������");
    return ;
}

void sort_id()
{
    student t;
    int i, j;
    for(i=0; i<num-1; i++)
    {
        for(j=0; j<num-1-i; j++)
        {
            if(s[j].id>s[j+1].id)
            {
                t=s[j];
                s[j]=s[j+1];
                s[j+1]=t;
            }
        }
    }
    return ;
}

//�����Ϣ
void scan_data(int n)
{
    int i;
    system("color B2");
    //�Ȱ�ѧ������
    if(n!=0)
        sort_id();
    printf("����ѧ���ش��������:\n");
    printf("����\tѧ��\t���\t��Դ���\t������");
    printf("\n");
    for(i=0; i<num; i++)
    {
        printf("%s\t", s[i].name);
        printf("%s\t", s[i].id);
        printf("%s\t", s[i].class_);
        printf("%d\t\t", s[i].right);
        printf("%d\n", s[i].wrong);
    }
    return ;
}

//ð������
void sort_fun1()
{
    student t;
    int i, j;
    for(i=0; i<num-1; i++)
    {
        for(j=0; j<num-1-i; j++)
        {
            if(s[j].right<s[j+1].right)
            {
                t=s[j];
                s[j]=s[j+1];
                s[j+1]=t;
            }
            else if(s[j].right==s[j+1].right)   //�ش���ȷ����һ�� ��ѧ������
            {
                if(s[j].id<s[j+1].id)
                {
                    t=s[j];
                    s[j]=s[j+1];
                    s[j+1]=t;
                }
            }
        }
    }
    printf("�������");
    printf("***********************");
    return ;
}

//ð������
void sort_fun2()
{
    student t;
    int i, j;
    for(i=0; i<num-1; i++)
    {
        for(j=0; j<num-1-i; j++)
        {
            if(s[j].wrong<s[j+1].wrong)
            {
                t=s[j];
                s[j]=s[j+1];
                s[j+1]=t;
            }
            else if(s[j].wrong==s[j+1].wrong)   //�ش�������һ�� ��ѧ������
            {
                if(s[j].id<s[j+1].id)
                {
                    t=s[j];
                    s[j]=s[j+1];
                    s[j+1]=t;
                }
            }
        }
    }
    printf("�������");
    printf("***********************");
    return ;
}

void sort_fun3()
{
    student t;
    int i, j;
    for(i=0; i<num-1; i++)
    {
        for(j=0; j<num-1-i; j++)
        {
            if(s[j].right>s[j+1].right)
            {
                t=s[j];
                s[j]=s[j+1];
                s[j+1]=t;
            }
            else if(s[j].right==s[j+1].right)   //�ش���ȷ����һ�� ��ѧ������
            {
                if(s[j].id>s[j+1].id)
                {
                    t=s[j];
                    s[j]=s[j+1];
                    s[j+1]=t;
                }
            }
        }
    }
    printf("�������");
    printf("***********************");
    return ;
}

void sort_fun4()
{
    student t;
    int i, j;
    for(i=0; i<num-1; i++)
    {
        for(j=0; j<num-1-i; j++)
        {
            if(s[j].wrong>s[j+1].wrong)
            {
                t=s[j];
                s[j]=s[j+1];
                s[j+1]=t;
            }
            else if(s[j].wrong==s[j+1].wrong)   //�ش�������һ�� ��ѧ������
            {
                if(s[j].id>s[j+1].id)
                {
                    t=s[j];
                    s[j]=s[j+1];
                    s[j+1]=t;
                }
            }
        }
    }
    printf("�������");
    printf("***********************");
    return ;
}

//ѡ������ķ�ʽ
void sort_data()
{
    int c;
    system("color C1");
    printf("��ѡ������ʽ:");
    printf("***********************");
    printf("1.����Դ�����������");
    printf("2.����������������");
    printf("3.����Դ�����������");
    printf("4.����������������");
    printf("5.�������˵�");
    printf("***********************");
    scanf("%d", &c);
    if(c==1)
    {
        sort_fun1();
    }
    else if(c==2)
    {
        sort_fun2();
    }
    else if(c==3)
    {
        sort_fun3();
    }
    else if(c==4)
    {
        sort_fun4();
    }
    else if(c==5)
    {
        printf("����δ����");
        return ;
    }
    else
    {
        printf("�������");
        return ;
    }
    scan_data(0);
    return ;
}

//�������� �˳�ϵͳ
void save_data()
{
    int t = 0, i;
    FILE *p = fopen("data.txt", "w");
    char color[] = "color 00";
    system("color 02");
    if(!p)
    {
        printf("����ʧ��!");
        exit(0);
    }
    printf("�ļ����ڱ���: [");
    for(i=0; i<num; i++)
    {
        fprintf(p, "%s\t", s[i].name);
        fprintf(p, "%s\t", s[i].id);
        fprintf(p, "%s\t", s[i].class_);
        fprintf(p, "%d\t", s[i].right);
        fprintf(p, "%d\n", s[i].wrong);
        printf(".");
        Sleep(100);
        system(color);
        color[7]='0'+t%7;
        t++;
    }
    fclose(p);
    printf("]");
    printf("����ɹ� ����data.txt�в鿴��Ϣ");
    return ;
}

void menu()
{
    int c;
    char t;
    system("color E0");
    while(1)
    {
        printf("\t\t�������ʹ���ϵͳ\n");
        printf("-----------------------------------------------------------\n");
        printf("1.�������   2.����ش����\t3.�ش��������\t4.�˳�ϵͳ\n");
        printf("-----------------------------------------------------------\n");
        printf("��ѡ��(1-4):");
        scanf("%d", &c);
        switch(c)
        {
        case 1:
            random_question();
            break;
        case 2:
            scan_data(1);
            break;
        case 3:
            sort_data();
            break;
        case 4:
            save_data();
            printf("ȷ���˳�ϵͳ��?");
            printf("1.��\t2.��");
            scanf("%c", &t);
            if(t=='1')
            {
                printf("��лʹ��");
                exit(0);
            }
            else
            {
                break;
            }
        default:
            printf("�������");
            break;
        }
        system("pause");
        system("cls");
    }
    return ;
}

void read_data()
{
    int t=0;
	FILE *f = fopen("data.txt", "r");
    char color[] = "color 00";
    system("color 00");
    printf("\t\t��ӭʹ�ÿ������ʹ���ϵͳ\n");
    printf("-----------------------------------------------------------\n");
    printf("1.�������   2.����ش����\t3.�ش��������\t4.�˳�ϵͳ\n");
    printf("-----------------------------------------------------------\n");
    if(!f)
    {
        printf("ѧ����Ϣ�ļ���ȡʧ��! ��鿴 data.txt �ļ��Ƿ��ڵ�ǰĿ¼");
        exit(0);
    }
    printf("���ڶ�ȡѧ���ļ���Ϣ: [");
    while(fscanf(f, "%s", s[num].name)!=EOF)
    {
        fscanf(f, "%s", s[num].id);
        fscanf(f, "%s", s[num].class_);
        fscanf(f, "%d", &s[num].right);
        fscanf(f, "%d", &s[num].wrong);
        num++;
        printf(".");
        //Sleep(100);
        system(color);
        color[7]='0'+t%7;
        t++;
        // printf(color);
    }
    printf("]");
    if(num==0)
    {
        printf("ѧ����¼Ϊ�� ����data.txt�в���ѧ����Ϣ\n");
        exit(0);
    }
    else
    {
        printf("ѧ����Ϣ�ļ���ȡ�ɹ�\n�밴�������������ϵͳ\n");
        system("pause");
        system("cls");
    }
    fclose(f);
    return ;
}

int main()
{
    read_data(); //���ļ��ж�ȡѧ���ش����
    menu();     //����˵�
    return 0;
}

