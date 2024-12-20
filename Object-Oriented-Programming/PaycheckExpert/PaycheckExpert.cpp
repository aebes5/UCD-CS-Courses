#include <iostream>
#include <iomanip> //library used to set the precision of decimal places

using namespace std;

int main() //main function(only function used)
{
    float wage; //asks user for hourly wage and stores in wage variable
    cout << "Enter hourly rate: ";
    cin >> wage;

    int hours; //asks user for hours worked and stores in hours variable
    cout << "Enter the number of hours worked this week: ";
    cin >> hours;

    double retirement; //asks user for retirement deduction for week and stores in variable
    cout << "Enter the retirement deduction for this week: ";
    cin >> retirement;

    int OverTimeHours; //create a variable OverTimeHours, uses 'if' statement to determine # 
    if (hours > 40)    //of overtime hours, if overtime hours set hours 40 so normal pay  
    {                  //calculates 40 hours pay
        OverTimeHours = hours - 40;
        hours = 40;
    }

    double OverTimePay; //calculates overtime pay assuming time and a half and stores in variable
    OverTimePay = OverTimeHours * 1.5 * wage;

    double NormalPay;//calculates amount made excluding overtime and stores in variable
    NormalPay = hours * wage;

    double GrossPay; //adds normal and overtime pay to find total pay stored in GrossPay variable
    GrossPay = OverTimePay + NormalPay;

    const double Social_Security_decimal = 0.062;
    double SocialSecurity; //calculates Social Security tax and stores in variable(6.2% of Gross)
    SocialSecurity = GrossPay * Social_Security_decimal;

    const double Medicare_decimal = 0.0145;
    double Medicare; //calculates medicare tax and stores in Medicare variable(1.45% of Gross)
    Medicare = GrossPay * Medicare_decimal; 

    double Annual; //calculates annual pay based on gross income for 1 week
    Annual = GrossPay * 52;

    double Federal; //determines tax bracket based on Annual income, determines Federal tax
    if (Annual < 9876)
    {
        Federal = GrossPay * 0.1;
    }
    if (Annual < 54126)
    {
        Federal = (987 + (Annual - 9875) * 0.12) / 52;
    }
    if (Annual > 54125)
    {
        Federal = (6297 + (Annual - 54125) * 0.22) / 52;
    }

    double Colorado; //calculates Colorado tax and stores in Colorado variable(4.55% of Gross)
    Colorado = GrossPay * 0.0455;

    double Deduction; //calculates tax&retirement deducted from Gross and stores in variable
    Deduction = SocialSecurity + Medicare + Federal + Colorado + retirement;

    double Net; //subtracts deduction from Gross to determine net pay and stores in variable
    Net = GrossPay - Deduction;

    cout << " " << endl
    << fixed << setprecision(2) //sets precision of all numbers printed to 2 decimals
    << "This week wage details: " << endl
    << "========================" << endl
    << "Gross pay: $" << GrossPay << "   (Overtime pay: $" << OverTimePay << ")" << endl
    << " " << endl
    << "Taxes and deductions: " << endl
    << "========================" << endl
    << "Social security withdrawal: $" << SocialSecurity << endl
    << "Medicare withdrawal: $" << Medicare << endl
    << "Federal tax: $" << Federal << endl
    << "Colorado state tax: $" << Colorado << endl
    << "Retirement contribution: $" << retirement << endl
    << " " << endl
    << "---------------------------------" << endl
    << "Deduction total: $" << Deduction << endl
    << "---------------------------------" << endl
    << "Net pay: $" << Net << endl;
}
