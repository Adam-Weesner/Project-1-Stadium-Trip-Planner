#ifndef GRAPH_H
#define	GRAPH_H
#include <queue>
#include <limits>
#include <list>
#include "header.h"

template <class vertType, class wtType>
class Graph {
    public:
        class Edge;
        class Vertex;

        class Vertex {
            public:
                Vertex();
                vertType name;
                int index;
                bool isDiscovered;
        };

        class Edge{
            public:
                Edge(const pair<Vertex, Vertex> vertPair, const wtType& w);
            private:
                pair<Vertex, Vertex> pairVert;
                wtType weight;
        };

        Graph();
        Graph(int numVerts);
        ~Graph();
        //Accessors
        void ListVert();
        vertType* GetSortedVertices();
        vertType* GetUnsortedVertices();
        vertType* GetCountedVertices(int count);
        int GetTotalV();
        int GetSortCount();
        int GetTotalMil();
        int** GetMatrix();
        int GetMatrixResult();
        void DisplayMatrix();
        double GetGrandTotal();
        //Mutators
        bool CreateVert(vertType vName);
        bool CreateVert(vertType vName, int i);
        void CreateEdge(int org, int dest, wtType w);
        void SetVertList(Vertex* newList);
        void SetNewMatrix(int** nMatrix);
        QString DFS(int v);
        QString BFS(int v);
        void Dijkstra(int srcVert);
        void Dijkstra(int srcVert, int destVert);
        QString PrimMST();
        void SetTotalVertices(int num);
        void SetTotalMil(long nTotal);
        void SetSortCount(int nCount);
        void SetMatrix(int** newMatrix);
        void SetMatrixResult(int nResult);
        Vertex* vertList;
    private:
        int totalV;
        int MAX;
        int** matrix;
        int sortCount;
        int matrixResult;
        vertType* sortedAr;
        QString DFSoutput;
        long DFStotal;
        long totalMil;
        void DFSRecur(int v, bool visited[], QString& output);
};

template<class vertType, class wtType>
Graph<vertType,wtType>::Graph() {
    MAX = numeric_limits<int>::max();
}

//Vertex Constructor
template <class vertType, class wtType>
Graph<vertType, wtType>::Vertex::Vertex() {
    name = vertType();
    index = 0;
    isDiscovered = false;
}

//Graph Constructor
template <class vertType, class wtType>
Graph<vertType, wtType>::Graph(int numVerts) {
    totalV = numVerts;
    MAX = std::numeric_limits<int>::max();
    vertList = new Vertex[numVerts];
    matrix = new int*[totalV];

    for(int i = 0; i < totalV; ++i) {
        matrix[i] = new int[totalV];
    }

    for(int i = 0; i < totalV; ++i){
        for(int j = 0; j < totalV; ++j) {
            matrix[i][j] = 0;
        }
    }
}

//Graph Destructor
template <class vertType, class wtType>
Graph<vertType, wtType>::~Graph() { }

template <class vertType, class wtType>
bool Graph<vertType, wtType>::CreateVert(vertType vName) {
    int i = 0;
    bool added = false;

    while(!added && i < totalV) {
        if(vertList[i].isDiscovered == false) {
            vertList[i].index = i;
            vertList[i].name = vName;
            vertList[i].isDiscovered = true;
            added = true;
        }
        i++;
    }

    return added;
}

template <class vertType, class wtType>
bool Graph<vertType, wtType>::CreateVert(vertType vName, int i) {
    bool added = false;

    if(i < totalV) {
        vertList[i].index = i;
        vertList[i].name = vName;
        vertList[i].isDiscovered = true;
        added = true;
    }

    return added;
}

template <class vertType, class wtType>
void Graph<vertType, wtType>::CreateEdge(int org, int dest, wtType w) {
    if(vertList[org].isDiscovered && vertList[dest].isDiscovered) {
        matrix[org][dest] = w;
        matrix[dest][org] = w;
        qDebug() << vertList[org].name
                 << " -> " << vertList[dest].name
                 << ": " << w << endl;
    }
    else {
        qDebug() << "\nERROR - Vertices cannot be found\n" << endl;
    }
}

