## Linkedlist Exercise（C语言算法与数据结构）

#### 3.2 参照P 打印L元素
```
void PrintLots(llist_ptr L,llist_ptr P){
    list_ptr  temp1 = L->head;
    list_ptr temp2 = P->head->next;
    while (temp2!=NULL){
        int n = temp2->element;
        for(int i =0;i<n;i++){
            if(temp1->next!=NULL){
            temp1 = temp1->next;} else{
                printf("Error\n");
                break;
            }

        }
        printf("%d\n",temp1->element);
        temp2 = temp2->next;
        temp1 = L->head;
    }
}
```

#### 3.3 换指针 换数据
```
void swap_ele(llist_ptr L,int beforeposition){
    set_pos(L,beforeposition);
    list_ptr temp1 = L->fence->next;
    L->fence->next = temp1->next;
    list_ptr temp2 = L->fence->next->next;
    L->fence->next->next = temp1;
    temp1->next = temp2;
}
```
#### 3.4 输出交集
```
llist_ptr intersect(llist_ptr L,llist_ptr P){
    // L,P 严格排序
    llist_ptr res = malloc(sizeof(llist_ptr));
    init_Linkedlist(res);
    set_start(L);set_start(P);set_start(res);
    next(L);next(P);
    while (L->fence !=NULL && P->fence!=NULL){
        if(L->fence->element==P->fence->element){
            append(res,L->fence->element);
            printf("%d\n",L->fence->element);

            //first error!!! should next；
            next(L);next(P);
        } else{
            if(L->fence->element<P->fence->element){
                next(L);
            } else{
                next(P);
            }
        }
    }
    return res;

}
```
#### 3.5 输出并集
```
llist_ptr Union(llist_ptr L,llist_ptr P){
    llist_ptr res = malloc(sizeof(llist_ptr));
    init_Linkedlist(res);
    set_start(L);set_start(P);set_start(res);
    next(L);next(P);
    while (L->fence!=NULL && P->fence!=NULL){ // 先跑光一个再， flush 剩下的
        if(L->fence->element==P->fence->element){
            append(res,L->fence->element);
            printf("%d\n",L->fence->element);

            //first error!!! should next；
            next(L);next(P);
        } else{
            if(L->fence->element<P->fence->element){
                append(res,L->fence->element);
                next(L);
            } else{
                append(res,P->fence->element);
                next(P);
            }
        }

    }
    while (L->fence!=NULL){
            append(res,L->fence->element);
            next(L);
    }
    while (P->fence!=NULL){
        append(res,P->fence->element);
        next(P);
    }
    return res;
    ```
