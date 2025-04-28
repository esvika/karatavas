#include <iostream> // Lai str�d�tu ar ievadi un izvadi
#include <vector> // Lai saglab�tu iesp�jamos v�rdus sarakst�
#include <string> // Str�d��anai ar tekstiem
#include <cstdlib> // Priek� random funkcijas
#include <ctime> // Lai �ener�tu at��ir�gus nejau�us skait�us
#include <algorithm> // Lai iegutu funkcijas, piemeram, all_of()

using namespace std;

void displayGameIntro() { // Sp�les "intro" sekcija, izskaidroti sp�les noteikumi, kalopjas k� s�kuma ekr�ns.

cout << "Laipni lugts karatavas!" << endl;
cout << "Saja spele tev ir jauzmin slepenais vards (angliski)!" << endl;
cout << "Ar katru nepareizu minejumu, tu zaude dzivibu." << endl;
cout << "Veiksmi!" << endl;
cout << endl;

}

void vardi() { // Funkcija, kas izv�las nejausi v�rdu no datu mas�va
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
