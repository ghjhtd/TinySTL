/*
 * @Author: gong hao jing
 * @Date: 2021-08-22 01:10:08
 * @LastEditTime: 2021-08-25 02:58:31
 * @LastEditors: Please set LastEditors
 * @Description: 这是一个c语言数据结构库的简单实现
 * @FilePath: \TinySTL\TinySTL.c
 */

#include "TinySTL.h" 

/**
 * @brief 错误打印函数
 * 
 * @param chars 错误消息
 */
void print_error(char *chars){
    printf("******************************\r\n");
    printf(chars);
    printf("******************************\r\n");
}


/**
 * @brief 分配内存空间
 * 
 * @return void* 
 * @return void* 
 */
void* new(unsigned int data_size){
    return malloc(data_size);
}


/**
 * @brief 初始化List
 * 
 * @param memory_limit 链表内存限制，byte
 * @return List 
 */
List new_List(unsigned int memory_limit){
	List list;
    list.memory_size = 0;
    list.memory_limit = memory_limit;
    list.memory_size += sizeof(list);
    list.head = 0;
    list.length = 0;

    list.add = add_List;
    list.addAt = addAt_List;
    list.remove = remove_List;
    list.removeAt = removeAt_List;
    list.get = get_List;
    list.getSize = getSize_List;
    list.index = index_List;
    list.indexFrom = indexFrom_List;
    list.max = max_List;
    list.maxOf = maxOf_List;
    list.set = set_List;
    list.delete = delete_List;
    return list;
}

/**
 * @brief 往链表中新增一个元素
 * 
 * @param list 链表头结点
 * @param data 元素数据指针
 * @param data_size 元素所占内存空间的大小
 * @return int -1--失败 1--成功 0--内存超限
 */
int add_List(List* list, void* data, unsigned int data_size){
    Node *new_node = 0;
    Node *last_node = 0;
    void *new_data = 0;
    if(list == 0){
        print_error("该头结点是个空指针！！\r\n");
        return -1;
    }
    if((list->memory_size + sizeof(Node) + data_size) > list->memory_limit){
        print_error("内存超限！\r\n");
        return 0;
    }
    new_node = (Node*)malloc(sizeof(Node));
    if(new_node == 0){
        print_error("分配节点内存失败\r\n");
        return -1;
    }
    new_node->data_size = data_size;
    if (data_size != 0) {
        new_data = malloc(data_size);
        new_data = memcpy(new_data, data, data_size);
        if (new_data == 0) {
            print_error("分配节点数据内存失败\r\n");
            return -1;
        }
    }
    else
    {
        new_data = data;
    }
    new_node->data = new_data;
    new_node->next = 0;
    if(list->head == 0){
        list->head = new_node;
        list->length++;
        list->memory_size += (sizeof(Node) + data_size);
        return 1;
    }
    else{
        last_node = list->head;
        while (last_node->next != 0)
        {
            last_node = last_node->next;
        }
        last_node->next = new_node;
        list->length++;
        list->memory_size += (sizeof(Node) + data_size);
        return 1;
    }
}

/**
 * @brief 往链表指定位置添加数据
 * 
 * @param list 链表头结点
 * @param index 位置，0-...
 * @param data 
 * @param data_size 
 * @return int -1--失败 1--成功 0--内存超限
 */
int addAt_List(List* list, unsigned int index, void* data, unsigned int data_size){
    Node *new_node;
    Node *last_node;
    void *new_data;
    int i = 0;
    if(list == 0){
        print_error("该头结点是个空指针！！\r\n");
        return -1;
    }
    if((list->memory_size + sizeof(Node) + data_size) > list->memory_limit){
        print_error("内存超限！\r\n");
        return 0;
    }
    if(index > list->length || index < 0){
        print_error("插入位置出错!\r\n");
        return -1;
    }
    new_node = (Node*)malloc(sizeof(Node));
    if(new_node == 0){
        print_error("分配节点内存失败\r\n");
        return -1;
    }
    new_node->data_size = data_size;
    if (data_size != 0) {
        new_data = malloc(data_size);
        new_data = memcpy(new_data, data, data_size);
        if (new_data == 0) {
            print_error("分配节点数据内存失败\r\n");
            return -1;
        }
    }
    else
    {
        new_data = data;
    }
    new_node->data = new_data;
    new_node->next = 0;

    if(list->head == 0){
        list->head = new_node;
        list->length++;
        list->memory_size += (sizeof(Node) + data_size);
        return 1;
    }
    else{
        last_node = list->head;
        for(i = 1; i < index; i++){
            last_node = last_node->next;
        }
        last_node->next = new_node;
        list->length++;
        list->memory_size += (sizeof(Node) + data_size);
        return 1;
    }
}

