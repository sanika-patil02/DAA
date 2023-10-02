#include<iostream>
using namespace std;

int v,e,src,v1,v2,p=0;
int main(){
cout<<"Enter no of vertices:";
cin>>v;
cout<<"Enter no of edges:";
cin>>e;
cout<<"Enter the source vertex:";
cin>>src;

int mat[v][v],edge[2*e],dist[v],prev[v];                         
for(int i=1;i<=v;i++){                 //Initialize each element in adjacency matrix to 0
    for(int j=1;j<=v;j++){
         mat[i][j]=0;
    }
}
cout<<endl;

cout<<"*********Enter Edges*********"<<endl;      //input from user
for(int i=0;i<e;i++){
cout<<"edge "<<i+1<<" :\n";
cout<<"Enter the source:";
cin>>v1;
cout<<"Enter the destination:";
cin>>v2;
cout<<"Enter the weight:";
cin>>mat[v1][v2];
cout<<endl;
edge[p]=v1;
edge[p+1]=v2;
p=p+2;
}

cout<<"Adjacency matrix for graph is:\n";
for(int i=1;i<=v;i++){                   //Print adjacency matrix
    for(int j=1;j<=v;j++){
        cout<<mat[i][j]<<"\t";
    }
    cout<<endl;
}

p=0; 
cout<<"\nSet of edges: ";                                           //Print edges
for(int i=0;i<e;i++){
    cout<<"("<<edge[p]<<","<<edge[p+1]<<")\t";
    p=p+2;
}
cout<<endl;

for(int i=0;i<v;i++){            //Initialize each vertex is at infinity distance and source is at 0
    dist[i]=999; 
}
dist[src-1]=0;               //Graph starts with vertex 1,so if the src is 2 then it is stored in dist arr at index 1

for(int i=0;i<v;i++){
    p=0;
    for(int j=0;j<e;j++){
        v1=edge[p];
        v2=edge[p+1];
        p=p+2;

        if(dist[v1-1]+mat[v1][v2]<dist[v2-1]){
            dist[v2-1]=dist[v1-1]+mat[v1][v2];
        }

    }

    cout<<"Iteration"<<i+1<<"\t";
    for(int k=0;k<v;k++){
        cout<<dist[k]<<"\t";
    }
    cout<<endl;

    if(i==0){
        for(int k=0;k<v;k++){
             prev[k]=dist[k]; 
        }
           
    }
    else{
        int flag=0;
        for(int k=0;k<v;k++){
            if(prev[k]!=dist[k]){
                flag=1;
                break;
            }
        }

        if(flag==0){
            cout<<"There is no change in distance matrix,so we can stop here....";
            break;
        }

        else if(i==v-1){
            cout<<"There is dissimilarity even after v-1 iterations,so graph contain negative edge cycle";
        }

        else{
            for(int k=0;k<v;k++){
                 prev[k]=dist[k];
            }
           
        }
        

    }
}

}

/********OUTPUT 1*********

Enter no of vertices:4
Enter no of edges:5
Enter the source vertex:1

**********Enter Edges*********
edge 1 :
Enter the source:3
Enter the destination:2
Enter the weight:-10

edge 2 :
Enter the source:4
Enter the destination:3
Enter the weight:3

edge 3 :
Enter the source:2
Enter the destination:4
Enter the weight:8

edge 4 :
Enter the source:1
Enter the destination:2
Enter the weight:4

edge 5 :
Enter the source:1
Enter the destination:4
Enter the weight:5

Adjacency matrix for graph is:
0       4       0       5
0       0       0       8
0       -10     0       0
0       0       3       0

Set of edges: (3,2)     (4,3)   (2,4)   (1,2)   (1,4)
Iteration1      0       4       999     5
Iteration2      0       4       8       5
Iteration3      0       -2      8       5
Iteration4      0       -2      8       5
There is no change in distance matrix,so we can stop here....
*/

/**********OUTPUT 2************
Enter no of vertices:4
Enter no of edges:5
Enter the source vertex:1

*********Enter Edges*********
edge 1 :
Enter the source:1
Enter the destination:2
Enter the weight:5

edge 2 :
Enter the source:1
Enter the destination:4
Enter the weight:4

edge 3 :
Enter the source:2
Enter the destination:3
Enter the weight:3

edge 4 :
Enter the source:3
Enter the destination:4
Enter the weight:-10

edge 5 :
Enter the source:4
Enter the destination:2
Enter the weight:5

Adjacency matrix for graph is:
0       5       0       4
0       0       3       0
0       0       0       -10
0       5       0       0

Set of edges: (1,2)     (1,4)   (2,3)   (3,4)   (4,2)
Iteration1      0       3       8       -2
Iteration2      0       1       6       -4
Iteration3      0       -1      4       -6
Iteration4      0       -3      2       -8
There is dissimilarity even after v-1 iterations,so graph contain negative edge cycle....
*/