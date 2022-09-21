#include <iostream>

#include <string.h>

using namespace std;

typedef struct OneDay

{

	int DD,MM,YYYY;

}OD;


struct HS

{

    char ten [100];

    int toan,van;

    float dtb;
};


void Nhap(OD& x, int& LastDay)

{

	cout << "Nhap ngay: ";

	cin >> x.DD;

	cout << "Nhap thang: ";
	cin >> x.MM;

	cout << "Nhap nam: ";
	cin >> x.YYYY;

	switch (x.MM)

	{

	case 1: case 3: case 5: case 7: case 8: case 10: case 12:

		LastDay = 31;

		break;

	case 4: case 6: case 9: case 11:

		LastDay = 30;

		break;

	case 2:

		if (x.YYYY % 400 == 0 || (x.YYYY % 4 == 0 && x.YYYY % 100 != 0))

			LastDay = 29;

		else LastDay = 28;

		break;

	default: LastDay = 0;

	}

	if (LastDay == 0 || x.YYYY < 1 || (LastDay != 0 && (x.DD > LastDay || x.DD < 1)))

	{

		cout << "Ngay thanh nam khong hop le, vui long nhap lai:" << '\n';

		Nhap(x, LastDay);

	}

}

void NextDay(OD x,OD &y,int n)

{

	if (x.DD < n)

	{

		y.DD = x.DD + 1;

		y.MM = x.MM;

		y.YYYY = x.YYYY;

	}

	else

	{

		if (x.MM != 12)

		{

			y.DD = 1;

			y.MM = x.MM + 1;

			y.YYYY = x.YYYY;

		}

		else

		{

			y.DD = 1;

			y.MM = 1;

			y.YYYY = x.YYYY + 1;

		}

	}

}


void Nhap1 (HS &A)

{

    cout<<"Nhap ten: "<<endl;

    gets(A.ten);

    fflush(stdin);

    cout<<"Diem toan: "<<endl;

    cin>>A.toan;

    cout<<"Diem van: "<<endl;

    cin>>A.van;

    A.dtb= (float)(A.toan+A.van)/2;

}


void Xuat1(HS A)

{

    cout<<"Ten: "<<A.ten<<endl;

    cout<<"DTB: "<<A.dtb<<endl;

}


int main()

{

	OD Day1, Day2;

	int LastDay;

	Nhap(Day1,LastDay);

	NextDay(Day1, Day2, LastDay);

    cout << "Ngay ke tiep la: " << Day2.DD << "/" << Day2.MM << "/" << Day2.YYYY;

    HS A;

    Nhap1(A);

    Xuat1(A);

	return 0;

}
