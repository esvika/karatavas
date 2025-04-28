#include <iostream> // Lai strâdâtu ar ievadi un izvadi
#include <vector> // Lai saglabâtu iespçjamos vârdus sarakstâ
#include <string> // Strâdâðanai ar tekstiem
#include <cstdlib> // Priekð random funkcijas
#include <ctime> // Lai ìenerçtu atðíirîgus nejauðus skaitïus
#include <algorithm> // Lai iegutu funkcijas, piemeram, all_of()

using namespace std;

void displayGameIntro() { // Spçles "intro" sekcija, izskaidroti spçles noteikumi, kalopjas kâ sâkuma ekrâns.

cout << "Laipni lugts karatavas!" << endl;
cout << "Saja spele tev ir jauzmin slepenais vards (angliski)!" << endl;
cout << "Ar katru nepareizu minejumu, tu zaude dzivibu." << endl;
cout << "Veiksmi!" << endl;
cout << endl;

}

void vardi() { // Funkcija, kas izvçlas nejausi vârdu no datu masîva
string randomVards[11]={"Function","Programs","Blueberry","Windows","Computer","Happiness","Rainbows","Attention","Starlight","Refrigerator","Conditioner"};
srand(time(0));
int randomNum = rand() % 12;
cout << randomVards[randomNum];

}

// Function to choose a random word from the list
string getRandomWord(const vector<string>& words) {
    return words[rand() % words.size()];
}


void displayWord(const string& word, const vector<bool>& guessed) {
    for (size_t i = 0; i < word.size(); i++) {
        if (guessed[i])
            cout << word[i] << " ";
        else
            cout << "_ ";
    }
    cout << endl;
}

int main() {

vardi();

}
