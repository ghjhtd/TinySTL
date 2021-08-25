/*
 * @Author: gong hao jing
 * @Date: 2021-08-22 01:10:16
 * @LastEditTime: 2021-08-25 06:30:22
 * @LastEditors: Please set LastEditors
 * @Description: 这是一个用于嵌入式平台的c语言数据结构库的简单实现
 * @FilePath: \TinySTL\TinySTL.h
 * @Description: 
 * 该库采用了类似高级语言oop的程序设计思想，为方便在
 * 嵌入式设备上使用，对常用的数据结构进行了简单的实现
 * 1. 单向链表
 * 2，链队列
 * 3，栈
 * 4. Map集合
 * 
 * @History 2021-08-24 01:00:01   v1.0    @by gonghaojing 基本实现了常见数据结构，可在TinySTL_Test.exe程序中进行测试，排序和查找算法暂未实现 
 * 
 * @History 2021-08-24 12:22:12   v1.1    @by gonghaojing 完善了一个该库的测试程序(main.c)，由于该库使用了较多指针，而指针既强大又危险，因此写了一个测试程序用来debug，防止在嵌入式设备上运行时程序死机
 * 可以使用TinySTL_Test.exe进行测试
 * 
 * @History 2021-08-25 02:11:05   v2.0    @by gonghaojing 增加了Tiny_List,Tiny_Stack等一系列结构
 * 
 * Tiny_ 系列继承自List,Stack等父类，该类的结构体的前面一些数据保存方式与父类完全相同，
 * 在内存中，继承自父类的Tiny系列在前面的内存上与父类一致，因此可以用一个父类型指针指向子类型内存，
 * 当做父类型使用
 * Tiny_ 系列增加了一个data_size的属性，在初始化时指定每个节点对象的内存空间,不用每次添加数据
 * 时指定需要占用的内存空间大小使用上比他的父类方便了许多，
 * 但没有父类那么灵活。相当于在初始化时指定了数据类型，有种泛型的味道
 * 
 * 
 */

/*********************----Warning!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!***************
* 当data_size为0时，得到的数据是数据域的指针，但此时没有开辟额外的空间，而是用此指针来保存数据，因此可以
* 直接使用它
* 由于指针占用四个字节，可以保存任意类型的数据四个字节，只要注意保存和取出的时候采用相同的格式就可以
* 比如，put(float),取出时把数据放到一个float型变量里就可以了
* 
* 当data_size不为0时，得到的只是指向数据域的一个指针，该指针指向一块大小为data_size的堆数据空间，使用时要遵循
* 指针使用的相关规则
* 
*/


#ifndef __TINYSTL_H
#define __TINYSTL_H
#include <stdlib.h>
#include <string.h>

void* new(unsigned int data_size);
void print_error(char *chars);  //警告打印函数，在.c文件按需实现,方便查看报错信息

