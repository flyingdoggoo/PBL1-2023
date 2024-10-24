#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct Element
{
    char mahang[100], tenhang[100], dvtinh[100];
	int soluong, ngay;
	float dongia, thanhtien;
};

struct List{
    struct Element item;
    struct List *next;
    struct List *pre;
};

typedef struct List *list;

list make_list();
void insert(list head, struct Element e); 
void print_list(list head);
void docfile(list main_list); 
void SapXep(list main_list, int type);
void TimKiem(list main_list, int type);
void Xoa(list main_list, int type);
void DieuChinh(list main_list, int type, char mahang[]); 
void swap(list tmp1, list tmp2);
float ThanhTien(int sl, float dongia);
void ThanhTienNgay(list main_list);
void ThanhTienThang(list main_list);
void destroy(list main_list);
int max(int a, int b);
void print_file(list head);
void save_file(list head);
int is_empty(list main_list);
void original_file(list main_list, char c[100]);

int main(){
	list main_list = make_list();
	int i, toggle_stop = 1;
	original_file(main_list, "default.txt");
	while(toggle_stop){
		system("cls");
		printf("\t\t   +");
		for(i = 0; i < 31; i++)
		printf("-");
		printf("+\n");
		printf("\t\t   | %-30s|\n","      Nhom 13 - 23T_DT2");
		printf("\t\t   | %-30s|\n","      Nguyen Thanh Hieu");
		printf("\t\t   | %-30s|\n","      Nguyen Van Tien");
		printf("\t\t   +");
		for(i=0;i<31;i++) printf("-");printf("+\n");
        printf("\n\t\t     QUAN LY HANG NHAP TRONG THANG\n\n");
        printf("+");
		for(i = 0; i < 71; i++)
		printf("-");
		printf("+\n");
			printf("| %-70s|\n","1. Menu thong tin hang hoa"); 
			printf("| %-70s|\n","2. Menu quan ly thong tin"); 
			printf("| %-70s|\n","3. Menu tien ich");
			printf("| %-70s|\n","0. Thoat chuong trinh");
		printf("+");
		for(i=0;i<71;i++) printf("-");printf("+\n\n");
		char type;
		int sec;
		fflush(stdin);
		printf("Moi ban nhap lua chon: "); scanf("%c", &type);
		sec = type - '0';
		switch(sec){
			case 1:
				{
					system("cls");
					printf("\n\n\t\t         Menu thong tin hang hoa\n\n");
					printf("+");
					for(i = 0; i < 71; i++)
					printf("-");
					printf("+\n");
					printf("| %-70s|\n","1. In ra danh sach hang hoa"); 
					printf("| %-70s|\n","2. In danh sach hang hoa ra file"); 
					printf("| %-70s|\n","B. Quay lai"); 
					printf("+");
					for(i=0;i<71;i++) printf("-");printf("+\n\n");					
					printf("Moi ban nhap lua chon: ");
					int type;
					fflush(stdin);
					char c; scanf("%c", &c);
					if(c == 'B') continue;
					else{
					type = c - '0';
					}
					switch(type){
						case 1:{
							system("cls");
							print_list(main_list);
							printf("Nhan phim bat ki de tiep tuc\n");
							getch();
							system("cls");
							break;
						}
						case 2:{
							system("cls");
							print_file(main_list);
							printf("Da in ra file danh sach hien tai!\n");
							printf("Nhan phim bat ki de tiep tuc\n");
							getch();
							system("cls");
							break;
						}
						default:{
						system("cls");
						printf("Lua chon cua ban khong hop le! Moi ban nhap lai\n");
						printf("Nhan phim bat ki de tiep tuc\n");
						getch();
						system("cls");
						continue;
					}
					}
					break;
				}
			case 2:
				{
					system("cls");
					printf("\n\n\t\t         Menu quan ly thong tin\n\n");
					printf("+");
					for(i = 0; i < 71; i++)
					printf("-");
					printf("+\n");
					printf("| %-70s|\n","1. Them thong tin hang nhap kho vao danh sach");
					printf("| %-70s|\n","2. Lay du lieu hang nhap kho tu file");
					printf("| %-70s|\n","3. Sap xep");
					printf("| %-70s|\n","4. Xoa mat hang ra khoi danh sach");
					printf("| %-70s|\n","B. Quay lai");
					printf("+");
					for(i=0;i<71;i++) printf("-");printf("+\n\n");
					printf("Moi ban nhap lua chon: ");
					int type;
					fflush(stdin);
					char c; scanf("%c", &c);
					if(c == 'B') continue;
					else{
					type = c - '0';
					}
					switch(type){
						case 1:
				{
				system("cls");
				struct Element item;
				printf("+"); for(i=0;i<71;i++) printf("-");printf("+\n");
				printf("Ma hang: "); fflush(stdin); gets(item.mahang);
				printf("Ten hang: "); fflush(stdin); gets(item.tenhang);
				printf("Don vi hang: "); fflush(stdin); gets(item.dvtinh);
				printf("So luong: "); scanf("%d", &item.soluong);
				printf("Don gia: "); scanf("%f", &item.dongia);
				item.thanhtien = ThanhTien(item.soluong, item.dongia);
				do{
				printf("Ngay nhap: "); scanf("%d", &item.ngay);
				if(item.ngay > 31 || item.ngay < 0) printf("Ngay khong hop le! Vui long nhap lai!\n");
				}while(item.ngay > 31 || item.ngay < 0);
				printf("+"); for(i=0;i<71;i++) printf("-");printf("+\n");
				insert(main_list, item);
				print_list(main_list);
				printf("Nhan phim bat ki de tiep tuc\n");
				getch();
				system("cls");
			}
				break;
						case 2:
			{
				system("cls");
				docfile(main_list);
				printf("Nhan phim bat ki de tiep tuc\n");
				getch();
				system("cls");
			}
				break;
						case 3:
				{
					system("cls");
					printf("Ban hay chon cach sap xep!\n1: Theo so luong\n2: Theo don gia\n3: Theo thanh tien\n4: Theo ngay nhap\n");
					int type;
					do{
					printf("Lua chon: "); 
					scanf("%d", &type);
					if(type < 1 || type > 4) printf("Lua chon cua ban khong hop le! Moi ban nhap lai!\n");
					}
					while(type < 1 || type > 4);
					SapXep(main_list, type);
					print_list(main_list);
					printf("Nhan phim bat ki de tiep tuc\n");
					getch(); 
					system("cls");
				}
				break;
						case 4:
				{
					system("cls");
					printf("Danh sach truoc khi xoa\n\n");
					print_list(main_list);
					printf("Ban hay chon cach xoa mat hang!\n1: Theo ma hang\n2: Theo ten hang\n3 :Theo don vi tinh\n4: Theo ngay nhap\n"); 
					int type;
					do{
					printf("Lua chon: "); 
					scanf("%d", &type);
					if(type < 1 || type > 4) printf("Lua chon cua ban khong hop le! Moi ban nhap lai!\n");
					}
					while(type < 1 || type > 4);
					Xoa(main_list, type);
					system("cls");
					printf("Danh sach sau khi xoa \n\n");
					print_list(main_list);
					printf("Thuc hien thanh cong\n");
					printf("Nhan phim bat ki de tiep tuc\n");
					getch();
					system("cls");
				}
				break;
						default:{
						system("cls");
						printf("Lua chon cua ban khong hop le! Moi ban nhap lai\n");
						printf("Nhan phim bat ki de tiep tuc\n");
						getch();
						system("cls");
						continue;
						}
					}
					
					break;
				}
			case 3:
				{
					system("cls");
					printf("\n\n\t\t          Menu tien ich\n\n");
					printf("+");
					for(i = 0; i < 71; i++)
					printf("-");
					printf("+\n");
					printf("| %-70s|\n","1. Tim kiem");
					printf("| %-70s|\n","2. Dieu chinh so luong/ don gia"); 
					printf("| %-70s|\n","3. Tinh thanh tien cua 1 ngay");
					printf("| %-70s|\n","4. Tinh thanh tien cua ca thang");
					printf("| %-70s|\n","5. Lam trong danh sach hien tai");
					printf("| %-70s|\n","B. Quay lai");
					printf("+");
					for(i=0;i<71;i++) printf("-");printf("+\n\n");
					printf("Moi ban nhap lua chon: ");
					int type;
					fflush(stdin);
					char c; scanf("%c", &c);
					if(c == 'B') continue;
					else{
					type = c - '0';
					}
					switch(type){
						case 1:
				{
					system("cls");
					printf("Ban hay chon cach tim kiem!\n1: Theo ma hang\n2: Theo ten hang\n3 :Theo ngay nhap\n"); 
					int type;
					do{
					printf("Lua chon: "); 
					scanf("%d", &type);
					if(type < 1 || type > 3) printf("Lua chon cua ban khong hop le! Moi ban nhap lai!\n");
					}
					while(type < 1 || type > 3);
					TimKiem(main_list, type); 
					printf("Nhan phim bat ki de tiep tuc\n");
					getch();
					system("cls");
				}
				break;
						case 2:
				{
					system("cls");
					char mahang[100];
					printf("Nhap ma hang can dieu chinh: "); fflush(stdin); gets(mahang);
					printf("Hay chon du lieu can dieu chinh!\n1: So luong\n2: Don gia\n"); 
					int type;
					do{
					printf("Lua chon: "); 
					scanf("%d", &type);
					if(type < 1 || type > 2) printf("Lua chon cua ban khong hop le! Moi ban nhap lai!\n");
					}
					while(type < 1 || type > 2);
					DieuChinh(main_list, type, mahang);
					printf("Nhan phim bat ki de tiep tuc\n");
					getch();
					system("cls");
				}
				break;
						case 3:
				{
					system("cls");
					ThanhTienNgay(main_list);
					printf("Nhan phim bat ki de tiep tuc\n");
					getch();
					system("cls");
				}
				break;
			case 4:
				{
					system("cls");
					ThanhTienThang(main_list);
					printf("Nhan phim bat ki de tiep tuc\n");
					getch();
					system("cls");
				}
				break;
			case 5:
			{
				system("cls");
				destroy(main_list);
				printf("Da huy danh sach hien tai!\n");
				printf("Nhan phim bat ki de tiep tuc\n");
				getch();
				system("cls");	
			}
				break;
			default:{
				system("cls");
				printf("Lua chon cua ban khong hop le! Moi ban nhap lai\n");
				printf("Nhan phim bat ki de tiep tuc\n");
				getch();
				system("cls");
				continue;
			}
			}
			break;
		}
		case 0:{
				toggle_stop = 0;
				char c;
				printf("Ban muon luu lai file du lieu khong!\nY (Dong y)\nN (Khong dong y)\n");
				fflush(stdin);
				do{
				scanf("%c", &c);
				if(c != 'Y' && c != 'N') printf("Lua chon khong hop le! Vui long nhap lai!\n");
				} while(c != 'Y' && c != 'N');
				if(c == 'Y'){
					save_file(main_list);
				}
				printf("Ban da thoat chuong trinh!\n");
				break;
			}
		default:{
			system("cls");
			printf("Lua chon cua ban khong hop le! Moi ban nhap lai\n");
			printf("Nhan phim bat ki de tiep tuc\n");
			getch();
			system("cls");
			continue;
		}
	}
	}
	
	return 0;
}

