#include <stdio.h>

void NhapMang(int a[], int& n);
void XuatMang(int a[], int n);
void TimKiem(int a[], int n);
void TinhChat(int a[], int n);
void TachMang(int a[], int b[], int c[], int length_a, int& length_b, int& length_c);
void GopMang(int d[], int a[], int b[], int& length_d, int length_a, int length_b);
void Max(int a[], int n);
void Min(int a[], int n);
void SxTangDan(int a[], int n);
void SxGiamDan(int a[], int n);
void Tacdongvaophantu(int a[], int& n);
void Themphantu(int a[], int& n);
void Xoaphantu(int a[], int& n);
void Suaphantu(int a[], int& n);

int main() {
	int a[50] = { 0 };
	int b[50] = { 0 };
	int c[50] = { 0 };
	int d[100] = { 0 };
	int length_a, length_b, length_c, length_d;
	NhapMang(a, length_a);
	printf("Mang a: \n");
	XuatMang(a, length_a);


	// Tim kiem phan tu trong mang
		 TimKiem(a, n);
	
	//Tinh chat cua mang (tang, giam, khong tang khong giam)
		TinhChat(a, n);
	
	//Tach mang a thanh 2 mang b, c. Voi b chua cac phan tu dau cua mang a
		TachMang(a, b, c, length_a, length_b, length_c);
		printf("Mang b: \n");
		XuatMang(b, length_b);
		printf("Mang c: \n");
		XuatMang(c, length_c);

	//Gop 2 mang a, b vao mang d. Voi mang a dung truoc mang b
		GopMang(d, a, b, length_d, length_a, length_b);
		printf("Mang d: \n");
		XuatMang(d, length_d);

	// GTLN, GTNN cua mang
		Max(a, length_a);
		Min(a, length_a);

	// Sap xep mang tang dan
		SxTangDan(a, length_a);
		printf("Mang a sau khi sap xep tang dan: \n");
		XuatMang(a, length_a);

	//Sap xep mang giam dan
		SxGiamDan(a, length_a);
		printf("Mang a sau khi sap xep giam dan: \n");
		XuatMang(a, length_a);

	//tac dong vao phan tu
		Tacdongvaophantu(a, length_a);
		printf("mang a sau khi sua: \n");
		XuatMang(a, length_a); 


	return 0;
}

void NhapMang(int a[], int& n) {
	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("A[%d] = ", i);
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
void TimKiem(int a[], int n) {
	int element;
	printf("Nhap phan tu can tim: ");
	scanf("%d", &element);
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == element) {
			printf("%d duoc tim thay o vi tri %d\n", element, i);
			break;
		}
		else
			count++;
	}
	if (count == n)
		printf("%d khong duoc tim thay\n", element);
}
void TinhChat(int a[], int n) {
	int count = 0;
	int count_tc = 0;
	if (n == 1) {
		printf("Mang chi co mot phan tu.\n");
	}
	else {
		if (a[1] > a[0]) {
			for (int i = 0; i < n-1; i++) {
				if (a[i + 1] > a[i])
					count++;
			}
			if (count == n - 1)
				printf("Mang tang dan.\n");
			else
				count_tc++;
		}
		if (a[1] < a[0]) {
			for (int i = 0; i < n - 1; i++) {
				if (a[i + 1] < a[i])
					count++;
			}
			if (count == n - 1)
				printf("Mang giam dan.\n");
			else
				count_tc++;
		}
		if (count_tc != 0)
			printf("Mang khong tang khong giam\n");
	}
}
void TachMang(int a[], int b[], int c[], int length_a, int& length_b, int& length_c) {
	printf("Nhap phan tu muon tach: ");
	scanf("%d", &length_b);
	length_c = length_a - length_b;
	for (int i = 0; i < length_b; i++) {
		b[i] = a[i];
	}
	for (int i = length_b; i < length_a; i++) {
		c[i - length_b] = a[i];
	}
}
void GopMang(int d[], int a[], int b[], int& length_d, int length_a, int length_b) {
	length_d = length_a + length_b;
	for (int i = 0; i < length_a; i++)
		d[i] = a[i];
	for (int i = length_a; i < length_d; i++)
		d[i] = b[i - length_a];
}
void Max(int a[], int n) {
	int max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}
	printf("Phan tu lon nhat cua mang la: %d\n", max);
}
void Min(int a[], int n) {
	int min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] < min)
			min = a[i];
	}
	printf("Phan tu nho nhat cua mang la: %d\n", min);
}
void SxTangDan(int a[], int n) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (a[i + 1] < a[i])
			{
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}	
}
void SxGiamDan(int a[], int n) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (a[i + 1] > a[i])
			{
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}
}
void Tacdongvaophantu(int a[], int& n) {
	char choose;
	printf("Them phan tu (t/T).\n");
	printf("Xoa phan tu (x/X).\n");
	printf("Sua phan tu (s/S).\n");
	printf("Hay cho toi biet lua chon cua ban: ");
	scanf(" %c", &choose);
	switch (choose)
	{
		case 't':
		case 'T':
			Themphantu(a,n);
			break;
		case 'x':
		case 'X':
			Xoaphantu(a,n);
			break;
		case 's':
		case 'S':
			Suaphantu(a, n);
			break;
		default:
			printf("Ban nhap sai roi!\n");
			break;
	}
}
void Themphantu(int a[], int& n) {
	int vitri, giatri;
	printf("Nhap vi tri phan tu ban muon them vao: ");
	scanf("%d", &vitri);
	printf("Nhap gia tri phan tu ban muon them vao: ");
	scanf("%d", &giatri);
	n++;
	for (int i = n-1; i > vitri; i--)
	{
		a[i] = a[i - 1];
	}
	a[vitri] = giatri;
}
void Xoaphantu(int a[], int& n) {
	int vitri;
	printf("Nhap vi tri phan tu ban muon xoa: ");
	scanf("%d", &vitri);
	for (int i = vitri; i < n; i++)
	{
		a[i] = a[i +1];
	}
	n--;
}
void Suaphantu(int a[], int& n) {
	int vitri, giatri;
	printf("Nhap vi tri phan tu ban muon sua: ");
	scanf("%d", &vitri);
	printf("Nhap gia tri phan tu ban muon sua: ");
	scanf("%d", &giatri);
	a[vitri] = giatri;
}