/**********************How to use******************
 * 新建数据结构对象有两种方式，1中是在栈中分配内存，第二种是程序运行时
 * 在堆中分配内存
 * 
 * 当data_size=0时，使用每个节点的指向数据域的指针存放数据（四个字节），不开辟新的内存
 * 并且传入的数据直接保存在节点里
 * 
 * 当data_size！=0时，开辟相应的内存空间用来存放数据
 * 每个节点占用12个字节的内存，每个数据结构对象占用几十个字节的数据
 * 传入的数据为一个指针，指向想要保存的数据的内存，然后把data_size个字节
 * 的数据复制到数据节点新开辟的内存中
 * 
 * 1.栈分配内存（Demo）：
 * List list = new_List(1024);     //内存限制为1k
 * list.addAt(&list, index, data, data_size);
 * list.removeAt(&list, index);
 * list.get(&list, index);
 * list.set(&list, index, data, data_size);
 * 
 * 2.堆分配内存
 * Map* map_ptr = (Map*)malloc(sizeof(Map));
 * (*map_ptr) = new_Map(1024);
 * map_ptr->push(map_ptr, 1, 0, "hello", 10);
 * (*map_ptr).push(map_ptr, 0, 0, "world", 10);
 * 
 * 
 * 
//---------------单向链表--------------------------
//如果采用双链表的话，在链表很长的时候查找可以快很多，但内存占用较大
//综合考虑下在嵌入式平台上选择实现占用内存相对较小的单链表

/***********************************************List概览
* 属性：
* length--------链表长度
* memory_size---该链表占用内存空间的大小，单位-字节
* memory_limit--限制该链表占用多少内存空间，单位-字节
* 
* 方法集合：                                           data_size = 0的时候将数据域指针用来存储数据
* List new_List(unsigned int memory_limit);                                                 //双向链表初始化

* void* get(List *list, unsigned int index);                                                //获取索引处的元素
* unsigned int getSize(List *list, unsigned int index);                                     //获取索引处的元素的大小
* 
* int add(List *list, void* data, unsigned int data_size);                                  //往链表尾部添加数据
* int addAt(List *list, unsigned int index, void* data，unsigned int data_size);            //往链表指定位置添加数据
* int set(List *list, unsigned int index, void* data，unsigned int data_size);              //更新链表指定位置的值
* int remove(List *list);                                                                   //删除链表尾部的数据
* int removeAt(List *list, unsigned int index);                                             //删除链表指定位置的数据
* int index(List *list, void* data, unsigned int data_size);                                //取得指定元素索引
* int indexFrom(List *list, unsigned int index, void* data, unsigned int data_size);        //从index处开始取得元素索引
* int delete_List(List* list);                                                              //删除整条链表并释放内存空间
* 
* unsigned int max(List *list，int (*compare)(void* first, void* second, unsigned int data_size));                         //获取最大元素的索引，需自己实现比较函数
* unsigned int maxOf(List *list, unsigned int index，int (*compare)(void* first, void* second, unsigned int data_size));   //获取第index大元素的索引，需自己实现比较函数
* unsigned int min(List *list，int (*compare)(void* first, void* second, unsigned int data_size));                         //获取最小元素的索引，需自己实现比较函数
* unsigned int minOf(List *list, unsigned int index，int (*compare)(void* first, void* second, unsigned int data_size));   //获取第index小元素的索引，需自己实现比较函数
*/

/***********************************************Queue概览
* 属性：
* length--------队列长度
* memory_size---该链表占用内存空间的大小，单位-字节
* memory_limit--限制该链表占用多少内存空间，单位-字节
*
* 方法集合：                                           data_size = 0的时候将数据域指针用来存储数据（四个字节）
* Queue new_Queue(unsigned int memory_limit);                                                             //队列初始化

* int push(Queue *queue, void* data, unsigned int data_size);                                             //往队列中添加数据
* int pop(Queue *queue);                                                                                  //从队列中弹出数据
* void* get(Queue *queue);                                                                                //获得队列中元素的值
* unsigned int getSize(Queue *queue);                                                                     //获得队列中元素所占内存空间的大小
* int delete(Queue *queue);                                                                               //删除队列
*/

/***********************************************Stack概览
* 属性：
* length--------栈长度
* memory_size---该链表占用内存空间的大小，单位-字节
* memory_limit--限制该链表占用多少内存空间，单位-字节
*
* 方法集合：               data_size = 0的时候将数据域指针用来存储数据（四个字节），不为0时自动开辟data_size字节大小的空间用来存放数据
* Stack new_Stack(unsigned int memory_limit);                                                             //栈初始化

* int push(Stack *stack, void* data, unsigned int data_size);                                             //往栈中添加数据
* int pop(Stack *stack);                                                                                  //从栈中弹出数据
* void* get(Stack *stack);                                                                                //获得栈中元素的值
* unsigned int getSize(Stack *stack);                                                                     //获得栈中元素所占内存空间的大小
* int delete(Stack *stack);                                                                               //删除栈
*/

