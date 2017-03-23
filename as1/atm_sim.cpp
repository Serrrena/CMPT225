#include "ATM.h"
#include "Node.h"
#include "ATMQueue.h"
#include "Customer.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int getSimParameters(int &officetime, int &totalATM, int &totalcustomer, int *&atime_list, int *&ttime_list);
void displaySimResults(int wait, int C);
int CheckAllCustomer(ATM **atm,int totalATM);
int main () {
  // TO DO:: Rename these
  int officetime,totalATM,totalcustomer;
  int *atime_list, *ttime_list;

  // Total wait time for all customers in the simulation.
  int total_wait_time = 0;

  // Input code to read simulation parameters
  int param_err = getSimParameters(officetime, totalATM, totalcustomer, atime_list, ttime_list);
  if (param_err) {
    cerr << "Error in simulation parameters." << endl;
    return -1;
  }

  // TO DO:: Your simulation code goes here.
  int minute = 0, leftcustomer = totalcustomer,
      i,j,k,minpeople=0,minatmpos=0,
      customerbegin,customerend,customercount = 0;
  ATM *atm[totalATM] ; //= new ATM();
  Customer *a = new Customer();
  for (k = 0; k < totalATM;k++){  
    atm[k] = new ATM();  
  } 
  while (minute < officetime){
    // Process New Customer arriving at same time
    printf("Current Time is %d\n",minute);
    if (customercount < totalcustomer ){
      customerbegin = a->CustomerBegin(atime_list,minute,totalcustomer);
      cout<< "customer begin:" << customerbegin<<endl;
      customerend = a->CustomerEnd(atime_list,minute,totalcustomer);
      cout<< "customer end:" << customerend<<endl;
      
      for (i = customerbegin;i<=customerend;i++){
        minpeople = atm[0]->TotalCustomer();
        minatmpos = 0;
        for (j = 0;j < totalATM;j++){
          if (atm[j]->TotalCustomer() < minpeople){
            minpeople = atm[j]->TotalCustomer();
            minatmpos = j;
          }
        }
        atm[minatmpos]->ArrivalCustomer(ttime_list[i]);
        customercount++;
        printf("Customer %d go to ATM%d\n",i,minatmpos);
      }
    }
   
    // Insert customer to the ATM.
    for (i=0;i<totalATM;i++){
      atm[i]->ProcessNewCustomer();
        
    } 

    minute++;
    // Process customer.
    for (i=0;i<totalATM;i++){
      atm[i]->ProcessCurrentCustomer();
        
    } 

  
    
  }
    
  for (i=0;i<totalATM;i++){
      total_wait_time = total_wait_time + atm[i]->GetWaitTime();
        
    } 

  // Display statistics on the simulation.
  displaySimResults(total_wait_time, totalcustomer);
  // Return total_wait_time, will be used by test script.
  for (i=0;i<totalATM;i++){
    atm[i]->~ATM();
    
  }
  delete a;
  //delete atm
  //delete atmqueue
  return total_wait_time;
}




// Read the simulation parameters from standard input (cin).
// Parameters:
// M: minutes to run simulation
// N: number of ATMs
// C: number of customers
// atime_list: array of customer arrival times
// ttime_list: array of customer transaction times
//    customer i arrives at time atime_list[i] and performs a transaction that takes ttime_list[i] minutes
//
// All parameters are pass-by-reference (note & character).  This means assignments in this function will affect value from calling function
// 
// Return value:
// returns 0 if successful read of input
// non-zero values used to denote failure
//   1: simulation time < 1
//   2: number of ATMs < 1
//   3: number of customers < 1
//   4: a customer's transaction time < 1
//   5: customer list is not sorted by arrival time
//   6: customer arrival time later than simulation end time
int getSimParameters(int &officetime, int &totalATM, int &totalcustomer, int *&atime_list, int *&ttime_list) {
  // Code to read simulation parameters.
  cout << "Run an ATM simulation" << endl;

  cout << "Enter the number of minutes" << endl;
  cin >> officetime;
  // Check input validity.
  if (officetime < 1) {
    cerr << "Simulation for invalid length of time." << endl;
    return 1;
  }

  
  cout << "Enter the number of ATMs" << endl;
  cin >> totalATM;
  // Check input validity.
  if (totalATM < 1) {
    cerr << "Simulation for invalid number of ATMs." << endl;
    return 2;
  }


  // Read customer list
  cout << "Enter the number of customers" << endl;
  cin >> totalcustomer;
  if (totalcustomer < 1) {
    cerr << "Simulation for invalid number of customers." << endl;
    return 3;
  }
  // Allocate memory for customer list.
  atime_list = new int [totalcustomer];
  ttime_list = new int [totalcustomer];

  // Read C customers
  int atime = -1;
  int prevatime = -1;
  int ttime = 0;
  for (int i=0; i<totalcustomer; i++) {
    cout << "Enter customer arrival and transaction time." << endl;
    cin >> atime;
    cin >> ttime;

    // Check input validity.
    if (ttime < 1) {
      cerr << "Invalid transaction time." << endl;
      return 4;
    }
    if (atime < prevatime) {
      cerr << "Arrival times not sorted." << endl;
      return 5;
    }
    if (atime >= officetime) {
      cerr << "Arrival time later than simulation end time." << endl;
      return 6;
    }
    prevatime = atime;

    atime_list[i] = atime;
    ttime_list[i] = ttime;
  }

  // All went well, return 0.
  return 0;
}


// Display statistics on the simulation.
// wait: Total wait time of all customers in simulation.
// C: total number of customers in simulation.
void displaySimResults(int wait, int totalcustomer) {
  cout << "Simulation results" << endl;
  cout << "Number of customers: " << totalcustomer << endl;
  cout << "Total wait time: " << wait << endl;
  cout << "Average wait time: " << ((double) wait)/((double) totalcustomer) << endl;
}

int CheckAllCustomer(ATM **atm,int totalATM){
  int total = 0;
  for(int i=0;i<totalATM;i++){
    total = total + atm[i]->TotalCustomer();
  }
  return total;
}

