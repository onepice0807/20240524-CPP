#include <iostream>

using namespace std;

// UpCasting, DownCasting
// UpCasting: ��Ӱ��迡�� �θ��� ������ Ÿ������ �ڽ��� �޴� ��
// ����Ÿ��/������

class Parent {
public:
	int _pvalue;

public:
	Parent()
		: _pvalue(0) {}


	Parent(int pvalue)
		: _pvalue(pvalue) {}

	void ShowInfo() {
		cout << "Parent::_pvalue = " << _pvalue << endl;
	}

};

class Child : public Parent {
private:
	int _cvalue;

public:
	Child()
		: Parent(0), _cvalue(0) {}

	Child(int pvalue, int cvalue)
		: Parent(pvalue), _cvalue(cvalue) {}

	void ShowInfo() {
		cout << "Child::Parent::_pvalue = " << _pvalue << endl;
		cout << "Child::_cvalue = " << _cvalue << endl;
	}

};

int main() {
	Parent parent(5);
	Child child(10, 20);

	parent.ShowInfo();
	parent = child;
	parent.ShowInfo();

	// child = parent; // �θ�Ÿ���� �ڽ�Ÿ�Կ� ������ �� ����.

	// ��Ӱ��迡 �ִ� ������ Ÿ�԰�����
	// �θ��� ������ Ÿ�Կ� �ڽ��� ������ Ÿ���� ������ �� �ִ�.
	// ������ �ϰ� �Ǹ� �ڽ��� �����κ��� ���ǵǱ� ������
	// �׷��� ��ü�� ����Ÿ��, ������ Ÿ������ �����Ѵ�.
	// �θ��� ���������̳� ������ Ÿ�Կ� �ڽ��� ��ü�� �����ϴ� ���� UpCasting�̶�� �Ѵ�.

	cout << endl;
	cout << "��ĳ����(UpCasting)" << endl;
	cout << "����Ÿ������ ����" << endl;
	Parent& refp = child; // UpCasting
	refp.ShowInfo();

	// �θ��� Ÿ���� �ڽ��� Ÿ�Կ� �����ϴ� ���� �ٿ�ĳ����(DownCasting)
	// �ٿ�ĳ������ ��õ������ �۵��� �ȵȴ�.
	cout << endl;

	Child& refc = (Child&)refp; // �ٿ� ĳ����(�θ�Ÿ���� �ڽĿ� ����)

	refc.ShowInfo();

	cout << endl;
	cout << "�ٿ�ĳ����(DownCasting)" << endl;
	cout << "������ Ÿ������ ����" << endl;

	Parent* pparent = &child; // ��ĳ����(UpCasting)

	pparent->ShowInfo();

	Child* pchild = (Child*)pparent; // �ٿ�ĳ����(DownCasting)
	pchild->ShowInfo();

	return 0;
}