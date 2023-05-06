#include<iostream>
#include<stdlib.h>
using namespace std;

char finalsym;

typedef struct ListNode{		//结构体，双向循环链表 
	int data;
	struct ListNode *pre;
	struct ListNode *next;
}Node,*List;
 
void Init(List &L){		//双向循环链表的初始化 

	L = new Node;
	if(L){
		L->pre=L;
		L->next=L;
	}	
	else
		exit(0);
}

void Create(List &L, int &n){		//双向循环链表的建立,返回结点数n，留作下面比绝对值 
	int x;
	char d;
	List p=L;
	cin>>x;
	while((d=getchar())!='\n'){  //循环输入数值，遇到回车结束。 
		List q=new Node;
		n++;
		q->data=x;
		q->pre=p;
		q->next=L;
		p->next=q;
		L->pre=q;
		p=q;
		cin>>d;
		cin>>x;
	}
	    List q=new Node;  //将回车前输入的x值存入链表的结点。 
		n++;
		q->data=x;
		q->pre=p;
		q->next=L;
		p->next=q;
		L->pre=q;
		p=q;
}

void ListInsertT(List &L, int e){ //头部插入数值e 
	List s=new Node;
	s->data=e;
	s->next=L->next;
	s->pre=L;
	L->next->pre=s;
	L->next=s;
} 

void ListInsertW(List &L, int e){ //尾部插入数值e 
	List s=new Node;
	s->data=e;
	s->next=L;
	s->pre=L->pre;
	L->pre->next=s;
	L->pre=s;	
}

int Compare(List &L1,List &L2, int &n1, int &n2){   //绝对值比较两数大小  返回1代表L1>L2，返回-1代表L1<L2,返回0代表L1=L2; 
	if(n1>n2) return 1;
	else if(n1<n2) return -1;
	else {
		List p,q;
		p=L1->next;
		q=L2->next;
		while(p!=L1&&q!=L2&&p->data==q->data){
				p=p->next;
				q=q->next;
		}
		if(p->data>q->data) return 1;
		else if(p==L1) return 0;
		else return -1;
	}
}

void sub(List &L1,List &L2,List &L3){    //减法 
	List p=new Node;
	List q=new Node;
	int e;
	int jiewei=0;
	p=L1->pre;
	q=L2->pre;
	while(p!=L1&&q!=L2){ //L1，L2长度相等 
		e=p->data-q->data-jiewei;
		if(p->data < q->data){
			e=e+10000;
			jiewei=1;
		}
		else {
			jiewei=0;
		}
		ListInsertT(L3,e);
		p=p->pre;
		q=q->pre;
	} 
	while(p!=L1){ //L1比L2长 
		e=p->data-jiewei;
		if(e<0) {
			e=e+10000;
			jiewei=1;
		}
		else jiewei=0;
		ListInsertT(L3,e);
		p=p->pre;
	}
	while(q!=L2){ //L2比L1长 
		e=q->data-jiewei;
		if(e<0) {
			e=e+10000;
			jiewei=1;
		}
		else jiewei=0;
		ListInsertT(L3,e);
		q=q->pre;
	} 
}

void add(List &L1,List &L2,List &L3){	//加法 
	List p=new Node;
	List q=new Node;
	int e;
	int jinwei=0;
	p=L1->pre;
	q=L2->pre;
	while(p!=L1&&q!=L2){ //L1，L2长度相等 
		e=p->data+q->data+jinwei;
		if(e>=10000){
			jinwei=1;
			e=e-10000;			
		}
		else jinwei=0;
		ListInsertT(L3,e);
		p=p->pre;
		q=q->pre;
	}
	while(p!=L1){ //L1比L2长 
		e=p->data+jinwei;
		if(e>=10000){
			jinwei=1;
			e=e-10000;			
		}
		else jinwei=0;
		ListInsertT(L3,e);
		p=p->pre;
	} 
	while(q!=L2){ //L2比L1长 
		e=q->data+jinwei;
		if(e>=10000){
			jinwei=1;
			e=e-10000;			
		}
		else jinwei=0;
		ListInsertT(L3,e);
		q=q->pre;
	}
	if(jinwei==1) ListInsertT(L3,1);
}

