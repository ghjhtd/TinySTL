/*
 * @Author: gong hao jing
 * @Date: 2021-08-22 01:10:16
 * @LastEditTime: 2021-08-25 06:30:22
 * @LastEditors: Please set LastEditors
 * @Description: ����һ������Ƕ��ʽƽ̨��c�������ݽṹ��ļ�ʵ��
 * @FilePath: \TinySTL\TinySTL.h
 * @Description: 
 * �ÿ���������Ƹ߼�����oop�ĳ������˼�룬Ϊ������
 * Ƕ��ʽ�豸��ʹ�ã��Գ��õ����ݽṹ�����˼򵥵�ʵ��
 * 1. ��������
 * 2��������
 * 3��ջ
 * 4. Map����
 * 
 * @History 2021-08-24 01:00:01   v1.0    @by gonghaojing ����ʵ���˳������ݽṹ������TinySTL_Test.exe�����н��в��ԣ�����Ͳ����㷨��δʵ�� 
 * 
 * @History 2021-08-24 12:22:12   v1.1    @by gonghaojing ������һ���ÿ�Ĳ��Գ���(main.c)�����ڸÿ�ʹ���˽϶�ָ�룬��ָ���ǿ����Σ�գ����д��һ�����Գ�������debug����ֹ��Ƕ��ʽ�豸������ʱ��������
 * ����ʹ��TinySTL_Test.exe���в���
 * 
 * @History 2021-08-25 02:11:05   v2.0    @by gonghaojing ������Tiny_List,Tiny_Stack��һϵ�нṹ
 * 
 * Tiny_ ϵ�м̳���List,Stack�ȸ��࣬����Ľṹ���ǰ��һЩ���ݱ��淽ʽ�븸����ȫ��ͬ��
 * ���ڴ��У��̳��Ը����Tinyϵ����ǰ����ڴ����븸��һ�£���˿�����һ��������ָ��ָ���������ڴ棬
 * ����������ʹ��
 * Tiny_ ϵ��������һ��data_size�����ԣ��ڳ�ʼ��ʱָ��ÿ���ڵ������ڴ�ռ�,����ÿ���������
 * ʱָ����Ҫռ�õ��ڴ�ռ��Сʹ���ϱ����ĸ��෽������࣬
 * ��û�и�����ô���൱���ڳ�ʼ��ʱָ�����������ͣ����ַ��͵�ζ��
 * 
 * 
 */

/*********************----Warning!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!***************
* ��data_sizeΪ0ʱ���õ����������������ָ�룬����ʱû�п��ٶ���Ŀռ䣬�����ô�ָ�����������ݣ���˿���
* ֱ��ʹ����
* ����ָ��ռ���ĸ��ֽڣ����Ա����������͵������ĸ��ֽڣ�ֻҪע�Ᵽ���ȡ����ʱ�������ͬ�ĸ�ʽ�Ϳ���
* ���磬put(float),ȡ��ʱ�����ݷŵ�һ��float�ͱ�����Ϳ�����
* 
* ��data_size��Ϊ0ʱ���õ���ֻ��ָ���������һ��ָ�룬��ָ��ָ��һ���СΪdata_size�Ķ����ݿռ䣬ʹ��ʱҪ��ѭ
* ָ��ʹ�õ���ع���
* 
*/


#ifndef __TINYSTL_H
#define __TINYSTL_H
#include <stdlib.h>
#include <string.h>

void* new(unsigned int data_size);
void print_error(char *chars);  //�����ӡ��������.c�ļ�����ʵ��,����鿴������Ϣ

