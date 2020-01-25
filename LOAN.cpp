#include <iostream>

using namespace std;

double initial_debt;
double annual_interest;
int goal_period;

double PossibleToRepayIfMonthlyRepaymentIs(double monthly_repayment) {
    double current_debt = initial_debt;
    for (int i = 0; i < goal_period; i++) {
        current_debt = current_debt * (1.0 + annual_interest / 12.0 / 100.0) - monthly_repayment;
    }
    return current_debt;
}

double FindMinimumMonthlyRepayment() {
    double lo = 0.0;
    double hi = initial_debt * (1.0 + annual_interest / 12.0 / 100.0);
    
    for (int i = 0; i < 1000; i++) {
        double mid = (lo + hi) / 2.0;
        if (PossibleToRepayIfMonthlyRepaymentIs(mid) <= 0) {
            hi = mid;
        }
        else {
            lo = mid;
        }
        
    }
    
    return hi;
}

int main()
{
    cout.precision(10);
    cout << fixed;
    
    int num_testcase;
    cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++) {
        cin >> initial_debt;
        cin >> goal_period;
        cin >> annual_interest;
        cout<<FindMinimumMonthlyRepayment() << endl;
    }
    

    return 0;
}