/***********************************************Map概览
* 属性：
* key_head-------键链表
* data_head------数值链表
* length--------Map集合长度
* memory_size---该Map集合占用内存空间的大小，单位-字节
* memory_limit--限制该Map集合占用多少内存空间，单位-字节
*
* 方法集合：               data_size和key_size = 0的时候将数据域指针用来存储数据（四个字节），不为0时自动开辟data_size字节大小的空间用来存放数据
* Stack new_Map(unsigned int memory_limit);                                                 //栈初始化
* 
* int push(Map* map, void* key, unsigned int key_size, void* data, unsigned int data_size);      //往Map集合中添加数据
* int remove(Map* map, void* key, unsigned int key_size);                                        //删除key对应的键值对
* void* get(Map* map, void* key, unsigned int key_size);                                         //获得Map键值对应的数据元素指针
* void* getKey(Map* map, void* key, unsigned int key_size);                                      //获得Map数据值对应的键值指针
* unsigned int getSize(Map* map, void* key, unsigned int key_size);                              //获得Map键值对应的元素所占的内存大小
* unsigned int getKeySize(Map* map, void* key, unsigned int key_size);                           //获得Map键对应的元素所占的内存大小
* List* values(Map* map);                                                                        //返回map的值集合，返回类型是一个链表集合
* List* keySet(Map* map);                                                                        //返回map的键值集合，返回类型是一个链表集合
* int delete(Map* map);                                                                          //删除map集合
* 
*/

typedef struct node  //一个节点占用12字节，data_size = 0的时候将数据域指针用来存储数据
{  
    //循环双链表的结点结构   
    void* data;//数据域指针   
    struct node *next;//指向当前结点的下一结点   
    unsigned int data_size;//结点数据所占内存空间的大小,因结构体内存特性，故设置为四个字节
}Node;  

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++链表
typedef struct List {
	struct node *head;                           //头指针，指向头结点   
    int length;                                  //链表list的长度                                                              
    unsigned int memory_size;                    //该链表占用内存空间的大小，单位-字节
    unsigned int memory_limit;                   //限制该链表占用多少内存空间，单位-字节
    
    int (*delete)(struct List* list);                                                              //删除整条链表并释放内存空间
    void* (*get)(struct List* list, unsigned int index);                                                //获取索引处的元素
    unsigned int (*getSize)(struct List* list, unsigned int index);                                     //获取索引处的元素的大小
    int (*add)(struct List* list, void* data, unsigned int data_size);                                  //往链表尾部添加数据
    int (*addAt)(struct List* list, unsigned int index, void* data, unsigned int data_size);            //往链表指定位置添加数据
    int (*set)(struct List* list, unsigned int index, void* data, unsigned int data_size);              //更新链表指定位置的值
    int (*remove)(struct List* list);                                                                   //删除链表尾部的数据
    int (*removeAt)(struct List* list, unsigned int index);                                             //删除链表指定位置的数据
    int (*index)(struct List* list, void* data, unsigned int data_size);                                //取得指定元素索引
    int (*indexFrom)(struct List* list, unsigned int index, void* data, unsigned int data_size);        //从index处开始取得元素索引
    unsigned int (*max)(struct List* list, int(*compare)(void* first, void* second, unsigned int data_size));                         //获取最大元素的索引，需自己实现比较函数
    unsigned int (*maxOf)(struct List* list, unsigned int index, int(*compare)(void* first, void* second, unsigned int data_size));   //获取第index大元素的索引，需自己实现比较函数
    unsigned int (*min)(struct List* list, int(*compare)(void* first, void* second, unsigned int data_size));                         //获取最小元素的索引，需自己实现比较函数
    unsigned int (*minOf)(struct List* list, unsigned int index, int(*compare)(void* first, void* second, unsigned int data_size));   //获取第index小元素的索引，需自己实现比较函数
}List;
List new_List(unsigned int memory_limit);                                                      //双向链表初始化

