#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
    string name;
    int cla;
    char section;
    int student_id;
};

int main() {
    int n;
    cin >> n;
    Student arr[n];
    int i;
    for (i = 0; i < n; i++) {
        cin >> arr[i].name >> arr[i].cla >> arr[i].section >> arr[i].student_id;
    }

    for (int i = 0; i < n / 2; i++) {
        swap(arr[i].section, arr[n - i - 1].section);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i].name << " " << arr[i].cla << " " << arr[i].section << " " << arr[i].student_id << endl;
    }

    return 0;
}
