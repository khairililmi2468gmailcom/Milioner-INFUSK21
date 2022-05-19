#include <stdio.h>  //khairil
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

// Deklarasi untuk public
int login();  //kharil
void daftar();  //kharil

void header();  //kiram
void petunjuk();    //kiram
void mainmenu();    //kiram

void quiz1();   //danis
void jikabenar();   //danis
void jikasalah();   //danis

void skor(int); //ghufran
void cheque();  //ghufran

void tentang(); //ghufran

struct biodata
{
    char name[25];
    char username[25];
    char pwd[25];
    int age;
} d;

struct dftr
{
    char uname[25];
    int uang;
} c;

int q1, lifeline;   //varible global agar bisa digunakan di banyak fungsi
 
int main()  //khairil
{
    int n, p = 0;
p1:
    printf("***********************************\n");
    printf("  SELAMAT DATANG \t\t \n");
    printf("        DI \t\t \n");
    printf("WHO WANT TO BE A MILLIONARE \t \n");
    printf("  KELOMPOK 1 INFUSK 21 \t\t \n");
    printf("**********************************\n");
    printf("\n1.Login\n2.Daftar\nMasukkan pilihan : ");
    fflush(stdin);
    scanf("%d", &n);
    system("cls");
    //Opsi di awal : login atau daftar, menggunakan looping tujuan agar 
    switch (n)
    {
    case 1:
    {
        printf("\n\n\n\n");
        p = 1;  //
        login();
        break;
    }
    case 2:
    {
        printf("\n\n\n\n");
        p = 1;
        daftar();
        break;
    }
    default:
    {
        printf("Tekan Enter....");
        system("cls");
        goto p1;    //kembali ke selamat datang
    }
    }
    if (p == 0) 
        goto p1;
    else if (p == 1)
    {
        system("cls");
        petunjuk();
        system("cls");
        header();
        mainmenu();
    }
    return 0;
}

void daftar()
{
    FILE *fp, *fp1;
    fp = fopen("database.bin", "ab");
    fp1 = fopen("username.txt", "a");
    printf("Masukkan Nama Anda: \t");
    scanf("%s", d.name);
    printf("Masukkan Username: \t");
    fflush(stdin);
    scanf("%s", d.username);
    strcpy(c.uname, d.username);
    fprintf(fp1, "%s ", c.uname);
    printf("Masukkan Password: \t");
    fflush(stdin);
    scanf("%s", d.pwd);
    printf("Masukkan Umur Anda: \t");
    scanf("%d", &d.age);
    fwrite(&d, sizeof(d), 1, fp);
    fclose(fp);
    fclose(fp1);
}

int login()
{
    char usr[25], pw[25];
    FILE *fp;
    fp = fopen("database.bin", "rb");
    printf("\t\tUsername:-  ");
    scanf("%s", usr);
    printf("\t\tPassword:-  ");
    fflush(stdin);
    scanf("%s", pw);
    while (!feof(fp))
    {
        fread(&d, sizeof(d), 1, fp);
        if ((strcmp(d.username, usr) == 0) && (strcmp(d.pwd, pw) == 0))
        {
            printf("Login Sukses.....\n");
            getch();
            return 1;
        }
    }
    fclose(fp);
    printf("\n\t\tTolong Masukkan Username dan nama yang valid\n");
    getch();
    system("cls");
    main();
    return 0;
}

void header()
{
    system("cls");
    printf("\t\t");
    printf("\t\t");
    printf("\t\t");
    printf("\n\t===Who Want To Be Millionare====");
    printf("\n\t\t\t\tUSERNAME : %s", d.username);
    printf("\t\t");
    printf("\t\t");
}

void petunjuk()
{
    header();
    printf("\n\tPETUNJUK : \n\n");
    printf("\n\n\t\t1. Satu Level terdiri dari 10 soal\n\t\t dijawab satu peRpatu .\n");
    printf("\n\t\t2. Dimulai dari \n\t\t Rp. 10,000 to Rp. 1 M  \n\t.\n");
    printf("\n\t\t3. Jawablah dengan benar\n\t\t dan kamu akan mendapatkan banyak uang .\n");
    printf("\n\t\t4. Jika kamu salah jawab maka ulangi lagi sampai kamu bisa\n\t\t tetapi harus dimulai dari awal.\n");
    printf("\n\t\t5. Kamu dapat keluar dari geme .");
    getch();
}

void skor(int a) 

