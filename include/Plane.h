#ifndef PLANE_H
#define PLANE_H
#include <fstream>
#include <iostream>
#include"Vector.h"
#include"List.h"
#include<math.h>
using namespace std;

#define PI 3.1415926
#define Ts 0.1//��������

struct Coordinate//����
{
	double x;
	double y;
	double z;
};

struct velocity//����
{
	double x;
	double y;
	double z;
};

class Plane
{
	private:
		List<int> FlyPlane;//�ɻ�
		Vector<double> X,Y,Z;//�ɻ�����ά����
		velocity init_v;//��ʼ�ٶȣ���λ��Km/h��
		velocity RealTime_v;//ʵʱ�ٶȣ���λ��Km/h��
		double acceleration=0;//���ٶ�(��λ��Km/h/h)
		double R;//�뾶����λ��Km��
		Coordinate RealTime_c;//�ɻ���ʵʱ����(��λ��Km��
		double T;//�ɻ����е�ʱ��(��λ��h��
		int N=0;//Vector<double> X,Y,Z�Ĺ�ģ
		int order[100];//��ʼ�켣����
		int s=0;//����order�ĳ���

	public:

		Plane();
		Plane(Coordinate c,velocity v);
		virtual ~Plane();

	public:
		void linear(Coordinate c0,velocity v0,double t);//����ֱ���˶�
		void ualinear(Coordinate c0,velocity v0,double t,double a);//�����˶�
		void ucirculcar(Coordinate c0,velocity v0,double t,double r);//�����˶�
		void track(int x);//�ɻ������ֹ켣
		void show();//����ɻ���ʱ��������
		void plot();//���λ��Ʒɻ��켣
		void writefile();//���ɻ���ά����ֱ�д��out.txt�ļ���
		void deletrack(int i);//ɾ����i�ι켣
		void addtrack(int i,int j);//�ڵ�i�ι켣����ӹ켣j
		void gettrack();//����켣
		void puttrack();//����켣����
		void updata_c(Coordinate _c);//����λ�ú��ٶ�
		void assignment(int n,Coordinate _c);//����ɢ�������걣�浽X,Y,Z��

	protected:

};

#endif // PLANE_H
