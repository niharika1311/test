#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b) {
  if(b == 0)
    return a;
  else
    return gcd(b, a%b);
}

void arrayRotation(vector<int> &a, int k) {
  int n = a.size();
  int i, j, d, temp;
  for(i = 0; i < gcd(n, k); i++) {
    j = i;
    temp = a[i];
    while(1) {
      d = (j + k) % n;
      if(d == i)
        break;
      a[j] = a[d];
      j = d;
    }
    a[j] = temp;
  }
}

int main() {
  vector<int> arr{2, 3, 4, 5, 6, 7};
  cout << "Array before rotation is: ";
  for(const auto &num: arr)
    cout << num << " ";
  cout << endl;
  arrayRotation(arr, 3);
  cout << "Array after rotation is: ";
  for(const auto &num: arr)
    cout << num << " ";
  cout << endl;
  return 0;
}
