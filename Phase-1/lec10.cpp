// Array-02.....questions solving

#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    cout << "printing the array " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// alternate swap
void A_swap(int x[], int size)
{
    int temp;
    // if(size%2){      //important step
    //     size--;
    // }
    for (int i = 0; i < size / 2; i++)
    {
        temp = x[2 * i];
        x[2 * i] = x[2 * i + 1];
        x[2 * i + 1] = temp;
    }
}

// unique element  (elements in form of 2m+1...)
int unique(int x[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (x[i] == x[j] && j != i)
            {
                break;
            }
            if (j == size - 1)
            {
                return x[i];
            }
        }
    }
}
// unique element sir's sol.
int Unique(int arr[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i]; // a^a=0...and...a^0=a
                            // if a^b=0 --> a=b
    }
    return ans;
}
// find duplicate
int duplicate(int x[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (x[i] == x[j] && j != i)
            {
                return x[i]; // or x[j]
            }
        }
    }
}

void all_duplicate(int x[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (x[i] == x[j])
            {
                cout << x[i] << " ";
            }
        }
    }
}
// sir's sol
int Duplicate(int x[], int size)
{
    int ans = 0;
    for (int i = 1; i < size; i++)
    {
        ans = ans ^ i;
    }
    for (int j = 0; j < size; j++)
    {
        ans = ans ^ x[j];
    }
    return ans;
}

void intersection(int x[], int a, int y[], int b){ 
    // array x must have distinct numbers
    int count = 0;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (x[i] == y[j])
            {
                cout << x[i] << " ";
                count++;
                y[j] = INT8_MIN;
                break;
            }
        }
    }
    if (!count)
    {
        cout << -1;
    }
}
// much faster to sort first
void sort(int x[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (x[j] < x[i])
            {
                int temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
}

void Intersection(int arr1[], int a, int arr2[], int b)
{
    sort(arr1, a);
    sort(arr2, b);
    int count = 0;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (arr1[i] < arr2[j])
            {
                break;
            }
            if (arr1[i] == arr2[j])
            {
                count++;
                cout << arr1[i] << " ";
                break;
            }
        }
    }
    if (count == 0)
    {
        cout << -1;
    }
}

void inter(int arr1[], int a, int arr2[], int b)
{
    sort(arr1, a);
    sort(arr2, b);
    int i = 0, j = 0, count = 0;
    while (i < a && j < b)
    {

        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            count++;
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}

void pair_sum(int x[], int size, int s)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (x[i] + x[j] == s && i != j)
            {
                if (x[i] < x[j])
                {
                    cout << "(" << x[i] << "," << x[j] << ")" << endl;
                }
                else
                {
                    cout << "(" << x[j] << "," << x[i] << ")" << endl;
                }
            }
        }
    }
}

void triplet(int arr[], int size, int p)
{
    for (int i = 0; i < size - 2; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (arr[i] + arr[j] + arr[k] == p)
                {
                    cout << "(" << arr[i] << "," << arr[j] << "," << arr[k] << ")" << endl;
                }
            }
        }
    }
}
// triplet ka optimize sol....by myself
void Triplet(int x[], int size, int p)
{
    for (int i = 0, j = i + 1, k = j + 1; i < size - 2 && j < size - 1 && k < size;)
    {
        //printing part
        if (x[i] + x[j] + x[k] == p)
        {
            cout << "(" << x[i] << "," << x[j] << "," << x[k] << ")" << endl;
        }

        //increment.....
        //remember to bring back k and j
        if (k < size - 1)
        {
            k++;
        }
        else if (j < size - 2)
        {
            j++;
            k = j + 1;
        }
        else
        {
            i++;
            j = i + 1;
            k = j + 1;
        }
    }
}

