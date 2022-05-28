# ifndef  _01SORT_H_
# define  _01SORT_H_

# include <iostream>
# include <vector>
# include <memory>

inline void swap(int & a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

class Sort
{
public:
    // 选择排序 时间复杂度 O(N2)   空间复杂度0(1)
    void selectSort(std::vector<int>vec);

    // 冒泡排序  时间复杂度0(N2)   空间复杂度0(1)
    void bubbleSort(std::vector<int>vec);

    // 插入排序 时间复杂度0(N2)   空间复杂度0(1)
    void insertSort(std::vector<int>vec);

    //O(NlogN)  归并排序  递归   空间复杂度 O(N)
    void mergeSort(std::vector<int>vec);
    void mergeSort(std::vector<int>&vec,size_t left,size_t right);
    void merge(std::vector<int>&vec,size_t left,size_t mid,size_t right);
    
    void quickSort(std::vector<int>vec);
    void quickSort(std::vector<int>&vec,size_t left,size_t right);

    void heapify(std::vector<int>& vec, int index, int size);
    void heapSort(std::vector<int>vec);
    void heapInsert(std::vector<int>&vec,size_t index);

    // 有序数组中查值
    size_t findValue(std::vector<int>vec,int val)
    {
        if(!vec.size())
            return -1;
        
        size_t left = 0;
        size_t right = vec.size()-1;
        
        while (left <= right)
        {
            size_t mid = left + ((right-left)>>1);
            if(val < vec[mid])
            {
                right = mid-1;
            }
            else if(val > vec[mid])
            {
                left = mid+1;
            }
            else
            {
                return mid;
            }
        }
        
        return -1;
    }

    void showInfo(std::vector<int>&vec) const;   
};


# endif