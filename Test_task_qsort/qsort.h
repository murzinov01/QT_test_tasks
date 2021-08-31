#ifndef QSORT_H
#define QSORT_H


template <typename T>
void quick_sort(T* items, int left, int right)
{
    int i = left, j = right;
    T tmp;
    T x = items[(left + right) / 2]; // select pivot element

    do
    {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j)
        {
            tmp = items[i];
            items[i] = items[j];
            items[j] = tmp;
            ++i;
            --j;
        }
    } while (i <= j) ;

    if (left < j) quick_sort(items, left, j);
    if (i < right) quick_sort(items, i, right);
}

#endif // QSORT_H
