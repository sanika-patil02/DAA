#include<iostream>
using namespace std;
#include<math.h>

struct object{
int id,weight,profit;
};

int wg,n;


int main(){
cout<<"Weight of the knapsack:";
cin>>wg;
cout<<"Total objects:";
cin>>n;

object arr[n];
int matrix[n+1][wg+1];
int objtaken[n];

for(int i=0;i<n;i++){    
arr[i].id=i+1;                        //Take weight and profit of each object from user
cout<<"Enter Weight and Profit of object "<<arr[i].id<<" :"<<endl;
cin>>arr[i].weight>>arr[i].profit;
}

cout<<"Object\t"<<"Weight\t"<<"Profit"<<endl;     //print weight and profit of each object
for(int j=0;j<n;j++){
cout<<arr[j].id<<"\t"<<arr[j].weight<<"\t"<<arr[j].profit<<endl;
}

for(int i=0;i<n;i++){                             //sort weight
for (int j=0;j<n-1;j++){
if(arr[j].weight>arr[j+1].weight){
object temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}

cout<<"Object\t"<<"Weight\t"<<"Profit"<<endl;     //Arrange weight in ascending order
for(int j=0;j<n;j++){
cout<<arr[j].id<<"\t"<<arr[j].weight<<"\t"<<arr[j].profit<<endl;
}

 for(int i=0;i<=n;i++){
        for(int w=0;w<=wg;w++){
            if(i==0 || w==0){
                matrix[i][w]=0;
                }
                else if(arr[i-1].weight<=w){
                     matrix[i][w]=max(matrix[i-1][w],matrix[i-1][w-arr[i-1].weight]+arr[i-1].profit);
                
                    }
                    else{
                        matrix[i][w]=matrix[i-1][w];
                      
                        }
                        }
 }

cout<<endl;
cout<<endl;
for(int i=0;i<=n;i++){                  //Print matrix
for(int w=0;w<=wg;w++){
cout<<matrix[i][w]<<"       ";
}
cout<<endl;
}


cout<<"Maximum Profit:";               //maximum profit
cout<<matrix[n][wg]<<endl;

int weight_remain=wg;                          //sequence
for(int i=n;i>0;i--){
    for(int w=weight_remain;w>0;w--){
        if(matrix[i][weight_remain]==matrix[i-1][weight_remain]){
            int k=arr[i-1].id;                                  
            objtaken[k-1]=0;
            break;
            }
            
            else{
                int k=arr[i-1].id;
                objtaken[k-1]=1;
                weight_remain=weight_remain-arr[i-1].weight;
                break;
                }

    }
    
}            


cout<<"{"<<"  ";
for(int i=0;i<n;i++){
    cout<<objtaken[i]<<"  ";
}
cout<<"}";

}



/****************OUTPUT******************
Weight of the knapsack:8
Total objects:4
Enter Weight and Profit of object 1 :
3
2
Enter Weight and Profit of object 2 :
4
3
Enter Weight and Profit of object 3 :
6
1
Enter Weight and Profit of object 4 :
5
4
Object  Weight  Profit
1       3       2
2       4       3
3       6       1
4       5       4
Object  Weight  Profit
1       3       2
2       4       3
4       5       4
3       6       1


0       0       0       0       0       0       0       0       0
0       0       0       2       2       2       2       2       2       
0       0       0       2       3       3       3       5       5       
0       0       0       2       3       4       4       5       6
0       0       0       2       3       4       4       5       6
Maximum Profit:6
{  1  0  0  1  }
*/