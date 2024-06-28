#include <iostream>
#include <vector>
#include <string>
#include "sqlite3.h"
#include <Windows.h>

using namespace std;

struct car_data{
	string engine = "";
	string color = "";
	short count = NULL;
};

struct car_market {
	string brand = "";
	string model = "";
	int graduation_year = NULL;
	float price = 0.0;
	int bargaining = NULL;
	car_data about_car;
};

car_data add_data_car();
car_market add_car_market();

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	const char* path = сюди вставте шлях до папки документи. До іншої папки може не вистачити прав\\struct.db;

	sqlite3* DB;
	sqlite3_stmt* stmt;
	string sql = "CREATE TABLE IF NOT EXISTS CAR_MARKET("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT,"
		"BRAND TEXT NOT NULL,"
		"MODEL TEXT NOT NULL,"
		"GRADUATION_YEAR INTEGER NOT NULL,"
		"PRICE INTEGER NOT NULL,"
		"BARGAINING INT NOT NULL,"
		"ABOUT_CAR TEXT);";
	int exit = sqlite3_open(path, &DB);
	if (exit != SQLITE_OK) {
		cerr << "\nПомилка відкриття файлу БД: " << sqlite3_errmsg(DB) << endl;
		return -1;
	}
	else {
		cout << "\nБД відкрита " << endl;
	}
	exit = sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL);
	if (exit != SQLITE_OK) {
		cerr << "\nНе вдалось підготувати запит: " << sqlite3_errmsg(DB) << endl;
		sqlite3_close(DB);
	}

	exit = sqlite3_step(stmt);
	if (exit != SQLITE_DONE) {
		cerr << "\nПомилка виконання запиту: " << sqlite3_errmsg(DB) << endl;;
		sqlite3_close(DB);
	}
	else{
		cout << "Табличка створена" << endl;
	}

	sqlite3_finalize(stmt);

	car_data buffer_car_data;

	buffer_car_data = add_data_car();
	while (buffer_car_data.color.empty() && buffer_car_data.engine.empty() && buffer_car_data.count == NULL) {
		buffer_car_data = add_data_car();
	}

	car_market buffer_market_data_piece;

	buffer_market_data_piece = add_car_market();
	while (buffer_market_data_piece.brand.empty() && buffer_market_data_piece.model.empty() && buffer_market_data_piece.graduation_year == NULL && buffer_market_data_piece.bargaining != NULL) {
		buffer_market_data_piece = add_car_market();
	}

	sql = "INSERT INTO CAR_MARKET (BRAND, MODEL, GRADUATION_YEAR, PRICE, BARGAINING, ABOUT_CAR) VALUES(?, ?, ?, ?, ?, ?);";
	exit = sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL);
	if (exit != SQLITE_OK) {
		cerr << "\nНе вдалось підготувати запит: " << sqlite3_errmsg(DB) << endl;
		sqlite3_finalize(stmt);
		sqlite3_close(DB);
	}

	sqlite3_bind_text(stmt, 1, buffer_market_data_piece.brand.c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, buffer_market_data_piece.model.c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_int(stmt, 3, buffer_market_data_piece.graduation_year);
	sqlite3_bind_double(stmt, 4, buffer_market_data_piece.price);
	sqlite3_bind_int(stmt, 5, buffer_market_data_piece.bargaining);
	string about_car = "";
	about_car += buffer_car_data.engine;
	about_car += "\n" + buffer_car_data.color;
	about_car += "\n" + to_string(buffer_car_data.count);
	sqlite3_bind_text(stmt, 6, about_car.c_str(), -1, SQLITE_STATIC);

	exit = sqlite3_step(stmt);
	if (exit != SQLITE_DONE) {
		cerr << "\nПомилка виконання запиту: " << sqlite3_errmsg(DB) << endl;;
	}
	else {
		cout << "Запит виконано" << endl;
	}

	sqlite3_finalize(stmt);
	sqlite3_close(DB);
	return 0;
}


car_data add_data_car() {
	car_data data_car;
	cout << "\nВведіть назву мотора: ";
	getline(cin, data_car.engine);

	cout << "\nВведіть колір в який окрашен автомобіль: ";
	getline(cin, data_car.color);

	cout << "Кількість власників автомобіля: ";
	cin >> data_car.count;

	cin.ignore();

	return data_car;
}

car_market add_car_market() {
	cout << "Введіть марку автомобіля: ";
	string brand;
	getline(cin, brand);

	cout << "Введіть модель автомобіля: ";
	string model;
	getline(cin, model);

	cout << "Введіть рік випуску авто: ";
	int graduation_year;
	cin >> graduation_year;

	cout << "Введіть ціну: ";
	float price;
	cin >> price;

	cout << "Торг доречний Так[1] Ні[2]: ";
	cin.ignore();
	char check;
	cin >> check;
	bool bargaining;
	if (check == '1') {
		bargaining = true;
	}
	else {
		bargaining = false;
	}

	car_market data_market_piece;

	data_market_piece = { brand, model, graduation_year, price, bargaining};

	return data_market_piece;
}
