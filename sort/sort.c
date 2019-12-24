//
// Created by Lucien on 2019/12/23.
//

#include "sort.h"


void print(ElementType A[], int N){
    for (int i = 0; i < N; ++i) {
        printf("%d \n ",A[i]);

    }
}

void insertsort(ElementType A[], int N){
    int p = 0;
    for (p=0;p<N;p++){
        ElementType temp;
        for (int j = p; j >0 && A[j-1]>A[j] ; j--) {
            temp = A[j];
            A[j] = A[j-1];
            A[j-1] = temp;

        }
    }
}

void shellsort(ElementType A[], int N){
    int i,j,incre;  // 序列类型很多
    for ( incre = N/2;incre>0;incre/=2){  // 指数 递减 ， 强化版 插入排序
        for( i = incre;i<N;i++){
            ElementType temp = A[i];
            for(j = i ; j>=incre ; j -= incre){
                if(A[j-incre]>A[j]){
                    temp = A[j];
                    A[j] = A[j-incre];
                    A[j-incre] = temp;
                } else{
                    break;
                }
            }
        }
    }

}
void merge(ElementType A[],ElementType temp [], int Lpos, int Rpos, int Rightend){  // {[Lpos][][][Rpos][][Rightend][][][][][][]}
    int i,leftend,NumElement,tmppos;
    leftend = Rpos-1;
    tmppos = Lpos;
    NumElement = Rightend - Lpos +1;

    while( Lpos <= leftend && Rpos<=Rightend){ // 主循环：线性比较+插入temp 的对应位置！！我们没有create更多的temp
        if(A[Lpos]<=A[Rpos]){
            temp [tmppos] = A[Lpos];  // 第一次错点！！！此处 只 incre Lpos
            tmppos++;
            Lpos++;
        } else{
            temp[tmppos] = A[Rpos];
            tmppos++;Rpos++;
        }
    }
    while (Lpos<=leftend){
        // 右 率先 插完
        temp[tmppos++] = A[Lpos++];
    }
    while (Rpos<=Rightend){
        temp[tmppos++] = A[Rpos++];
    }
    // 不浪费TEMP， COPY TEMP 进入A
    for(i=0;i<NumElement;i++){
        A[Rightend] = temp[Rightend];
        Rightend--;
    }

}

void mergedivide(ElementType A[],ElementType temp[],int left,int right){
    int center = (left+right)/2;
    if (left<right){
        mergedivide(A,temp,left,center);
        mergedivide(A,temp,center+1,right);
        merge(A,temp,left,center+1,right);  // 当 运行到merge这里时，已经是 left-center,,center+1-right 两个merge 好的array
    }
} // 分治法 分

void Mergesort(ElementType A[], int N){
    ElementType *temp = malloc(sizeof(ElementType)*N);
    if(temp!= NULL){
        mergedivide(A,temp,0,N-1);
        free(temp);
    } else{
        printf("fail\n");
    }
}

void swap(ElementType* A,ElementType* B){
    ElementType tmp;
    tmp = *B;
    *B = *A;
    *A = tmp;
}

ElementType Median3(ElementType A[], int left, int right){
    // 三数 中值，藏pivot；
    int center = (left+right)/2;
    // 意义在于 让 left right center 率先排好位置
    if(A[left]>A[center]){
        swap(&A[left],&A[center]);
    }
    if(A[left]>A[right]){
        swap(&A[left],&A[right]);
    }
    if(A[center]>A[right]){
        swap(&A[center],&A[right]);
    }

    // 藏头！！！（注意 将center 和 right-1 交换，并不影响 center 在 right左边，这意味着 center<right）
    swap(&A[center],&A[right-1]);
    return A[right-1];  // 输出的是 center 的 值，并不是 center元素的位置

}

void qcsort(ElementType A[],int left, int right){
    ElementType pivot = Median3(A,left,right);
    if(left+3<right){
        int i =left;
        int j =right-1; // ATTENTION pivot 在 这里！， 而 下文用的是 --j, 直接跳开 j  de
        while (1){
            while (A[++i]<pivot){;}
            while (A[--j]>pivot){;}
            if(i<j){
                swap(&A[i],&A[j]);
            } else{
                break;
            }
        }
        swap(&A[i],&A[right-1]);
        qcsort(A,left,i);
        qcsort(A,i+1,right);

    } else{
        insertsort(A,right-left+1);
    }

}

void Quicksort(ElementType A[],int N){
    qcsort(A,0,N-1);
}


void selectionsort(ElementType A[],int N){  // 错点： 每次被比较的应该是 min_indice,而不是i！！！
    int i,j,min_indice;
    for( i =0; i<N;i++){
        min_indice = i;
        for(j = i;j<N;j++){
            if(A[j]<A[min_indice]){
                min_indice =j;

            }

        }
        swap(&A[i],&A[min_indice]);
    }
}
void bubblesort(ElementType A[], int N){
    // 倒序版 insert, 相邻换位，从尾到头，最小的优先浮出来
    int i,j;
    for(i = 0;i<N;i++){
        for(j = 0;j<N-i-1;j++){  // !!!!!!这个 N-i-1 是必须的，否则 i = 0; j<N 时， j_+1会超出索引！！！
            if(A[j]>A[j+1]){
                swap(&A[j],&A[j+1]);
            }
        }
    }
}