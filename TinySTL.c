/*
 * @Author: gong hao jing
 * @Date: 2021-08-22 01:10:08
 * @LastEditTime: 2021-08-25 02:58:31
 * @LastEditors: Please set LastEditors
 * @Description: ����һ��c�������ݽṹ��ļ�ʵ��
 * @FilePath: \TinySTL\TinySTL.c
 */

#include "TinySTL.h" 

/**
 * @brief �����ӡ����
 * 
 * @param chars ������Ϣ
 */
void print_error(char *chars){
    printf("******************************\r\n");
    printf(chars);
    printf("******************************\r\n");
}


/**
 * @brief �����ڴ�ռ�
 * 
 * @return void* 
 * @return void* 
 */
void* new(unsigned int data_size){
    return malloc(data_size);
}


/**
 * @brief ��ʼ��List
 * 
 * @param memory_limit �����ڴ����ƣ�byte
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
 * @brief ������������һ��Ԫ��
 * 
 * @param list ����ͷ���
 * @param data Ԫ������ָ��
 * @param data_size Ԫ����ռ�ڴ�ռ�Ĵ�С
 * @return int -1--ʧ�� 1--�ɹ� 0--�ڴ泬��
 */
int add_List(List* list, void* data, unsigned int data_size){
    Node *new_node = 0;
    Node *last_node = 0;
    void *new_data = 0;
    if(list == 0){
        print_error("��ͷ����Ǹ���ָ�룡��\r\n");
        return -1;
    }
    if((list->memory_size + sizeof(Node) + data_size) > list->memory_limit){
        print_error("�ڴ泬�ޣ�\r\n");
        return 0;
    }
    new_node = (Node*)malloc(sizeof(Node));
    if(new_node == 0){
        print_error("����ڵ��ڴ�ʧ��\r\n");
        return -1;
    }
    new_node->data_size = data_size;
    if (data_size != 0) {
        new_data = malloc(data_size);
        new_data = memcpy(new_data, data, data_size);
        if (new_data == 0) {
            print_error("����ڵ������ڴ�ʧ��\r\n");
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
 * @brief ������ָ��λ���������
 * 
 * @param list ����ͷ���
 * @param index λ�ã�0-...
 * @param data 
 * @param data_size 
 * @return int -1--ʧ�� 1--�ɹ� 0--�ڴ泬��
 */
int addAt_List(List* list, unsigned int index, void* data, unsigned int data_size){
    Node *new_node;
    Node *last_node;
    void *new_data;
    int i = 0;
    if(list == 0){
        print_error("��ͷ����Ǹ���ָ�룡��\r\n");
        return -1;
    }
    if((list->memory_size + sizeof(Node) + data_size) > list->memory_limit){
        print_error("�ڴ泬�ޣ�\r\n");
        return 0;
    }
    if(index > list->length || index < 0){
        print_error("����λ�ó���!\r\n");
        return -1;
    }
    new_node = (Node*)malloc(sizeof(Node));
    if(new_node == 0){
        print_error("����ڵ��ڴ�ʧ��\r\n");
        return -1;
    }
    new_node->data_size = data_size;
    if (data_size != 0) {
        new_data = malloc(data_size);
        new_data = memcpy(new_data, data, data_size);
        if (new_data == 0) {
            print_error("����ڵ������ڴ�ʧ��\r\n");
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
 * @brief �ҵ���index���ڵ�
 * 
 * @param list 
 * @param index 
 * @return Node* 
 */
Node* get_Node(List* list, unsigned int index){
    Node* last_node;
    int i;
    if(index >= list->length || index < 0){
        print_error("û������ڵ�!\r\n");
        return 0;
    }
    last_node = list->head;
    for(i = 0; i < index; i++){
        last_node = last_node->next;
    }
    return last_node;
}

/**
 * @brief ɾ������ָ��λ�õ�����
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
        print_error("��ͷ����Ǹ���ָ�룡��\r\n");
        return -1;
    }
    if(list->length == 0){
        print_error("������Ϊ��\r\n");
        return 0;
    }
    if (index >= list->length) {
        print_error("���ʵ�λ�ò�����\r\n");
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
 * @brief ������β��������
 * 
 * @param list ����ָ��
 * @return int -1--ʧ�� 1--�ɹ� 0--����Ϊ��
 */
int remove_List(List* list){
    return removeAt_List(list,list->length-1);
}

/**
 * @brief Get the List object
 * 
 * @param list 
 * @param index 
 * @return void* �ڵ�����Ԫ��ָ��
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
 * @brief ��ȡ��������Ԫ�صĴ�С
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
 * @brief Set the List object��������ָ��λ�õ�ֵ
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
        print_error("��ͷ����Ǹ���ָ�룡��\r\n");
        return -1;
    }
    if(list->length == 0){
        print_error("����Ϊ��\r\n");
        return 0;
    }
    if(index > list->length || index < 0){
        print_error("λ�ó���!\r\n");
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
            print_error("����ڵ������ڴ�ʧ��\r\n");
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
 * @return int -1--ʧ��  >0--�ɹ�
 */
int index_List(List* list, void* data, unsigned int data_size){
    Node* node;
    void* data_new;
    int i = 0;
    int j = 0;
    if(list == 0){
        print_error("��ͷ����Ǹ���ָ�룡��\r\n");
        return -1;
    }
    if(list->length == 0){
        //print_error("����Ϊ��\r\n");
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
 * @brief ��index����ʼȡ��Ԫ������
 * 
 * @param list 
 * @param index 
 * @param data 
 * @param data_size 
 * @return int -1--ʧ��  >0--�ɹ�
 */
int indexFrom_List(List* list, unsigned int index, void* data, unsigned int data_size){
    Node* node;
    void* data_new;
    int i = 0;
    int j = 0;
    if(list == 0){
        print_error("��ͷ����Ǹ���ָ�룡��\r\n");
        return -1;
    }
    if(list->length == 0){
        print_error("����Ϊ��\r\n");
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
 * @brief ��ȡ���Ԫ�ص����������Լ�ʵ�ֱȽϺ���
 * 
 * @param list 
 * @param compare 
 * @return unsigned int 
 */
unsigned int max_List(List* list, int(*compare)(void* first, void* second, unsigned int data_size)){

    return 0;
}


/**
 * @brief ��ȡ��index��Ԫ�ص����������Լ�ʵ�ֱȽϺ���
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
 * @brief ��ȡ��СԪ�ص����������Լ�ʵ�ֱȽϺ���
 * 
 * @param list 
 * @param compare 
 * @return unsigned int 
 */
unsigned int min_List(List* list, int(*compare)(void* first, void* second, unsigned int data_size)){

    return 0;
}


/**
 * @brief ��ȡ��indexСԪ�ص����������Լ�ʵ�ֱȽϺ���
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
 * @brief ɾ�����������ͷ��ڴ�ռ�
 * 
 * @param list 
 * @return int 1-ɾ���ɹ�
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
 * @brief ���г�ʼ��
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
 * @brief �Ӷ����е�������
 * 
 * @param queue 
 * @return int 1--�ɹ�
 */
int pop_Queue(Queue* queue){
    return removeAt_List((List*)queue, 0);
}


/**
 * @brief �鿴������Ԫ�ص�ֵ
 * 
 * @param queue 
 * @return void* 
 */
void* get_Queue(Queue* queue){
    return get_List((List *)queue, 0);
}


/**
 * @brief �鿴������Ԫ����ռ�ڴ�ռ�Ĵ�С
 * 
 * @param queue 
 * @return unsigned int 
 */
unsigned int getSize_Queue(Queue* queue){
    return getSize_List((List *)queue, 0);
}


/**
 * @brief ɾ���������в��ͷ��ڴ�ռ�
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
 * @brief ջ��ʼ��
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
 * @brief ���ջ��Ԫ�ص�ֵ
 * 
 * @param stack 
 * @return void* 
 */
void* get_Stack(Stack* stack){
    return get_List((List *)stack, stack->length - 1);
}

/**
 * @brief ��ջ�е�������
 * 
 * @param stack 
 * @return void* 
 */
int pop_Stack(Stack* stack){
    return removeAt_List((List*)stack, stack->length - 1);
}


/**
 * @brief Get the Size Stack object���ջ��Ԫ����ռ�ڴ�ռ�Ĵ�С
 * 
 * @param stack 
 * @return unsigned int 
 */
unsigned int getSize_Stack(Stack* stack){
    return getSize_List((List *)stack, stack->length - 1);
}


/**
 * @brief ɾ��ջ
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
 * @brief ջ��ʼ��
 * 
 * @param memory_limit �ڴ��С����
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
 * @brief ��Map�������������
 * 
 * @param map 
 * @param key 
 * @param key_size 
 * @param data 
 * @param data_size 
 * @return int -1----ʧ��   1----�ɹ�  0 ------�ڴ治����ü��Ѵ���
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
        print_error("Map���ϼ���ʧ�ܣ��ڴ治����ü��Ѵ���\r\n");
        return 0;
    }
}


/**
 * @brief ɾ��key��Ӧ�ļ�ֵ��
 * 
 * @param map 
 * @param key 
 * @param key_size 
 * @return int -1----ʧ��  0-----δ��ѯ��  1----�ɹ�
 */
int remove_Map(Map* map, void* key, unsigned int key_size){
    int index = -1;
    index = map->key_head.index(&map->key_head, key, key_size);
    if(index != -1){
        if(!(map->key_head.removeAt(&map->key_head, index) && map->data_head.removeAt(&map->data_head, index))){
            print_error("ɾ����ֵ��ʱ����\r\n");
            return -1;
        }
        map->length = map->key_head.length;
        map->memory_size = (map->key_head.memory_size + map->data_head.memory_size + sizeof(Map) - 2*sizeof(List));
        return 1;
    }
    return 0;
}

/**
 * @brief ���Map��ֵ��Ӧ������Ԫ��ָ��
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
 * @brief ���Map����ֵ��Ӧ�ļ�ֵָ��
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
 * @brief ���Map��ֵ��Ӧ��Ԫ����ռ���ڴ��С
 * 
 * @param map 
 * @param key 
 * @param key_size 
 * @return unsigned int -1----δ�ҵ�Ŷ
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
 * @brief ���Map����Ӧ��Ԫ����ռ���ڴ��С
 * 
 * @param map 
 * @param key 
 * @param key_size 
 * @return unsigned int -1----δ�ҵ�Ŷ
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
 * @brief ����map��ֵ���ϣ�����������һ��������
 * 
 * @param map 
 * @return List* 
 */
List* values_Map(Map* map){
    return &map->data_head;
}


/**
 * @brief ����map�ļ�ֵ���ϣ�����������һ��������
 * 
 * @param map 
 * @return List* 
 */
List* keySet_Map(Map* map){
    return &map->key_head;
}


/**
 * @brief ɾ��map����
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
Tiny_List new_TinyList(unsigned int memory_limit, unsigned int data_size)                              //˫�������ʼ��
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
void* get_TinyList(Tiny_List* list, unsigned int index)                                                //��ȡ��������Ԫ��
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
unsigned int getSize_TinyList( Tiny_List* list, unsigned int index)                                    //��ȡ��������Ԫ�صĴ�С
{
    return getSize_List( (List*) list, index);
}


/**
 * @brief 
 * 
 */
int delete_TinyList( Tiny_List* list)                                                                   //ɾ�����������ͷ��ڴ�ռ�
{
    return delete_List( (List*) list);                         
}


/**
 * @brief 
 * 
 */
int add_TinyList( Tiny_List* list, void* data )                                  //������β���������
{
    return add_List( (List*) list, data, list->data_size);
}


/**
 * @brief 
 * 
 */
int addAt_TinyList( Tiny_List* list, unsigned int index, void* data )            //������ָ��λ���������
{
    return addAt_List( (List*) list, index, data, list->data_size);
}


/**
 * @brief 
 * 
 */
int set_TinyList( Tiny_List* list, unsigned int index, void* data )              //��������ָ��λ�õ�ֵ
{
    return set_List( (List*) list,index,data, list->data_size );
}


/**
 * @brief 
 * 
 */
int remove_TinyList( Tiny_List* list)                                                                   //ɾ������β��������
{
    return remove_List( (List*) list);        
}


/**
 * @brief 
 * 
 */
int removeAt_TinyList( Tiny_List* list, unsigned int index)                                            //ɾ������ָ��λ�õ�����
{
    return removeAt_List( (List*) list, index);                    
}


/**
 * @brief 
 * 
 */
int index_TinyList( Tiny_List* list, void* data )                                //ȡ��ָ��Ԫ������
{
    return index_List((List*)list, data, list->data_size);
}


/**
 * @brief 
 * 
 */
int indexFrom_TinyList( Tiny_List* list, unsigned int index, void* data )       //��index����ʼȡ��Ԫ������
{
    return indexFrom_List((List*)list, index, data, list->data_size);
}


/**
 * @brief 
 * 
 */
unsigned int max_TinyList( Tiny_List* list, int(*compare)(void* first, void* second ))                         //��ȡ���Ԫ�ص����������Լ�ʵ�ֱȽϺ���
{
    
    return 0;
}


/**
 * @brief 
 * 
 */
unsigned int maxOf_TinyList( Tiny_List* list, unsigned int index, int(*compare)(void* first, void* second ))   //��ȡ��index��Ԫ�ص����������Լ�ʵ�ֱȽϺ���
{

    return 0;
}


/**
 * @brief 
 * 
 */
unsigned int min_TinyList( Tiny_List* list, int(*compare)(void* first, void* second ))                         //��ȡ��СԪ�ص����������Լ�ʵ�ֱȽϺ���
{

    return 0;
}


/**
 * @brief 
 * 
 */
unsigned int minOf_TinyList( Tiny_List* list, unsigned int index, int(*compare)(void* first, void* second ))   //��ȡ��indexСԪ�ص����������Լ�ʵ�ֱȽϺ���
{

    return 0;
}


/**
 * @brief ���г�ʼ��
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
 * @brief �Ӷ����е�������
 * 
 * @param queue 
 * @return void* 
 */
int pop_Tiny_Queue(Tiny_Queue* queue){
    return pop_Queue((Queue*) queue);
}


/**
 * @brief Get the Tiny Queue object�鿴������Ԫ�ص�ֵ
 * 
 * @param queue 
 * @return void* 
 */
void* get_Tiny_Queue(Tiny_Queue* queue){
    return get_Queue((Queue*) queue);
}


/**
 * @brief Get the Size Tiny Queue object �鿴������Ԫ����ռ�ڴ�ռ�Ĵ�С
 * 
 * @param queue 
 * @return unsigned int 
 */
unsigned int getSize_Tiny_Queue(Tiny_Queue* queue){
    return getSize_Queue((Queue*) queue);
}


/**
 * @brief ɾ���������в��ͷ��ڴ�ռ�
 * 
 * @param queue 
 * @return int 
 */
int delete_Tiny_Queue(Tiny_Queue* queue){
    return delete_Queue((Queue*) queue);
}


/**
 * @brief ջ��ʼ��
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
 * @brief  Tiny_Stack�����Ԫ��
 * 
 * @param stack 
 * @return void* 
 */
int add_Tiny_Stack(Tiny_Stack* stack, void* data, unsigned int data_size){
    return add_List((List* )stack, data, stack->data_size);
}


/**
 * @brief ��ջ�е�������
 * 
 * @param stack 
 * @return void* 
 */
int pop_Tiny_Stack(Tiny_Stack* stack){
    return pop_Stack((Stack* ) stack);
}

/**
 * @brief Get the Stack object���ջ��Ԫ�ص�ֵ
 * 
 * @param stack 
 * @return void* 
 */
void* get_Tiny_Stack(Tiny_Stack* stack){
    return get_Stack((Stack* ) stack);
}

/**
 * @brief Get the Size Stack object���ջ��Ԫ����ռ�ڴ�ռ�Ĵ�С
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
 * @brief ջ��ʼ��
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



int push_Tiny_Map(Tiny_Map* map, void* key, void* data)      //��Map�������������
{
    return push_Map((Map*) map, key,map->key_size, data, map->data_size);
}
int remove_Tiny_Map(Tiny_Map* map, void* key)                                        //ɾ��key��Ӧ�ļ�ֵ��
{
    return remove_Map((Map*) map, key, map->key_size);
}
void* get_Tiny_Map(Tiny_Map* map, void* key)                                         //���Map��ֵ��Ӧ������Ԫ��ָ��
{
    return get_Map((Map*) map, key, map->key_size);
}
void* getKey_Tiny_Map(Tiny_Map* map, void* data)                                      //���Map����ֵ��Ӧ�ļ�ֵָ��
{
    return getKey_Map((Map*) map, data, map->data_size);
}
unsigned int getSize_Tiny_Map(Tiny_Map* map, void* key)                              //���Map��ֵ��Ӧ��Ԫ����ռ���ڴ��С
{
    return getSize_Map((Map*) map, key, map->key_size);
}
unsigned int getKeySize_Tiny_Map(Tiny_Map* map, void* key)                           //���Map����Ӧ��Ԫ����ռ���ڴ��С
{
    return getKeySize_Map((Map*) map, key, map->key_size);
}
List* values_Tiny_Map(Tiny_Map* map)                                                                       //����map��ֵ���ϣ�����������һ��������
{
    return values_Map((Map*) map);
}
List* keySet_Tiny_Map(Tiny_Map* map)                                                                        //����map�ļ�ֵ���ϣ�����������һ��������
{
    return keySet_Map((Map*) map);
}
int delete_Tiny_Map(Tiny_Map* map)                                                                         //ɾ��map����
{
    return delete_Map((Map*) map);                   
}