void original_file(list main_list, char c[100]){
	FILE *fi;
	int j = 0;
	struct Element i[100];
	char line[101];
	fi = fopen(c, "r");
	while (fgets(line, sizeof(line), fi) != NULL) { 
		if (line[0] == '\n') {
        	break;
   		 }
   		sscanf(line, "%[^,],%[^,],%[^,],%d,%f,%d", i[j].mahang, i[j].tenhang, i[j].dvtinh, &i[j].soluong, &i[j].dongia, &i[j].ngay);
   		i[j].thanhtien = ThanhTien(i[j].soluong, i[j].dongia);
   		++j;
	}
	int file_size = j;
	for(j = 0; j < file_size; j++){
		insert(main_list, i[j]);
	}
}

void docfile(list main_list){
	FILE *fi;
	int j = 0, file_size = 0;
	struct Element i[100];
	char c1[100];
	do{
	printf("Moi nhap ten file du lieu: "); 
	fflush(stdin); 
	gets(c1);
	fi = fopen(c1, "r");	
	if(fi == NULL) printf("File khong ton tai! Vui long nhap lai ten file\n");
	}while(fi == NULL);
	printf("Truy cap file %s thanh cong\n", c1);
	fflush(stdin); 
	char line[100 + 1];
	while (fgets(line, sizeof(line), fi) != NULL) { 
		if (line[0] == '\n') {
        	break; 
   		 }
   		sscanf(line, "%[^,],%[^,],%[^,],%d,%f,%d", i[j].mahang, i[j].tenhang, i[j].dvtinh, &i[j].soluong, &i[j].dongia, &i[j].ngay);
   		i[j].thanhtien = ThanhTien(i[j].soluong, i[j].dongia);
   		++j;
		++file_size;
	}
	printf("Da doc du lieu cua %d mat hang\n\n", file_size);
	for(j = 0; j < file_size; j++){
		insert(main_list, i[j]);
	}
} 

