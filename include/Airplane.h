#ifndef AIRPLANE_H
#define AIRPLANE_H
//#include"List.h"
#include"Vector.h"

class Airplane
{
	private:
		Vector<double> X(1000,0,0),Y(1000,0,0),Z(1000,0,0);//�ɻ�����ά����
		// X(1000,0,0),Y(1000,0,0),Z(1000,0,0);//�ɻ�����ά����
        double A,V,VX,VZ,VY;//���ٶȣ��ٶ�
        double XX,YY,ZZ;//�ɻ���ʵʱ����
        double T;//�ɻ����е�ʱ��
	    int N=0;

	public:

		Airplane();
		Airplane(double x0,double y0,double z0,double vx,double vy,double vz);
		virtual ~Airplane();
    void linear(double x0,double y0,double z0,double vx,double vy,double vz,double t);
    int ualinear(double x0,double y0,double z0,double vx,double vy,double vz,double t,double a);
	int ucirculcar(double x0,double y0,double z0,double v,double t,double r);
	void track(int x);
	void show();
	int size()
	{
		return X.size();
	}
	int count()
	{
		return N;
	}
	protected:


};

#endif // AIRPLANE_H
