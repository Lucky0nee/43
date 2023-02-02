#include <iostream>
#include <thread>
using namespace std;

class DigitalСounter {
public:
	DigitalСounter() {
		this->Min = 0;
		this->Max = 59;
		this->Current = 0;
	}
	DigitalСounter(int Min, int Max, int Current) {
		this->Min = Min;
		this->Max = Max;
		this->Current = Current;
	}

	void Set(int Min, int Max, int Current) {
		this->Min = Min;
		this->Max = Max;
		this->Current = Current;
	}

	void Increment() {
		if (this->Current == this->Max)
			this->Current = this->Min;
		else
			this->Current++;
	}

	int GetCurrentNum() {
		return this->Current;
	}

private:
	int Current;
	int Min;
	int Max;
};

int main() {
	DigitalСounter Counter;
	int Current, Min, Max; 
	cout << "Min number:"; cin >> Min;
	cout << "Max number:"; cin >> Max;
	cout << "Current number:"; cin >> Current;

	Counter.Set(Min, Max, Current);

	for (int i = 0; i < 60; i++) {
		system("cls");
		cout << Counter.GetCurrentNum(); //cout << "\n";
		Counter.Increment();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	return 0;
}
/*
Цифровий лічильник - це змінна з обмеженим діапазоном.
Його значення скидається,коли ціле значення досягає певного максимуму (наприклад, 59).
Лічильником є цифровий годинник.
Опишіть клас такого лічильника, в якому був би передбачений
конструктор. Надайте можливість встановити максимум і мінімум,
створіть метод 
збільшувати лічильник на 1,
метод, щоб повертати поточне значення.
*/
