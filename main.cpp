#include <iostream> // Lai straadatu ar ievadi un izvadi
#include <vector> // Lai saglabaatu iespeejamos vaardus sarakstaa
#include <string> // Stradashanai ar tekstiem
#include <cstdlib> // Prieks random funkcijas
#include <ctime> // Lai genereetu atskirigus nejausus skaitlus
#include <algorithm> // Lai iegutu funkciju all_of()

using namespace std;



// Parada sveicienu un noteikumus
void speleIntro() {
    cout << "Laipni lugts karatavas!" << endl;
    cout << "Spele jaatmin slepens vards anglu valodaa!!" << endl;
    cout << "Par katru nepareizu minejumu tiek zaudeta dziviba." << endl << endl;
}



// Atgriez vienu nejausi izveletu vardu no saraksta
string randomVaards() {
    vector<string> saraksts = {
        "Function", "Programs", "Blueberry", "Windows", "Computer",
        "Happiness", "Rainbows", "Attention", "Starlight", "Refrigerator", "Conditioner"
    };
    srand(time(0));
    return saraksts[rand() % saraksts.size()];
}



// Paraada vardu ar pasleptiem burtiem (_), iznemot jau atminetos
void tuksumi(const string& vards, const vector<bool>& uzminets) {
    for (size_t i = 0; i < vards.size(); ++i) {
        cout << (uzminets[i] ? vards[i] : '_') << " ";
    }
    cout << endl;
}
// Lietotajs izvelas grutibas limeni (1 - viegls, 2 - videjs, 3 - gruts)
int izveletiesLimeni() {
    int limenis;
    cout << "Izvelies grutibas limeni: (1) Viegls, (2) Videjs, (3) Gruts" << endl;
    cout << "Ievadi 1, 2 vai 3: ";
    cin >> limenis;
    if (limenis < 1 || limenis > 3) {
        cout << "Nederigs limenis, iestatits grutakais limenis" << endl;
        return 3;
    }
    return limenis;
}
// Atgriez atbilstoso dzivibu skaitu pec izveleta limena
int sanemtDzivibas(int limenis) {
    if (limenis == 1) return 12;
    if (limenis == 2) return 8;
    return 6;
}







// Galvenais speles cikls vienai spelei
bool speele(int dzivibas) {
    string vards = randomVaards();
    vector<bool> uzminets(vards.size(), false);
    string minejumi;

    while (dzivibas > 0) {
        // Parada spelei aktualo vardu, dzivibas un minejumus
        tuksumi(vards, uzminets);
        cout << "Atlikusas dzivibas: " << dzivibas << endl;
        cout << "Mineetie burti: " << minejumi << endl;

        string ievade;
        cout << "Ievadi vienu burtu: ";
        cin >> ievade;

        // Parbauda vai ievade ir tikai viens alfabeta burts
        if (ievade.size() != 1 || !isalpha(ievade[0])) {
            cout << "Ievadi tikai vienu burtu, megini velreiz!" << endl;
            continue;
        }

        char burts = ievade[0];

        // Parbauda vai burts jau mineets
        if (minejumi.find(burts) != string::npos) {
            cout << "Sis burts jau ir mineets!" << endl;
            continue;
        }

        minejumi += burts;
        bool pareizsminejums = false;

        // Parbauda vai burts ir slepenaja varda
        for (size_t i = 0; i < vards.size(); ++i) {
            if (vards[i] == burts || vards[i] == toupper(burts)) {
                uzminets[i] = true;
                pareizsminejums = true;
            }
        }
        // Ja burts nav pareizi atmineets, samazina dzivibu
        if (!pareizsminejums) {
            dzivibas--;
            cout << "Burts nav varda!" << endl;
        }

        // Ja visi burti ir atmineti, spele uzvareta
        if (all_of(uzminets.begin(), uzminets.end(), [](bool burtsAtminets) { return burtsAtminets; })) {
            cout << "Apsveicam! Tu atmineji vardu: " << vards << endl;
            return true;
        }
    }
    // Ja nav vairs dzivibu, spele zaudeta
    cout << "Speles beigas! Slepenais vards bija: " << vards << endl;
    return false;
}







// Cikls, kas atkartoti izpilda speli, kamer lietotajs to velas
void speletvelreiz() {
    int uzvaras = 0, zaudejumi = 0;
    char velreiz = 'y';

    while (velreiz == 'y' || velreiz == 'Y') {
        int limenis = izveletiesLimeni();
        int dzivibas = sanemtDzivibas(limenis);
        bool uzvarets = speele(dzivibas);

        if (uzvarets) uzvaras++;
        else zaudejumi++;

        cout << "Uzvaras: " << uzvaras << " | Zaudejumi: " << zaudejumi << endl;
        cout << "Spelet velreiz? (y/n): ";
        cin >> velreiz;
    }

    cout << "\nPaldies par speeli!" << endl;
    cout << "Gala statistika: Uzvaras: " << uzvaras << " | Zaudejumi: " << zaudejumi << endl;
}

// Programmas sakums
int main() {
    speleIntro();
    speletvelreiz();
    return 0;
}
