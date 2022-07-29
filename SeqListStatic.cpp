#include <iostream>

#define MaxSize 15

using namespace std;

typedef struct {
    int data[MaxSize];
    int length;
} SeqList;

//初始化顺序表
void InitSeqLit(SeqList &seqList);

//添加测试数据
void TestData(SeqList &seqList);

//打印测试数据
void ShowSeqList(SeqList &seqList);

//插入元素
bool SeqListInset(SeqList &seqList, int i, int e);

//删除元素
bool SeqListDelete(SeqList &seqList, int i, int &e);

//按位查找
int getElement(SeqList &seqList, int i);

//按值查找（查找该元素第一次出现的位置，并返回查找元素的位置）
int locateElement(SeqList &seqList, int e);

int main() {
    SeqList seqList;
    InitSeqLit(seqList);
    TestData(seqList);
    ShowSeqList(seqList);
//    SeqListInset(seqList, 3, 555);
//    int e;
//    bool res = SeqListDelete(seqList, 5, e);
//    if (res) {
//        cout << "删除元素为：" << e << endl;
//    }
//    cout << getElement(seqList, 3) << endl;
    cout << locateElement(seqList, 9) << endl;
    ShowSeqList(seqList);
    return 0;
}

//初始化顺序表
void InitSeqLit(SeqList &seqList) {
    seqList.length = 0;//初始化长度为0
}

//添加测试数据
void TestData(SeqList &seqList) {
    int data[] = {3, 5, 2, 9, 7};
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        seqList.data[i] = data[i];
        seqList.length++;
    }
}

//打印测试数据
void ShowSeqList(SeqList &seqList) {
    cout << "顺序表中的元素为：";
    for (int i = 0; i < seqList.length; i++) {
        if (i != seqList.length - 1) {
            cout << seqList.data[i] << ", ";
        } else {
            cout << seqList.data[i] << endl;
        }
    }
}

//插入元素
bool SeqListInset(SeqList &seqList, int i, int e) {
    //插入位置合法性检测
    if (i < 1 || i > seqList.length + 1) {
        cout << "插入位置非法" << endl;
        return false;
    }
    //顺序表已满，不允许插入
    if (seqList.length >= MaxSize) {
        cout << "顺序表已满，不允许插入" << endl;
        return false;
    }
    //将插入位置的元素全部往后移动一位
    for (int j = seqList.length; j >= i; j--) {
        seqList.data[j] = seqList.data[j - 1];
    }
    seqList.data[i - 1] = e;//插入元素
    seqList.length++;//插入数据后将表长度+1
    return true;
}

//删除元素
bool SeqListDelete(SeqList &seqList, int i, int &e) {
    //判断删除位置是否合法
    if (i < 1 || i > seqList.length) {
        cout << "删除位置非法！" << endl;
        return false;
    }
    //表中无元素
    if (seqList.length < 1) {
        cout << "表中无元素" << endl;
        return false;
    }
    e = seqList.data[i - 1];
    for (int j = i; j <= seqList.length; j++) {
        seqList.data[j - 1] = seqList.data[j];
    }
    seqList.length--;
    return true;
}

//按位查找
int getElement(SeqList &seqList, int i) {
    if (i < 1 || i > seqList.length) {
        return -1;//默认表中没有负数
    }
    return seqList.data[i - 1];
}

//按值查找（查找该元素第一次出现的位置，并返回查找元素的位置）
int locateElement(SeqList &seqList, int e) {
    for (int i = 0; i < seqList.length; i++) {
        if (e == seqList.data[i]) {
            return i + 1;//数组元素下标是从0开始的，这里返回时需要进行加一
        }
    }
    return -1;//未查到时，返回-1
}