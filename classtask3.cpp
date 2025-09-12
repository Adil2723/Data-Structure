#include <iostream>
using namespace std;

int main() {
    int numTeams;

    cout << "Enter the number of teams: ";
    cin >> numTeams;

    int** teams = new int*[numTeams];
    int* teamSizes = new int[numTeams];

    for (int i = 0; i < numTeams; ++i) {
        cout << "Enter number of players in team " << i + 1 << ": ";
        cin >> teamSizes[i];

        teams[i] = new int[teamSizes[i]];

        cout << "Enter scores for team " << i + 1 << ": ";
        for (int j = 0; j < teamSizes[i]; ++j) {
            cin >> teams[i][j];
        }
    }

    cout << "\nSum of scores for each team:\n";
    for (int i = 0; i < numTeams; ++i) {
        int sum = 0;
        for (int j = 0; j < teamSizes[i]; ++j) {
            sum += teams[i][j];
        }
        cout << "Team " << i + 1 << ": " << sum << endl;
    }

    for (int i = 0; i < numTeams; ++i) {
        delete[] teams[i];
    }
    delete[] teams;
    delete[] teamSizes;

    return 0;
}
