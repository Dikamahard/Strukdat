// Kelompok 12 Kelas B :
// -Rizky Mahardika Hariyanto - 140810200010
// -Jonathan Victor Goklas - 140810200024
// =============================================================
// UAS Struktur Data
// Penerapan Algoritma Dijkstra Untuk Menentukan Jarak Terdekat
// Studi Kasus Hotel di Kab. Majalengka


#include<iostream>
#include<climits>  // buat ngambil int_max
using namespace std;

//fungsi untuk mencari minimum distance
int minimumDist(float dist[], bool visit[]) 
{
	float min = INT_MAX;  //infinity (maximum value of an integer)
    int index; 
              
	for(int i=0;i<8;i++) 
	{
		if(visit[i]==false && dist[i]<=min)      
		{
			min=dist[i];
			index=i;
		}
	}
	return index;
}

void Dijkstra(float graph[8][8], int src, float dist[]) // adjacency matrix 8x8
{
	dist[8];  // array untuk menyimpan jarak min vertex                             
	bool visit[8];  // boolean array untuk menyimpan visit/unvisited
	
	// inisialisai vertex awal seluruhnya infinity dan unvisited
	// kecuali vertex src (titik awal)
	for(int i = 0; i<8; i++)
	{
		dist[i] = INT_MAX;
		visit[i] = false;	
	}
	
	dist[src] = 0;   // vertex titik awal set ke nol            
	
	for(int i = 0; i<8; i++)                           
	{
		int m=minimumDist(dist,visit); // vertex not yet included.
		visit[m]=true;// m with minimum distance included in visit.
		for(int i = 0; i<8; i++)                  
		{
			// upadate minimum distance vertex i
			if(!visit[i] && graph[m][i] && dist[m]!=INT_MAX && dist[m]+graph[m][i]<dist[i]) {
                dist[i]=dist[m]+graph[m][i];
            }	
		}
	}

	// cout<<"Vertex\t\tDistance from source"<<endl;
	// for(int i = 0; i<8; i++)                      
	// { //Printing
	// 	char str=65+i; // Ascii values for pritning A,B,C..
	// 	cout<<str<<"\t\t\t"<<dist[i]<<endl;
	// }
}

void drawGraph() {
	


	cout << "                               [4] \n";
	cout << "                               / \\ \n";
	cout << "                   /---(80)---/   \\--(200)---\\	\n";
	cout << "                  /                           \\---[6]---\\ \n";
	cout << "       /---[2]---/                                 /     \\ (850) \n";
	cout << "    (290)                                         /       \\ \n";
	cout << "     /                                           /         \\---------[7] \n";
	cout << "   [1]                                        (210)                  / \n";
	cout << "     \\                                         /                  (940) \n";
	cout << "      \\                                       /                    / \n";
	cout << "       \\                          /---[5]----/-------(160)-------[8] \n";
	cout << "        \\--(270)---\\             / \n";	
	cout << "                    \\         (22)    \n";
	cout << "                     \\---[3]---/	\n";

	cout << "\n";
	cout << ">>> Titik Awal \n";
	cout << "[1] Terminal Cigasong \n";
	cout << "[5] Alun-alun Majalengka \n";

	cout << "\n>>> Titik Akhir \n";
	cout << "[2] Tidar Jaya Hotel \n";
	cout << "[3] Sederhana Baru Hotel \n";
	cout << "[4] Penginapan Wisma Hikmah \n";
	cout << "[5] Alun-alun Majalengka \n";
	cout << "[6] Putra Jaya Hotel \n";
	cout << "[7] Toserba Surya Kadipaten \n";
	cout << "[8] Puri Elsas Hotel \n\n";
	
}