/**********************How to use******************
 * �½����ݽṹ���������ַ�ʽ��1������ջ�з����ڴ棬�ڶ����ǳ�������ʱ
 * �ڶ��з����ڴ�
 * 
 * ��data_size=0ʱ��ʹ��ÿ���ڵ��ָ���������ָ�������ݣ��ĸ��ֽڣ����������µ��ڴ�
 * ���Ҵ��������ֱ�ӱ����ڽڵ���
 * 
 * ��data_size��=0ʱ��������Ӧ���ڴ�ռ������������
 * ÿ���ڵ�ռ��12���ֽڵ��ڴ棬ÿ�����ݽṹ����ռ�ü�ʮ���ֽڵ�����
 * ���������Ϊһ��ָ�룬ָ����Ҫ��������ݵ��ڴ棬Ȼ���data_size���ֽ�
 * �����ݸ��Ƶ����ݽڵ��¿��ٵ��ڴ���
 * 
 * 1.ջ�����ڴ棨Demo����
 * List list = new_List(1024);     //�ڴ�����Ϊ1k
 * list.addAt(&list, index, data, data_size);
 * list.removeAt(&list, index);
 * list.get(&list, index);
 * list.set(&list, index, data, data_size);
 * 
 * 2.�ѷ����ڴ�
 * Map* map_ptr = (Map*)malloc(sizeof(Map));
 * (*map_ptr) = new_Map(1024);
 * map_ptr->push(map_ptr, 1, 0, "hello", 10);
 * (*map_ptr).push(map_ptr, 0, 0, "world", 10);
 * 
 * 
 * 
//---------------��������--------------------------
//�������˫����Ļ���������ܳ���ʱ����ҿ��Կ�ܶ࣬���ڴ�ռ�ýϴ�
//�ۺϿ�������Ƕ��ʽƽ̨��ѡ��ʵ��ռ���ڴ���Խ�С�ĵ�����

/***********************************************List����
* ���ԣ�
* length--------������
* memory_size---������ռ���ڴ�ռ�Ĵ�С����λ-�ֽ�
* memory_limit--���Ƹ�����ռ�ö����ڴ�ռ䣬��λ-�ֽ�
* 
* �������ϣ�                                           data_size = 0��ʱ��������ָ�������洢����
* List new_List(unsigned int memory_limit);                                                 //˫�������ʼ��

* void* get(List *list, unsigned int index);                                                //��ȡ��������Ԫ��
* unsigned int getSize(List *list, unsigned int index);                                     //��ȡ��������Ԫ�صĴ�С
* 
* int add(List *list, void* data, unsigned int data_size);                                  //������β���������
* int addAt(List *list, unsigned int index, void* data��unsigned int data_size);            //������ָ��λ���������
* int set(List *list, unsigned int index, void* data��unsigned int data_size);              //��������ָ��λ�õ�ֵ
* int remove(List *list);                                                                   //ɾ������β��������
* int removeAt(List *list, unsigned int index);                                             //ɾ������ָ��λ�õ�����
* int index(List *list, void* data, unsigned int data_size);                                //ȡ��ָ��Ԫ������
* int indexFrom(List *list, unsigned int index, void* data, unsigned int data_size);        //��index����ʼȡ��Ԫ������
* int delete_List(List* list);                                                              //ɾ�����������ͷ��ڴ�ռ�
* 
* unsigned int max(List *list��int (*compare)(void* first, void* second, unsigned int data_size));                         //��ȡ���Ԫ�ص����������Լ�ʵ�ֱȽϺ���
* unsigned int maxOf(List *list, unsigned int index��int (*compare)(void* first, void* second, unsigned int data_size));   //��ȡ��index��Ԫ�ص����������Լ�ʵ�ֱȽϺ���
* unsigned int min(List *list��int (*compare)(void* first, void* second, unsigned int data_size));                         //��ȡ��СԪ�ص����������Լ�ʵ�ֱȽϺ���
* unsigned int minOf(List *list, unsigned int index��int (*compare)(void* first, void* second, unsigned int data_size));   //��ȡ��indexСԪ�ص����������Լ�ʵ�ֱȽϺ���
*/

/***********************************************Queue����
* ���ԣ�
* length--------���г���
* memory_size---������ռ���ڴ�ռ�Ĵ�С����λ-�ֽ�
* memory_limit--���Ƹ�����ռ�ö����ڴ�ռ䣬��λ-�ֽ�
*
* �������ϣ�                                           data_size = 0��ʱ��������ָ�������洢���ݣ��ĸ��ֽڣ�
* Queue new_Queue(unsigned int memory_limit);                                                             //���г�ʼ��

* int push(Queue *queue, void* data, unsigned int data_size);                                             //���������������
* int pop(Queue *queue);                                                                                  //�Ӷ����е�������
* void* get(Queue *queue);                                                                                //��ö�����Ԫ�ص�ֵ
* unsigned int getSize(Queue *queue);                                                                     //��ö�����Ԫ����ռ�ڴ�ռ�Ĵ�С
* int delete(Queue *queue);                                                                               //ɾ������
*/

