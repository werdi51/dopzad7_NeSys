#include <iostream>
#include <vector>
#include <string>

struct Event
{
    void(*handler)(const std::string&);
    std::string mess;
};

struct EventSystem {
    std::vector<Event> handlers;
    int maxSize = 100;
    int nextIndex = 0; 
};

void registerHandler(EventSystem& system, void(*handler)(const std::string&), const std::string& message) {
    Event smgEvent;
    smgEvent.handler=handler;
    smgEvent.mess=message;
    system.handlers.push_back(smgEvent);
}

void triggerEvent(EventSystem& system) {

    if (system.handlers.size() > system.maxSize)
        {
        std::cout << "Переполнение" << std::endl;
            system.handlers[0].handler(system.handlers[0].mess);

            system.handlers.erase(system.handlers.begin());
        }
       

}

void onUserLogin(const std::string& message) {
    std::cout << "вошел в систему" <<" "<<message<< std::endl;
}

void onUserLogout(const std::string& message) {
    std::cout << "вышел из системы" << " " << message << std::endl;
}

void onError(const std::string& message) {
    std::cout << "ошибка" << " " << message << std::endl;
}

int main() {
    setlocale(0, "rus");
    EventSystem System;
    std::string name;
    System.maxSize = 2;  

    int choice;
    std::string message;

    do {

        std::cout << " " << std::endl;
        std::cout << " " << std::endl;

        std::cout << "1. Создать событие входа" << std::endl;
        std::cout << "2. Создать событие выхода" << std::endl;
        std::cout << "3. Создать событие ошибки" << std::endl;
        std::cout << "4. Вывести список всех недавних событий" << std::endl;
        std::cout << "0. Выйти" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << " " << std::endl;
            std::cout << "Кто совершил действие?" << std::endl;
            std::cin >> name;
            std::cout << "Добавлено сообщение" << std::endl;
            registerHandler(System, onUserLogin,name);
            triggerEvent(System);
            std::cout << " " << std::endl;
            
            break;

        case 2:
            std::cout << " " << std::endl;
            std::cout << "Кто совершил действие?" << std::endl;
            std::cin >> name;
            std::cout << "Добавлено сообщение " << std::endl;
            registerHandler(System, onUserLogout,name);
            triggerEvent(System);
            std::cout << " " << std::endl;


            break;

        case 3:
            std::cout << "Кто совершил действие?" << std::endl;
            std::cin >> name;
            std::cout << "Добавлена ошибка " << std::endl;
            registerHandler(System, onError,name);
            triggerEvent(System);
            std::cout << " " << std::endl;

            break;

        case 4:
            std::cout << "Текущие события:" << std::endl;
            for (int i = 0; i < System.handlers.size(); i++) {
                System.handlers[i].handler(System.handlers[i].mess);
            }
            break;

        case 0:
            std::cout << "Выход из программы" << std::endl;
            std::cout << "нажмите для продолжения" << std::endl;
            std::cin;
            break;

        default:
            std::cout << "Нет выборпа" << std::endl;
            break;
        }

    } while (choice != 0);
}