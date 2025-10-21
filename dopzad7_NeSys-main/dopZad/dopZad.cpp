#include <iostream>
#include <vector>
#include <string>

struct EventSystem {
    std::vector<void(*)(const std::string&)> handlers;
    int maxSize = 100;
    int nextIndex = 0; 
    int correctPassword;
};

void registerHandler(EventSystem& system, void(*handler)(const std::string&)) {
    if (system.handlers.size() < system.maxSize) {
        system.handlers.push_back(handler);
    }
    else {
        system.handlers[system.nextIndex] = handler;
        system.nextIndex = (system.nextIndex + 1) % system.maxSize;
    }
}

void triggerEvent(const EventSystem& system, const std::string& message) {
    if (std::stoi(message) == system.correctPassword)
    {
        if (system.handlers.size() < system.maxSize) {
            for (auto handler : system.handlers) {
                handler(message);
            }
        }
        else {
            for (int i = 0; i < system.maxSize; i++) {
                int index = (system.nextIndex + i) % system.maxSize;
                system.handlers[index](message);
            }
        }
    }
    else
    {
        std::cout << "нееверный пароль. запрет." << std::endl;
    }
}

void onUserLogin(const std::string& message) {
    std::cout << "вошел в систему" << std::endl;
}

void onUserLogout(const std::string& message) {
    std::cout << "вышел из системы"<< std::endl;
}

void onError(const std::string& message) {
    std::cout << "ошибка" << std::endl;
}

int main() {
    setlocale(0, "rus");
    int correct_password;
    EventSystem System;
    System.maxSize = 5;  

    int choice;
    std::string message;
    while (true)
    {
        std::cout << "Установите пароль (цифрами): ";
        std::cin >> System.correctPassword;
        break;
    }
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
            std::cout << "Добавлено сообщение";
            registerHandler(System, onUserLogin);
            std::cout << " " << std::endl;

            break;

        case 2:
            std::cout << " " << std::endl;
            std::cout << "Добавлено сообщение ";
            registerHandler(System, onUserLogout);
            std::cout << " " << std::endl;


            break;

        case 3:
            std::cout << "Добавлена ошибка ";
            registerHandler(System, onError);
            std::cout << " " << std::endl;

            break;

        case 4:
            int password;
            std::cout << "Введите пароль: ";
            std::cin >> password;
            

            triggerEvent(System, std::to_string(password));
            std::cout << " " << std::endl;

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