list make_list(){
    list head = malloc(sizeof(struct List));
    head -> next = NULL;
}

void insert(list head, struct Element item){
	list tmp = make_list();
	tmp -> item = item;
	if(head -> next == NULL){
		head -> next = tmp;
		tmp -> pre = head;
	}
	else{
		list tmpp = head -> next;
		while(tmpp != NULL){
			if(strcmp(tmpp -> item.mahang, tmp -> item.mahang) == 0 && tmpp -> item.ngay == tmp -> item.ngay){
				printf("Da ton tai ma hang %s vao ngay %d!\n\n", tmpp -> item.mahang, tmpp -> item.ngay);
				return;
			}
			tmpp = tmpp -> next;
		}
		head = head -> next;
		while(head -> next != NULL && head -> item.ngay <= item.ngay) head = head -> next;
		if((head -> item.ngay == tmp -> item.ngay) && (strcmp(head -> item.mahang, tmp -> item.mahang) == 0)){
			head -> item.soluong += tmp -> item.soluong;
			head -> item.thanhtien = ThanhTien(head -> item.soluong, head -> item.dongia);
			return;
		}
		if(head -> next == NULL && head -> item.ngay <= item.ngay){
			head -> next = tmp;
			tmp -> pre = head;
		}
		else{
			tmp -> next = head;
			tmp -> pre = head -> pre;
			head -> pre -> next = tmp;
			head -> pre = tmp;
		}
	}
}

