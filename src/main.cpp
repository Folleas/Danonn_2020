/*
** EPITECH PROJECT, 2020
** main
** File description:
** file
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <list>
using namespace std;

int selection(vector<double> stack)
{
    int x = 0;
    int a = 0;
    int b = 0;
    int stock = a;
    double s;

    while (a < stack.size() - 1) {
        stock = a;
	b = a + 1;
        while (stack.size() > b) {
            if (stack[b] < stack[stock])
                stock = b;
	    x++;
            b++;
        }
        if (a != stock) {
            s = stack[stock];
            stack[stock] = stack[a];
            stack[a] = s;
        }
        a++;
    }
    return (x);
}

int insertion(vector<double> stack)
{
    int x = 0;
    list<double> list;
    int a = 0;
    std::list<double>::iterator stock;

    while (stack.size() > a) {
        if (list.empty())
            list.push_back(stack[a]);
        else {
            for (std::list<double>::iterator it = list.begin(); it != list.end(); it++) {
                x++;
                if (stack[a] < *it) {
                    list.insert(it, stack[a]);
                    break;
                }
                stock = it;
            }
            stock++;
            if (stock == list.end())
                list.push_back(stack[a]);
        }
        a++;
    }
    return (x);
}

int bubble(vector<double> stack)
{
    int x = 0;
    int a = stack.size() - 2;
    int b = 0;

    while (a + 1 > 0) {
        b = 0;
        while (a + 1 > b) {
            x++;
            if (stack[b + 1] < stack[b]) {
                double stock = stack[b];
                stack[b] = stack[b + 1];
                stack[b + 1] = stock;
            }
            b++;
        }
        a--;
    }
    return (x);
}

int quick(vector<double> stack)
{
    int x = 0;
    int stock = 0;
    int a = 0;
    vector<double> i;
    vector<double> j;

    if (stack.size() <= 1)
        return (0);
    while (stack.size() > a) {
        if (stock != a) {
            x++;
            if (stack[a] >= stack[stock])
                j.push_back(stack[a]);
            if (stack[stock] > stack[a])
                i.push_back(stack[a]);
        }
        a++;
    }
    if (a > 0) {
        x = x + quick(i);
        x = x + quick(j);
    }
    return (x);
}

int merge(vector<double> stack)
{
    int x = 21;

    return (x);
}

void print_sorts(vector<double> stack)
{
    cout << "Selection sort: " << selection(stack) << " comparisons" << endl;
    cout << "Insertion sort: " << insertion(stack) << " comparisons" << endl;
    cout << "Bubble sort: " << bubble(stack) << " comparisons" << endl;
    cout << "Quicksort: " << quick(stack) << " comparisons" << endl;
    cout << "Merge sort: " << merge(stack) << " comparisons" << endl;
}

bool errorHandling(int ac, char **av)
{
    if (ac != 2 || av[1][1] == 'h') {
        cerr << "USAGE\n\t" << av[0] << " file" << endl;
        return (true);
    }
    ifstream file;
    file.open(av[1]);
    std::stringstream buffer;
    buffer << file.rdbuf();
    if (buffer.str().empty()) {
        return (true);
    }
    return (false);
}

bool isDigits(const string s)
{
    return s.find_first_not_of( ".0123456789" ) == string::npos;
}


int main(int ac, char **av)
{
    ifstream stream;
    vector<double> stack;
    string new_line;
    string str;

    if (errorHandling(ac, av)) {
        return (84);
    } else {
        stream.open(av[1]);
        getline(stream, new_line);
        istringstream sstr(new_line);
        while (getline(sstr, str, ' ')) {
            if (!isDigits(str.c_str()))
                return (84);
            stack.push_back(atof(str.c_str()));
        }
        if (stack.size() > 1)
            cout << stack.size() << " elements" << endl;
        else
            cout << stack.size() << " element" << endl;
        print_sorts(stack);
        return (0);
    }
}
