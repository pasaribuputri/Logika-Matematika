#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>
#include "windows_api.c"
#include <time.h>
 #include"materi.c"

      FILE *fp;
      char tampUser[100][50],tampPass[100][50];
      int jmlakun;
      char user[50],pass[50];
      char data[100][5][100];
      int nilai[100];
      int akun=0;
      int poin=0;
      int benar=0,salah=0;
      char nama[50];
    struct DATA{
        char nama[100][100];
        int nilai[100];
      }rank;



      struct tm *Sys_T;
//////////////////////////////////////////////////////
      void warning(int text,int bg);         void readfile();
      void warning2(int text,int bg);       void admin();
      void bg_rainbow();                         void login_user();
      void logo();                                     void daftar();
      void bg(int clr);                              void pilihan();
      void bingkai(int x,int y,int tcolor,int bcolor,int panjang,int lebar);
      void bingkaibergerak(int x,int y,int tcolor,int bcolor,int panjang,int lebar);
      void menu();
      void transisi(int clr);                 void profil();
      void transisi2(int clr);               void totalnilai();
      void transisi3(int clr);               void edit();
      void tampilan_awal();                  
      void materi();
      void animasiLogout();                  void logout();
      void quiz1();
      void quiz2();
      void quiz3();
      void quiz4();
      void quiz5();
      void quiz6();
      void quiz7();
      void quiz8();
      void quiz9();
      void quiz10();
      void quiz11();
      void quiz12();
      void quiz13();
      void quiz14();
      void quiz15();
      void kuncijawaban();
///////////////////////////////////////////////////////
    int vhp();
    int vusia(char*);          int vemail();
    int vkosong(char*);        int vuser(char*);
    int vpass(char*);          int vjk(char*);
/////////////////////////////////////////////////////
char* vnama(char* nama){
char inputan;	
char data1[30]={};
char data2[30]={};
int index=0;
while((inputan=getch())!=13 || index<3 || data1[index-1]==' '  || data1[index-1]=='-'  || data1[index-1]=='\'' )
	{
		if(index<25 && (inputan>='a' && inputan<='z' || inputan>='A' && inputan<='Z' || inputan==' ' && index!=0 && data1[index-1]!=' ' || inputan=='-' && index!=0 && data1[index-1]!='-'
            || inputan=='\'' && index!=0 && data1[index-1]!='\'')){
			printf("%c",inputan);
			data1[index]=inputan;
			index++;
		}else if(inputan==8 && index!=0){
			printf("\b \b");
			index-=1;
		    data1[index]=' ';
		}
	}
	for(int a=0;a<index;a++){
		data2[a]=data1[a];
	}
	strcpy(nama,data2);
    return nama;
}


void validasi_nama(){	
    char inputan;	
    char data1[30]={};
    char data2[30]={};
    int index=0;
    while((inputan=getch())!=13 || index<3 || data1[index-1]==' '  || data1[index-1]=='-'  || data1[index-1]=='\'' )
        {
            if(index<25 && (inputan>='a' && inputan<='z' || inputan>='A' && inputan<='Z' || inputan==' ' && index!=0 && data1[index-1]!=' ' || inputan=='-' && index!=0 && data1[index-1]!='-'
                || inputan=='\'' && index!=0 && data1[index-1]!='\'')){
                printf("%c",inputan);
                data1[index]=inputan;
                index++;
            }else if(inputan==8 && index!=0){
                printf("\b \b");
                index-=1;
                data1[index]=' ';
            }
        }
        for(int a=0;a<index;a++){
            data2[a]=data1[a];
        }
        strcpy(nama,data2);
        strupr(nama);
}

// char* validasi_username1( char* user1){
//     char inputan1;
//     char data1[30]={};
//     char data2[30]={};
//     int index=0;
//     while((inputan1=getch())!=13 || index<8 )
//     {
//         if(index < 16 &&(inputan1 >='a' && inputan1 <='z' || inputan1 >='A' && inputan1 <='Z' || inputan1 >= '0' && inputan1 <='9' && index!=0)){
//             printf("%c",inputan1);
//             data1[index]=inputan1;
//             index++;

//         }else if(inputan1==8 && index!=0){
//             printf("\b \b");
//             index-=1;
//             data1[index]=' ';
//         }
//     }
//     for(int a=0;a<index;a++){
// 		data2[a]=data1[a];
// 	}
// 	strcpy(user1,data2);
//     return user1;
// }

// void validasi_username(){
//     char inputan1;
//     char data1[30]={};
//     char data2[30]={};
//     int index=0;

//     while((inputan1=getch())!=13 || index<8 )
//     {
//         if(index < 16 &&(inputan1 >='a' && inputan1 <='z' || inputan1 >='A' && inputan1 <='Z' || inputan1 >= '0' && inputan1 <='9' && index!=0)){
//             printf("%c",inputan1);
//             data1[index]=inputan1;
//             index++;

//         }else if(inputan1==8 && index!=0){
//             printf("\b \b");
//             index-=1;
//             data1[index]=' ';
//         }
//     }
//     for(int a=0;a<index;a++){
// 		data2[a]=data1[a];
// 	}
// 	strcpy(user1,data2);
// }

// void validasi_nohp(){
//     char inputan1;
//     char data1[30]={};
//     char data2[30]={};
//     int index=0;

//     while((inputan1=getch())!=13 || index<11)
//     {
//         if(inputan1 >= '0' && inputan1 <='9' && index<13)
//         {
//             if((index==0 && inputan1=='0') || (index==1 && inputan1 =='8') || (index==2 && inputan1=='1') || (index==2 && inputan1=='2') || (index==2 && inputan1=='3') || (index==2 && inputan1=='5') || (index==2 && inputan1=='7')
//                 || (index==3 && inputan1=='1') || (index==3 && inputan1=='2') || (index==3 && inputan1=='3') || (index==3 && inputan1=='7') || (index==3 && inputan1=='8') || (index==3 && inputan1=='9')){
//               printf("%c",inputan1);
//               data1[index]=inputan1;
//               index++;
//             }else if(index>=4){
//                 printf("%c",inputan1);
//                 data1[index]=inputan1;
//                 index++;
//             }
//         }else if(inputan1==8 && index!=0){
//             printf("\b \b");
//             index-=1;
//             data1[index]=' ';
//         }
//     }
//     for(int a=0;a<index;a++){
// 		data2[a]=data1[a];
// 	}
// 	// strcpy(handphone,data2);
// }

int validasiEmail(char e[]){
int tamp7=0;
	if (e[0]=='@' || e[0]=='.'|| e[0]>='0' && e[0]<='9'){
  		tamp7++;
	}
for (int x=0;e[x]!=NULL;x++){

	if (e[x]>='a' && e[x]<='z' || e[x]>='A' && e[x]<='Z' || e[x]=='@' || e[x]=='.' || e[x]>='0' && e[x]<='9'){
   	continue;
      }
      tamp7++;
   }
   return tamp7;

}

void warning(int txt, int bckg){
    gotoxy(2,33);color(txt,bckg);printf("NOTE: ");
    gotoxy(2,35);color(txt,bckg);printf("Tekan \"%c\" untuk geser keatas & \"%c\" untuk geser kebawah.",286,287);
    gotoxy(2,36);color(txt,bckg);printf("Tekan \"Enter\" untuk memilih.");
    Sleep(2000);
    gotoxy(2,33);color(txt,bckg);printf("                                                        ");
    gotoxy(2,35);color(txt,bckg);printf("                                                        ");
    gotoxy(2,36);color(txt,bckg);printf("                                                        ");
}

void warning2(int txt, int bckg){
    gotoxy(2,33);color(txt,bckg);printf("NOTE: ");
    gotoxy(2,35);color(txt,bckg);printf("Tekan \"%c\" untuk geser kekiri & \"%c\" untuk geser kekanan.",273,272);
    Sleep(2000);
    gotoxy(2,33);color(txt,bckg);printf("                                                        ");
    gotoxy(2,35);color(txt,bckg);printf("                                                        ");
}

void warning3(int txt, int bckg){
    gotoxy(2,35);color(txt,bckg);printf("NOTE: ");
    gotoxy(2,37);color(txt,bckg);printf("Tekan \"%c\" untuk geser kekiri & \"%c\" untuk geser kekanan.",273,272);
    gotoxy(2,38);color(txt,bckg);printf("Tekan \"Enter\" untuk memilih.");
    Sleep(2000);
    gotoxy(2,35);color(txt,bckg);printf("                                                        ");
    gotoxy(2,37);color(txt,bckg);printf("                                                        ");
     gotoxy(2,38);color(txt,bckg);printf("                                                        ");
}

void animasiLogout(){
    for(int x=0; x<20; x++){
        gotoxy(10+x,38-x);textcolor(14);printf("*");Sleep(50);
        gotoxy(30,38-x);textcolor(14);printf("*");Sleep(50);
        gotoxy(50-x,38-x);textcolor(14);printf("*");Sleep(50);
        gotoxy(10+x,38-x);textcolor(14);printf(" ");
        gotoxy(30,38-x);textcolor(14);printf(" ");
        gotoxy(50-x,38-x);textcolor(0);printf(" ");
    }   
    int x,y,clr;
    srand(time(0));
    for(int a=1;a<=200;a++){
        x = rand()%60;
        if(x<10){
            x+=10;
        }else if(x>48){
            x-=10;
        }
        y = rand()%20;
        if(y<5){
            y+=5;
        }
        clr = rand()%15;
        gotoxy(x,y);textcolor(clr);printf("%c",3);Sleep(1);
    }
    char kata[] = "SAMPAI JUMPA LAGI...";
    for(int x=0;x<strlen(kata);x++){
        gotoxy(20+x,30);textcolor(15);printf("%c",kata[x]);Sleep(100);
    }
}

void logout(){
    transisi(15);
            bg(0);
            char c;
            gotoxy(19,19);color(15,0);printf("Yakin untuk keluar?(y/t)");
            while(c!='y' || c!='Y' || c!='t' || c!='T'){
                gotoxy(57,37);c=getche();
                gotoxy(57,37);printf(" ");
                if(c=='y' || c=='Y'){
                    transisi(BLACK);
                    animasiLogout();
                    Sleep(1000);
                    akun = 0;
                    tampilan_awal();
                }else if(c=='t' || c=='T'){
                    menu();
                }else{
                    gotoxy(19,25);color(15,0);printf("Tekan y/Y atau t/T.");Sleep(1000);
                    gotoxy(19,25);color(15,0);printf("                   ");
                }
            }
}


void bg_rainbow(){
    for(int a=1;a<17;a++){
        for(int x=1; x<=38; x++){
            for(int y=1; y<=58; y++){
                gotoxy(0+y,0+x);color(0+a,0);printf("%c",219);
            }
        }
    }
}