void Xoa(list main_list, int type){
	if(is_empty(main_list)){
		printf("Danh sach chua co du lieu!\n");
		return;
	}
	switch(type){
		case 1:{
			list tmp = main_list -> next;
			char mh[100]; int is_exist = 0;
			printf("Nhap ma hang can xoa: ");
			fflush(stdin);
			gets(mh);
			while(tmp != NULL){
				if(strcmp(mh, tmp -> item.mahang) == 0){
					is_exist = 1;
					if(tmp -> next == NULL){
						tmp = tmp -> pre;
						tmp -> next = NULL;
					} else{
						tmp -> pre -> next = tmp -> next;
						tmp -> next -> pre = tmp -> pre;
					}
				}
				tmp = tmp -> next;
			}
			if(is_exist == 0){
				printf("Khong tim thay ma hang %s!\n", mh);
			}
			break;
		}
		case 2:{
			list tmp = main_list -> next;
			char tenhang[100]; int is_exist = 0;
			printf("Nhap ten hang can xoa: ");
			fflush(stdin);
			gets(tenhang);
			while(tmp != NULL){
				if(strcmp(tenhang, tmp -> item.tenhang) == 0){
					is_exist = 1;
					if(tmp -> next == NULL){
						tmp = tmp -> pre;
						tmp -> next = NULL;
					} else{
						tmp -> pre -> next = tmp -> next;
						tmp -> next -> pre = tmp -> pre;
					}
				}
				tmp = tmp -> next;
			}
			if(is_exist == 0){
				printf("Khong tim thay ten hang %s!\n", tenhang);
			}
			break;
		}
		case 3:{
			list tmp = main_list -> next;
			char dvtinh[100]; int is_exist = 0;
			printf("Nhap don vi hang can xoa: ");
			fflush(stdin);
			gets(dvtinh);
			while(tmp != NULL){
				if(strcmp(dvtinh, tmp -> item.dvtinh) == 0){
					is_exist = 1;
					if(tmp -> next == NULL){
						tmp = tmp -> pre;
						tmp -> next = NULL;
					} else{
						tmp -> pre -> next = tmp -> next;
						tmp -> next -> pre = tmp -> pre;
					}
				}
				tmp = tmp -> next;
			}
			if(is_exist == 0){
				printf("Khong tim thay don vi hang %s!\n", dvtinh);
			}
			break;
		}
		case 4:{
			list tmp = main_list -> next;
			int is_exist = 0, ngay;
			printf("Nhap ngay nhap hang can xoa: ");
			scanf("%d", &ngay);
			while(tmp != NULL){
				if(tmp -> item.ngay == ngay){
					is_exist = 1;
					if(tmp -> next == NULL){
						tmp = tmp -> pre;
						tmp -> next = NULL;
					} else{
						tmp -> pre -> next = tmp -> next;
						tmp -> next -> pre = tmp -> pre;
					}
				}
				tmp = tmp -> next;
			}
			if(is_exist == 0){
				printf("Khong tim thay ngay nhap hang %d!\n", ngay);
			}
			break;
		}
}
}

