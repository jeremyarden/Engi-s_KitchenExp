/* NIM/Nama : 13517101/Jeremy Arden Hartono
   Tanggal : 11 September 2018
   Topik : ADT Array
   Deskripsi : membuat ADT untuk Array
*/

#include <stdio.h>
#include "boolean.h"
#include "array.h"
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
   return Neff(T);
}
/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return (IdxMax);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return (IdxMin);
}
IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return (Neff(T));
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((i >= IdxMin) && (i <= IdxMax));
}
boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return ((i >= IdxMin) && (i <= Neff(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (Neff(T) == 100);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    /* KAMUS LOKAL */
    int N;
    boolean valid;
    IdxType i;

    /* ALGORITMA */
    scanf("%d", &N);
    if (N == 0)
    {
        MakeEmpty(T);
    }
    else
    {
        if ((N < 0) || (N > IdxMax))
        {
            while (!IsIdxValid(*T, N))
            {
                scanf("%d", &N);
            }
        }
        Neff(*T) = N;
    }

    for (i = 1; i < Neff(*T); i++)
    {
        scanf("%d", &Elmt(*T, i));
    }
}
void BacaIsiTab (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
    /* KAMUS LOKAL */
    ElType N;
    IdxType i;

    /* ALGORITMA */
    i = IdxMin;
    scanf("%d", &N);
    while (N != -9999 && !IsFull(*T) && i <= IdxMax)
    {
        Elmt(*T, i) = N;
        scanf("%d", &N);
        i++;
    }
    Neff(*T) = i - 1;
}
void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
    IdxType i;

    if(IsEmpty(T))
    {
        printf("Tabel kosong\n");
    }
    else
    {
        for(i = 1; i <= Neff(T); i++)
        {
            printf("[%d]%d\n", i, Elmt(T, i));
        }
    }
}
void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    IdxType i;

    if (IsEmpty(T))
    {
        printf("[]");
    }
    else
    {
        printf("[");
        for (i = 1; i < Neff(T); i++)
        {
            printf("%d,", Elmt(T, i));
        }
        printf("%d]", Elmt(T, Neff(T)));
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
    IdxType i;
    TabInt T;

    for (i = 1; i <= Neff(T1); i++)
    {
        Elmt(T, i) = Elmt(T1, i) + Elmt(T2, i);
    }

    Neff(T) = Neff(T1);

    return T;
}
TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    IdxType i;
    TabInt T;

    for (i = 1; i <= Neff(T1); i++)
    {
        Elmt(T, i) = Elmt(T1, i) - Elmt(T2, i);
    }

    Neff(T) = Neff(T1);

    return T;
}
TabInt KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
    IdxType i;
    TabInt T;

    for (i = 1; i <= Neff(T1); i++)
    {
        Elmt(T, i) = Elmt(T1, i) * Elmt(T2, i);
    }

    Neff(T) = Neff(T1);

    return T;
}
TabInt KaliKons (TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
    IdxType i;
    TabInt T;

    for (i = 1; i <= Neff(Tin); i++)
    {
        Elmt(T, i) = Elmt(Tin, i) * c;
    }

    Neff(T) = Neff(Tin);
    return T;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{

    IdxType i;
    boolean valid;

    if (Neff(T1) != Neff(T2))
    {
        return false;
    }
    else
    {
        valid = true;
        i = 1;
        while ((i < Neff(T1)) && (valid != false))
        {
            if (Elmt(T1, i) == Elmt(T2, i))
            {
                i++;
            }
            else
            {
                valid = false;
            }
        }

        return valid;
    }
}
boolean IsLess (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
{
    int i,j,ls;

   	i = 1;
   	j = 0;
   	if(NbElmt(T1) == NbElmt(T2))
    {
      	while ((i <= T1.Neff) && (j == 0))
        {
      		if (Elmt(T1, i) < Elmt(T2, i))
      		{
      			j = 1;
			}
            else if (Elmt(T1, i) > Elmt(T2, i))
            {
				j = 2;
			}
			i++;
		}
		if (j == 1)
        {
			return true;
		}
		else
        {
			return false;
		}
	}
	else if (Neff(T1) < Neff(T2))
    {
		return true;
    }
    else
    {
        return false;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
	IdxType i;

	if(!IsEmpty(T))
    {
        i = IdxMin;
        while(X != Elmt(T,i) && i < GetLastIdx(T))
        {
            if(X == Elmt(T,i))
            {
                return i;
            }
            else
            {
                i++;
            }
        }
    }
    else
    {
        return IdxUndef;
    }
}
IdxType Search2 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
	IdxType i;
	boolean Found;

	if(!IsEmpty(T))
    {
        Found = false;
        i = GetFirstIdx(T);
        while((!Found) && (i<=NbElmt(T)))
        {
            if(X == Elmt(T,i))
            Found = true;
            i++;
        }
	  	if(Found)
	  	{
			return(i-1);
		}
  	}
	return(IdxUndef);
}

boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
    IdxType i;
    boolean Found;

    Found = false;
    while ((i <= Neff(T)) && Found == false)
    {
        if (Elmt(T, i) == X)
        {
            Found = true;
        }
        else
        {
            i++;
        }
    }

    return Found;
}
boolean SearchSentinel (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C
   yang tidak dipakai dalam definisi tabel */
{
	int i;

	Elmt(T, 0) = 0;
	for (i=1; i<=Neff(T); i++)
    {
		if (Elmt(T, i) == X) {
			Elmt(T, 0) = X;
		}
	}

	return (Elmt(T, 0) == X);
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
    ElType max;
    IdxType i;

    max = 0;
    for (i = 1; i <= Neff(T); i++)
    {
        if ((Elmt(T, i) > max))
        {
            max = Elmt(T, i);
        }
    }

    return max;
}
ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
{
    ElType min;
    IdxType i;

    min = 0;
    for (i = 1; i <= Neff(T); i++)
    {
        if ((Elmt(T, i) < min))
        {
            min = Elmt(T, i);
        }
    }

    return min;
}
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
    IdxType i, temp;

    for (i = 1; i <= Neff(T); i++)
    {
        if (Elmt(T, i) == ValMax(T))
        {
            temp = i;
        }
    }

    return temp;
}

IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{
    IdxType i, temp;

    for (i = 1; i <= Neff(T); i++)
    {
        if (Elmt(T, i) == ValMin(T))
        {
            temp = i;
        }
    }

    return temp;
}
/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
    IdxType i;

    for (i = 1; i <= Neff(Tin); i++)
    {
        Elmt(*Tout, i) = Elmt(Tin, i);
    }
}
TabInt InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
    IdxType i, j;
    TabInt Tout;

    i = Neff(T);
    if (IsEmpty(T))
    {
        MakeEmpty(&Tout);
    }
    else
    {
        for (j = 1; j <= Neff(T); j++)
        {
            Elmt(Tout, j) = Elmt(T, i);
            i--;
        }
    }

    return Tout;
}
boolean IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
    boolean simetris;
    IdxType i, j;

    if (Neff(T) % 2 == 1)
    {
        return false;
    }
    else if (IsEmpty(T))
    {
        return true;
    }
    else
    {
        j = Neff(T);
        i = 1;
        simetris = true;
        do
        {
            if (Elmt(T, j) == Elmt(T, i))
            {
                i++;
                j--;
            }
            else
            {
                simetris = false;
            }
        }
        while ((simetris = true) || (i <= j));

        return simetris;
    }
}

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
    ElType temp;
    IdxType i, j;

    for (i = 1; i <= Neff(*T); i++)
    {
        for (j = i + 1; j < Neff(*T); j++)
        {
            if (Elmt(*T, i) < Elmt(*T, j))
            {
                temp = Elmt(*T, i);
                Elmt(*T, i) = Elmt(*T, j);
                Elmt(*T, j) = temp;
            }
        }
    }
}
void InsSortAsc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
{
    int i,j,k,h,temp;

	for (i=2; i<=Neff(*T); i++) {
		temp = Elmt(*T,i);
		j = i-1;
		while (temp < Elmt(*T,j) && j>1) {
			Elmt(*T,j+1) = Elmt(*T,j);
			j--;
		}
		if (temp >= Elmt(*T,j)) {
			Elmt(*T,j+1) = temp;
		} else {
			Elmt(*T,j+1) = Elmt(*T,j);
			Elmt(*T,j) = temp;
		}
	}
}
/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    Neff(*T) = Neff(*T) + 1;
    Elmt(*T, Neff(*T)) = X;
}
void AddEli (TabInt * T, ElType X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
    int j;

	Neff(*T) += 1;
	if (i < Neff(*T)) {
		for (j = Neff(*T); j > i; j--) {
			Elmt(*T,j) = Elmt(*T,j-1);
		}
		Elmt(*T,i) = X;
	} else {
		Elmt(*T,i) = X;
	}
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    *X = Elmt(*T, Neff(*T));
    Neff(*T) = Neff(*T) - 1;
}
void DelEli (TabInt * T, IdxType i, ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*        Kurangi elemen efektif tabel */
{
    IdxType j;

    *X = Elmt(*T, i);
    for (j = i; j <= Neff(*T); j++)
    {
        Elmt(*T, j) = Elmt(*T, (j+1));
    }

    Neff(*T) = Neff(*T) - 1;
}

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
        jika belum ada elemen yang bernilai X.
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
    int i,j;

	if (Neff(*T) != 0)
    {
		j=0;
		for (i=1; i<=Neff(*T); i++)
		{
            if (Elmt(*T,i) == X)
            {
				j=1;
			}
		}
		if (j==1)
		{
			printf("nilai sudah ada\n");
		}
        else
        {
			Neff(*T) += 1;
			Elmt(*T,Neff(*T)) = X;
		}
    }
    else
    {
		Neff(*T) += 1;
		Elmt (*T,1) = X;
	}
}

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
	int i;
	boolean Found;

	if (T.Neff != 0)
    {
		Found = false;
		i = 1;
		while ((!Found) && (i<=T.Neff))
		{
			if (X == T.TI[i])
			{
				Found = true;
			}
			i++;
		}
		if (Found)
		{
			return (i-1);
		}
        else
        {
			return (IdxUndef);
		}
	}
	else
    {
		return (IdxUndef);
	}
}
ElType MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
    return Elmt(T, Neff(T));
}
ElType MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
    return Elmt(T, IdxMin);
}
void MaxMinUrut (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    *Max = MaxUrut(T);
    *Min = MinUrut(T);
}
void Add1Urut (TabInt * T, ElType X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
    int i,j,k;

	j=0;
	if (Neff(*T) != 100)
    {
		Neff(*T) += 1;
		i = 1;
		while ((i<Neff(*T)) && (j==0))
		{
			if (Elmt(*T,i) > X)
			{
				j = 1;
			}
			i++;
		}
		if (j == 1)
		{
			for (k=Neff(*T); k>=i; k--)
			{
				Elmt(*T,k) = Elmt(*T,k-1);
			}
			Elmt(*T,i-1) = X;
		}
        else
        {
			Elmt(*T,Neff(*T)) = X;
		}
	}
}
void Del1Urut (TabInt * T, ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
    IdxType i, N;

    i = Search1(*T, X);
    DelEli(T, i , X);
    for (N = i-1; N <= Neff(*T); N++)
    {
        Elmt(*T, N) = Elmt(*T, (N+1));
    }
}

