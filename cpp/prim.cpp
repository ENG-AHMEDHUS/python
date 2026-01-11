#include <iostream>

using namespace std;

#define dim 7

#define inf 99

int weight[dim][dim] =

{ { 0, 3, inf, inf, inf, inf, 5 },

{ 3, 0, 2, inf, inf, inf, 5 },

{ inf, 2, 0, 7, 1, 1, 3 },

{ inf, inf, 7, 0, 6, 7, inf },

{ inf, inf, 1, 6, 0, 4, inf },

{ inf, inf, 1, 7, 4, 0, 8 },

{ 5, 5, 3, inf, inf, 8, 0 } };


void print_matrix(int array[dim][dim])

{

    int r, c;

    for (c = 0; c < dim; c++) cout << "\t" << c;

    cout << "\n";

    for (r = 0; r < dim; r++)

    {

        cout << "\n" << r << "\t";

        for (c = 0; c < dim; c++)

            if (array[r][c] == inf) cout << "#\t";

            else cout << array[r][c] << "\t";

    }

    cout << "\n";

}


int main(void)

{

    int z[dim][3], r, c, min, rmin, cmin, min_span[dim][dim];

    int total_weight = 0;

    print_matrix(weight);


    for (r = 0; r < dim; r++){

        for (c = 0; c < dim; c++){

            if (r == c) min_span[r][c] = 0;

            else min_span[r][c] = inf;

        }
    }

    for (r = 0; r < dim; r++)

    {

        z[r][0] = -1;
        z[r][1] = inf;
        z[r][2] = 0;

    }


    rmin = 0; //any node

    z[rmin][0] = rmin;
    z[rmin][1] = 0;
    z[rmin][2] = 1;


    do {

        for (r = 0; r < dim; r++){

            if ((z[r][2] == 0) && (z[r][1] > weight[rmin][r]))
        
                {
        
                    z[r][0] = rmin;
                    z[r][1] = weight[rmin][r];
        
                }
        
        }

        min = inf;
        cmin = -1;

        for (r = 0; r < dim; r++){

            if ((z[r][2] == 0) && (z[r][1] < min)){

                min = z[r][1];
                rmin = z[r][0];
                cmin = r;

            }

        }

        if (min == inf) break;

        min_span[rmin][cmin] = min_span[cmin][rmin] = min;

        total_weight+= min;

        rmin = cmin;

        z[rmin][2] = 1;

    } while (rmin != -1);

    cout << "\nMinimum Total Weight = " << total_weight << "\n";

    print_matrix(min_span);




}