/**
 * @brief 找到第index个节点
 * 
 * @param list 
 * @param index 
 * @return Node* 
 */
Node* get_Node(List* list, unsigned int index){
    Node* last_node;
    int i;
    if(index >= list->length || index < 0){
        print_error("没有这个节点!\r\n");
        return 0;
    }
    last_node = list->head;
    for(i = 0; i < index; i++){
        last_node = last_node->next;
    }
    return last_node;
}

/**
 * @brief 删除链表指定位置的数据
 * 
 * @param list 
 * @param index 
 * @return int 
 */
int removeAt_List(List* list, unsigned int index){
    Node* final_node = 0;
    Node* pre_node = 0;
    Node* last_node = 0;
    unsigned int data_size = 0;
    if(list == 0){
        print_error("该头结点是个空指针！！\r\n");
        return -1;
    }
    if(list->length == 0){
        print_error("链表已为空\r\n");
        return 0;
    }
    if (index >= list->length) {
        print_error("访问的位置不存在\r\n");
        return -1;
    }
    if(index == list->length-1){
        pre_node = get_Node(list, index - 1);
    }
    else{
        if(index != 0){
            pre_node = get_Node(list, index - 1);
            last_node = get_Node(list, index + 1);
        }
        else{
            last_node = get_Node(list, index + 1);
        }        
    }
    final_node = get_Node(list,index);
    data_size = final_node->data_size;
    if (data_size != 0) {
        free(final_node->data);
    }
    free(final_node);
    if(index == list->length-1 && pre_node != 0){
        pre_node->next = 0;
    }
    else{
        if (index == 0) {
            list->head = last_node;
        }
        else {
            pre_node->next = last_node;
        }
    }
    list->length--;
    list->memory_size -= (sizeof(Node) + data_size);
    return 1;
}


/**
 * @brief 除链表尾部的数据
 * 
 * @param list 链表指针
 * @return int -1--失败 1--成功 0--链表为空
 */
int remove_List(List* list){
    return removeAt_List(list,list->length-1);
}

/**
 * @brief Get the List object
 * 
 * @param list 
 * @param index 
 * @return void* 节点数据元素指针
 */
void* get_List(List* list, unsigned int index){
    Node* node = 0;
    node = get_Node(list, index);
    if (node != 0) {
        return node->data;
    }
    return 0;
}

/**
 * @brief 获取索引处的元素的大小
 * 
 * @param list 
 * @param index 
 * @return unsigned int 
 */
unsigned int getSize_List(List* list, unsigned int index){
    Node* node;
    node = get_Node(list, index);
    if (node == 0)
        return 0;
    return node->data_size;
}

/**
 * @brief Set the List object更新链表指定位置的值
 * 
 * @param list 
 * @param index 
 * @param data 
 * @param data_size 
 * @return int 
 */
int set_List(List* list, unsigned int index, void* data, unsigned int data_size){
    Node* node = 0;
    void* new_data = 0;
    if(list == 0){
        print_error("该头结点是个空指针！！\r\n");
        return -1;
    }
    if(list->length == 0){
        print_error("链表为空\r\n");
        return 0;
    }
    if(index > list->length || index < 0){
        print_error("位置出错!\r\n");
        return -1;
    }
    node = get_Node(list, index);
    new_data = node->data;
    if (data_size != 0) {
        if(node->data_size != 0)
        free(new_data);
        new_data = malloc(data_size);
        new_data = memcpy(new_data, data, data_size);
        if (new_data == 0) {
            print_error("分配节点数据内存失败\r\n");
            return -1;
        }
    }
    else
    {
        new_data = data;
    }
    node->data = new_data;
    node->data_size = data_size;
    return 1;
}


/**
 * @brief 
 * 
 * @param list 
 * @param data 
 * @param data_size 
 * @return int -1--失败  >0--成功
 */