/***********************************************Stack����
* ���ԣ�
* length--------ջ����
* memory_size---������ռ���ڴ�ռ�Ĵ�С����λ-�ֽ�
* memory_limit--���Ƹ�����ռ�ö����ڴ�ռ䣬��λ-�ֽ�
*
* �������ϣ�               data_size = 0��ʱ��������ָ�������洢���ݣ��ĸ��ֽڣ�����Ϊ0ʱ�Զ�����data_size�ֽڴ�С�Ŀռ������������
* Stack new_Stack(unsigned int memory_limit);                                                             //ջ��ʼ��

* int push(Stack *stack, void* data, unsigned int data_size);                                             //��ջ���������
* int pop(Stack *stack);                                                                                  //��ջ�е�������
* void* get(Stack *stack);                                                                                //���ջ��Ԫ�ص�ֵ
* unsigned int getSize(Stack *stack);                                                                     //���ջ��Ԫ����ռ�ڴ�ռ�Ĵ�С
* int delete(Stack *stack);                                                                               //ɾ��ջ
*/

/***********************************************Map����
* ���ԣ�
* key_head-------������
* data_head------��ֵ����
* length--------Map���ϳ���
* memory_size---��Map����ռ���ڴ�ռ�Ĵ�С����λ-�ֽ�
* memory_limit--���Ƹ�Map����ռ�ö����ڴ�ռ䣬��λ-�ֽ�
*
* �������ϣ�               data_size��key_size = 0��ʱ��������ָ�������洢���ݣ��ĸ��ֽڣ�����Ϊ0ʱ�Զ�����data_size�ֽڴ�С�Ŀռ������������
* Stack new_Map(unsigned int memory_limit);                                                 //ջ��ʼ��
* 
* int push(Map* map, void* key, unsigned int key_size, void* data, unsigned int data_size);      //��Map�������������
* int remove(Map* map, void* key, unsigned int key_size);                                        //ɾ��key��Ӧ�ļ�ֵ��
* void* get(Map* map, void* key, unsigned int key_size);                                         //���Map��ֵ��Ӧ������Ԫ��ָ��
* void* getKey(Map* map, void* key, unsigned int key_size);                                      //���Map����ֵ��Ӧ�ļ�ֵָ��
* unsigned int getSize(Map* map, void* key, unsigned int key_size);                              //���Map��ֵ��Ӧ��Ԫ����ռ���ڴ��С
* unsigned int getKeySize(Map* map, void* key, unsigned int key_size);                           //���Map����Ӧ��Ԫ����ռ���ڴ��С
* List* values(Map* map);                                                                        //����map��ֵ���ϣ�����������һ��������
* List* keySet(Map* map);                                                                        //����map�ļ�ֵ���ϣ�����������һ��������
* int delete(Map* map);                                                                          //ɾ��map����
* 
*/

