#include <iostream>
using namespace std;
#include <string>
int main() {

    string s1("�l����λ�ciŶ�ٷ�����ifһ�ɳ��촺��δ�VG��");
	s1.reserve(20);
	for (int i = 0; i < s1.size(); i++) {
		s1[i] = 's';
		cout << s1[i] << "";
	
	}
	cout << endl;
	cout << s1 << endl;

	cout << s1.length() << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;//����Ո�˶��ٿ��g

	return 0;

}