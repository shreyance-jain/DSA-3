#include <iostream>
using namespace std;
 
struct Interval
{
    int buy;
    int sell;
};
 
void stockBuySell(int arr[], int n)
{
    if (n == 1) return;
    Interval sol[n/2 + 1];
    int count = 0, i = 0;
    while(i < n){
        // find the local minima
        while((i < n-1) && arr[i+1] <= arr[i])
            i++;
        if (i == n-1) break;
        sol[count].buy = i++;
        // finding the corresponding local maxima
        while ((i < n) && arr[i] >= arr[i-1])
            i++;
        sol[count].sell = i-1;
        count++;
    }
    if (count == 0){
        cout << "No Profit";
    } else {
        for(int i = 0; i < count; i++){
            cout << "Buy on: " << sol[i].buy << "\t Sell On: " << sol[i].sell << endl;
        }
    }
}

int main()
{   
    
    int price[10000],n,i,T;
    
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&price[i]);
    // fucntion call
    stockBuySell(price, n);
    cout<<endl;
    }
    return 0;
}