{
    FILE *fp;
    fp = fopen("username.txt", "a");   // buat baru jika tidak ada atau tulis ulang
    if (q1 == 1 && a)
    {
        printf("Selamat!!!\nSaudara memenangkan Rp.%d.", 10000);
        c.uang = 10000;
        getch();
    }
    else if (q1 == 1 && a == 0)

    {
        printf("Kerja Bagus...\nKamu tidak membawa pulang uang..");
        c.uang = 0;
        fprintf(fp, "%d\n", c.uang);
        getch();
    }
    else if (q1 == 2 && a)
    {
        printf("Selamat!!!\nsaudara mendapatkan Rp.%d.", 80000);
        c.uang = 80000;
        getch();
    }
    else if (q1 == 2 && a == 0)
    {
        printf("Kerja Bagus.....\nKamu tidak membawa pulang uang..");
        c.uang = 0;
        fprintf(fp, "%d\n", c.uang);
        getch();
    }
    else if (q1 == 3 && a)
    {
        printf("Selamat!!!\nKamu memenangkan Rp.%d.", 160000);
        c.uang = 160000;
        getch();
    }
    else if (q1 == 3 && a == 0)
    {
        printf("Kerja bagus.....\nKamu tidak mendapatkan rupiah..");
        c.uang = 0;
        fprintf(fp, "%d\n", c.uang);
    }
    else if (q1 == 4 && a)
    {
        printf("Selamat!!!\nLKamu mendapatkan uang Rp.250.000");
        printf("\nMenakjubkan!!!!!!Kamu berhasil melewati tahap pertama. Di kirim ke rekening anda sebesar Rp.250.000 .");
        c.uang = 250000;
        getch();
        cheque(c.uang);
    }
    else if (q1 == 4 && a == 0)
    {
        printf("Kerja bagus.....\nTetapi hanya memenangkan Rp.250.000, ayo coba lagi..");
        c.uang = 250000;
        fprintf(fp, "%d\n", c.uang);
        getch();
        cheque(c.uang);
    }
    else if (q1 == 5 && a)
    {
        printf("Selamat!!!\nSaudara mendapatkan Rp.%d.", 320000);
        c.uang = 320000;
        getch();
    }
    else if (q1 == 5 && a == 0)
    {
        printf("Kerja Bagus.....\nKamu mendapatkan Rp.250.000");
        c.uang = 250000;
        fprintf(fp, "%d\n", c.uang);
        getch();
        cheque(c.uang);
    }
    else if (q1 == 6 & a)
    {
        printf("Selamat!!!\nKamu mendapatkan Rp.%d.", 640000);
        c.uang = 640000;
        getch();
    }
    else if (q1 == 6 & a == 0)
    {
        printf("Kerja bagus.....\nkamu membawa pulang Rp.250.000");
        c.uang = 250000;
        fprintf(fp, "%d\n", c.uang);
        getch();
        cheque(c.uang);
    }
    else if (q1 == 7 && a)
    {
        printf("Keren!!!Saudara melewati tahap dua Who want to be Millionare....");
        printf("Selamat!!!\nKamu mendapatkan Rp.%d.", 1250000);
        c.uang = 1250000;
        getch();
        cheque(c.uang);
    }
    else if (q1 == 7 && a == 0)
    {
        printf("Bagus Sekali.....\nKamu bisa membawa pulang Rp.1.250.000");
        c.uang = 250000;
        fprintf(fp, "%d\n", c.uang);
        getch();
        cheque(c.uang);
    }
    else if (q1 == 8 && a)
    {
        printf("Selamat!!!\nKamu mendapatkan Rp.%d.", 2500000);
        c.uang = 2500000;
        getch();
    }
    else if (q1 == 8 && a == 0)
    {
        printf("Kerja bagus.....\nKamu membawa pulang Rp.2.500.000");
        c.uang = 1250000;
        fprintf(fp, "%d\n", c.uang);
        getch();
        cheque(c.uang);
    }
    else if (q1 == 9 && a)
    {
        printf("Selamat!!!\nKamu berhasil mendapatkan  Rp.%d.", 500000);
        c.uang = 500000;
        getch();
    }
    else if (q1 == 9 && a == 0)
    {
        printf("Kerja bagus.....\ntapi hanya dapat Rp.1.250.000");
        c.uang = 1250000;
        fprintf(fp, "%d\n", c.uang);
        getch();
        cheque(c.uang);
    }
    else if (q1 == 10 && a)
    {
        printf("Selamat!!!\nKamu memenangkan Rp.%d.", 1000000);
        printf("\n\t\tYOU ARE A MILLIONAIRE!!");
        c.uang = 1000000;
        fprintf(fp, "%d\n", c.uang);
        getch();
        cheque(c.uang);
    }
    else if (q1 == 10 && a == 0)
    {
        printf("Kerja bagus.....\n Kamu membawa pulang Rp.1.250.000 .");
        c.uang = 1250000;
        fprintf(fp, "%d\n", c.uang);
        getch();
        cheque(c.uang);
    }
}

