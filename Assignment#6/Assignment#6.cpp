#include <iostream>
using namespace std;

class Length {
private:
    // Data Members
    int feet;
    double inches;

public:
    // Constructors
    Length() {
        feet = 0;
        inches = 0;
    }
    Length(int f, double i = 0) {
        feet = f;
        inches = i;
    }
    Length(double ln) {
        feet = static_cast<int>(ln);
        inches = ln - feet;
    }

    // Access Functions (Getters)
    int getFeet() { return feet; };
    double getInches() { return inches; };
    double getLength() { return (feet * 12) + inches; };
    double Meters() { return (feet * 0.3048) + (inches * 0.0254); };

    // Arithmetic/Comparison Functions
    Length Add(Length ln) {
        Length l = *this;
        l.AddTo(ln);

        return l;
    };
    Length operator+(Length ln) {
        Length tmp;
        tmp.feet = feet + ln.feet;
        tmp.inches = inches + ln.inches;

        // Normalize inches
        if (tmp.inches >= 12.0) {
            tmp.inches -= 12.0;
            tmp.feet++;
        }

        return tmp;
    }
    bool LessThan(Length l) {
        if (getLength() < l.getLength()) {
            cout << boolalpha;
            return true;
        }
        else {
            cout << boolalpha;
            return false;
        }
    };
    bool operator<(Length l) {
        if (getLength() < l.getLength()) {
            cout << boolalpha;
            return true;
        }
        else {
            cout << boolalpha;
            return false;
        }
    }
    bool GreaterThan(Length l) {
        if (getLength() > l.getLength()) {
            cout << boolalpha;
            return true;
        }
        else {
            cout << boolalpha;
            return false;
        }
    };
    bool operator>(Length l) {
        if (getLength() > l.getLength()) {
            cout << boolalpha;
            return true;
        }
        else {
            cout << boolalpha;
            return false;
        }
    }
    bool EqualTo(Length l) {
        if (getLength() == l.getLength()) {
            cout << boolalpha;
            return true;
        }
        else {
            cout << boolalpha;
            return false;
        }
    };
    bool operator==(Length l) {
        if (getLength() == l.getLength()) {
            cout << boolalpha;
            return true;
        }
        else {
            cout << boolalpha;
            return false;
        }
    }

    // Modifier Functions (Setters)
    void setFeet(int f) { feet = f; };
    void setInches(double i) { inches = i; };
    void setLength(int f, double i) { feet = f, inches = i; };
    void setLength(double ln) { feet = static_cast<int>(ln), inches = ln - feet; };
    void AddTo(Length ln) {
        feet += ln.feet;
        inches += ln.inches;

        while (inches >= 12.0) {
            inches -= 12.0;
            feet++;
        }
    };

    // Input/Output Functions
    void Read() {
        char quote;
        cin >> feet >> quote >> inches >> quote;
    };
    friend istream& operator>>(istream& s, Length& l);
   
    void Write() { cout << feet << "'" << inches << "''"; };
    friend ostream& operator<<(ostream& s, Length& l);
};

istream& operator>>(istream& s, Length& l) {
    char quote;
    s >> l.feet >> quote >> l.inches >> quote;
    return s;
}

ostream& operator<<(ostream& s, Length& l) {
    s << l.getFeet() << "'" << l.getInches() << "''";
    return s;
}

void ReadData(Length list[], int& size);
void SortData(Length lst[], int sz, char order = 'A');
void Swap(Length lst[], int i, int j);
void DisplayData(Length list[], int size);

int main()
{
    Length list[100];
    int size = 0;

    ReadData(list, size);
    SortData(list, size, 'A');
    DisplayData(list, size);
}

void ReadData(Length list[], int& size) {
    string input = "";

    cout << "Would you like to sort a length value (yes/no)? ";
    cin >> input;

    if (input != "Yes" && input != "yes") exit(0);

    while (input == "Yes" || input == "yes") {
        cout << "Enter a length value in from f'i: ";
        cin >> list[size];

        cout << endl;

        cout << "Would you like to sort a length value (yes/no)? ";
        cin >> input;

        size++;
    }
}

void SortData(Length lst[], int sz, char order) {
    cout << "\nSpecify sort order, ''A'' for asceding, ''D'' for descending: ";
    cin >> order;
    cout << endl;

    while (order != 'A' && order != 'a' && order != 'D' && order != 'd') {
        cout << "Input a correct value ('A' or 'D' in uppercase or lowercase): ";
        cin >> order;
    }

    if (order == 'A' || order == 'a') {
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if (lst[i] > lst[j]) Swap(lst, i, j);
            }
        }
        cout << "Length List" << endl;
        for (int i = 0; i < sz; i++) i == sz - 1 ? cout << lst[i] << endl: cout << lst[i] << ", ";
    }

    if (order == 'D' || order == 'd') {
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if (lst[i] < lst[j]) Swap(lst, i, j);
            }
        }
        cout << "Length List" << endl;
        for (int i = 0; i < sz; i++) i == sz - 1 ? cout << lst[i] << endl: cout << lst[i] << ", ";
    }
}

void Swap(Length arr[], int i, int j) {
    Length tmp;

    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void DisplayData(Length list[], int size) {
    cout << "\nNumber of Length values in the array: " << size;
    cout << "\nEach of the Length values in the array in the order in which they are contained in the array:" << endl;
    for (int i = 0; i < size; i++) cout << i+1 << ": " << list[i] << endl;
}