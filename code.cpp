#include <iostream>

using namespace std;

int main() {
    int n;
    cout<<"Enter size of the arr: ";
    cin>>n;
    cout<<endl;

    int sum=0,num=0;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        sum+=num;
    }

    cout<<endl<<"Avg: "<<sum/n<<endl;
    return 0;
}
