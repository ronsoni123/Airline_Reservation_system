#include<bits/stdc++.h>
#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <utility>
#define K 14
#define INF 3999


using namespace std;

typedef pair<int, int> Pair;
class ShortestPath{
    int V, E;
    vector<Pair > *graph;
    int *dist;

        //  In the priority queue, first element is weight and second is destination, bcoz it sorts acc. to first element
    priority_queue<Pair, vector<Pair> , greater<Pair> > pq;
public:
    ShortestPath(int v, int e){
        V = v;
        E = e;
        graph = new vector<Pair >[V];
        dist = new int[V];
        for(int i = 0; i<V; i++)
            dist[i] = INT_MAX;
    }
    void createGraph();
    void dijkstra(int );
    void print(int );
};
void ShortestPath :: createGraph(){
    int a, b, c;
    FILE *fp;
    fp=fopen("input.txt","r");
    while(fscanf(fp,"%d%d%d",&a,&b,&c)!=EOF)
            {
                graph[a].push_back(make_pair(b,c));
                graph[b].push_back(make_pair(a,c));
            }
}
void ShortestPath :: dijkstra(int source){
    dist[source] = 0;
    pq.push(make_pair(dist[source],source));
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(int i = 0; i<graph[u].size(); i++){
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if(dist[u] != INT_MAX && w + dist[u] < dist[v])
                dist[v] = w + dist[u], pq.push(make_pair(dist[v], v));
        }
    }
}
void ShortestPath :: print(int source){
    int dest;
    cout<<" enter destination for journey :- ";
    cin>>dest;
    cout<<"\n\t Vertex \t Distance from source";
    for(int i = 0; i<V; i++){
        cout<<"\n\t  "<<i<<"\t\t\t"<<dist[i];
    }
    cout<<"\n\t Minimum Distance from source:- ";
        cout<<dist[dest];
    }



//************************************PRIMS-CODE*************************************************//
class PrimsMST{
    int V, E;
    vector<Pair> *graph;
    int *parent;
    int *key;
    bool *mstset;
    priority_queue<Pair, vector<Pair> , greater<Pair> > pq;
public:
    PrimsMST(int v, int e){
        V = v;
        E = e;
        graph = new vector<Pair>[V];
        parent = new int[V];
        key = new int[V];
        mstset = new bool[V];
        for(int i = 0; i<V; i++)
            key[i] = INT_MAX, mstset[i] = false;

        key[0] = 0;
        parent[0] = -1;
        pq.push(make_pair(0,0));
    }
    void createGraph();
    void calcMST();
    void printMST();
};
void PrimsMST :: createGraph(){
    int a, b, c;
    FILE *fp;
    fp=fopen("input.txt","r");
    while(fscanf(fp,"%d%d%d",&a,&b,&c)!=EOF)
            {
                graph[a].push_back(make_pair(b,c));
                graph[b].push_back(make_pair(a,c));
            }
}
void PrimsMST :: calcMST(){
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        mstset[u] = true;
        for(int i = 0; i<graph[u].size(); i++){
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if(mstset[v] == false && w < key[v])
                pq.push(make_pair(w, v)), parent[v] = u, key[v] = w;

        }
    }
}
void PrimsMST :: printMST(){
    cout<<"\n\n Following are the edges in the Prim's MST : \n\n\t Edge     |    Weight \n\n\t ------------------- \n";
    for(int i = 1; i<V; i++)
        cout<<"\t("<<parent[i]<<"----- "<<i<<")   |     "<<key[i]<<endl;
    cout<<"\n\n\t Complexity of Prim's MST (using adjacency list) : O(E log V))\n";
}
//*****************************************floyed-warshell**************************************//

void printSolution(int dist[][K]);

void floyds(int b[20][20],int n)
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if ((b[i][k] * b[k][j] != 0) && (i != j))
                {
                    if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))
                    {
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        cout<<"\nMinimum Cost With Respect to Node:"<<i<<endl;
        for (j = 0; j < n; j++)
        {
        	if(j>i)
            cout<<b[i][j]<<"\t";
            else
            cout<<"NA"<<"\t";
        }
 
    }
}
    


/* A utility function to print solution */
void printSolution(int dist[][K])
{
    int source,dest;
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
    cout<<"enter source and destination"<<endl;
    cin>>source>>dest;
    cout<<"shortest distance between "<<source<<" and "<<dest<<"is  "<<dist[source][dest]<<endl;
}
//**********************************************main function********************************//
int main(){
    int v, e, source,ch,t=3;
    /*cout<<"enter the number of cities"<<endl;
	cin>>n;
	string x[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
			}	*/	
    while(t>0)
{


    cout<<"\n\tMAIN MENU\n\t---------\n\t1.To Find Shortest Distance For 2 Way Path\n\t2.Shortest Route Between All The Stations\n\t";
    cout<<"3.Shortest Path For One Way Traffic Flow\n\t4.Exit";
    cout<<"\n\n\tEnter Your Choice : ";
    cin>>ch;
    cout<<endl;
    switch(ch)
    {
    	case 1:
    	{
    	    int v, e, source,ch,a,b,c;
            FILE *fp;
            fp=fopen("ve.txt","r");
            while(fscanf(fp,"%d%d",&v,&e)!=EOF);
    		ShortestPath SP(v,e);
    		SP.createGraph();
    		cout<<"\n Enter the source vertex : ";
    		cin>>source;
    		SP.dijkstra(source);
    		SP.print(source);
			break;
		}
		case 2:
		{
		    int v, e, source,ch,a,b,c;
            FILE *fp;
            fp=fopen("ve.txt","r");
            while(fscanf(fp,"%d%d",&v,&e)!=EOF);
			PrimsMST PMST(v,e);
    		PMST.createGraph();
    		PMST.calcMST();
    		PMST.printMST();
    		break;
		}
		case 3:
		{
			vector<int> numbers;
			int k=0,n;
			int b[20][20];
			cout<<"enter the number of cities"<<endl;
			cin>>n;
			ifstream in("abc.txt",ios::in);
		
			
			int number;  
			
		        
		        while (in >> number) {
				
				numbers.push_back(number);
			}
		
			
			in.close();
		
			
			
			cout << "Numbers:\n";
			for (int i=0; i<n; i++) {
				
				for(int j=0;j<n;j++)
				{
					if(k<numbers.size())
					{
						b[i][j]=numbers[k++];
					}
				}
			}
			floyds(b,n);
			break;
        }

		case 4:
		exit(0);
		default :cout<<"\nInvalid Choice";

	}
}

}



