#include "Header.h"

//1. Khởi tạo danh sách liên kết
void init(Nodeptr& head) {
	head = NULL;
}

//2. Tạo node
Nodeptr makeNode(typeinfo x) {
	Nodeptr p = new Node;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->link = NULL;
	return p;
}

//3. Giải phóng bộ nhớ
void release(Nodeptr& head) {
	while (head != NULL) {
		Nodeptr p = head;
		head = head->link;
		delete p;
	}
}

void print(Nodeptr head) {
	while (head != NULL) {
		cout << head->data << "  ";
		head = head->link;
	}
}

//4. Kiểm tra danh sách rỗng hay không
bool isEmpty(Nodeptr head) {
	return head == NULL;
}

//5. Thêm 1 phần tử vào đầu danh sách
void addFirst(Nodeptr& head, typeinfo x) {
	Nodeptr p = makeNode(x);
	if (isEmpty(head))
		head = p;
	else {
		p->link = head;
		head = p;
	}
}

int length(Nodeptr head) {
	int count = 0;
	while (head != NULL) {
		count++;
		head = head->link;
	}
	return count;
}

Nodeptr nodeIndex(Nodeptr head, int idx) {
	if (idx < 0 || idx>length(head))
		throw "\nIndex incorrect!!!";
	else {
		int count = 0;
		while (head != NULL) {
			if (count++ == idx)
				return head;
			head = head->link;
		}
	}
}

//6. Thêm 1 phần tử vào danh sách(thêm sau phần tử q)
Nodeptr findX(Nodeptr head, typeinfo x) {
	while (head != NULL) {
		if (head->data == x)
			return head;
		head = head->link;
	}
	return NULL;
}

//7. Thêm 1 phần tử vào cuối danh sách
void addLast(Nodeptr& head, typeinfo x) {
	Nodeptr p = makeNode(x);
	if (isEmpty(head))
		head = p;
	else {
		Nodeptr r;
		for (r = head; r->link != NULL; r = r->link);
		r->link = p;
	}
}
	




//38. Trộn 2 danh sách tăng dần thành 1 danh sách đảm bảo tính tăng dần.
Nodeptr tronTangDan(Nodeptr& ds1, Nodeptr& ds2) {
	Nodeptr ds3;
	init(ds3);
	Nodeptr p;
	init(p);

	while (ds1 != NULL && ds2 != NULL) {
		if (ds1->data < ds2->data) {
			addLast(ds3, ds1->data);
			ds1 = ds1->link;
		}
		else {
			addLast(ds3, ds2->data);
			ds2 = ds2->link;
		}
		// Di chuyển con trỏ p đến phần tử cuối cùng trong danh sách kết quả
		if (p == NULL) {
			p = ds3;
		}
		else {	
			while (p->link != NULL) {
				p = p->link;
			}
		}
	}
	// Nếu một trong hai danh sách còn phần tử
	while (ds1 != nullptr) {
		cout << "  ";
		addLast(p->link, ds1->data);
		ds1 = ds1->link;
	}
	while (ds2 != nullptr) {
		cout << "  ";
		addLast(p->link, ds2->data);
		ds2 = ds2->link;
	}
	return ds3;
}

//39. Sắp xếp danh sách tăng dần
void swap(typeinfo& x, typeinfo& y) {
	typeinfo temp = x;
	x = y;
	y = temp;
}

void sapXepTangDan(Nodeptr& head) {
	Nodeptr i, j;
	Nodeptr tail = nodeIndex(head, length(head) - 1);

	for (i = head; i->link != NULL; i = i->link) {
		for (j = i->link; j != NULL; j = j->link) {
			if (i->data > j->data) {
				swap(i->data, j->data);
			}
		}
	}
}


//40. Sắp xếp danh sách giảm dần
void sapXepGiamDan(Nodeptr& head) {
	Nodeptr i, j;
	Nodeptr tail = nodeIndex(head, length(head) - 1);

	for (i = head; i->link != NULL; i = i->link) {
		for (j = i->link; j != NULL; j = j->link) {
			if (i->data < j->data) {
				swap(i->data, j->data);
			}
		}
	}
}

bool kt_doixung(Nodeptr head) {
	typeinfo r = length(head) - 1;
	typeinfo l = 0;

	while(l!=r) {
		Nodeptr ptr1 = nodeIndex(head, l);
		Nodeptr ptr2 = nodeIndex(head, r);

		if (ptr1->data != ptr2->data) {
			return false;
		}
		r--; l++;
		if (l > r)
			break;
	}
	return true;
}




