#include <iostream>
#include <fstream>
#include <cstring>
#include <Windows.h>
using namespace std;


const int Max_nameMovie = 50; 
const int Max_Director = 50; 
const int Max_Country = 50;

struct Movie {
    char nameMovie[Max_nameMovie];
    char Director[Max_Director];
    char Country[Max_Country];
    int doxod;
};

bool readFromFile(ifstream& inFile, Movie& Movie) {
    if (!inFile.read((char*)&Movie, sizeof(Movie))) {
        if (inFile.eof()) {
            return false;
        }
        else {
            cout << "Ошибка чтения из файла" << endl << endl;
            exit(1);
        }
    }
    return true;
}
 
void clearFile(const char* fileDirector) {
    ofstream outFile(fileDirector, ios::trunc);
    if (!outFile) {
        cout << "Ошибка открытия файла " << fileDirector << endl << endl;
        return;
    }
    outFile.close(); 
    cout << "База данных успешно очищена" << endl << endl;
}

void writeToFile(ofstream& outFile, const Movie& Movie) {
    outFile.write((const char*)&Movie, sizeof(Movie));
}

void addMovieToFile(const char* fileDirector) {
    ofstream outFile(fileDirector, ios::binary | ios::app);
    if (!outFile) {
        cout << "Ошибка открытия файла " << fileDirector << endl << endl;
        return;
    }
    Movie Movie;
    cout << "Введите название фильма: ";
    cin >> Movie.nameMovie;
    cout << "Введите Режисера: ";
    cin >> Movie.Director;
    cout << "Введите страну: ";
    cin >> Movie.Country;
    cout << "Введите доход: ";
    cin >> Movie.doxod;
    if (!cin) {
        cout << endl << "Ошибка ввода" << endl << endl;
        cin.clear();
        return;
    }
    writeToFile(outFile, Movie);
    cout << endl << "Фильм успешно добавлен" << endl << endl;
    outFile.close();
}

void printFileContents(const char* fileDirector) {
    ifstream inFile(fileDirector, ios::binary);
    if (!inFile) {
        cout << "Ошибка открытия файла " << fileDirector << endl << endl;
        return;
    }
    Movie Movie;
    if (inFile.peek() == EOF)
        cout << "База данных пустая" << endl << endl;
    else {
        while (readFromFile(inFile, Movie)) {
            cout << "Фильм: " << Movie.nameMovie << endl;
            cout << "Режисер: " << Movie.Director << endl;
            cout << "Страна: " << Movie.Country << endl;
            cout << "Доход: " << Movie.doxod << endl;
            cout << "----------------------" << endl;
        }
    }
    inFile.close();
}

void removeMoviesFromFile(const char* fileDirector) {
    string namemovie;
    cout << "Введите название фильма: ";
    cin >> namemovie;
    if (!cin) {
        cout << "Ошибка ввода" << endl;
        cin.clear();
        return;
    }

    ifstream inFile(fileDirector, ios::binary);
    if (!inFile) {
        cout << "Ошибка открытия файла " << fileDirector << endl << endl;
        return;
    }
    ofstream tempFile("temp.dat", ios::binary);
    if (!tempFile) {
        cout << "Ошибка открытия файла temp.dat" << endl << endl;
        inFile.close();
        return;
    }
    Movie movie;

    bool removed = false;
    while (readFromFile(inFile, movie)) {
        if (movie.nameMovie == namemovie) {
            removed = true;
            continue;
        }
        writeToFile(tempFile, movie);
    }
    removed = true;

    

    inFile.close();
    tempFile.close();
    remove(fileDirector);
    rename("temp.dat", fileDirector);
    if (removed) {
        cout << endl << "Фильмы успешно удалены" << endl << endl;
    }
    else {
        cout << endl << "Фильмы не найдены" << endl << endl;
    }
}

void addMovieToFile1(const char* fileDirector) {
    char nameMovie[Max_nameMovie];
    cout << "Введите название Фильма, после которого нужно добавить нового студента: ";
    cin >> nameMovie;
    Movie newMovie;
    cout << "Введите данные нового Фильма" << endl;
    cout << "Введите название Фильма: ";
    cin >> newMovie.nameMovie;
    cout << "Введите фамилию режисера: ";
    cin >> newMovie.Director;
    cout << "Введите Страна: ";
    cin >> newMovie.Country;
    cout << "Введите Доход: ";
    cin >> newMovie.doxod;
    if (!cin) {
        cout << endl << "Ошибка ввода" << endl << endl;
        cin.clear();
        return;
    }
    ifstream inFile(fileDirector, ios::binary);
    if (!inFile) {
        cout << endl << "Ошибка открытия файла " << fileDirector << endl << endl;
        return;
    }
    ofstream tempFile("temp.dat", ios::binary);
    if (!tempFile) {
        cout << endl << "Ошибка открытия файла temp.dat" << endl << endl;
        inFile.close();
        return;
    }
    Movie movie;
    bool added = false;
    while (readFromFile(inFile, movie)) {
        writeToFile(tempFile, movie);
        if (strcmp(movie.nameMovie, nameMovie) == 0) {
            writeToFile(tempFile, newMovie);
            added = true;
        }
    }
    inFile.close();
    tempFile.close();
    remove(fileDirector);
    rename("temp.dat", fileDirector);
    if (added) {
        cout << endl << "Фильм успешно добавлен" << endl << endl;
    }
    else {
        cout << endl << "Фильм " << nameMovie << " не найден" << endl << endl;
    }
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const char* fileDirector = "Movies.dat";
    int choice;
    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1. Вывести содержимое базы данных с Фильмом" << endl;
        cout << "2. Добавить фильм в базу данных" << endl;
        cout << "3. Удалить данные фильма" << endl;
        cout << "4. Добавить элемент помле элемента с указанным названием" << endl;
        cout << "5. Очистить базу данных" << endl;
        cout << "6. Завершить работу с базой данных" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        if (!cin) {
            cout << endl << "Ошибка ввода" << endl << endl;
            cin.clear();
            continue;
        }
        cout << endl;
        switch (choice) {
        case 1:
            printFileContents(fileDirector);
            break;
        case 2:
            addMovieToFile(fileDirector);
            break;
        case 3:
            removeMoviesFromFile(fileDirector);
            break;
        case 4:
            addMovieToFile1(fileDirector);
            break;
        case 5:
            clearFile(fileDirector);
            break;
        case 6:
            return 0;
        default:
            cout << "Некорректный ввод" << endl << endl;
            break;
        }
    }
    return 0;
}