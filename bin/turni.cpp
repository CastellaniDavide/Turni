/**
 * @file turni.cpp
 *
 * @version 01.01 2021513
 *
 * @brief https://training.olinfo.it/#/task/turni/statement
 *
 * @ingroup turni
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Castellani Davide
 *
 * Contact: contacts@castellanidavide.it
 *
 */
#include <bits/stdc++.h>
#define DEBUG
using namespace std;

struct persona
{
    int inizio, fine;
    bool operator < (const persona& other) const
    {
        return inizio < other.inizio;
    }
};

int N, K, current, sol, tmp;
vector <persona> persone;

int main()
{
    freopen("input.txt", "r", stdin);
#ifndef DEBUG
    freopen("output.txt", "w", stdout);
#endif // DEBUG

    cin >> K >> N;
    persone.resize(N);
    current = -1;
    sol = 0;

    for (size_t i = 0; i < N; ++i)
        cin >> persone[i].inizio >> persone[i].fine;

    sort(persone.begin(), persone.end());

#ifdef DEBUG
    for (size_t i = 0; i < N; ++i)
        cout << persone[i].inizio << "\t" << persone[i].fine << endl;
#endif // DEBUG

    while (current < K - 1)
    {
        sol++;
        tmp = current;
        int i = -1;

        while (persone[++i].inizio <= current + 1)
            if (persone[i].fine > tmp)
                tmp = persone[i].fine;

        current = tmp;

#ifdef DEBUG
        cout << sol << "\t" << current << "\t" << endl;
#endif // DEBUG
    }

    cout << sol;

    return 0;
}