void ThanhTienNgay(list main_list){ 
	if(is_empty(main_list)){
		printf("Danh sach chua co du lieu!\n");
		return;
	}
	float thanhtien = 0, thanhtiengoc = 0;
	int ngay;
	do{
	printf("Ban hay nhap ngay ban muon tinh thanh tien: "); 
	scanf("%d", &ngay);
	if(ngay < 1 || ngay > 31) printf("Lua chon cua ban khong hop le! Moi ban nhap lai!\n");
	}
	while(ngay < 1 || ngay > 31);
	list tmp = main_list -> next;
	while(tmp != NULL){
		if(tmp -> item.ngay == ngay){
			thanhtien += tmp -> item.thanhtien;
			thanhtiengoc += (tmp -> item.soluong * tmp -> item.dongia);
		}
		tmp = tmp -> next;
	}
	main_list = main_list -> next;
	tmp = main_list;
	list print = make_list();
	int day = ngay; int is_exist = 0;
	while(tmp != NULL){
		if(day == tmp -> item.ngay){
			is_exist = 1;
			insert(print, tmp -> item);
		}
		tmp = tmp -> next;
	}
	if(is_exist == 0){
		printf("Khong tim thay ngay nhap hang %d!\n", day);
	}
	else{
		print_list(print);
	}
	printf("Thanh tien trong ngay %d la: %.2f\n", ngay, thanhtien);
	printf("Chi phi tiet kiem duoc trong ngay %d la: %.2f\n", ngay, thanhtiengoc - thanhtien);
}

void ThanhTienThang(list main_list){
	if(is_empty(main_list)){
		printf("Danh sach chua co du lieu!\n");
		return;
	}
	main_list = main_list -> next;
	list tmp1, tmp2;
	for(tmp1 = main_list; tmp1 != NULL; tmp1 = tmp1 -> next){
		for(tmp2 = tmp1 -> next; tmp2 != NULL; tmp2 = tmp2 -> next){
			if(tmp1 -> item.ngay > tmp2 -> item.ngay){
				swap(tmp1, tmp2);
			}
		}
	}
	list tmpp = main_list;
	float thanhtienngay = tmpp -> item.thanhtien, tietkiem = (tmpp -> item.dongia * tmpp -> item.soluong - thanhtienngay);
	printf("\n\n\t\t\t     Thanh tien trong thang\n\n");
	printf( "+-------------------------+-------------------------+-------------------------+\n");
    printf("|%-25s|%-25s|%-25s|\n", "NGAY NHAP","THANH TIEN", "TIET KIEM");
	while(tmpp -> next != NULL){
		if(tmpp -> next -> item.ngay != tmpp -> item.ngay){
			if(tmpp -> pre -> item.ngay == tmpp -> item.ngay){
			thanhtienngay += tmpp -> item.thanhtien;
			tietkiem += fabs(tmpp -> item.dongia * tmpp -> item.soluong - tmpp -> item.thanhtien);
			}
			printf( "|-------------------------|-------------------------|-------------------------|\n");
			printf("|%-25d|%-25.2f|%-25.2f|\n", tmpp -> item.ngay, thanhtienngay, tietkiem);
			thanhtienngay = tmpp -> next -> item.thanhtien;
			tietkiem = fabs(tmpp -> next -> item.dongia * tmpp -> next -> item.soluong - thanhtienngay);
		}
		else{
			if(tmpp -> pre -> item.ngay == tmpp -> item.ngay){
			thanhtienngay += tmpp -> item.thanhtien;
			tietkiem += fabs(tmpp -> item.dongia * tmpp -> item.soluong - tmpp -> item.thanhtien);
			}
		}
		tmpp = tmpp -> next;
	}
	if(tmpp -> pre -> item.ngay == tmpp -> item.ngay){
	thanhtienngay += tmpp -> item.thanhtien;
	tietkiem += fabs(tmpp -> item.dongia * tmpp -> item.soluong - tmpp -> item.thanhtien);
	}
	printf( "|-------------------------|-------------------------|-------------------------|\n");
	printf("|%-25d|%-25.2f|%-25.2f|\n", tmpp -> item.ngay, thanhtienngay, tietkiem);
	printf( "+-------------------------+-------------------------+-------------------------+\n");
	float thanhtien = 0, thanhtiengoc = 0;
	list tmp = main_list;
	while(tmp != NULL){
		thanhtien += tmp -> item.thanhtien;
		thanhtiengoc += (tmp -> item.soluong * tmp -> item.dongia);
		tmp = tmp -> next;
	}
	printf("Thanh tien trong thang la: %.2f\n", thanhtien);
	printf("Chi phi tiet kiem duoc trong thang la: %.2f\n", thanhtiengoc - thanhtien);
}

