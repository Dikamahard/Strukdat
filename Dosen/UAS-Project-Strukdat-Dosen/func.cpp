#include <iostream>
#include <set>
using namespace std;

struct vertex{
    int id;
   // string tempat;
    float jarak;

    vertex* next;
};

typedef vertex* ptr;

struct queue{
    ptr head;
    ptr tail;
};



// struct adj{
//     vertex *asal;
//     int jarak;
//     adj *next;
// };


//typedef adj* list;

void createVertex(ptr& ver, int id, /*string name,*/ float weight) {
    ver = new vertex;

    ver->next = nullptr;
    ver->id = id;
    //ver->tempat = name;
    ver->jarak = weight;
}

void addEdge(ptr& head, ptr ver) {
    ptr temp = head;

    if (head == nullptr) {
        head = ver;
    }else {
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = ver;
    }

}

void print(ptr head) {
    ptr temp = head;

    while(temp != nullptr) {
        cout << "- vertex " << temp->id << '\n';
        cout << "  dengan jarak " << temp->jarak << '\n' << '\n';
        temp = temp->next;
    }
}

void createQueue(queue& Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

// void createAdjList(list head, adj v, int , ptr sub ) {
//     head->asal = v;
// }


typedef pair<int, int> PII;

void dijsktra(ptr graph, int sumber, int jumVertex ) {  // harus nentuin sumber
    const int INF = 999;
    // queue Q;
    // ptr shortP;
    
    // shortP = new vertex;
    // shortP->id = 0;
    // shortP->jarak = 0;
    // shortP->next = nullptr;

    // createQueue(Q);

    int dist[8] = {INF};
    dist[sumber] = 0;

    set<PII> setJarak;
    setJarak.insert(0, sumber);

    while(!setJarak.empty()) {
        PII top = *setJarak.begin();
        setJarak.erase(setJarak.begin());

        int currentSourceVertex = top.second;

        for(auto& it : graph->id=currentSourceVertex) {}
    }

}

