#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
typedef struct Node
{
    char name[8];
    char tele[12];
    char ID[11];
    struct Node* next;
}Node, * CLLinkList;
#define len sizeof(Node)
void InitCLLinkList(CLLinkList* head)//��ʼ��ѭ������
{
    *head = (CLLinkList)malloc(len);
    if (*head)//����ڴ�й©��������
    {
        (*head)->next = *head;
    }
}
int SearchCLLinkList1(CLLinkList head, char tele[])//�����ֻ���
{
    int j = 0; //�ó�ֵ
    Node* p;
    p = head->next;//�ó�ֵ
    while (p != head)
    {
        j++;
        if (strcmp(p->tele, tele) == 0)
            return(j);
        p = p->next;
    }
    return(0);
}
int SearchCLLinkList2(CLLinkList head, char name[])//��������
{
    int j = 0; //�ó�ֵ
    Node* p;
    p = head->next;//�ó�ֵ
    while (p != head)
    {
        j++;
        if (strcmp(p->name, name) == 0)
            return(j);
        p = p->next;
    }
    return(0);
}
void CreatCLLinkList(CLLinkList head)//ѭ������Ĵ���
{
    Node* rear, * s;
    char n1[8];
    char t1[12];
    char u1[11];
    int flag = 1;
    int a, b, n;
    rear = head;//rearָ�붯ָ̬��ǰ��β�����ʼֵָ��ͷ���
    cout << "��������Ҫ¼���ѧ��������:";
    cin >> n;
    while (flag)
    {
        for (b = 0; b < n; b++)
        {
            cout << "��������Ҫ��ӵ�ѧ��������:" << "\n";
            cin >> n1;
            s = (Node*)malloc(len);
            A:
            while (1)
            {
                cout << "��������Ҫ��ӵ�ѧ����10λѧ��:" << "\n";
                cin >> u1;
                if (strlen(u1) == 10)
                {
                    for (a = 0; a < 11; a++)
                    {
                        if ((u1[a] >= '0') && (u1[a] <= '9'))
                        {
                            if (s)//����ڴ�й©��������
                            {
                                strcpy_s(s->ID, u1);
                                goto B;
                            }

                        }
                        else
                        {
                            cout << "�������";
                            strcpy_s(u1, "");//������飬����ڴ��������
                            goto A;
                        }
                    }
                }
                else
                {
                    cout << "�������";
                    strcpy_s(u1, "");//������飬����ڴ��������
                    goto A;
                }
            }
            B:
            while (1)
            {
                cout << "��������Ҫ��ӵ�ѧ����11λ�绰����:" << "\n";
                cin >> t1;
                if (strlen(t1) == 11)
                {
                    for (a = 0; a < 11; a++)
                    {
                        if ((t1[a] >= '0') && (t1[a] <= '9'))
                        {
                            strcpy_s(s->tele, t1);
                            goto C;
                        }
                        else
                        {
                            cout << "�������";
                            strcpy_s(t1, "");//������飬����ڴ��������
                            goto B;
                        }
                    }
                }
                else
                {
                    cout << "�������";
                    strcpy_s(t1, "");//������飬����ڴ��������
                    goto B;
                }
            }
            C:
            strcpy_s(s->name, n1);
            strcpy_s(s->ID, u1);
            rear->next = s;
            rear = s;
        }
        flag = 0;
        rear->next = head;//���һ���ڵ��next��ָ��ͷ���
    }
}
void InCLLinkList(CLLinkList head, int i)//���
{
    Node* p, * s;
    int a, k = 0;
    int flag = 1;
    char n1[8], u1[11], t1[12];
    p = head;
    if (i <= 0)
    {
        cout << "�����λ�ò��Ϸ�:" << "\n";
        return;
    }
    while (p->next != head && k < i - 1)
    {
        k++;
        p = p->next;
    }
    s = (Node*)malloc(len);
    cout << "��������Ҫ��ӵ�ѧ��������" << "\n";
    cin >> n1;
    A:
    while (1)
    {
        cout << "��������Ҫ��ӵ�ѧ����10λѧ��:" << "\n";
        cin >> u1;
        if (strlen(u1) == 10)
        {
            for (a = 0; a < 11; a++)
            {
                if ((u1[a] >= '0') && (u1[a] <= '9'))
                {
                    if (s)//����ڴ�й©��������
                    {
                        strcpy_s(s->ID, u1);
                        goto B;
                    }

                }
                else
                {
                    cout << "�������";
                    strcpy_s(u1, "");//������飬����ڴ��������
                    goto A;
                }
            }
        }
        else
        {
            cout << "�������";
            strcpy_s(u1, "");//������飬����ڴ��������
            goto A;
        }
    }
    B:
    while (1)
    {
        cout << "��������Ҫ��ӵ�ѧ����11λ�绰����:" << "\n";
        cin >> t1;
        if (strlen(t1) == 11)
        {
            for (a = 0; a < 11; a++)
            {
                if ((t1[a] >= '0') && (t1[a] <= '9'))
                {
                    strcpy_s(s->tele, t1);
                    goto C;
                }
                else
                {
                    cout << "�������";
                    strcpy_s(t1, "");//������飬����ڴ��������
                    goto B;
                }
            }
        }
        else
        {
            cout << "�������";
            strcpy_s(t1, "");//������飬����ڴ��������
            goto B;
        }
    }
    C:
    strcpy_s(s->name, n1);
    strcpy_s(s->ID, u1);
    s->next = p->next;
    p->next = s;
    cout << "����ɹ���";
}
void Print_CLLinkList(CLLinkList head)//���
{
    Node* p;
    p = head->next;
    cout << "����         ѧ��             �绰\n";
    for (; p != head; p = p->next)
    {
        if (strlen(p->name) == 6)
        {
            printf("%s       %s       %s \n", p->name, p->ID, p->tele);
        }
        else if (strlen(p->name) == 4)
        {
            printf("%s         %s       %s \n", p->name, p->ID, p->tele);
        }
        else
        {
            printf("%s         %s       %s \n", p->name, p->ID, p->tele);
        }
    }

}
void DeleCLLinkList(CLLinkList head, char u1[])//ɾ��
{
    Node* p, * r;
    p = head;
    while (p->next != head && strcmp((p->next)->ID, u1) != 0)
    {
        p = p->next;
    }
    if (p->next == head)
    {
        cout << "��Ҫɾ����ѧ�Ų�����!";
        return;
    }
    r = p->next;
    p->next = r->next;
    free(r);
}
int LengthCLLinkList(CLLinkList head)//��ѭ������ĳ���
{
    int i = 0;
    Node* p;
    p = head->next;
    while (p != head)
    {
        i++;
        p = p->next;
    }
    return i;
}
int main()
{
    int i, y;
    char n1[8];
    char t1[12];
    char u1[11];
    int select = 1;
    CLLinkList head;
    InitCLLinkList(&head);
    while (select != 0)
    {
        cout << "**ѧ���������ϵͳ**\n"
                "  #���������ѡ��#\n"
                "   1-��ʼ¼����Ϣ\n"
                "   2-����ѧ����Ϣ\n"
                "   3-����λ�ò���\n"
                "   4-ɾ��ѧ����Ϣ\n"
                "   5-��ʾȫ����Ϣ\n"
                "   0-�������η���\n";
        cin >> select;
        switch (select)
        {
            case 1:
                CreatCLLinkList(head);
                cout << "\nѧ������ĳ�ʼ����Ϊ:\n";
                Print_CLLinkList(head);
                break;
            case 2:
                cout << "\n��������Ҫ���ҵ��ֻ���:\n";
                cin >> t1;
                y = SearchCLLinkList1(head, t1);
                if (y == 0)
                {
                    printf("\n\n%s����绰�Ų���ѧ��������\n\n", t1);
                }
                else
                {
                    printf("\n�ֻ���Ϊ%s���������ѧ�������е�λ��Ϊ%d\n", t1, y);
                }
                break;
            case 3:
                cout << "\n��������Ҫ������λͬѧ����������ǰ��:\n";
                cin >> n1;
                i = SearchCLLinkList2(head, n1);
                if (i == 0)
                {
                    cout << "\n��λͬѧ����ѧ�������У�\n\n";
                }
                else
                {
                    InCLLinkList(head, i);
                }
                cout << "������ѧ������Ϊ:\n";
                Print_CLLinkList(head);
                break;
            case 4:
                cout << "\n��������Ҫɾ��ѧ����ѧ��:\n";
                cin >> u1;
                DeleCLLinkList(head, u1);
                cout << "\nɾ�����ѧ������Ϊ:\n";
                Print_CLLinkList(head);
                printf("\nѧ������ĳ���Ϊ%d:\n", LengthCLLinkList(head));
                break;
            case 5:
                cout << "\n***ѧ������***\n";
                Print_CLLinkList(head);
                break;
            case 0:
                break;
            default:
                cout << "\n�������\n\n";
        }
    }
    cout << "\n";
    return 0;
}
