//If I wanted to do more optimizations, I should instead use <vector>. This implementation, however, will work up until n=100000. 

#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;

struct item {
    int item_num = -1;
    int weight;
    int val;
};

//--FUNCTION OVERLOADS--//
item* populate_array_from_file(ifstream&);
int find_best(item*);
int*  sub_vector(int* , int, int);
void write_out_from_array(item* );

int main() {
    remove("knapsack.out"); //We don't duplicate results
    ifstream data;
    data.open("data.txt");
    if(!data) { //checks if file exists
        cout << "Error! File could not be opened" << endl;
        return 0;
    }

    //Due to the location of the cursor, we should be on the new line. After, we write to a new line on the out file
    while(data.peek() != EOF) {
        item* new_data = populate_array_from_file(data);
        int size = 0;

        int temp = find_best(new_data);
        write_out_from_array(new_data);
        free(new_data);
    }
    data.close();
}

/*
This function will:
-Read from the data.txt file.
-Format it into an integer array.
-Return the formatted array.
*/
item* populate_array_from_file(ifstream& data) {
    cout << "Reading from data.txt, formatting data..." << endl;
    item* items = new item[100]; 
    int increment = 0; //used to increment array
    int subincrement = 0;
    string new_number; //used to store numbers while we read from file
    char new_char;

    //We are under the assumption here that the file will not give non-numbers or spaces.
    //std::noskipws makes it so reading the file doesn't ignore ' ' or '\n'
    
    while(data >> std::noskipws >> new_char) { //Check character, and add to array for future sorting. 
        if(new_char != ' ' && new_char != '\n') {
            new_number += new_char;
            continue;
        }

        else if(new_char == ' ' || new_char == '\n') {
            if (subincrement == 0) { //we are on the weight 
                items[increment].weight = stoi(new_number);
                cout << items[increment].weight << " ";
                subincrement = 1;
                new_number = "";
                continue;
            }
            else if (subincrement == 1) {//we are on the money
                items[increment].val = stoi(new_number);
                items[increment].item_num = increment;
                cout << items[increment].val << endl;
                increment++;
                subincrement = 0;
                new_number = "";
                continue;
            }
        }
    }
    cout << "Data format successful" << endl;
    return items;
}

int find_best(item* items) { //right is index of. 
    int** best = new int*[100];
    for (int i = 0; i < 100; i++) {
        best[i] = new int[100];
    }

    int W = 6; //new weight
    int n = 5; //amount of items

    for(int i = 0; i < W; i++) {
        best[0][i] = 0;
    }
    cout << "a" << endl;
    for(int i = 0; i < n; i++) {
        best[i][0] = 0;
        for(int w = 0; w < W; w++) { 
            if (items[i].weight <= w) {
                if (items[i].val)
            }
        }
    }
    cout << best[n][n] << endl;
}

void write_out_from_array(item* items) {
    ofstream insert ("knapsack.out", ios_base::app);
    int iterator = 0;
    while(items[iterator].item_num != -1) {
        insert << items[iterator].weight << " " << items[iterator].val << endl;
        ++iterator;
    }
    insert << endl;
    return;
}