#ifndef LIST_H
#define LIST_H
#define Posi(T) ListNode<T>*//�б�ڵ�
typedef int Rank;//��
#include<stdlib.h>
template <typename T>
struct ListNode//�б�ڵ�ģ���ࣨ��˫��������ʽʵ�֣�
{
	T data;//��ֵ
	Posi(T) pred;//ǰ��
	Posi(T) succ;//���
	ListNode() {}//���header��trailer�Ĺ���
	ListNode(T e,Posi(T) p=NULL,Posi(T) s=NULL)
	{
		data=e;
		pred=p;
		succ=s;
	}//Ĭ�Ϲ�����
	Posi(T) insertAsPred(T const& e);//ǰ����
	Posi(T) insertAsSucc(T const& e);//�����
};



template<typename T>
class List//�б�ģ����
{
	private:
		int _size;//��ģ
		Posi(T) header;//ͷ�ڱ�
		Posi(T) trailer;//β�ڱ�

	protected:
		void init();//���б���ʱ�ĳ�ʼ��
		int clear();//������нڵ�
		void copyNodes(Posi(T),int);//�����б�����λ��p���n��
		void merge(Posi(T)&,int,List<T>&,Posi(T),int);//�����б�����鲢
		void mergesort(Posi(T)&,int);//�Դ�p��ʼ������n���ڵ�鲢����
		void selectionsort(Posi(T),int);//�Դ�p��ʼ������n���ڵ�ѡ������
		void insertionsort(Posi(T),int);//�Դ�p��ʼ������n���ڵ��������

	public:
		//���캯��
		List()
		{
			init();//Ĭ��
		}
		List(List<T> const& L);//���帴���б�L
		List(List<T> const& L,Rank r,int n);//�����б�L����r���n��
		List(Posi(T) p,int n);//�����б�����λ��p���n��

		//��������
		~List()
		{
			clear();
			delete header;
			delete trailer;
		}// �ͷ����нڵ�

		//ֻ�����ʽӿ�
		Rank size() const
		{
			return _size;//��ģ
		}
		bool empty() const
		{
			return _size<=0;//�п�
		}
		T& operator[](Rank r) const;//���أ�֧��ѭ�ȷ���
		Posi(T) first() const
		{
			return header->succ;//�׽ڵ�λ��
		}
		Posi(T) last() const
		{
			return trailer->pred;//β�ڵ�λ��
		}
		bool valid(Posi(T) p)//�ж�λ��p�����Ƿ�Ϸ�
		{
			return p&&(trailer!=p)&&(header!=p);//��ͷβ�ڵ��ͬ��NULL
		}
		int disordered() const;//�ж��б��Ƿ�������
		Posi(T) find(T const& e) const//�����б����
		{
			return find(e,_size,trailer);
		}
		Posi(T) find(T const& e,int n,Posi(T) p) const;//�����������
		Posi(T) search(T const& e) const//�����б����
		{
			return search(e,_size,trailer);
		}
		Posi(T) search(T const& e,int n,Posi(T) p) const;//�����������
		Posi(T) selectMax(Posi(T) p,int n);//��p����n-1�������ѡ�������
		Posi(T) selectMax()//���������
		{
			return selectMax(header->succ,_size);
		}

		//��д���ʽӿ�
		Posi(T) insertAsFirst(T const& e);//��e�����׽ڵ����
		Posi(T) insertAsLast(T const& e);//��e����ĩ�ڵ����
		Posi(T) insertBefore(Posi(T) p,T const& e);//��e����p��ǰ������
		Posi(T) insertAfter(Posi(T) p,T const& e);//��e����p�ĺ�̲���
		void remove(Posi(T) p);//ɾ��p���Ľڵ�
		void merge(List<T>& L)
		{
			merge(first(),size,L,L.first(),L,_size);//ȫ�б�鲢
		}
		void sort(Posi(T) p,int n);//�б���������
		void sort()
		{
			sort(first(),_size);//�б���������
		}
		int deduplicate();//����ȥ��
		int uniquify();//����ȥ��

