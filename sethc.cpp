#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void menuan(string);
void resetpass(){
	system("del /f C:\\Users\\Default\\security.myfile");
}
void checkpwd(string input){
	string pwdsave, check;
	fstream filesave;
	filesave.open("C:\\Users\\Default\\security.myfile", ios::in);
	getline(filesave, pwdsave);
	if (pwdsave=="") {
		cout << "Tao Password moi: ";
		cin >> check;
		filesave.open("C:\\Users\\Default\\security.myfile", ios::out);
		filesave << check;
		filesave.close();
		system("cls");
		menuan(input);
	} else {
	while(1){
	cout << "Password: ";
	cin >> check;
	if (check == pwdsave) {
	system("cls");
	menuan(input);
	break;
	}
	else {
		cout <<"Sai mat khau.\n";
	}
	}
}}
void menuan(string input){
    string luachon, luachon0, tentaikhoan;
	if (input=="menu"||input=="Menu"){
		cout << "Menu da khoi tao. Chon chuc nang tuong ung\n";
		cout <<
		"1.Danh sach tai khoan\n2.Danh sach tai khoan admin\n" <<
		"3.Change Password tai khoan\n" <<
		"4.Active Admin: Bat\n5.Active Admin: Tat\n6.Open Cmd\n" <<
		"Vui long nhap so tuong ung: ";
		cin >> luachon;
		cout << "----------------------------------------------------\n";
		if (luachon=="1") {
			system("net user");
			cout << "----------------------------------------------------\n";
		}
		if (luachon=="2") {
			system("net localgroup Administrators");
			cout << "----------------------------------------------------\n";
		}
		if (luachon=="3") {
			cout << "Nhap ten tai khoan: ";
			cin >> tentaikhoan;
			system(("net user " + tentaikhoan + " *").c_str());
			cout << "----------------------------------------------------\n";
		}
		if (luachon=="4") {
			system("net user Administrator /active:yes");
			cout << "----------------------------------------------------\n";
		}
		if (luachon=="5") {
			system("net user Administrator /active:no");
			cout << "----------------------------------------------------\n";
		}
		if (luachon=="6") system("start cmd.exe");
		cout << "Nhap 0 de tro lai: ";
		cin >> luachon0;
		cout << "----------------------------------------------------\n";
		if (luachon0=="0") return menuan(input);
		
} 
}
void inputhd(string input){
	if (input=="1"||input=="2"||input=="3"||input=="menu"||input=="Menu"||input=="resetpwd"||input=="reset"){
	if (input=="1") system("shutdown -s");
	if (input=="2") system("shutdown -r");
	if (input=="3") system("exit");
	if (input=="menu"||input=="Menu") checkpwd(input);
	if (input=="resetpwd"||input=="reset") resetpass();
	}else{
		cout << "Ban vui long chon chinh xac\nVui long nhap so tuong ung: ";
		cin >> input;
		return inputhd(input);
	}
	
}

int main(){
	system("color 2");
	cout <<
	"1.Tat may\n" <<
	"2.Khoi dong lai may\n" <<
	"3.Thoat\n" <<
	"Vui long nhap so tuong ung: ";
	string input;
	cin >> input;
	inputhd(input);
}