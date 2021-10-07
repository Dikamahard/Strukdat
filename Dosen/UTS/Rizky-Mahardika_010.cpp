// RIZKY MAHARDIKA HARIYANTO
// 140810200010
// KELAS B

#include <iostream>
using namespace std;

struct node{       // MEMBUAT STRUKTUR NODE                         
    int data;
    node *next;
};

typedef node* ptr;  // MEMBUAT  ALIAS
typedef ptr list;   // MEMBUAT ALIAS

void create(ptr& nodebaru, int a) {        // FUNGSI UNTUK MEBUAT NODE YANG SUDAH DITENTUKAN
    nodebaru = new node;                   // MENYEDIAKAN MEMORI
    nodebaru->data = a;                    // MEMASUKKAN NILAI A KE DALAM NODE
    nodebaru->next = nullptr;              // MEMBUAT NODE NEXT MENJADI KOSONG
}

void createbebas(ptr& nodebaru) {           // FUNGSI UNTUK MEBUAT NODE YANG DAPAT DIINPUTKAN SENDIRI
    nodebaru = new node;                    // MENYEDIAKAN MEMORI
    cout << "Masukkan data : " << endl;
    cin >> nodebaru->data;                  // INPUT DATA DARI NODE
    nodebaru->next = nullptr;               // MEMBUAT NODE NEXT MENJADI KOSONG
}

float rata (ptr &head) {                    // FUNGSI UNTUK MENCARI RERATA LIST
  int sum = 0, count = 0;              // MEMBUAT VARIABLE BANTU UNTUK HASIL DARI JUMLAH DAN BANYAK DATA
  ptr temp = head;
  while (temp->next != nullptr) {           //SELAMA NODE BELUM BERAKHIR
    sum += temp->data;                      // NILAI SUM SELALU BERTAMBAH DARI DATA NODE
    count++;                                // NILAI COUNT BERTAMBAH SESUAI BANYAKNYA DATA
    temp = temp->next;                      // MENGGESER DATA KE DATA SELANJUTNYA
  }

  return (float)sum / count;                // MENGEMBALIKAN HASIL
}

int maximum(ptr &head) {                       // FUNGSI UNTUK MENCARI NILAI MAXIMUM
  int result = 0;                            // MEMBUAT VARIABEL PENAMPUNG DATA MAXIMAL
  ptr temp = head;                           // variabel bantu temp
  while (temp->next != nullptr) {            // SELAMA NODE BELUM BERAKHIR
    if (temp->data > result) {              // BANDINGKAN DATA SEKARANG DENGAN DATA MAXIMAL
      result = temp->data;                  // JIKA BENAR MASUKKAN DATA KE VARIABEL RESULT
    }
    temp = temp->next;                      // MENGGESER NODE
  }

  return result;
}


void insertfirst(ptr& head, ptr baru) {        // FUNGSI UNTUK MENEMPEL NODE DI DEPAN LIST
    if (head == nullptr){                      
        head = baru;
    }else {
        baru->next = head;                      // MASUKKAN HEAD KE NODE BARU.NEXT
        head = baru;                            // JADIKAN NODE BARU SEBAGAI KEPALA
    }

}

void insertlast(ptr& head, ptr baru){           // FUNGSI UNTUK MENEMPEL NODE DI BELAKANG LIST
    ptr temp = head;
    if (head == nullptr){
        head = baru;
    }else {
        while(temp->next != nullptr){           // SELAMA BELUM MENCAPAI UJUNG
            temp = temp->next;                  // GESER NODE
        }
        temp->next = baru;                      // MASUKKAN NODE BARU KE NODE PALING AKHIR
    }
}

void print(ptr head){                           // FUNGSI TRANSVERSAL YANG DIGUNAKAN UNTUK MENCETAK SELURUH NILAI LIST
    ptr temp = head;                            
    if (head == nullptr){
        cout << "data kososng";
    }else {
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

int main(){
    list data1, data2, data3, data4, data6, data5, data7, data8, data9, data10, data11, data12, data13, data14;
    int a, max;
    float hasil_rata;
    ptr kepala = nullptr;

   



    // MEMBUAT DATA AWAL
    a = 14;
    create(data1, a);
    insertlast(kepala, data1);
    
    a = 8;
    create(data2, a);
    insertlast(kepala, data2);

    a = 10;
    create(data3, a);
    insertlast(kepala, data3);

    a = 17;
    create(data4, a);
    insertlast(kepala, data4);
    
    a = 00;
    create(data5, a);
    insertlast(kepala, data5);

    a = 29;
    create(data6, a);
    insertlast(kepala, data6);

    print(kepala);   
    cout << endl;

    // MEMASUKKAN 4 ANGKA YANG AKAN DI SAMBUNGKAN DI BELAKANG DATA AWAL 

    createbebas(data7);                     
    insertlast(kepala, data7);

    createbebas(data8);
    insertlast(kepala, data8);

    createbebas(data9);
    insertlast(kepala, data9);

    createbebas(data10);
    insertlast(kepala, data10);

    cout << endl;
    print(kepala);  
    cout << endl;

    // MEMASUKKAN 4 ANGKA YANG AKAN DISAMBUNGKAN DI DEPAN DATA AWAL

    createbebas(data11);                     
    insertfirst(kepala, data11);

    createbebas(data12);
    insertfirst(kepala, data12);

    createbebas(data13);
    insertfirst(kepala, data13);

    createbebas(data14);
    insertfirst(kepala, data14);

    cout << endl;
    print (kepala);
    cout << endl;

    cout << "Rata- rata : ";
    hasil_rata = rata(kepala);
    cout << endl;
    cout << hasil_rata;
    cout << endl;
    
    cout << "Nilai Terbesar : ";
    max = maximum(kepala);
    cout << endl;
    cout << max;

}