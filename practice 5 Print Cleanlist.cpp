#include <iostream>

using namespace std;

int main()
{
    int arr[]={01,01,02,03,03,04,05};
    int n = sizeof(arr)/sizeof(arr[0]);

     if(n==0) {
        cout<< "list is empty";
        cout<<endl;
        return 0;
     }
    int cleanlist = 0;
    for(int i=1;i<n;i++){
        if(arr[i]!= arr[cleanlist]){
            cleanlist++;
            arr[cleanlist]=arr[i];
        }
    }
    for(int i=0;i<cleanlist;i++){
        cout<< arr[i]<<" ";
    }
     cout<<endl;

    return 0;
}
