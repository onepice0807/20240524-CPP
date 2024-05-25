#include <iostream>
#include <string>

using namespace std;

// 포함

class Heart {
private:
	float _purseRate;

public:
	Heart(float purseRate)
		: _purseRate(purseRate)
	{
		cout << "Heart 생성자" << endl;
	}
	
	~Heart() {
		cout << "Heart 소멸자" << endl;
	}

	void Check() {
		cout << "심장이" << _purseRate << " /min으로 뛰고 있습니다" << endl;
	}
};

class Watch {
private:
	string _color;

public:
	Watch(string color)
		: _color(color)
	{
		cout << "Watch 생성자" << endl;
	}

	~Watch() {
		cout << "Watch 소멸자" << endl;
	}

	string GetColor() {
		return _color;
	}
	
	void ShowTime() {
		cout << _color << " 시계의 현재시간은 12:00입니다" << endl;
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
		cout << _name << "Human 생성자" << endl;
	}

	~Human() {
		cout << "Human 소멸자" << endl;
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
	Watch redWatch("빨간색");

	cout << "------------------- 프로그램 시작 ----------------------" << endl;
	{
		Human human("human", 70.0f, redWatch);

		human.CheckHeart();
		human.DisplayTime();
	}

	cout << "------------------- 프로그램 종료 ----------------------" << endl;

	return 0;
}