void* get_List(List* list, unsigned int index);                                                //获取索引处的元素
unsigned int getSize_List(List* list, unsigned int index);                                     //获取索引处的元素的大小

int delete_List(List* list);                                                                   //删除整条链表并释放内存空间
int add_List(List* list, void* data, unsigned int data_size);                                  //往链表尾部添加数据
int addAt_List(List* list, unsigned int index, void* data, unsigned int data_size);            //往链表指定位置添加数据
int set_List(List* list, unsigned int index, void* data, unsigned int data_size);              //更新链表指定位置的值
int remove_List(List* list);                                                                   //删除链表尾部的数据
int removeAt_List(List* list, unsigned int index);                                             //删除链表指定位置的数据
int index_List(List* list, void* data, unsigned int data_size);                                //取得指定元素索引
int indexFrom_List(List* list, unsigned int index, void* data, unsigned int data_size);        //从index处开始取得元素索引

unsigned int max_List(List* list, int(*compare)(void* first, void* second, unsigned int data_size));                         //获取最大元素的索引，需自己实现比较函数
unsigned int maxOf_List(List* list, unsigned int index, int(*compare)(void* first, void* second, unsigned int data_size));   //获取第index大元素的索引，需自己实现比较函数
unsigned int min_List(List* list, int(*compare)(void* first, void* second, unsigned int data_size));                         //获取最小元素的索引，需自己实现比较函数
unsigned int minOf_List(List* list, unsigned int index, int(*compare)(void* first, void* second, unsigned int data_size));   //获取第index小元素的索引，需自己实现比较函数


typedef struct Tiny_List {
    struct node* head;                           //头指针，指向头结点   
    int length;                                  //链表list的长度                                                              
    unsigned int memory_size;                    //该链表占用内存空间的大小，单位-字节
    unsigned int memory_limit;                   //限制该链表占用多少内存空间，单位-字节

    int (*delete)(struct Tiny_List* list);                                                                   //删除整条链表并释放内存空间
    void* (*get)(struct Tiny_List* list, unsigned int index);                                                //获取索引处的元素
    unsigned int (*getSize)(struct Tiny_List* list, unsigned int index);                                     //获取索引处的元素的大小
    int (*add)(struct Tiny_List* list, void* data );                                  //往链表尾部添加数据
    int (*addAt)(struct Tiny_List* list, unsigned int index, void* data );            //往链表指定位置添加数据
    int (*set)(struct Tiny_List* list, unsigned int index, void* data );              //更新链表指定位置的值
    int (*remove)(struct Tiny_List* list);                                                                   //删除链表尾部的数据
    int (*removeAt)(struct Tiny_List* list, unsigned int index);                                             //删除链表指定位置的数据
    int (*index)(struct Tiny_List* list, void* data );                                //取得指定元素索引
    int (*indexFrom)(struct Tiny_List* list, unsigned int index, void* data );        //从index处开始取得元素索引
    unsigned int (*max)(struct Tiny_List* list, int(*compare)(void* first, void* second ));                         //获取最大元素的索引，需自己实现比较函数
    unsigned int (*maxOf)(struct Tiny_List* list, unsigned int index, int(*compare)(void* first, void* second ));   //获取第index大元素的索引，需自己实现比较函数
    unsigned int (*min)(struct Tiny_List* list, int(*compare)(void* first, void* second ));                         //获取最小元素的索引，需自己实现比较函数
    unsigned int (*minOf)(struct Tiny_List* list, unsigned int index, int(*compare)(void* first, void* second ));   //获取第index小元素的索引，需自己实现比较函数

    unsigned int data_size;
}Tiny_List;

Tiny_List new_TinyList(unsigned int memory_limit, unsigned int data_size);                              //双向链表初始化

void* get_TinyList(Tiny_List* list, unsigned int index);                                                //获取索引处的元素
unsigned int getSize_TinyList(Tiny_List* list, unsigned int index);                                     //获取索引处的元素的大小

