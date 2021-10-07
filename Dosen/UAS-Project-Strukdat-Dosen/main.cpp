// Kelompok 12 Kelas B :
// -Rizky Mahardika Hariyanto - 140810200010
// -Jonathan Victor Goklas - 140810200024
// =============================================================
// UAS Struktur Data
// Penerapan Algoritma Dijkstra Untuk Menentukan Jarak Terdekat
// Studi Kasus Hotel di Kab. Majalengka

#include "func.cpp"

int main() {
    ptr A, B, C ,D, E, F, G, H;  //list adjacency 
    ptr x; //tumbal
    ptr adjList[8];  //titik tempat  (graph)

    A = B = C = D = E = F = G = H = nullptr;

    // Adjacency list vertex 0
    createVertex(x, 1, 2.9);
    addEdge(A, x);
    createVertex(x, 2, 2.7);
    addEdge(A, x);
    adjList[0] = A;

    // Adjacency list vertex 1
    createVertex(x, 0, 2.9);
    addEdge(B, x);
    createVertex(x, 3, 0.8);
    addEdge(B, x);
    adjList[1] = B;

    // Adjacency list vertex 2
    createVertex(x, 0, 2.7);
    addEdge(C, x);
    createVertex(x, 4, 0.22);
    addEdge(C, x);
    adjList[2] = C;

    // Adjacency list vertex 3
    createVertex(x, 1, 0.8);
    addEdge(D, x);
    createVertex(x, 5, 2);
    addEdge(D, x);
    adjList[3] = D;

    // Adjacency list vertex 4
    createVertex(x, 2, 0.22);
    addEdge(E, x);
    createVertex(x, 5, 2.1);
    addEdge(E, x);
    createVertex(x, 7, 1.6);
    addEdge(E, x);
    adjList[4] = E;
    
    // Adjacency list vertex 5
    createVertex(x, 3, 2);
    addEdge(F, x);
    createVertex(x, 4, 2.1);
    addEdge(F, x);
    createVertex(x, 6, 8.5);
    addEdge(F, x);
    adjList[5] = F;

    // Adjacency list vertex 6
    createVertex(x, 5, 8.5);
    addEdge(G, x);
    createVertex(x, 7, 9.4);
    addEdge(G, x);
    adjList[6] = G;

    // Adjacency list vertex 7
    createVertex(x, 4, 1.6);
    addEdge(H, x);
    createVertex(x, 6, 9.4);
    addEdge(H, x);
    adjList[7] = H;


    //print edge dari suatu vertex
    for(int i=0; i<=7; i++) {
        cout << "edge yang terhubung ke vertex " << i << '\n';
        print(adjList[i]);
    }
      
}
