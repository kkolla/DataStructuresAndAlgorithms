#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
long long int addVector(vector<long long int> & container, int a, int b, long long int k) {
    long long int maxVal = container[a];
    if (a == b) {
        container[a] += k;
        return max(maxVal, container[a]);
    }
    for (int i = a; i <= b && i < container.size(); i++)
    {
        container[i] += k;
        maxVal = max(maxVal, container[i]);
    }
    return maxVal;
}

void printVector(vector<long long int> & box)
{
    for (int i = 0;i < box.size(); i++)
    {
       cout << box[i] << " ";
    }
    cout<<endl;
}


int main() {
    long long int maxVal = LLONG_MIN;
    long long int n = 0, m = 0;
    cin >> n >> m;
    std::vector<long long int> container(n, 0);

    for (long long int i = 0; i < m; i++) {
        long long int k;
        int a, b;
        cin >>a >> b >>k;
        if (k != 0) {
            maxVal = max(maxVal, addVector(container, a-1, b-1, k));
        }
    }
    cout<<maxVal<<endl;
    return maxVal;
}
