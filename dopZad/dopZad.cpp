// dopZad.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct EventSystem {
	void (*handlers[100])(const std::string&);

	int count = 0;
};

void registerHandler(EventSystem& system, void (*handler) (const std::string& message))
{
	if (system.count< 100)
	{
		system.handlers[system.count] = handler;
		system.count++;
	}
};

void triggerEvent(const EventSystem& system, const std::string& message)
{
	for (int i = 0; i < system.count; i++)
	{
		system.handlers[i](message);
	}

};
void onUserLogin(const std::string& message)
{
	std::cout << "sign in" <<" " <<message <<  std::endl;
};

void onUserLogout(const std::string& message)
{
	std::cout << "sign out" <<" " <<message <<  std::endl;
};

void onError(const std::string& message)
{
	std::cout << "Error" <<" " <<message<< std::endl;
};


int main()
{
	setlocale(0, "rus");
	std::cout << "привет" << std::endl;
	std::cout << std::endl;

	EventSystem testiki;


	registerHandler(testiki, onUserLogin);
	registerHandler(testiki, onUserLogout);
	registerHandler(testiki, onError);


	triggerEvent(testiki,"Заход 1");

	//triggerEvent(testiki);
	//triggerEvent(testiki);

	//triggerEvent(testiki, "giiii");
	//triggerEvent(testiki, "giiii");
	//triggerEvent(testiki, "giiii");



}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
