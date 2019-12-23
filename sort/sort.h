//
// Created by Lucien on 2019/12/23.
//

#ifndef SORT_SORT_H
#define SORT_SORT_H

#include <stdio.h>
#include <stdlib.h>
#define ElementType int
void print( ElementType A[],int N);
void insertsort( ElementType A[], int N);
void shellsort(ElementType A[], int N);

void merge(ElementType A[],ElementType temp[], int lpos,int rpos,int rend);
void mergedivide(ElementType A[],ElementType temp[], int left, int right);
void Mergesort(ElementType A[],int N);


void swap(ElementType* A,ElementType*B);
ElementType Median3(ElementType A[],int left, int right);
void qcsort(ElementType A[],int left, int right);

void Quicksort(ElementType A[],int N);
#endif //SORT_SORT_H
