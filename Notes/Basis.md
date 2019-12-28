## 关键字作用

* auto
    函数中定义的变量视为局部变量, 不被视为 全局变量。
* register
    提高访问速度
* static
    1. 对局部变量使用（函数里）：函数结束不会被销毁
    2. 对全局变量使用：使 该变量 局限在 申明它的文件内
    3. 全局变量 默认 自带 static
```
void augment(void){
    static int i = 0;   
    printf("i= %d\n",i++);}

int main()
    {    int j;
        for (int j = 0; j < 3; ++j) { 
        augment();    }}
```
**输出0，1，2**


* extern
    存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的。当您使用 'extern' 时，     对于无法初始化的变量，会把变量名指向一个之前定义过的存储位置。



## Reading & Writing integers
* int i  输入 11
* scanf( "%u",&i)
```math
11 = 1 * 10^1 +1 * 10^0
```
* scanf( "%o",&i)
```math
11 = 1 * 8^1 +1 * 8^0
```
* scanf( "%x",&i) // A-F 表示 10 到 15
```math
11 = 1 * 16^1 + 1 * 16^0
```

## 优先级
#### 取成员>自增自减>取值取非取反>代数运算>逻辑比较>与非比较
#### 赋值是最慢的 ，op=更慢