void DieuChinh(list main_list, int type, char mahang[]){
	if(is_empty(main_list)){
		printf("Danh sach chua co du lieu!\n");
		return;
	}
	list tmp = main_list -> next;
	list print = make_list();
	while(tmp != NULL){
		if(strcmp(tmp -> item.mahang, mahang) == 0){
			insert(print, tmp -> item);
		}
		tmp = tmp -> next;
	}
	if(is_empty(print)){
		printf("Khong tim thay ma hang %s!\n", mahang);
		return;
	}
	else{
		print_list(print);
	}
	switch(type){
		case 1:
			{
				int type, sl, ok = 0;
				printf("Ban muon tang hay giam so luong cua mat hang!\n1:Tang\n2:Giam\n");
					do{
					printf("Lua chon: "); 
					scanf("%d", &type);
					if(type < 1 || type > 2) printf("Lua chon cua ban khong hop le! Moi ban nhap lai!\n");
					}
					while(type < 1 || type > 2);
					if(type == 1){
						printf("Ban hay nhap so luong tang them cua ma hang %s: ", mahang); scanf("%d", &sl);
						tmp = main_list -> next;
						while(tmp != NULL){
							if(strcmp(tmp -> item.mahang, mahang) == 0){
								tmp -> item.soluong += sl;
								tmp -> item.thanhtien = ThanhTien(tmp -> item.soluong, tmp -> item.dongia);
							}
							tmp = tmp -> next;
						}
					}
					else{
						printf("Ban hay nhap so luong giam di cua ma hang %s: ", mahang); scanf("%d", &sl);
						tmp = main_list -> next;
						while(tmp != NULL){
							if(strcmp(tmp -> item.mahang, mahang) == 0){
								tmp -> item.soluong = max(0, tmp -> item.soluong - sl); 
								tmp -> item.thanhtien = ThanhTien(tmp -> item.soluong, tmp -> item.dongia);
							}
							tmp = tmp -> next;
						}
					}
			}
			break;
		case 2:
			{
				int type; float dg;
				printf("Ban muon tang hay giam don gia cua mat hang!\n1:Tang\n2:Giam\n");
					do{
					printf("Lua chon: "); 
					scanf("%d", &type);
					if(type < 1 || type > 2) printf("Lua chon cua ban khong hop le! Moi ban nhap lai!\n");
					}
					while(type < 1 || type > 2);
					if(type == 1){
						printf("Ban hay nhap don gia tang them cua ma hang %s: ", mahang); scanf("%f", &dg);
						tmp = main_list -> next;
						while(tmp != NULL){
							if(strcmp(tmp -> item.mahang, mahang) == 0){
								tmp -> item.dongia += dg;
								tmp -> item.thanhtien = ThanhTien(tmp -> item.soluong, tmp -> item.dongia);
							}
							tmp = tmp -> next;
						}
					}
					else{
						printf("Ban hay nhap don gia giam di cua ma hang %s: ", mahang); scanf("%f", &dg);
						tmp = main_list -> next;
						while(tmp != NULL){
							if(strcmp(tmp -> item.mahang, mahang) == 0){
								if(tmp -> item.dongia - dg < 0) 
								{
								tmp -> item.dongia = 0;
								tmp -> item.thanhtien = ThanhTien(tmp -> item.soluong, tmp -> item.dongia);
								}
								else{
									tmp -> item.dongia -= dg;
									tmp -> item.thanhtien = ThanhTien(tmp -> item.soluong, tmp -> item.dongia);
								}
							}
							tmp = tmp -> next;
						}
					}
			}
			break;
	}
	printf("Thuc hien thanh cong!\n");
}

