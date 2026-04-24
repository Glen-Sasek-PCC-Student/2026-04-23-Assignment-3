// ------------- FILE HEADER -------------
// Author ✅: Glen Sasek
// Assignment ✅:3
// Date ✅:2026-04-23
// Citations:

// ------------- DESIGN DOCUMENT -------------
// A. INPUT ✅:
// B. OUTPUT ✅:
// C. CALCULATIONS ✅:
// D. LOGIC and ALGORITHMS ✅:
//    (Optional) flow chart link or file name:

// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS ✅:
// (Optional) Additional tests count:

// ------------- CODE -------------
#include <iostream>
#include <iomanip> // for setprecision
#include <cctype> // for tolower

using namespace std;

// Function prototypes (if any)

// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main(int argc, char *argv[])
{
  cout << "Welcome to the Washington State Ferries Fare Calculator!" << endl
       << endl;

  cout << "Fare Description                                           Ticket $" << endl;
  cout << "--------------------------------------                     --------" << endl;
  cout << "Vehicle Under 14' (less than 168\") & Driver                  $57.90" << endl;
  cout << "Adult (age 19 - 64)                                          $14.95" << endl;
  cout << "Senior (age 65 & over) / Disability                           $7.40" << endl;
  cout << "Youth (age 6 - 18)                                            $5.55" << endl;
  cout << "Bicycle Surcharge (included with Vehicle)                     $4.00" << endl;

  char y_or_n = '\0';
  cout << "Are you riding a vehicle on the Ferry (Y/N): ";
  cin >> y_or_n;
  y_or_n = tolower(y_or_n);

  switch(y_or_n) {
    case 'y': // Fallthrough
    case 'n':
      break;
    default:
      cout << "Error:( Invalid answer;( Please try again later" << endl;
      return 1;
  }

  int adults = 0;
  cout << "How many adults: ";
  cin >> adults;

  int seniors = 0;
  cout << "How many seniors? ";
  cin >> seniors;

  int youths = 0;
  cout << "How many youths? ";
  cin >> youths;

  bool vehicle = y_or_n == 'y';

  int bicycles = 0;
  if (!vehicle)
  {
    cout << "How many bicycles? ";
    cin >> bicycles;
  }

  // calc charge
  const float VEHICLE_USD = 57.9;
  const float ADULT_USD = 14.95;
  const float SENIOR_USD = 7.40;
  const float YOUTH_USD = 5.55;
  const float BICYCLE_USD = 4.00;

  const int MAX_SUM_ADULT_SENIOR_YOUTH = 20;

  const float EARN_FREE_TICKET_USD = 100.0;

  float charge = 0.0;
  if (vehicle)
  {
    charge += VEHICLE_USD; // charge = charge + 57.90
  }

  charge += (adults * ADULT_USD);
  charge += (seniors * SENIOR_USD);
  charge += (youths * YOUTH_USD);
  charge += (bicycles * BICYCLE_USD);

  cout << fixed << setprecision(2);

  if ((adults + seniors + youths) > MAX_SUM_ADULT_SENIOR_YOUTH)
  {
    cout << "Uh oh!! Too many people in your group. Split into 2 groups and try again!" << endl;
  }
  else
  {
    cout << "Your total charge is " << charge << endl;
    if (charge > EARN_FREE_TICKET_USD)
    {
      cout << "You earn 1 free adult ticket for your next trip." << endl;
    }
    else
    {
      float usd_to_free_ticket = EARN_FREE_TICKET_USD - charge;
      cout << "If you spend $" << usd_to_free_ticket << "more, you earn a free adult ticket for the next trip." << endl;
    }
  }

  cout << endl;
  cout << "Thank you for using Washington State Ferries Fare Calculator!" << endl;

  return 0;
}

// Function implementations (if any)

// ------------- DESIGN -------------
/*
Program Name:

Program Description:

Design:
A. INPUT
Define the input variables including name data type.

B. OUTPUT
Define the output variables including data types.

C. CALCULATIONS
Describe calculations used by algorithms in step D.
List all formulas.
If there are no calculations needed, state there are no calculations.

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts.
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs.
https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/Pseudocode-Reference.txt


SAMPLE RUNS
Welcome to the Washington State Ferries Fare Calculator!
Fare Description                                           Ticket $
--------------------------------------                     --------
Vehicle Under 14' (less than 168") & Driver                  $57.90
Adult (age 19 - 64)                                          $14.95
Senior (age 65 & over) / Disability                           $7.40
Youth (age 6 - 18)                                            $5.55
Bicycle Surcharge (included with Vehicle)                     $4.00
Are you riding a vehicle on the Ferry (Y/N): y
How many adults? 2
How many seniors? 1
How many youths? 0
Your total charge is $95.20
If you spend $4.80 more, you are eligible for a free adult ticket
for the next trip.
Thank you for using Washington State Ferries Fare Calculator!



Welcome to the Washington State Ferries Fare Calculator!

Fare Description                                           Ticket $
--------------------------------------                     --------
Vehicle Under 14' (less than 168") & Driver                  $57.90
Adult (age 19 - 64)                                          $14.95
Senior (age 65 & over) / Disability                           $7.40
Youth (age 6 - 18)                                            $5.55
Bicycle Surcharge (included with Vehicle)                     $4.00
Are you riding a vehicle on the Ferry (Y/N): a
Error!! Invalid answer!! Please try again later!!!
Thank you for using Washington State Ferries Fare Calculator!



Welcome to the Washington State Ferries Fare Calculator!

Fare Description                                           Ticket $
--------------------------------------                     --------
Vehicle Under 14' (less than 168") & Driver                  $57.90
Adult (age 19 - 64)                                          $14.95
Senior (age 65 & over) / Disability                           $7.40
Youth (age 6 - 18)                                            $5.55
Bicycle Surcharge (included with Vehicle)                     $4.00
Are you riding a vehicle on the Ferry (Y/N): n
How many adults? -7
Error!! Invalid answer!! Please try again later!!!
Thank you for using Washington State Ferries Fare Calculator!




Welcome to the Washington State Ferries Fare Calculator!

Fare Description                                           Ticket $
--------------------------------------                     --------
Vehicle Under 14' (less than 168") & Driver                  $57.90
Adult (age 19 - 64)                                          $14.95
Senior (age 65 & over) / Disability                           $7.40
Youth (age 6 - 18)                                            $5.55
Bicycle Surcharge (included with Vehicle)                     $4.00
Are you riding a vehicle on the Ferry (Y/N): n
How many adults? 12
How many seniors? 4
How many youths? 5
How many bikes? 2
Uh oh!! Too many people in your group. Split into 2 groups and try
again!
Thank you for using Washington State Ferries Fare Calculator!



*/
