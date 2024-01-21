#include "Header.h"


int main() {
	Nodeptr head;
	init(head);
	
	typeinfo x;
	do {
		cout << "nhap x (-99 thoat): ";
		cin >> x;
		if (x == -99)
			break;
		addLast(head, x);
	} while (true);

	cout << "\ndanh sach hien tai: "; print(head); 

		if (kt_doixung(head)==true)
			cout << "\nDoi xung.";
		else
			cout << "\nKhong doi xung.";
		

	system("pause");
	system("cls");
	Nodeptr ds1; init(ds1);
	Nodeptr ds2; init(ds2);
	typeinfo i, v;
	do {
		cout << "\nNhap ptu cho ds1 (-99 thoat): ";
		cin >> i;
		if (i == -99)
			break;
		addLast(ds1, i);
	} while (true);
	
	do {
		cout << "\nNhap ptu cho ds2 (-99 thoat): ";
		cin >> v;
		if (v == -99)
			break;
		addLast(ds2, v);
	} while (true);
	cout << "\nDanh sach 1 hien tai: "; print(ds1);
	cout << "\nDanh sach 2 hien tai: "; print(ds2);
	
	//39. Sắp xếp danh sách tăng dần
	cout << "\n-----Sap xep danh sach 1 tang dan-----";
	sapXepTangDan(ds1);
	cout << "\nDanh sach hien tai: "; print(ds1);

	//40. Sắp xếp danh sách giảm dần
	cout << "\n-----Sap xep danh sach 1 giam dan-----";
	sapXepGiamDan(ds1);
	cout << "\nDanh sach hien tai: "; print(ds1);


	//38.Trộn 2 danh sách tăng dần thành 1 danh sách đảm bảo tính tăng dần.
	sapXepTangDan(ds1);
	sapXepTangDan(ds2);
	cout << "\nDanh sach sau khi tron ds1 va ds2 dam bao tinh tang dan: ";
	print(tronTangDan(ds1, ds2));


	
	
	


	release(ds1);
	release(ds2);
	return 0;
}