int delete_TinyList(Tiny_List* list);                                                                   //删除整条链表并释放内存空间
int add_TinyList(Tiny_List* list, void* data );                                  //往链表尾部添加数据
int addAt_TinyList(Tiny_List* list, unsigned int index, void* data );            //往链表指定位置添加数据
int set_TinyList(Tiny_List* list, unsigned int index, void* data );              //更新链表指定位置的值
int remove_TinyList(Tiny_List* list);                                                                   //删除链表尾部的数据
int removeAt_TinyList(Tiny_List* list, unsigned int index);                                             //删除链表指定位置的数据
int index_TinyList(Tiny_List* list, void* data );                                //取得指定元素索引
int indexFrom_TinyList(Tiny_List* list, unsigned int index, void* data );        //从index处开始取得元素索引

unsigned int max_TinyList(Tiny_List* list, int(*compare)(void* first, void* second ));                         //获取最大元素的索引，需自己实现比较函数
unsigned int maxOf_TinyList(Tiny_List* list, unsigned int index, int(*compare)(void* first, void* second ));   //获取第index大元素的索引，需自己实现比较函数
unsigned int min_TinyList(Tiny_List* list, int(*compare)(void* first, void* second ));                         //获取最小元素的索引，需自己实现比较函数
unsigned int minOf_TinyList(Tiny_List* list, unsigned int index, int(*compare)(void* first, void* second ));   //获取第index小元素的索引，需自己实现比较函数

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++队列
typedef struct Queue
{
    struct node* head;                  //头指针，指向头结点   
    int length;                         //队列的长度                                                              
    unsigned int memory_size;           //该队列占用内存空间的大小，单位-字节
    unsigned int memory_limit;          //限制该队列占用多少内存空间，单位-字节

    int (*push)(struct Queue* queue, void* data, unsigned int data_size);    //往队列中添加数据
    int (*pop)(struct Queue* queue);                                       //从队列中弹出数据
    void* (*get)(struct Queue* queue);                                       //查看队列中元素的值
    unsigned int (*getSize)(struct Queue* queue);                            //查看队列中元素所占内存空间的大小
    int (*delete)(struct Queue* queue);                                      //删除队列 
} Queue;

Queue new_Queue(unsigned int memory_limit);     //队列初始化
int pop_Queue(Queue* queue);                  //从队列中弹出数据
void* get_Queue(Queue* queue);                  //查看队列中元素的值
unsigned int getSize_Queue(Queue* queue);       //查看队列中元素所占内存空间的大小
int delete_Queue(Queue* queue);                 //删除整个队列并释放内存空间


typedef struct Tiny_Queue
{
    struct node* head;                  //头指针，指向头结点   
    int length;                         //队列的长度                                                              
    unsigned int memory_size;           //该队列占用内存空间的大小，单位-字节
    unsigned int memory_limit;          //限制该队列占用多少内存空间，单位-字节

    int (*push)(struct Tiny_Queue* queue, void* data);    //往队列中添加数据
    int (*pop)(struct Tiny_Queue* queue);                                       //从队列中弹出数据
    void* (*get)(struct Tiny_Queue* queue);                                       //查看队列中元素的值
    unsigned int (*getSize)(struct Tiny_Queue* queue);                            //查看队列中元素所占内存空间的大小
    int (*delete)(struct Tiny_Queue* queue);                                      //删除队列 
    unsigned int data_size;
} Tiny_Queue;

