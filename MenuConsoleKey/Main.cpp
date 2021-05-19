#include "head.h"
#include <iostream>
#include <windows.h>
#include <locale.h>
#include "../Sorting.h"
#include <limits>
#include <stdlib.h>

void clearRow(int row)
{
	DWORD dw;
	COORD here;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	here.X = 2;
	here.Y = row;
	LPCSTR str = "       ";
	WriteConsoleOutputCharacter(hStdOut, str, 8, here, &dw);
}

const char* space = "\t\t";
HWND console = nullptr;
POINT PosConsole = { 100,100 };
POINT sizeConsole = { 1200,600 };

void FontsSettings(int width, int height) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = width;
	cfi.dwFontSize.Y = height;
	cfi.FontFamily = FF_DONTCARE; 
	cfi.FontWeight = 600;
	//std::wcscpy(cfi.FaceName, L"Sony Sketch EF");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}


void loading()
{
	ProgressBar prog("", 0, 0);
	bool exit = true;
	while (exit)
	{	
		//cls();
		setCursorPosition(65, 16);
		setConsoleColour(0xA);
		std::wcout << "LOADING...";
		setCursorPosition(18, 18);
		prog.Show(0);
		Sleep(10);
		prog.ChangeValue(0);
		std::cout.flush();
		if (prog.value == 100.0F)
			exit = false;
	}

}


int menu(field* Array_field, int cout_Array_field)
{
	cls();

	//Exemple :)
	setConsoleColour(0xA);
	bool change = true;
	bool finish = false;
	int pos = 0;
	int max = 0;
	timer tmr1(100, true);

	while (!finish)
	{
		if (tmr1.timer_on())
		{
			if (change)
			{
				square(40, 5, 1, 0, 0);
				setCursorPosition(8, 0);
				size_t i = 0;
				
				std::cout << " GitHub @Yut-ka \r";
				std::cout << std::endl;
				int line_number = 8;

				for (field* ptr = Array_field; ptr <= &Array_field[cout_Array_field - 1]; ptr++) {
					setCursorPosition(2, line_number++);
					ptr->show(pos);
					++i;
				}
				max = i-1;
				change = false;
				
			}
	
			if (GetAsyncKeyState(VK_UP))
			{
				pos--;
				if (pos < 0)
					pos = max;
				change = true;

			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				++pos;
				if (pos > max)
					pos = 0;
				change = true; 
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				for (field* ptr = Array_field; ptr <= &Array_field[cout_Array_field - 1]; ptr++) {
					ptr->Press(pos);				
				}
				pos == max ? finish = true : finish = false;
				change = true;
				return pos;
			}
			setCursorPosition(2, 2);
			std::cout << "SAOD LAB1_1";
			setCursorPosition(2, 3);
			std::cout << "by Osipov Danil 4218";	
			setCursorPosition(2, 15);


			std::cout.flush();
		}
		Sleep(1);
	}
}


std::string text(textblock field)
{
	cls();

	//Exemple :)
	setConsoleColour(0xA);
	bool change = true;
	bool finish = false;
	int pos = 0;
	int max = 0;
	timer tmr1(100, true);
	

	while (!finish)
	{
		if (tmr1.timer_on())
		{
			
			std::string a;

			if (change)
			{
				square(40, 5, 1, 0, 0);
				setCursorPosition(8, 0);
				size_t i = 0;

				std::cout << " GitHub @Yut-ka \r" << std::endl;
				std::cout << std::endl;

				setCursorPosition(2, 2);
				std::cout << "SAOD LAB1_1" << std::endl;
				setCursorPosition(2, 3);
				std::cout << "by Osipov Danil 4218" << std::endl;

				setCursorPosition(2, 8);
				field.show(pos);
				setCursorPosition(2, 10);
				clearRow(10);
				getline(std::cin,a);
				std::cin.clear();
				std::cin.sync();
			}

			

			if (GetAsyncKeyState(VK_RETURN))
			{
				finish = true;
				return a;
			}

			
			
			std::cout.flush();
		}
		Sleep(0.5);
	}
}


std::string Get_el_console(std::string str) {
	textblock C = str;
	std::flush(std::cout);
	std::string A = text(C);
	return A;
}