void sort_0_1(int x[], int size)
{
    for (int i = 0, j = size - 1; i < j;)
    {
        if (x[i] == 0 && x[j] == 1)
        {
            i++;
            j--;
        }
        else if (x[i] == 1 && x[j] == 0)
        {
            int t = x[i];
            x[i] = x[j];
            x[j] = t;
        }
        else if (x[i] == 1 && x[j] == 1)
        {
            j--;
        }
        else if (x[i] == 0 && x[j] == 0)
        {
            i++;
        }
    }
}
// sir's method
void sortOne(int arr[], int n)
{
    int left = 0, right = n - 1, step = 0;

    while (left < right)
    {
        // cout<<"step: "<<step++<<endl;   //debugged my program myself
        // printArray(arr,n);
        while (arr[left] == 0)
        {
            left++;
        }
        while (arr[right] == 1)
        {
            right--;
        }
        // yaha tk pohoch gye means
        // arr[left]=1...arr[right]=0
        // swap
        if (left < right)
        {
            arr[left] = 0;
            arr[right] = 1;
        }
    }
}
//nakamyaab koshish nhi rhi
void sortTwo(int arr[], int n){
    int i = 0, j = n - 1, k=0,step = 0, t,T;
    
    
    while (arr[i] == 0){i++;}
    while (arr[j] == 2){j--;}
    k=i;
    
    while (k<=j)
    {
        // cout << "step: " << step++ << endl; // debugged my program myself
        // printArray(arr, n);
        
        if(arr[k]==0){
            swap(arr[k],arr[i]);
            i++;k++;
        }
        else if(arr[k]==2){
            swap(arr[k],arr[j]);
            j--;
        }
        else{
            k++;
        }

        
        //below is just a bakvass but hardwork
        
        // while (arr[left] == 0)
        // {
        //     left++;
        // }
        // while (arr[right] == 2)
        // {
        //     right--;
        // }
        // // yaha tk pohoch gye means
        // // arr[left]=1,2...arr[right]=0,1
        // // swap
        // if (left < right && arr[left] == arr[right] && arr[left+1]!=arr[right-1])
        // {
        //     t=arr[left];
        //     arr[left]=arr[left+1];
        //     arr[left+1]=t;
        //     T=arr[right];
        //     arr[right]=arr[right-1];
        //     arr[right-1]=T;
        // }
        // else if (left < right && arr[left] == arr[right] && arr[left+1]==arr[right-1])
        // {
        //     t=arr[left];
        //     arr[left]=arr[left+2];
        //     arr[left+2]=t;
        //     T=arr[right];
        //     arr[right]=arr[right-2];
        //     arr[right-2]=T;
        // }
        // if (left < right && arr[right] == 0)
        // {
        //     arr[right] == arr[left];
        //     arr[left] == 0;
        //     left++;
        //     if (arr[right] == 2)
        //     {
        //         right--;
        //     }
        // }
        // if (left < right && arr[left] == 2)
        // {
        //     arr[left] = arr[right];
        //     arr[right] = 2;
        //     right--;
        //     if (arr[left] == 0)
        //     {
        //         left++;
        //     }
        // }
            // int m = arr[(left + right) / 2];
            // int n = arr[(left + right) / 2 + 1];
            // if (n >= m)
            // {
            //     t = arr[left];
            //     arr[left] = arr[(left + right) / 2];
            //     arr[(left + right) / 2] = t;
            //     t = arr[right];
            //     arr[right] = arr[(left + right) / 2 + 1];
            //     arr[(left + right) / 2 + 1] = t;
            // }
            // else
            // {
            //     t = arr[left];
            //     arr[left] = arr[(left + right) / 2 + 1];
            //     arr[(left + right) / 2 + 1] = t;
            //     t = arr[right];
            //     arr[right] = arr[(left + right) / 2];
            //     arr[(left + right) / 2] = t;
            // }
            // t=arr[left];
            // arr[left]=arr[(left+right)/2];
            // arr[(left+right)/2]=t;
            // t=arr[right];
            // arr[right]=arr[(left+right)/2+1];
            // arr[(left+right)/2+1]=t;
        // if(arr[left+1]==1  && arr[right-1]==1 ){
        //     exit;
        // }

    }


}
// Dutch Flag Algorithm
// ~F I discovered this lol....just one mistake
int main()
{
    // //alternate swap
    // int x[10]={2,1,2,1,2,1,2,1,2,1};
    // int s=10;
    // printArray(x,s);
    // A_swap(x,s);
    // printArray(x,s);

    // //dublicate
    // int y[7]={1,3,6,4,1,3,6};
    // int s= sizeof(y)/sizeof(int);
    // cout<<unique(y,s)<<endl;
    // cout<<Unique(y,s)<<endl;

    // //Hw--find all dublicates
    // int y[7]={1,3,6,4,1,3,6};
    // int s= sizeof(y)/sizeof(int);
    // all_duplicate(y,s);

    // // intersection...if empty then return -1
    // int x[10]={1,2,3,4,5,6,7,8,9,9};
    // int y[5]={10,9,11,7,9};
    // // intersection(x,10,y,5);
    // // Intersection(x,10,y,5);
    // inter(x,10,y,5);

    // //pair sum
    // int x[5]={5,4,3,2,1};
    // int size=5;
    // int s=5;
    // pair_sum(x,size,s);

    // //triplet with given sum..(similar to pair sum)
    // int y[11]={0,1,2,3,4,5,6,7,8,9,10};
    // int size=sizeof(y)/sizeof(int);
    // int k=12;
    // triplet(y,size,k);
    // cout<<"end"<<endl;
    // Triplet(y,size,k);  //lets goooooo baby!!!! :@

    // //Sort 0,1
    // int x[15]={0,0,1,1,0,1,0,1,1,0,1,1,1,0,1};
    // int s=sizeof(x)/sizeof(int);
    // // sort_0_1(x,s);
    // sortOne(x,s);
    // printArray(x,15);

    // HW sort 0,1,2....try to handle with different approach
    // first simple approach is to count all...O(n)
    // can do quick sort...O(nlog(n))
    int y[] = {2,2,1,0,0,0,0,0,0};
    int s = sizeof(y) / sizeof(int);
    sortTwo(y,s);
    printArray(y,s);

    return 0;
}