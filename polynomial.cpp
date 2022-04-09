#include "polynomial.hpp"
#include <stdio.h>
#include <malloc.h>
void Attach(int c,int e,Polynomial *pRear)
{
    Polynomial P;
    P=(Polynomial)malloc(sizeof(struct Node));
    P->Coefficient=c;
    P->Power=e;
    P->next=NULL;
    (*pRear)->next=P;
    *pRear=P;
}
Polynomial ReadPoly()
{
    int n;
    int c,e;
    scanf("%d",&n);
    Polynomial P=(Polynomial)malloc(sizeof(struct Node));
    P->next=NULL;
    Polynomial Rear;
    Rear=P;
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&c,&e);
        Attach(c,e,&Rear);
    }
    Polynomial t=P;
    P=P->next;
    return P;
}

Polynomial Add(Polynomial P1,Polynomial P2){
    Polynomial front,rear,temp;
    int sum;
    rear=(Polynomial)malloc(sizeof(struct Node));
    front=rear;
    while(P1&&P2){
        if(P1->Power>P2->Power){
            Attach(P1->Coefficient,P1->Power,&rear);
            P1=P1->next;
        }

        else if(P1->Power<P2->Power){
            Attach(P2->Coefficient,P2->Power,&rear);
            P2=P2->next;
        }
        else{
            sum=P1->Coefficient+P2->Coefficient;
            if(sum) Attach(sum,P1->Power,&rear);
            P1=P1->next;
            P2=P2->next;
        }
    }
    if(P1){
        while(P1){
        Attach(P1->Coefficient,P1->Power,&rear);
        P1=P1->next;
    }
    }
    if(P2){
        while(P2){
            Attach(P2->Coefficient,P2->Power,&rear);
            P2=P2->next;
        }
    }
    temp=front;
    front=front->next;
    free(temp);
    return front;
}

Polynomial Mult(Polynomial P1,Polynomial P2){
    Polynomial t,t1,t2,rear;
    int c,e;
    t1=P1;t2=P2;
    Polynomial P=(Polynomial)malloc(sizeof(Node));
    P->next=NULL;
    rear=P;//结果多项式带头结点
    if(!t1||!t2) return NULL;
    while(t2){
        c=t1->Coefficient*t2->Coefficient;
        e=t1->Power+t2->Power;
        Attach(c,e,&rear);
        t2=t2->next;
    }

    t1=t1->next;
    while(t1){
        t2=P2;
        while(t2){
            rear=P;
            c=t2->Coefficient*t1->Coefficient;
            e=t2->Power+t1->Power;
            while(rear->next&&rear->next->Power>e){
                rear=rear->next;
            }
            if(rear->next&&(rear->next->Power==e)){
                if(rear->next->Coefficient+c==0){
                    t=rear->next;
                    rear->next=t->next;
                    free(t);
                    }
                else{
                    rear->next->Coefficient+=c;
                }              
            }
            else{
                t=(Polynomial)malloc(sizeof(Node));
                t->next=rear->next;
                t->Coefficient=c;
                t->Power=e;
                rear->next=t;
            }
            t2=t2->next;
        }
        t1=t1->next;
    }

   t=P;
   P=P->next;
   free(t);
   return P;
//    Polynomial P, Rear, t1, t2, t;
//     int c, e;
//     P = (Polynomial)malloc(sizeof(Node));
//     P->next = NULL;
//     Rear = P;
//     t1 = P1;
//     t2 = P2;
//     // 若P1或P2为空,则返回null
//     if(!t1||!t2) return NULL;

//     // P1第一项乘以P2每一项, 放入P
//     while(t2){
//         c = t1->Coefficient * t2->Coefficient; //系数相乘,指数相加
//         e = t1->Power + t2->Power;
//         Attach(c, e, &Rear); 
//         t2 =  t2->next;
//     }
//     t1 = t1->next;// 从t1第二项开始,遍历t1和t2,得到结果与P比较,插入
   
//     while(t1){
//         t2 = P2;
//         Rear = P;
//         while(t2)
//         {
//             e = t1->Power + t2->Power;
//             c = t1->Coefficient * t2->Coefficient;
//             while (Rear->next && Rear->next->Power > e)
//             {// Rear一直移到 Rear所指的Node 的link所指的Node 的expon不大于e
//                 Rear =  Rear->next;  
//             }
//             if(Rear->next && Rear->next->Power == e)
//             { // 下一项的expon和e相等;
//                 if(Rear->next->Coefficient + c != 0)
//                 {  // 指数相加不为0
//                     Rear->next->Coefficient += c;  // 原指数加上新指数
//                 }
//                 else
//                 { // 指数相加等于0, 释放掉Rear->link所指的Node
//                     t = Rear->next;
//                     Rear->next = t->next;
//                     free(t);
//                 }
//             }else
//             {  // 小于e时,插入到Rear的后面,下一个Node的前面
//                 t= (Polynomial)malloc(sizeof(Node));
//                 t->Coefficient = c;
//                 t->Power = e;
//                 t->next = Rear->next;  // t的link指向Rear指向的后一个结点
//                 Rear->next = t;     // 连上t
//                 Rear = Rear->next; // Rear往后移
//             }
//             t2 = t2->next;
//         }
//         t1 = t1->next;
//     }
//     // 释放空结点
//     t = P;
//     P = P->next;
//     free(t);
//     return P;
  
}

void PrintPoly(Polynomial P){
    int flag=0;
    if(!P) {
        printf("0 0\n");return;}
    while(P){
        if(!flag)   flag=1;
        else
            printf(" ");
        printf("%d %d",P->Coefficient,P->Power);
        P=P->next;
    }
    printf("\n");
}