void cheque(int a) 
{
    system("cls");
    printf("\n\t--------------------------------------------------------------------\n");
    printf("\t|                             *                                     |\n");
    printf("\t|                           ****                                    |\n");
    printf("\t|                         ********                                  |\n");
    printf("\t|                       ************                                |\n");
    printf("\t|                   ****  BANK USK ****           \t\t    |\n");
    printf("\t|                                                                   |\n");
    printf("\t|   Kepada:     %s                          Uang Masuk         |\n", d.username);
    printf("\t|                                                                   |\n");
    printf("\t|                                                                   |\n");
    printf("\t|   Rp. %d                                                 |\n", a);
    printf("\t|                                                                   |\n");
    printf("\t|                                                                   |\n");
    printf("\t|                                                                   |\n");
    printf("\t|  SELAMAT ANDA TELAH MENCAPAI TITIK INI                            |\n");
    printf("\t|                                                                   |\n");
    printf("\t|                                          __________________       |\n");
    printf("\t|                                              %s                    |\n", d.username);
    printf("\t|                                                                   |\n");
    printf("\t|                                                                   |\n");
    printf("\t---------------------------------------------------------------------");
    Beep(1000, 400);
    Beep(500, 400);
    Beep(1200, 400);
    printf("\n\n\t\t\tTekan Enter Untuk Continue...  "); 
    getch();
}

void mainmenu()
{
    while (1) //

    {
        system("cls");
        int pilih;

        header();
        printf("\n\n\t\t\t\t\t*** MAIN MENU ***");
        printf("\n\n\t\t\t\t\t1. Mulai");
        printf("\n\t\t\t\t\t2. petunjuk");
        printf("\n\t\t\t\t\t3. Tentang");
        printf("\n\t\t\t\t\t4. Logout User");
        printf("\n\t\t\t\t\t5. Exit");

        printf("\n\n\t\t\t\t\tPilih menu:  >>>");
        fflush(stdin);
        scanf("%d", &pilih);
        system("cls");
        switch (pilih)
        {
        case 1:
            quiz1();      
            break;

        case 2:
            petunjuk();
            printf("\n\n\t\t\t\t<<<Kembali Ke Menu... >>>");
            getch();
            break;

        case 3:
            tentang();
            break;

        case 4:
            main();

        case 5:
            exit(0);

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            fflush(stdin);
        }
    }
}


void tentang()
{
    header();
    printf("\n\nTENTANG");
    printf("\n\n\nPENCIPTA :  \n");
    printf("\n\n\n1. KHAIRIL ILMI\n2. MUHAMMAD DANIS RABANI\n3. DJULKIRAM HILMI\n4.GHUFRAN ");
    printf("\n\n\nWho Want to be a millionare adalah sebuah game yang terdapat beragam pertanyaan yang harus dijawab. Game ini menawarkan hadiah uang tunai dengan jumlah yang besar bagi pemenangnya.");
    
    getch();
}

void jikabenar()
{
    system("cls");
   
    printf("\t\t*************Selamat!!!***********  \n\n\t\t\t\t Saudara benar.");
   

    Beep(500, 500);
    Beep(1000, 500);
    Beep(1500, 500);
    skor(1);
}

void jikasalah()
{
    system("cls");
    printf("\t\t*************Wah!!!***********  \n\n\t\t\t\t Belum belum benar");
    Beep(5000, 500);
    Beep(4500, 500);
    Beep(3500, 500);
    skor(0);
    printf("\n\n\t\t\t\t Kembali Ke Menu... >> ");
    getch();
    mainmenu();
}

void keluar()
{
    FILE *fp1;
    fp1 = fopen("username.txt", "w");
    header();
    printf("\n\n \t\t\tKamu telah keluar dari game");
    printf("\n\n \t\t\tKamu adalah seorang pemenang ");
    printf("Rp. %d  ", c.uang);
    if (c.uang >= 10000)
        cheque(c.uang);
    fprintf(fp1, "%d\n", c.uang);
    fclose(fp1);
    printf("\n\n\t\t\t\t Kembali Ke Menu... >> ");
    getch();
    mainmenu();
}


