#pragma once
#include <string>
#include <iostream>
#include <time.h>

int N=0;

std::string Exchange_sort(int Array[]) {
	int change = 0;
	int compare = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = N-1; j > i; j--) {
			if (Array[j - 1] > Array[j]) {
				int temp = Array[j - 1];
				Array[j - 1] = Array[j];
				Array[j] = temp;
				change++;
			}
			compare++;
		}
	}
	return "Change: " + std::to_string(change) + " , Compare: " + std::to_string(compare);
}

std::string Insert_sort(int Array[]) {
	int change = 0;
	int compare = 0;
	for (int i = 1; i < N; ++i) {
		int temp = Array[i];
		int j = i - 1;
		while (j >= 0 && temp < Array[j]) {
			compare++;
			Array[j + 1] = Array[j];
			j--;
			change++;
		}
		compare++;
		if (j < 0) compare--;
		Array[j + 1] = temp;
	}
	return "Change: " + std::to_string(change) + " , Compare: " + std::to_string(compare-1);
}

std::string Selection_sort(int Array[]) {
	int change = 0;
	int compare = 0;
	for (int i = 0; i < N; ++i) {
		int temp = Array[i];
		int k = i;
		for (int j = i + 1; j < N; j++) {
			if (Array[j] < temp) { k = j; temp = Array[j]; }
			compare++;
		}
		if (k != i) change++;
		Array[k] = Array[i];
		Array[i] = temp;
	}
	return "Change: " + std::to_string(change) + " , Compare: " + std::to_string(compare );
}

int* Create_Array(int lenght) {
	int* Array = new int[lenght];
	srand(time(NULL));
	for (int i = 0; i < lenght; i++) {
		Array[i] = int(pow(-1, rand() % 2)) * rand() % 100;
	}
	return Array;
}

std::string Shell_sort(int Array[], int t, int h[]) {
	int change = 0;
	int compare = 0;

	for (int m = 0; m < t; m++) {
		int k = h[t - m - 1];
		for (int i = k; i < N; i++) {    
			int temp = Array[i];
			int j = i - k;
			while (j >= 0 && temp < Array[j]) {
				compare++;
				Array[j + k] = Array[j];
				j = j - k;
				change++;
			}
			compare++;
			if (j < 0) compare--;
			Array[j + k] = temp;
		}
	}
	return "Change: " + std::to_string(change) + " , Compare: " + std::to_string(compare);
}

std::string Shell_sort(int Array[]) {
	int change = 0;
	int compare = 0;
	int t = int(log(N) / log(2));
	int* h = new int[t];
	for (int i = 0; i < t; i++) {
		h[i] = int(pow(2, i+1)) - 1;
	}
	for (int m = 0; m < t; m++) {
		int k = h[t - m - 1];
		for (int i = k; i < N; i++) {    
			int temp = Array[i];
			int j = i - k;
			while (j >= 0 && temp < Array[j]) {
				compare++;
				Array[j + k] = Array[j];
				j = j - k;
				change++;
			}
			compare++;
			if (j < 0) compare--;
			Array[j + k] = temp;
		}
	}
	return "Change: " + std::to_string(change) + " , Compare: " + std::to_string(compare);
}

int compare1 = 0;
int change1 = 0;

void Quick_sort(int Array[], int size = N) {
	int i = 0;
	int j = size - 1;
	int sred = Array[size / 2];
	do {
		while (Array[i] < sred) {i++; compare1++; }
		while (Array[j] > sred) {j--; compare1++; }
		if (i <= j) {
			if (i != j) {
				change1++;
			}
			int temp = Array[i];
			Array[i] = Array[j];
			Array[j] = temp;
			i++; j--;
		}
		compare1++;
	} while (i <= j);
	if (j > 0) Quick_sort(Array, j + 1);
	if (i < size) Quick_sort(&Array[i], size - i);
}

int compare;
int change;

void Sito(int Array[], int al, int ar) {
	int i = al;
	int j = 2 * al;
	int x = Array[al];
	if (j < ar && Array[j + 1] < Array[j]) j++;
	while (j <= ar && Array[j] < x) {
		compare++;
		if (i != j) change++;
		Array[i] = Array[j];
		i = j;
		j = 2 * j;
		if (j < ar && Array[j + 1] < Array[j]) j++;
	}
	if(j > ar || Array[j] >= x) compare++;
	Array[i] = x;
}

void Piramid_sort(int Array[]) {
	int left = N / 2 + 1;
	int right = N;
	while (left > 1) {
		left--;
		Sito(Array, left, right);
	}
	while (right > 1) {
		int temp = Array[1];
		Array[1] = Array[right];
		change++;
		Array[right] = temp;
		right--;
		Sito(Array, left, right);
	}
}