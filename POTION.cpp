
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int num_recipe;
int amount_recipe[201], amount_put[201], amount_more[201];
int gcd(int p, int q) {
    if (q == 0) {
        return p;
    }
    return gcd(q, p % q);
}
void calculateLeft() {
    double maximum_ratio = 0.0;
    int maximum_ratio_denom = 0;
    int maximum_ratio_numer = 0;
    int gcd_recipe = amount_recipe[0];
    for (int i = 0; i < num_recipe; i++) {
        gcd_recipe = gcd(amount_recipe[i], gcd_recipe); // calculate gcd for all amount_recipe
        if (maximum_ratio < (double)amount_put[i] / amount_recipe[i]) {// calculate maximum ratio 
            maximum_ratio = (double)amount_put[i] / amount_recipe[i];
            maximum_ratio_denom = amount_put[i];
            maximum_ratio_numer = amount_recipe[i];
        }
    }
    int denom = ceil(gcd_recipe * maximum_ratio_denom / (double)maximum_ratio_numer);
    
    for (int i =0; i < num_recipe; i++) {
        amount_more[i] = amount_put[i] * denom / gcd_recipe - amount_put[i];
    }
    
}

int main()
{
    int num_testcase;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> num_recipe;
        for (int j = 0; j < num_recipe; j++) {
            cin >> amount_recipe[j];
        }
        for (int j = 0; j < num_recipe; j++) {
            cin >> amount_put[j];
        }
        calculateLeft();
        for (int j = 0; j < num_recipe; j++) {
            cout << amount_more[j] << " ";
        }
        cout << endl;
        
    }
    

    return 0;
}
