# TinySTL
  这是一个用于嵌入式平台的c语言数据结构库的简单实现
  该库采用了类似高级语言oop的程序设计思想，为方便在嵌入式设备上使用，对常用的数据结构进行了简单的实现.可在嵌入式平台上实现消息队列等常见的应用。方法的命名基本采用了java的格式。可在.exe文件中进行测试，也可使用make工具重新编译代码，所有数据结构基本采用的链表的形式。

  1. 单向链表-List
  2. 队列-Queue
  3. 栈-Stack
  4. Map集合
  ***
  Tiny_系列：
  * 单向链表--Tiny_List
  * 队列-----Tiny_Queue
  * 栈-------Tiny_Stack
  * Map集合--Tiny_Map
  
  Tiny_ 系列继承自List,Stack等父类，该类的结构体的前面一些数据保存方式与父类完全相同，在内存中，继承自父类的Tiny系列在前面的内存上与父类一致，因此可以用一个父类型指针指向子类型内存，当做父类型使用Tiny_ 系列增加了一个data_size的属性，在初始化时指定每个节点对象的内存空间,不用每次添加数据时指定需要占用的内存空间大小使用上比他的父类方便了许多，但没有父类那么灵活。相当于在初始化时指定了数据类型，有种泛型的味道。

## **Warning!!!!!!!!!!!!!!!!!!!!!**
* 当data_size为0时，得到的数据是数据域的指针，但此时没有开辟额外的空间，而是用此指针来保存数据，因此可以直接使用它
* 由于指针占用四个字节，可以保存任意类型的数据四个字节，只要注意保存和取出的时候采用相同的格式就可以
* 比如，put(float),取出时把数据放到一个float型变量里就可以了
* 当data_size不为0时，得到的只是指向数据域的一个指针，该指针指向一块大小为data_size的堆数据空间，使用时要遵循指针使用的相关规则

## How to use:
新建数据结构对象有两种方式，一中是在栈中分配内存，第二种是
在堆中分配内存

* 当data_size=0时，使用每个节点的指向数据域的指针存放数据（四个字节），不开辟新的内存,并且传入的数据直接保存在节点里

* 当data_size！=0时，开辟相应的内存空间用来存放数据
每个节点占用12个字节的内存，每个数据结构对象占用几十个字节的数据
传入的数据为一个指针，指向想要保存的数据的内存，然后把data_size个字节
的数据复制到数据节点新开辟的内存中

  **在stm32上使用时，编译器要求较严格时，数据data必须为(void*)类型**
1. **栈分配内存（Demo）：**
```c
List list = new_List(1024);     //内存限制为1k
list.addAt(&list, index, data, data_size);
list.removeAt(&list, index);
list.get(&list, index);
list.set(&list, index, data, data_size);
```
1. **堆分配内存**
```c
Map* map_ptr = (Map*)malloc(sizeof(Map));
(*map_ptr) = new_Map(1024);
map_ptr->push(map_ptr, 1, 0, "hello", 10);
(*map_ptr).push(map_ptr, 0, 0, "world", 10);
```
### 为什么采用单链表？
如果采用双链表的话，在链表很长的时候查找可以快很多，但内存占用较大
综合考虑下在嵌入式平台上选择实现占用内存相对较小的单链表

### 方法概览：