void quiz1()
{
    char q, l;
    /*  SOAL 1 */
    q1 = 1;
q111:
    header();
    printf("\n Pertanyaan no. 1");
    printf("\t\t\t\t\t\t\t\t\t\tRp.10.000/-");
    printf("\n\n\t\t\tArti fana adalah....");
    printf("\n\n\t\t\t\tA. tidak kekal");
    printf("\n\t\t\t\tB. kekal");
    printf("\n\t\t\t\tC. abadi");
    printf("\n\t\t\t\tD. tidak ada akhir");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Gunakan");
    }

    printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
    printf("\n\n\t\t\t\t Pilihan mu :  >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'A' :
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':
    {
    q110:
        printf("\n\n\t\t\t\t Buat keputusan mu ::");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Telepon");
        printf("\n\n\t\t\t\t\tPilihan mu :  >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q112;
            break;

        case 'B':
            goto q113;
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q110;
        }

    q112:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 1    Anda menggunakan  50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.10.000/-");
        printf("\n\n\t\t\tArti fana adalah....'?");
        printf("\n\n\t\t\t\tA. tidak kekal");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. tidak ada akhir");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: \n\n\t\t\t\tTelepon");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q113;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q112;
        }
        break;
    }

    q113:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 1    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.10.000/-");
        printf("\n\n\t\t\tArti fana adalah....");
        printf("\n\n\t\t\t\tA. tidak kekal");
        printf("\n\t\t\t\tB. kekal");
        printf("\n\t\t\t\tC. abadi");
        printf("\n\t\t\t\tD. tidak ada akhir");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: 50:50");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Telepons: \n\t\t\t\tA. tidak kekal");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q112;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q113;
        }
    }
    break;
    default:
        printf("\nMasukkan jawaban A - D");
        getch();
        goto q111;
    }
    }

    /*  SOAL 2 */

q121:
    header();
    q1 = 2;
    printf("\n Pertanyaan no. 2");
    printf("\t\t\t\t\t\t\t\t\t\tRp.80.000/-");
    printf("\n\n\t\t\tAllah memiliki sifat Al Karim, artinya Allah Maha");
    printf("\n\n\t\t\t\tA. pemberi keamanan");
    printf("\n\t\t\t\tB. akhir");
    printf("\n\t\t\t\tC. mulia");
    printf("\n\t\t\t\tD. adil");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Gunakan");
    }

    printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
    printf("\n\n\t\t\t\t Pilihan mu :  >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'C':
        jikabenar();
        break;
    case 'B':
    case 'A':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q120:
        printf("\n\n\t\t\t\t Buat keputusan mu ::");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Telepon");
        printf("\n\n\t\t\t\t\tPilihan mu :  >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q122;
            break;

        case 'B':
            goto q123;
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q120;
        }

    q122:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 2    Anda menggunakan  50:50");
        printf("\t\t\t\t\t\t\t\t\t\tRp.80.000/-");
        printf("\n\n\t\t\tAllah memiliki sifat Al Karim, artinya Allah Maha...");
        printf("\n\n\t\t\t\t");
        printf("\n\t\t\t\tB. adil");
        printf("\n\t\t\t\tC. mulia");
        printf("\n\t\t\t\t");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: \n\n\t\t\t\tTelepon");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
            jikasalah();
            break;
        case 'E':
            goto q123;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q122;
        }
        break;
    }

    q123:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 2    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.80.000/-");
        printf("\n\n\t\t\tAllah memiliki sifat Al Karim, artinya Allah Maha...");
        printf("\n\n\t\t\t\tA. pemberi keamanan");
        printf("\n\t\t\t\tB. akhir");
        printf("\n\t\t\t\tC. mulia");
        printf("\n\t\t\t\tD. adil");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: 50:50");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Telepons: \n\t\t\t\tC. 14 to 18");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
        case 'A':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q122;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q123;
        }
    }
    break;
    default:
        printf("\nMasukkan jawaban A - D");
        getch();
        goto q121;
    }
    }

    /*  SOAL 3 */

