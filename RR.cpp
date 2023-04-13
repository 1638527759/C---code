#include <stdio.h>
#include <stdlib.h>
struct PCB
{
    int pid;          // ���̱�ʶ��
    int rr;           // ������ʱ��
    int time;         // ����Ҫ������ʱ��
    char sta;         // ���̵�״̬
    struct PCB *next; // ����ָ��
};
struct PCB pcb1, pcb2, pcb3, pcb4, pcb5, *tail, *head, *rp;
void init() // ��ʼ���������̵�����ʱ��
{
    int time;
    pcb1.pid = 1;
    pcb2.pid = 2;
    pcb3.pid = 3;
    pcb4.pid = 4;
    pcb5.pid = 5;
    pcb1.rr = pcb2.rr = pcb3.rr = pcb4.rr = pcb5.rr = 0;
    pcb1.sta = pcb2.sta = pcb3.sta = pcb4.sta = pcb5.sta = 'w';
    printf("���������p1��Ҫ���е�ʱ��:");
    scanf("%d", &time);
    pcb1.time = time;
    printf("���������p2��Ҫ���е�ʱ��:");
    scanf("%d", &time);
    pcb2.time = time;
    printf("���������p3��Ҫ���е�ʱ��:");
    scanf("%d", &time);
    pcb3.time = time;
    printf("���������p4��Ҫ���е�ʱ��:");
    scanf("%d", &time);
    pcb4.time = time;
    printf("���������p5��Ҫ���е�ʱ��:");
    scanf("%d", &time);
    pcb5.time = time;
    pcb1.next = &pcb2;
    pcb2.next = &pcb3;
    pcb3.next = &pcb4;
    pcb4.next = &pcb5;
    pcb5.next = &pcb1;
    head = &pcb1;
    tail = &pcb5;
}
void printf1() // ��ʾ��ͷ
{
    printf("+---------------|---------------|---------------|---------------+\n");
    printf("|\tpid\t|\trr\t|\ttime\t|\tSTA\t|\n");
    printf("|---------------|---------------|---------------|---------------|\n");
}
void printf2() // ��ʾ�������̵ĳ�ʼ״̬
{
    printf("processes p%d running\n", head->pid);
    printf1();
    printf("|\t%d\t|\t%d\t|\t%d\t|\t%c\t|\n", head->pid, head->rr, head->time, head->sta);
    printf("|---------------|---------------|---------------|---------------|\n");
    rp = head;
    while (rp != tail)
    {
        rp = rp->next;
        printf("|\t%d\t|\t%d\t|\t%d\t|\t%c\t|\n", rp->pid, rp->rr, rp->time, rp->sta);
        printf("|---------------|---------------|---------------|---------------|\n");
    }
}
void operation() // ����
{
    int flag = 1;
    while (flag <= 5)
    {
        head->rr++;
        if ((head->rr == head->time) || (head->time == 0))
        {
            tail->sta = 'w'; // ������״̬����Ϊ�ȴ�̬
            head->sta = 'f'; // ������״̬����Ϊִ��̬
            printf2();
            head = head->next;
            tail->next = head;
            flag++;
        }
        else
        {
            tail->sta = 'w'; // ������״̬����Ϊ�ȴ�̬
            head->sta = 'r'; // ������״̬����Ϊ����̬
            printf2();
            tail = head;
            head = head->next;
        }
    }
}
int main(void)
{
    init();
    printf2();
    operation();
}
