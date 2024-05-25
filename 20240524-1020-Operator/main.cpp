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
	Watch& _refWatch; // agreggation 

public:
	Human(string _name, float purseRate, Watch& refWatch)
		: _name(_name), _heart(purseRate), _refWatch(refWatch)
	{
		cout << _name << "Human ������" << endl;
	}

	~Human() {
		cout << "Human �Ҹ���" << endl;
	}
	
	void DisplayTime() {
		cout << _name << " _ ";
		_refWatch.ShowTime();
	}

	void CheckHeart() {
		cout << _name << " _ ";
		_heart.Check();
	}

};

int main() {
	Watch redWatch("������");

	cout << "------------------- ���α׷� ���� ----------------------" << endl;
	{
		Human human("human", 70.0f, redWatch);

		human.CheckHeart();
		human.DisplayTime();
	}

	cout << "------------------- ���α׷� ���� ----------------------" << endl;

	return 0;
}