q131:
    header();
    q1 = 3;
    printf("\n Pertanyaan no. 3");
    printf("\t\t\t\t\t\t\t\t\t\tRp.160.000/-");
    printf("\n\n\t\t\tAllah memiki sifat Al Karim, yang tercantum dalam surah....");
    printf("\n\n\t\t\t\tA. Al Hadid ayat 3");
    printf("\n\t\t\t\tB. Al A’raf ayat 180");
    printf("\n\t\t\t\tC. An Naml ayt 40");
    printf("\n\t\t\t\tD. Taha ayat 8");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Gunakan");
    }

    printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
    printf("\n\n\t\t\t\t Pilihan mu :  >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'C':
        jikabenar();
        break;
    case 'B':
    case 'A':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q130:
        printf("\n\n\t\t\t\t Buat keputusan mu ::");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Telepon");
        printf("\n\n\t\t\t\t\tPilihan mu :  >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q132;
            break;

        case 'B':
            goto q133;
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q130;
        }

    q132:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 1    Anda menggunakan  50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.160.000/-");
        printf("\n\n\t\t\tAllah memiki sifat Al Karim, yang tercantum dalam surah....");
        printf("\n\n\t\t\t\tA. Al Hadid ayat 3");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tC. An Naml ayt 40");
        printf("\n\t\t\t\t");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: \n\n\t\t\t\tTelepon");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q133;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q132;
        }
        break;
    }

    q133:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 3    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.160.000/-");
        printf("\n\n\t\t\tAllah memiki sifat Al Karim, yang tercantum dalam surah....");
        printf("\n\n\t\t\t\tA. Al Hadid ayat 3");
        printf("\n\t\t\t\tB. Al A’raf ayat 180");
        printf("\n\t\t\t\tC. An Naml ayt 40");
        printf("\n\t\t\t\tD. Taha ayat 8");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: 50:50");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Telepons: \n\t\t\t\tC. An Naml ayt 40");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
        case 'A':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q132;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q133;
        }
    }
    break;
    default:
        printf("\nMasukkan jawaban A - D");
        getch();
        goto q131;
    }
    }

    /*  SOAL 4 */

q141:
    header();
    q1 = 4;
    printf("\n Pertanyaan no. 4");
    printf("\t\t\t\t\t\t\t\t\t\tRp.250.000/-");
    printf("\n\n\t\t\tAllah memiliki sifat Al Matin, artinya Allah Maha....");
    printf("\n\n\t\t\t\tA. Pemberi Keamanan");
    printf("\n\t\t\t\tB. Mulia");
    printf("\n\t\t\t\tC. Adil");
    printf("\n\t\t\t\tD. Kokoh ");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Gunakan");
    }

    printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
    printf("\n\n\t\t\t\t Pilihan mu :  >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'D':
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'A':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q140:
        printf("\n\n\t\t\t\t Buat keputusan mu ::");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Telepon");
        printf("\n\n\t\t\t\t\tPilihan mu :  >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q142;
            break;

        case 'B':
            goto q143;
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q140;
        }

    q142:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 4    Anda menggunakan  50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.250.000/-");
        printf("\n\n\t\t\tAllah memiliki sifat Al Matin, artinya Allah Maha....");
        printf("\n\n\t\t\t\tA. Pemberi Keamanan");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. Kokoh ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: \n\n\t\t\t\tTelepon");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'D':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q143;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q142;
        }
        break;
    }

    q143:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 4    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.250.000/-");
        printf("\n\n\t\t\tAllah memiliki sifat Al Matin, artinya Allah Maha....");
        printf("\n\n\t\t\t\tA. Pemberi Keamanan");
        printf("\n\t\t\t\tB. Mulia");
        printf("\n\t\t\t\tC. Adil");
        printf("\n\t\t\t\tD. Kokoh ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: 50:50");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Telepons: \n\t\t\t\tD. Kokoh ");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'D':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q142;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q143;
        }
    }
    break;
    default:
        printf("\nMasukkan jawaban A - D");
        getch();
        goto q141;
    }
    }

/*  SOAL 5 */
q151:
    header();
    q1 = 5;
    printf("\n Pertanyaan no. 5");
    printf("\t\t\t\t\t\t\t\t\t\tRp.320.000/-");
    printf("\n\n\t\t\tJika diketahui himpunan P = {2, 3, 4, 5, 6}, dengan relasi dari P ke Q adalah “½ kalinya dari”. Maka di bawah ini yang termasuk anggota himpunan Q adalah …");
    printf("\n\n\t\t\t\tA. {1, 3/2, 2, 5/2, 3}");
    printf("\n\t\t\t\tB. {4, 6, 8, 10, 12}");
    printf("\n\t\t\t\tC. {1, 2, 3, 4, 5}");
    printf("\n\t\t\t\tD. {2, 3, 4, 5, 6} ");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Gunakan");
    }

    printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
    printf("\n\n\t\t\t\t Pilihan mu :  >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'B':
        jikabenar();
        break;
    case 'A':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q150:
        printf("\n\n\t\t\t\t Buat keputusan mu ::");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Telepon");
        printf("\n\n\t\t\t\t\tPilihan mu :  >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q152;
            break;

        case 'B':
            goto q153;
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q150;
        }

    q152:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 5    Anda menggunakan  50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.320.000/-");
        printf("\n\n\t\t\tJika diketahui himpunan P = {2, 3, 4, 5, 6}, dengan relasi dari P ke Q adalah “½ kalinya dari”. Maka di bawah ini yang termasuk anggota himpunan Q adalah …");
        printf("\n\n\t\t\t\tA. {1, 3/2, 2, 5/2, 3}");
        printf("\n\t\t\t\tB. {4, 6, 8, 10, 12}");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: \n\n\t\t\t\tTelepon");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q153;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q152;
        }
        break;
    }

    q153:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 5    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.320.000/-");
        printf("\n\n\t\t\tJika diketahui himpunan P = {2, 3, 4, 5, 6}, dengan relasi dari P ke Q adalah “½ kalinya dari”. Maka di bawah ini yang termasuk anggota himpunan Q adalah …");
        printf("\n\n\t\t\t\tA. {1, 3/2, 2, 5/2, 3}");
        printf("\n\t\t\t\tB. {4, 6, 8, 10, 12}");
        printf("\n\t\t\t\tC. {1, 2, 3, 4, 5}");
        printf("\n\t\t\t\tD. {2, 3, 4, 5, 6} ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: 50:50");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Telepons: \n\t\t\t\tB. {4, 6, 8, 10, 12}");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'A':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q152;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q153;
        }
    }
    break;
    default:
        printf("\nMasukkan jawaban A - D");
        getch();
        goto q151;
    }
    }

    /*  SOAL 6 */
