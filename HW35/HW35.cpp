#include <iostream>
#include <vector>
using namespace std;

vector<int> readArray(const string& name)
{
    int n;
    cout << "Enter size of " << name << ": ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements of " << name << ": ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    return a;
}

bool contains(const vector<int>& a, int x)
{
    for (int v : a)
        if (v == x)
            return true;
    return false;
}

void task1(const vector<int>& a)
{
    int sum = 0;
    for (int x : a)
    {
        x = abs(x);
        while (x > 0)
        {
            sum += x % 10;
            x /= 10;
        }
    }
    cout << "Sum of digits: " << sum << endl;
}

void task2(const vector<int>& a)
{
    int sum = 0, count = 0;
    for (int x : a)
    {
        if (x > 0)
        {
            sum += x;
            count++;
        }
    }
    if (count == 0)
        cout << "No positive elements" << endl;
    else
        cout << "Average of positive elements: " << (double)sum / count << endl;
}

void task3(const vector<int>& a)
{
    int pos = -1;
    for (int i = 0; i < (int)a.size(); i++)
    {
        if (a[i] < 0 && (pos == -1 || a[i] > a[pos]))
            pos = i;
    }
    if (pos == -1)
        cout << "No negative elements" << endl;
    else
        cout << "Max negative element: " << a[pos] << ", index: " << pos << endl;
}

void task4(const vector<int>& a)
{
    if (a.empty())
    {
        cout << "Array is empty" << endl;
        return;
    }
    int bestValue = a[0], bestCount = 0;
    for (int i = 0; i < (int)a.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < (int)a.size(); j++)
            if (a[j] == a[i])
                count++;
        if (count > bestCount)
        {
            bestCount = count;
            bestValue = a[i];
        }
    }
    cout << "Most frequent number: " << bestValue << " (" << bestCount << " times)" << endl;
}

void task5(const vector<int>& a)
{
    int pos = -1;
    for (int i = 0; i < (int)a.size(); i += 2)
    {
        if (a[i] % 3 == 0 && (pos == -1 || a[i] > a[pos]))
            pos = i;
    }
    if (pos == -1)
        cout << "No suitable elements" << endl;
    else
        cout << "Largest element divisible by 3 at odd positions: " << a[pos]
        << ", index: " << pos << endl;
}

void task6(vector<int>& a)
{
    int maxEven = -1, minOdd = -1;
    for (int i = 0; i < (int)a.size(); i++)
    {
        if (a[i] % 2 == 0)
        {
            if (maxEven == -1 || a[i] > a[maxEven])
                maxEven = i;
        }
        else
        {
            if (minOdd == -1 || a[i] < a[minOdd])
                minOdd = i;
        }
    }
    if (maxEven == -1 || minOdd == -1)
    {
        for (int& x : a)
            x = 0;
        cout << "One of the elements not found, array filled with zeros" << endl;
    }
    else
    {
        int tmp = a[maxEven];
        a[maxEven] = a[minOdd];
        a[minOdd] = tmp;
        cout << "Swapped" << endl;
    }
    cout << "Result: ";
    for (int x : a)
        cout << x << " ";
    cout << endl;
}

void task7(const vector<int>& a, const vector<int>& b)
{
    vector<int> both, only;

    for (int x : a)
        if (contains(b, x) && !contains(both, x))
            both.push_back(x);

    for (int x : a)
        if (!contains(b, x) && !contains(only, x))
            only.push_back(x);
    for (int x : b)
        if (!contains(a, x) && !contains(only, x))
            only.push_back(x);

    cout << "Present in both arrays: ";
    for (int x : both)
        cout << x << " ";
    cout << endl;

    cout << "Present in only one array: ";
    for (int x : only)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int choice;
    do
    {
        cout << "\n1. Sum of digits\n"
            << "2. Average of positive elements\n"
            << "3. Max negative element\n"
            << "4. Most frequent number\n"
            << "5. Largest element divisible by 3 at odd positions\n"
            << "6. Swap max even and min odd\n"
            << "7. Two arrays: common / unique elements\n"
            << "0. Exit\n"
            << "Choose task: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5)
        {
            vector<int> a = readArray("array");
            switch (choice)
            {
            case 1: task1(a); break;
            case 2: task2(a); break;
            case 3: task3(a); break;
            case 4: task4(a); break;
            case 5: task5(a); break;
            }
        }
        else if (choice == 6)
        {
            vector<int> a = readArray("array");
            task6(a);
        }
        else if (choice == 7)
        {
            vector<int> a = readArray("first array");
            vector<int> b = readArray("second array");
            task7(a, b);
        }
    } while (choice != 0);
}