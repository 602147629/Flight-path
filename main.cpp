//����һ�ηɻ��ķ��й켣��������ӻ���ɾ��ĳһС�ι켣��
//���Բ�������ֱ���˶��������˶��������˶�
//����ά����д��txt�ļ�����
//Author:Shenbaoyin & PangHongli & XuChensong Time:2018/05/24
#include <iostream>
#include "Plane.h"
using namespace std;

int main()
{
	Plane P1;
	P1.gettrack();//��ʼ���켣
	P1.addtrack(3,2);//���һ���켣
	P1.puttrack();//����켣����
	P1.deletrack(2);//ɾ��һ���켣
	P1.puttrack();
	P1.plot();//�켣�����
	P1.show();//����켣��
	P1.writefile();//����ά����д��txt�ļ�����

	return 0;
}
