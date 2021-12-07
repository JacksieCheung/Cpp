#include <iostream>
using namespace std;
// 头节点存数据
// 初始化链表
struct LinkList
{
    int data;
    struct LinkList *next;
};

typedef struct LinkList node;

void Init(node *head)
{
    int num;
    int a[20];
    node *cur = head;

    cout << "请输入链表的元素个数:" << endl;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> a[i];
    }

    cur->data = a[0];
    for (int i = 1; i < num; i++)
    {
        node *temp = new node;
        temp->data = a[i];
        temp->next = NULL;
        cur->next = temp;
        cur = temp;
    }

    cur->next = NULL;
}

// 尾插法，顺序创建链表
// void Init2(node* head)
// {
//     int num;
//     int a;
//     cout<<"请输入要输入数的个数:"<<endl;
//     cin>>num;

//     cin>>a;
//     head = new node;
//     head->data = a;
//     head->next = NULL;

//     // 可不可以node* temp， temp->next = NULL;
//     node* pre = head;
//     for(int i=0; i<num-1; i++)
//     {
//         cin>>a;
//         node* temp = new node;
//         pre->next = temp;
//         pre->data = a;
//         pre = temp;
//     }

//     pre->next = NULL;
// }

// 输出链表的全部元素
void ListTraverse(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// 将数据e插入到第i个元素前面, i可以为1
// eg: 1 2 3 4
// i = 1, e =9
void ListInsert(node **head, int i, int e)
{
    node *temp = new node;
    temp->data = e;

    printf("参数%p\n", *head);

    if (i == 1)
    {
        temp->next = *head;
        *head = temp;
        // head->next = temp;
        // printf("之后%p\n", head);
        //cout<<head->data;

        return; // 不能插入第一个元素？？？？
    }

    node *cur = *head;
    for (int j = 0; j < i - 2; j++)
    {
        cur = cur->next;
    }

    temp->next = cur->next;
    cur->next = temp;
}

// 返回元素e在第几个位置
int LocateElem(node *head, int e)
{
    int pos = 1;
    node *temp = head;
    while (temp != NULL && temp->data != e)
    {
        temp = temp->next;
        pos++;
    }

    if (temp == NULL)
    {
        return -1;
    }

    return pos;
}

// 返回链表的长度
int ListLength(node *head)
{
    node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// 销毁链表
void Destroy(node *head)
{
    node *cur = head;
    node *pre = head;

    while (pre != NULL)
    {
        pre = cur->next;
        delete cur;
        cur = pre;
    }
    cout << "链表已经销毁" << endl;
}
int main()
{
    // node* head1;     // 没有分配内存吗？？？
    node *head1 = new node;
    printf("分配%p\n", head1);
    Init(head1);

    ListTraverse(head1);

    ListInsert(&head1, 1, 9);
    cout << head1->data;

    //printf("   main   %p      \n", head1);
    // cout<<"pos: "<<LocateElem(head1, 4);
    cout << endl;
    ListTraverse(head1);
    Destroy(head1);
    return 0;
}