int index_List(List* list, void* data, unsigned int data_size){
    Node* node;
    void* data_new;
    int i = 0;
    int j = 0;
    if(list == 0){
        print_error("该头结点是个空指针！！\r\n");
        return -1;
    }
    if(list->length == 0){
        //print_error("链表为空\r\n");
        return -1;
    }
    node = list->head;
    for(i = 0; i < list->length; i++){
        if(node->data_size == data_size && data_size > 0){
            if(memcmp(node->data, data, data_size) == 0){
                return i;
            }
        }
        if (node->data_size == data_size && data_size == 0) {
            if (node->data == data) {
                return i;
            }
        }
        node = node->next;
    }
    return -1;
}


/**
 * @brief 从index处开始取得元素索引
 * 
 * @param list 
 * @param index 
 * @param data 
 * @param data_size 
 * @return int -1--失败  >0--成功
 */
int indexFrom_List(List* list, unsigned int index, void* data, unsigned int data_size){
    Node* node;
    void* data_new;
    int i = 0;
    int j = 0;
    if(list == 0){
        print_error("该头结点是个空指针！！\r\n");
        return -1;
    }
    if(list->length == 0){
        print_error("链表为空\r\n");
        return 0;
    }
    node = list->head;
    for(i = index; i < list->length; i++){
        if(node->data_size == data_size){
            if(memcmp(node->data, data, data_size) == 0){
                return i;
            }
        }
        node = node->next;
    }
    return -1;
}


/**
 * @brief 获取最大元素的索引，需自己实现比较函数
 * 
 * @param list 
 * @param compare 
 * @return unsigned int 
 */
unsigned int max_List(List* list, int(*compare)(void* first, void* second, unsigned int data_size)){

    return 0;
}


/**
 * @brief 获取第index大元素的索引，需自己实现比较函数
 * 
 * @param list 
 * @param index 
 * @param compare 
 * @return unsigned int 
 */
unsigned int maxOf_List(List* list, unsigned int index, int(*compare)(void* first, void* second, unsigned int data_size)){

    return 0;
}


/**
 * @brief 获取最小元素的索引，需自己实现比较函数
 * 
 * @param list 
 * @param compare 
 * @return unsigned int 
 */
unsigned int min_List(List* list, int(*compare)(void* first, void* second, unsigned int data_size)){

    return 0;
}


/**
 * @brief 获取第index小元素的索引，需自己实现比较函数
 * 
 * @param list 
 * @param index 
 * @param compare 
 * @return unsigned int 
 */
unsigned int minOf_List(List* list, unsigned int index, int(*compare)(void* first, void* second, unsigned int data_size)){

    return 0;
}


/**
 * @brief 删除整条链表并释放内存空间
 * 
 * @param list 
 * @return int 1-删除成功
 */
int delete_List(List* list){
    Node *node = 0;
    Node *temp = 0;
    if(list->head != 0){
        node = list->head;
        while(node->next != 0){
            temp = node;
            node = node->next;
            if(temp->data_size != 0){
                free(temp->data);
            }
            free(temp);
        }
        if(node->next == 0){
            if(node->data_size != 0){
                free(node->data);
            }
            free(node);
        }
        
    }
    list->head = 0;
    list->length = 0;
    list->memory_size = 0;
    list->memory_size += sizeof(*list);
    return 1;
}


/**
 * @brief 队列初始化
 * 
 * @param memory_limit 
 * @return Queue 
 */
Queue new_Queue(unsigned int memory_limit){
    Queue queue;
    queue.memory_size = 0;
    queue.memory_limit = memory_limit;
    queue.memory_size += sizeof(queue);
    queue.head = 0;
    queue.length = 0;

    queue.push = add_List;
    queue.get = get_Queue;
    queue.pop = pop_Queue;
    queue.getSize = getSize_Queue;
    queue.delete = delete_Queue;
    return queue;
}


/**
 * @brief 从队列中弹出数据
 * 
 * @param queue 
 * @return int 1--成功
 */
int pop_Queue(Queue* queue){
    return removeAt_List((List*)queue, 0);
}


/**
 * @brief 查看队列中元素的值
 * 
 * @param queue 
 * @return void* 
 */
void* get_Queue(Queue* queue){
    return get_List((List *)queue, 0);
}


/**
 * @brief 查看队列中元素所占内存空间的大小
 * 
 * @param queue 
 * @return unsigned int 
 */
unsigned int getSize_Queue(Queue* queue){
    return getSize_List((List *)queue, 0);
}


/**
 * @brief 删除整个队列并释放内存空间
 * 
 * @param queue 
 * @return int 
 */