Tiny_Queue new_TinyQueue(unsigned int memory_limit, unsigned int data_size);     //队列初始化
int add_Tiny_Queue(Tiny_Queue* queue, void *data);
int pop_Tiny_Queue(Tiny_Queue* queue);                  //从队列中弹出数据
void* get_Tiny_Queue(Tiny_Queue* queue);                  //查看队列中元素的值
unsigned int getSize_Tiny_Queue(Tiny_Queue* queue);       //查看队列中元素所占内存空间的大小
int delete_Tiny_Queue(Tiny_Queue* queue);                 //删除整个队列并释放内存空间
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++栈
typedef struct Stack
{
    struct node* head;                           //头指针，指向头结点   
    int length;                                  //栈的长度                                                              
    unsigned int memory_size;                    //该栈占用内存空间的大小，单位-字节
    unsigned int memory_limit;                   //限制该栈占用多少内存空间，单位-字节

    int (*push)(struct Stack* stack, void* data, unsigned int data_size);   //往栈中添加数据
    int (*pop)(struct Stack* stack);                                      //从栈中弹出数据
    void* (*get)(struct Stack* stack);                                      //获得栈中元素的值
    unsigned int (*getSize)(struct Stack* stack);                           //获得栈中元素所占内存空间的大小
    int (*delete)(struct Stack* stack);                                     //删除栈
} Stack;

Stack new_Stack(unsigned int memory_limit);      //栈初始化
int pop_Stack(Stack* stack);                   //从栈中弹出数据
void* get_Stack(Stack* stack);                   //获得栈中元素的值
unsigned int getSize_Stack(Stack* stack);        //获得栈中元素所占内存空间的大小
int delete_Stack(Stack* stack);                      

typedef struct Tiny_Stack
{
    struct node* head;                           //头指针，指向头结点   
    int length;                                  //栈的长度                                                              
    unsigned int memory_size;                    //该栈占用内存空间的大小，单位-字节
    unsigned int memory_limit;                   //限制该栈占用多少内存空间，单位-字节

    int (*push)(struct Tiny_Stack* stack, void* data);   //往栈中添加数据
    int (*pop)(struct Tiny_Stack* stack);                                      //从栈中弹出数据
    void* (*get)(struct Tiny_Stack* stack);                                      //获得栈中元素的值
    unsigned int (*getSize)(struct Tiny_Stack* stack);                           //获得栈中元素所占内存空间的大小
    int (*delete)(struct Tiny_Stack* stack);                                     //删除栈

    unsigned int data_size;
} Tiny_Stack;

Tiny_Stack new_Tiny_Stack(unsigned int memory_limit, unsigned int data_size);      //栈初始化
int add_Tiny_Stack(Tiny_Stack* stack, void* data, unsigned int data_size);       //添加元素
int   pop_Tiny_Stack(Tiny_Stack* stack);                   //从栈中弹出数据
void* get_Tiny_Stack(Tiny_Stack* stack);                   //获得栈中元素的值
unsigned int getSize_Tiny_Stack(Tiny_Stack* stack);        //获得栈中元素所占内存空间的大小
int delete_Tiny_Stack(Tiny_Stack* stack);       

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++Map集合
typedef struct Map
{
    List key_head;                               //键头指针，指向头结点   
    List data_head;                              //值头指针，指向头结点   
    int length;                                  //Map集合的长度                                                              
    unsigned int memory_size;                    //该Map集合占用内存空间的大小，单位-字节
    unsigned int memory_limit;                   //限制该Map集合占用多少内存空间，单位-字节

    int (*push)(struct Map* map, void* key, unsigned int key_size, void* data, unsigned int data_size);      //往Map集合中添加数据
    int (*remove)(struct Map* map, void* key, unsigned int key_size);                                        //删除key对应的键值对
    void* (*get)(struct Map* map, void* key, unsigned int key_size);                                         //获得Map键值对应的数据元素指针
    void* (*getKey)(struct Map* map, void* data, unsigned int data_size);                                      //获得Map数据值对应的键值指针
    unsigned int (*getSize)(struct Map* map, void* key, unsigned int key_size);                              //获得Map键值对应的元素所占的内存大小
    unsigned int (*getKeySize)(struct Map* map, void* key, unsigned int key_size);                           //获得Map键对应的元素所占的内存大小
    List* (*values)(struct Map* map);                                                                        //返回map的值集合，返回类型是一个链表集合
    List* (*keySet)(struct Map* map);                                                                        //返回map的键值集合，返回类型是一个链表集合
    int (*delete)(struct Map* map);                                                                          //删除map集合 
} Map;

