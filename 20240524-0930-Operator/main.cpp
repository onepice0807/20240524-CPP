#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
	int _type;
	string _name;

public:
	Animal(int type, string name)
		:_type(type), _name(name) {}

	int GetType() {
		return _type;
	}

	void Speak() {
		cout << _name << "���մϴ�." << endl;
	}
};

class Pig : public Animal {
public:
	Pig(string name)
		:Animal(0, "����") {}

	void Speak() {
		cout << _name << "�� �ܲ��մϴ�." << endl;
	}

};

class Cow : public Animal {
public:
	Cow(string name)
		:Animal(1, "��") {}

	void Speak() {
		cout << _name << "�� �����մϴ�." << endl;
	}

};

class Chicken : public Animal {
public:
	Chicken(string name)
		:Animal(2, "��") {}

	void Speak() {
		cout << _name << "�� ������ �մϴ�." << endl;
	}

};

void InvokeSpeak(Animal* panimal) {
	switch (panimal->GetType()) {
	case 0:
		((Pig*)panimal)->Speak(); // �ٿ� ĳ����
		break;
	case 1:
		((Cow*)panimal)->Speak(); // �ٿ� ĳ����
		break;
	case 2:
		((Chicken*)panimal)->Speak(); // �ٿ� ĳ����
		break;
	default:
		cout << "Ÿ���� �߸� �Ǿ����ϴ�" << endl;
		break;
	}
}

int main() {
	Pig pig1("����1");
	Pig pig2("����2");
	Pig pig3("����3");

	Cow cow1("��1");
	Cow cow2("��2");
	Cow cow3("��3");

	Chicken chicken1("��1");
	Chicken chicken2("��2");
	Chicken chicken3("��3");

	// ���϶�� ����� ������ ���
	// ��ü�� �����ϴ� ���
	// 1. ������ ��ü���� ����� ����
	cout << "1. ������ ��ü���� ���" << endl;
	pig1.Speak();
	pig2.Speak();
	pig3.Speak();

	cow1.Speak();
	cow2.Speak();
	cow3.Speak();

	chicken1.Speak();
	chicken2.Speak();
	chicken3.Speak();

	// 2. ������ Ÿ�Կ� �迭�� ����� ó��
	cout << endl;
	cout << "2. ������ Ÿ�Կ� �迭�� ����� ó��" << endl;
	Pig* pigArray[3] = { &pig1,&pig2 ,&pig3 };
	Cow* cowArray[3] = { &cow1,&cow2 ,&cow3 };
	Chicken* chickenArray[3] = { &chicken1,&chicken2 ,&chicken3 };

	for (int i = 0; i < 3; i++) {
		pigArray[i]->Speak();
		cowArray[i]->Speak();
		chickenArray[i]->Speak();
	}

	// 3. ��ӿ� ���� ��ĳ����(UpCasting)�� ����� ����ؼ� �θ�Ÿ���� �迭�� �����
	// �ڽ��� ��ü���� �ϰ������� �����ؼ� ó��
	cout << endl;
	cout << "3. ��ĳ����(UpCasting) ó��" << endl;
	Animal* panimal[9] = { &pig1, &cow1, &chicken1, &pig2, &cow2, &chicken2, &pig3, &cow3, &chicken3 };
	
	for (int i = 0; i < 9; i++) {
		panimal[i]->Speak();
	}

	for (int i = 0; i < 9; i++) {
		InvokeSpeak(panimal[i]);
	}


	return 0;
}