int delete_Queue(Queue* queue){
    int i = 0;
    i = delete_List((List *)queue);
    queue->memory_size = 0;
    queue->memory_size += sizeof(Queue);
    return i;
}


/**
 * @brief 栈初始化
 * 
 * @param memory_limit 
 * @return Queue 
 */
Stack new_Stack(unsigned int memory_limit){
    Stack stack;
    stack.memory_size = 0;
    stack.memory_limit = memory_limit;
    stack.memory_size += sizeof(Stack);
    stack.head = 0;
    stack.length = 0;

    stack.push = add_List;
    stack.get = get_Stack;
    stack.pop = pop_Stack;
    stack.getSize = getSize_Stack;
    stack.delete = delete_Stack;
    return stack;
}



/**
 * @brief 获得栈中元素的值
 * 
 * @param stack 
 * @return void* 
 */
void* get_Stack(Stack* stack){
    return get_List((List *)stack, stack->length - 1);
}

/**
 * @brief 从栈中弹出数据
 * 
 * @param stack 
 * @return void* 
 */
int pop_Stack(Stack* stack){
    return removeAt_List((List*)stack, stack->length - 1);
}


/**
 * @brief Get the Size Stack object获得栈中元素所占内存空间的大小
 * 
 * @param stack 
 * @return unsigned int 
 */
unsigned int getSize_Stack(Stack* stack){
    return getSize_List((List *)stack, stack->length - 1);
}


/**
 * @brief 删除栈
 * 
 * @param stack 
 * @return int 
 */
int delete_Stack(Stack* stack){
    int i = 0;
    i = delete_List((List *)stack);
    stack->memory_size = 0;
    stack->memory_size += sizeof(Stack);
    return i;
}


/**
 * @brief 栈初始化
 * 
 * @param memory_limit 内存大小限制
 * @return Map 
 */
Map new_Map(unsigned int memory_limit){
    Map map;
    List key_list = new_List(0xffffffff);
    List value_list = new_List(0xffffffff);
    map.memory_size = 0;
    map.memory_limit = memory_limit;
    map.memory_size += sizeof(Map);
    map.key_head = key_list;
    map.data_head = value_list;
    map.length = 0;
    
    map.push = push_Map;
    map.get = get_Map;
    map.getKey = getKey_Map;
    map.getKeySize = getKeySize_Map;
    map.getSize = getSize_Map;
    map.remove = remove_Map;
    map.delete = delete_Map;
    map.values = values_Map;
    map.keySet = getKey_Map;
    return map;
}

/**
 * @brief 往Map集合中添加数据
 * 
 * @param map 
 * @param key 
 * @param key_size 
 * @param data 
 * @param data_size 
 * @return int -1----失败   1----成功  0 ------内存不够或该键已存在
 */
int push_Map(Map* map, void* key, unsigned int key_size, void* data, unsigned int data_size){
    int key_state = 0;
    int value_state = 0;
    if(map->memory_size + (key_size + data_size + 2 * sizeof(Node)) <= map->memory_limit && map->key_head.index(&map->key_head, key, key_size) == -1){
        key_state = map->key_head.add(&map->key_head, key, key_size);
        value_state = map->data_head.add(&map->data_head, data, data_size);
        if (key_state == 1 && value_state == 1) {
            map->length = map->key_head.length;
            map->memory_size = (map->key_head.memory_size + map->data_head.memory_size + sizeof(Map) - 2*sizeof(List));
        }
        else {
            if (key_state == 1) {
                map->key_head.remove(&map->key_head);
            }
            if (value_state == 1) {
                map->data_head.remove(&map->data_head);
            }
            return -1;
        }
        return 1;
    }
    else{
        print_error("Map集合加入失败，内存不够或该键已存在\r\n");
        return 0;
    }
}


/**
 * @brief 删除key对应的键值对
 * 
 * @param map 
 * @param key 
 * @param key_size 
 * @return int -1----失败  0-----未查询到  1----成功
 */
int remove_Map(Map* map, void* key, unsigned int key_size){
    int index = -1;
    index = map->key_head.index(&map->key_head, key, key_size);
    if(index != -1){
        if(!(map->key_head.removeAt(&map->key_head, index) && map->data_head.removeAt(&map->data_head, index))){
            print_error("删除键值对时出错\r\n");
            return -1;
        }
        map->length = map->key_head.length;
        map->memory_size = (map->key_head.memory_size + map->data_head.memory_size + sizeof(Map) - 2*sizeof(List));
        return 1;
    }
    return 0;
}