template<class vertType, class wtType>
void Graph<vertType,wtType>::SetVertList(Vertex* newList) {
    for(int i = 0; i < totalV-1; ++i) {
//        qDebug() << vertList[i].name.GetStadiumName() << " - " << newList[i].name.GetStadiumName();
        vertList[i].index = newList[i].index;
        vertList[i].name  = newList[i].name;
        vertList[i].isDiscovered = newList[i].isDiscovered;
    }
}

template<class vertType, class wtType>
void Graph<vertType,wtType>::SetNewMatrix(int** nMatrix) {
    for(int i = 0; i < totalV-1; ++i){
        for(int j = 0; j < totalV; ++j) {
            matrix[i][j] = nMatrix[i][j];
        }
    }
}

template <class vertType, class wtType>
QString Graph<vertType, wtType>::DFS(int v) {
    bool visited[totalV];
    queue<int> edges;
    int small = MAX;
    int destVert;
    DFStotal = 0;
    QString output = "";

    for(int i = 0; i < totalV; i++) {
        visited[i] = false;
    }

    if(v < totalV) {
       visited[v] = true;
//       qDebug() << "Starting DFS:\n" << vertList[v].name.GetStadiumName() << endl;
       output += "Starting DFS:\n\t" + vertList[v].name.GetStadiumName() + "\n";

        for(int i = 0; i < totalV; i++) {
            if( matrix[v][i] > 0 && (!visited[i])) {
                edges.push(i);
//                qDebug() << "\tAdjacent vertex: " << vertList[i].name.GetStadiumName() << ": " << matrix[v][i] << endl;
            }
        }
        if(!edges.empty()) {
            while(!edges.empty()) {
                int adjVert = matrix[v][edges.front()];
//                qDebug() << "Vert: " << edges.front() << ": " << adjVert;

                if(adjVert < small){
                    small = adjVert;
                    destVert = edges.front();
                }
                edges.pop();
            }
        }
        else {
            bool found = false;
            int i = 0;
            while(!found && i < totalV){
                if(visited[i] == false){
                    destVert = i;
                    found = true;
                }
                i++;
            }
        }
        DFStotal += matrix[v][destVert];
        DFSRecur(destVert, visited, output);
    }

    matrixResult = DFStotal;
    return output;
}

template <class vertType, class wtType>
void Graph<vertType, wtType>::DFSRecur(int v, bool visited[], QString& output) {
    queue<int> edges;
    int small = MAX;
    int destVert;
    visited[v] = true;

//    qDebug() << vertList[v].name.GetStadiumName() << endl;
    output += "\t" + vertList[v].name.GetStadiumName() + "\n";

    for(int i = 0; i < totalV; i++) {
        if( matrix[v][i] > 0 && (!visited[i]) ){
            edges.push(i);
//            qDebug() << "\tAdjacent vertex: " << vertList[i].name.GetStadiumName() << ": " << matrix[v][i] << endl;
        }
    }
    if(!edges.empty()) {
        while(!edges.empty()) {
            int adjVert = matrix[v][edges.front()];

//            qDebug() << "Vert: " << edges.front() << ": " << adjVert;

            if(adjVert < small) {
                small = adjVert;
                destVert = edges.front();
            }
            edges.pop();
        }
        DFStotal += matrix[v][destVert];
        DFSRecur(destVert, visited, output);
    }
    else {
        bool found = false;
        int i = 0;
        while(!found && i < totalV) {
            if(visited[i] == false) {
                destVert = i;
                found = true;
            }
            i++;
        }
        if(found == true) {
//            qDebug() << destVert << " cannot be found\n" <<  endl;
            DFSRecur(destVert, visited, output);
        }
    }
}