	    //����
	void traverse(void(*)(T&));//������ʹ�ú���ָ�룬ֻ����ֲ����޸ģ�
    template <typename VST> //������
    void traverse(VST&);//������ʹ�ú������󣬿�ȫ�����޸ģ�
};//List

template<typename T>
void List<T>::init()//��ʼ���������б����ʱͳһ����
{
	header=new ListNode<T>;//����ͷ�ڱ��ڵ�
	trailer=new ListNode<T>;//����β�ڱ��ڵ�
	header->succ=trailer;
	header->pred=NULL;//����
	trailer->pred=header;
	trailer->succ=NULL;//����
	_size=0;//��¼��ģ
}

template <typename T>
T& List<T>::operator[](Rank r)const//O(r)Ч�ʵ���
{
	Posi(T) p=first();//���׽ڵ����
	while(0<r--)
	{
		p=p->succ;//˳����r���ڵ�
	}
	return p->data;//Ŀ��ڵ�
}//��һ�ڵ���ȣ��༴��ǰ������

template <typename T>//�������б��ڽڵ�p��n��ǰ���У��ҵ�����e�������
Posi(T) List<T>::find(T const& e,int n,Posi(T) p) const
{
	while(0<n--)//��������
	{
		if(e==(p=p->pred)->data) return p;
	}
	return NULL;
}//ʧ�ܣ�����NULL

template <typename T>
Posi(T) List<T>::insertAsFirst(T const& e)
{
	_size++;
	return header->insertAsSucc(e);
}//e�����׽ڵ����

template <typename T>
Posi(T) List<T>::insertAsLast(T const& e)
{
	_size++;
	return trailer->insertAsPred(e);
}//e����β�ڵ����

template <typename T>
Posi(T) List<T>::insertBefore(Posi(T) p,T const& e)
{
	_size++;
	return p->insertAsPred(e);
}//e����p��ǰ������

template <typename T>
Posi(T) List<T>::insertAfter(Posi(T) p,T const& e)
{
	_size++;
	return p->insertAsSucc(e);
}//e����p�ĺ�̲���

template <typename T>
Posi(T) ListNode<T>::insertAsPred(T const& e)//ǰ��
{
	Posi(T) x=new ListNode(e,pred,this);//�����½ڵ�
	pred->succ=x;
	pred=x;//������������
	return x;//�����½ڵ�
}

template <typename T>
Posi(T) ListNode<T>::insertAsSucc(T const& e)//���
{
	Posi(T) x=new ListNode(e,this,succ);//�����½ڵ�
	succ->pred=x;
	succ=x;//������������
	return x;//�����½ڵ�
}

template <typename T>//�����б�����λ��p���n��
void List<T>::copyNodes(Posi(T) p,int n)
{
	init();//
	while(n--)
	{
		insertAsLast(p->data);
		p=p->succ;
	}
}

template<typename T>
List<T>::List(Posi(T) p,int n)//�����б�����λ��p���n��
{
	copyNodes(p,n);
}

template<typename T>
List<T>::List(List<T> const& L)//���������б�L
{
	copyNodes(L.first(),L._size);
}

template<typename T>
List<T>::List(List<T> const& L,int r,int n)//����L���Ե�r�����n��
{
	copyNodes(L[r],n);
}

template<typename T>
void List<T>::remove(Posi(T) p)//ɾ��p���ڵ㣬��������ֵ
{
	//T e=p->data;//����
	p->pred->succ=p->succ;//���
	p->succ->pred=p->pred;//ǰ��
	delete p;//ɾ���ڵ�
	_size--;//���¹�ģ
	//return e;//���ر��ݵ�ֵ
}

template<typename T>
int List<T>::clear()//����б�
{
	int oldSize=_size;
	while(0<_size)remove(header->succ);//����ɾ���׽ڵ�
	return oldSize;
}