/**
 * @brief 获得Map键值对应的数据元素指针
 * 
 * @param map 
 * @param key 
 * @param key_size 
 * @return void* 
 */
void* get_Map(Map* map, void* key, unsigned int key_size){
    int index = -1;
    index = map->key_head.index(&map->key_head, key, key_size);
    if (index != -1) {
        return map->data_head.get(&map->data_head, index);
    }
    return 0;
}


/**
 * @brief 获得Map数据值对应的键值指针
 * 
 * @param map 
 * @param key 
 * @param key_size 
 * @return void* 
 */
void* getKey_Map(Map* map, void* data, unsigned int data_size){
    int index = -1;
    index = map->data_head.index(&map->data_head, data, data_size);
    if (index != -1) {
        return map->key_head.get(&map->key_head, index);
    }
    return 0;
}


/**
 * @brief 获得Map键值对应的元素所占的内存大小
 * 
 * @param map 
 * @param key 
 * @param key_size 
 * @return unsigned int -1----未找到哦
 */
unsigned int getSize_Map(Map* map, void* key, unsigned int key_size){
    int index = -1;
    index = map->key_head.index(&map->key_head, key, key_size);
    if (index != -1) {
        return map->data_head.getSize(&map->data_head, index);
    }
    return 0;
}


/**
 * @brief 获得Map键对应的元素所占的内存大小
 * 
 * @param map 
 * @param key 
 * @param key_size 
 * @return unsigned int -1----未找到哦
 */
unsigned int getKeySize_Map(Map* map, void* key, unsigned int key_size){
    int index = -1;
    index = map->data_head.index(&map->data_head, key, key_size);
    if (index != -1) {
        return map->key_head.getSize(&map->key_head, index);
    }
    return 0;
}


/**
 * @brief 返回map的值集合，返回类型是一个链表集合
 * 
 * @param map 
 * @return List* 
 */
List* values_Map(Map* map){
    return &map->data_head;
}


/**
 * @brief 返回map的键值集合，返回类型是一个链表集合
 * 
 * @param map 
 * @return List* 
 */
List* keySet_Map(Map* map){
    return &map->key_head;
}


/**
 * @brief 删除map集合
 * 
 * @param map 
 * @return int 
 */
int delete_Map(Map* map){
    int i = 0;
    i = (map->key_head.delete(&map->key_head) && map->data_head.delete(&map->data_head));
    map->length = map->key_head.length;
    map->memory_size = sizeof(Map);
    return i;
}


/**
 * @brief 
 * 
 * @param memory_limit 
 * @param data_size 
 * @return List 
 */
Tiny_List new_TinyList(unsigned int memory_limit, unsigned int data_size)                              //双向链表初始化
{
    Tiny_List list;
    list.memory_size = 0;
    list.memory_limit = memory_limit;
    list.memory_size += sizeof(Tiny_List);
    list.head = 0;
    list.length = 0;

    list.add = add_TinyList;
    list.addAt = addAt_TinyList;
    list.remove = remove_TinyList;
    list.removeAt = removeAt_TinyList;
    list.get = get_TinyList;
    list.getSize = getSize_TinyList;
    list.index = index_TinyList;
    list.indexFrom = indexFrom_TinyList;
    list.max = max_TinyList;
    list.maxOf = maxOf_TinyList;
    list.set = set_TinyList;
    list.delete = delete_TinyList;

    list.data_size = data_size;
    return list;
}


/**
 * @brief Get the Tiny Tiny_List object
 * 
 * @param list 
 * @param index 
 * @return void* 
 */
void* get_TinyList(Tiny_List* list, unsigned int index)                                                //获取索引处的元素
{
    return get_List((List*)list, index);
}


/**
 * @brief Get the Size TinyList object
 * 
 * @param list 
 * @param index 
 * @return unsigned int 
 */
unsigned int getSize_TinyList( Tiny_List* list, unsigned int index)                                    //获取索引处的元素的大小
{
    return getSize_List( (List*) list, index);
}


/**
 * @brief 
 * 
 */
int delete_TinyList( Tiny_List* list)                                                                   //删除整条链表并释放内存空间
{
    return delete_List( (List*) list);                         
}


/**
 * @brief 
 * 
 */
int add_TinyList( Tiny_List* list, void* data )                                  //往链表尾部添加数据
{
    return add_List( (List*) list, data, list->data_size);
}


/**
 * @brief 
 * 
 */