Map new_Map(unsigned int memory_limit);                                                      //栈初始化

int push_Map(Map* map, void* key, unsigned int key_size, void* data, unsigned int data_size);      //往Map集合中添加数据
int remove_Map(Map* map, void* key, unsigned int key_size);                                        //删除key对应的键值对
void* get_Map(Map* map, void* key, unsigned int key_size);                                         //获得Map键值对应的数据元素指针
void* getKey_Map(Map* map, void* data, unsigned int data_size);                                      //获得Map数据值对应的键值指针
unsigned int getSize_Map(Map* map, void* key, unsigned int key_size);                              //获得Map键值对应的元素所占的内存大小
unsigned int getKeySize_Map(Map* map, void* key, unsigned int key_size);                           //获得Map键对应的元素所占的内存大小
List* values_Map(Map* map);                                                                        //返回map的值集合，返回类型是一个链表集合
List* keySet_Map(Map* map);                                                                        //返回map的键值集合，返回类型是一个链表集合
int delete_Map(Map* map);                                                                          //删除map集合


typedef struct Tiny_Map
{
    List key_head;                               //键头指针，指向头结点   
    List data_head;                              //值头指针，指向头结点   
    int length;                                  //Map集合的长度                                                              
    unsigned int memory_size;                    //该Map集合占用内存空间的大小，单位-字节
    unsigned int memory_limit;                   //限制该Map集合占用多少内存空间，单位-字节

    int (*push)(struct Tiny_Map* map, void* key,void* data);      //往Map集合中添加数据
    int (*remove)(struct Tiny_Map* map, void* key);                                        //删除key对应的键值对
    void* (*get)(struct Tiny_Map* map, void* key);                                         //获得Map键值对应的数据元素指针
    void* (*getKey)(struct Tiny_Map* map, void* data);                                      //获得Map数据值对应的键值指针
    unsigned int (*getSize)(struct Tiny_Map* map, void* key);                              //获得Map键值对应的元素所占的内存大小
    unsigned int (*getKeySize)(struct Tiny_Map* map, void* key);                           //获得Map键对应的元素所占的内存大小
    List* (*values)(struct Tiny_Map* map);                                                                        //返回map的值集合，返回类型是一个链表集合
    List* (*keySet)(struct Tiny_Map* map);                                                                        //返回map的键值集合，返回类型是一个链表集合
    int (*delete)(struct Tiny_Map* map);                                                                          //删除map集合 

    unsigned int key_size;
    unsigned int data_size;
} Tiny_Map;

Tiny_Map new_Tiny_Map(unsigned int memory_limit, unsigned int key_size, unsigned int data_size);          //栈初始化

int push_Tiny_Map(Tiny_Map* map, void* key, void* data);      //往Map集合中添加数据
int remove_Tiny_Map(Tiny_Map* map, void* key);                                        //删除key对应的键值对
void* get_Tiny_Map(Tiny_Map* map, void* key);                                         //获得Map键值对应的数据元素指针
void* getKey_Tiny_Map(Tiny_Map* map, void* data);                                      //获得Map数据值对应的键值指针
unsigned int getSize_Tiny_Map(Tiny_Map* map, void* key);                              //获得Map键值对应的元素所占的内存大小
unsigned int getKeySize_Tiny_Map(Tiny_Map* map, void* key);                           //获得Map键对应的元素所占的内存大小
List* values_Tiny_Map(Tiny_Map* map);                                                                        //返回map的值集合，返回类型是一个链表集合
List* keySet_Tiny_Map(Tiny_Map* map);                                                                        //返回map的键值集合，返回类型是一个链表集合
int delete_Tiny_Map(Tiny_Map* map);                                                                          //删除map集合


#endif 