void Select(List &A,List &B,List &C,int &n1, int &n2, char &sym1, char &sym2){  //运算方法判断选择 
	char symbol;
	cin>>symbol;
	int num=Compare(A,B,n1,n2);
	if(symbol=='+'){
		if(sym1=='+'&&sym2=='+'){
			//a+b算法 
			finalsym='+';
			add(A,B,C);
		}else if(sym1=='+'&&sym2=='-'){
			//compare A,B 
			if(num==1){            //A>B
			//a-b
			finalsym='+';    
			sub(A,B,C);
			}else if(num==-1){        //B>A
			//-(b-a)
			finalsym='-';
			sub(B,A,C);
			}else sub(A,B,C);
		}else if(sym1=='-'&&sym2=='+'){
			//compare A,B
			if(num==1){     //A>B:-(a-b)
			   finalsym='-';
			   sub(A,B,C);
			}else if(num==-1){    //B>A:b-a
			   finalsym='+';
			   sub(B,A,C);
		   }else sub(A,B,C);
		}else if(sym1=='-'&&sym2=='-'){
			//-(a+b)算法 
			finalsym='-';
			add(A,B,C);
		}
	}else if(symbol=='-'){
		if(sym1=='+'&&sym2=='+'){      
			//compare A,B
			if(num==1){         //A>B: a-b
			    finalsym='+';
			    sub(A,B,C);
		    }
			else if(num==-1){    //B>A: -(b-a)
			    finalsym='-';
			    sub(B,A,C);
	    	}else sub(A,B,C);
		}else if(sym1=='+'&&sym2=='-'){
		    //a+b
		    finalsym='+';
		    add(A,B,C);
		}else if(sym1=='-'&&sym2=='+'){
			//-(a+b)算法 
			finalsym='-';
			add(A,B,C);
		}else if(sym1=='-'&&sym2=='-'){
			//compare A,B
			if(num==1){      //A>B:-(a-b)
			    finalsym='-';
			    sub(A,B,C);
		    }
			else if(num==-1){    //B>A:b-a
			   finalsym='+';
			    sub(B,A,C);
		   }else sub(A,B,C);
		}
	}else{
		cout<<"输入错误，请重新输入:"<<endl; 
		Select(A,B,C,n1,n2,sym1,sym2);
	}
}

void Show(List &L){ //输出结果 
	Node *p;
 	if(NULL == L) return;
 	p=L->next;
 	while(p->data==0&&p->next!=L){  //结果中遇到数据为0的结点直接略过不输出，直到有数值的结点或尾节点 
 		p=p->next;
	 }
	 if(p->data==0&&p->next==L) {  //如果结果链表中数据全为0 
	 	cout<<"0";
	 	return;
	 }
	 cout<<p->data;  //第一个数作直接输出，无需在前添0； 
	 p=p->next;
	 if(p==L) return;  //如果p此时指向最后一个数 ，p->next为null，结束输出。 
	 else cout<<",";
 	while (1){       //循环输出剩余结点内容。 
 		if(p->data==0)    
 			cout<<"0000";
		else if(p->data<10)
			cout<<"000"<<p->data;
		else if(p->data<100)
			cout<<"00"<<p->data;
		else if(p->data<1000)
			cout<<"0"<<p->data;
  		else cout<<p->data;
  		p=p->next;
		if(p==L) break;
		cout<<",";
 	}
 	cout<<endl;
}

int main(){	 
    int n1=0,n2=0;
	List A,B,C; //定义链表A,B
	Init(A);
	Init(B);
	Init(C);  //相加的结果存入C链表 
	cout << "********************************************************************" << endl;
	cout << "*                      任意长的整数加减法运算                      *" << endl;
	cout << "********************************************************************" << endl;
	cout << endl;
	cout << "操作要求：" << endl;
	cout << "1.整型变量的范围：-（2^15 -1）~（2^15 -1）" << endl;
	cout << "2.输入形式每四组一位，组间用逗号分隔开，如1986,8213,1935,2736,3299" << endl;
	cout << endl;
	cout << "请输入第一个带符号位的整数(如-2345,6789或+1234,4567)：" << endl;
	//输入第一个长整数
	char sym1;
	while(1){
		cin>>sym1;
		if(sym1=='+'||sym1=='-') break;
		cout << "符号输入错误,请重输第一个整数!"<<endl;
		fflush(stdin); //清除输入 
	}
	Create(A,n1);
	cout << "请输入第二个带符号位的整数(如-2345,6789或+1234,4567)：" << endl;
	//输入第二个长整数 
	char sym2;
	while(1){ 
		cin>>sym2;
		if(sym2=='+'||sym2=='-') break;
		cout << "符号输入错误,请重输第一个整数!"<<endl;
		fflush(stdin); //清除输入 
	}	
	Create(B,n2);
	cout << "选择加法请输入+，选择减法请输入-（如+）："  << endl; 
	Select(A,B,C,n1,n2,sym1,sym2);
	//计算过程
	cout << "结果为："  << endl;
	if(finalsym=='-') cout<<finalsym;
	Show(C);
} 