int addAt_TinyList( Tiny_List* list, unsigned int index, void* data )            //往链表指定位置添加数据
{
    return addAt_List( (List*) list, index, data, list->data_size);
}


/**
 * @brief 
 * 
 */
int set_TinyList( Tiny_List* list, unsigned int index, void* data )              //更新链表指定位置的值
{
    return set_List( (List*) list,index,data, list->data_size );
}


/**
 * @brief 
 * 
 */
int remove_TinyList( Tiny_List* list)                                                                   //删除链表尾部的数据
{
    return remove_List( (List*) list);        
}


/**
 * @brief 
 * 
 */
int removeAt_TinyList( Tiny_List* list, unsigned int index)                                            //删除链表指定位置的数据
{
    return removeAt_List( (List*) list, index);                    
}


/**
 * @brief 
 * 
 */
int index_TinyList( Tiny_List* list, void* data )                                //取得指定元素索引
{
    return index_List((List*)list, data, list->data_size);
}


/**
 * @brief 
 * 
 */
int indexFrom_TinyList( Tiny_List* list, unsigned int index, void* data )       //从index处开始取得元素索引
{
    return indexFrom_List((List*)list, index, data, list->data_size);
}


/**
 * @brief 
 * 
 */
unsigned int max_TinyList( Tiny_List* list, int(*compare)(void* first, void* second ))                         //获取最大元素的索引，需自己实现比较函数
{
    
    return 0;
}


/**
 * @brief 
 * 
 */
unsigned int maxOf_TinyList( Tiny_List* list, unsigned int index, int(*compare)(void* first, void* second ))   //获取第index大元素的索引，需自己实现比较函数
{

    return 0;
}


/**
 * @brief 
 * 
 */
unsigned int min_TinyList( Tiny_List* list, int(*compare)(void* first, void* second ))                         //获取最小元素的索引，需自己实现比较函数
{

    return 0;
}


/**
 * @brief 
 * 
 */
unsigned int minOf_TinyList( Tiny_List* list, unsigned int index, int(*compare)(void* first, void* second ))   //获取第index小元素的索引，需自己实现比较函数
{

    return 0;
}


/**
 * @brief 队列初始化
 * 
 * @param memory_limit 
 * @param data_size 
 * @return Tiny_Queue 
 */
Tiny_Queue new_TinyQueue(unsigned int memory_limit, unsigned int data_size){
    Tiny_Queue queue;
    queue.memory_size = 0;
    queue.memory_limit = memory_limit;
    queue.memory_size += sizeof(Tiny_Queue);
    queue.head = 0;
    queue.length = 0;

    queue.push = add_Tiny_Queue;
    queue.get = get_Tiny_Queue;
    queue.pop = pop_Tiny_Queue;
    queue.getSize = getSize_Tiny_Queue;
    queue.delete = delete_Tiny_Queue;
    queue.data_size = data_size;
    return queue;
}


/**
 * @brief 
 * 
 * @param queue 
 * @return void* 
 */
int add_Tiny_Queue(Tiny_Queue* queue, void *data){
    return add_List((List*) queue, data, queue->data_size);
}


/**
 * @brief 从队列中弹出数据
 * 
 * @param queue 
 * @return void* 
 */
int pop_Tiny_Queue(Tiny_Queue* queue){
    return pop_Queue((Queue*) queue);
}


/**
 * @brief Get the Tiny Queue object查看队列中元素的值
 * 
 * @param queue 
 * @return void* 
 */
void* get_Tiny_Queue(Tiny_Queue* queue){
    return get_Queue((Queue*) queue);
}


/**
 * @brief Get the Size Tiny Queue object 查看队列中元素所占内存空间的大小
 * 
 * @param queue 
 * @return unsigned int 
 */
unsigned int getSize_Tiny_Queue(Tiny_Queue* queue){
    return getSize_Queue((Queue*) queue);
}


/**
 * @brief 删除整个队列并释放内存空间
 * 
 * @param queue 
 * @return int 
 */
int delete_Tiny_Queue(Tiny_Queue* queue){
    return delete_Queue((Queue*) queue);
}


/**
 * @brief 栈初始化
 * 
 * @param memory_limit 
 * @param data_size 
 * @return Tiny_Stack 
 */