typedef struct node  //һ���ڵ�ռ��12�ֽڣ�data_size = 0��ʱ��������ָ�������洢����
{  
    //ѭ��˫����Ľ��ṹ   
    void* data;//������ָ��   
    struct node *next;//ָ��ǰ������һ���   
    unsigned int data_size;//���������ռ�ڴ�ռ�Ĵ�С,��ṹ���ڴ����ԣ�������Ϊ�ĸ��ֽ�
}Node;  

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++����
typedef struct List {
	struct node *head;                           //ͷָ�룬ָ��ͷ���   
    int length;                                  //����list�ĳ���                                                              
    unsigned int memory_size;                    //������ռ���ڴ�ռ�Ĵ�С����λ-�ֽ�
    unsigned int memory_limit;                   //���Ƹ�����ռ�ö����ڴ�ռ䣬��λ-�ֽ�
    
    int (*delete)(struct List* list);                                                              //ɾ�����������ͷ��ڴ�ռ�
    void* (*get)(struct List* list, unsigned int index);                                                //��ȡ��������Ԫ��
    unsigned int (*getSize)(struct List* list, unsigned int index);                                     //��ȡ��������Ԫ�صĴ�С
    int (*add)(struct List* list, void* data, unsigned int data_size);                                  //������β���������
    int (*addAt)(struct List* list, unsigned int index, void* data, unsigned int data_size);            //������ָ��λ���������
    int (*set)(struct List* list, unsigned int index, void* data, unsigned int data_size);              //��������ָ��λ�õ�ֵ
    int (*remove)(struct List* list);                                                                   //ɾ������β��������
    int (*removeAt)(struct List* list, unsigned int index);                                             //ɾ������ָ��λ�õ�����
    int (*index)(struct List* list, void* data, unsigned int data_size);                                //ȡ��ָ��Ԫ������
    int (*indexFrom)(struct List* list, unsigned int index, void* data, unsigned int data_size);        //��index����ʼȡ��Ԫ������
    unsigned int (*max)(struct List* list, int(*compare)(void* first, void* second, unsigned int data_size));                         //��ȡ���Ԫ�ص����������Լ�ʵ�ֱȽϺ���
    unsigned int (*maxOf)(struct List* list, unsigned int index, int(*compare)(void* first, void* second, unsigned int data_size));   //��ȡ��index��Ԫ�ص����������Լ�ʵ�ֱȽϺ���
    unsigned int (*min)(struct List* list, int(*compare)(void* first, void* second, unsigned int data_size));                         //��ȡ��СԪ�ص����������Լ�ʵ�ֱȽϺ���
    unsigned int (*minOf)(struct List* list, unsigned int index, int(*compare)(void* first, void* second, unsigned int data_size));   //��ȡ��indexСԪ�ص����������Լ�ʵ�ֱȽϺ���
}List;
List new_List(unsigned int memory_limit);                                                      //˫�������ʼ��

void* get_List(List* list, unsigned int index);                                                //��ȡ��������Ԫ��
unsigned int getSize_List(List* list, unsigned int index);                                     //��ȡ��������Ԫ�صĴ�С

int delete_List(List* list);                                                                   //ɾ�����������ͷ��ڴ�ռ�
int add_List(List* list, void* data, unsigned int data_size);                                  //������β���������
int addAt_List(List* list, unsigned int index, void* data, unsigned int data_size);            //������ָ��λ���������
int set_List(List* list, unsigned int index, void* data, unsigned int data_size);              //��������ָ��λ�õ�ֵ
int remove_List(List* list);                                                                   //ɾ������β��������
int removeAt_List(List* list, unsigned int index);                                             //ɾ������ָ��λ�õ�����
int index_List(List* list, void* data, unsigned int data_size);                                //ȡ��ָ��Ԫ������
int indexFrom_List(List* list, unsigned int index, void* data, unsigned int data_size);        //��index����ʼȡ��Ԫ������

unsigned int max_List(List* list, int(*compare)(void* first, void* second, unsigned int data_size));                         //��ȡ���Ԫ�ص����������Լ�ʵ�ֱȽϺ���
unsigned int maxOf_List(List* list, unsigned int index, int(*compare)(void* first, void* second, unsigned int data_size));   //��ȡ��index��Ԫ�ص����������Լ�ʵ�ֱȽϺ���
unsigned int min_List(List* list, int(*compare)(void* first, void* second, unsigned int data_size));                         //��ȡ��СԪ�ص����������Լ�ʵ�ֱȽϺ���
unsigned int minOf_List(List* list, unsigned int index, int(*compare)(void* first, void* second, unsigned int data_size));   //��ȡ��indexСԪ�ص����������Լ�ʵ�ֱȽϺ���


typedef struct Tiny_List {
    struct node* head;                           //ͷָ�룬ָ��ͷ���   
    int length;                                  //����list�ĳ���                                                              
    unsigned int memory_size;                    //������ռ���ڴ�ռ�Ĵ�С����λ-�ֽ�
    unsigned int memory_limit;                   //���Ƹ�����ռ�ö����ڴ�ռ䣬��λ-�ֽ�

    int (*delete)(struct Tiny_List* list);                                                                   //ɾ�����������ͷ��ڴ�ռ�
    void* (*get)(struct Tiny_List* list, unsigned int index);                                                //��ȡ��������Ԫ��
    unsigned int (*getSize)(struct Tiny_List* list, unsigned int index);                                     //��ȡ��������Ԫ�صĴ�С
    int (*add)(struct Tiny_List* list, void* data );                                  //������β���������
    int (*addAt)(struct Tiny_List* list, unsigned int index, void* data );            //������ָ��λ���������
    int (*set)(struct Tiny_List* list, unsigned int index, void* data );              //��������ָ��λ�õ�ֵ
    int (*remove)(struct Tiny_List* list);                                                                   //ɾ������β��������
    int (*removeAt)(struct Tiny_List* list, unsigned int index);                                             //ɾ������ָ��λ�õ�����
    int (*index)(struct Tiny_List* list, void* data );                                //ȡ��ָ��Ԫ������
    int (*indexFrom)(struct Tiny_List* list, unsigned int index, void* data );        //��index����ʼȡ��Ԫ������
    unsigned int (*max)(struct Tiny_List* list, int(*compare)(void* first, void* second ));                         //��ȡ���Ԫ�ص����������Լ�ʵ�ֱȽϺ���
    unsigned int (*maxOf)(struct Tiny_List* list, unsigned int index, int(*compare)(void* first, void* second ));   //��ȡ��index��Ԫ�ص����������Լ�ʵ�ֱȽϺ���
    unsigned int (*min)(struct Tiny_List* list, int(*compare)(void* first, void* second ));                         //��ȡ��СԪ�ص����������Լ�ʵ�ֱȽϺ���
    unsigned int (*minOf)(struct Tiny_List* list, unsigned int index, int(*compare)(void* first, void* second ));   //��ȡ��indexСԪ�ص����������Լ�ʵ�ֱȽϺ���

    unsigned int data_size;
}Tiny_List;

Tiny_List new_TinyList(unsigned int memory_limit, unsigned int data_size);                              //˫�������ʼ��

void* get_TinyList(Tiny_List* list, unsigned int index);                                                //��ȡ��������Ԫ��
unsigned int getSize_TinyList(Tiny_List* list, unsigned int index);                                     //��ȡ��������Ԫ�صĴ�С

int delete_TinyList(Tiny_List* list);                                                                   //ɾ�����������ͷ��ڴ�ռ�
int add_TinyList(Tiny_List* list, void* data );                                  //������β���������
int addAt_TinyList(Tiny_List* list, unsigned int index, void* data );            //������ָ��λ���������
int set_TinyList(Tiny_List* list, unsigned int index, void* data );              //��������ָ��λ�õ�ֵ
int remove_TinyList(Tiny_List* list);                                                                   //ɾ������β��������
int removeAt_TinyList(Tiny_List* list, unsigned int index);                                             //ɾ������ָ��λ�õ�����
int index_TinyList(Tiny_List* list, void* data );                                //ȡ��ָ��Ԫ������
int indexFrom_TinyList(Tiny_List* list, unsigned int index, void* data );        //��index����ʼȡ��Ԫ������

