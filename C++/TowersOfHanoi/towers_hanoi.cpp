#include <iostream>
#include <vector>
using namespace std;
//bool candidate (vector<int> t1, vector<int> t2, vector<int> t3, int previous) {}

void print(vector<int> tower[3]) {
//Print Towers.
for(int i = 0; i < 3; i++) {
    cout << "\t" << tower[0][i];
    cout << "\t" << tower[1][i];
    cout << "\t" << tower[2][i];
    cout << endl;
}

cout << "       ---";
cout << "     ---";
cout << "     ---" << endl;

for (int i = 0; i < 3; i++) {
    cout << "\t" << "4";
}

cout << "\n     Tower " << "1";
cout << " Tower " << "2";
cout << "  Tower " << "3" << endl;
}

int main () {
//Creating vars and Initialization.
vector<int> tower[3]; //Creates 3 vectors that are stored in an array.
int current_candidate = 1;
int from_tower = 0; //From tower 1.
int to_tower = 1; //Prospectice tower we are considering to move value too.
int n = 3, move_count = 0;

for (int i = n + 1; i >= 1; --i) {
    tower[0].push_back(i);
}
    tower[1].push_back(n+1);
    tower[2].push_back(n+1);

while (tower[1].size() < n + 1) {
cout << "Move #: " << ++move_count << ": Transfer ring " << current_candidate << " from tower " << char(from_tower + 65) << " to tower " << char(to_tower+65) << endl;

/*Move the candidate ring from the "From tower" to the "to tower" (First copy it,
then delete it from the "from tower") */
tower[to_tower].push_back(current_candidate);
tower[from_tower].pop_back();

/*Determine the next candidate! We need to check the possible towers not including
the tower we just moved the ring too*/
if (tower[(to_tower + 1) % 3].back() < tower[(to_tower + 2) % 3].back()) {
    from_tower = (to_tower + 1) % 3;
} else {
    from_tower = (to_tower + 2) % 3;
}

current_candidate = tower[from_tower].back();

//Get the next to tower!
if (current_candidate < tower[(from_tower + 1) % 3].back()) {
    to_tower = (from_tower + 1) % 3;
} else {
    to_tower = (from_tower + 2) % 3;
}
}
//print(tower);

return 0;
}