void SapXep(list main_list, int type){
	if(is_empty(main_list)){
		printf("Danh sach chua co du lieu!\n");
		return;
	}
	switch(type){
		case 1:
			{
				main_list = main_list -> next;
				list tmp1, tmp2;
				for(tmp1 = main_list; tmp1 != NULL; tmp1 = tmp1 -> next){
					for(tmp2 = tmp1 -> next; tmp2 != NULL; tmp2 = tmp2 -> next){
						if(tmp1 -> item.soluong > tmp2 -> item.soluong){
							swap(tmp1, tmp2);
						}
					}
				}
				printf("Da hoan thanh sap xep du lieu theo so luong!\n");
			}
			break; 
		case 2:
			{
				main_list = main_list -> next;
				list tmp1, tmp2;
				for(tmp1 = main_list; tmp1 != NULL; tmp1 = tmp1 -> next){
					for(tmp2 = tmp1 -> next; tmp2 != NULL; tmp2 = tmp2 -> next){
						if(tmp1 -> item.dongia > tmp2 -> item.dongia){
							swap(tmp1, tmp2);
						}
					}
				}
				printf("Da hoan thanh sap xep du lieu theo don gia!\n");
			}
			break; 
		case 3:
			{
				main_list = main_list -> next;
				list tmp1, tmp2;
				for(tmp1 = main_list; tmp1 != NULL; tmp1 = tmp1 -> next){
					for(tmp2 = tmp1 -> next; tmp2 != NULL; tmp2 = tmp2 -> next){
						if(tmp1 -> item.thanhtien > tmp2 -> item.thanhtien){
							swap(tmp1, tmp2);
						}
					}
				}
				printf("Da hoan thanh sap xep du lieu theo thanh tien!\n");
			}
			break; 
		case 4:
		{
			main_list = main_list -> next;
				list tmp1, tmp2;
				for(tmp1 = main_list; tmp1 != NULL; tmp1 = tmp1 -> next){
					for(tmp2 = tmp1 -> next; tmp2 != NULL; tmp2 = tmp2 -> next){
						if(tmp1 -> item.ngay > tmp2 -> item.ngay){
							swap(tmp1, tmp2);
						}
					}
				}
				printf("Da hoan thanh sap xep du lieu theo ngay nhap!\n");
		}
		break;
		default:
		break; 
	}
}

void TimKiem(list main_list, int type){
	if(is_empty(main_list)){
		printf("Danh sach chua co du lieu!\n");
		return;
	}
	switch(type){
		case 1:{
			main_list = main_list -> next;
			list tmp = main_list;
			list print = make_list();
			char mh[100]; int is_exist = 0;
			printf("Nhap ma hang can tim kiem: ");
			fflush(stdin);
			gets(mh);
			while(tmp != NULL){
				if(strcmp(mh, tmp -> item.mahang) == 0){
					is_exist = 1;
					insert(print, tmp -> item);
				}
				tmp = tmp -> next;
			}
			if(is_exist == 0){
				printf("Khong tim thay ma hang %s!\n", mh);
			}
			else{
				print_list(print);
			}
			break;
		}
		case 2:{
			main_list = main_list -> next;
			list tmp = main_list;
			list print = make_list();
			char th[100]; int is_exist = 0;
			printf("Nhap ten hang can tim kiem: ");
			fflush(stdin);
			gets(th);
			while(tmp != NULL){
				if(strcmp(th, tmp -> item.tenhang) == 0){
					is_exist = 1;
					insert(print, tmp -> item);
				}
				tmp = tmp -> next;
			}
			if(is_exist == 0){
				printf("Khong tim thay ten hang %s!\n", th);
			}
			else{
				print_list(print);
			}
			break;
		}
		case 3:{
			main_list = main_list -> next;
			list tmp = main_list;
			list print = make_list();
			int day; int is_exist = 0;
			printf("Nhap ngay nhap hang can tim kiem: "); scanf("%d", &day);
			while(tmp != NULL){
				if(day == tmp -> item.ngay){
					is_exist = 1;
					insert(print, tmp -> item);
				}
				tmp = tmp -> next;
			}
			if(is_exist == 0){
				printf("Khong tim thay ngay nhap hang %d!\n", day);
			}
			else{
				print_list(print);
			}
			break;
		}
	}
}

