//����ʵ��a+b 
//��������������Base1��Base2��Ȼ������������ఴ�չ��з�ʽ��������Derived��
//����������඼���԰���һ�����г�Աx������Base1��Base2���н���һ�����Ͳ����Ĺ��캯����
//Derived�Ĺ��캯������Base1��Base2�Ķ�������a��b����ʼ��Derived����󣬲���xΪBase1::x��Base2::x֮�͡�

#include "stdafx.h"

#include <iostream>
using namespace std;

struct Base1
{
	int x;
	Base1(int x);
};

struct Base2
{
	int x;
	Base2(int x);
};

struct Derived :public Base1, public Base2
{
	int x;
	Derived(Base1& a, Base2& b);
};

//��ʵ��Base1��Base2, Derived�Ĺ��캯��
Base1::Base1(int a) :x(a) {}
Base2::Base2(int a) :x(a) {}
Derived::Derived(Base1& a, Base2 &b) : Base1(a.x), Base2(b.x), x(a.x + b.x) {}

int main()
{
	int x, y;
	cin >> x >> y;
	Base1 a(x);
	Base2 b(y);
	Derived d(a, b);
	cout << d.Base1::x << "+" << d.Base2::x << "=" << d.x << endl;
	return 0;
}
