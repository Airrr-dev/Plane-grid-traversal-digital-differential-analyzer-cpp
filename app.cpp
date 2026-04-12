#include <bits/stdc++.h>
#include "functions.h"
#include "objects.h"
using std::cin;
using std::cout;
using std::floor;
using std::min;
using std::max;
using std::numeric_limits;
using ll = long long;
using ld = long double;

int main()
{
    ll w, h;
    ld Ox, Oy, Px, Py;
    cin >> w >> h >> Ox >> Oy >> Px >> Py;
    if(w < 0 || h < 0 ||
        Ox < 0 || Ox >= w ||
        Oy < 0 || Oy >= h ||
        Px < 0 || Px >= w ||
        Py < 0 || Py >= h ||
        (Ox == Px && Oy == Py))
    {
        cout << "Invalid params\n";
        return 0;
    }
    char plane[h][w + 1];
    for(ll i {0}; i < h; i++)
    {
        for(ll j {0}; j < w; j++)
        {
            plane[i][j] = '@';
        }
    }
    for(ll i {0}; i < h; i++)
        plane[i][w] = '\0';
    ll rx {static_cast<ll>(Ox)}, ry {static_cast<ll>(Oy)};
    ld dx {Px - Ox}, dy {Py - Oy}, ddx {dx != 0 ? (1 / abs(dx)) : numeric_limits<ld>::infinity()}, ddy {dy != 0 ? (1 / abs(dy)) : numeric_limits<ld>::infinity()}, dmaxx {dx != 0 ? (((dx > 0 ? floor(Ox) + 1 : floor(Ox)) - Ox) / dx) : numeric_limits<ld>::infinity()}, dmaxy {dy != 0 ? (((dy > 0 ? floor(Oy) + 1 : floor(Oy)) - Oy) / dy) : numeric_limits<ld>::infinity()};
    while(rx > -1 && rx < w && ry > -1 && ry < h)
    {
        if(dmaxx < dmaxy)
        {
            rx += sign(dx);
            dmaxx += ddx;
        }
        else
        {
            if(abs(dmaxx - dmaxy) < eps)
            {
                rx += sign(dx);
                dmaxx += ddx;
                ry += sign(dy);
                dmaxy += ddy;
            }
            else
            {
                ry += sign(dy);
                dmaxy += ddy;
            }
        }
        plane[ry][rx] = 'W';
    }
    for(ll i {0}; i < h; i++)
    {
        for(ll j {0}; j < w; j++)
        {
            if(i == static_cast<ll>(Oy) && j == static_cast<ll>(Ox)) plane[i][j] = 'O';
            else if(i == static_cast<ll>(Py) && j == static_cast<ll>(Px)) plane[i][j] = 'P';
        }
    }
    for(ll i {0}; i < h; i++)
    {
        for(ll j {0}; j < w; j++)
        {
            cout << plane[i][j];
        }
        cout << '\n';
    }
}