void logo(){
    gotoxy(2,1);color(15,0);printf("%c%c%c %c%c %c%c",219,219,219,219,219,219,219);
    gotoxy(2,2);color(15,0);printf("%c %c %c %c %c",219,219,219,219,219);
    gotoxy(2,3);color(15,0);printf("%c%c%c %c %c %c",219,219,219,219,219,219);
    gotoxy(2,4);color(15,0);printf("%c   %c   %c",219,219,219);
    gotoxy(12,3);color(15,0);printf("LOGIKA");
    gotoxy(12,4);color(15,0);printf("MATEMATIKA");
}
 void logologin(){
gotoxy(3,2);color(0,15);printf("%c%c    %c%c%c%c%c %c%c%c%c%c %c%c %c%c%c  %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(3,3);color(0,15);printf("%c%c    %c%c %c%c %c%c    %c%c %c%c%c  %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(3,4);color(0,15);printf("%c%c    %c%c %c%c %c%c%c%c%c %c%c %c%c %c %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(3,5);color(0,15);printf("%c%c    %c%c %c%c %c%c %c%c %c%c %c%c  %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(3,6);color(0,15);printf("%c%c%c%c%c %c%c%c%c%c %c%c%c%c%c %c%c %c%c  %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
 }

void bg(int clr){
    for(int x=1; x<=38; x++){
        for(int y=1; y<=58; y++){
            gotoxy(0+y,0+x);color(clr,0);printf("%c",219);
        }Sleep(5);
    }
}

void bingkai(int x,int y,int tcolor,int bcolor,int panjang,int lebar){
    for(int z=1; z<=panjang;z++){
        for(int v=1; v<=lebar;v++){
            if(z==1 || v==1 || z==panjang || v==lebar){
                gotoxy(x+v,y+z);color(tcolor,0);printf("%c",219);
            }else{
                gotoxy(x+v,y+z);color(bcolor,0);printf("%c",219);
            }
        }
    }
}

void bingkaibergerak(int x,int y,int tcolor,int bcolor,int panjang,int lebar){
    for(int z=1; z<=panjang;z++){
        for(int v=1; v<=lebar;v++){
            if(z==1 || v==1 || z==panjang || v==lebar){
                gotoxy(x+v,y+z);color(tcolor,0);printf("%c",219);
            }else{
                gotoxy(x+v,y+z);color(bcolor,0);printf("%c",219);
            }
        }Sleep(50);
    }
}

void transisi(int clr){
    for(int x=1; x<=38; x++){
        for(int y=1; y<=58; y++){

                gotoxy(0+y,0+x);color(clr,0);printf("%c",219);
        
        }printf("\n");Sleep(1);
    }
}

void transisi2(int clr){
    for(int x=0; x<58; x++){
        for(int y=0; y<38; y++){
            gotoxy(1+x,1+y);color(clr,0);printf("%c",219);
        }Sleep(1);
    }
}

void transisi3(int clr){
    for(int x=0; x<58; x++){
        for(int y=0; y<38; y++){
            gotoxy(58-x,38-y);color(clr,0);printf("%c",219);
        }Sleep(1);
    }
}

void tampilan_awal(){
    bg(WHITE);
    gotoxy(18,8);color(0,15);printf("      @ @ @ @ @      ");Sleep(5); //1,6-9
    gotoxy(18,9);color(0,15);printf("   @ @       @ @ @   ");Sleep(5); //2,4-112
    gotoxy(25,9);color(6,15);printf("%c %c %c",232,232,232);Sleep(5);
    gotoxy(18,10);color(0,15);printf("  @ @   ! !   @ @ @  ");Sleep(5); //3,3-9
    gotoxy(26,10);color(0,15);printf("| |");Sleep(5);
    gotoxy(24,10);color(6,15);printf("%c",232);Sleep(5);
    gotoxy(30,10);color(6,15);printf("%c",232);Sleep(5);
    gotoxy(18,11);color(0,15);printf(" @ @ * * ! * * @ @ @ ");Sleep(5); //4,2-12
    gotoxy(27,11);color(0,15);printf("|");Sleep(5);
    gotoxy(23,11);color(6,15);printf("%c %c",232,232);Sleep(5);
    gotoxy(29,11);color(6,15);printf("%c %c",232,232);Sleep(5);
    gotoxy(18,12);color(0,15);printf("@ @ @ * | | * @ @ @  ");Sleep(5); //5,1-9
    gotoxy(26,12);color(0,15);printf("| |");Sleep(5);
    gotoxy(24,12);color(6,15);printf("%c",232);Sleep(5);
    gotoxy(30,12);color(6,15);printf("%c",232);Sleep(5);
    gotoxy(18,13);color(0,15);printf("@ @ @ @ * * @ @ @ @  ");Sleep(5); //6,1-9
    gotoxy(26,13);color(6,15);printf("%c %c",232,232);Sleep(5);
    gotoxy(18,14);color(0,15);printf("@ @ @ @ * * @ @ @ @ @");Sleep(5); //7,1-13
    gotoxy(26,14);color(6,15);printf("%c %c",232,232);Sleep(5);
    gotoxy(18,15);color(0,15);printf(" @ @ @ @ @ @ @ @ @ @ ");Sleep(5); //12,2-12
    gotoxy(18,16);color(0,15);printf("  @ @ @ @ @ @ @ @ @  ");Sleep(5); //9,3-9
    gotoxy(18,17);color(0,15);printf("   @ @ @ @ @ @ @ @ @ ");Sleep(5); //112,4-12
    gotoxy(18,18);color(0,15);printf("   @ @ @ @ @ @ @ @ @ ");Sleep(5); //9,4-12
    gotoxy(18,19);color(0,15);printf("   @ @ @ @ @ @       ");Sleep(5); //12,4-9
    gotoxy(18,20);color(0,15);printf("   @ @ @ @ @         ");Sleep(5); 

    char teks[2][20]={"     PM TEST     ","LOGIKA MATEMATIKA"};
    for(int x=0;x<2;x++){
        for(int y=0;y<17;y++){
            gotoxy(20+y,22+x);color(0,15);printf("%c",teks[x][y]);Sleep(75);
        }
    }

        for(int x=1; x<=19;x++){
        gotoxy(2,0+x);color(1,0);printf("%c",219);Sleep(1);
        gotoxy(1,39-x);color(2,0);printf("%c",219);Sleep(1);
        gotoxy(57,0+x);color(1,0);printf("%c",219);Sleep(1);
        gotoxy(58,39-x);color(2,0);printf("%c",219);Sleep(1);
        gotoxy(3,39-x);color(1,0);printf("%c",219);Sleep(1);
        gotoxy(56,39-x);color(1,0);printf("%c",219);Sleep(1);
        gotoxy(4,0+x);color(2,0);printf("%c",219);Sleep(1);
        gotoxy(55,0+x);color(2,0);printf("%c",219);Sleep(1);
    }

    gotoxy(15,26);color(0,15);printf("Press Any Key to Continue.....");
    pause();
    gotoxy(15,26);color(0,15);printf("                              ");
    for(int x=1; x<=25; x++){
        gotoxy(27,26);color(0,15);printf("%d%%",x*4);Sleep(50);
        gotoxy(15+x,27);color(0,15);printf("%C",219);Sleep(50);
    }
    Sleep(10);
    transisi(0);
    pilihan();

}
void logoprofil(){
gotoxy(2,2);color(0,15);printf("%c%c%c%c%c%c %c%c%c%c%c%c %c%c%c%c%c%c %c%c%c%c%c%c %c%c %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(2,3);color(0,15);printf("%c%c  %c%c %c%c  %c%c %c%c  %c%c %c%c     %c%c %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(2,4);color(0,15);printf("%c%c%c%c%c%c %c%c%c%c%c%c %c%c  %c%c %c%c%c%c%c%c %c%c %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(2,5);color(0,15);printf("%c%c     %c%c  %c  %c%c  %c%c %c%c     %c%c %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(2,6);color(0,15);printf("%c%c     %c%c   %c %c%c%c%c%c%c %c%c     %c%c %c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void logomenu(){
gotoxy(13,3);color(15,0);printf("%c%c%c   %c%c%c %c%c%c%c%c %c%c%c    %c%c %c%c  %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(13,4);color(15,0);printf("%c%c %c %c %c%c %c%c    %c%c %c   %c%c %c%c  %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(13,5);color(15,0);printf("%c%c  %c  %c%c %c%c%c%c%c %c%c  %c  %c%c %c%c  %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(13,6);color(15,0);printf("%c%c     %c%c %c%c    %c%c   %c %c%c %c%c  %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(13,7);color(15,0);printf("%c%c     %c%c %c%c%c%c%c %c%c    %c%c%c %c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

}
void readfile(){
        fp=fopen("jmlakun.txt","r");
        fscanf(fp,"%d",&jmlakun);
        fclose(fp);

        fp = fopen("data.txt","r");
        for(int x=0;x<jmlakun;x++){
            fscanf(fp,"%s",&tampUser[x]);
            fscanf(fp,"%s",&tampPass[x]);
        }
        fclose(fp);

        fp = fopen("profil.txt","r");
        for(int a=0;a<jmlakun;a++){
            for(int b=0;b<5;b++){
                fscanf(fp,"%[^\n]\n",&data[a][b]);
            }
            strcpy(rank.nama[a],data[a][0]);
        }
        fclose(fp);
        

        fp = fopen("nilai.txt","r");
        for(int x=0;x<jmlakun;x++){
            fscanf(fp,"%d",&nilai[x]);
            rank.nilai[x] = nilai[x];
        }
        fclose(fp);        
}

void sortirRank(){
    int tamp;
    char tamp2[100];
    for(int x=0; x<jmlakun; x++){
        for(int y=x; y<jmlakun; y++){
            if(rank.nilai[x]<rank.nilai[y]){
                tamp = rank.nilai[x];
                rank.nilai[x] = rank.nilai[y];
                rank.nilai[y] = tamp;
                strcpy(tamp2,rank.nama[x]);
                strcpy(rank.nama[x],rank.nama[y]);
                strcpy(rank.nama[y],tamp2);
            }
        }
    }
}

void ranking(){
    readfile();
    sortirRank();
    transisi(15);
    bingkai(2,1,7,7,35,54);
    int jrk=0;
    gotoxy(20,2);color(0,7);printf("R A N K I N G");
    for(int x=0; x<jmlakun;x++,jrk+=2){
        gotoxy(5,4+jrk);color(0,7);printf("%d. %s  %d",x+1,rank.nama[x],rank.nilai[x]);
    }
    gotoxy(4,36);color(0,7);printf("Tekan Backspace untuk kembali.");
}

void deleteUser(){
    readfile();
    for(int j=0;j<jmlakun;j++){
        if(strcmp(data[akun][0],data[j][0])==0){
            for(int i=j;i<jmlakun;i++){
                strcpy(data[i][0],data[i+1][0]);
                strcpy(data[i][1],data[i+1][1]);
                strcpy(data[i][2],data[i+1][2]);
                strcpy(data[i][3],data[i+1][3]);
                strcpy(data[i][4],data[i+1][4]);
                strcpy(tampUser[i],tampUser[i+1]);
                strcpy(tampPass[i],tampPass[i+1]);
                nilai[i] = nilai[i+1];
            }
            jmlakun--;
            break;
        }
    }
    fp=fopen("profil.txt","w");
    for(int x=0; x<jmlakun; x++){
        fprintf(fp,"%s\n%s\n%s\n%s\n%s\n",data[x][0],data[x][1],data[x][2],data[x][3],data[x][4]);
    }
    fclose(fp);

    fp= fopen("data.txt","w");
    for(int x=0; x<jmlakun; x++){
        fprintf(fp,"%s\n%s\n",tampUser[x],tampPass[x]);
    }
    fclose(fp);

    fp = fopen("nilai.txt","w");
    for(int x=0; x<jmlakun; x++){
        fprintf(fp,"%d\n",nilai[x]);
    }
    fclose(fp);

    fp = fopen("jmlakun.txt","w");
    fprintf(fp,"%d",jmlakun);
    fclose(fp);

    info_pengguna();
}

void menu(){
    readfile();
    time_t Tval;
    Tval = time(NULL);
    Sys_T = localtime(&Tval);
    int waktu = Sys_T->tm_hour;
    int x,tempat=1;
    bg(WHITE);
    bingkai(0,0,15,0,32,58);
    logomenu();
    bingkai(19,10,7,12,3,20);
    bingkai(19,15,7,12,3,20);
    bingkai(19,20,7,12,3,20);
    bingkai(19,25,7,12,3,20);
    bingkai(18,9,9,0,3,20);
    bingkai(18,14,8,0,3,20);
    bingkai(18,19,8,0,3,20);
    bingkai(18,24,8,0,3,20);
    gotoxy(27,16);color(15,0);printf("MATERI");
    gotoxy(27,21);color(15,0);printf("QUIZZ");
    gotoxy(27,26);color(15,0);printf("LOGOUT");
    gotoxy(27,11);color(15,0);printf("PROFIL");
    if(waktu>3 && waktu <=10){
        gotoxy(15,30);color(15,0);printf("Selamat Pagi %s!",data[akun][0]);
    }else if(waktu>10 && waktu<=15){
        gotoxy(15,30);color(15,0);printf("Selamat Siang %s!",data[akun][0]);
    }else if(waktu>15 && waktu<=18){
        gotoxy(15,30);color(15,0);printf("Selamat Sore %s!",data[akun][0]);
    }else if(waktu>18 && waktu<=24 || waktu>=0 && waktu<=3){
        gotoxy(15,30);color(15,0);printf("Selamat Malam %s!",data[akun][0]);
    }
    for(int x=0; x<19; x++){
        gotoxy(9,10+x);color(15,0);printf("/");
        gotoxy(50,10+x);color(15,0);printf("/");
        Sleep(10);
    }
    while(x!=13){
        gotoxy(57,37);x=getche();
        gotoxy(57,37);color(15,15);printf(" ");
        if(x == 80){
            if(tempat==1){
                tempat=2;
                bingkai(18,9,8,0,3,20);
                gotoxy(27,11);color(15,0);printf("PROFIL");
                bingkai(18,14,9,0,3,20);
                gotoxy(27,16);color(15,0);printf("MATERI");
                bingkai(18,19,8,0,3,20);
                gotoxy(27,21);color(15,0);printf("QUIZZ");
                bingkai(18,24,8,0,3,20);
                gotoxy(27,26);color(15,0);printf("LOGOUT");
            }else if(tempat==2){
                tempat=3;
                bingkai(18,14,8,0,3,20);
                gotoxy(27,16);color(15,0);printf("MATERI");
                bingkai(18,19,9,0,3,20);
                gotoxy(27,21);color(15,0);printf("QUIZZ");
                bingkai(18,24,8,0,3,20);
                gotoxy(27,26);color(15,0);printf("LOGOUT");
                bingkai(18,9,8,0,3,20);
                gotoxy(27,11);color(15,0);printf("PROFIL");
            }else if(tempat==3){
                tempat=4;
                bingkai(18,19,8,0,3,20);
                gotoxy(27,21);color(15,0);printf("QUIZZ");
                bingkai(18,24,9,0,3,20);
                gotoxy(27,26);color(15,0);printf("LOGOUT");
                bingkai(18,9,8,0,3,20);
                gotoxy(27,11);color(15,0);printf("PROFIL");
                bingkai(18,14,8,0,3,20);
                gotoxy(27,16);color(15,0);printf("MATERI");
            }else if(tempat==4){
                tempat=1;
                bingkai(18,24,8,0,3,20);
                gotoxy(27,26);color(15,0);printf("LOGOUT");
                bingkai(18,9,9,0,3,20);
                gotoxy(27,11);color(15,0);printf("PROFIL");
                bingkai(18,14,8,0,3,20);
                gotoxy(27,16);color(15,0);printf("MATERI");
                bingkai(18,19,8,0,3,20);
                gotoxy(27,21);color(15,0);printf("QUIZZ");
            }
        }else if(x == 72){
            if(tempat==1){
                tempat=4;
                bingkai(18,19,8,0,3,20);
                gotoxy(27,21);color(15,0);printf("QUIZZ");
                bingkai(18,24,9,0,3,20);
                gotoxy(27,26);color(15,0);printf("LOGOUT");
                bingkai(18,9,8,0,3,20);
                gotoxy(27,11);color(15,0);printf("PROFIL");
                bingkai(18,14,8,0,3,20);
                gotoxy(27,16);color(15,0);printf("MATERI");
            }else if(tempat==2){
                tempat=1;
                bingkai(18,14,8,0,3,20);
                gotoxy(27,16);color(15,0);printf("MATERI");
                bingkai(18,19,8,0,3,20);
                gotoxy(27,21);color(15,0);printf("QUIZZ");
                bingkai(18,24,8,0,3,20);
                gotoxy(27,26);color(15,0);printf("LOGOUT");
                bingkai(18,9,9,0,3,20);
                gotoxy(27,11);color(15,0);printf("PROFIL");
            }else if(tempat==3){
                tempat=2;
                bingkai(18,9,8,0,3,20);
                gotoxy(27,11);color(15,0);printf("PROFIL");
                bingkai(18,14,9,0,3,20);
                gotoxy(27,16);color(15,0);printf("MATERI");
                bingkai(18,19,8,0,3,20);
                gotoxy(27,21);color(15,0);printf("QUIZZ");
                bingkai(18,24,8,0,3,20);
                gotoxy(27,26);color(15,0);printf("LOGOUT");
            }else if(tempat==4){
               tempat=3;
                bingkai(18,24,8,0,3,20);
                gotoxy(27,26);color(15,0);printf("LOGOUT");
                bingkai(18,9,8,0,3,20);
                gotoxy(27,11);color(15,0);printf("PROFIL");
                bingkai(18,14,8,0,3,20);
                gotoxy(27,16);color(15,0);printf("MATERI");
                bingkai(18,19,9,0,3,20);
                gotoxy(27,21);color(15,0);printf("QUIZZ");
            }               
        }else if(x!=0 && x!=13 && x!=80 && x!=72 && x!=224){
            warning(BLACK,WHITE);
        }
    }
    if(tempat==1){
        profil();
    }else if(tempat==2){
        materi();
    }else if(tempat==3){
        quiz1();
    }else if(tempat==4){
        logout();
    }
}

void quiz1(){
    transisi(15);
    bingkai(0,0,15,7,39,58);color(0,7);
    char soal[1];
    gotoxy(4,4);printf(">> QUESTION 1 <<");
    gotoxy(4,6);printf("Ingkaran dari pernyataan 'Tidak benar bahwa jika");
    gotoxy(4,7);printf("Ayu lulus sekolah maka ia dibelikan sepeda'adalah...");
    gotoxy(6,9);printf("A. Ayu lulus sekolah, tetapi ia tidak dibelikan");
    gotoxy(9,10);printf("sepeda");
    gotoxy(6,11);printf("B. Ayu Lulus sekolah dan ia dibelikan ");
    gotoxy(6,13);printf("C. Ayu tidak sekolah,tetapi ia dibelikan");
    gotoxy(9,14);printf("sepeda");
    gotoxy(6,15);printf("D. Ayu tidak sekolah dan ia tidak dibelikan");
    gotoxy(9,16);printf("sepeda");
    gotoxy(6,17);printf("E. Ayu tidak lulus sekolah sehingga ia tidak");
    gotoxy(9,18);printf("dibelikan sepeda");
    gotoxy(6,32);printf(">> ANSWER : ");
    fflush(stdin);
    gotoxy(18,32);gets(soal);
    if(strcmp(soal,"A")==0 || strcmp(soal,"B")==0 || strcmp(soal,"C")==0 || strcmp(soal,"D")==0 || strcmp(soal,"E")==0){
        if(strcmp(soal,"E")==0){
            poin+=1;
            benar++;
        }else{
            poin+=0;
            salah++;
        }
    }else{
        gotoxy(18,32);printf("Gunakan Kapital");Sleep(500);
        quiz1();
    }
    gotoxy(38,38);printf("Next >>>");
    getch();
    gotoxy(38,38);printf("           ");
    quiz2();
}

void quiz2(){
    transisi(15);
    bingkai(0,0,15,7,39,58);color(0,7);
    char soal[1];
    gotoxy(4,4);printf(">> QUESTION 2 <<");
    gotoxy(4,6);printf("Jika ~p menyatakan negasi dari pernyataan");
    gotoxy(4,7);printf("p, dengan ~p bernilai benar dan q bernilai");
    gotoxy(4,8);printf("salah, maka pernyataan berikut bernilai ");
    gotoxy(4,9);printf("benar adalah ....");
    gotoxy(6,11);printf("A. (~p V ~q)^ q");
    gotoxy(6,13);printf("B. (p => q)^ q");
    gotoxy(6,15);printf("C. (~p <=> q) ^ p");
    gotoxy(6,17);printf("D. (p ^ q) => p");
    gotoxy(6,19);printf("E. (~p V q) => p");
    gotoxy(6,32);printf(">> ANSWER : ");
    gotoxy(18,32);gets(soal);
    if(strcmp(soal,"A")==0 || strcmp(soal,"B")==0 || strcmp(soal,"C")==0 || strcmp(soal,"D")==0 || strcmp(soal,"E")==0){
        if(strcmp(soal,"D")==0){
            poin+=1;
            benar++;
        }else{
            poin+=0;
            salah++;
        }
    }else{
        gotoxy(18,32);printf("Gunakan Kapital");Sleep(500);
        gotoxy(18,32);printf("Pilihan hanya A,B,C,D");Sleep(500);
        quiz2();
    }
    gotoxy(38,38);printf("Next >>>");
    getch();
    gotoxy(38,38);printf("           ");
    quiz3();
}
void quiz3(){
    transisi(15);
    bingkai(0,0,15,7,39,58);color(0,7);
    char soal[1];
    gotoxy(4,4);printf(">> QUESTION 3 <<");
    gotoxy(4,6);printf("Jika Adi tidak sombong makan Adi mempunyai");
    gotoxy(4,7);printf("banyak teman. Pada kenyataannya, Adi tidak");
    gotoxy(4,8);printf("mempunyai banyak teman, kesimpulan yang ");
    gotoxy(4,9);printf("yang benar adalah ....");
    gotoxy(6,11);printf("A. Adi pasti sombong");
    gotoxy(6,13);printf("B. Adi mungkin anak yang baik");
    gotoxy(6,15);printf("C. Adi bukan anak yang baik");
    gotoxy(6,17);printf("D. Adi punya beberapa teman");
    gotoxy(6,19);printf("E. Adi anak yang baik");
    gotoxy(6,32);printf(">> ANSWER : ");
    gotoxy(18,32);gets(soal);
    if(strcmp(soal,"A")==0 || strcmp(soal,"B")==0 || strcmp(soal,"C")==0 || strcmp(soal,"D")==0 || strcmp(soal,"E")==0){
        if(strcmp(soal,"A")==0){
            poin+=1;
            benar++;
        }else{
            salah++;
            poin+=0;
        }
    }else{
        gotoxy(18,32);printf("Gunakan Kapital");Sleep(500);
        gotoxy(18,32);printf("Pilihan hanya A,B,C,D");Sleep(500);

        quiz3();
    }
    gotoxy(38,38);printf("Next >>>");
    getch();
    gotoxy(38,38);printf("           ");
    quiz4();
}

void quiz4(){
    transisi(15);
    bingkai(0,0,15,7,39,58);color(0,7);
    char soal[1];
    gotoxy(4,4);printf(">> QUESTION 4 <<");
    gotoxy(4,6);printf("Pernyataan yang setara dengan 'jika setiap");
    gotoxy(4,7);printf("siswa berlaku jujur dalam UN maka nilai UN");
    gotoxy(4,8);printf("menjadi pertimbangan masuk PTN' adalah....");
    gotoxy(6,10);printf("A. Jika ada siswa berlaku tidak jujur dalam");
    gotoxy(9,11);printf("UN maka nilai UN menjadi pertimbangan");
    gotoxy(9,12);printf("masuk PTN");
    gotoxy(6,13);printf("B. Jika nilai UN menjadi pertimbangan masuk");
    gotoxy(9,14);printf("PTN maka setiap siswa berlaku jujur dalam");
    gotoxy(9,15);printf("UN");
    gotoxy(6,15);printf("C. Jika nilai UN tidak menjadi pertimbangan");
    gotoxy(9,16);printf("masuk PTN maka ada siswa tidak berlaku");
    gotoxy(9,17);printf("jujur dalam UN");
    gotoxy(6,18);printf("D. Setiap siswa berlaku jujur dalam UN dan");
    gotoxy(9,19);printf("nilai UN tidak menjadi pertimbangan");
    gotoxy(9,20);printf("masuk PTN");
    gotoxy(6,21);printf("E. Ada siswa tidak berlaku jujur dalam UN");
    gotoxy(9,22);printf("atau nilai UN tidak menjadi pertimbangan");
    gotoxy(9,23);printf("masuk PTN");
    gotoxy(6,32);printf(">> ANSWER : ");
    gotoxy(18,32);gets(soal);
    if(strcmp(soal,"A")==0 || strcmp(soal,"B")==0 || strcmp(soal,"C")==0 || strcmp(soal,"D")==0 || strcmp(soal,"E")==0){
        if(strcmp(soal,"C")==0){
            poin+=1;
            benar++;
        }else{
            poin+=0;
            salah++;
        }
    }else{
        gotoxy(18,32);printf("Gunakan Kapital");Sleep(500);
        gotoxy(18,32);printf("Pilihan hanya A,B,C,D");Sleep(500);

        quiz4();
    }
    gotoxy(38,38);printf("Next >>>");
    getch();
    gotoxy(38,38);printf("           ");
    quiz5();
}

void quiz5(){
    transisi(15);
    bingkai(0,0,15,7,39,58);color(0,7);
    char soal[1];
    gotoxy(4,4);printf(">> QUESTION 5 <<");
    gotoxy(4,6);printf("Aini rajin belajar maka naik kelas.");
    gotoxy(4,7);printf("Aini dapat hadiah atau tidak naik kelas.");
    gotoxy(4,8);printf("Aini rajin belajar.");
    gotoxy(4,9);printf("Kesimpulan yang sah adalah....");
    gotoxy(6,11);printf("A. Aini naik kelas");
    gotoxy(6,13);printf("B. Aini dapat hadiah");
    gotoxy(6,15);printf("C. Aini tidak dapat hadiah");
    gotoxy(6,17);printf("D. Aini naik kelas dan dapat hadiah");
    gotoxy(6,19);printf("E. Aini dapat hadiah atau naik kelas");
    gotoxy(6,32);printf(">> ANSWER : ");
    gotoxy(18,32);gets(soal);
    if(strcmp(soal,"A")==0 || strcmp(soal,"B")==0 || strcmp(soal,"C")==0 || strcmp(soal,"D")==0 || strcmp(soal,"E")==0){
        if(strcmp(soal,"E")==0){
            poin+=1;
            benar++;
        }else{
            poin+=0;
            salah++;
        }
    }else{
        gotoxy(18,32);printf("Gunakan Kapital");Sleep(500);
        gotoxy(18,32);printf("Pilihan hanya A,B,C,D");Sleep(500);

        quiz5();
    }
    gotoxy(38,38);printf("Next >>>");
    getch();
    gotoxy(38,38);printf("           ");
    quiz6();
}

void quiz6(){
    transisi(15);
    bingkai(0,0,15,7,39,58);color(0,7);
    char soal[1];
    gotoxy(4,4);printf(">> QUESTION 6 <<");
    gotoxy(4,6);printf("Diberikan premis-premis sebagai berikut");
    gotoxy(4,7);printf("Premis 1 : Jika harga BBM naik,maka harga");
    gotoxy(4,8);printf("bahan pokok naik.");
    gotoxy(4,9);printf("Premis 2 : Jika harga bahan pokok naik,maka");
    gotoxy(4,10);printf("semua orang tidak senang.");
    gotoxy(4,11);printf("Ingkaran dari kesimpulan tersebut adalah....");
    gotoxy(6,13);printf("A. Harga BBM tidak naik");
    gotoxy(6,15);printf("B. Jika harga bahan pokok naik maka ada");
    gotoxy(9,16);printf("orang yang tidak senang.");
    gotoxy(6,17);printf("C. Harga bahan pokok naik atau ada orang");
    gotoxy(9,18);printf("tidak senang");
    gotoxy(6,19);printf("D. Jika semua orang tidak senang maka harga");
    gotoxy(9,20);printf("bahan pokok naik");
    gotoxy(6,21);printf("E. Harga BBM naik dan ada orang yang");
    gotoxy(9,22);printf("senang");
    gotoxy(6,32);printf(">> ANSWER : ");
    gotoxy(18,32);gets(soal);
    if(strcmp(soal,"A")==0 || strcmp(soal,"B")==0 || strcmp(soal,"C")==0 || strcmp(soal,"D")==0|| strcmp(soal,"E")==0){
        if(strcmp(soal,"E")==0){
            poin+=1;
            benar++;
        }else{
            poin+=0;
            salah++;
        }
    }else{
        gotoxy(18,32);printf("Gunakan Kapital");Sleep(500);
        gotoxy(18,32);printf("Pilihan hanya A,B,C,D");Sleep(500);

        quiz6();
    }
    gotoxy(38,38);printf("Next >>>");
    getch();
    gotoxy(38,38);printf("           ");
    quiz7();
}
void quiz7(){
    transisi(15);
    bingkai(0,0,15,7,39,58);color(0,7);
    char soal[1];
    gotoxy(4,4);printf(">> QUESTION 7 <<");
    gotoxy(4,6);printf("Pernyataan yang ekuivalen dengan pernyataan");
    gotoxy(4,7);printf("'jika semua siswa hadir maka beberapa guru");
    gotoxy(4,8);printf("tidak hadir' adalah ....");
    gotoxy(6,10);printf("A. Beberapa siswa tidak hadir atau beberapa");
    gotoxy(9,11);printf("guru hadir");
    gotoxy(6,12);printf("B. Semua siswa tidak hadir atau beberapa guru");
    gotoxy(9,13);printf("tidak hadir.");
    gotoxy(6,14);printf("C. Beberapa siswa tidak hadir dan semua guru");
    gotoxy(9,15);printf("tidak hadir");
    gotoxy(6,16);printf("D. Beberapa siswa tidak hadir atau beberapa guru");
    gotoxy(9,17);printf("tidak hadir");
    gotoxy(6,18);printf("E. Semua siswa hadir dan beberapa guru hadir");
    gotoxy(6,32);printf(">> ANSWER : ");
    gotoxy(18,32);gets(soal);
    if(strcmp(soal,"A")==0 || strcmp(soal,"B")==0 || strcmp(soal,"C")==0 || strcmp(soal,"D")==0|| strcmp(soal,"E")==0){
        if(strcmp(soal,"A")==0){
            poin+=1;
            benar++;
        }else{
            poin+=0;
            salah++;
        }
    }else{
        gotoxy(18,32);printf("Gunakan Kapital");Sleep(500);
        gotoxy(18,32);printf("Pilihan hanya A,B,C,D");Sleep(500);

        quiz7();
    }
    gotoxy(38,38);printf("Next >>>");
    getch();
    gotoxy(38,38);printf("           ");
    quiz8();
}

void quiz8(){
    transisi(15);
    bingkai(0,0,15,7,39,58);color(0,7);
    char soal[1];
    gotoxy(4,4);printf(">> QUESTION 8 <<");
    gotoxy(4,6);printf("Pernyataan yang setara dengan pernyataan");
    gotoxy(4,7);printf("'Riya tidak mengikuti pelajaran Matematika");
    gotoxy(4,8);printf("atau Riya mendapat tugas menyelesaikan");
    gotoxy(4,9);printf("soal-soal matematika' adalah .... ");
    gotoxy(6,11);printf("A. Jika Riya mengikuti pelajaran Matematika");
    gotoxy(9,12);printf("maka Riya mendapat tugas menyelesaikan");
    gotoxy(9,13);printf("soal-soal Matematika.");
    gotoxy(6,14);printf("B. Jika Riya tidak mengikuti pelajaran");
    gotoxy(9,15);printf("Matematika maka Riya mendapat tugas");
    gotoxy(9,16);printf("menyelesaikan soal-soal Matematika");
    gotoxy(6,17);printf("C. Jika Riya tidak mengikuti pelajaran");
    gotoxy(9,18);printf("Matematika maka Riya tidak mendapat");
    gotoxy(9,19);printf("tugas tidak menyelesaikan soal-soal");
    gotoxy(9,20);printf("Matematika");
    gotoxy(6,21);printf("D. Riya tidak mengikuti pelajaran Matematika");
    gotoxy(9,22);printf("dan Riya mendapat tugas menyelesaikan");
    gotoxy(9,23);printf("soal-soal matematika");
    gotoxy(9,24);printf("Riya tidak mengikuti pelajaran Matematika");
    gotoxy(6,25);printf("E. Riya tidak mengikuti pelajaran Matematika");
    gotoxy(9,26);printf("dan Riya tidak mendapat tugas menyelesaikan");
    gotoxy(9,27);printf("soal-soal matematika");
    gotoxy(6,32);printf(">> ANSWER : ");
    gotoxy(18,32);gets(soal);
    if(strcmp(soal,"A")==0 || strcmp(soal,"B")==0 || strcmp(soal,"C")==0 || strcmp(soal,"D")==0|| strcmp(soal,"E")==0){
        if(strcmp(soal,"A")==0){
            poin+=1;
            benar++;
        }else{
            poin+=0;
            salah++;
        }
    }else{
        gotoxy(18,32);printf("Gunakan Kapital");Sleep(500);
        gotoxy(18,32);printf("Pilihan hanya A,B,C,D");Sleep(500);

        quiz8();
    }
    gotoxy(38,38);printf("Next >>>");
    getch();
    gotoxy(38,38);printf("           ");
    quiz9();
}

void quiz9(){
    transisi(15);
    bingkai(0,0,15,7,39,58);color(0,7);
    char soal[1];
    gotoxy(4,4);printf(">> QUESTION 9 <<");
    gotoxy(4,6);printf("Pernyataan (~p V q) ^ (p V ~q) = p <=> q");
    gotoxy(4,7);printf("ekuivalen dengan pernyataan ....");
    gotoxy(6,9);printf("A. p => q");
    gotoxy(6,11);printf("B. p => ~q");
    gotoxy(6,13);printf("C. ~p => q");
    gotoxy(6,15);printf("D. ~p => ~q");
    gotoxy(6,17);printf("E. p <=> q");
    gotoxy(6,32);printf(">> ANSWER : ");
    gotoxy(18,32);gets(soal);
    if(strcmp(soal,"A")==0 || strcmp(soal,"B")==0 || strcmp(soal,"C")==0 || strcmp(soal,"D")==0|| strcmp(soal,"E")==0){
        if(strcmp(soal,"E")==0){
            poin+=1;
            benar++;
        }else{
            poin+=0;
            salah++;
        }
    }else{
        gotoxy(18,32);printf("Gunakan Kapital");Sleep(500);
        
        quiz9();
    }
    gotoxy(38,38);printf("Next >>>");
    getch();
    gotoxy(38,38);printf("           ");
    quiz10();
}

void quiz10(){
    transisi(15);
    bingkai(0,0,15,7,39,58);color(0,7);
    char soal[1];
    gotoxy(4,4);printf(">> QUESTION 10 <<");
    gotoxy(4,6);printf("Nilai kebenaran yang tepat untuk pernyataan");
    gotoxy(4,7);printf("(p ^ q) ~p pada tabel berikut adalah ....");
    gotoxy(4,8);
    bingkai(4,7,0,7,3,10);bingkai(13,7,0,7,3,10);bingkai(22,7,0,7,3,12);
    bingkai(4,9,0,7,3,10);bingkai(13,9,0,7,3,10);bingkai(22,9,0,7,3,12);
    bingkai(4,11,0,7,3,10);bingkai(13,11,0,7,3,10);bingkai(22,11,0,7,3,12);
    bingkai(4,13,0,7,3,10);bingkai(13,13,0,7,3,10);bingkai(22,13,0,7,3,12);
    bingkai(4,15,0,7,3,10);bingkai(13,15,0,7,3,10);bingkai(22,15,0,7,3,12);
    color(0,7);gotoxy(9,9);printf("p");color(0,7);gotoxy(18,9);printf("q");color(0,7);gotoxy(25,9);printf("(p^q)=>~p");
    color(0,7);gotoxy(9,11);printf("B");color(0,7);gotoxy(18,11);printf("B");color(0,7);gotoxy(27,11);printf(" ");
    color(0,7);gotoxy(9,13);printf("B");color(0,7);gotoxy(18,13);printf("S");color(0,7);gotoxy(27,13);printf(" ");
    color(0,7);gotoxy(9,15);printf("S");color(0,7);gotoxy(18,15);printf("B");color(0,7);gotoxy(27,15);printf(" ");
    color(0,7);gotoxy(9,17);printf("S");color(0,7);gotoxy(18,17);printf("S");color(0,7);gotoxy(27,17);printf("");
    gotoxy(6,20);printf("A. SBSB");
    gotoxy(6,22);printf("B. SSSB");
    gotoxy(6,24);printf("C. SSBB");
    gotoxy(6,26);printf("D. SBBB");
    gotoxy(6,28);printf("E. BBBB");
    gotoxy(6,32);printf(">> ANSWER : ");
    gotoxy(18,32);gets(soal);
    if(strcmp(soal,"A")==0 || strcmp(soal,"B")==0 || strcmp(soal,"C")==0 || strcmp(soal,"D")==0|| strcmp(soal,"E")==0){
        if(strcmp(soal,"D")==0){
            poin+=1;
            benar++;
        }else{
            poin+=0;
            salah++;
        }
    }else{
        gotoxy(18,32);printf("Gunakan Kapital");Sleep(500);
        gotoxy(18,32);printf("Pilihan hanya A,B,C,D");Sleep(500);

        quiz10();
    }
    gotoxy(38,38);printf("Next >>>");
    getch();
    gotoxy(38,38);printf("           ");
    quiz11();
}

void quiz11(){
    transisi(15);
    bingkai(0,0,15,7,39,58);color(0,7);
    char soal[1];
    gotoxy(4,4);printf(">> QUESTION 11 <<");
    gotoxy(4,6);printf("Negasi dari kalimat majemuk : 'Gunung Bromo di Jawa");
    gotoxy(4,7);printf("Timur atau Bunaken di Sulawesi Utara' adalah ....");
    gotoxy(6,9);printf("A. Gunung Bromo di Jawa timur atau Bunaken ");
    gotoxy(9,10);printf("tidak di Sulawesi Utara");
    gotoxy(6,11);printf("B. Gunung Bromo tidak di Jawa Timur dan Bunaken");
    gotoxy(9,12);printf("tidak di Sulawesi Utara");
    gotoxy(6,13);printf("C. Gunung Bromo di Jawa Timur dan Bunaken");
    gotoxy(9,14);printf("tidak di Sulawesi Utara");
    gotoxy(6,15);printf("D. Jika Gunung Bromo di Jawa Timur,maka Bunaken");
    gotoxy(9,16);printf("tidak di Sulawesi Utara");
    gotoxy(6,17);printf("E. Jika Gunung Bromo di Jawa Timur,maka Bunaken");
    gotoxy(9,18);printf("tidak di Sulawesi Utara");
    gotoxy(6,32);printf(">> ANSWER : ");
    gotoxy(18,32);gets(soal);
    if(strcmp(soal,"A")==0 || strcmp(soal,"B")==0 || strcmp(soal,"C")==0 || strcmp(soal,"D")==0|| strcmp(soal,"E")==0){
        if(strcmp(soal,"B")==0){
            poin+=1;
            benar++;
        }else{
            poin+=0;
            salah++;
        }
    }else{
        gotoxy(18,32);printf("Gunakan Kapital");Sleep(500);
        gotoxy(18,32);printf("Pilihan hanya A,B,C,D");Sleep(500);

        quiz11();
    }
    gotoxy(38,38);printf("Next >>>");
    getch();
    gotoxy(38,38);printf("           ");
    quiz12();
}

void quiz12(){
    transisi(15);
    bingkai(0,0,15,7,39,58);color(0,7);
    char soal[1];
    gotoxy(4,4);printf(">> QUESTION 12 <<");
    gotoxy(4,6);printf("Diketahui premis-premis :  ");
    gotoxy(4,7);printf("1) Jika Badu rajin belajar dan patuh pada");
    gotoxy(6,8);printf("orang tua maka Ayah akan membelikan Bola");
    gotoxy(6,9);printf("Basket.");
    gotoxy(4,10);printf("2) Ayah tidak membelikan Bola Basket.");
    gotoxy(4,11);printf("Kesimpulan yang sah adalah ....");
    gotoxy(6,13);printf("A. Badu rajin belajar dan Badu patuh pada");
    gotoxy(9,14);printf("orang tua.");
    gotoxy(6,15);printf("B. Badu rajin belajar dan Badu tidak patuh");
    gotoxy(9,16);printf("pada orang tua");
    gotoxy(6,17);printf("C. Badu tidak rajin belajar atau Badu tidak");
    gotoxy(9,18);printf("patuh pada orang tua");
    gotoxy(6,19);printf("D. Badu tidak rajin belajar atau Badu patuh");
    gotoxy(9,20);printf("pada orang tua");
    gotoxy(6,21);printf("E. Badu rajin belajar atau Badu tidak patuh");
    gotoxy(9,22);printf("pada orang tua");
    gotoxy(6,32);printf(">> ANSWER : ");
    gotoxy(18,32);gets(soal);
    if(strcmp(soal,"A")==0 || strcmp(soal,"B")==0 || strcmp(soal,"C")==0 || strcmp(soal,"D")==0|| strcmp(soal,"E")==0){
        if(strcmp(soal,"C")==0){
            poin+=1;
            benar++;
        }else{
            poin+=0;
            salah++;
        }
    }else{
        gotoxy(18,32);printf("Gunakan Kapital");Sleep(500);
        gotoxy(18,32);printf("Pilihan hanya A,B,C,D");Sleep(500);

        quiz12();
    }
    gotoxy(38,38);printf("Next >>>");
    getch();
    gotoxy(38,38);printf("           ");
    quiz13();
}

void quiz13(){
    transisi(15);
    bingkai(0,0,15,7,39,58);color(0,7);
    char soal[1];
gotoxy(4,4);color(0,7);printf(">> QUESTION 13 <<");
gotoxy(12,6);color(0,7);printf("Berapakah angka yang tepat untuk");
gotoxy(12,7);color(0,7);printf("mengisi yang kosong?");
gotoxy(15,8);color(0,7);printf("  6 ------------------- 3  ");
gotoxy(15,9);color(0,7);printf("|---                   ---|");
gotoxy(28,9);color(4,7);printf("?");
gotoxy(15,10);color(0,7);printf("|                         |");
gotoxy(15,11);color(0,7);printf("| 12                   15 |");
gotoxy(15,12);color(0,7);printf("|                         |");  
gotoxy(15,13);color(0,7);printf("|---        10         ---|");
gotoxy(15,14);color(0,7);printf("  2 ------------------- 5  ");
gotoxy(15,17);color(0,7);printf("A. 18");
gotoxy(35,17);color(0,7);printf("B. 38");
gotoxy(15,19);color(0,7);printf("C. 28");
gotoxy(35,19);color(0,7);printf("D. 19");
gotoxy(15,21);color(0,7);printf("E. 48");
gotoxy(6,32);printf(">> ANSWER : ");
gotoxy(18,32);gets(soal);
if(strcmp(soal,"A")==0 || strcmp(soal,"B")==0 || strcmp(soal,"C")==0 || strcmp(soal,"D")==0|| strcmp(soal,"E")==0){
        if(strcmp(soal,"A")==0){
            poin+=1;
            benar++;
        }else{
            poin+=0;
            salah++;
        }
    }else{
        gotoxy(18,32);printf("Gunakan Kapital");Sleep(500);
        gotoxy(18,32);printf("Pilihan hanya A,B,C,D");Sleep(500);

        quiz13();
    }
    gotoxy(38,38);printf("Next >>>");
    getch();
    gotoxy(38,38);printf("           ");
    quiz14();
}

void quiz14(){
    transisi(15);
    bingkai(0,0,15,7,39,58);color(0,7);
    char soal[100];
    gotoxy(4,4);color(0,7);printf(">> QUESTION 14 <<");
    gotoxy(12,6);color(0,7);printf("Berapakah Hasilnya ? ");
    gotoxy(18,8);color(0,7);printf("1 + 1 = 121");
    gotoxy(18,9);color(0,7);printf("1 + 2 = 134");
    gotoxy(18,10);color(0,7);printf("2 + 2 = 444");
    gotoxy(18,11);color(0,7);printf("3 + 3 = ???");
    gotoxy(14,13);color(0,7);printf("A. 898");
    gotoxy(24,13);color(0,7);printf("B. 565");
    gotoxy(14,15);color(0,7);printf("C. 969");
    gotoxy(24,15);color(0,7);printf("D. 797");
    gotoxy(14,17);color(0,7);printf("E. 666");
    gotoxy(6,32);color(0,7);printf(">> ANSWER : ");
    gotoxy(18,32);color(0,7);gets(soal);
    if(strcmp(soal,"A")==0 || strcmp(soal,"B")==0 || strcmp(soal,"C")==0 || strcmp(soal,"D")==0|| strcmp(soal,"E")==0){
        if(strcmp(soal,"C")==0){
            poin+=1;
            benar++;
        }else{
            poin+=0;
            salah++;
        }
    }else{
        gotoxy(18,32);printf("Gunakan Kapital");Sleep(500);
        gotoxy(18,32);printf("Pilihan hanya A,B,C,D");Sleep(500);

        quiz14();
    }
    gotoxy(38,38);printf("Next >>>");
    getch();
    gotoxy(38,38);printf("           ");
    quiz15();
}

void quiz15(){
    transisi(15);
    bingkai(0,0,15,7,39,58);color(0,7);
    char soal[100];
    gotoxy(4,4);color(0,7);printf(">> QUESTION 15 <<");
    gotoxy(16,7);color(0,7);printf("14 Februari = 16");
    gotoxy(16,8);color(0,7);printf("9  Maret    = 12");
    gotoxy(16,9);color(0,7);printf("20 Juni     = 26");
    gotoxy(16,10);color(0,7);printf("15 Oktober = ???");
    gotoxy(6,11);color(0,7);printf("Berapakah jawabannya ....");
    gotoxy(6,13);color(0,7);printf("A. 32");
    gotoxy(6,15);color(0,7);printf("B. 25");
    gotoxy(6,17);color(0,7);printf("C. 27");
    gotoxy(6,19);color(0,7);printf("D. 45");
    gotoxy(6,21);color(0,7);printf("E. 47");
    gotoxy(6,32);color(0,7);printf(">> ANSWER : ");
    gotoxy(18,32);color(0,7);gets(soal);
    if(strcmp(soal,"A")==0 || strcmp(soal,"B")==0 || strcmp(soal,"C")==0 || strcmp(soal,"D")==0|| strcmp(soal,"E")==0){
        if(strcmp(soal,"B")==0){
            poin+=1;
            benar++;
        }else{
            poin+=0;
            salah++;
        }
    }else{
        gotoxy(18,32);printf("Gunakan Kapital");Sleep(500);
        gotoxy(18,32);printf("Pilihan hanya A,B,C,D");Sleep(500);

        quiz15();
    }
    gotoxy(38,38);printf("Next >>>");
    getch();
    gotoxy(38,38);printf("           ");
    totalnilai();
}

void totalnilai(){
    int x,tempat=1;
    readfile();
    transisi(15);
    bingkai(0,0,15,7,39,58);
    bingkai(13,8,8,0,16,30);
    char name[]="P O I N M U ";
    for(int a=0;a<strlen(name);a++){
        gotoxy(19+a,7);color(0,7);printf("%c",name[a]);Sleep(50);
    }
    int y=0;
    while(y<2){
    char titik[]=". . . . . ";
    for(int a=0;a<strlen(titik);a++){
        gotoxy(30+a,7);printf("            ");
        gotoxy(30+a,7);printf("%c",titik[a]);Sleep(200);
    }
    y++;
    }
    int tamp=(poin *6.66);
    bingkai(19,10,15,0,4,19);color(15,0);gotoxy(29,13);printf("%d",tamp);
    nilai[akun] = tamp;
    fp = fopen("nilai.txt","w");
    for(int x=0; x<jmlakun;x++){
        fprintf(fp,"%d\n",nilai[x]);
    }
    fclose(fp);

    gotoxy(20,16);color(10,0);printf("Correct");
    gotoxy(33,16);color(4,0);printf("Wrong");
    gotoxy(23,17);color(15,0);printf("%d",benar);
    gotoxy(35,17);color(15,0);printf("%d",salah);
    if(tamp>=0 && tamp<70){
        gotoxy(22,19);color(15,0);printf("TETAP SEMANGAT");
        gotoxy(26,20);color(15,0);printf("UNTUK");
        gotoxy(23,21);color(15,0);printf("BELAJAR LAGI");
        gotoxy(28,22);color(12,0);printf("%c",3);
    }else if(tamp>=70 && tamp<80){
        gotoxy(25,19);color(15,0);printf("YOU ARE");
        gotoxy(27,20);color(15,0);printf("THE");
        gotoxy(26,21);color(15,0);printf("WINNER");
        gotoxy(28,22);color(14,0);printf("%c",5);
    }else if(tamp>=80 && tamp<100){
        gotoxy(21,19);color(15,0);printf("YOU ARE AMAZING!");
        gotoxy(24,20);color(15,0);printf("I PROUD OF");
        gotoxy(27,21);color(15,0);printf("YOU");
        gotoxy(28,22);color(9,0);printf("%c",2);
    }
    benar=0;salah=0;poin=0;
    bingkai(6,30,9,0,3,20);color(15,0);gotoxy(11,32);printf("KUNCI JAWABAN");
    bingkai(32,30,8,0,3,20);color(15,0);gotoxy(39,32);printf("KEMBALI");
    while(x!=13 && x!=27){
        gotoxy(57,37);x=getche();
        gotoxy(57,37);color(7,7);printf(" ");
    if(x == 77){
        if(tempat==1){
        tempat=2;
            bingkai(6,30,8,0,3,20);color(15,0);gotoxy(11,32);printf("KUNCI JAWABAN");
            bingkai(32,30,9,0,3,20);color(15,0);gotoxy(39,32);printf("KEMBALI");
    }else if(tempat==2){
            tempat=1;
            bingkai(6,30,9,0,3,20);color(15,0);gotoxy(11,32);printf("KUNCI JAWABAN");
            bingkai(32,30,8,0,3,20);color(15,0);gotoxy(39,32);printf("KEMBALI");
            }
    }else if(x == 75){
        if(tempat==1){
            tempat=2;
            bingkai(6,30,8,0,3,20);color(15,0);gotoxy(11,32);printf("KUNCI JAWABAN");
            bingkai(32,30,9,0,3,20);color(15,0);gotoxy(39,32);printf("KEMBALI");
        }else if(tempat==2){
            tempat=1;
            bingkai(6,30,9,0,3,20);color(15,0);gotoxy(11,32);printf("KUNCI JAWABAN");
            bingkai(32,30,8,0,3,20);color(15,0);gotoxy(39,32);printf("KEMBALI");
        }
    }else if(x!=13 && x!=77 && x!=75 && x!=224){
            warning3(0,7);
    }
    }  
    if(tempat==1){
        kuncijawaban();
    }else if(tempat==2){
        menu();
    }
 }

void kuncijawaban(){
    int x,tempat=1;
    transisi(15);
    bingkai(0,0,15,7,39,58);color(0,7);
    bingkai(9,4,8,0,25,40);
    gotoxy(19,5);color(0,8);printf("K U N C I J A W A B A N");
    gotoxy(13,7);color(15,0); printf("QUESTION 1  : E");
    gotoxy(13,9);color(15,0); printf("QUESTION 2  : D");
    gotoxy(13,11);color(15,0);printf("QUESTION 3  : A");
    gotoxy(13,13);color(15,0);printf("QUESTION 4  : C");
    gotoxy(13,15);color(15,0);printf("QUESTION 5  : E");
    gotoxy(13,17);color(15,0);printf("QUESTION 6  : E");
    gotoxy(13,19);color(15,0);printf("QUESTION 7  : A");
    gotoxy(13,21);color(15,0);printf("QUESTION 8  : A");
    gotoxy(30,7);color(15,0);printf("QUESTION 9  : E");
    gotoxy(30,9);color(15,0);printf("QUESTION 10 : D");
    gotoxy(30,11);color(15,0);printf("QUESTION 11 : B");
    gotoxy(30,13);color(15,0);printf("QUESTION 12 : C");
    gotoxy(30,15);color(15,0);printf("QUESTION 13 : A");
    gotoxy(30,17);color(15,0);printf("QUESTION 14 : C");
    gotoxy(30,19);color(15,0);printf("QUESTION 15 : B");
    bingkai(6,30,9,0,3,20);color(15,0);gotoxy(12,32);printf("JAWAB LAGI");
    bingkai(32,30,8,0,3,20);color(15,0);gotoxy(40,32);printf("KEMBALI");
    while(x!=13 && x!=27){
        gotoxy(57,37);x=getche();
        gotoxy(57,37);printf(" ");
    if(x == 77){
        if(tempat==1){
        tempat=2;
            bingkai(6,30,8,0,3,20);color(15,0);gotoxy(12,32);printf("JAWAB LAGI");
            bingkai(32,30,9,0,3,20);color(15,0);gotoxy(40,32);printf("KEMBALI");
    }else if(tempat==2){
            tempat=1;
            bingkai(6,30,9,0,3,20);color(15,0);gotoxy(12,32);printf("JAWAB LAGI");
            bingkai(32,30,8,0,3,20);color(15,0);gotoxy(40,32);printf("KEMBALI");
            }
    }else if(x == 75){
        if(tempat==1){
            tempat=2;
            bingkai(6,30,8,0,3,20);color(15,0);gotoxy(12,32);printf("JAWAB LAGI");
            bingkai(32,30,9,0,3,20);color(15,0);gotoxy(40,32);printf("KEMBALI");
        }else if(tempat==2){
            tempat=1;
            bingkai(6,30,9,0,3,20);color(15,0);gotoxy(12,32);printf("JAWAB LAGI");
            bingkai(32,30,8,0,3,20);color(15,0);gotoxy(40,32);printf("KEMBALI");
        }
    }else if(x!=13 && x!=77 && x!=75 && x!=224){
            warning3(0,7);
    }
    }
    if(tempat==1){
        quiz1();
    }else if(tempat==2){
        menu();
    }

}

void materi(){
    transisi(15);
    bingkai(0,0,9,7,39,58);
    materi1();
    int inp=0,mtr=1;
    while(inp!=8){
        gotoxy(57,38);color(7,7);printf(" "); 
        gotoxy(57,38);inp=getche();
        if(inp == 77){
            if(mtr==1){
                mtr=2;
                transisi3(15);
                bingkai(0,0,9,7,39,58);
                color(0,7);
                gotoxy(7,5);materi2();
                gotoxy(2,38);color(0,7);printf("Tekan Backspace untuk kembali.");
            }else if(mtr==2){
                mtr=3;
                transisi3(15);
                bingkai(0,0,9,7,39,58);
                color(0,7);
                gotoxy(7,5);materi3();
                gotoxy(2,38);color(0,7);printf("Tekan Backspace untuk kembali.");             
            }else if(mtr==3){
                mtr=4;
                transisi3(15);
                bingkai(0,0,9,7,39,58);
                color(0,7);
                gotoxy(7,5);materi4();             
                gotoxy(2,38);color(0,7);printf("Tekan Backspace untuk kembali.");
            }else if(mtr==4){
                mtr=5;
                transisi3(15);
                bingkai(0,0,9,7,39,58);
                color(0,7);
                gotoxy(7,5);materi5();              
                gotoxy(2,38);color(0,7);printf("Tekan Backspace untuk kembali.");
            }else if(mtr==5){
                mtr=1;
                transisi3(15);
                bingkai(0,0,9,7,39,58);
                color(0,7);
                gotoxy(7,5);materi1();              
                gotoxy(2,38);color(0,7);printf("Tekan Backspace untuk kembali.");
            }
        }else if(inp == 75){
            if(mtr==1){
                mtr=5;
                transisi2(15);
                bingkai(0,0,9,7,39,58);
                color(0,7);
                gotoxy(7,5);materi5();
                gotoxy(2,38);color(0,7);printf("Tekan Backspace untuk kembali.");
            }else if(mtr==5){
                mtr=4;
                transisi2(15);
                bingkai(0,0,9,7,39,58);
                color(0,7);
                gotoxy(7,5);materi4();              
                gotoxy(2,38);color(0,7);printf("Tekan Backspace untuk kembali.");
            }else if(mtr==4){
                mtr=3;
                transisi2(15);
                bingkai(0,0,9,7,39,58);
                color(0,7);
                gotoxy(7,5);materi3();              
                gotoxy(2,38);color(0,7);printf("Tekan Backspace untuk kembali.");
            }else if(mtr==3){
                mtr=2;
                transisi2(15);
                bingkai(0,0,9,7,39,58);
                color(0,7);
                gotoxy(7,5);materi2();              
                gotoxy(2,38);color(0,7);printf("Tekan Backspace untuk kembali.");
            }else if(mtr==2){
                mtr=1;
                transisi2(15);
                bingkai(0,0,9,7,39,58);
                color(0,7);
                gotoxy(7,5);materi1();               
                gotoxy(2,38);color(0,7);printf("Tekan Backspace untuk kembali.");
            }
        }else if(inp == 8){
            menu();
        }else if(inp!=8 && inp!=75 && inp!=77 && inp!=224){
            warning2(0,7);
        }
    }
}

void profil(){
    transisi(15);
    readfile();
    bingkai(0,0,15,15,39,58);
    logoprofil();
    bingkai(14,7,7,7,25,41);
    bingkai(7,9,8,0,21,43);
    gotoxy(2,37);color(0,15);printf("Tekan Backspace untuk kembali.");
    gotoxy(2,38);color(0,15);printf("Tekan CTRL+R untuk melihat ranking.");
    bingkai(10,12,8,15,1,37);color(15,0);gotoxy(11,12);printf("NAMA           : %s",data[akun][0]);
    bingkai(10,15,8,9,1,37);color(15,0);gotoxy(11,15);printf("JENIS KELAMIN  : %s",data[akun][1]);
    bingkai(10,18,8,9,1,37);color(15,0);gotoxy(11,18);printf("UMUR           : %s",data[akun][2]);
    bingkai(10,21,8,9,1,37);color(15,0);gotoxy(11,21);printf("NO.Hp          : %s",data[akun][3]);
    bingkai(10,24,8,9,1,37);color(15,0);gotoxy(11,24);printf("EMAIL          : %s",data[akun][4]);
    bingkai(10,27,8,9,1,37);color(15,0);gotoxy(11,27);printf("NILAI          : %d",nilai[akun]);
    int inp=0;
    while(inp!=8){
        gotoxy(57,38);
        inp = getche();
        if(inp==8){
            menu();
        }else if(inp == 18){
            ranking();
        }else{
            gotoxy(38,58);color(15,15);printf("");
        }
    }
}

void loginadmin(){
    int y;
    transisi(15);
    char us[20];
    bingkai(17,14,7,12,3,25);
    bingkai(3,2,7,7,34,52);
    gotoxy(19,5);color(0,7);printf("L O G I N  A D M I N");
    do{
    bingkai(16,13,8,0,3,25);gotoxy(19,15);color(15,0);printf("KODE AKSES : ");
    //gotoxy(32,15);gets(us);
    int a=0;
            gotoxy(32,15);color(15,0);us[a] = getch();
            while (us[a] != 13){
            if (us[a] == 8){
                gotoxy(32+a,15);color(15,0);printf(" ");
                a--;
                if(a<0){
                a = 0;
                }
                gotoxy(32+a,15);color(15,0);printf(" ");
                }else{
                gotoxy(32+a,15);color(15,0);printf("*",us[a]);
                a++;
            }
            if(a>6){
                a=6;
                gotoxy(42,21);printf("");
            }
            gotoxy(32+a,15);color(15,0);
            us[a]=getch();
            }
            us[a]='\0';
                if(strcmp(us,"051221")==0){
                    gotoxy(21,19);color(0,7);printf("LOGIN BERHASIL!");Sleep(100);
                    gotoxy(18,27);color(0,7);printf("P R O S E S S");
                    for(int x=1; x<=5; x++){
                        gotoxy(41,27);color(7,7);printf("             ");
                        for(int y=0; y<5; y++){
                            gotoxy(32+y,27);color(0,7);printf(" . ");Sleep(200);
                        }
                    }
                    y=0;
                    admin();
                    break;
                }
                akun++;
                y++;
        if(y!=0){
            bingkaibergerak(16,20,0,4,3,25);
            for(int x=1; x<=3; x++){
                gotoxy(24,22);color(0,4);printf("KODE SALAH!");Sleep(500);
                gotoxy(20,22);color(0,4);printf("                   ");Sleep(500);
            }
            bingkai(16,20,7,7,3,25);
        }else{
            break;
        }
    }while(true);

}
void admin(){
    transisi(WHITE);
        bg(0);
        int x,tempat=1;
        bingkai(0,6,15,15,23,58);
        logo();
        gotoxy(1,38);color(15,0);printf("Tekan \"ESC\" untuk keluar program.");
        bingkai(19,14,7,12,3,20);
        bingkai(19,19,7,12,3,20);
        bingkai(18,18,8,0,3,20);
        gotoxy(25,20);color(15,0);printf("KEMBALI");
        bingkai(18,13,9,0,3,20);
        gotoxy(25,15);color(15,0);printf("INFO USER");
        while(x!=13 && x!=27){
            gotoxy(57,37);x=getche();
            gotoxy(57,37);printf(" ");
            if(x == 80){
                if(tempat==1){
                    tempat=2;
                    bingkai(18,13,8,0,3,20);
                    gotoxy(25,15);color(15,0);printf("INFO USER");
                    bingkai(18,18,9,0,3,20);
                    gotoxy(25,20);color(15,0);printf("KEMBALI");
                }else if(tempat==2){
                    tempat=1;
                    bingkai(18,18,8,0,3,20);
                    gotoxy(25,20);color(15,0);printf("KEMBALI");
                    bingkai(18,13,9,0,3,20);
                    gotoxy(25,15);color(15,0);printf("INFO USER");
                }
            }else if(x == 72){
                if(tempat==1){
                    tempat=2;
                    bingkai(18,13,8,0,3,20);
                    gotoxy(25,15);color(15,0);printf("INFO USER");
                    bingkai(18,18,9,0,3,20);
                    gotoxy(25,20);color(15,0);printf("KEMBALI");               
                }else if(tempat==2){
                    tempat=1;
                    bingkai(18,18,8,0,3,20);
                    gotoxy(25,20);color(15,0);printf("KEMBALI");
                    bingkai(18,13,9,0,3,20);
                    gotoxy(25,15);color(15,0);printf("INFO USER");   
                }             
            }else if(x == 27){
                transisi(WHITE);
                bg(0);
                char c;
                gotoxy(19,19);color(15,0);printf("Yakin untuk keluar?(y/t)");
                while(c!='y' || c!='Y' || c!='t' || c!='T'){
                    gotoxy(57,37);c=getche();
                    gotoxy(57,37);printf(" ");
                    if(c=='y' || c=='Y'){
                        char teks1[20]={"Terima Kasih...."};
                        gotoxy(19,19);color(15,0);printf("                               ");
                        for(int x=0; x<16; x++){
                            gotoxy(21+x,19);color(15,0);printf("%c",teks1[x]);Sleep(100);
                        }
                        exit(0);
                    }else if(c=='t' || c=='T'){
                        pilihan();
                    }else{
                        gotoxy(19,25);color(15,0);printf("Tekan y/Y atau t/T.");Sleep(1000);
                        gotoxy(19,25);color(15,0);printf("                   ");
                    }
                }
            }else if(x!=0 && x!=13 && x!=80 && x!=72 && x!=224){
                warning(WHITE,BLACK);
            }
        }

        if(tempat==1){
            info_pengguna();
        }else if(tempat==2){
            pilihan();
        }
        
}

void login_user(){
        system("cls");
        transisi(0);
        bg(15);
        logologin();
        readfile();
            bingkai(17,14,7,12,3,25);
            bingkai(17,20,7,12,3,25);
            bingkai(16,13,8,0,3,25);gotoxy(19,15);color(15,0);printf("USERNAME :  ");
            bingkai(16,19,8,0,3,25);gotoxy(19,21);color(15,0);printf("PASSWORD : ");
        for(int a=0; a<58; a++){
            gotoxy(58-a,8);color(0,15);printf("%c",219);
            gotoxy(58-a,37);color(1,15);printf("%c",219);
            gotoxy(1+a,38);color(0,15);printf("%c",219);
            if(a<25){
                gotoxy(58-a,2);color(1,15);printf("%c",219);
            }
            if(a<20){
                gotoxy(58-a,4);color(0,15);printf("%c",219);
            }
            if(a<15){
                gotoxy(58-a,6);color(1,15);printf("%c",219);
            }
            Sleep(50);
        }    
        int y=0,z=0,v=0,c=0,d,e;
        for(int x=0; x<68; x++){
             if(x<15 || x>=19 && x<46 ){
                gotoxy(1+y,15+z);color(GREEN,15);printf("%c",272);
                gotoxy(58-y,16-z);color(1,15);printf("%c",273);
                gotoxy(1+y,21+z);color(1,15);printf("%c",272);
                gotoxy(58-y,22-z);color(GREEN,15);printf("%c",273);
                y++;
             }else if(x>=16 && x<19){
                gotoxy(1+y,15+z);color(GREEN,15);printf("%c",287);
                gotoxy(58-y,16-z);color(1,15);printf("%c",286);
                gotoxy(1+y,21+z);color(1,15);printf("%c",287);
                gotoxy(58-y,22-z);color(GREEN,15);printf("%c",286);
                z++;
                v=16-z;
                c=15+z;
                d=21+z;
                e=22-z;
             }else if(x>=48 && x<50){
                gotoxy(58-y,v);color(1,15);printf("%c",287);
                gotoxy(1+y,c);color(GREEN,15);printf("%c",286);
                gotoxy(58-y,e);color(GREEN,15);printf("%c",287);
                gotoxy(1+y,d);color(1,15);printf("%c",286);
                v++;
                c--;
                d--;
                e++;
             }else if(x>=51 && x<67){
                gotoxy(58-y,17-z);color(1,15);printf("%c",273);
                gotoxy(1+y,14+z);color(GREEN,15);printf("%c",272);
                gotoxy(58-y,23-z);color(GREEN,15);printf("%c",273);
                gotoxy(1+y,20+z);color(1,15);printf("%c",272);
                y++;
             }
            Sleep(50);
        }
        while(true){
            int y=0;
            gotoxy(30,15);color(15,0);printf("          ");
            gotoxy(30,21);color(15,0);printf("          ");
            // gotoxy(30,15);color(15,0);scanf("%s",&user);
            int a=0;
            gotoxy(30,15);color(15,0);user[a] = getch();
            while (user[a] != 13){
            if (user[a] == 8){
                gotoxy(30+a,15);color(15,0);printf(" ");
                a--;
                if(a<0){
                a = 0;
                }
                gotoxy(30+a,15);color(15,0);printf(" ");
                }else{
                gotoxy(30+a,15);color(15,0);printf("%c",user[a]);
                a++;
            }
            if(a>10){
                a=10;
                gotoxy(40,21);printf("");
            }
            gotoxy(30+a,15);color(15,0);
            user[a]=getch();
            }
            user[a]='\0';
            // gotoxy(31,21);color(15,0);scanf("%s",&pass);
            int p=0;
            gotoxy(30,21);color(15,0);pass[p] = getch();
            while (pass[p] != 13){
            if (pass[p] == 8){
                gotoxy(30+p,21);color(15,0);printf(" ");
                p--;
                if(p<0){
                p = 0;
                }
                gotoxy(30+p,21);color(15,0);printf(" ");
                }else{
                gotoxy(30+p,21);color(15,0);printf("*");
                p++;
            }
            if(p>10){
                p=10;
                gotoxy(40,21);printf("");
            }
            gotoxy(30+p,21);color(15,0);
            pass[p]=getch();
            }
            pass[p]='\0';

            while(y<jmlakun){
                if(strcmp(tampUser[y],user)==0 && strcmp(tampPass[y],pass)==0){
                    gotoxy(21,26);color(0,15);printf("Login Berhasil!");Sleep(100);
                    gotoxy(20,28);color(0,15);printf("Mohon Menunggu");
                    for(int x=1; x<=5; x++){
                        gotoxy(34,28);color(15,15);printf("        ");
                        for(int y=0; y<5; y++){
                            gotoxy(34+y,28);color(0,15);printf(".");Sleep(200);
                        }
                    }
                    y=0;
                    menu();
                    break;
                }
                akun++;
                y++;
        }
        if(y!=0){
            bingkaibergerak(17,25,GRAY,RED,3,25);
            for(int x=1; x<=3; x++){
                gotoxy(20,27);color(WHITE,RED);printf("Akun Tidak Ditemukan!");Sleep(500);
                gotoxy(20,27);color(RED,RED);printf("                      ");Sleep(500);
            }
            bingkai(17,25,WHITE,WHITE,3,25);
        }else{
            break;
        }
    }
}


void daftar(){
    char nama[50],jk[10],umur[5],nohp[13],email[50],user[50],pass[50];
    int p;
    transisi(15);
    fflush(stdin);
    readfile();
    bingkai(0,0,15,15,39,58);
    gotoxy(29,3);color(0,15);printf("R E G I S T E R");
    bingkai(14,4,8,8,28,42);
    bingkai(5,6,7,0,24,46);
    bingkai(8,9,7,7,1,40);color(15,0);gotoxy(10,9);  printf("NAMA          :");
    bingkai(8,12,7,7,1,40);color(15,0);gotoxy(10,12);printf("JENIS KELAMIN :");
    bingkai(8,15,7,7,1,40);color(15,0);gotoxy(10,15);printf("UMUR          :");
    bingkai(8,18,7,7,1,40);color(15,0);gotoxy(10,18);printf("NO.Hp         :+628");
    bingkai(8,21,7,7,1,40);color(15,0);gotoxy(10,21);printf("EMAIL         : ");
    bingkai(8,24,7,7,1,40);color(15,0);gotoxy(10,24);printf("USERNAME      : ");
    bingkai(8,27,7,7,1,40);color(15,0);gotoxy(10,27);printf("PASSWORD     : ");
    //gotoxy(25,9);gets(nama);
}
void nama(){
    p=0;
            gotoxy(25,9);color(15,0);nama[p] = getch();
            while (nama[p] != 13){
            if (nama[p] == 8){
                gotoxy(25+p,9);color(15,0);printf(" ");
                p--;
                if(p<0){
                p = 0;
                }
                gotoxy(25+p,9);color(15,0);printf("");
                }else{
                gotoxy(25+p,9);color(15,0);printf("%c",nama[p]);
                p++;
            }
            if(p>23){
                p=23;
                gotoxy(45,9);printf("");
            }
            gotoxy(25+p,9);color(15,0);
            nama[p]=getch();
            }
            nama[p]='\0';

            if (strlen(nama)>39){
                gotoxy(25,9);printf("Inputan K");
                Sleep(1000);
                gotoxy(25,9);printf("                                                ");
            }else if (validasi_nama(nama)>0){
                gotoxy(25,9);printf("MAY NOT BEGIN BY WHICH NOT ALPHABET");
                Sleep(1000);
                gotoxy(25,9);printf("                                    ");
                nama();
            }else if (strlen(nama)==0){
                gotoxy(25,9);printf("MAY NOT USE SPACE THE FIRST");
                Sleep(1000);
                gotoxy(25,9);printf("                           ");
                nama();
            }
   //jk();
}
    //gotoxy(25,12);gets(jk);
    p=0;
            gotoxy(25,12);color(15,0);jk[p] = getch();
            while (jk[p] != 13){
            if (jk[p] == 8){
                gotoxy(25+p,12);color(15,0);printf(" ");
                p--;
                if(p<0){
                p = 0;
                }
                gotoxy(25+p,12);color(15,0);printf("");
                }else{
                gotoxy(25+p,12);color(15,0);printf("%c",jk[p]);
                p++;
            }
            if(p>0){
                p=0;
                gotoxy(45,12);printf("");
            }
            gotoxy(25+p,12);color(15,0);
            jk[p]=getch();
            }
            jk[p]='\0';
    //gotoxy(25,15);gets(umur);
     p=0;
            fflush(stdin);
            gotoxy(25,15);color(15,0);umur[p] = getch();
            while (umur[p] != 13){
            if (umur[p] == 8){
                gotoxy(25+p,15);color(15,0);printf(" ");
                p--;
                if(p<0){
                p = 0;
                }
                gotoxy(25+p,15);color(15,0);printf("");
                }else{
                gotoxy(25+p,15);color(15,0);printf("%c",umur[p]);
                p++;
            }
            if(p>1){
                p=1;
                gotoxy(45,15);printf("");
            }
            gotoxy(25+p,15);color(15,0);
            umur[p]=getch();
            }
            umur[p]='\0';
    //gotoxy(29,18);gets(nohp);
     p=0;
            gotoxy(29,18);color(15,0);nohp[p] = getch();
            while (nohp[p] != 13){
            if (nohp[p] == 8){
                gotoxy(29+p,18);color(15,0);printf(" ");
                p--;
                if(p<0){
                p = 0;
                }
                gotoxy(29+p,18);color(15,0);printf("");
                }else{
                gotoxy(29+p,18);color(15,0);printf("%c",nohp[p]);
                p++;
            }
            if(p>11){
                p=11;
                gotoxy(45,18);printf("");
            }
            gotoxy(29+p,18);color(15,0);
            nohp[p]=getch();
            }
            nohp[p]='\0';
    //gotoxy(25,21);gets(email);
    p=0;
            gotoxy(25,21);color(15,0);email[p] = getch();
            while (email[p] != 13){
            if (email[p] == 8){
                gotoxy(25+p,21);color(15,0);printf(" ");
                p--;
                if(p<0){
                p = 0;
                }
                gotoxy(25+p,21);color(15,0);printf("");
                }else{
                gotoxy(25+p,21);color(15,0);printf("%c",email[p]);
                p++;
            }
            if(p>23){
                p=23;
                gotoxy(45,21);printf("");
            }
            gotoxy(25+p,21);color(15,0);
            email[p]=getch();
            }
            email[p]='\0';
    //gotoxy(25,24);gets(user);
    p=0;
            gotoxy(25,24);color(15,0);user[p] = getch();
            while (user[p] != 13){
            if (user[p] == 8){
                gotoxy(25+p,24);color(15,0);printf(" ");
                p--;
                if(p<0){
                p = 0;
                }
                gotoxy(25+p,24);color(15,0);printf("");
                }else{
                gotoxy(25+p,24);color(15,0);printf("%c",user[p]);
                p++;
            }
            if(p>23){
                p=23;
                gotoxy(45,24);printf("");
            }
            gotoxy(25+p,24);color(15,0);
            user[p]=getch();
            }
            user[p]='\0';
    //gotoxy(25,27);gets(pass);
    p=0;
            gotoxy(25,27);color(15,0);pass[p] = getch();
            while (pass[p] != 13){
            if (pass[p] == 8){
                gotoxy(25+p,27);color(15,0);printf(" ");
                p--;
                if(p<0){
                p = 0;
                }
                gotoxy(25+p,27);color(15,0);printf("");
                }else{
                gotoxy(25+p,27);color(15,0);printf("%c",pass[p]);
                p++;
            }
            if(p>23){
                p=23;
                gotoxy(45,27);printf("");
            }
            gotoxy(25+p,27);color(15,0);
            pass[p]=getch();
            }
            pass[p]='\0';

    fp=fopen("profil.txt","a");
    fprintf(fp,"%s\n%s\n%s\n%s\n%s\n",nama,jk,umur,nohp,email);
    fclose(fp);

    fp= fopen("data.txt","a");
    fprintf(fp,"%s\n%s\n",user,pass);
    fclose(fp);

    fp = fopen("nilai.txt","a");
    fprintf(fp,"%d\n",0);
    fclose(fp);

    fp = fopen("jmlakun.txt","w");
    jmlakun++;
    fprintf(fp,"%d",jmlakun);
    fclose(fp);

    gotoxy(15,33);color(BLUE,WHITE);printf("Mohon Menunggu");
    for(int x=1; x<=5; x++){
        gotoxy(30,33);color(WHITE,WHITE);printf("        ");
        for(int y=0; y<5; y++){
            gotoxy(30+y,33);color(BLUE,WHITE);printf(".");Sleep(200);
        }
    }
    gotoxy(18,35);color(BLUE,WHITE);printf("Anda Berhasil Mendaftar!!");
    gotoxy(13,39);color(BLUE,WHITE);printf("Tekan Apa Saja Untuk Lanjut Login.");
    pause();
    login_user();
}
void  info_pengguna(){
    transisi(15);
    readfile();
    int b=0,tempat=1,x,pilih;
    gotoxy(0,0);
    bingkai(0,0,15,15,39,58);
    bingkai(5,3,7,7,35,50);
     
    gotoxy(20,3);color(0,15);printf("D A F T A R  N A M A");
    //gotoxy(4,50);printf("Tekan 0 untuk kembali");

    for(int a=0; a<jmlakun; a++){
        bingkai(15,5+b,8,0,3,28);gotoxy(18,7+b);color(15,0);printf("%s",data[a][0]);
        gotoxy(25,6+b);color(0,8);printf("No.Akun : %d",a+1);
        b+=4;
    }
    bingkai(34,33,15,0,3,20);color(15,0);gotoxy(37,35);printf("Pilih Akun : ");
    gotoxy(49,35);
    while(true){
        fflush(stdin);
        gotoxy(49,35);color(15,0);printf(" ");
        gotoxy(49,35);color(15,0);scanf("%d",&pilih);
        if(pilih==0){
            admin();
            break;
        }else if(pilih<=jmlakun){
            akun=pilih-1;
    transisi(15);
    bingkai(7,5,7,7,29,42);
    bingkai(10,8,8,9,1,37);color(0,7);gotoxy(11,8);printf("NAMA           : %s",data[akun][0]);
    bingkai(10,11,8,9,1,37);color(0,7);gotoxy(11,11);printf("JENIS KELAMIN  : %s",data[akun][1]);
    bingkai(10,14,8,9,1,37);color(0,7);gotoxy(11,14);printf("UMUR           : %s",data[akun][2]);
    bingkai(10,17,8,9,1,37);color(0,7);gotoxy(11,17);printf("NO.Hp          : %s",data[akun][3]);
    bingkai(10,20,8,9,1,37);color(0,7);gotoxy(11,20);printf("EMAIL          : %s",data[akun][4]);
    bingkai(10,23,8,9,1,37);color(0,7);gotoxy(11,23);printf("NILAI          : %d",nilai[akun]);
    bingkai(5,25,9,0,3,20);color(15,0);gotoxy(14,27);printf("EDIT");
    bingkai(31,25,8,0,3,20);color(15,0);gotoxy(39,27);printf("HAPUS");
    bingkai(18,29,8,0,3,20);color(15,0);gotoxy(26,31);printf("KEMBALI");
    while(x!=13 && x!=27){
        fflush(stdin);
        gotoxy(57,37);x=getche();
        gotoxy(57,37);printf(" ");
        if(x == 77){
            if(tempat==1){
                tempat=2;
                bingkai(5,25,8,0,3,20);color(15,0);gotoxy(14,27);printf("EDIT");
                bingkai(31,25,9,0,3,20);color(15,0);gotoxy(39,27);printf("HAPUS");
                bingkai(18,29,8,0,3,20);color(15,0);gotoxy(26,31);printf("KEMBALI");
            }else if(tempat==2){
                tempat=3;
                bingkai(5,25,8,0,3,20);color(15,0);gotoxy(14,27);printf("EDIT");
                bingkai(31,25,8,0,3,20);color(15,0);gotoxy(39,27);printf("HAPUS");
                bingkai(18,29,9,0,3,20);color(15,0);gotoxy(26,31);printf("KEMBALI");
            }else if(tempat==3){
                tempat=1;
                bingkai(5,25,9,0,3,20);color(15,0);gotoxy(14,27);printf("EDIT");
                bingkai(31,25,8,0,3,20);color(15,0);gotoxy(39,27);printf("HAPUS");
                bingkai(18,29,8,0,3,20);color(15,0);gotoxy(26,31);printf("KEMBALI");
            }
        }else if(x == 75){
            if(tempat==1){
                tempat=3;
                bingkai(5,25,8,0,3,20);color(15,0);gotoxy(14,27);printf("EDIT");
                bingkai(31,25,8,0,3,20);color(15,0);gotoxy(39,27);printf("HAPUS");
                bingkai(18,29,9,0,3,20);color(15,0);gotoxy(26,31);printf("KEMBALI");
            }else if(tempat==2){
                tempat=1;
                bingkai(5,25,9,0,3,20);color(15,0);gotoxy(14,27);printf("EDIT");
                bingkai(31,25,8,0,3,20);color(15,0);gotoxy(39,27);printf("HAPUS");
                bingkai(18,29,8,0,3,20);color(15,0);gotoxy(26,31);printf("KEMBALI");
            }else if(tempat == 3){
                tempat = 2;
                bingkai(5,25,8,0,3,20);color(15,0);gotoxy(14,27);printf("EDIT");
                bingkai(31,25,9,0,3,20);color(15,0);gotoxy(39,27);printf("HAPUS");
                bingkai(18,29,8,0,3,20);color(15,0);gotoxy(26,31);printf("KEMBALI");
            }
        }else if(x!=13 && x!=77 && x!=75 && x!=224){
            warning3(0,15);
        }
    }
    if(tempat==1){
        edit();
    }else if(tempat==2){
        deleteUser();
    }else if(tempat==3){
        info_pengguna();
    }
    break;
        }else{
           gotoxy(23,37);color(0,7); printf("Inputan invalid / user tidak ada!");Sleep(1000);
           gotoxy(23,37);color(0,7); printf("                                 ");
        }
    }
}   

void edit(){
    int p;
    transisi(15);
    char nama[50],jk[10],umur[5],nohp[13],email[50],user[50],pass[50];
     bingkai(0,0,15,15,39,58);
    bingkai(0,0,15,15,39,58);    gotoxy(29,3);color(0,15);printf("E D I T  U S E R");
    bingkai(14,4,8,8,28,42);
    bingkai(5,6,7,0,24,46);
    bingkai(8,9,7,7,1,40);color(15,0);gotoxy(11,9);  printf("NAMA          :");
    bingkai(8,12,7,7,1,40);color(15,0);gotoxy(11,12);printf("JENIS KELAMIN :");
    bingkai(8,15,7,7,1,40);color(15,0);gotoxy(11,15);printf("UMUR          :");
    bingkai(8,18,7,7,1,40);color(15,0);gotoxy(11,18);printf("NO.Hp         :+62");
    bingkai(8,21,7,7,1,40);color(15,0);gotoxy(11,21);printf("EMAIL         : ");

    fflush(stdin);
    //gotoxy(26,9);gets(nama);
    p=0;
            gotoxy(26,9);color(15,0);nama[p] = getch();
            while (nama[p] != 13){
            if (nama[p] == 8){
                gotoxy(26+p,9);color(15,0);printf(" ");
                p--;
                if(p<0){
                p = 0;
                }
                gotoxy(26+p,9);color(15,0);printf("");
                }else{
                gotoxy(26+p,9);color(15,0);printf("%c",nama[p]);
                p++;
            }
            if(p>23){
                p=23;
                gotoxy(45,9);printf("");
            }
            gotoxy(26+p,9);color(15,0);
            nama[p]=getch();
            }
            nama[p]='\0';
    //gotoxy(26,12);gets(jk);
    p=0;
            gotoxy(26,12);color(15,0);jk[p] = getch();
            while (jk[p] != 13){
            if (jk[p] == 8){
                gotoxy(26+p,12);color(15,0);printf(" ");
                p--;
                if(p<0){
                p = 0;
                }
                gotoxy(26+p,12);color(15,0);printf("");
                }else{
                gotoxy(26+p,12);color(15,0);printf("%c",jk[p]);
                p++;
            }
            if(p>0){
                p=0;
                gotoxy(45,12);printf("");
            }
            gotoxy(26+p,12);color(15,0);
            jk[p]=getch();
            }
            jk[p]='\0';
    //gotoxy(26,15);gets(umur);
    p=0;
            gotoxy(26,15);color(15,0);umur[p] = getch();
            while (umur[p] != 13){
            if (umur[p] == 8){
                gotoxy(26+p,15);color(15,0);printf(" ");
                p--;
                if(p<0){
                p = 0;
                }
                gotoxy(26+p,15);color(15,0);printf("");
                }else{
                gotoxy(26+p,15);color(15,0);printf("%c",umur[p]);
                p++;
            }
            if(p>1){
                p=1;
                gotoxy(45,15);printf("");
            }
            gotoxy(26+p,15);color(15,0);
            umur[p]=getch();
            }
            umur[p]='\0';
    //gotoxy(29,18);gets(nohp);
    p=0;
            gotoxy(29,18);color(15,0);nohp[p] = getch();
            while (nohp[p] != 13){
            if (nohp[p] == 8){
                gotoxy(29+p,18);color(15,0);printf(" ");
                p--;
                if(p<0){
                p = 0;
                }
                gotoxy(29+p,18);color(15,0);printf("");
                }else{
                gotoxy(29+p,18);color(15,0);printf("%c",nohp[p]);
                p++;
            }
            if(p>11){
                p=11;
                gotoxy(45,18);printf("");
            }
            gotoxy(29+p,18);color(15,0);
            nohp[p]=getch();
            }
            nohp[p]='\0';
    //gotoxy(26,21);gets(email);
    p=0;
            gotoxy(26,21);color(15,0);email[p] = getch();
            while (email[p] != 13){
            if (email[p] == 8){
                gotoxy(26+p,21);color(15,0);printf(" ");
                p--;
                if(p<0){
                p = 0;
                }
                gotoxy(26+p,21);color(15,0);printf("");
                }else{
                gotoxy(26+p,21);color(15,0);printf("%c",email[p]);
                p++;
            }
            if(p>23){
                p=23;
                gotoxy(45,21);printf("");
            }
            gotoxy(26+p,21);color(15,0);
            email[p]=getch();
            }
            email[p]='\0';
    strcpy(data[akun][0],nama);
    strcpy(data[akun][1],jk);
    strcpy(data[akun][2],umur);
    strcpy(data[akun][3],nohp);
    strcpy(data[akun][4],email);

    fp=fopen("profil.txt","w");
    for(int x=0; x<jmlakun; x++){
        fprintf(fp,"%s\n%s\n%s\n%s\n%s\n",data[x][0],data[x][1],data[x][2],data[x][3],data[x][4]);
    }
    fclose(fp);

    info_pengguna();
}

void pilihan(){
    int x,tempat=1;
    bg(0);
    for(int x=1;x<=58;x++){
        gotoxy(0+x,5);color(1,0);printf("%c",203);
        gotoxy(0+x,31);color(1,0);printf("%c",202);
        if(x>6 && x<52){
            gotoxy(0+x,6);color(2,0);printf("%c",202);
            gotoxy(0+x,30);color(2,0);printf("%c",203);
        }
    }
    bingkai(0,6,15,15,23,58);
    gotoxy(1,38);color(15,0);printf("Tekan \"ESC\" untuk keluar program.");
    logo();
    bingkai(19,14,7,12,3,20);
    bingkai(19,19,7,12,3,20);
    bingkai(18,18,8,0,3,20);
    gotoxy(27,20);color(15,0);printf("USER");
    bingkai(18,13,9,0,3,20);
    gotoxy(27,15);color(15,0);printf("ADMIN");
    while(x!=13 && x!=27){
        gotoxy(57,37);x=getche();
        gotoxy(57,37);printf(" ");
        if(x == 80){
            if(tempat==1){
                tempat=2;
                bingkai(18,13,8,0,3,20);
                gotoxy(27,15);color(15,0);printf("ADMIN");
                bingkai(18,18,9,0,3,20);
                gotoxy(27,20);color(15,0);printf("USER");
            }else if(tempat==2){
                tempat=1;
                bingkai(18,18,8,0,3,20);
                gotoxy(27,20);color(15,0);printf("USER");
                bingkai(18,13,9,0,3,20);
                gotoxy(27,15);color(15,0);printf("ADMIN");
            }
        }else if(x == 72){
            if(tempat==1){
                tempat=2;
                bingkai(18,13,8,0,3,20);
                gotoxy(27,15);color(15,0);printf("ADMIN");
                bingkai(18,18,9,0,3,20);
                gotoxy(27,20);color(15,0);printf("USER");               
            }else if(tempat==2){
                tempat=1;
                bingkai(18,18,8,0,3,20);
                gotoxy(27,20);color(15,0);printf("USER");
                bingkai(18,13,9,0,3,20);
                gotoxy(27,15);color(15,0);printf("ADMIN");   
            }
        }else if(x == 27){
            transisi(WHITE);
            bg(0);
            char c;
            gotoxy(19,19);color(15,0);printf("Yakin untuk keluar?(y/t)");
            while(c!='y' || c!='Y' || c!='t' || c!='T'){
                gotoxy(57,37);c=getche();
                gotoxy(57,37);printf(" ");
                if(c=='y' || c=='Y'){
                    char teks1[20]={"Terima Kasih...."};
                    gotoxy(19,19);color(15,0);printf("                               ");
                    for(int x=0; x<16; x++){
                        gotoxy(21+x,19);color(15,0);printf("%c",teks1[x]);Sleep(100);
                    }
                    exit(0);
                }else if(c=='t' || c=='T'){
                    pilihan();
                }else{
                    gotoxy(19,25);color(15,0);printf("Tekan y/Y atau t/T.");Sleep(1000);
                    gotoxy(19,25);color(15,0);printf("                   ");
                }
            }
        }else if(x!=0 && x!=13 && x!=80 && x!=72 && x!=224){
            warning(WHITE,BLACK);
        }
    }

    if(tempat==1){
        loginadmin();
    }else if(tempat==2){
        int x,tempat=1;
        transisi(15);
        bg(0);
        bingkai(0,6,15,15,23,58);
        logo();
        for(int x=1;x<=58;x++){
            gotoxy(0+x,5);color(1,0);printf("%c",203);
            gotoxy(0+x,31);color(1,0);printf("%c",202);
        if(x>6 && x<52){
            gotoxy(0+x,6);color(2,0);printf("%c",202);
            gotoxy(0+x,30);color(2,0);printf("%c",203);
        }
    }
        gotoxy(1,38);color(15,0);printf("Tekan \"Backspace\" untuk kembali.");
        bingkai(19,14,7,12,3,20);
        bingkai(19,19,7,12,3,20);
        bingkai(18,18,8,0,3,20);
        gotoxy(27,20);color(15,0);printf("LOGIN");
        bingkai(18,13,9,0,3,20);
        gotoxy(27,15);color(15,0);printf("DAFTAR");
        while(x!=13 && x!=8){
        gotoxy(57,37);x=getche();
        gotoxy(57,37);printf(" ");
        if(x == 80){
            if(tempat==1){
                tempat=2;
                bingkai(18,13,8,0,3,20);
                gotoxy(27,15);color(15,0);printf("DAFTAR");
                bingkai(18,18,9,0,3,20);
                gotoxy(27,20);color(15,0);printf("LOGIN");
            }else if(tempat==2){
                tempat=1;
                bingkai(18,18,8,0,3,20);
                gotoxy(27,20);color(15,0);printf("LOGIN");
                bingkai(18,13,9,0,3,20);
                gotoxy(27,15);color(15,0);printf("DAFTAR");
            }
        }else if(x == 72){
            if(tempat==1){
                tempat=2;
                bingkai(18,13,8,0,3,20);
                gotoxy(27,15);color(15,0);printf("DAFTAR");
                bingkai(18,18,9,0,3,20);
                gotoxy(27,20);color(15,0);printf("LOGIN");               
            }else if(tempat==2){
                tempat=1;
                bingkai(18,18,8,0,3,20);
                gotoxy(27,20);color(15,0);printf("LOGIN");
                bingkai(18,13,9,0,3,20);
                gotoxy(27,15);color(15,0);printf("DAFTAR");   
            }
        }else if(x == 8){
           pilihan();
        }else if(x!=0 && x!=13 && x!=80 && x!=72 && x!=224 && x!=8){
            warning(WHITE,BLACK);
    
        }  
        }  
        if(tempat==1){
            daftar();
        }else if(tempat==2){
            login_user();
        }
    }
    
}

void main(){
    // edit();
    //loginadmin();
    // kuncijawaban();
    // pilihan();
    // info_pengguna();
    //daftar();
     tampilan_awal();
    //  profil();
    //login_user();
     //menu();
    // materi();
    // quiz12();
    // totalnilai();
    // deleteUser();
    //ranking();
  }