unsigned int max_TinyList(Tiny_List* list, int(*compare)(void* first, void* second ));                         //��ȡ���Ԫ�ص����������Լ�ʵ�ֱȽϺ���
unsigned int maxOf_TinyList(Tiny_List* list, unsigned int index, int(*compare)(void* first, void* second ));   //��ȡ��index��Ԫ�ص����������Լ�ʵ�ֱȽϺ���
unsigned int min_TinyList(Tiny_List* list, int(*compare)(void* first, void* second ));                         //��ȡ��СԪ�ص����������Լ�ʵ�ֱȽϺ���
unsigned int minOf_TinyList(Tiny_List* list, unsigned int index, int(*compare)(void* first, void* second ));   //��ȡ��indexСԪ�ص����������Լ�ʵ�ֱȽϺ���

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++����
typedef struct Queue
{
    struct node* head;                  //ͷָ�룬ָ��ͷ���   
    int length;                         //���еĳ���                                                              
    unsigned int memory_size;           //�ö���ռ���ڴ�ռ�Ĵ�С����λ-�ֽ�
    unsigned int memory_limit;          //���Ƹö���ռ�ö����ڴ�ռ䣬��λ-�ֽ�

    int (*push)(struct Queue* queue, void* data, unsigned int data_size);    //���������������
    int (*pop)(struct Queue* queue);                                       //�Ӷ����е�������
    void* (*get)(struct Queue* queue);                                       //�鿴������Ԫ�ص�ֵ
    unsigned int (*getSize)(struct Queue* queue);                            //�鿴������Ԫ����ռ�ڴ�ռ�Ĵ�С
    int (*delete)(struct Queue* queue);                                      //ɾ������ 
} Queue;

Queue new_Queue(unsigned int memory_limit);     //���г�ʼ��
int pop_Queue(Queue* queue);                  //�Ӷ����е�������
void* get_Queue(Queue* queue);                  //�鿴������Ԫ�ص�ֵ
unsigned int getSize_Queue(Queue* queue);       //�鿴������Ԫ����ռ�ڴ�ռ�Ĵ�С
int delete_Queue(Queue* queue);                 //ɾ���������в��ͷ��ڴ�ռ�


typedef struct Tiny_Queue
{
    struct node* head;                  //ͷָ�룬ָ��ͷ���   
    int length;                         //���еĳ���                                                              
    unsigned int memory_size;           //�ö���ռ���ڴ�ռ�Ĵ�С����λ-�ֽ�
    unsigned int memory_limit;          //���Ƹö���ռ�ö����ڴ�ռ䣬��λ-�ֽ�

    int (*push)(struct Tiny_Queue* queue, void* data);    //���������������
    int (*pop)(struct Tiny_Queue* queue);                                       //�Ӷ����е�������
    void* (*get)(struct Tiny_Queue* queue);                                       //�鿴������Ԫ�ص�ֵ
    unsigned int (*getSize)(struct Tiny_Queue* queue);                            //�鿴������Ԫ����ռ�ڴ�ռ�Ĵ�С
    int (*delete)(struct Tiny_Queue* queue);                                      //ɾ������ 
    unsigned int data_size;
} Tiny_Queue;

Tiny_Queue new_TinyQueue(unsigned int memory_limit, unsigned int data_size);     //���г�ʼ��
int add_Tiny_Queue(Tiny_Queue* queue, void *data);
int pop_Tiny_Queue(Tiny_Queue* queue);                  //�Ӷ����е�������
void* get_Tiny_Queue(Tiny_Queue* queue);                  //�鿴������Ԫ�ص�ֵ
unsigned int getSize_Tiny_Queue(Tiny_Queue* queue);       //�鿴������Ԫ����ռ�ڴ�ռ�Ĵ�С
int delete_Tiny_Queue(Tiny_Queue* queue);                 //ɾ���������в��ͷ��ڴ�ռ�
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ջ
typedef struct Stack
{
    struct node* head;                           //ͷָ�룬ָ��ͷ���   
    int length;                                  //ջ�ĳ���                                                              
    unsigned int memory_size;                    //��ջռ���ڴ�ռ�Ĵ�С����λ-�ֽ�
    unsigned int memory_limit;                   //���Ƹ�ջռ�ö����ڴ�ռ䣬��λ-�ֽ�

    int (*push)(struct Stack* stack, void* data, unsigned int data_size);   //��ջ���������
    int (*pop)(struct Stack* stack);                                      //��ջ�е�������
    void* (*get)(struct Stack* stack);                                      //���ջ��Ԫ�ص�ֵ
    unsigned int (*getSize)(struct Stack* stack);                           //���ջ��Ԫ����ռ�ڴ�ռ�Ĵ�С
    int (*delete)(struct Stack* stack);                                     //ɾ��ջ
} Stack;

