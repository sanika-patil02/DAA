//Name - Sanika Sanjay Patil
//Roll No - TIB53


#include<iostream>
using namespace std;

struct item{
int profit, weight;
};

int wg,n;
float totalprofit;

void KnapsackAlgo(item arr[],float ratio[]){
    int index;
for(int j=0;j<n;j++){
if(arr[j].weight>wg){
    index=j;
    break;
}
else{
    cout<<"object "<<j+1<<"=1.0\t";
    wg=wg-arr[j].weight;
    totalprofit=totalprofit+arr[j].profit;
}

}

if(wg>0){
    float x=(float)wg/arr[index].weight;
    cout<<"object "<<index+1<<"="<<x<<endl;
    wg=wg-(x*arr[index].weight);
    //cout<<wg;
    totalprofit=totalprofit+(x*arr[index].profit);
}
cout<<"Total Profit="<<totalprofit;
}

int main (){

cout<<"weight of the knapsack:";
cin>>wg;
cout<<"Number of items:";
cin>>n;
item arr[n];
cout<<"enter the profit and weight of each object:\n";
for(int k=0;k<n;k++){
cout<<"Profit and weight of "<<k+1<<" object:";         //Take inputs from user
cin>>arr[k].profit;
cin>>arr[k].weight;
}


float ratio [n];                                       //Find P/W ratio
for(int j=0;j<n;j++){
ratio[j]=(float)arr[j].profit/arr[j].weight;
}


cout<<"Object\tProfit\tWeight\tP/W"<<endl;           //Before Sorting
for(int i=0;i<n;i++){
     cout<<i+1<<"\t"<<arr[i].profit<<"\t"<<arr[i].weight<<"\t"<<ratio[i]<<endl;
}

for(int i=0;i<n;i++){                                 //Sorting P/W ratio
for(int j=0;j<n-1;j++){
if(ratio[j]<ratio[j+1]){
float temp1=ratio[j];
ratio[j]=ratio[j+1];
ratio[j+1]=temp1;

item temp2=arr[j];                                   //swap profit and weight as per P/W ratio
arr[j]=arr[j+1];
arr[j+1]=temp2;
}
}
}

cout<<endl;                                          //After Sorting
cout<<"After Sorting"<<endl;
cout<<"Object\tProfit\tWeight\tP/w\n";
for(int i=0;i<n;i++){
    cout<<i+1<<"\t"<<arr[i].profit<<"\t"<<arr[i].weight<<"\t"<<ratio[i]<<endl;
}


KnapsackAlgo(arr,ratio);
}
