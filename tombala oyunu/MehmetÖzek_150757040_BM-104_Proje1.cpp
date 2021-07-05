                 
				 
				 
		 //                 ADI:   MEHMET 
        //               SOYADI:   �ZEK
      //                 B�L�M�:   B�LG�SAYAR M�HEND�SL���(
     //             




#include<iostream>//cin cout �al��t�rmak i�in
#include<cstdlib>
#include<ctime>//time �al��t�rmak i�in
#include<vector>//vector �al��t�mrak i�in
#include <algorithm>
#include<iomanip> // setw �al��t�rmak i�in
using namespace std;

// Puan beyan et
vector<int> points;

// Kart destesi olu�turun
void KartlariOlustur(int arr[][15], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<15; j++){
            int temp = (rand() % 90) + 1;
            arr[i][j] = temp;
        }
    }
};

int CekilenKard(int arr[90]){
	for( int i=0;i<90;i++)
			 {
 				 int temp=rand()%100;
 				 arr[i]=temp;
			}
	
}
// Oyuncu kartlar�n� g�nceller
void Update(int arr[][15], int size, int player[], int num, int val){
    for(int i=0; i<num; i++){
        for(int j=0; j<15; j++){
            if(arr[player[i]][j]==val)
               arr[player[i]][j] = -1;
        }
    }
}

// Kazananlar� kontrol eder
int Check(int arr[][15], int size, int player[], int val){
    int count = 0;
    for(int i=0; i<15; i++){
        if(arr[player[val]][i]==-1)
            count+=1;
    }
    if(count<10 && count>=5)
        return 1;
    else if(count<14 && count >=10)
        return 2;
    else if(count>=15)
        return 3;
    else 
        return 0;

}

int main(){
    srand ( time(0) );
    int card_set[10][15];
  int i,j,k;


    for(int x=0; x<3; x++){
    	  cout <<"\n\n\n\n\n\n" << "SET " << (x+1) << endl;
        cout << "TOMBALA KARTLARI HAZIRLANIYOR..." << endl; 
        KartlariOlustur(card_set,10);
        for(i=0; i<10; i++){
            cout << "Kart No"<<i<<": ";
            for(j=0; j<15; j++){
                cout << card_set[i][j] << "\t";
            }
            cout << "\n";
        }
    
    
    cout << "Oyuncu Sayisi: ";
    int num_player; 
    cin >> num_player;  // oyuncu say�s� girmek i�in
    int player[10];  //
    points.resize(num_player,0);


        //  rastgele dizi atar
        for(i=0; i<num_player; i++){
            player[i] = (rand()%10);
        }

        //T�m Oyuncular�n Kartlar�n� G�sterir
        cout << "Oyuncular icin Secilen Kart Numaralari" << endl;
        int seed = rand();
        for(i=0; i<num_player; i++)
            cin>>player[i];
        cout << endl;
        //Se�ilen Oyuncular�n Kartlar�n� G�sterir
        for( i=0; i<num_player; i++){
            cout << i <<". Oyuncunun Tombala Karti: ";
            for( j=0; j<15; j++){
                cout << card_set[player[i]][j] << "\t";
            }
            cout << endl;
        }
      
        int bag[90];
        cout<<"\n"<<"CEKILEN NUMARALAR"<<endl;
        
		CekilenKard(bag);
        for(i=0; i<90; i++){
		
        
            cout <<setw(2)<<bag[i]<<"  ";
			  if((i+1)%10==0) // 10x9 �eklinde yazdr�r
  				cout<<"\n";
  				bag[i] = i+1;
	}
           cout << "\n";
        random_shuffle(&bag[0],&bag[89]);
        
        int flag0=0,flag1=0,flag2=0;
        for(i=0; i<90; i++){
            // Her �ekili�ten sonra oyuncu kartlar�n� g�nceller
            Update(card_set,10,player,num_player,bag[i]);

            // Kazananlar� kontrol eder
            for(j=0; j<num_player; j++){
                int temp = Check(card_set,10,player,j);
                if(temp==1 && flag0==0){
                    cout << "1. Cinko Kazanani # " << j << " Oyuncu" << endl;
                    flag0=1;
                    points[j] += 5;
                    break;
                }
                else if(temp==2 && flag1==0){
                    cout << "2. Cinko Kazanani # " << j << " Oyuncu" << endl;
                    flag1 = 1;
                    points[j] += 10;
                    break;
                }
                else if(temp==3 && flag2==0){
                    cout << "Tombala Kazanani # " << j << " Oyuncu" << endl;
                    flag2 = 1;
                    points[j] += 15;
                    break;
                }        
            }
            if(flag2==1)
                break;
        }

        //Puan kart�n� g�r�nt�ler
        cout << "\n";
        cout << "PUAN KARTI: "<< endl;
        for(i=0; i<num_player; i++)
            cout << "Oyuncu # " << i << " : " << points[i] << endl;
}
	}

