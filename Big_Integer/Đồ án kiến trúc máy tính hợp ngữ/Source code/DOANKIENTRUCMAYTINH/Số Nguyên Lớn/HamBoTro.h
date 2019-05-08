#pragma once
#pragma once
#include <string>
#include <iostream>

using namespace std;


string multiple_by_2(string a);//Hàm nhân 2 cho một chuỗi số string
string two_power_n(int n);//Hàm nhân 2 cho một chuỗi số string n lần
string find_sum(string str1, string str2);//Hàm cộng 2 chuỗi string hệ 10
int fill_zero(char *a, int n);
char *substr(char *s, int start, int end);//Hàm  lấy giá trị của chuỗi từ vị trí start bất kì đến vị trí end bất kì
string addBinary(string str1, string str2); // bổ trợ cho toán tử cộng
void ShiftTrai(string &Bit, int shift);//Hàm dịch trái shift lần
void ShiftPhai(string &Bit, int shift);//hàm dịch phải shift lần
void XoayTrai(string &Bit, int shift);//Hàm xoay trái shift lần
void XoayPhai(string &Bit, int shift);//Hàm xoay phải shift lần
void remove_zero(string &a);//Hàm xóa số 0 thừa