template <class vertType, class wtType>
QString Graph<vertType, wtType>::BFS(int v) {
    bool visited[totalV];
    queue<int> priorityQueue;
    matrixResult = 0;
    QString output = "";

    for(int i = 0; i < totalV; i++)
        visited[i] = false;

    visited[v] = true;
    priorityQueue.push(v);

    output += "Starting BFS:\n";
    QString prev = "";
    while(!priorityQueue.empty()) {
        v = priorityQueue.front();
        priorityQueue.pop();

        if (vertList[v].name.GetStadiumName() != prev) {
            output += "\t" + vertList[v].name.GetStadiumName() + "\n";
            prev = vertList[v].name.GetStadiumName();

            for (int i = 0; i < totalV; i++) {
                if (matrix[v][i] > 0) {
                    if (!visited[i]) {
                        visited[i] = true;
                        matrixResult += matrix[v][i];
                        priorityQueue.push(i);
                    }
                }
            }
        }
    }
    return output;
}

template <class vertType, class wtType>
void Graph<vertType, wtType>::Dijkstra(int src) {
    int distAr[totalV];
    bool isVisited[totalV];
    totalMil = 0;

    for(int i = 0; i < totalV; i++){
        distAr[i] = MAX;
        isVisited[i] = false;
    }

    distAr[src] = 0;

    for(int i = 0; i < totalV-1; i++) {
        int minNum = MAX;
        int minDex = 0;

        for(int a = 0; a < totalV; a++) {
            if(isVisited[a] == false &&
               distAr[a] <= minNum){
                minNum = distAr[a];
                minDex = a;
            }
        }
        isVisited[minDex] = true;

        for(int j = 0; j < totalV; j++) {
            if(!isVisited[j] && matrix[minDex][j] &&
               distAr[minDex] != MAX &&
               distAr[minDex]+matrix[minDex][j] < distAr[j]){       
                distAr[j] = distAr[minDex] + matrix[minDex][j];
            }
        }
    }

    int key, k;
    Vertex temp;

    for(int i = 1; i < totalV; i++) {
        key = distAr[i];
        temp = vertList[i];
        for(k = i - 1; (k >= 0) && (distAr[k] > key); k--) {
            distAr[k+1] = distAr[k];
            vertList[k+1] = vertList[k];
        }
        distAr[k+1] = key;
        vertList[k+1] = temp;
    }

    sortedAr = new vertType[totalV];
    sortCount = 0;

    for(int i = 0; i < totalV; i++) {
        sortedAr[i] = vertList[i].name;
        sortCount++;
    }
    
    for(int i = 0; i < totalV-1; i++)
        Dijkstra(sortedAr[i].GetID(), sortedAr[i+1].GetID());
}

template <class vertType, class wtType>
void Graph<vertType, wtType>::Dijkstra(int srcVert, int destVert) {
    int distAr[totalV];
    bool sptAr[totalV];

    for(int i = 0; i < totalV; i++){
        distAr[i] = MAX;
        sptAr[i] = false;
    }

    distAr[srcVert] = 0;

    for(int i = 0; i < totalV-1; i++) {
        int minNum = MAX;
        int minDex = 0;

        for(int j = 0; j < totalV; j++) {
            if(sptAr[j] == false &&
               distAr[j] <= minNum) {
                minNum = distAr[j];
                minDex = j;
            }
        }

        sptAr[minDex] = true;

        for(int k = 0; k < totalV; k++) {
            if(!sptAr[k] && matrix[minDex][k] &&
                distAr[minDex] != MAX &&
               (distAr[minDex] + matrix[minDex][k]) < distAr[k]) {
                 distAr[k] = distAr[minDex] + matrix[minDex][k];
            }
        }
    }
    totalMil += distAr[destVert];
}

