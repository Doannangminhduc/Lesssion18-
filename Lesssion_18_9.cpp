#include <stdio.h>
#include <string.h>

	struct MonAn {
	    int ma;
	    char ten[50];
	    float gia;
	};
	
	struct MonAn MenuMonAn[100] = {      
	    {1, "Thit cho dat vang noi", 99999999},
	    {2, "Thit lon rung dinh kim cuong", 999999999},
	    {3, "Thit bo kube A5 sieu cap pro vip thuong hang", 9999999},
	    {4, "Thit ga kimono e gai dung mua", 9999999},
	    {5, "Thit chim phuong hoang tung canh dai 1000m", 9999999}
	};
	int soLuong = 5;
	
	void inMenu() {
	    for (int i = 0; i < soLuong; i++) {
	        printf("%d. Ma: %d, Ten: %s, Gia: %.2f\n", i + 1, MenuMonAn[i].ma, MenuMonAn[i].ten, MenuMonAn[i].gia);
	    }
	}
	
	int main() {
	    int luaChon;
	    do {
	        printf("\n-----------Menu cua nha hang dinh noc kich tran bay phap phoi----------\n");
	        printf("1. In ra gia tri cac phan tu\n");
	        printf("2. Nhap mot phan tu vao vi tri cuoi mang\n");
	        printf("3. Sua mot phan tu o vi tri cuoi mang\n");
	        printf("4. Xoa mot phan tu o vi tri cuoi mang\n");
	        printf("5. Sap xep cac phan tu\n");
	        printf("6. Tim kiem phan tu theo ten nhap vao\n");
	        printf("7. Thoat\n");
	        printf("Vui long lua chon: ");
	        scanf("%d", &luaChon);
	        
	        switch (luaChon) {
	            case 1:
	                inMenu();
	                break;
	            case 2:
	                if (soLuong >= 100) {
	                    printf("Menu da day.\n");
	                } else {
	                    printf("Nhap Ma: ");
	                    scanf("%d", &MenuMonAn[soLuong].ma);
	                    printf("Nhap Ten: ");
	                    scanf(" %[^\n]s", MenuMonAn[soLuong].ten);
	                    printf("Nhap Gia: ");
	                    scanf("%f", &MenuMonAn[soLuong].gia);
	                    soLuong++;
	                    printf("Them mon an thanh cong.\n");
	                }
	                break;
	            case 3:
	                if (soLuong == 0) {
	                    printf("Menu trong.\n");
	                } else {
	                    printf("Nhap Ma: ");
	                    scanf("%d", &MenuMonAn[soLuong - 1].ma);
	                    printf("Nhap Ten: ");
	                    scanf(" %[^\n]s", MenuMonAn[soLuong - 1].ten);
	                    printf("Nhap Gia: ");
	                    scanf("%f", &MenuMonAn[soLuong - 1].gia);
	                    printf("Sua mon an thanh cong.\n");
	                }
	                break;
	            case 4:
	                if (soLuong == 0) {
	                    printf("Menu trong.\n");
	                } else {
	                    soLuong--;
	                    printf("Xoa mon an thanh cong.\n");
	                }
	                break;
	            case 5: {
	                char luaChonCon;
	                printf("Sap xep mon an\n");
	                printf("a. Giam dan theo gia\n");
	                printf("b. Tang dan theo gia\n");
	                printf("Lua chon: ");
	                scanf(" %c", &luaChonCon);
	                for (int i = 0; i < soLuong - 1; i++) {
	                    for (int j = i + 1; j < soLuong; j++) {
	                        if ((luaChonCon == 'b' && MenuMonAn[i].gia > MenuMonAn[j].gia) ||
	                            (luaChonCon == 'a' && MenuMonAn[i].gia < MenuMonAn[j].gia)) {
	                            struct MonAn temp = MenuMonAn[i];
	                            MenuMonAn[i] = MenuMonAn[j];
	                            MenuMonAn[j] = temp;
	                        }
	                    }
	                }
	                printf("Sap xep thanh cong.\n");
	                break;
	            }
	            case 6: {
	                char luaChonCon;
	                char ten[50];
	                printf("Nhap ten mon an: ");
	                scanf(" %[^\n]s", ten);
	                printf("Tim kiem mon an\n");
	                printf("a. Tim kiem tuyen tinh\n");
	                printf("b. Tim kiem nhi phan\n");
	                printf("Lua chon: ");
	                scanf(" %c", &luaChonCon);
	                int index = -1;
	                if (luaChonCon == 'a') {
	                    for (int i = 0; i < soLuong; i++) {
	                        if (strcmp(MenuMonAn[i].ten, ten) == 0) {
	                            index = i;
	                            break;
	                        }
	                    }
	                } else {
	                    printf("Chuc nang tim kiem nhi phan chua duoc cai dat.\n");
	                }
	                if (index != -1) {
	                    printf("Tim thay mon an: Ma: %d, Ten: %s, Gia: %.2f\n", MenuMonAn[index].ma, MenuMonAn[index].ten, MenuMonAn[index].gia);
	                } else {
	                    printf("Khong tim thay mon an.\n");
	                }
	                break;
	            }
	            case 7:
	                printf("Thoat chuong trinh.\n");
	                break;
	            default:
	                printf("Lua chon khong hop le.\n");
	        }
	    } while (luaChon != 7);

    return 0;
}

