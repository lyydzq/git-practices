#include <iostream>
using namespace std;
#include <string>
int main() {

    string s1("發到各位與i哦官方体育if一飞冲天春归何处VG和");
	s1.reserve(20);
	for (int i = 0; i < s1.size(); i++) {
		s1[i] = 's';
		cout << s1[i] << "";
	
	}
	cout << endl;
	cout << s1 << endl;

	cout << s1.length() << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;//是申請了多少空間

	return 0;

}