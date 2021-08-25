/*
 * @Author: your name
 * @Date: 2021-08-22 01:12:20
 * @LastEditTime: 2021-08-24 16:04:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \TinySTL\main.c
 */
#include<stdio.h>
#include "TinySTL.h"
#define _CRT_SECURE_NO_WARNINGS


int main(void){
	char* chars[200];
	char* datas;
	char* keys[200];
	int witch = 0;
	int data = 0;
	int key = 0;
	int state = 0;
	unsigned int data_size = 0;
	unsigned int key_size = 0;
	unsigned int index = 0;
	unsigned int where = 0;
	int i = 0;
	int a = 111;
	int b = 222;

	List list = new_List(1024);     //内存限制为1k
	Queue queue = new_Queue(1024);  //内存限制为1k
	Stack stack = new_Stack(1024);  //内存限制为1k
	Map map = new_Map(1024);        //内存限制为1k

	printf("Tiny系列数据结构简单测试：-----------------------------------------\r\n");
	Tiny_List tiny_list = new_TinyList(1024, 6);
	Tiny_Queue tiny_queue = new_TinyQueue(1024, 0);
	Tiny_Stack tiny_stack = new_Tiny_Stack(1024, 0);
	Tiny_Map tiny_map = new_Tiny_Map(1024, 0, 0);

	printf("-------------------Tiny_List----------------------\r\n");
	printf("length: %d\r\n", tiny_list.length);
	printf("mem_size: %d字节\r\n", tiny_list.memory_size);
	tiny_list.add(&tiny_list, &a);
	tiny_list.add(&tiny_list, &b);
	printf("0: %d\r\n", *(int*)tiny_list.get(&tiny_list, 0));
	printf("1: %d\r\n", *(int*)tiny_list.get(&tiny_list, 1));
	printf("length: %d\r\n", tiny_list.length);
	printf("mem_size: %d字节\r\n", tiny_list.memory_size);

	printf("-------------------Tiny_Queue----------------------\r\n");
	printf("length: %d\r\n", tiny_queue.length);
	printf("mem_size: %d字节\r\n", tiny_queue.memory_size);
	tiny_queue.push(&tiny_queue, 111);
	tiny_queue.push(&tiny_queue, 222);
	printf("0: %d\r\n", tiny_queue.get(&tiny_queue));
	tiny_queue.pop(&tiny_queue);
	printf("1: %d\r\n", tiny_queue.get(&tiny_queue));
	printf("length: %d\r\n", tiny_queue.length);
	printf("mem_size: %d字节\r\n", tiny_queue.memory_size);

	printf("-------------------Tiny_Stack----------------------\r\n");
	printf("length: %d\r\n", tiny_stack.length);
	printf("mem_size: %d字节\r\n", tiny_stack.memory_size);
	tiny_stack.push(&tiny_stack, 111);
	tiny_stack.push(&tiny_stack, 222);
	printf("0: %d\r\n", tiny_stack.get(&tiny_stack));
	tiny_stack.pop(&tiny_stack);
	printf("1: %d\r\n", tiny_stack.get(&tiny_stack));
	printf("length: %d\r\n", tiny_stack.length);
	printf("mem_size: %d字节\r\n", tiny_stack.memory_size);

	printf("-------------------Tiny_Map----------------------\r\n");
	printf("length: %d\r\n", tiny_map.length);
	printf("mem_size: %d字节\r\n", tiny_map.memory_size);
	tiny_map.push(&tiny_map, 0, 111);
	tiny_map.push(&tiny_map, 1, 111);
	tiny_map.push(&tiny_map, 2, 222);
	tiny_map.push(&tiny_map, 3, 333);
	tiny_map.push(&tiny_map, 4, 444);
	tiny_map.push(&tiny_map, 5, 555);
	printf("0: %d\r\n", tiny_map.get(&tiny_map, 0));
	printf("1: %d\r\n", tiny_map.get(&tiny_map, 1));
	printf("2: %d\r\n", tiny_map.get(&tiny_map, 2));
	printf("3: %d\r\n", tiny_map.get(&tiny_map, 3));
	printf("4: %d\r\n", tiny_map.get(&tiny_map, 4));
	printf("5: %d\r\n", tiny_map.get(&tiny_map, 5));
	tiny_map.remove(&tiny_map, 0);
	printf("length: %d\r\n", tiny_map.length);
	printf("mem_size: %d字节\r\n", tiny_map.memory_size);


	printf("当data_size或key_size为0时，数据保存在节点的数据指针中，不额外开辟内存空间\r\n");
	while(1){
		printf("请选择想要测试哪种结构：\r\n");
		printf("0--------链表\r\n");
		printf("1--------队列\r\n");
		printf("2--------栈\r\n");
		printf("3--------Map集合\r\n");
		scanf_s("%d", &state);
		switch (state)
		{
		case 0:
			printf("*************Link Menu************\r\n");
			printf("-1--------退出\r\n");
			printf("0--------显示详细信息\r\n");
			printf("1--------往链表尾部添加数据\r\n");
			printf("2--------往链表指定位置添加数据\r\n");
			printf("3--------更新链表指定位置的值\r\n");
			printf("4--------删除链表尾部的数据\r\n");
			printf("5--------删除链表指定位置的数据\r\n");
			printf("6--------取得指定元素索引\r\n");
			printf("7--------从index处开始取得元素索引\r\n");
			printf("8--------获取索引处的元素\r\n");
			printf("9--------获取索引处的元素的大小\r\n");
			printf("10-------删除整条链表并释放内存空间\r\n");
			printf("**********************************\r\n");
			while (state != -1) {
				scanf_s("%d", &state);
				switch (state)
				{
				case 0:
					printf("list长度:%d\r\n", list.length);
					printf("list占用内存大小:%d\r\n", list.memory_size);
					printf("每个不带数据域的节点占用空间大小%d\r\n", sizeof(Node));
					printf("*************Link Menu************\r\n");
					printf("-1--------退出\r\n");
					printf("0--------显示详细信息\r\n");
					printf("1--------往链表尾部添加数据\r\n");
					printf("2--------往链表指定位置添加数据\r\n");
					printf("3--------更新链表指定位置的值\r\n");
					printf("4--------删除链表尾部的数据\r\n");
					printf("5--------删除链表指定位置的数据\r\n");
					printf("6--------取得指定元素索引\r\n");
					printf("7--------从index处开始取得元素索引\r\n");
					printf("8--------获取索引处的元素\r\n");
					printf("9--------获取索引处的元素的大小\r\n");
					printf("10-------删除整条链表并释放内存空间\r\n");
					printf("**********************************\r\n");
					break;

				case 1:
					printf("int add(List *list, void* data, unsigned int data_size)\r\n");
					printf("data_size:\r\n");
					scanf_s("%d", &data_size);
					printf("data:\r\n");
					if (data_size == 0) {
						scanf_s("%d", &data);
						if(list.add(&list, data, data_size) == 1)
							printf("插入成功\r\n");
					}
					else {
						scanf_s("%s", chars, 200);
						if (list.add(&list, chars, data_size) == 1)
							printf("插入成功\r\n");
					}
					break;

				case 2:
					printf("int addAt(List *list, unsigned int index, void* data，unsigned int data_size)\r\n");
					printf("index:\r\n");
					scanf_s("%d", &index);
					printf("data_size:\r\n");
					scanf_s("%d", &data_size);
					printf("data:\r\n");
					if (data_size == 0) {
						scanf_s("%d", &data);
						if (list.addAt(&list,index, data, data_size) == 1)
							printf("插入成功\r\n");
					}
					else {
						scanf_s("%s", chars, 200);
						if (list.addAt(&list,index, chars, data_size) == 1)
							printf("插入成功\r\n");
					}
					break;

				case 3:
					printf("int set(List *list, unsigned int index, void* data，unsigned int data_size)\r\n");
					printf("index:\r\n");
					scanf_s("%d", &index);
					printf("data_size:\r\n");
					scanf_s("%d", &data_size);
					printf("data:\r\n");
					if (data_size == 0) {
						scanf_s("%d", &data);
						if (list.set(&list,index, data, data_size) == 1)
							printf("插入成功\r\n");
					}
					else {
						scanf_s("%s", chars, 200);
						if (list.set(&list,index, chars, data_size) == 1)
							printf("插入成功\r\n");
					}
					break;

				case 4:
					printf("int remove(List *list)\r\n");
					if (list.remove(&list) == 1)
						printf("删除成功\r\n");
					break;

				case 5:
					printf("int removeAt(List *list, unsigned int index)\r\n");
					printf("index:\r\n");
					scanf_s("%d", &index);
					if (list.removeAt(&list,index) == 1)
						printf("删除成功\r\n");
					break;

				case 6:
					printf("int index(List *list, void* data, unsigned int data_size)\r\n");
					printf("data_size:\r\n");
					scanf_s("%d", &data_size);
					printf("data:\r\n");
					if (data_size == 0) {
						scanf_s("%d", &data);
						if (list.index(&list, data, data_size) != -1)
							printf("元素%d的索引为：%d\r\n", data, list.index(&list, data, data_size));
					}
					else {
						scanf_s("%s", chars, 200);
						if (list.index(&list, chars, data_size) != -1)
							printf("该元素的索引为：%d\r\n", list.index(&list, chars, data_size));
					}
					break;

				case 7:
					printf("int indexFrom(List *list, unsigned int index, void* data, unsigned int data_size)\r\n");
					printf("indexFrom:\r\n");
					scanf_s("%d", &index);
					printf("data_size:\r\n");
					scanf_s("%d", &data_size);
					printf("data:\r\n");
					if (data_size == 0) {
						scanf_s("%d", &data);
						if (list.indexFrom(&list, index, data, data_size) != -1)
							printf("元素%d的索引为：%d\r\n", data, list.indexFrom(&list, index, data, data_size));
					}
					else {
						scanf_s("%s", chars, 200);
						if (list.indexFrom(&list, index, chars, data_size) != -1)
							printf("该元素的索引为：%d\r\n", list.indexFrom(&list, index, chars, data_size));
					}
					break;

				case 8:
					printf("void* get(List *list, unsigned int index)\r\n");
					printf("index:\r\n");
					scanf_s("%d", &index);
					data_size = list.getSize(&list, index);
					if (list.get(&list, index) != 0) {
						if (data_size == 0) {
							printf("第%d个元素为：%d  ,该元素占空内存空间大小：%d字节\r\n", index, list.get(&list, index), data_size);
						}
						else {
							datas = list.get(&list, index);
							printf("第%d个元素为：", index);
							for (i = 0; i < data_size; i++) {
								printf("%c", datas[i]);
							}
							printf("   ,该元素占空内存空间大小：% d字节\r\n", data_size);
						}
					}
					break;

				case 9:
					printf("void* getSize(List *list, unsigned int index)\r\n");
					printf("index:\r\n");
					scanf_s("%d", &index);
					printf("第%d个元素占空内存空间大小：%d字节\r\n", index, list.getSize(&list, index));
					break;
					

				case 10:
					if (list.delete(&list) == 1)
						printf("删除成功\r\n");
					break;
				case -1:
					state = -1;
					break;

				default:
					printf("请输入正确值!!!\r\n");
					break;
				}
			}
			break;

		case 1:
			printf("*************Queue Menu************\r\n");
			printf("-1--------退出\r\n");
			printf("0--------显示详细信息\r\n");
			printf("1--------往队列中添加数据\r\n");
			printf("2--------从队列中弹出数据\r\n");
			printf("3--------获得队列中元素的值\r\n");
			printf("4--------获得队列中元素所占内存空间的大小\r\n");
			printf("5--------删除队列\r\n");
			printf("**********************************\r\n");
			while (state != -1) {
				scanf_s("%d", &state);
				switch (state)
				{
				case 0:
					printf("queue长度:%d\r\n", queue.length);
					printf("queue占用内存大小:%d\r\n", queue.memory_size);
					printf("每个不带数据域的节点占用空间大小%d\r\n", sizeof(Node));
					printf("*************Queue Menu************\r\n");
					printf("-1--------退出\r\n");
					printf("0--------显示详细信息\r\n");
					printf("1--------往队列中添加数据\r\n");
					printf("2--------从队列中弹出数据\r\n");
					printf("3--------获得队列中元素的值\r\n");
					printf("4--------获得队列中元素所占内存空间的大小\r\n");
					printf("5--------删除队列\r\n");
					printf("**********************************\r\n");
					break;

				case 1:
					printf("int push(Queue *queue, void* data, unsigned int data_size)\r\n");
					printf("data_size:\r\n");
					scanf_s("%d", &data_size);
					printf("data:\r\n");
					if (data_size == 0) {
						scanf_s("%d", &data);
						if (queue.push(&queue, data, data_size) == 1)
							printf("插入成功\r\n");
					}
					else {
						scanf_s("%s", chars, 200);
						if (queue.push(&queue, chars, data_size) == 1)
							printf("插入成功\r\n");
					}
					break;

				case 2:
					printf("int pop(Queue *queue)\r\n");
					if (queue.pop(&queue) > 0)
						printf("弹出成功\r\n");
					break;

				case 3:
					printf("void* get(Queue *queue)\r\n");
					data_size = queue.getSize(&queue);
					if (queue.get(&queue) != 0) {
						if (data_size == 0) {
							printf("第%d个元素为：%d  ,该元素占空内存空间大小：%d字节\r\n", queue.length , queue.get(&queue), data_size);
						}
						else {
							datas = queue.get(&queue);
							printf("第%d个元素为：", queue.length);
							for (i = 0; i < data_size; i++) {
								printf("%c", datas[i]);
							}
							printf("  ,该元素占空内存空间大小：% d字节\r\n", data_size);
						}
					}
					break;

				case 4:
					printf("unsigned int getSize(Queue *queue)\r\n");
					data_size = queue.getSize(&queue);
					if (data_size != 0) {
						printf("该元素占空内存空间大小：%d字节\r\n", data_size);
					}
					break;

				case 5:
					printf("int delete(Queue *queue)\r\n");
					if (queue.delete(&queue) == 1)
						printf("删除成功\r\n");
					break;

				case -1:
					state = -1;
					break;

				default:
					printf("请输入正确值!!!\r\n");
					break;
				}
			}
			break;

		case 2:
			printf("*************Stack Menu************\r\n");
			printf("-1--------退出\r\n");
			printf("0--------显示详细信息\r\n");
			printf("1--------往栈中添加数据\r\n");
			printf("2--------从栈中弹出数据\r\n");
			printf("3--------获得栈中元素的值\r\n");
			printf("4--------获得栈中元素所占内存空间的大小\r\n");
			printf("5--------删除栈\r\n");
			printf("**********************************\r\n");
			while (state != -1) {
				scanf_s("%d", &state);
				switch (state)
				{
				case 0:
					printf("stack长度:%d\r\n", stack.length);
					printf("stack占用内存大小:%d\r\n", stack.memory_size);
					printf("每个不带数据域的节点占用空间大小%d\r\n", sizeof(Node));
					printf("*************Stack Menu************\r\n");
					printf("-1--------退出\r\n");
					printf("0--------显示详细信息\r\n");
					printf("1--------往栈中添加数据\r\n");
					printf("2--------从栈中弹出数据\r\n");
					printf("3--------获得栈中元素的值\r\n");
					printf("4--------获得栈中元素所占内存空间的大小\r\n");
					printf("5--------删除栈\r\n");
					printf("**********************************\r\n");
					break;

				case 1:
					printf("int push(Stack *stack, void* data, unsigned int data_size)\r\n");
					printf("data_size:\r\n");
					scanf_s("%d", &data_size);
					printf("data:\r\n");
					if (data_size == 0) {
						scanf_s("%d", &data);
						if (stack.push(&stack, data, data_size) == 1)
							printf("插入成功\r\n");
					}
					else {
						scanf_s("%s", chars, 200);
						if (stack.push(&stack, chars, data_size) == 1)
							printf("插入成功\r\n");
					}
					break;

				case 2:
					printf("int pop(Stack *stack)\r\n");
					if (stack.pop(&stack) > 0)
						printf("弹出成功\r\n");
					break;

				case 3:
					printf("void* get(Stack *stack)\r\n");
					data_size = stack.getSize(&stack);
					if (stack.get(&stack) != 0) {
						if (data_size == 0) {
							printf("第%d个元素为：%d  ,该元素占空内存空间大小：%d字节\r\n", stack.length, stack.get(&stack), data_size);
						}
						else {
							datas = stack.get(&stack);
							printf("第%d个元素为：", stack.length);
							for (i = 0; i < data_size; i++) {
								printf("%c", datas[i]);
							}
							printf("   ,该元素占空内存空间大小：% d字节\r\n", data_size);
						}
					}
					break;

				case 4:
					printf("unsigned int getSize(Stack *stack)\r\n");
					data_size = stack.getSize(&stack);
					if (data_size != 0) {
						printf("该元素占空内存空间大小：%d字节\r\n", data_size);
					}
					break;

				case 5:
					printf("int delete(Stack *stack)\r\n");
					if (stack.delete(&stack) == 1)
						printf("删除成功\r\n");
					break;

				case -1:
					state = -1;
					break;

				default:
					printf("请输入正确值!!!\r\n");
					break;
				}
			}
			break;

		case 3:
			printf("*************Map Menu**************\r\n");
			printf("-1--------退出\r\n");
			printf("0--------显示详细信息\r\n");
			printf("1--------往Map集合中添加数据\r\n");
			printf("2--------删除key对应的键值对\r\n");
			printf("3--------获得Map键值对应的数据元素指针\r\n");
			printf("4--------获得Map数据值对应的键值指针\r\n");
			printf("5--------获得Map键值对应的元素所占的内存大小\r\n");
			printf("6--------获得Map键对应的元素所占的内存大小\r\n");
			printf("7--------返回map的值集合，返回类型是一个链表集合\r\n");
			printf("8--------返回map的键值集合，返回类型是一个链表集合\r\n");
			printf("9--------删除map集合\r\n");
			printf("**********************************\r\n");
			while (state != -1) {
				scanf_s("%d", &state);
				switch (state)
				{
				case 0:
					printf("map长度:%d\r\n", map.length);
					printf("map占用内存大小:%d\r\n", map.memory_size);
					printf("每个不带数据域的节点占用空间大小%d\r\n", sizeof(Node));
					printf("*************Map Menu**************\r\n");
					printf("-1--------退出\r\n");
					printf("0--------显示详细信息\r\n");
					printf("1--------往Map集合中添加数据\r\n");
					printf("2--------删除key对应的键值对\r\n");
					printf("3--------获得Map键值对应的数据元素指针\r\n");
					printf("4--------获得Map数据值对应的键值指针\r\n");
					printf("//5--------获得Map键值对应的元素所占的内存大小\r\n");
					printf("//6--------获得Map键对应的元素所占的内存大小\r\n");
					printf("//7--------返回map的值集合，返回类型是一个链表集合\r\n");
					printf("//8--------返回map的键值集合，返回类型是一个链表集合\r\n");
					printf("9--------删除map集合\r\n");
					printf("**********************************\r\n");
					break;

				case 1:
					printf("int push(Map* map, void* key, unsigned int key_size, void* data, unsigned int data_size)\r\n");
					printf("key_size:\r\n");
					scanf_s("%d", &key_size);
					if (key_size == 0) {
						printf("key:\r\n");
						scanf_s("%d", &key);
					}
					else {
						printf("key:\r\n");
						scanf_s("%s", keys, 200);
					}
					printf("data_size:\r\n");
					scanf_s("%d", &data_size);
					printf("data:\r\n");
					if (data_size == 0) {
						scanf_s("%d", &data);
						if (key_size == 0) {
							if (map.push(&map, key, key_size, data, data_size) == 1)
								printf("插入成功\r\n");
						}
						else {
							if (map.push(&map, keys, key_size, data, data_size) == 1)
								printf("插入成功\r\n");
						}
					}
					else {
						scanf_s("%s", chars, 200);
						if (key_size == 0) {
							if (map.push(&map, key, key_size, chars, data_size) == 1)
								printf("插入成功\r\n");
						}
						else {
							if (map.push(&map, keys, key_size, chars, data_size) == 1)
								printf("插入成功\r\n");
						}
					}
					break;

				case 2:
					printf("int remove(Map* map, void* key, unsigned int key_size)\r\n");
					printf("key_size:\r\n");
					scanf_s("%d", &key_size);
					if (key_size == 0) {
						printf("key:\r\n");
						scanf_s("%d", &key);
						if (map.remove(&map, key, key_size) == 1)
							printf("弹出成功\r\n");
						else
							printf("找不到\r\n");
					}
					else {
						printf("key:\r\n");
						scanf_s("%s", keys, 200);
						if (map.remove(&map, keys, key_size) == 1)
							printf("弹出成功\r\n");
						else
							printf("找不到\r\n");
					}
					break;

				case 3:
					printf("void* get(Map* map, void* key, unsigned int key_size)\r\n");
					printf("key_size:\r\n");
					scanf_s("%d", &key_size);
					printf("key:\r\n");
					if (key_size == 0) {
						scanf_s("%d", &key);
						data_size = map.getSize(&map, key, key_size);
						if (map.get(&map, key, key_size) != 0) {
							if (data_size == 0) {
								printf("该元素为：%d  ,该元素占空内存空间大小：%d字节\r\n", map.get(&map, key, key_size), data_size);
							}
							else {
								datas = map.get(&map, key, key_size);
								printf("该元素为：");
								for (i = 0; i < data_size; i++) {
									printf("%c", datas[i]);
								}
								printf("   ,该元素占空内存空间大小：% d字节\r\n", data_size);
							}
						}
					}
					else {
						scanf_s("%s", keys, 200);
						data_size = map.getSize(&map, keys, key_size);
						if (map.get(&map, keys, key_size) != 0) {
							if (data_size == 0) {
								printf("该元素为：%d  ,该元素占空内存空间大小：%d字节\r\n",map.get(&map, keys, key_size), data_size);
							}
							else {
								datas = map.get(&map, keys, key_size);
								printf("该元素为：");
								for (i = 0; i < data_size; i++) {
									printf("%c", datas[i]);
								}
								printf("   ,该元素占空内存空间大小：% d字节\r\n", data_size);
							}
						}
					}
					break;

				case 4:
					printf("void* getKey(Map* map, void* data, unsigned int data_size)\r\n");
					printf("data_size:\r\n");
					scanf_s("%d", &key_size);
					printf("data:\r\n");
					if (key_size == 0) {
						scanf_s("%d", &key);
						data_size = map.getKeySize(&map, key, key_size);
						if (map.getKey(&map, key, key_size) != 0) {
							if (data_size == 0) {
								printf("元素为：%d  ,该元素占空内存空间大小：%d字节\r\n", map.getKey(&map, key, key_size), data_size);
							}
							else {
								datas = map.getKey(&map, key, key_size);
								printf("元素为：");
								for (i = 0; i < data_size; i++) {
									printf("%c", datas[i]);
								}
								printf("   ,该元素占空内存空间大小：% d字节\r\n", data_size);
							}
						}
					}
					else {
						scanf_s("%s", keys, 200);
						data_size = map.getKeySize(&map, keys, key_size);
						if (map.getKey(&map, keys, key_size) != 0) {
							if (data_size == 0) {
								printf("元素为：%d  ,该元素占空内存空间大小：%d字节\r\n", map.getKey(&map, keys, key_size), data_size);
							}
							else {
								datas = map.getKey(&map, keys, key_size);
								printf("元素为：");
								for (i = 0; i < data_size; i++) {
									printf("%c", datas[i]);
								}
								printf("   ,该元素占空内存空间大小：% d字节\r\n", data_size);
							}
						}
					}
					break;

				case 9:
					printf("int delete(Map *map)\r\n");
					if (map.delete(&map) == 1)
						printf("删除成功\r\n");
					break;

				case -1:
					state = -1;
					break;

				default:
					printf("请输入正确值!!!\r\n");
					break;
				}
			}
			break;

		default:
			printf("请输入正确值!!!\r\n");
			break;
		}
	}
	// printf("List长度:%d\r\n", list.length);
	// printf("List占用内存大小:%d\r\n", list.memory_size);
	// printf("每个不带数据域的节点占用空间大小%d\r\n", sizeof(Node));

	// list.add(&list,"hello\0",6);
	// list.add(&list, "world\0", 6);
	// list.add(&list, "hahahaha\0", 10);
	// list.add(&list, 123456, 0);
	// list.add(&list, -123456, 1000);


	// printf("List元素0:%s\r\n", (char*)list.get(&list, 0));
	// printf("List元素1:%s\r\n", list.get(&list, 1)); 
	// printf("List元素2:%s\r\n", chars);
	// printf("List元素3:%d\r\n", list.get(&list,3));
	// printf("List元素4:%d\r\n", list.get(&list, 4));

	// printf("List长度:%d\r\n", list.length);
	// printf("List占用内存大小:%d\r\n", list.memory_size);

	// printf("删除第2个元素\r\n");
	// list.removeAt(&list, 2);
	// printf("List长度:%d\r\n", list.length);
	// printf("List占用内存大小:%d\r\n", list.memory_size);

	// list.set(&list, 2, 111111, 0);
	// printf("设置List元素2:%d\r\n", list.get(&list, 2));

	// printf("111111的索引:%d\r\n", list.index(&list, 111111, 0));

	// printf("List地址:%x\r\n",&list);

	// printf("*********************************************************************************\r\n");

	// printf("queue长度:%d\r\n", queue.length);
	// printf("queue占用内存大小:%d\r\n", queue.memory_size);
	// printf("每个不带数据域的节点占用空间大小%d\r\n", sizeof(Node));
	
	// queue.push(&queue, "hello queue\0", 20);
	// queue.push(&queue, 123123, 0);
	// queue.push(&queue, "queue end\0", 10);

	// printf("queue长度:%d\r\n", queue.length);
	// printf("queue占用内存大小:%d\r\n", queue.memory_size);

	// printf("查看队列元素:%s\r\n", queue.get(&queue));
	// printf("queue长度:%d\r\n", queue.length);
	// printf("queue占用内存大小:%d\r\n", queue.memory_size);
	// printf("弹出队列元素\r\n");
	// queue.pop(&queue);
	// printf("查看队列元素:%d\r\n", queue.get(&queue));
	// printf("queue长度:%d\r\n", queue.length);
	// printf("queue占用内存大小:%d\r\n", queue.memory_size);
	// printf("弹出队列元素:%d\r\n", queue.pop(&queue));
	// printf("queue长度:%d\r\n", queue.length);
	// printf("queue占用内存大小:%d\r\n", queue.memory_size);
	// printf("删除queue\r\n");
	// queue.delete(&queue);
	// printf("queue长度:%d\r\n", queue.length);
	// printf("queue占用内存大小:%d\r\n", queue.memory_size);

	// printf("******************************************************************************\r\n");

	// printf("stack长度:%d\r\n", stack.length);
	// printf("stack占用内存大小:%d\r\n", stack.memory_size);
	// printf("每个不带数据域的节点占用空间大小%d\r\n", sizeof(Node));

	// stack.push(&stack, "hello stack\0", 20);
	// stack.push(&stack, 123123, 0);
	// stack.push(&stack, "stack end\0", 10);

	// printf("stack长度:%d\r\n", stack.length);
	// printf("stack占用内存大小:%d\r\n", stack.memory_size);

	// printf("查看栈元素:%s\r\n", stack.get(&stack));
	// printf("stack长度:%d\r\n", stack.length);
	// printf("stack占用内存大小:%d\r\n", stack.memory_size);
	// printf("弹出栈元素\r\n");
	// stack.pop(&stack);
	// printf("查看栈元素:%d\r\n", stack.get(&stack));
	// printf("stack长度:%d\r\n", stack.length);
	// printf("stack占用内存大小:%d\r\n", stack.memory_size);
	// printf("弹出栈元素:%d\r\n", stack.pop(&stack));
	// printf("stack长度:%d\r\n", stack.length);
	// printf("stack占用内存大小:%d\r\n", stack.memory_size);
	// printf("删除stack\r\n");
	// stack.delete(&stack);
	// printf("stack长度:%d\r\n", stack.length);
	// printf("stack占用内存大小:%d\r\n", stack.memory_size);

	// printf("******************************************************************************\r\n");

	// while (state != -1) {
	// 			printf("*************Link Menu************\r\n");
	// 			printf("-1--------退出\r\n");
	// 			printf("0--------显示详细信息\r\n");
	// 			printf("1--------插入数据\r\n");
	// 			printf("2--------删除数据\r\n");
	// 			printf("3--------查询数据\r\n");
	// 			printf("4--------更新数据\r\n");
	// 			printf("5--------删除链表\r\n");
	// 			printf("6--------查找元素索引\r\n");
	// 			printf("**********************************\r\n");
	// 			scanf_s("%d", &state);
	// 			switch (state)
	// 			{
	// 			case 0:
	// 				printf("List长度:%d\r\n", list.length);
	// 				printf("List占用内存大小:%d\r\n", list.memory_size);
	// 				printf("每个不带数据域的节点占用空间大小%d\r\n", sizeof(Node));
	// 				break;

	// 			case 1:
	// 				printf("请选择插入位置\r\n");
	// 				scanf_s("%d", &where);
	// 				printf("请选择插入字符串还是整形数据：\r\n");
	// 				printf("0--------插入字符串\r\n");
	// 				printf("1--------插入整形数据\r\n");
	// 				scanf_s("%d", &witch);
	// 				if (witch == 0) {
	// 					printf("内存空间大小为0时采用数域据指针存储四个字节数据\r\n");
	// 					printf("请输入：字符串 保存该元素的内存空间大小(byte)\r\n");
	// 					scanf_s("%s", chars, 100);
	// 					scanf_s("%d", &witch);
	// 					chars[witch - 1] = '\0';
	// 					if(list.addAt(&list, where, chars, witch) == 1)
	// 					printf("插入成功\r\n");
	// 				}
	// 				else {
	// 					printf("内存空间大小为0时采用数域据指针存储四个字节数据\r\n");
	// 					printf("请输入：整形数据 保存该元素的内存空间大小(byte)\r\n");
	// 					scanf_s("%d %d", &data, &witch);				
	// 					if(list.addAt(&list, where, data, witch) == 1)
	// 					printf("插入成功\r\n");
	// 				}
	// 				break;

	// 			case 2:
	// 				printf("请选择删除位置\r\n");
	// 				scanf_s("%d", &where);
	// 				if (list.removeAt(&list, where) == 1)
	// 					printf("删除成功\r\n");
	// 				else
	// 					printf("删除失败\r\n");
	// 				break;

	// 			case 3:
	// 				printf("请选择查询位置\r\n");
	// 				scanf_s("%d", &where);
	// 				printf("请选择查询字符串还是整形数据：\r\n");
	// 				printf("0--------查询字符串\r\n");
	// 				printf("1--------查询整形数据\r\n");
	// 				scanf_s("%d", &witch);
	// 				if (witch == 0) {
	// 					printf("List元素%d:%s\r\n", where, list.get(&list, where));
	// 				}
	// 				else {
	// 					printf("List元素%d:%d\r\n", where, list.get(&list, where));
	// 				}
	// 				break;

	// 			case 4:
	// 				printf("请选择更新位置\r\n");
	// 				scanf_s("%d", &where);
	// 				printf("请选择更新为字符串还是整形数据：\r\n");
	// 				printf("0--------更新为字符串\r\n");
	// 				printf("1--------更新为整形数据\r\n");
	// 				scanf_s("%d", &witch);
	// 				if (witch == 0) {
	// 					printf("内存空间大小为0时采用数域据指针存储四个字节数据\r\n");
	// 					printf("请输入：字符串 保存该元素的内存空间大小(byte)\r\n");
	// 					scanf_s("%s", chars, 100);
	// 					scanf_s("%d", &witch); chars[witch - 1] = '\0';
	// 					if (list.set(&list, where, chars, witch) == 1)
	// 						printf("更新成功\r\n");
	// 					else
	// 						printf("更新失败\r\n");
	// 				}
	// 				else {
	// 					printf("内存空间大小为0时采用数域据指针存储四个字节数据\r\n");
	// 					printf("请输入：整形数据 保存该元素的内存空间大小(byte)\r\n");
	// 					scanf_s("%d %d", &data, &witch);
	// 					if (list.set(&list, where, data, witch) == 1)
	// 						printf("更新成功\r\n");
	// 					else
	// 						printf("更新失败\r\n");
	// 				}
	// 				break;

	// 			case 5:
	// 				if (list.delete(&list) == 1)
	// 					printf("删除成功\r\n");
	// 				else
	// 					printf("删除失败\r\n");
	// 				break;

	// 			case 6:
	// 				printf("请选择从何处开始查询\r\n");
	// 				scanf_s("%d", &where);
	// 				printf("请选择查询字符串还是整形数据：\r\n");
	// 				printf("0--------查询字符串\r\n");
	// 				printf("1--------查询整形数据\r\n");
	// 				scanf_s("%d", &witch);
	// 				if (witch == 0) {
	// 					printf("请输入：字符串 保存该元素的内存空间大小(byte)\r\n");
	// 					scanf_s("%s", chars, 100);
	// 					scanf_s("%d", &witch); chars[witch - 1] = '\0';
	// 					if (list.indexFrom(&list, where, chars, witch) != -1)
	// 						printf("%s的索引为：%d\r\n", chars, list.indexFrom(&list, where, chars, witch) != -1);
	// 					else
	// 						printf("查找失败\r\n");
	// 				}
	// 				else {
	// 					printf("请输入：整形数据 保存该元素的内存空间大小(byte)\r\n");
	// 					scanf_s("%d %d", &data, &witch);
	// 					if (list.indexFrom(&list, where, data, witch) != -1)
	// 						printf("%d的索引为：%d\r\n", data, list.indexFrom(&list, where, data, witch) != -1);
	// 					else
	// 						printf("查找失败\r\n");
						
	// 				}
	// 				break;

	// 			case -1:
	// 				witch = -1;
	// 				break;

	// 			default:
	// 				printf("请输入正确值!!!\r\n");
	// 				break;
	// 			}
	// 		}

	system("pause");
	return 0;
} 