Tiny_Stack new_Tiny_Stack(unsigned int memory_limit, unsigned int data_size){
    Tiny_Stack stack;
    stack.memory_size = 0;
    stack.memory_limit = memory_limit;
    stack.memory_size += sizeof(Tiny_Stack);
    stack.head = 0;
    stack.length = 0;

    stack.push = add_Tiny_Stack;
    stack.get = get_Tiny_Stack;
    stack.pop = pop_Tiny_Stack;
    stack.getSize = getSize_Tiny_Stack;
    stack.delete = delete_Tiny_Stack;

    stack.data_size = data_size;
    return stack;
}


/**
 * @brief  Tiny_Stack添加新元素
 * 
 * @param stack 
 * @return void* 
 */
int add_Tiny_Stack(Tiny_Stack* stack, void* data, unsigned int data_size){
    return add_List((List* )stack, data, stack->data_size);
}


/**
 * @brief 从栈中弹出数据
 * 
 * @param stack 
 * @return void* 
 */
int pop_Tiny_Stack(Tiny_Stack* stack){
    return pop_Stack((Stack* ) stack);
}

/**
 * @brief Get the Stack object获得栈中元素的值
 * 
 * @param stack 
 * @return void* 
 */
void* get_Tiny_Stack(Tiny_Stack* stack){
    return get_Stack((Stack* ) stack);
}

/**
 * @brief Get the Size Stack object获得栈中元素所占内存空间的大小
 * 
 * @param stack 
 * @return unsigned int 
 */
unsigned int getSize_Tiny_Stack(Tiny_Stack* stack){
    return getSize_Stack((Stack* ) stack);
}


/**
 * @brief delete
 * 
 * @param stack 
 * @return int 
 */
int delete_Tiny_Stack(Tiny_Stack* stack){
    return delete_Stack((Stack* ) stack);
}     


/**
 * @brief 栈初始化
 * 
 * @param memory_limit 
 * @param key_size 
 * @param data_size 
 * @return Tiny_Map 
 */
Tiny_Map new_Tiny_Map(unsigned int memory_limit, unsigned int key_size, unsigned int data_size){
    Tiny_Map map;
    List key_list = new_List(0xffffffff);
    List value_list = new_List(0xffffffff);
    map.memory_size = 0;
    map.memory_limit = memory_limit;
    map.memory_size += sizeof(Tiny_Map);
    map.key_head = key_list;
    map.data_head = value_list;
    map.length = 0;
    
    map.push = push_Tiny_Map;
    map.get = get_Tiny_Map;
    map.getKey = getKey_Tiny_Map;
    map.getKeySize = getKeySize_Tiny_Map;
    map.getSize = getSize_Tiny_Map;
    map.remove = remove_Tiny_Map;
    map.delete = delete_Tiny_Map;
    map.values = values_Tiny_Map;
    map.keySet = getKey_Tiny_Map;

    map.key_size = key_size;
    map.data_size = data_size;
    return map;
}



int push_Tiny_Map(Tiny_Map* map, void* key, void* data)      //往Map集合中添加数据
{
    return push_Map((Map*) map, key,map->key_size, data, map->data_size);
}
int remove_Tiny_Map(Tiny_Map* map, void* key)                                        //删除key对应的键值对
{
    return remove_Map((Map*) map, key, map->key_size);
}
void* get_Tiny_Map(Tiny_Map* map, void* key)                                         //获得Map键值对应的数据元素指针
{
    return get_Map((Map*) map, key, map->key_size);
}
void* getKey_Tiny_Map(Tiny_Map* map, void* data)                                      //获得Map数据值对应的键值指针
{
    return getKey_Map((Map*) map, data, map->data_size);
}
unsigned int getSize_Tiny_Map(Tiny_Map* map, void* key)                              //获得Map键值对应的元素所占的内存大小
{
    return getSize_Map((Map*) map, key, map->key_size);
}
unsigned int getKeySize_Tiny_Map(Tiny_Map* map, void* key)                           //获得Map键对应的元素所占的内存大小
{
    return getKeySize_Map((Map*) map, key, map->key_size);
}
List* values_Tiny_Map(Tiny_Map* map)                                                                       //返回map的值集合，返回类型是一个链表集合
{
    return values_Map((Map*) map);
}
List* keySet_Tiny_Map(Tiny_Map* map)                                                                        //返回map的键值集合，返回类型是一个链表集合
{
    return keySet_Map((Map*) map);
}
int delete_Tiny_Map(Tiny_Map* map)                                                                         //删除map集合
{
    return delete_Map((Map*) map);                   
}