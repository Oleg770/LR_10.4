#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void AddDataToFile()
{
	ofstream f("file1.txt", ios::out | ofstream::app);
	cout << "enter firm, marka1,price1, marka2,price2, ...\n";
	cout << "for end press Enter\n";
	cout << "enter down this data:\n";
	string dt;
	if (cin.peek() == '\n') { cin.get(); } // если попал предыдущий символ конца строки, считываем его в пустоту и он исчезает
	getline(cin, dt);
	f << dt << endl;
	f.close();
}

void CreateNewFile()
{
	fstream in("file1.txt", ios::in);
	ofstream f2("file2.txt", ios::out);

	while (1)
	{

		char str[1000];
		in.getline(str, 1000);
		if (in.eof())break;
		f2 << str;

		char* wrds[300]; // масив для слів із запасом - на 300 слів
		int cnt = 0; // кількість найдених слів
					 // разбиваем на слова
		cnt = 0;
		char seps[] = " ,,\n\r"; // // розділові знаки, тут англійські літери і керуючі символи і наші
		char* word = strtok(str, seps); //во втором параметре указаны разделители (пробел, запятая, точка..)
		while (word != NULL) //пока есть лексемы
		{
			wrds[cnt++] = word;
			word = strtok(NULL, seps);
		}
		//printf("\nFinded %d words\n", cnt);

		int max = 0;
		for (int i = 2; i < cnt; i += 2) {
			//cout << wrds[i] << ", ";
			string sv = wrds[i];
			int x = stoi(sv);
			if (x > max)max = x;

		}
		if (cnt == 0)break;
		cout << "max: " << max << endl;
		f2 << ", max: " << max << endl;

	}

	in.close();
	f2.close();

}

int main()
{

	int choose = 0;
	while (choose != 9) {
		cout << "\n 1) Add data to file\
			\n 2) Create new file\
			\n 9) Quit\n\n";
		cin >> choose;
		switch (choose) {
		case 1: AddDataToFile(); break;
		case 2: CreateNewFile(); break;
		case 9: return 0;
		}
	}


#ifdef _WIN32
	cout << "\n\n"; system("pause"); // нужно для вижул только
#endif  
	return 0;
}