template<typename T>
int List<T>::deduplicate()//����Ψһ��
{
	if(_size<2) return 0;
	int oldSize=_size;//
	Posi(T) p=header;
	Rank r=0;
	while(trailer!=(p=p->succ))
	{
		Posi(T) q=find(p->data,r,p);//��p��r��ǰ����Ѱ����ͬ��
		q?remove(q):r++;
	}
	return oldSize-_size;
}

template <typename T>
void List<T>::traverse(void (*visit)(T&))//������ʹ�ú���ָ�룬ֻ����ֲ����޸ģ�
{
	for(Posi(T) p=header->succ;p!=trailer;p=p->succ)
	{
		visit(p->data);
	}
}

template <typename T> template <typename VST>
void List<T>::traverse(VST& visit)//������ʹ�ú������󣬿�ȫ�����޸ģ�
{
	for(Posi(T) p=header->succ;p!=trailer;p=p->succ)
	{
		visit(p->data);
	}
}

template<typename T>
int List<T>::uniquify()//����Ψһ��
{
	if(_size<2) return 0;
	int oldSize=_size;//
	Posi(T) p,q;//����ָ����ڵĸ��Խڵ�
	for(p=header,q=p->succ;trailer!=q;p=q,q=q->succ)//��������ɨ��
	{
		if(p->data==q->data)
		{
			remove(q);
			q=p;
		}//��p��q��ͬ��ɾ������
	}
	return oldSize-_size;
}

template <typename T>
Posi(T) List<T>::search(T const& e,int n,Posi(T) p) const//�������
{
	while(0<=n--)//��������
	{
		if(((p=p->pred)->data)<=e) break;
	}
	return p;//���ز�����ֹ��λ��
}

template <typename T>
void List<T>::sort(Posi(T) p,int n)//�б�����
{
	switch (rand()%3)
	{
		case 1:insertionsort(p,n);break;
		case 2:selectionsort(p,n);break;
		default:mergesort(p,n);break;
	}
}

template <typename T>
void List<T>::insertionsort(Posi(T) p,int n)//�б��������
{
	for(int r=0;r<n;r++)//��һΪ���ڵ�
	{
		insertAfter(search(p->data,r,p),p->data);//�����ʵ���λ�ò�����
		p=p->succ;
		remove(p->pred);//ת����һ���ڵ�
	}
}

template <typename T>
void List<T>::selectionsort(Posi(T) p,int n)//�б�ѡ������
{
	Posi(T) head=p->pred;
	Posi(T) tail=p;
	for(int i=0;i<n;i++)
	{
		tail=tail->succ;
	}//���������䣨head,tail��
	while(1<n)
	{
		Posi(T) max=selectMax(head->succ,n);//�ҳ������
		insertBefore(tail,remove(max));//����������������ĩβ
		tail=tail->pred;
		n--;
	}
}

template <typename T>
Posi(T) List<T>::selectMax(Posi(T) p,int n)//����ʼ��p��n��Ԫ����ѡ�������
{
	Posi(T) max=p;
	for(Posi(T) cur=p;1<n;n--)
	{
		if(!lt((cur=cur->succ)->data,max->data))
		{
			max=cur;
		}
	}
	return max;
}

template <typename T>
void List<T>::merge(Posi(T)& p,int n,List<T>& L,Posi(T) q,int m)//�����б�Ĺ鲢
{
	Posi(T) pp=p->pred;
	while(0<m)
	{
		if((0<n)&&(p->data<=q->data))
		{
			if(q==(p=p->succ))break;
			n--;
		}
		else
		{
			insertBefore(p,L.remove((q=q->succ)->pred));
			m--;
		}
	}
	p=pp->succ;
}

template <typename T>
void List<T>::mergesort(Posi(T)& p,int n)//�����б�Ĺ鲢�����㷨
{
	if(n<2) return;
	int m=n>>1;
	Posi(T) q=p;
	for(int i=0;i<m;i++)
	{
		q=q->succ;
	}
	mergesort(p,m);
	mergesort(q,n-m);
	merge(p,m,*this,q,n-m);//
}

#endif // LIST_H
