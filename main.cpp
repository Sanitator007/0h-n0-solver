#include <iostream>

#include <Table.h>
#include <BlueCell.h>
#include <BlueCell_list.h>

using namespace std;

/*
Ready solver for 0h n0 at http://0hn0.com/
Cool puzzle
*/

int main()
{
    Table T;
    T.get_table();

    BlueCell_list L;
    L.make_list(T);

    for(int step = 0; step < T.n * T.n; ++step)
        for(size_t i = 0; i < L.v.size(); ++i)
        {
            L.v[i].fill_intersection_of_placements(T, L);
            L.v[i].block_exc_bridges(T, L);
        }

    for(size_t i = 1; i <= T.n; ++i)
        for(size_t j = 1; j <= T.n; ++j)
            if(T.t[i][j] == 0)
                T.t[i][j] = -2;

    T.show_table();
}

/*
5
3 e e e 1
e e 3 e r
e e e 2 e
e 2 e e r
e 5 5 4 e
*/
