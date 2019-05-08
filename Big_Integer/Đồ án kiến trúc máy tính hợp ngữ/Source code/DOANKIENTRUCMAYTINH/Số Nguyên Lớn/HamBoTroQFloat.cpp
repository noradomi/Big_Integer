#include "HamBoTroQFloat.h"

//Hàm kiểm tra chuỗi chứa số thập phân bằng 0
int is_zero(string a) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != '0' && a[i] != '.') {
			return 0;
		}
	}
	return 1;
}

//Hàm kiểm tra dãy bit bằng 0
int is_zero(unsigned int *a, int size) {
	for (int i = 0; i < size; i++) {
		if (a[i] != 0) {
			return 0;
		}
	}
	return 1;
}

//Hàm kiểm tra chuỗi bit gồm toàn c ("0" hoặc "1")
int all_c(string a, char c) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != c) {
			return 0;
		}
	}
	return 1;
}
