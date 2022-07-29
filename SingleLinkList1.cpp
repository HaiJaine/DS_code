#include <iostream>

using namespace std;
//带头结点的单链表

//定义一个单链表结点类型
typedef struct LNode {
    int data; //每个结点存放一个数据元素
    struct LNode *next; //指针指向下一个结点
} LNode, *LinkList;


//初始化一个单链表（带头结点）
void InitLinkList(LinkList &linkList);

//判断链表是否为空（带头结点）
bool ListIsEmpty(LinkList &linkList);

//打印单链表中的元素
void showLinkList(const LinkList &linkList);

//采用头插法建立单链表
LinkList List_HeadInsert(LinkList &linkList);

//采用尾插法建立单链表
LinkList List_TailInsert(LinkList &linkList);

//按位序插入结点（找到待插入位置的前一个结点，然后插入）
bool ListInsert(LinkList &linkList, int i, int e);

//按序号查找结点值
LNode *GetElem(const LinkList &linkList, int i);

//按值查找结点
LNode *LocateElem(const LinkList &linkList, int e);

//删除结点值（按位序）
bool DelByIndex(LinkList &linkList, int i);

//删除结点值（按元素值）
bool DelByElem(LinkList &linkList, int e);

int main() {
    LinkList linkList;
    InitLinkList(linkList);//带头结点的方式
//    cout << "-----头插法------" << endl;
//    List_HeadInsert(linkList);
//    showLinkList(linkList);
    cout << "-----尾插法------" << endl;
    List_TailInsert(linkList);
    showLinkList(linkList);
    cout << "-----插入元素后-----" << endl;
    ListInsert(linkList, 1, 888);
    showLinkList(linkList);
    LNode *t1 = GetElem(linkList, 1);
    if (t1 != nullptr) {
        cout << ">>>>>>>通过位序获取结点值为：" << t1->data << endl;
    } else {
        cout << ">>>>>>>通过位序获取结点值为：" << "出错啦" << endl;
    }
    LNode *t2 = LocateElem(linkList, 55);
    if (t2 != nullptr) {
        cout << ">>>>>>>通过元素值获取结点值为：" << t2->data << endl;
    } else {
        cout << ">>>>>>>通过元素值获取结点值为：" << "当前表中无该元素！！！" << endl;
    }
//    cout << "--------通过位序删除结点--------" << endl;
//    DelByIndex(linkList, 6);
    cout << "--------通过元素删除结点--------" << endl;
    DelByElem(linkList, 55);
    showLinkList(linkList);
    return 0;
}

//初始化一个单链表（带头结点）
void InitLinkList(LinkList &linkList) {
    linkList = (LNode *) malloc(sizeof(LNode *));
    linkList->next = nullptr;
    linkList->data = 0;//头结点中的数据用来存链表的长度
}

//判断链表是否为空（带头结点）
bool ListIsEmpty(LinkList &linkList) {
    return linkList->next == nullptr;
}

//打印单链表中的元素
void showLinkList(const LinkList &linkList) {
    LinkList temp = linkList;//将链表中地址复制一份出来打印
    cout << "链表中一共有" << linkList->data << "个元素，分别为：";
    while (temp->next != nullptr) {//判断当前单链表中是否还有元素
        temp = temp->next;//采用的是带头结点的方式创建单链表，所以链表中的第一个结点没有数据，将当前指针指向下一个结点
        if (temp->next) {//未达到末尾时
            cout << temp->data << ",";
        } else {
            cout << temp->data << endl;
        }
    }
}

//采用头插法建立单链表
LinkList List_HeadInsert(LinkList &linkList) {
    LNode *s;
    int len = linkList->data;
    for (int i = len; i < len + 5; i++) {
        s = (LNode *) malloc(sizeof(LNode));//创建新结点
        s->data = (i + 1) * 11;//将数据存入新创建的结点中
        s->next = linkList->next;//采用头插法，新结点的next指针需要指向原单链表的第一个元素
        linkList->next = s;//将新结点插入表中，linkList为头指针
        linkList->data++;//添加一个结点后，将头结点数据的值加一，表示链表中添加一个元素
    }
    return linkList;
}

//采用尾插法建立单链表
LinkList List_TailInsert(LinkList &linkList) {
    LNode *s, *r;//r为表尾指针
    r = linkList;//初始时，将表尾指针指向头结点
    int len = linkList->data;
    for (int i = len; i < len + 5; i++) {
        s = (LNode *) malloc(sizeof(LNode));//创建一个新结点
        s->data = (i + 1) * 11;//将输入的数据存入新结点
        r->next = s;
        r = s;//将r指向表尾
        linkList->data++;//将单链表数据位加一，表示链表新加一个元素
    }
    r->next = nullptr;//插入完成后，将表尾指针指向空
    return linkList;
}

//按位序插入结点（找到待插入位置的前一个结点，然后插入）
bool ListInsert(LinkList &linkList, int i, int e) {
    if (i < 1 || i > linkList->data + 1) {//linkList->data头结点中存入链表长度
        return false;
    }
    LNode *p = linkList;
    //找到要插入的位置
    int j = 0;
    while (p != nullptr && j < i - 1) {//循环找到i-1个结点，插入方式和头插法类似
        p = p->next;//移动指针，知道找到待插入位置的前一个结点
        j++;//记录下当前指针的位置
    }
    LNode *s = (LNode *) malloc(sizeof(LNode *));//创建插入的新结点
    s->data = e;//将插入元素存入新结点
    s->next = p->next;//开始插入节点
    p->next = s;
    linkList->data++;
    return true;
}

//按序号查找结点值
LNode *GetElem(const LinkList &linkList, int i) {
    if (i < 1 || i > linkList->data) {
        return nullptr;
    }
    LNode *p = linkList->next;
    int j = 1;
    while (j < i && p != nullptr) {
        p = p->next;
        j++;
    }
    return p;
}

//按值查找结点
LNode *LocateElem(const LinkList &linkList, int e) {
    LNode *p = linkList->next;
    while (p != nullptr) {
        if (p->data == e) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

//删除结点值（按位序）
bool DelByIndex(LinkList &linkList, int i) {

    if (ListIsEmpty(linkList) || i < 1 || i > linkList->data) {
        return false;
    }
    LNode *s, *p = linkList;
    int j = 0;
    //找到待删除结点的前一个结点
    while (j < i - 1 && p != nullptr) {
        p = p->next;
        j++;
    }
    s = p->next;//s为待删除的结点
    p->next = s->next;//将待删除的结点的下一个结点连接到s的前一个结点
    free(s);//将s的内存释放掉，完成结点的删除
    linkList->data--;//删除结点后单链表长度减一
    return true;
}

//删除结点值（按元素值）
bool DelByElem(LinkList &linkList, int e) {
    LNode *s, *p = linkList;
    while (p->next != nullptr) {
        if (p->next->data == e) {//通过元素值找到了要删除的结点
            s = p->next;//s为待删除结点
            p->next = s->next;
            free(s);
            linkList->data--;
            cout << "删除元素《 " << e << " 》成功" << endl;
            return true;
        }
        p = p->next;
    }
    cout << "未找到要删除的元素" << endl;
    return false;
}