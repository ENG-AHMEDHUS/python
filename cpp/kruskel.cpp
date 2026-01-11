#include <iostream>

using namespace std;

#define dim 7

#define inf 99

int weight[dim][dim] =

{ { 0, 3, inf, inf, inf, inf, 2 },

{ 3, 0, 2, inf, inf, inf, 5 },

{ inf, 2, 0, 7, 1, 1, 3 },

{ inf, inf, 7, 0, 6, 7, inf },

{ inf, inf, 1, 6, 0, 4, inf },

{ inf, inf, 1, 7, 4, 0, 8 },

{ 2, 5, 3, inf, inf, 8, 0 } };


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

    int z[dim], min_span[dim][dim];

    int min, rmin, cmin, r, c, i, temp, total_weight, group;


    print_matrix(weight);


    for (r = 0; r < dim; r++)

        for (c = 0; c < dim; c++)

            if (r == c) min_span[r][c] = 0;

            else min_span[r][c] = inf;


    group = 0,total_weight = 0;

    for (r = 0; r < dim; r++) z[r] = -1;


    while (1)

    {

        min = inf;

        for (r = 0; r < dim; r++)

            for (c = 0; c < r; c++)

                if (min > weight[r][c])

        {

            rmin = r;
            cmin = c;
            min = weight[r][c];

        }


        if (min == inf)

        {

            cout << "\n\n Minimum Total Weight =" << total_weight << endl << endl;

            print_matrix(min_span);



            return 0;

        }


        if ((z[rmin] != z[cmin]) || (z[rmin] == -1) || (z[cmin] == -1))

        {

            min_span[rmin][cmin] = min_span[cmin][rmin] = min;


            total_weight += min;

            if ((z[rmin] == -1) && (z[cmin] == -1))

            {

                group++;
                z[rmin] = z[cmin] = group;

            }

            else if ((z[rmin] == -1) && (z[cmin] != -1))

                z[rmin] = z[cmin];

            else if ((z[cmin] == -1) && (z[rmin] != -1))

                z[cmin] = z[rmin];

            else //z[rmin] != -1 && z[cmin] != -1 && z[rmin] != z[cmin]

            {

                temp = z[cmin];

                for (i = 0; i < dim; i++)

                    if (z[i] == temp) z[i] = z[rmin];

            }

        }

        weight[rmin][cmin] = inf;

    }



}