float ThanhTien(int sl, float dongia){
	if(sl <= 100){
		return sl * dongia;
	} else if(100 < sl && sl <= 200){
		return sl * dongia - 0.1 * sl * dongia;
	} else{
		return sl * dongia - 0.15 * sl * dongia;
	}
}

void swap(list tmp1, list tmp2){
	struct Element i;
	i = tmp1 -> item; 
	tmp1 -> item = tmp2 -> item;
	tmp2 -> item = i; 
}

void destroy(list main_list){
	list cur = main_list;
	list next;
	while(cur != NULL){
		next = cur -> next;
		free(cur);
		cur = next;
	}
	main_list = make_list();
}

int is_empty(list main_list){
	if(main_list -> next == NULL) return 1;
	return 0;
}

int max(int a, int b) { 
    return (a > b) ? a : b; 
} 

void print_list(list head){
	if(is_empty(head)){
		printf("Danh sach chua co du lieu!\n");
		return;
	}
	printf("\n\n\t\t\t\t\t\t     Danh Sach Hang Hoa\n\n");
	printf( "+--------------------+-------------------------+--------------------+---------------+---------------+--------------------+----------+\n");
    printf("|%-20s|%-25s|%-20s|%-15s|%-15s|%-20s|%-10s|\n","MA HANG","TEN HANG","DON VI HANG","SO LUONG","DON GIA", "THANH TIEN", "NGAY NHAP");
	head = head -> next;
	while(head != NULL){
		printf( "|--------------------|-------------------------|--------------------|---------------|---------------|--------------------|----------|\n");
    	printf("|%-20s|%-25s|%-20s|%-15d|%-15.2f|%-20.2f|%-10d|\n",head -> item.mahang ,head -> item.tenhang ,head -> item.dvtinh,
		head -> item.soluong,head -> item.dongia, head -> item.thanhtien, head -> item.ngay);
		head = head -> next;
	}
	printf( "+--------------------+-------------------------+--------------------+---------------+---------------+--------------------+----------+\n");	
}
void save_file(list head){
	if(is_empty(head)){
		printf("Danh sach chua co du lieu!\n");
		return;
	}
	FILE *fi;
	FILE *fi1 = fopen("default.txt", "w");
	char c1[100];
	do{
	printf("Moi nhap ten file de ghi du lieu: "); 
	fflush(stdin); 
	gets(c1);
	fi = fopen(c1, "w");
	if(fi == NULL) printf("File khong ton tai! Vui long nhap lai ten file\n");
	}while(fi == NULL);
	printf("Truy cap file %s thanh cong\n", c1);
	head = head -> next;
	while(head != NULL){
		fprintf(fi, "%s,%s,%s,%d,%.2f,%d\n", head -> item.mahang, head -> item.tenhang, head -> item.dvtinh, head -> item.soluong, head -> item.dongia, head -> item.ngay);
		fprintf(fi1, "%s,%s,%s,%d,%.2f,%d\n", head -> item.mahang, head -> item.tenhang, head -> item.dvtinh, head -> item.soluong, head -> item.dongia, head -> item.ngay);
		head = head -> next;
	}
	printf("Da luu du lieu vao file %s !\n", c1);
	fclose(fi);
	fclose(fi1);
} 
void print_file(list head){
	if(is_empty(head)){
		printf("Danh sach chua co du lieu!\n");
		return;
	}
	FILE *fi;
	char c1[100];
	do{
	printf("Moi nhap ten file de ghi du lieu: "); 
	fflush(stdin); 
	gets(c1); 
	fi = fopen(c1, "w");
	if(fi == NULL) printf("File khong ton tai! Vui long nhap lai ten file\n");
	}while(fi == NULL);
	printf("Truy cap file %s thanh cong\n", c1);
	head = head -> next;
	while(head != NULL){
		fprintf(fi, "Ma hang: %s\nTen hang: %s\nDon vi hang: %s\nSo luong: %d\nDon gia: %.2f\nThanh tien: %.2f\nNgay nhap: %d\n\n\n", head -> item.mahang, head -> item.tenhang, head -> item.dvtinh, head -> item.soluong, head -> item.dongia, head -> item.thanhtien, head -> item.ngay);
		head = head -> next;
	}
	fclose(fi);
}
