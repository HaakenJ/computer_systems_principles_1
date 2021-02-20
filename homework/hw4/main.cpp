#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void sortScores(string* names, int* scores, const int size) {
    int i, key, j;
    string nameKey;
    for (i = 1; i < size; i++) {
        key     = scores[i];
        nameKey = names[i];
        j = i - 1;

        while (j >= 0 && scores[j] > key) {
            scores[j + 1] = scores[j];
            names[j + 1]  = names[j];
            j = j - 1;
        }

        scores[j + 1] = key;
        names[j + 1]  = nameKey;
    }
}

double calculateAvg(const int* scores, const int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / size;
}

void displayNamesScores(const string* names, const int* scores, const int size) {
    int width = 20;
    cout << "Name" << setw(width - 1) << "Score" << endl;
    for (int i = 0; i < size; i++) {
        int pad = width - names[i].size();
        cout << left << names[i] << right << setw(pad) << scores[i] << endl;
    }
}

int main() {
    int numTests;
    cout << "How many tests will you enter? ";
    cin.clear();
    cin >> numTests;

    auto* scores = new int[numTests];
    auto* names  = new string[numTests];

    for (int i = 0; i < numTests; i++) {
        string name;
        int score;

        cout << "Enter student " << i + 1 << "'s name: ";
        cin >> name;
        cin.clear();
        names[i] = name;


        cout << "Enter that student’s test score: ";
        cin >> score;
        while (!isdigit(score) || score < 0 || score > 100) {
            score = 0;
            cout << "Please enter a valid integer score between 0 and 100." << endl;
            cout << "Enter that student’s test score: ";
            cin >> score;
        }

        cin.clear();
        scores[i] = score;

        cout << endl;
    }

//    names[0] = "King";
//    names[1] = "Lewis";
//    names[2] = "Goss";
//    names[3] = "Green";
//    names[4] = "Clinton";
//
//    scores[0] = 100;
//    scores[1] = 90;
//    scores[2] = 98;
//    scores[3] = 95;
//    scores[4] = 96;

    sortScores(names, scores, numTests);

    cout << "The test scores in ascending order, and their average, are:";
    cout << endl << endl;

    displayNamesScores(names, scores, numTests);

    cout << endl;

    double avg = calculateAvg(scores, numTests);

    cout << "Average score:    " << setprecision(2) << fixed << avg << endl;

    return 0;
}
