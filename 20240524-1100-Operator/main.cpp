#include <iostream>
#include <string>

using namespace std;

// ����

class Heart {
private:
	float _purseRate;

public:
	Heart(float purseRate)
		: _purseRate(purseRate)
	{
		cout << "Heart ������" << endl;
	}

	~Heart() {
		cout << "Heart �Ҹ���" << endl;
	}

	void Check() {
		cout << "������" << _purseRate << " /min���� �ٰ� �ֽ��ϴ�" << endl;
	}
};

class Watch {
private:
	string _color;

public:
	Watch(string color)
		: _color(color)
	{
		cout << "Watch ������" << endl;
	}

	~Watch() {
		cout << "Watch �Ҹ���" << endl;
	}

	string GetColor() {
		return _color;
	}

	void ShowTime() {
		cout << _color << " �ð��� ����ð��� 12:00�Դϴ�" << endl;
	}
};

class Human {
private:
	string _name;
	Heart _heart; // Composition
	Watch* _pWatch; // agreggation 

public:
	Human(string name, float purseRate, Watch* pWatch)
		: _name(name), _heart(purseRate), _pWatch(pWatch)
	{
		cout << _name << "Human ������" << endl;
	}

	~Human() {
		cout << "Human �Ҹ���" << endl;
	}

	void DisplayTime() {
		cout << _name << " _ ";
		_pWatch->ShowTime();
	}

	void ChangeWatch(Watch* pWatch) {
		_pWatch = pWatch;
	}

	void CheckHeart() {
		cout << _name << " _ ";
		_heart.Check();
	}

};

int main() {
	Watch redWatch("������");
	Watch blackWatch("������");

	cout << "------------------- ���α׷� ���� ----------------------" << endl;
	{
		Human human("human", 70.0f, &redWatch);

		human.CheckHeart();
		human.DisplayTime();

		human.ChangeWatch(&blackWatch);

		human.DisplayTime();
	}

	cout << "------------------- ���α׷� ���� ----------------------" << endl;

	return 0;
}