# include "01Sort.h"

void Sort::selectSort(std::vector<int>vec)
{
    std::cout<<"selectSort : "<<std::endl;
    if(vec.size()<2)
    {
        return;
    }

    size_t i,j;
    for(i = 0;i<vec.size();++i)
    {
        size_t minIndex = i;
        for(j = i ;j<vec.size();++j)
        {
            if (vec[j]<vec[minIndex])
            {
                minIndex = j;
            }
        }
        swap(vec[i],vec[minIndex]);
    }
    showInfo(vec);
}

void Sort::bubbleSort(std::vector<int>vec)
{
    std::cout<<"bubbleSort : "<<std::endl;

    if(vec.size() <2)
        return;

    int i,j;
    for(i = 0;i<vec.size();++i)
    {
        for(j = 0;j<vec.size()-i-1;++j)
        {
            if(vec[j]>vec[j+1])
            {
                swap(vec[j],vec[j+1]);
            }
        }
    }

    showInfo(vec);
}

void Sort::insertSort(std::vector<int>vec)
{
    std::cout<<"insertSort : "<<std::endl;

    if(vec.size() <2)
    {
        return;
    }
    
    int i,j;
    for(i = 1;i<vec.size();++i)
    {
        for(j = i;j>0;--j)
        {
            if(vec[j-1] > vec[j])
            {
                swap(vec[j-1],vec[j]);
            }
        }
    }

    showInfo(vec);
}

void Sort::mergeSort(std::vector<int>vec)
{
    std::cout<<"mergeSort : "<<std::endl;
    if(vec.size() < 2)
        return;
    
    mergeSort(vec,0,vec.size()-1);

    showInfo(vec);
}   

void Sort::mergeSort(std::vector<int>&vec,size_t left,size_t right)
{
    if(left == right)
        return;

    size_t mid = left + ((right-left)>>1);

    // 将左侧数组继续划分
    mergeSort(vec,left,mid);

    // 右侧数组继续划分
    mergeSort(vec,mid+1,right);

    merge(vec,left,mid,right);
}

void Sort::merge(std::vector<int>&vec,size_t left,size_t mid,size_t right)
    {
        int * pArray = new int [right-left +1];

        int index = 0;
        int i = left;
        int j = mid+1;

        while (i <= mid  && j <= right)
        {
            if(vec[i]<vec[j])
            {
                pArray[index++] = vec[i++];
            }
            else
            {
                pArray[index++] = vec[j++];
            }
        }

        while (i <= mid)
        {
            pArray[index++] = vec[i++];
        }
        
        while (j <= right)
        {
            pArray[index++] = vec[j++];
        }
        
        for(index = 0;index <right-left+1;++index)
        {
            vec[left+index] = pArray[index];
        }

        delete [] pArray;
    }

void Sort::quickSort(std::vector<int>vec)
{
    std::cout<<"quickSort : "<<std::endl;
    if(vec.size() < 2)
        return;

    quickSort(vec,0,vec.size()-1);
    showInfo(vec);
}

void Sort::quickSort(std::vector<int>&vec,size_t left,size_t right)
{
    //  结束标志
    if (left >= right)
        return;

    int i = left;
    int j = right;
    int pivot = vec[i];

    while (i < j)
    {
       while (i < j && vec[j] >= pivot)
       {
           j--;
       }
       
       if(i < j)
       {
           vec[i++] = vec[j];
       }

       while (i < j && vec[i] < pivot)
       {
          i++;
       }

       if(i < j)
       {
          vec[j--] = vec[i];  
       } 
    }
    
    vec[i] = pivot;
    quickSort(vec,left,i-1);
    quickSort(vec,i+1,right);
}

void Sort::heapSort(std::vector<int>vec)
{
    std::cout<<"heapSort : "<<std::endl;
    if(vec.size() <2)
        return;
    for(size_t i = 0;i<vec.size();++i)
    {
        heapInsert(vec,i);
    }

    size_t size = vec.size();
    swap(vec[0],vec[--size]);
    while (size > 0)
    {
        heapify(vec,0,size);
        swap(vec[0],vec[--size]);
    }
    
    showInfo(vec);
}

void Sort::heapInsert(std::vector<int>&vec,size_t index)
{
    // 和父节点进行对比
    while (vec[index] > vec[(index-1)>>1])
    {
        swap(vec[index],vec[(index -1)>>1]);
        index = (index - 1)>>1;
    }   
}

void Sort::heapify(std::vector<int>& vec, int index, int size)
{
    //size为数组长度
    size_t left = 1+ (index << 1 );

    //孩子是否存在
    while (left < size )
    {
        // 孩子中的最大值
        size_t largest = left + 1 < size && vec[left+1] > vec[left] ?  left + 1 : left;
        largest = vec[largest] > vec[index] ? largest : index;
        if (largest == index) 
				break;
        swap(vec[largest], vec[index]);
		index = largest;	
		left = index * 2 + 1;
    }
}



void Sort::showInfo(std::vector<int>&vec) const
{
    std::vector<int>::const_iterator it = vec.begin();
    std::cout<<"elements : "<<std::endl;
    while (it != vec.end())
    {
        std::cout<<*it<<std::endl;
        it++;
    }   
}