q161:
    header();
    q1 = 6;
    printf("\n Pertanyaan no. 6");
    printf("\t\t\t\t\t\t\t\t\t\tRp.640.000/-");
    printf("\n\n\t\t\tDiketahui f(x) = 6x - 8, jika f-1(a) = 4, maka nilai 4a - 11 adalah …");
    printf("\n\n\t\t\t\tA. 6 ");
    printf("\n\t\t\t\tB. 11 ");
    printf("\n\t\t\t\tC. 13 ");
    printf("\n\t\t\t\tD. 18  ");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Gunakan");
    }

    printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
    printf("\n\n\t\t\t\t Pilihan mu :  >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'C':
        jikabenar();
        break;
    case 'B':
    case 'A':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q160:
        printf("\n\n\t\t\t\t Buat keputusan mu ::");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Telepon");
        printf("\n\n\t\t\t\t\tPilihan mu :  >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q162;
            break;

        case 'B':
            goto q163;
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q160;
        }

    q162:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 6    Anda menggunakan  50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.640.000/-");
        printf("\n\n\t\t\tDiketahui f(x) = 6x - 8, jika f-1(a) = 4, maka nilai 4a - 11 adalah …'");
        printf("\n\n\t\t\t\t ");
        printf("\n\t\t\t\tB. 11 ");
        printf("\n\t\t\t\tC. 13 ");
        printf("\n\t\t\t\t ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: \n\n\t\t\t\tTelepon");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
            jikasalah();
            break;
        case 'E':
            goto q163;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q162;
        }
        break;
    }

    q163:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 6    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.640.000/-");
        printf("\n\n\t\t\tDiketahui f(x) = 6x - 8, jika f-1(a) = 4, maka nilai 4a - 11 adalah …'");
        printf("\n\n\t\t\t\tA. 6 ");
        printf("\n\t\t\t\tB. 11 ");
        printf("\n\t\t\t\tC. 13 ");
        printf("\n\t\t\t\tD. 18  ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: 50:50");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Telepons: \n\t\t\t\tC. 13 ");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'C':
            jikabenar();
            break;
        case 'B':
        case 'A':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q162;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q163;
        }
    }
    break;
    default:
        printf("\nMasukkan jawaban A - D");
        getch();
        goto q161;
    }
    }

    /*  SOAL 7 */

q171:
    header();
    q1 = 7;
    printf("\n Pertanyaan no. 7");
    printf("\t\t\t\t\t\t\t\t\t\tRp.1.250.000/-");
    printf("\n\n\t\t\tNilai x yang memenuhi agar -x2 + 4x + 5 ≤ 0 adalah …");
    printf("\n\n\t\t\t\tA. x ≥ -5  ");
    printf("\n\t\t\t\tB. x ≥ 5  ");
    printf("\n\t\t\t\tC. x ≥ -1");
    printf("\n\t\t\t\tD. x ≥ 0 ");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Gunakan");
    }

    printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
    printf("\n\n\t\t\t\t Pilihan mu :  >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'B':
        jikabenar();
        break;
    case 'A':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q170:
        printf("\n\n\t\t\t\t Buat keputusan mu ::");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Telepon");
        printf("\n\n\t\t\t\t\tPilihan mu :  >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q172;
            break;

        case 'B':
            goto q173;
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q170;
        }

    q172:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 7    Anda menggunakan  50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.1.250.000/-");
        printf("\n\n\t\t\tNilai x yang memenuhi agar -x2 + 4x + 5 ≤ 0 adalah …");
        printf("\n\n\t\t\t\tA. x ≥ -5  ");
        printf("\n\t\t\t\tB. x ≥ 5  ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: \n\n\t\t\t\tTelepon");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q173;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q172;
        }
        break;
    }

    q173:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 7    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.1.250.000/-");
        printf("\n\n\t\t\tNilai x yang memenuhi agar -x2 + 4x + 5 ≤ 0 adalah …");
        printf("\n\n\t\t\t\tA. x ≥ -5  ");
        printf("\n\t\t\t\tB. x ≥ 5  ");
        printf("\n\t\t\t\tC. x ≥ -1");
        printf("\n\t\t\t\tD. x ≥ 0 ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: 50:50");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Telepons: \n\t\t\t\tB. x ≥ 5  ");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'B':
            jikabenar();
            break;
        case 'A':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q172;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q173;
        }
    }
    break;
    default:
        printf("\nMasukkan jawaban A - D");
        getch();
        goto q171;
    }
    }

    /*  SOAL 8 */

