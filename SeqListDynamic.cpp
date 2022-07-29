#include <iostream>
#define MaxSize 10

using namespace std;

typedef struct {
    int *data;
    int length;
    int maxSize;
} SeqList;

//初始化顺序表
void InitSeqLit(SeqList &seqList);

//添加测试数据
void TestData(SeqList &seqList);

//打印测试数据
void ShowSeqList(SeqList &seqList);

//动态增加顺序表长度
void IncreaseSize(SeqList &seqList, int len);

int main() {
    SeqList seqList;
    InitSeqLit(seqList);
    TestData(seqList);
    ShowSeqList(seqList);
    cout << "当前顺序表中的容量：" << seqList.maxSize << endl;
    IncreaseSize(seqList, 5);
    cout << "扩容后顺序表中的容量：" << seqList.maxSize << endl;
    IncreaseSize(seqList, 5);
    cout << "再扩容后顺序表中的容量：" << seqList.maxSize << endl;
    ShowSeqList(seqList);
    return 0;
}

//初始化顺序表
void InitSeqLit(SeqList &seqList) {
    seqList.data = (int *) malloc(MaxSize * sizeof(int));//为数据分配空间
    seqList.length = 0;//初始化长度为0
    seqList.maxSize = MaxSize;//最大长度为初始化长度
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
    cout << "当前顺序表中的元素为：";
    for (int i = 0; i < seqList.length; i++) {
        if (i != seqList.length - 1) {
            cout << seqList.data[i] << ", ";
        } else {
            cout << seqList.data[i] << endl;
        }
    }
}

//动态增加顺序表长度
void IncreaseSize(SeqList &seqList, int len) {
    int *p = seqList.data;//将原有的数据保存
    seqList.data = (int *) malloc((seqList.maxSize + len) * sizeof(int));//重新分配空间
    for (int i = 0; i < seqList.length; i++) {
        seqList.data[i] = p[i];//将原有的数据存入新分配的顺序表中
    }
    seqList.maxSize = seqList.maxSize + len;//修改最大空间的容量
    free(p);//释放原来的内容空间

}