template <class vertType, class wtType>
QString Graph<vertType, wtType>::PrimMST() {
    QString output = "Starting MST:\n";
    int MST[totalV];
    int key[totalV];
    bool used[totalV];

    for(int i = 0; i < totalV; i++) {
        key[i] = MAX;
        used[i] = false;
    }

    key[0] = 0;
    MST[0] = -1;

    for(int i = 0; i < totalV-1; i++) {
        int minNum = MAX;
        int minDex = 0;

        for(int j = 0; j < totalV; j++) {
            if(used[j] == false &&
               key[j] <= minNum) {
                minNum = key[j];
                minDex = j;
            }
        }

        used[minDex] = true;

        for(int k = 0; k < totalV; k++) {
            if(matrix[minDex][k] &&
               used[k] == false  &&
               matrix[minDex][k] < key[k]) {
                MST[k] = minDex;
                key[k] = matrix[minDex][k];
            }
        }
    }
    matrixResult = 0;
    QString prev = "";
    for(int i = 1; i < totalV; i++) {
        if (vertList[i].name.GetStadiumName() != prev) {
            output += "\t" + vertList[MST[i]].name.GetStadiumName() + " -> " + vertList[i].name.GetStadiumName() + ": Weight: "  + QString::number(matrix[i][MST[i]]) + "\n";
            matrixResult += matrix[i][MST[i]];
            prev = vertList[i].name.GetStadiumName();
        }
    }
    return output;
}

template <class vertType, class wtType>
void Graph<vertType, wtType>::ListVert() {
    for(int i = 0; i < totalV; i++){
        qDebug() << i << " - " << vertList[i].name.GetTeamName();
    }
}

template<class vertType, class wtType>
vertType* Graph<vertType, wtType>::GetSortedVertices() {
    return sortedAr;
}

template<class vertType, class wtType>
vertType* Graph<vertType, wtType>::GetUnsortedVertices() {
    vertType* temp = new vertType[totalV];
    for(int i = 0; i < totalV; i++) {
        temp[i] = vertList[i].name;
    }
    return temp;
}

template<class vertType, class wtType>
vertType* Graph<vertType, wtType>::GetCountedVertices(int count) {
    vertType* temp = new vertType[count];
    for(int i = 0; i < count; i++) {
        temp[i] = vertList[i].name;
    }
    return temp;
}

template<class vertType, class wtType>
void Graph<vertType,wtType>::SetTotalVertices(int num) {
    totalV = num;
    vertList = new Vertex[totalV];
    matrix = new int*[totalV];

    for(int i = 0; i < totalV; ++i) {
        matrix[i] = new int[totalV];
    }

    for(int i = 0; i < totalV; ++i) {
        for(int j = 0; j < totalV; ++j) {
            matrix[i][j] = 0;
        }
    }
}

template<class vertType, class wtType>
int Graph<vertType,wtType>::GetTotalV() {
    return totalV;
}

template<class vertType, class wtType>
int Graph<vertType,wtType>::GetSortCount() {
    return sortCount;
}

template<class vertType, class wtType>
int Graph<vertType,wtType>::GetTotalMil() {
    return totalMil;
}

template<class vertType, class wtType>
void Graph<vertType,wtType>::SetTotalMil(long nTotal) {
    totalMil = nTotal;
}

template<class vertType, class wtType>
void Graph<vertType,wtType>::SetSortCount(int nCount) {
    sortCount = nCount;
}

template<class vertType,class wtType>
void Graph<vertType,wtType>::SetMatrix(int** newMatrix) {
    matrix = newMatrix;
}

template<class vertType,class wtType>
int** Graph<vertType,wtType>::GetMatrix() {
    return matrix;
}

template<class vertType,class wtType>
int Graph<vertType,wtType>::GetMatrixResult() {
    return matrixResult;
}

template<class vertType,class wtType>
void Graph<vertType,wtType>::SetMatrixResult(int nResult) {
    matrixResult = nResult;
}

template<class vertType,class wtType>
void Graph<vertType,wtType>::DisplayMatrix() {
    for(int i = 0; i < totalV; ++i) {
        qDebug() << "Vert ID #" << i << ": " << vertList[i].name.GetTeamName();
        for(int j = 0; j < totalV; ++j) {
            qDebug() << "\tAdj #" << j << ": " << vertList[j].name.GetTeamName() << " - Weight:" << matrix[i][j];
        }
        qDebug() << endl;
    }
}

template<class vertType,class wtType>
double Graph<vertType,wtType>::GetGrandTotal() {
    double out = 0;
    for (int i = 0; i < totalV; i++)
        out += vertList[i].name.GetTotalRevenue();
    return out;
}

#endif	/* GRAPH_H */
