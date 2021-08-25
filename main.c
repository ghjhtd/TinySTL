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

	List list = new_List(1024);     //�ڴ�����Ϊ1k
	Queue queue = new_Queue(1024);  //�ڴ�����Ϊ1k
	Stack stack = new_Stack(1024);  //�ڴ�����Ϊ1k
	Map map = new_Map(1024);        //�ڴ�����Ϊ1k

	printf("Tinyϵ�����ݽṹ�򵥲��ԣ�-----------------------------------------\r\n");
	Tiny_List tiny_list = new_TinyList(1024, 6);
	Tiny_Queue tiny_queue = new_TinyQueue(1024, 0);
	Tiny_Stack tiny_stack = new_Tiny_Stack(1024, 0);
	Tiny_Map tiny_map = new_Tiny_Map(1024, 0, 0);

	printf("-------------------Tiny_List----------------------\r\n");
	printf("length: %d\r\n", tiny_list.length);
	printf("mem_size: %d�ֽ�\r\n", tiny_list.memory_size);
	tiny_list.add(&tiny_list, &a);
	tiny_list.add(&tiny_list, &b);
	printf("0: %d\r\n", *(int*)tiny_list.get(&tiny_list, 0));
	printf("1: %d\r\n", *(int*)tiny_list.get(&tiny_list, 1));
	printf("length: %d\r\n", tiny_list.length);
	printf("mem_size: %d�ֽ�\r\n", tiny_list.memory_size);

	printf("-------------------Tiny_Queue----------------------\r\n");
	printf("length: %d\r\n", tiny_queue.length);
	printf("mem_size: %d�ֽ�\r\n", tiny_queue.memory_size);
	tiny_queue.push(&tiny_queue, 111);
	tiny_queue.push(&tiny_queue, 222);
	printf("0: %d\r\n", tiny_queue.get(&tiny_queue));
	tiny_queue.pop(&tiny_queue);
	printf("1: %d\r\n", tiny_queue.get(&tiny_queue));
	printf("length: %d\r\n", tiny_queue.length);
	printf("mem_size: %d�ֽ�\r\n", tiny_queue.memory_size);

	printf("-------------------Tiny_Stack----------------------\r\n");
	printf("length: %d\r\n", tiny_stack.length);
	printf("mem_size: %d�ֽ�\r\n", tiny_stack.memory_size);
	tiny_stack.push(&tiny_stack, 111);
	tiny_stack.push(&tiny_stack, 222);
	printf("0: %d\r\n", tiny_stack.get(&tiny_stack));
	tiny_stack.pop(&tiny_stack);
	printf("1: %d\r\n", tiny_stack.get(&tiny_stack));
	printf("length: %d\r\n", tiny_stack.length);
	printf("mem_size: %d�ֽ�\r\n", tiny_stack.memory_size);

	printf("-------------------Tiny_Map----------------------\r\n");
	printf("length: %d\r\n", tiny_map.length);
	printf("mem_size: %d�ֽ�\r\n", tiny_map.memory_size);
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
	printf("mem_size: %d�ֽ�\r\n", tiny_map.memory_size);


	printf("��data_size��key_sizeΪ0ʱ�����ݱ����ڽڵ������ָ���У������⿪���ڴ�ռ�\r\n");
	while(1){
		printf("��ѡ����Ҫ�������ֽṹ��\r\n");
		printf("0--------����\r\n");
		printf("1--------����\r\n");
		printf("2--------ջ\r\n");
		printf("3--------Map����\r\n");
		scanf_s("%d", &state);
		switch (state)
		{
		case 0:
			printf("*************Link Menu************\r\n");
			printf("-1--------�˳�\r\n");
			printf("0--------��ʾ��ϸ��Ϣ\r\n");
			printf("1--------������β���������\r\n");
			printf("2--------������ָ��λ���������\r\n");
			printf("3--------��������ָ��λ�õ�ֵ\r\n");
			printf("4--------ɾ������β��������\r\n");
			printf("5--------ɾ������ָ��λ�õ�����\r\n");
			printf("6--------ȡ��ָ��Ԫ������\r\n");
			printf("7--------��index����ʼȡ��Ԫ������\r\n");
			printf("8--------��ȡ��������Ԫ��\r\n");
			printf("9--------��ȡ��������Ԫ�صĴ�С\r\n");
			printf("10-------ɾ�����������ͷ��ڴ�ռ�\r\n");
			printf("**********************************\r\n");
			while (state != -1) {
				scanf_s("%d", &state);
				switch (state)
				{
				case 0:
					printf("list����:%d\r\n", list.length);
					printf("listռ���ڴ��С:%d\r\n", list.memory_size);
					printf("ÿ������������Ľڵ�ռ�ÿռ��С%d\r\n", sizeof(Node));
					printf("*************Link Menu************\r\n");
					printf("-1--------�˳�\r\n");
					printf("0--------��ʾ��ϸ��Ϣ\r\n");
					printf("1--------������β���������\r\n");
					printf("2--------������ָ��λ���������\r\n");
					printf("3--------��������ָ��λ�õ�ֵ\r\n");
					printf("4--------ɾ������β��������\r\n");
					printf("5--------ɾ������ָ��λ�õ�����\r\n");
					printf("6--------ȡ��ָ��Ԫ������\r\n");
					printf("7--------��index����ʼȡ��Ԫ������\r\n");
					printf("8--------��ȡ��������Ԫ��\r\n");
					printf("9--------��ȡ��������Ԫ�صĴ�С\r\n");
					printf("10-------ɾ�����������ͷ��ڴ�ռ�\r\n");
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
							printf("����ɹ�\r\n");
					}
					else {
						scanf_s("%s", chars, 200);
						if (list.add(&list, chars, data_size) == 1)
							printf("����ɹ�\r\n");
					}
					break;

				case 2:
					printf("int addAt(List *list, unsigned int index, void* data��unsigned int data_size)\r\n");
					printf("index:\r\n");
					scanf_s("%d", &index);
					printf("data_size:\r\n");
					scanf_s("%d", &data_size);
					printf("data:\r\n");
					if (data_size == 0) {
						scanf_s("%d", &data);
						if (list.addAt(&list,index, data, data_size) == 1)
							printf("����ɹ�\r\n");
					}
					else {
						scanf_s("%s", chars, 200);
						if (list.addAt(&list,index, chars, data_size) == 1)
							printf("����ɹ�\r\n");
					}
					break;

				case 3:
					printf("int set(List *list, unsigned int index, void* data��unsigned int data_size)\r\n");
					printf("index:\r\n");
					scanf_s("%d", &index);
					printf("data_size:\r\n");
					scanf_s("%d", &data_size);
					printf("data:\r\n");
					if (data_size == 0) {
						scanf_s("%d", &data);
						if (list.set(&list,index, data, data_size) == 1)
							printf("����ɹ�\r\n");
					}
					else {
						scanf_s("%s", chars, 200);
						if (list.set(&list,index, chars, data_size) == 1)
							printf("����ɹ�\r\n");
					}
					break;

				case 4:
					printf("int remove(List *list)\r\n");
					if (list.remove(&list) == 1)
						printf("ɾ���ɹ�\r\n");
					break;

				case 5:
					printf("int removeAt(List *list, unsigned int index)\r\n");
					printf("index:\r\n");
					scanf_s("%d", &index);
					if (list.removeAt(&list,index) == 1)
						printf("ɾ���ɹ�\r\n");
					break;

				case 6:
					printf("int index(List *list, void* data, unsigned int data_size)\r\n");
					printf("data_size:\r\n");
					scanf_s("%d", &data_size);
					printf("data:\r\n");
					if (data_size == 0) {
						scanf_s("%d", &data);
						if (list.index(&list, data, data_size) != -1)
							printf("Ԫ��%d������Ϊ��%d\r\n", data, list.index(&list, data, data_size));
					}
					else {
						scanf_s("%s", chars, 200);
						if (list.index(&list, chars, data_size) != -1)
							printf("��Ԫ�ص�����Ϊ��%d\r\n", list.index(&list, chars, data_size));
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
							printf("Ԫ��%d������Ϊ��%d\r\n", data, list.indexFrom(&list, index, data, data_size));
					}
					else {
						scanf_s("%s", chars, 200);
						if (list.indexFrom(&list, index, chars, data_size) != -1)
							printf("��Ԫ�ص�����Ϊ��%d\r\n", list.indexFrom(&list, index, chars, data_size));
					}
					break;

				case 8:
					printf("void* get(List *list, unsigned int index)\r\n");
					printf("index:\r\n");
					scanf_s("%d", &index);
					data_size = list.getSize(&list, index);
					if (list.get(&list, index) != 0) {
						if (data_size == 0) {
							printf("��%d��Ԫ��Ϊ��%d  ,��Ԫ��ռ���ڴ�ռ��С��%d�ֽ�\r\n", index, list.get(&list, index), data_size);
						}
						else {
							datas = list.get(&list, index);
							printf("��%d��Ԫ��Ϊ��", index);
							for (i = 0; i < data_size; i++) {
								printf("%c", datas[i]);
							}
							printf("   ,��Ԫ��ռ���ڴ�ռ��С��% d�ֽ�\r\n", data_size);
						}
					}
					break;

				case 9:
					printf("void* getSize(List *list, unsigned int index)\r\n");
					printf("index:\r\n");
					scanf_s("%d", &index);
					printf("��%d��Ԫ��ռ���ڴ�ռ��С��%d�ֽ�\r\n", index, list.getSize(&list, index));
					break;
					

				case 10:
					if (list.delete(&list) == 1)
						printf("ɾ���ɹ�\r\n");
					break;
				case -1:
					state = -1;
					break;

				default:
					printf("��������ȷֵ!!!\r\n");
					break;
				}
			}
			break;

		case 1:
			printf("*************Queue Menu************\r\n");
			printf("-1--------�˳�\r\n");
			printf("0--------��ʾ��ϸ��Ϣ\r\n");
			printf("1--------���������������\r\n");
			printf("2--------�Ӷ����е�������\r\n");
			printf("3--------��ö�����Ԫ�ص�ֵ\r\n");
			printf("4--------��ö�����Ԫ����ռ�ڴ�ռ�Ĵ�С\r\n");
			printf("5--------ɾ������\r\n");
			printf("**********************************\r\n");
			while (state != -1) {
				scanf_s("%d", &state);
				switch (state)
				{
				case 0:
					printf("queue����:%d\r\n", queue.length);
					printf("queueռ���ڴ��С:%d\r\n", queue.memory_size);
					printf("ÿ������������Ľڵ�ռ�ÿռ��С%d\r\n", sizeof(Node));
					printf("*************Queue Menu************\r\n");
					printf("-1--------�˳�\r\n");
					printf("0--------��ʾ��ϸ��Ϣ\r\n");
					printf("1--------���������������\r\n");
					printf("2--------�Ӷ����е�������\r\n");
					printf("3--------��ö�����Ԫ�ص�ֵ\r\n");
					printf("4--------��ö�����Ԫ����ռ�ڴ�ռ�Ĵ�С\r\n");
					printf("5--------ɾ������\r\n");
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
							printf("����ɹ�\r\n");
					}
					else {
						scanf_s("%s", chars, 200);
						if (queue.push(&queue, chars, data_size) == 1)
							printf("����ɹ�\r\n");
					}
					break;

				case 2:
					printf("int pop(Queue *queue)\r\n");
					if (queue.pop(&queue) > 0)
						printf("�����ɹ�\r\n");
					break;

				case 3:
					printf("void* get(Queue *queue)\r\n");
					data_size = queue.getSize(&queue);
					if (queue.get(&queue) != 0) {
						if (data_size == 0) {
							printf("��%d��Ԫ��Ϊ��%d  ,��Ԫ��ռ���ڴ�ռ��С��%d�ֽ�\r\n", queue.length , queue.get(&queue), data_size);
						}
						else {
							datas = queue.get(&queue);
							printf("��%d��Ԫ��Ϊ��", queue.length);
							for (i = 0; i < data_size; i++) {
								printf("%c", datas[i]);
							}
							printf("  ,��Ԫ��ռ���ڴ�ռ��С��% d�ֽ�\r\n", data_size);
						}
					}
					break;

				case 4:
					printf("unsigned int getSize(Queue *queue)\r\n");
					data_size = queue.getSize(&queue);
					if (data_size != 0) {
						printf("��Ԫ��ռ���ڴ�ռ��С��%d�ֽ�\r\n", data_size);
					}
					break;

				case 5:
					printf("int delete(Queue *queue)\r\n");
					if (queue.delete(&queue) == 1)
						printf("ɾ���ɹ�\r\n");
					break;

				case -1:
					state = -1;
					break;

				default:
					printf("��������ȷֵ!!!\r\n");
					break;
				}
			}
			break;

		case 2:
			printf("*************Stack Menu************\r\n");
			printf("-1--------�˳�\r\n");
			printf("0--------��ʾ��ϸ��Ϣ\r\n");
			printf("1--------��ջ���������\r\n");
			printf("2--------��ջ�е�������\r\n");
			printf("3--------���ջ��Ԫ�ص�ֵ\r\n");
			printf("4--------���ջ��Ԫ����ռ�ڴ�ռ�Ĵ�С\r\n");
			printf("5--------ɾ��ջ\r\n");
			printf("**********************************\r\n");
			while (state != -1) {
				scanf_s("%d", &state);
				switch (state)
				{
				case 0:
					printf("stack����:%d\r\n", stack.length);
					printf("stackռ���ڴ��С:%d\r\n", stack.memory_size);
					printf("ÿ������������Ľڵ�ռ�ÿռ��С%d\r\n", sizeof(Node));
					printf("*************Stack Menu************\r\n");
					printf("-1--------�˳�\r\n");
					printf("0--------��ʾ��ϸ��Ϣ\r\n");
					printf("1--------��ջ���������\r\n");
					printf("2--------��ջ�е�������\r\n");
					printf("3--------���ջ��Ԫ�ص�ֵ\r\n");
					printf("4--------���ջ��Ԫ����ռ�ڴ�ռ�Ĵ�С\r\n");
					printf("5--------ɾ��ջ\r\n");
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
							printf("����ɹ�\r\n");
					}
					else {
						scanf_s("%s", chars, 200);
						if (stack.push(&stack, chars, data_size) == 1)
							printf("����ɹ�\r\n");
					}
					break;

				case 2:
					printf("int pop(Stack *stack)\r\n");
					if (stack.pop(&stack) > 0)
						printf("�����ɹ�\r\n");
					break;

				case 3:
					printf("void* get(Stack *stack)\r\n");
					data_size = stack.getSize(&stack);
					if (stack.get(&stack) != 0) {
						if (data_size == 0) {
							printf("��%d��Ԫ��Ϊ��%d  ,��Ԫ��ռ���ڴ�ռ��С��%d�ֽ�\r\n", stack.length, stack.get(&stack), data_size);
						}
						else {
							datas = stack.get(&stack);
							printf("��%d��Ԫ��Ϊ��", stack.length);
							for (i = 0; i < data_size; i++) {
								printf("%c", datas[i]);
							}
							printf("   ,��Ԫ��ռ���ڴ�ռ��С��% d�ֽ�\r\n", data_size);
						}
					}
					break;

				case 4:
					printf("unsigned int getSize(Stack *stack)\r\n");
					data_size = stack.getSize(&stack);
					if (data_size != 0) {
						printf("��Ԫ��ռ���ڴ�ռ��С��%d�ֽ�\r\n", data_size);
					}
					break;

				case 5:
					printf("int delete(Stack *stack)\r\n");
					if (stack.delete(&stack) == 1)
						printf("ɾ���ɹ�\r\n");
					break;

				case -1:
					state = -1;
					break;

				default:
					printf("��������ȷֵ!!!\r\n");
					break;
				}
			}
			break;

		case 3:
			printf("*************Map Menu**************\r\n");
			printf("-1--------�˳�\r\n");
			printf("0--------��ʾ��ϸ��Ϣ\r\n");
			printf("1--------��Map�������������\r\n");
			printf("2--------ɾ��key��Ӧ�ļ�ֵ��\r\n");
			printf("3--------���Map��ֵ��Ӧ������Ԫ��ָ��\r\n");
			printf("4--------���Map����ֵ��Ӧ�ļ�ֵָ��\r\n");
			printf("5--------���Map��ֵ��Ӧ��Ԫ����ռ���ڴ��С\r\n");
			printf("6--------���Map����Ӧ��Ԫ����ռ���ڴ��С\r\n");
			printf("7--------����map��ֵ���ϣ�����������һ��������\r\n");
			printf("8--------����map�ļ�ֵ���ϣ�����������һ��������\r\n");
			printf("9--------ɾ��map����\r\n");
			printf("**********************************\r\n");
			while (state != -1) {
				scanf_s("%d", &state);
				switch (state)
				{
				case 0:
					printf("map����:%d\r\n", map.length);
					printf("mapռ���ڴ��С:%d\r\n", map.memory_size);
					printf("ÿ������������Ľڵ�ռ�ÿռ��С%d\r\n", sizeof(Node));
					printf("*************Map Menu**************\r\n");
					printf("-1--------�˳�\r\n");
					printf("0--------��ʾ��ϸ��Ϣ\r\n");
					printf("1--------��Map�������������\r\n");
					printf("2--------ɾ��key��Ӧ�ļ�ֵ��\r\n");
					printf("3--------���Map��ֵ��Ӧ������Ԫ��ָ��\r\n");
					printf("4--------���Map����ֵ��Ӧ�ļ�ֵָ��\r\n");
					printf("//5--------���Map��ֵ��Ӧ��Ԫ����ռ���ڴ��С\r\n");
					printf("//6--------���Map����Ӧ��Ԫ����ռ���ڴ��С\r\n");
					printf("//7--------����map��ֵ���ϣ�����������һ��������\r\n");
					printf("//8--------����map�ļ�ֵ���ϣ�����������һ��������\r\n");
					printf("9--------ɾ��map����\r\n");
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
								printf("����ɹ�\r\n");
						}
						else {
							if (map.push(&map, keys, key_size, data, data_size) == 1)
								printf("����ɹ�\r\n");
						}
					}
					else {
						scanf_s("%s", chars, 200);
						if (key_size == 0) {
							if (map.push(&map, key, key_size, chars, data_size) == 1)
								printf("����ɹ�\r\n");
						}
						else {
							if (map.push(&map, keys, key_size, chars, data_size) == 1)
								printf("����ɹ�\r\n");
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
							printf("�����ɹ�\r\n");
						else
							printf("�Ҳ���\r\n");
					}
					else {
						printf("key:\r\n");
						scanf_s("%s", keys, 200);
						if (map.remove(&map, keys, key_size) == 1)
							printf("�����ɹ�\r\n");
						else
							printf("�Ҳ���\r\n");
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
								printf("��Ԫ��Ϊ��%d  ,��Ԫ��ռ���ڴ�ռ��С��%d�ֽ�\r\n", map.get(&map, key, key_size), data_size);
							}
							else {
								datas = map.get(&map, key, key_size);
								printf("��Ԫ��Ϊ��");
								for (i = 0; i < data_size; i++) {
									printf("%c", datas[i]);
								}
								printf("   ,��Ԫ��ռ���ڴ�ռ��С��% d�ֽ�\r\n", data_size);
							}
						}
					}
					else {
						scanf_s("%s", keys, 200);
						data_size = map.getSize(&map, keys, key_size);
						if (map.get(&map, keys, key_size) != 0) {
							if (data_size == 0) {
								printf("��Ԫ��Ϊ��%d  ,��Ԫ��ռ���ڴ�ռ��С��%d�ֽ�\r\n",map.get(&map, keys, key_size), data_size);
							}
							else {
								datas = map.get(&map, keys, key_size);
								printf("��Ԫ��Ϊ��");
								for (i = 0; i < data_size; i++) {
									printf("%c", datas[i]);
								}
								printf("   ,��Ԫ��ռ���ڴ�ռ��С��% d�ֽ�\r\n", data_size);
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
								printf("Ԫ��Ϊ��%d  ,��Ԫ��ռ���ڴ�ռ��С��%d�ֽ�\r\n", map.getKey(&map, key, key_size), data_size);
							}
							else {
								datas = map.getKey(&map, key, key_size);
								printf("Ԫ��Ϊ��");
								for (i = 0; i < data_size; i++) {
									printf("%c", datas[i]);
								}
								printf("   ,��Ԫ��ռ���ڴ�ռ��С��% d�ֽ�\r\n", data_size);
							}
						}
					}
					else {
						scanf_s("%s", keys, 200);
						data_size = map.getKeySize(&map, keys, key_size);
						if (map.getKey(&map, keys, key_size) != 0) {
							if (data_size == 0) {
								printf("Ԫ��Ϊ��%d  ,��Ԫ��ռ���ڴ�ռ��С��%d�ֽ�\r\n", map.getKey(&map, keys, key_size), data_size);
							}
							else {
								datas = map.getKey(&map, keys, key_size);
								printf("Ԫ��Ϊ��");
								for (i = 0; i < data_size; i++) {
									printf("%c", datas[i]);
								}
								printf("   ,��Ԫ��ռ���ڴ�ռ��С��% d�ֽ�\r\n", data_size);
							}
						}
					}
					break;

				case 9:
					printf("int delete(Map *map)\r\n");
					if (map.delete(&map) == 1)
						printf("ɾ���ɹ�\r\n");
					break;

				case -1:
					state = -1;
					break;

				default:
					printf("��������ȷֵ!!!\r\n");
					break;
				}
			}
			break;

		default:
			printf("��������ȷֵ!!!\r\n");
			break;
		}
	}
	// printf("List����:%d\r\n", list.length);
	// printf("Listռ���ڴ��С:%d\r\n", list.memory_size);
	// printf("ÿ������������Ľڵ�ռ�ÿռ��С%d\r\n", sizeof(Node));

	// list.add(&list,"hello\0",6);
	// list.add(&list, "world\0", 6);
	// list.add(&list, "hahahaha\0", 10);
	// list.add(&list, 123456, 0);
	// list.add(&list, -123456, 1000);


	// printf("ListԪ��0:%s\r\n", (char*)list.get(&list, 0));
	// printf("ListԪ��1:%s\r\n", list.get(&list, 1)); 
	// printf("ListԪ��2:%s\r\n", chars);
	// printf("ListԪ��3:%d\r\n", list.get(&list,3));
	// printf("ListԪ��4:%d\r\n", list.get(&list, 4));

	// printf("List����:%d\r\n", list.length);
	// printf("Listռ���ڴ��С:%d\r\n", list.memory_size);

	// printf("ɾ����2��Ԫ��\r\n");
	// list.removeAt(&list, 2);
	// printf("List����:%d\r\n", list.length);
	// printf("Listռ���ڴ��С:%d\r\n", list.memory_size);

	// list.set(&list, 2, 111111, 0);
	// printf("����ListԪ��2:%d\r\n", list.get(&list, 2));

	// printf("111111������:%d\r\n", list.index(&list, 111111, 0));

	// printf("List��ַ:%x\r\n",&list);

	// printf("*********************************************************************************\r\n");

	// printf("queue����:%d\r\n", queue.length);
	// printf("queueռ���ڴ��С:%d\r\n", queue.memory_size);
	// printf("ÿ������������Ľڵ�ռ�ÿռ��С%d\r\n", sizeof(Node));
	
	// queue.push(&queue, "hello queue\0", 20);
	// queue.push(&queue, 123123, 0);
	// queue.push(&queue, "queue end\0", 10);

	// printf("queue����:%d\r\n", queue.length);
	// printf("queueռ���ڴ��С:%d\r\n", queue.memory_size);

	// printf("�鿴����Ԫ��:%s\r\n", queue.get(&queue));
	// printf("queue����:%d\r\n", queue.length);
	// printf("queueռ���ڴ��С:%d\r\n", queue.memory_size);
	// printf("��������Ԫ��\r\n");
	// queue.pop(&queue);
	// printf("�鿴����Ԫ��:%d\r\n", queue.get(&queue));
	// printf("queue����:%d\r\n", queue.length);
	// printf("queueռ���ڴ��С:%d\r\n", queue.memory_size);
	// printf("��������Ԫ��:%d\r\n", queue.pop(&queue));
	// printf("queue����:%d\r\n", queue.length);
	// printf("queueռ���ڴ��С:%d\r\n", queue.memory_size);
	// printf("ɾ��queue\r\n");
	// queue.delete(&queue);
	// printf("queue����:%d\r\n", queue.length);
	// printf("queueռ���ڴ��С:%d\r\n", queue.memory_size);

	// printf("******************************************************************************\r\n");

	// printf("stack����:%d\r\n", stack.length);
	// printf("stackռ���ڴ��С:%d\r\n", stack.memory_size);
	// printf("ÿ������������Ľڵ�ռ�ÿռ��С%d\r\n", sizeof(Node));

	// stack.push(&stack, "hello stack\0", 20);
	// stack.push(&stack, 123123, 0);
	// stack.push(&stack, "stack end\0", 10);

	// printf("stack����:%d\r\n", stack.length);
	// printf("stackռ���ڴ��С:%d\r\n", stack.memory_size);

	// printf("�鿴ջԪ��:%s\r\n", stack.get(&stack));
	// printf("stack����:%d\r\n", stack.length);
	// printf("stackռ���ڴ��С:%d\r\n", stack.memory_size);
	// printf("����ջԪ��\r\n");
	// stack.pop(&stack);
	// printf("�鿴ջԪ��:%d\r\n", stack.get(&stack));
	// printf("stack����:%d\r\n", stack.length);
	// printf("stackռ���ڴ��С:%d\r\n", stack.memory_size);
	// printf("����ջԪ��:%d\r\n", stack.pop(&stack));
	// printf("stack����:%d\r\n", stack.length);
	// printf("stackռ���ڴ��С:%d\r\n", stack.memory_size);
	// printf("ɾ��stack\r\n");
	// stack.delete(&stack);
	// printf("stack����:%d\r\n", stack.length);
	// printf("stackռ���ڴ��С:%d\r\n", stack.memory_size);

	// printf("******************************************************************************\r\n");

	// while (state != -1) {
	// 			printf("*************Link Menu************\r\n");
	// 			printf("-1--------�˳�\r\n");
	// 			printf("0--------��ʾ��ϸ��Ϣ\r\n");
	// 			printf("1--------��������\r\n");
	// 			printf("2--------ɾ������\r\n");
	// 			printf("3--------��ѯ����\r\n");
	// 			printf("4--------��������\r\n");
	// 			printf("5--------ɾ������\r\n");
	// 			printf("6--------����Ԫ������\r\n");
	// 			printf("**********************************\r\n");
	// 			scanf_s("%d", &state);
	// 			switch (state)
	// 			{
	// 			case 0:
	// 				printf("List����:%d\r\n", list.length);
	// 				printf("Listռ���ڴ��С:%d\r\n", list.memory_size);
	// 				printf("ÿ������������Ľڵ�ռ�ÿռ��С%d\r\n", sizeof(Node));
	// 				break;

	// 			case 1:
	// 				printf("��ѡ�����λ��\r\n");
	// 				scanf_s("%d", &where);
	// 				printf("��ѡ������ַ��������������ݣ�\r\n");
	// 				printf("0--------�����ַ���\r\n");
	// 				printf("1--------������������\r\n");
	// 				scanf_s("%d", &witch);
	// 				if (witch == 0) {
	// 					printf("�ڴ�ռ��СΪ0ʱ���������ָ��洢�ĸ��ֽ�����\r\n");
	// 					printf("�����룺�ַ��� �����Ԫ�ص��ڴ�ռ��С(byte)\r\n");
	// 					scanf_s("%s", chars, 100);
	// 					scanf_s("%d", &witch);
	// 					chars[witch - 1] = '\0';
	// 					if(list.addAt(&list, where, chars, witch) == 1)
	// 					printf("����ɹ�\r\n");
	// 				}
	// 				else {
	// 					printf("�ڴ�ռ��СΪ0ʱ���������ָ��洢�ĸ��ֽ�����\r\n");
	// 					printf("�����룺�������� �����Ԫ�ص��ڴ�ռ��С(byte)\r\n");
	// 					scanf_s("%d %d", &data, &witch);				
	// 					if(list.addAt(&list, where, data, witch) == 1)
	// 					printf("����ɹ�\r\n");
	// 				}
	// 				break;

	// 			case 2:
	// 				printf("��ѡ��ɾ��λ��\r\n");
	// 				scanf_s("%d", &where);
	// 				if (list.removeAt(&list, where) == 1)
	// 					printf("ɾ���ɹ�\r\n");
	// 				else
	// 					printf("ɾ��ʧ��\r\n");
	// 				break;

	// 			case 3:
	// 				printf("��ѡ���ѯλ��\r\n");
	// 				scanf_s("%d", &where);
	// 				printf("��ѡ���ѯ�ַ��������������ݣ�\r\n");
	// 				printf("0--------��ѯ�ַ���\r\n");
	// 				printf("1--------��ѯ��������\r\n");
	// 				scanf_s("%d", &witch);
	// 				if (witch == 0) {
	// 					printf("ListԪ��%d:%s\r\n", where, list.get(&list, where));
	// 				}
	// 				else {
	// 					printf("ListԪ��%d:%d\r\n", where, list.get(&list, where));
	// 				}
	// 				break;

	// 			case 4:
	// 				printf("��ѡ�����λ��\r\n");
	// 				scanf_s("%d", &where);
	// 				printf("��ѡ�����Ϊ�ַ��������������ݣ�\r\n");
	// 				printf("0--------����Ϊ�ַ���\r\n");
	// 				printf("1--------����Ϊ��������\r\n");
	// 				scanf_s("%d", &witch);
	// 				if (witch == 0) {
	// 					printf("�ڴ�ռ��СΪ0ʱ���������ָ��洢�ĸ��ֽ�����\r\n");
	// 					printf("�����룺�ַ��� �����Ԫ�ص��ڴ�ռ��С(byte)\r\n");
	// 					scanf_s("%s", chars, 100);
	// 					scanf_s("%d", &witch); chars[witch - 1] = '\0';
	// 					if (list.set(&list, where, chars, witch) == 1)
	// 						printf("���³ɹ�\r\n");
	// 					else
	// 						printf("����ʧ��\r\n");
	// 				}
	// 				else {
	// 					printf("�ڴ�ռ��СΪ0ʱ���������ָ��洢�ĸ��ֽ�����\r\n");
	// 					printf("�����룺�������� �����Ԫ�ص��ڴ�ռ��С(byte)\r\n");
	// 					scanf_s("%d %d", &data, &witch);
	// 					if (list.set(&list, where, data, witch) == 1)
	// 						printf("���³ɹ�\r\n");
	// 					else
	// 						printf("����ʧ��\r\n");
	// 				}
	// 				break;

	// 			case 5:
	// 				if (list.delete(&list) == 1)
	// 					printf("ɾ���ɹ�\r\n");
	// 				else
	// 					printf("ɾ��ʧ��\r\n");
	// 				break;

	// 			case 6:
	// 				printf("��ѡ��Ӻδ���ʼ��ѯ\r\n");
	// 				scanf_s("%d", &where);
	// 				printf("��ѡ���ѯ�ַ��������������ݣ�\r\n");
	// 				printf("0--------��ѯ�ַ���\r\n");
	// 				printf("1--------��ѯ��������\r\n");
	// 				scanf_s("%d", &witch);
	// 				if (witch == 0) {
	// 					printf("�����룺�ַ��� �����Ԫ�ص��ڴ�ռ��С(byte)\r\n");
	// 					scanf_s("%s", chars, 100);
	// 					scanf_s("%d", &witch); chars[witch - 1] = '\0';
	// 					if (list.indexFrom(&list, where, chars, witch) != -1)
	// 						printf("%s������Ϊ��%d\r\n", chars, list.indexFrom(&list, where, chars, witch) != -1);
	// 					else
	// 						printf("����ʧ��\r\n");
	// 				}
	// 				else {
	// 					printf("�����룺�������� �����Ԫ�ص��ڴ�ռ��С(byte)\r\n");
	// 					scanf_s("%d %d", &data, &witch);
	// 					if (list.indexFrom(&list, where, data, witch) != -1)
	// 						printf("%d������Ϊ��%d\r\n", data, list.indexFrom(&list, where, data, witch) != -1);
	// 					else
	// 						printf("����ʧ��\r\n");
						
	// 				}
	// 				break;

	// 			case -1:
	// 				witch = -1;
	// 				break;

	// 			default:
	// 				printf("��������ȷֵ!!!\r\n");
	// 				break;
	// 			}
	// 		}

	system("pause");
	return 0;
} 
