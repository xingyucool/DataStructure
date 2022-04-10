#include <stdio.h>
typedef struct Node{
    int data;
    int next;
    int address;
}Node;
int main(){
    Node List[100001],L[100001];
    int head,n,k;
    scanf("%d %d %d",&head,&n,&k);
    for(int i=0;i<n;i++){
        Node p;
        scanf("%d %d %d",&p.address,&p.data,&p.next);
        List[p.address]=p;
    }//建立数组存放多个静态链表
   
	int j =head,i=0;  //找到head为头结点的单链表
	while(j!=-1){
		L[i++]=List[j];
		j=List[j].next;
	}
	n=i;//链表长度，输入节点有些不在head链表上。

	for(int i=0;i<n/k;i++){  //数组逆转
		for(int j=0;j<k/2;j++){
			Node p;
			p=L[j+i*k];
			L[j+i*k]=L[k-1-j+i*k];
			L[k-1-j+i*k]=p;
		}
	}

    for(int i=0;i<n;i++){
    if(i!=n-1){
        L[i].next=L[i+1].address;//指针域赋值
        printf("%05d %d %05d\n",
        L[i].address,
        L[i].data,L[i].next);    
    }
    else{
            L[i].next=-1;
            printf("%05d %d %d\n",L[i].address,
            L[i].data,L[i].next);    
    }
        }
}