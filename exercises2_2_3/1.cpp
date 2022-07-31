#include <iostream>

#define MAXSIZE 10
using namespace std;
typedef struct {
    int data[MAXSIZE];
    int length;
} SeqList;

bool InitSeqList(SeqList &L) {
    L.length = 0;
    return true;
}

void AddTestData(SeqList &L) {
    int data[] = {3, 5, 9, 7, 2, 6};
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        L.data[i] = data[i];
        L.length++;
    }
}

void ShowSeqList(const SeqList &L) {
    cout << "当前顺序表中的元素为：";
    for (int i = 0; i < L.length; i++) {
        if (i != L.length - 1) {
            cout << L.data[i] << ",";
        } else {
            cout << L.data[i] << endl;
        }
    }
}

//删除顺序表中的最小值
int DelMinElem(SeqList &L) {
    if (L.length == 0) {//判断顺序表是否为空
        cout << "--------  顺序表为空，删除失败！  --------" << endl;
    }
    int j = 0;//定义最小值存放的下标
    for (int i = 1; i < L.length; i++) {//遍历顺序表，找到最小元素下标
        if (L.data[j] > L.data[i]) {
            j = i;
        }
    }
    int e = L.data[j];//将最小值保存下来，待后面返回使用
    L.data[j] = L.data[L.length - 1];
    L.length--;
    return e;//返回最小值
}

//顺序表逆序
void ReversSeqList(SeqList &L) {
    for (int i = 0; i < L.length / 2; i++) {
        int temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}

int main() {
    SeqList L;
    InitSeqList(L);
    AddTestData(L);
    ShowSeqList(L);
//    for (int i = 0; i < 6; i++) {
//        cout << "》》》删除的元素为：" << DelMinElem(L) << endl;
//        ShowSeqList(L);
//    }
    ReversSeqList(L);
    ShowSeqList(L);
    return 0;
}