Stack new_Stack(unsigned int memory_limit);      //ջ��ʼ��
int pop_Stack(Stack* stack);                   //��ջ�е�������
void* get_Stack(Stack* stack);                   //���ջ��Ԫ�ص�ֵ
unsigned int getSize_Stack(Stack* stack);        //���ջ��Ԫ����ռ�ڴ�ռ�Ĵ�С
int delete_Stack(Stack* stack);                      

typedef struct Tiny_Stack
{
    struct node* head;                           //ͷָ�룬ָ��ͷ���   
    int length;                                  //ջ�ĳ���                                                              
    unsigned int memory_size;                    //��ջռ���ڴ�ռ�Ĵ�С����λ-�ֽ�
    unsigned int memory_limit;                   //���Ƹ�ջռ�ö����ڴ�ռ䣬��λ-�ֽ�

    int (*push)(struct Tiny_Stack* stack, void* data);   //��ջ���������
    int (*pop)(struct Tiny_Stack* stack);                                      //��ջ�е�������
    void* (*get)(struct Tiny_Stack* stack);                                      //���ջ��Ԫ�ص�ֵ
    unsigned int (*getSize)(struct Tiny_Stack* stack);                           //���ջ��Ԫ����ռ�ڴ�ռ�Ĵ�С
    int (*delete)(struct Tiny_Stack* stack);                                     //ɾ��ջ

    unsigned int data_size;
} Tiny_Stack;

Tiny_Stack new_Tiny_Stack(unsigned int memory_limit, unsigned int data_size);      //ջ��ʼ��
int add_Tiny_Stack(Tiny_Stack* stack, void* data, unsigned int data_size);       //���Ԫ��
int   pop_Tiny_Stack(Tiny_Stack* stack);                   //��ջ�е�������
void* get_Tiny_Stack(Tiny_Stack* stack);                   //���ջ��Ԫ�ص�ֵ
unsigned int getSize_Tiny_Stack(Tiny_Stack* stack);        //���ջ��Ԫ����ռ�ڴ�ռ�Ĵ�С
int delete_Tiny_Stack(Tiny_Stack* stack);       

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++Map����
typedef struct Map
{
    List key_head;                               //��ͷָ�룬ָ��ͷ���   
    List data_head;                              //ֵͷָ�룬ָ��ͷ���   
    int length;                                  //Map���ϵĳ���                                                              
    unsigned int memory_size;                    //��Map����ռ���ڴ�ռ�Ĵ�С����λ-�ֽ�
    unsigned int memory_limit;                   //���Ƹ�Map����ռ�ö����ڴ�ռ䣬��λ-�ֽ�

    int (*push)(struct Map* map, void* key, unsigned int key_size, void* data, unsigned int data_size);      //��Map�������������
    int (*remove)(struct Map* map, void* key, unsigned int key_size);                                        //ɾ��key��Ӧ�ļ�ֵ��
    void* (*get)(struct Map* map, void* key, unsigned int key_size);                                         //���Map��ֵ��Ӧ������Ԫ��ָ��
    void* (*getKey)(struct Map* map, void* data, unsigned int data_size);                                      //���Map����ֵ��Ӧ�ļ�ֵָ��
    unsigned int (*getSize)(struct Map* map, void* key, unsigned int key_size);                              //���Map��ֵ��Ӧ��Ԫ����ռ���ڴ��С
    unsigned int (*getKeySize)(struct Map* map, void* key, unsigned int key_size);                           //���Map����Ӧ��Ԫ����ռ���ڴ��С
    List* (*values)(struct Map* map);                                                                        //����map��ֵ���ϣ�����������һ��������
    List* (*keySet)(struct Map* map);                                                                        //����map�ļ�ֵ���ϣ�����������һ��������
    int (*delete)(struct Map* map);                                                                          //ɾ��map���� 
} Map;

Map new_Map(unsigned int memory_limit);                                                      //ջ��ʼ��

