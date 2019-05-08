#include "HamBoTro.h"

string multiple_by_2(string a) {
	char b[50];

	int c = 0;
	int d;

	for (int i = a.size() - 1; i >= 0; i--) {
		c = c + 2 * (int)(a[i] - '0');
		d = c % 10;
		c = c / 10;
		b[i] = (char)(d + '0');
	}
	b[a.size()] = '\0';

	if (c != 0) {
		return "1" + string(b);
	}

	return string(b);
}//Hàm nhân 1 chuỗi string cho 2
string two_power_n(int n) {
	string a("1");
	for (int i = 1; i <= n; i++) {
		a = multiple_by_2(a);
	}
	return a;
}//Hàm nhân 1 chuỗi string cho 2 n lần
string find_sum(string str1, string str2)
{
	if (str1.length() > str2.length())
		swap(str1, str2);

	string res = "";

	// Tính toán chiều dài của 2 chuỗi
	int n1 = str1.length(), n2 = str2.length();

	// Đảo ngược 2 chuỗi để tính toán
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int temp = 0;
	for (int i = 0; i < n1; i++)
	{
		//Tính toán tổng của 2 chữ số ở vị trí thứ i của 2 chuỗi cộng với biến nhớ
		int sum = ((str1[i] - '0') + (str2[i] - '0') + temp);
		res.push_back(sum % 10 + '0');//Chuyển phần dư của sum tính toán vào kết quả

									  //Chia nguyên kết quả cho 10 để tính toán biến nhớ cho bước kế tiếp
		temp = sum / 10;
	}

	//Tính toán tương tự nếu n1 có chiều dài nhỏ hơn n2 
	for (int i = n1; i < n2; i++)
	{
		int sum = ((str2[i] - '0') + temp);
		res.push_back(sum % 10 + '0');
		temp = sum / 10;
	}

	//Thêm biến nhớ vào kết quả cuối cùng
	if (temp) {
		res.push_back(temp + '0');
	}

	//Đảo ngược chuỗi số ta được kết quả cuối cùng
	reverse(res.begin(), res.end());

	return res;
}//Hàm cộng 2 chuỗi hệ 10 với nhau
char *substr(char *s, int start, int end)
{
	char p[100];
	//int len = lenstr(s);
	int indext = 0;

	for (int i = start; i <= end; i++)
	{
		p[indext] = s[i];
		indext++;
	}
	p[indext] = '\0';

	return p;
}//Hàm lấy các kí tự từ vị trí start bất kì đến vị trí end bất kì của chuỗi s kiểu char*
string addBinary(string str1, string str2)
{
	/*string result;
	unsigned int s = 0;
	int i = str1.size() - 1, j = str2.size() - 1;
	while (i >= 0 || j >= 0 || s == 1)
	{
	s += ((i >= 0) ? str1[i] - '0' : 0);
	s += ((j >= 0) ? str2[j] - '0' : 0);
	result = (char)(s % 2 + '0') + result;
	s /= 2;
	i--;
	j--;
	}
	return result;*/
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	string res = "";
	int c = 0, d = 0;
	for (int i = 0; i < str1.size(); i++) {
		c = c + str1[i] - '0' + str2[i] - '0';
		d = c % 2;
		c = (c - d) / 2;
		res += (d + '0');
	}
	reverse(res.begin(), res.end());

	return res;
}//Hàm cộng 2 chuỗi nhị phân với nhau
int fill_zero(char *a, int n) {
	int i = 0;
	while (a[i] != '1' && i < n) {
		a[i] = '0';
		i++;
	}
	return i;
}
void ShiftTrai(string &Bit, int shift) {
	Bit.erase(Bit.begin(), Bit.begin() + shift);//Xóa shift phần tử đầu

	string temp;
	for (int i = 0; i < shift; i++) {
		temp = temp + "0";
	}
	Bit = Bit + temp;//Cộng thêm shift phần tử 0 vào cuối 
}//Hàm dịch trái shift lần
void ShiftPhai(string &Bit, int shift) {
	Bit.erase(Bit.size() - shift);//Xóa shift phần tử cuối
	string temp;
	for (int i = 0; i < shift; i++) {
		temp = temp + "0";
	}
	Bit = temp + Bit;//Cộng thêm shift phần tử 0 vào đầu dãy bit
}//Hàm dịch phải dãy bit
void XoayTrai(string &Bit, int shift) {
	string temp;
	temp = Bit.substr(0, shift);//Lưu shift phần tử đầu vào temp
	Bit.erase(Bit.begin(), Bit.begin() + shift);//Xóa shift phần tử đầu sau khi đã chép vào temp
	Bit = Bit + temp;//Thêm temp vào cuối của dãy bit
}//Hàm xoay trái dãy bit shift lần
void XoayPhai(string &Bit, int shift) {
	string temp;
	temp = Bit.substr(Bit.size() - shift, shift);//Lưu shift phần tử cuối vào temp
	Bit.erase(Bit.size() - shift);//Xóa shift phần tử cuối sau khi đã chép vào temp
	Bit = temp + Bit;//Thêm temp vào đầu của dãy bit
}//Hàm xoay phải dãy bit shift lần
void remove_zero(string &a)
{
	int dem = 0; //Đếm số '0'
	unsigned int j = 0;

	while (j < a.size() && a[j] == '0')
		j++;

	a.erase(a.begin(), a.begin() + j); // Xóa kí tự từ đầu chuỗi đến vị trí j trong chuỗi
}//Hàm xóa số 0 thừa