```c
//***********************************************List概览
 //属性：
 length--------链表长度
 memory_size---该链表占用内存空间的大小，单位-字节
 memory_limit--限制该链表占用多少内存空间，单位-字节
 
 //方法集合：                                           data_size = 0的时候将数据域指针用来存储数据
 List new_List(unsigned int memory_limit);                                                 //双向链表初始化
 void* get(List *list, unsigned int index);                                                //获取索引处的元素
 unsigned int getSize(List *list, unsigned int index);                                     //获取索引处的元素的大小
 
 int add(List *list, void* data, unsigned int data_size);                                  //往链表尾部添加数据
 int addAt(List *list, unsigned int index, void* data，unsigned int data_size);            //往链表指定位置添加数据
 int set(List *list, unsigned int index, void* data，unsigned int data_size);              //更新链表指定位置的值
 int remove(List *list);                                                                   //删除链表尾部的数据
 int removeAt(List *list, unsigned int index);                                             //删除链表指定位置的数据
 int index(List *list, void* data, unsigned int data_size);                                //取得指定元素索引
 int indexFrom(List *list, unsigned int index, void* data, unsigned int data_size);        //从index处开始取得元素索引
 int delete_List(List* list);                                                              //删除整条链表并释放内存空间
 
 unsigned int max(List *list，int (*compare)(void* first, void* second, unsigned int data_size));                         //获取最大元素的索引
 unsigned int maxOf(List *list, unsigned int index，int (*compare)(void* first, void* second, unsigned int data_size));   //获取第index大元素的
 unsigned int min(List *list，int (*compare)(void* first, void* second, unsigned int data_size));                         //获取最小元素的索引
 unsigned int minOf(List *list, unsigned int index，int (*compare)(void* first, void* second, unsigned int data_size));   //获取第index小元素的

//********************************************Queue概览
 属性：
 length--------队列长度
 memory_size---该链表占用内存空间的大小，单位-字节
 memory_limit--限制该链表占用多少内存空间，单位-字节

 //方法集合：                                           data_size = 0的时候将数据域指针用来存储数据（四个字节）
 Queue new_Queue(unsigned int memory_limit);                                                             //队列初始化
 int push(Queue *queue, void* data, unsigned int data_size);                                             //往队列中添加数据
 int pop(Queue *queue);                                                                                  //从队列中弹出数据
 void* get(Queue *queue);                                                                                //获得队列中元素的值
 unsigned int getSize(Queue *queue);                                                                     //获得队列中元素所占内存空间的大小
 int delete(Queue *queue);                                                                               //删除队列

//***********************************************Stack概览
 //属性：
 length--------栈长度
 memory_size---该链表占用内存空间的大小，单位-字节
 memory_limit--限制该链表占用多少内存空间，单位-字节

 //方法集合：               data_size = 0的时候将数据域指针用来存储数据（四个字节），不为0时自动开辟data_size字节大小的空间用来存放数据
 Stack new_Stack(unsigned int memory_limit);                                                             //栈初始化
 int push(Stack *stack, void* data, unsigned int data_size);                                             //往栈中添加数据
 int pop(Stack *stack);                                                                                  //从栈中弹出数据
 void* get(Stack *stack);                                                                                //获得栈中元素的值
 unsigned int getSize(Stack *stack);                                                                     //获得栈中元素所占内存空间的大小
 int delete(Stack *stack);                                                                               //删除栈

//***********************************************Map概览
 //属性：
 key_head-------键链表
 data_head------数值链表
 length--------Map集合长度
 memory_size---该Map集合占用内存空间的大小，单位-字节
 memory_limit--限制该Map集合占用多少内存空间，单位-字节

 //方法集合：               data_size和key_size = 0的时候将数据域指针用来存储数据（四个字节），不为0时自动开辟data_size字节大小的空间用来存放数据
 Stack new_Map(unsigned int memory_limit);                                                 //栈初始化
 
 int push(Map* map, void* key, unsigned int key_size, void* data, unsigned int data_size);      //往Map集合中添加数据
 int remove(Map* map, void* key, unsigned int key_size);                                        //删除key对应的键值对
 void* get(Map* map, void* key, unsigned int key_size);                                         //获得Map键值对应的数据元素指针
 void* getKey(Map* map, void* key, unsigned int key_size);                                      //获得Map数据值对应的键值指针
 unsigned int getSize(Map* map, void* key, unsigned int key_size);                              //获得Map键值对应的元素所占的内存大小
 unsigned int getKeySize(Map* map, void* key, unsigned int key_size);                           //获得Map键对应的元素所占的内存大小
 List* values(Map* map);                                                                        //返回map的值集合，返回类型是一个链表集合
 List* keySet(Map* map);                                                                        //返回map的键值集合，返回类型是一个链表集合
 int delete(Map* map);                                                                          //删除map集合