#include "lab3.h"

int main(){
        int value;
        int repetitions;

        cout << "Number: " << endl;
        cin >> value;
        cout << "Repetitions: " << endl;
        cin >> repetitions;

        int outp = run(value, repetitions);
        cout << "Balanced Lists & repetitions: " << outp << endl;

        return 0;
}
