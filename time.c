#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define Size 40

void main(){
     

    struct tm 
{
int tm_sec; // detik
int tm_min; // menit
int tm_hour; // jam
int tm_mday; // hari dalam bulan
int tm_mon; // bulan
int tm_year; // angka dari tahun yang dimulai sejak 1900
int tm_wday; // hari dalam minggu
int tm_yday; // hari dalam tahun
int tm_isdst; // waktu siang hari    
};
/*
%x = menampilkan waktu spesial.
%l = menampilkan jam dalam angka desimal (12 jam).
%M = menampilkan menit dalam rentang 00 sampai 59.
%p = AM dan PM diberikan sesuai dengan waktu yang ditampilan.
%a = singkatan nama hari dalam satu minggu.
%A = nama penuh hari dalam satu minggu.
%b = singkatan nama bulan.
%B = nama penuh bulan dalam satu tahun.
%c = menampilkan tanggal dan waktu.
%d = menampilkan hari dalam satu bulan.
%H = menampilkan jam dalam format 24 jam.
%I = menampilkan jam dalam format 12 jam.
%m = menampilkan bulan sebagai angkat desimal.
%M = menit mulai dari 00 hingga 59.
*/

time_t t ; 

struct tm *tmp ; 

char MY_TIME[Size]; 

time( &t ); 

	
// localtime () menggunakan

// waktu yang ditunjukkan oleh

// t, untuk mengisi struktur

// tm dengan nilai yang

// mewakili waktu lokal yang

// sesuai. 

tmp = localtime( &t ); 

	

// menggunakan strftime untuk

// menampilkan waktu. 

strftime(MY_TIME, sizeof(MY_TIME), "%B -"" %H:%M %p %c", tmp);
//bila mau ganti tinggal ganti aja yg %nya bisa dubah ubah; 

	

printf("Format tanggal &"

" waktu: %s\n", MY_TIME ); 

    getch();  
}