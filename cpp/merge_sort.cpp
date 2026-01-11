#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------
// 🔹 دالة دمج جزئين مفروزين من المصفوفة
// ------------------------------------------------------
void mergeTwoSortedParts(int* arr, int leftStart, int leftEnd, int rightStart, int rightEnd) {
    int totalSize = rightEnd - leftStart + 1;
    int* temp = new int[totalSize];

    int l = leftStart;   // مؤشر الجزء الأيسر
    int r = rightStart;  // مؤشر الجزء الأيمن
    int k = 0;           // مؤشر المصفوفة المؤقتة

    // ✅ دمج العناصر من الجزئين بترتيب تصاعدي
    while (l <= leftEnd && r <= rightEnd) {
        if (arr[l] < arr[r])
            temp[k++] = arr[l++];
        else
            temp[k++] = arr[r++];
    }

    // ✅ نسخ العناصر المتبقية من الجزء الأيسر
    while (l <= leftEnd)
        temp[k++] = arr[l++];

    // ✅ نسخ العناصر المتبقية من الجزء الأيمن
    while (r <= rightEnd)
        temp[k++] = arr[r++];

    // ✅ نسخ النتيجة من temp إلى arr
    for (int i = 0; i < totalSize; i++)
        arr[leftStart + i] = temp[i];

    delete[] temp; // تنظيف الذاكرة
}

// ------------------------------------------------------
// 🔹 دالة Merge Sort (تقسيم + دمج)
// ------------------------------------------------------
void mergeSort(int* arr, int start, int end) {
    if (start >= end)
        return; // حالة التوقف: عنصر واحد فقط

    int mid = (start + end) / 2;

    // 🟢 تقسيم المصفوفة إلى نصفين
    mergeSort(arr, start, mid);       // النصف الأيسر
    mergeSort(arr, mid + 1, end);     // النصف الأيمن

    // 🟠 دمج النصفين بعد فرزهما
    mergeTwoSortedParts(arr, start, mid, mid + 1, end);
}

// ------------------------------------------------------
// 🔹 الدالة الرئيسية لتجربة Merge Sort
// ------------------------------------------------------
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // 🔷 استدعاء Merge Sort
    mergeSort(arr, 0, n - 1);

    cout << "After Sorting:  ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