q181:
    header();
    q1 = 8;
    printf("\n Pertanyaan no. 8");
    printf("\t\t\t\t\t\t\t\t\t\tRp.2.500.000/-");
    printf("\n\n\t\t\tJika penyelesaian dari pertidaksamaan adalah q < x < p, maka 3p - 2q adalah …");
    printf("\n\n\t\t\t\tA. 11  ");
    printf("\n\t\t\t\tB. 4  ");
    printf("\n\t\t\t\tC. -4");
    printf("\n\t\t\t\tD. 19 ");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Gunakan");
    }

    printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
    printf("\n\n\t\t\t\t Pilihan mu :  >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'A':
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q180:
        printf("\n\n\t\t\t\t Buat keputusan mu ::");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Telepon");
        printf("\n\n\t\t\t\t\tPilihan mu :  >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q182;
            break;

        case 'B':
            goto q183;
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q180;
        }

    q182:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 8    Anda menggunakan  50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.2.500.000/-");
        printf("\n\n\t\t\tJika penyelesaian dari pertidaksamaan adalah q < x < p, maka 3p - 2q adalah …");
        printf("\n\n\t\t\t\tA. 11  ");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\t");
        printf("\n\t\t\t\tD. 19 ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: \n\n\t\t\t\tTelepon");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q183;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q182;
        }
        break;
    }

    q183:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 8    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.2.500.000/-");
        printf("\n\n\t\t\tJika penyelesaian dari pertidaksamaan adalah q < x < p, maka 3p - 2q adalah …");
        printf("\n\n\t\t\t\tA. 11  ");
        printf("\n\t\t\t\tB. 4  ");
        printf("\n\t\t\t\tC. -4");
        printf("\n\t\t\t\tD. 19 ");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: 50:50");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Telepons: \n\t\t\t\tA. 11  ");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q182;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q183;
        }
    }
    break;
    default:
        printf("\nMasukkan jawaban A - D");
        getch();
        goto q181;
    }
    }

    /*  SOAL 9 */
q191:
    header();
    q1 = 9;
    printf("\n Pertanyaan no. 9\n");
    printf("\t\t\t\t\t\t\t\t\t\tRp.5.000.000/-");
    printf("\n\n\t\t\t Dalam menyusun suatu program,langkah pertama yang harus di lakkukan adalah :");
    printf("\n\n\t\t\t\tA. Membuat algoritma  ");
    printf("\n\t\t\t\tB. Membuat program  ");
    printf("\n\t\t\t\tC. Membeli komputer");
    printf("\n\t\t\t\tD. Mempelajari program");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Gunakan");
    }

    printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
    printf("\n\n\t\t\t\t Pilihan mu :  >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'A':
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'D':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q190:
        printf("\n\n\t\t\t\t Buat keputusan mu ::");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Telepon");
        printf("\n\n\t\t\t\t\tPilihan mu :  >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q192;
            break;

        case 'B':
            goto q193;
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q190;
        }

    q192:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 9    Anda menggunakan  50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.5.000.000/-");
        printf("\n\n\t\t\t Dalam menyusun suatu program,langkah pertama yang harus di lakkukan adalah :");
        printf("\n\n\t\t\t\tA. Membuat algoritma  ");
        printf("\n\t\t\t\t  ");
        printf("\n\t\t\t\tC. Head");
        printf("\n\t\t\t\t");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: \n\n\t\t\t\tTelepon");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Enter your choice >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'C':
            jikasalah();
            break;
        case 'E':
            goto q193;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q192;
        }
        break;
    }

    q193:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 9    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp.5.000.000/-");
        printf("\n\n\t\t\t Dalam menyusun suatu program,langkah pertama yang harus di lakkukan adalah :");
        printf("\n\n\t\t\t\tA. Membuat algoritma  ");
        printf("\n\t\t\t\tB. Membuat program  ");
        printf("\n\t\t\t\tC. Membeli komputer");
        printf("\n\t\t\t\tD. Mempelajari program");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: 50:50");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Telepons: \n\t\t\t\tA. Membuat algoritma ");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'A':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'D':
            jikasalah();
            break;
        case 'E':
            goto q192;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q193;
        }
    }
    break;
    default:
        printf("\nMasukkan jawaban A - D");
        getch();
        goto q191;
    }
    }

    /*  SOAL 10*/

