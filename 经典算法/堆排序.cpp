/**
 * 堆排序的平均时间复杂度为O(nlogn)，空间复杂度为O(1)。
 * 父节点i的左子节点在位置(2*i+1);
 * 父节点i的右子节点在位置(2*i+2);
 * 子节点i的父节点在位置floor((i-1)/2);
 * 在最大堆的数据结构中，堆中的最大值总是位于根节点。堆中定义以下几种操作：
 * 最大堆调整（max_heapify）：将堆的末端子节点作调整，使得子节点永远小于父节点
 * 创建最大堆（build_max_heap）：将堆所有数据重新排序
 * 堆排序（heap_sort）：移除位在第一个数据的根节点，并做最大堆调整的递归运算
 */

#include <iostream>
#include <algorithm>

using namespace std;

void print_out(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

void max_heapify(int arr[], int start, int end) {
  int dad = start; // 父节点索引
  int son = dad * 2 + 1; // 子节点索引

  while (son < end) {
    if (son + 1 < end && arr[son] < arr[son + 1]) { // 比较两个兄弟节点，选择较大者
      son++;
    }

    if (arr[dad] > arr[son]) { // 如果父节点大于子节点代表调整完毕
      return;
    } else { // 否则交换父子内容再继续子节点和孙节点的比较
      swap(arr[dad], arr[son]);
      dad = son;
      son = dad * 2 + 1;
    }
  }
}

void heap_sort(int arr[], int len) {
  // build_max_heap
  // 初始化，i从最后一个父节点开始调整
  for (int i = len / 2 - 1; i >= 0; i--) {
    max_heapify(arr, i, len);
  }

  // print_out(arr, len);

  // 先将第一个元素和已经排好的元素前一位做交换，再重新调整，直到排序完毕
  for (int i = len - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    max_heapify(arr, 0, i);
  }
}

int main() {
  int arr[] = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, -1, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
  int len = (int) sizeof(arr) / sizeof(*arr);

  heap_sort(arr, len);

  print_out(arr, len);

  return 0;
}
