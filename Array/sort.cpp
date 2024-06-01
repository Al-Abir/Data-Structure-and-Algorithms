#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string name;
    int cls;
    char section;
    int student_id;
    int math_marks;
    int eng_marks;
    int total_marks;

    void calculate_total_marks() {
        total_marks = math_marks + eng_marks;
    }
};

bool cmp(Student a, Student b) {
    if (a.total_marks == b.total_marks) {
        return a.student_id < b.student_id;
    } else {
        return a.total_marks > b.total_marks;
    }
}

int main() {
    int n;
    cin >> n;
    Student a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].cls >> a[i].section >> a[i].student_id >> a[i].math_marks >> a[i].eng_marks;
        a[i].calculate_total_marks();
    }

    sort(a, a+n, cmp);

    for (int i = 0; i < n; i++) {
        cout << a[i].name << " " << a[i].cls << " " << a[i].section << " " << a[i].student_id << " " << a[i].math_marks << " " << a[i].eng_marks << endl;
    }

    return 0;
}
