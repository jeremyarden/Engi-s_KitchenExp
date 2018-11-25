/* File : queue.c */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
#include "queue.h"

/* ********* Prototype ********* */
boolean QueueIsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return ((Head(Q)==NilQueue)&&(Tail(Q)==NilQueue));
}
boolean QueueIsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return ((Tail(Q)%MaxEl(Q))+1==Head(Q));
}
int QueueNBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (QueueIsEmpty(Q)){
        return 0;
    } else{
        if (Tail(Q)>=Head(Q)){
            return Tail(Q)-Head(Q)+1;
        } else{
            return Tail(Q)+MaxEl(Q)-Head(Q)+1;
        }
    }
}
/* *** Kreator *** */
void QueueCreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T=(infoqueue *) malloc ((Max+1)*sizeof(infoqueue));
    if ((*Q).T != NilQueue ){
        MaxEl(*Q)=Max;
        Head(*Q)=NilQueue;
        Tail(*Q)=NilQueue;
    }else{
        MaxEl(*Q)=NilQueue;
    }
}
/* *** Destruktor *** */
void QueueDeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q)=NilQueue;
    free((*Q).T);
}
/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infoqueue X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    if (QueueIsEmpty(*Q)){
        Head(*Q)=1;
    }
    Tail(*Q)=(Tail(*Q)%MaxEl(*Q))+1;
    InfoTail(*Q)=X;
}
void Del (Queue * Q, infoqueue * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
 Q mungkin kosong */
{
    if (Tail(*Q)==Head(*Q)){
        *X=InfoHead(*Q);
        Head(*Q)=NilQueue;
        Tail(*Q)=NilQueue;
    }else{
        *X=InfoHead(*Q);
        Head(*Q)=(Head(*Q)%MaxEl(*Q))+1;
    }
}
void pindah(Queue *Q,int x,int y){
    int tmp;
    tmp=InfoOrang(*Q,x);
    InfoOrang(*Q,x)=InfoOrang(*Q,y);
    InfoOrang(*Q,y)=tmp;
    tmp=InfoKesabaran(*Q,x);
    InfoKesabaran(*Q,x)=InfoKesabaran(*Q,y);
    InfoKesabaran(*Q,y)=tmp;
}
void Deli (Queue * Q,int i, infoqueue * X){
    int a,until;
    if (Tail(*Q)==Head(*Q)){
        *X=InfoHead(*Q);
        Head(*Q)=NilQueue;
        Tail(*Q)=NilQueue;
    }else{
        if (i>Tail(*Q)){
            until=Tail(*Q)+MaxEl(*Q);
        }else{
            until=Tail(*Q);
        }
        for (a=i+1;i<=until;i++){
            pindah(Q,(a-1)%MaxEl(*Q)+1,a%MaxEl(*Q)+1);
        }
        Tail(*Q)=Tail(*Q)-1;
        if (Tail(*Q)<1){
            Tail(*Q)+=MaxEl(*Q);
        }
    }
}
void CopyQueue(Queue X,Queue *Y){
    Queue save;
    QueueCreateEmpty(&save,999);
    infoqueue e;
    while (!QueueIsEmpty(X)){ 
        Del(&X,&e);
        Add(Y,e);
    }
}
void printQueue(Queue antrian){
    Queue tmp;
    infoqueue X;
    QueueCreateEmpty(&tmp,999);
    CopyQueue(antrian,&tmp);
    printf("Antrian pelanggan\n");
    while (!QueueIsEmpty(tmp)){
        Del(&tmp,&X);
        printf("%d\n",X.orang);
    }
}
