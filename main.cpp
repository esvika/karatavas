#include <iostream> // Lai strādātu ar ievadi un izvadi
#include <vector> // Lai saglabātu iespējamos vārdus sarakstā
#include <string> // Strādāšanai ar tekstiem
#include <cstdlib> // Priekš random funkcijas
#include <ctime> // Lai ģenerētu atšķirīgus nejaušus skaitļus
#include <algorithm> // Lai iegūtu funkcijas, piemeram, all_of()

using namespace std;

void displayGameIntro() { // Spēles intro
    cout << "Laipni lūgts karatavas!" << endl;
    cout << "Šajā spēlē tev ir jāuzmin slepenais vārds (angliski)!" << endl;
    cout << "Ar katru nepareizu minējumu, tu zaudē dzīvību." << endl;
    cout << "Veiksmi!" << endl;
    cout << endl;
}

string getRandomWord() {// Funkcija nejausi izvelas vardu
    vector<string> randomVards = {"Function", "Programs", "Blueberry", "Windows", "Computer", "Happiness", "Rainbows", "Attention", "Starlight", "Refrigerator", "Conditioner"};
    srand(time(0));
    int randomNum = rand() % randomVards.size();
    return randomVards[randomNum];
}

void displayWord(const string &word, const vector<bool> &guessed) { // Funkcija aizvieto burtus ar _
    for (size_t i = 0; i < word.size(); i++) {
        if (guessed[i])
            cout << word[i] << " ";
        else
            cout << "_ ";
    }
    cout << endl;
}

char getGuess() { // Lietotājs ievada minējumu
    char guess;
    cout << "Ievadi burtu: ";
    cin >> guess;
    return tolower(guess);
}

int chooseDifficulty() { // Izvelas grutibas limeni
    int level;
    cout << "Izvelies grutibas limeni: (1) Viegls, (2) Videjs, (3) Gruts" << endl;
    cout << "Ievadi 1, 2 vai 3: ";
    cin >> level;
    return level;
}

int getAttemptsForDifficulty(int level) {
    switch (level) {
        case 1: return 12;
        case 2: return 8;
        case 3: return 6;
        default: return 6;
    }
