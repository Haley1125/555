#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<math.h>


/*
测试学生信息
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

//随机抽取学生回答问题
void random_question()
{
    char c[10];
    int choice = rand()%num;
    system("color F3");
    srand((int)time(0));
    printf("***********************\n");
    printf("姓名: %s", s[choice].name);
    printf("\n");
    printf("学号: %s", s[choice].id);
    printf("\n");
    printf("***********************\n");
    printf("是否答对?\nr(答对)    w(答错)\n");
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
            printf("输入错误 请重新输入\n");
            scanf("%s", c);
        }
    }
    while(1);
    printf("答题完成");
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

//浏览信息
void scan_data(int n)
{
    int i;
    system("color B2");
    //先按学号排序
    if(n!=0)
        sort_id();
    printf("所有学生回答情况如下:\n");
    printf("姓名\t学号\t班号\t答对次数\t答错次数");
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

//冒泡排序
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
            else if(s[j].right==s[j+1].right)   //回答正确次数一样 按学号排序
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
    printf("排序完成");
    printf("***********************");
    return ;
}

//冒泡排序
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
            else if(s[j].wrong==s[j+1].wrong)   //回答错误次数一样 按学号排序
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
    printf("排序完成");
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
            else if(s[j].right==s[j+1].right)   //回答正确次数一样 按学号排序
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
    printf("排序完成");
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
            else if(s[j].wrong==s[j+1].wrong)   //回答错误次数一样 按学号排序
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
    printf("排序完成");
    printf("***********************");
    return ;
}

//选择排序的方式
void sort_data()
{
    int c;
    system("color C1");
    printf("请选择排序方式:");
    printf("***********************");
    printf("1.按答对次数降序排序");
    printf("2.按答错次数降序排序");
    printf("3.按答对次数升序排序");
    printf("4.按答错次数升序排序");
    printf("5.返回主菜单");
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
        printf("排序未进行");
        return ;
    }
    else
    {
        printf("输入错误");
        return ;
    }
    scan_data(0);
    return ;
}

//保存数据 退出系统
void save_data()
{
    int t = 0, i;
    FILE *p = fopen("data.txt", "w");
    char color[] = "color 00";
    system("color 02");
    if(!p)
    {
        printf("保存失败!");
        exit(0);
    }
    printf("文件正在保存: [");
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
    printf("保存成功 请在data.txt中查看信息");
    return ;
}

void menu()
{
    int c;
    char t;
    system("color E0");
    while(1)
    {
        printf("\t\t课堂提问管理系统\n");
        printf("-----------------------------------------------------------\n");
        printf("1.随机提问   2.浏览回答情况\t3.回答情况排序\t4.退出系统\n");
        printf("-----------------------------------------------------------\n");
        printf("请选择(1-4):");
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
            printf("确认退出系统吗?");
            printf("1.是\t2.否");
            scanf("%c", &t);
            if(t=='1')
            {
                printf("感谢使用");
                exit(0);
            }
            else
            {
                break;
            }
        default:
            printf("输入错误");
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
    printf("\t\t欢迎使用课堂提问管理系统\n");
    printf("-----------------------------------------------------------\n");
    printf("1.随机提问   2.浏览回答情况\t3.回答情况排序\t4.退出系统\n");
    printf("-----------------------------------------------------------\n");
    if(!f)
    {
        printf("学生信息文件读取失败! 请查看 data.txt 文件是否在当前目录");
        exit(0);
    }
    printf("正在读取学生文件信息: [");
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
        printf("学生记录为空 请在data.txt中补充学生信息\n");
        exit(0);
    }
    else
    {
        printf("学生信息文件读取成功\n请按任意键进入提问系统\n");
        system("pause");
        system("cls");
    }
    fclose(f);
    return ;
}

int main()
{
    read_data(); //从文件中读取学生回答情况
    menu();     //进入菜单
    return 0;
}