int push_Map(Map* map, void* key, unsigned int key_size, void* data, unsigned int data_size);      //��Map�������������
int remove_Map(Map* map, void* key, unsigned int key_size);                                        //ɾ��key��Ӧ�ļ�ֵ��
void* get_Map(Map* map, void* key, unsigned int key_size);                                         //���Map��ֵ��Ӧ������Ԫ��ָ��
void* getKey_Map(Map* map, void* data, unsigned int data_size);                                      //���Map����ֵ��Ӧ�ļ�ֵָ��
unsigned int getSize_Map(Map* map, void* key, unsigned int key_size);                              //���Map��ֵ��Ӧ��Ԫ����ռ���ڴ��С
unsigned int getKeySize_Map(Map* map, void* key, unsigned int key_size);                           //���Map����Ӧ��Ԫ����ռ���ڴ��С
List* values_Map(Map* map);                                                                        //����map��ֵ���ϣ�����������һ��������
List* keySet_Map(Map* map);                                                                        //����map�ļ�ֵ���ϣ�����������һ��������
int delete_Map(Map* map);                                                                          //ɾ��map����


typedef struct Tiny_Map
{
    List key_head;                               //��ͷָ�룬ָ��ͷ���   
    List data_head;                              //ֵͷָ�룬ָ��ͷ���   
    int length;                                  //Map���ϵĳ���                                                              
    unsigned int memory_size;                    //��Map����ռ���ڴ�ռ�Ĵ�С����λ-�ֽ�
    unsigned int memory_limit;                   //���Ƹ�Map����ռ�ö����ڴ�ռ䣬��λ-�ֽ�

    int (*push)(struct Tiny_Map* map, void* key,void* data);      //��Map�������������
    int (*remove)(struct Tiny_Map* map, void* key);                                        //ɾ��key��Ӧ�ļ�ֵ��
    void* (*get)(struct Tiny_Map* map, void* key);                                         //���Map��ֵ��Ӧ������Ԫ��ָ��
    void* (*getKey)(struct Tiny_Map* map, void* data);                                      //���Map����ֵ��Ӧ�ļ�ֵָ��
    unsigned int (*getSize)(struct Tiny_Map* map, void* key);                              //���Map��ֵ��Ӧ��Ԫ����ռ���ڴ��С
    unsigned int (*getKeySize)(struct Tiny_Map* map, void* key);                           //���Map����Ӧ��Ԫ����ռ���ڴ��С
    List* (*values)(struct Tiny_Map* map);                                                                        //����map��ֵ���ϣ�����������һ��������
    List* (*keySet)(struct Tiny_Map* map);                                                                        //����map�ļ�ֵ���ϣ�����������һ��������
    int (*delete)(struct Tiny_Map* map);                                                                          //ɾ��map���� 

    unsigned int key_size;
    unsigned int data_size;
} Tiny_Map;

Tiny_Map new_Tiny_Map(unsigned int memory_limit, unsigned int key_size, unsigned int data_size);          //ջ��ʼ��

int push_Tiny_Map(Tiny_Map* map, void* key, void* data);      //��Map�������������
int remove_Tiny_Map(Tiny_Map* map, void* key);                                        //ɾ��key��Ӧ�ļ�ֵ��
void* get_Tiny_Map(Tiny_Map* map, void* key);                                         //���Map��ֵ��Ӧ������Ԫ��ָ��
void* getKey_Tiny_Map(Tiny_Map* map, void* data);                                      //���Map����ֵ��Ӧ�ļ�ֵָ��
unsigned int getSize_Tiny_Map(Tiny_Map* map, void* key);                              //���Map��ֵ��Ӧ��Ԫ����ռ���ڴ��С
unsigned int getKeySize_Tiny_Map(Tiny_Map* map, void* key);                           //���Map����Ӧ��Ԫ����ռ���ڴ��С
List* values_Tiny_Map(Tiny_Map* map);                                                                        //����map��ֵ���ϣ�����������һ��������
List* keySet_Tiny_Map(Tiny_Map* map);                                                                        //����map�ļ�ֵ���ϣ�����������һ��������
int delete_Tiny_Map(Tiny_Map* map);                                                                          //ɾ��map����


#endif 