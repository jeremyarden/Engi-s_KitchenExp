/* NIM : 13517101
 Nama : Jeremy Arden Hartono
 Tanggal : 2 September 2018
 Topik Praktikum : ADT Jam
 Deskripsi : membuat abstract data type (ADT) untuk tipe jam
 */

#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "jam.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

{
    return (((0 <= H) && (23 >= H)) && ((0 <= M) && (59 >= M)) && ((0 <= S) && (59 >= 0)));
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
    /* KAMUS LOKAL */
    JAM J;
    
    /* ALGORITMA */
    if (IsJAMValid(HH, MM, SS))
    {
        Hour(J) = HH;
        Minute(J) = MM;
        Second(J) = SS;
    }
    return J;
}

void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
 tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
{
    printf("%d:%d:%d\n", Hour(J), Minute(J), Second(J));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
    /*KAMUS LOKAL */
    long detik;
    
    /* ALGORITMA */
    detik = Hour(J)*3600 + Minute(J)*60 + Second(J);
    return detik;
}

JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
 mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
 N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
    /* KAMUS LOKAL */
    JAM J;
    int H, M, S;
    long N1;
    /* ALGORITMA */
    if (N >= 86400)
    {
        N1 = N % 86400;
        H = N1 / 3600;
        M = (N1 % 3600) / 60;
        S = (N1 % 3600) % 60;
    }
    else
    {
        H = N / 3600;
        M = (N % 3600) / 60;
        S = (N % 3600) % 60;
    }
    
    J = MakeJAM(H, M, S);
    
    return J;
}
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
    J = DetikToJAM(JAMToDetik(J) + 1);
    
    return J;
}