int* a;

int main()
{ 
	FontsSettings(0, 16);
	console = GetConsoleWindow();
	SetWindowPos(console, NULL, PosConsole.x, PosConsole.y, sizeConsole.x, sizeConsole.y, NULL);
	SetWindowLong(console, GWL_STYLE, WS_BORDER);
	ShowWindow(console, SW_SHOW);
	ExConsole();
	loading();		
				
	
	

	while (1) {
		field A[9] = { "Create the ARRAY", "Exchange sort", "Insert sort", "Selection sort", "Shell sort", "Quick sort", "Piramid sort", "Show ARRAY", "Exit" };
		bool back = 0;
		int choice = menu(A, 9);
		if (choice == 0) {	
			while (!back) {
				field D[2] = { "The ARRAY was successfully created", "Back"};
				N = stoi(Get_el_console("Enter a lenght of ARRAY"));
				a = Create_Array(N);
				if (menu(D, 2) == 1) back = 1;
			}
		}

		else if (choice == 1) {
			while (!back) {
				int* B = new int[N];
				memcpy(B, a, sizeof(int) * N);
				field EX_SORT[2] = { Exchange_sort(B) , "Back"};
				if (menu(EX_SORT, 2) == 1) { back = 1; delete[] B; }
			}
		}

		else if (choice == 2) {
			while (!back) {
				int* C = new int[N];
				memcpy(C, a, sizeof(int) * N);
				field IN_SORT[2] = { Insert_sort(C) , "Back" };
				if (menu(IN_SORT, 2) == 1) { back = 1; delete[] C;}
			}
		}

		else if (choice == 3) {
			while (!back) {
				int* D = new int[N];
				memcpy(D, a, sizeof(int) * N);
				field SEL_SORT[2] = { Selection_sort(D) , "Back" };
				if (menu(SEL_SORT, 2) == 1) { back = 1; delete[] D; }
			}
		}

		else if (choice == 4) {
			field AA[2] = { "Enter step manualy", "Default step" };
			int res = menu(AA, 2);
			if (res == 0) {
				while (!back) {
					int count = stoi(Get_el_console("Enter a number of step:"));
					int* h = new int[count];
					for (int i = 0; i < count; i++) {
						h[i] = stoi(Get_el_console("Enter a step(from min to max)"));
					}
					int* S = new int[N];
					memcpy(S, a, sizeof(int) * N);
					field SHELL1[2] = { Shell_sort(S, count, h), "Back" };
					if (menu(SHELL1, 2) == 1) { back = 1; delete[] S; delete[] h; }
				}
			}
			else if (res == 1) {
				while (!back) {
					int* E = new int[N];
					memcpy(E, a, sizeof(int) * N);
					field SHELL2[2] = { Shell_sort(E), "Back" };
					if (menu(SHELL2, 2) == 1) { back = 1; delete[] E; }
				}
			}
			
		}

		else if (choice == 5) {
			while (!back) {
				int* E = new int[N];
				memcpy(E, a, sizeof(int) * N);
				compare1 = 0;
				change1 = 0;
				Quick_sort(E);
				field QUICK[2] = { "Change: " + std::to_string(change1) + " , Compare: " + std::to_string(compare1) , "Back" };
				if (menu(QUICK, 2) == 1) { back = 1; delete[] E; }
			}
		}

		else if (choice == 6) {
			while (!back) {
				int* E = new int[N];
				memcpy(E, a, sizeof(int) * N);
				compare = 0;
				change = 0;
				Piramid_sort(E);
				field PIR[2] = { "Change: " + std::to_string(change) + " , Compare: " + std::to_string(compare) , "Back" };
				if (menu(PIR, 2) == 1) { back = 1; delete[] E; }
			}
		}

		else if (choice == 7) {
			while (!back) {
				std::string str = "";
				for (int i = 0; i < N; ++i) {
					str += std::to_string(a[i]) + " ";
				}
				field SHOW[2] = { "Back", str};
				if (menu(SHOW, 2) == 0) { back = 1; }
			}
		}

		else if (choice == 8) {
			delete(a);
			exit(0);
		}
	}
		
	
	return 0;
}