q1101:
    header();
    q1 = 10;
    printf("\n Pertanyaan no. 10");
    printf("\t\t\t\t\t\t\t\t\t\tRp. 10 Jt/-");
    printf("\n\n\t\t\t Pseudocode yang di gunakan pada penulisan algoritma berupa :");
    printf("\n\n\t\t\t\tA. Bahasa Inggris  ");
    printf("\n\t\t\t\tB. Bahasa Rusia  ");
    printf("\n\t\t\t\tC.Bahasa Mesin");
    printf("\n\t\t\t\tD. Bahasa Pemrograman");
    if (lifeline > 0)
    {
        printf("\n\n\t\t\t\tE. Gunakan");
    }

    printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
    printf("\n\n\t\t\t\t Pilihan mu :  >>>");
    fflush(stdin);
    scanf("%c", &q);
    switch (q)
    {
    case 'D' :
        jikabenar();
        break;
    case 'B':
    case 'C':
    case 'A':
        jikasalah();
        break;

    case 'F':
        keluar();
        break;

    case 'E':

    {
    q1100:
        printf("\n\n\t\t\t\t Buat keputusan mu ::");
        printf("\n\n\t\t\t\t A. 50:50");
        printf("\n\n\t\t\t\t B. Telepon");
        printf("\n\n\t\t\t\t\tPilihan mu :  >>> ");
        fflush(stdin);
        scanf("%c", &l);
        switch (l)
        {
        case 'A':
            goto q1102;
            break;

        case 'B':
            goto q1103;
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q1100;
        }

    q1102:
    {
        lifeline = lifeline - 1;
        header();
        printf("\n Pertanyaan no. 10    Anda menggunakan  50:50");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp. 10 Jt/-");
        printf("\n\n\t\t\t Pseudocode yang di gunakan pada penulisan algoritma berupa :");
        printf("\n\n\t\t\t\t ");
        printf("\n\t\t\t\t ");
        printf("\n\t\t\t\tC.Bahasa Mesin");
        printf("\n\t\t\t\tD. Bahasa Pemrograman");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: \n\n\t\t\t\tTelepon");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'D':
            jikabenar();
            break;
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q1103;
            break;
        case 'F':
            keluar();
            break;

        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q1102;
        }
        break;
    }

    q1103:
    {
        lifeline = lifeline - 1;
        header();

        printf("\n Pertanyaan no. 10    Jawablah dengan benar");
        printf("\n\t\t\t\t\t\t\t\t\t\tRp. 10 Jt/-");
        printf("\n\n\t\t\t Pseudocode yang di gunakan pada penulisan algoritma berupa :");
        printf("\n\n\t\t\t\tA. Bahasa Inggris  ");
        printf("\n\t\t\t\tB. Bahasa Rusia  ");
        printf("\n\t\t\t\tC.Bahasa Mesin");
        printf("\n\t\t\t\tD. Bahasa Pemrograman");
        if (lifeline > 0)
        {
            printf("\n\n\t\t\t\tE. Gunakan: 50:50");
        }

        printf("\n\n\t\t\t\tE. Life Line\t F. Keluar Game");
        printf("\n\n\t\t\t\t Telepons: \n\t\t\t\tD. Bahasa Pemrograman");
        printf("\n\n\t\t\t\t Pilihan mu :  >>>");
        fflush(stdin);
        scanf("%c", &q);
        switch (q)
        {
        case 'D':
            jikabenar();
            break;
        case 'B':
        case 'C':
        case 'A':
            jikasalah();
            break;
        case 'E':
            goto q1102;
            break;
        case 'F':
            keluar();
            break;
        default:
            printf("\nMasukkan jawaban A - D");
            getch();
            goto q1103;
        }
    }
    break;
    default:
        printf("\nMasukkan jawaban A - D");
        getch();
        goto q1101;
    }
    }
    return;
}


   
/*
 JAWABAN:
 1: A
 2: C
 3: C
 4: D
 5: B
 6: C
 7: B
 8: A
 9: A
10: D
*/
