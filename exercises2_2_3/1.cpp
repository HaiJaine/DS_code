#include <iostream>

#define MAXSIZE 20
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
//    int data[] = {3, 5, 9, 7, 2, 6, 5, 1, 5, 8, 5, 3, 6, 2, 4};
    int data[] = {1, 2, 3, 3, 5, 5, 5, 6, 7, 8, 8, 9, 9, 12, 14};
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

//删除线性表中所有值为x的数据元素
void DelAllXElem(SeqList &L, int x) {
    int j = 0;//用来记录不是顺序表中要删除元素的下标
    for (int i = 0; i < L.length; i++) {//遍历顺序表
        if (L.data[i] != x) {//将表中不是要删除的元素保留下来，这样就会跳过删除的元素
            L.data[j] = L.data[i];
            j++;//这个下标也可以表示表中剩余元素个数
        }
    }
    L.length = j;//将表长修改为删除后的元素个数
}

//删除线性表中所有值为x的数据元素
void DelAllXElem2(SeqList &L, int x) {
    int j = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == x) {//记录下待删除元素的个数
            j++;
        } else {
            L.data[i - j] = L.data[i];//每次往前移动的个数是当前下标减去等于要删除元素的个数
        }
    }
    L.length -= j;//最后将待删元素个数减去
}

//删除有序顺序表中其值在给定值s与t之间的所有元素（删除时不包括s与t对应元素）
bool Del_S_T_Elem(SeqList &L, int s, int t) {
    if (s >= t || s < 1 || s > L.length || t < 1 || t > L.length) {
        cout << "s，t不合法！" << endl;
        return false;
    }
    int c = t - s - 1;//待删除元素个数
    for (int i = s; i < L.length - c; i++) {//需要移动元素次数
        L.data[i] = L.data[i + c];
    }
    L.length -= c;
    return true;
}

//删除有序顺序表中其值在给定值s与t之间的所有元素（有序表中是有可能存在重复元素的）
bool Del_S_T_Elem_modify(SeqList &L, int s, int t) {
    int i, j;
    if (s >= t || L.length == 0) {
        cout << "s，t不合法！" << endl;
        return false;
    }
    for (i = 0; i < L.length && L.data[i] < s; i++); //找到值大于等于s的第一个元素，因为等于的元素是需要被覆盖的
    if (i >= L.length) {
        return false;//遍历完整个有序表，所有元素均小于s，返回
    }
    //执行到这，是因为找到了第一个大于等于s的元素
    for (j = i; j < L.length && L.data[j] <= t; j++);//找到值大于t的第一个元素，因为等于的元素是需要删除的
    for (; j < L.length; i++, j++) {//若for循环执行，说明找到大于t的第一个元素，若for不执行，说明找到表尾，都没有找到大于t的第一个元素
        L.data[i] = L.data[j];//前移，填补删除元素位置
    }
    L.length = i;//由于for循环最后会进行加一操作，正好可以解决下标从0开始的问题
    return true;
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
//    ReversSeqList(L);
//    DelAllXElem(L, 1);
//    DelAllXElem2(L, 5);
//    Del_S_T_Elem(L, 1, 18);
    Del_S_T_Elem_modify(L, 2, 3);
    ShowSeqList(L);
    return 0;
}