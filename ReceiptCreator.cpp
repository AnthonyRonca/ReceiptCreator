/*
Anthony Ronca
CIT 133
Due Oct. 18th
2 hours over one day

    This program takes an input stream and displays it in an output file.

    VARIABLES USED:

    fileName          -   user input for inFile name
    outName           -   user input for outFile name
    done              -   bool value which changes once there's no more data to read
    description       -   item description
    quantity          -   amount of item
    price             -   price per item
    totalPrice        -   calculated sum of a specific item
    subTotal          -   sum of entire order
    tax               -   tax calculated with subtotal (8%)
    count             -   amount of times loop reiterates
    total             -   overall total w/ tax and subtotal

*/


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {

    //
    string fileName;        //  input file
    string outName;         //  output file
    bool done = false;      // test bool when file has been read
    string description;     // item description
    int quantity = 0;       // item quantity
    double price = 0;       // price per item
    double totalPrice = 0;  // sum of items * quantity
    double subTotal = 0;    // overall order total
    double tax;             // calculated tax from order @ 8%
    int count = 0;          // count loop iterations
    double total;           // overall total + tax

    // GET fileName
    cout << "Enter the name of the input file: " ;
    cin >> fileName;
    // input stream
    ifstream inFile ( fileName.c_str() );

    // validate file exists
    if (!inFile){

        cout << " ERROR - " << fileName << " does not exist. ";

    } else {

        // GET outName
        cout << "Enter the name of the output file: " ;
        cin >> outName;
        // create output stream
        ofstream outFile ( outName.c_str() );
        // format and display data in output file
        outFile << fixed << left << setw(25);
        outFile << "Item " << setw(10) << "Price" << "\n";
        outFile << "------------------------------------";
        outFile << setprecision(2);
        outFile << "\n";

        // pre-test loop to validate all data is read
        while (!done) {

            // SET subTotal
            subTotal = subTotal + totalPrice;

            // increment count for each item to output later
            count++;

            // format & display input data from inFile and display in outFile
            inFile >> description >> quantity >> price;
            outFile << fixed << left;
            outFile << description << " -- ";
            outFile << quantity << " @ " ;
            outFile << price << ":" << "\t";
            // calculate totalPrice in this scope to display in outFile
            totalPrice = (price * quantity);
            outFile << "$" << setprecision(2) << totalPrice;
            outFile << "\n";
            // when file is completely read, test bool "done" becomes true, thus
            //exiting loop

            if (inFile.eof()){
                done = true;
            } // end if
        } // end while

        // calculate tax
        tax = 0.08 * subTotal;
        // calculate total
        total = tax + subTotal;

        // display formatted output to outFile
        outFile << "------------------------------------" << "\n";
        outFile << fixed << left << setw(24);
        outFile <<"Subtotal:" << "$" << subTotal << "\n";
        outFile << fixed << left <<
                setw(24) <<"Tax:" <<  "$" << tax << "\n";
        outFile << "------------------------------------";
        outFile << "\n";

        // display formatted output to OutFile
        outFile << fixed << left << setw(24);
        outFile <<"Total:" << "$" << total << "\n";
        outFile << "Number of items: " << count;

    }// end Main



    return 0;
}