void jalur(int src, int tujuan, string& arah) {

	if(src == 1 && tujuan == 2) {
		arah = "Terminal -> Tidar Jaya Hotel";
	}else if(src == 1 && tujuan ==  3) {
		arah = "Terminal -> Sederhana Baru Hotel";
	}else if (src == 1 && tujuan == 4) {
		arah = "Terminal -> Tidar Jaya Hotel -> Penginapan Wisma Hikmah";
	}else if (src == 1 && tujuan == 5) {
		arah = "Terminal -> Sederhana Baru Hotel -> Alun-Alun Majalengka";
	}else if (src == 1 && tujuan == 6) {
		arah = "Terminal -> Sederhana Baru Hotel -> Alun-Alun Majalengka -> Putra Jaya Hotel";
	}else if (src == 1 && tujuan == 7) {
		arah = "Terminal -> Sederhana Baru Hotel -> Alun-Alun Majalengka -> Putra Jaya Hotel -> Toserba Surya Kadipaten"; 
	}else if (src == 1 && tujuan == 8) {
		arah = "Terminal -> Sederhana Baru Hotel -> Alun-alun Majalengka -> Puri Elsas Hotel";
	}else if (src == 5 && tujuan == 2) {
		arah = "Alun-alun Majalengka -> Putra Jaya Hotel -> Penginapan Wisma Hikmah -> Tidar Jaya Hotel"; 
	}else if (src == 5 && tujuan == 3) {
		arah = "Alun-alun Majalengka -> Sederhana Baru Hotel";
	}else if (src == 5 && tujuan == 4) {
		arah = "ALun-alun Majalengka -> Putra Jaya Hotel -> Penginapan Wisma Hikmah";
	}else if (src == 5 && tujuan == 6) {
		arah = " Alun-alun Majalengka -> Putra Jaya Hotel";
	}else if (src == 5 && tujuan == 7) {
		arah = "Alun-alun Majalengka -> Putra Jaya Hotel -> Toserba Surya Kadipaten ";
	}else if (src == 5 && tujuan == 8) {
		arah = "Alun-alun Majalengka -> Puri Elsas Hotel ";
	}
		
	
}

void printHasil(int src, float jarak, int tujuan) {
	string start, end, arah;


	//fungsi print jalur
	jalur(src, tujuan, arah);
	//


	switch (src)
	{
	case 1:
		start = "Terminal Cigasong";
		break;
	
	case 5:
		start = "Alun-alun Majalengka";
		break;
		
	default:
		start = "Maaf input salah";
		break;
	}


	switch (tujuan)
	{
	case 2:
		end = "Tidar Jaya Hotel";
		break;

	case 3:
		end = "Sederhana Baru Hotel";
		break;

	case 4:
		end = "Penginapan Wisma Hikmah";
		break;

	case 5:
		end = "Alun-alun Majalengka";
		break;

	case 6:
		end = "Putra Jaya Hotel";
		break;

	case 7:
		end = "Toserba Surya Kadipaten";
		break;

	case 8:
		end = "Puri Elsas Hotel";
		break;

	default:
		end = "Maaf input salah";
		break;
	}


	if(start == "Maaf input salah" || end == "Maaf input salah") {
		cout << "Error 101 \n";
	}else {
		cout << "Jarak tercepat menuju " << end << " adalah sejauh " << jarak << " m" << '\n';
		if(start == "Alun-alun Majalengka" && end == "Alun-alun Majalengka") {
		
		}else {
			cout << "Melalui " << arah << '\n';	
		}

	}
}


int main() {
	char pil;
	int src, tujuan;
	float jarak[8];

	float graph[8][8] = {
        {0, 290, 270, 0, 0, 0, 0, 0},
        {290, 0, 0, 80, 0, 0, 0, 0},
        {270, 0, 0, 0, 22, 0, 0, 0},
        {0, 80, 0, 0, 0, 200, 0, 0},
        {0, 0, 22, 0, 0, 210, 0, 160},
        {0, 0, 0, 200, 210, 0, 850, 0},
        {0, 0, 0, 0, 0, 850, 0, 940},
        {0, 0, 0, 0, 160, 0, 940, 0}
    };

	drawGraph();

	do {
	cout << "=============================\n";
	cout << ">> Masukkan titik awal : ";
	cin >> src;
	cout << "=============================\n";
	cout << ">> Masukkan titik tujuan : ";
	cin >> tujuan;
	cout << "=============================\n";

	Dijkstra(graph, src-1, jarak);
	printHasil(src, jarak[tujuan-1], tujuan);
	
	cout << "\n=====================\n";
	cout << ">> Lanjut? (y/n) : ";
	cin >> pil;
	cout << "=====================\n\n";
	}while(pil == 'Y' || pil == 'y');
	
    //Dijkstra(graph,0);
}