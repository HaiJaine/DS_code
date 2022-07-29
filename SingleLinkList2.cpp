#include <iostream>

using namespace std;
//不带头结点的单链表

//定义一个单链表结点类型
typedef struct LNode {
    int data; //每个结点存放一个数据元素
    struct LNode *next; //指针指向下一个结点
    int length;
} LNode, *LinkList;

//初始化一个单链表（不带头结点）
void InitLinkList(LinkList &linkList);

//判断链表是否为空（不带头结点）
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
    ListInsert(linkList, 6, 888);
    showLinkList(linkList);
    LNode *t1 = GetElem(linkList, 6);
    if (t1 != nullptr) {
        cout << ">>>>>>>通过位序获取结点值为：" << t1->data << endl;
    } else {
        cout << ">>>>>>>通过位序获取结点值为：" << "出错啦" << endl;
    }
    LNode *t2 = LocateElem(linkList, 11);
    if (t2 != nullptr) {
        cout << ">>>>>>>通过元素值获取结点值为：" << t2->data << endl;
    } else {
        cout << ">>>>>>>通过元素值获取结点值为：" << "当前表中无该元素！！！" << endl;
    }
//    cout << "--------通过位序删除结点--------" << endl;
//    DelByIndex(linkList, 6);
//    showLinkList(linkList);
    cout << "--------通过元素删除结点--------" << endl;
    DelByElem(linkList, 11);
    showLinkList(linkList);
    return 0;
}

//初始化一个单链表（不带头结点）
void InitLinkList(LinkList &linkList) {
    linkList = (LNode *) malloc(sizeof(LNode *));
    linkList->next = nullptr;
    linkList->length = 0;
}

//判断链表是否为空（不带头结点）
bool ListIsEmpty(LinkList &linkList) {
    return nullptr == linkList;
}

//打印单链表中的元素
void showLinkList(const LinkList &linkList) {
    LinkList temp = linkList;//将链表中地址复制一份出来打印
    cout << "链表中一共有" << linkList->length << "个元素，分别为：";
    while (temp != nullptr) {//判断当前单链表中是否还有元素
        if (temp->next) {//未达到末尾时
            cout << temp->data << ",";
        } else {
            cout << temp->data << endl;
        }
        temp = temp->next;
    }
}

//采用头插法建立单链表
LinkList List_HeadInsert(LinkList &linkList) {
    LNode *s;
    for (int i = 0; i < 5; i++) {
        s = (LNode *) malloc(sizeof(LNode));//创建新结点
        s->data = (i + 1) * 11;//将数据存入新创建的结点中
        s->length = linkList->length;//将链表长度存入新结点
        s->next = linkList;//不带头结点的链表头插法的思想是，把新结点的下一个指针直接指向原表的首地址即可
        linkList = s;//将链表的首地址更新为s
        if (i == 0) {
            linkList->next = nullptr;
        }
        linkList->length++;//添加一个结点后，将头结点数据的值加一，表示链表中添加一个元素
    }
    return linkList;
}

//采用尾插法建立单链表
LinkList List_TailInsert(LinkList &linkList) {
    LNode *s, *r;//r为表尾指针
    r = linkList;//初始时，将表尾指针指向头结点
    for (int i = 0; i < 5; i++) {
        s = (LNode *) malloc(sizeof(LNode));//创建一个新结点
        s->data = (i + 1) * 11;//将输入的数据存入新结点
        s->length = linkList->length;
        if (i == 0) {
            linkList = s;
            r = linkList;
        } else {
            r->next = s;
            r = s;//将r指向表尾
        }
        linkList->length++;//将单链表数据位加一，表示链表新加一个元素
    }
    r->next = nullptr;//插入完成后，将表尾指针指向空
    return linkList;
}

//按位序插入结点（找到待插入位置的前一个结点，然后插入）
bool ListInsert(LinkList &linkList, int i, int e) {
    if (i < 1 || i > linkList->length + 1) {//linkList->length中存入链表长度
        cout << "插入位置不合法！" << endl;
        return false;
    }
    LNode *p = linkList;
    //找到要插入的位置
    int j = 0;
    while (p != nullptr && j < i - 2) {//循环找到i-1个结点，插入方式和头插法类似
        p = p->next;//移动指针，知道找到待插入位置的前一个结点
        j++;//记录下当前指针的位置
    }
    LNode *s = (LNode *) malloc(sizeof(LNode *));//创建插入的新结点
    s->data = e;//将插入元素存入新结点
    if (i == 1) {
        s->next = linkList;
        s->length = linkList->length;
        linkList = s;
    } else {
        s->next = p->next;//开始插入节点
        s->length = p->length;
        p->next = s;
    }
    linkList->length++;
    return true;
}

//按序号查找结点值
LNode *GetElem(const LinkList &linkList, int i) {
    if (i < 1 || i > linkList->length) {
        return nullptr;
    }
    LNode *p = linkList;//指针p指向链表首地址
    int j = 1;//p指针当前位序
    while (j < i && p != nullptr) {
        p = p->next;
        j++;
    }
    return p;
}

//按值查找结点
LNode *LocateElem(const LinkList &linkList, int e) {
    LNode *p = linkList;
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
    if (i < 1 || i > linkList->length) {
        return false;
    }
    LNode *s, *p = linkList;
    int j = 1;
    //找到待删除结点的前一个结点
    while (j < i - 1 && p != nullptr) {
        p = p->next;
        j++;
    }
    //删除第一个元素时需单独处理
    if (i == 1) {
        p->next->length = linkList->length;
        linkList = p->next;
    } else {
        s = p->next;//s为待删除的结点
        p->next = s->next;//将待删除的结点的下一个结点连接到s的前一个结点
    }
    linkList->length--;//删除结点后单链表长度减一
    return true;
}

//删除结点值（按元素值）
bool DelByElem(LinkList &linkList, int e) {
    LNode *s, *p = linkList;
    int len = linkList->length;
    for (int i = 0; i < len; i++) {
        //头结点特殊处理
        if (i == 0 && p->data == e) {
            p->next->length = linkList->length;
            linkList = p->next;
            linkList->length--;
            return true;
        }
        if (p->next->data == e) {
            s = p->next;
            p->next = s->next;
            linkList->length--;
            return true;
        }
        p = p->next;
    }
    cout << "未找到要删除的元素" << endl;
    return false;
}