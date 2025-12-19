#include <iostream>
#include <csignal>
using namespace std;

void signal_handler(int signum){
    cout << "\nProgram terminated by user (Ctrl+Z)\n";
    // exit(signum);  // Exit gracefully
}

void array_of_char();
void cin_string();
void read_line();
void read_line_split();
void read_char_counter();
void shift_array(char*, char, int);
void upper_first();
void next_int();

int main(){
    // array_of_char();
    // cin_string();
    // read_line();
    // read_line_split();
    // read_char_counter();
    // upper_first();
    next_int();
    return 0;
}

void next_int(){
    cout << "USE EXAMPLE: ali is 185 cm tall" << endl;
    char ch;
    int n;
    while (cin.get(ch)){
        if (ch >= '0' && ch <= '9'){
            cin.putback(ch);
            cin >> n;
            break;
        }
    }
    cout << n << endl; 
}

void upper_first(){
    cout << "USE EXAMPLE: type a sentence with lowe case" << endl;
    char ch;
    char stop[] = "abcd";
    while (true){
        cin.get(ch);
        shift_array(stop, ch, 5);
        if (stop[0]=='s' && stop[1]=='t' && stop[2]=='o' && stop[3]=='p') break;
        if (stop[2] == ' ' || stop[2] == '\n'){
            cout.put(char(toupper(ch)));
        }
        else {
            cout.put(ch);
        }
    }
}

void shift_array(char* arr, char new_value, int size){
    for (int i = 0; i < size; i++){
        arr[i] = arr[i + 1];
    }
    arr[size-2] = new_value;
    arr[size-1] = '\0'; 
}

void read_char_counter(){
    cout << "USE EXAMPLE: search for how many e alphabet do exists";
    cout << endl;

    char ch;
    char stop[] = "abcd";
    int counter = 0;
    while (cin.get(ch)){
        if (ch == 'e') counter ++;
        shift_array(stop, ch, 5);
        cout << stop << endl;
        if (stop[0]=='s' && stop[1]=='t' && stop[2]=='o' && stop[3]=='p') break;
    }
    cout << "the counter of e charactar: " << counter << endl;
}

void read_line_split(){
    cout << "USE EXAMPLE: Hello, how are you, doing today, hope everything is fine, let's catch up soon!";
    cout << endl;
    char word[100];
    while (*word){
        cin.getline(word, 100, ',');
        if (*word) cout << "\t " << word << endl;
    }
}

void read_line(){
    char word[80];
    while (*word){
        cin.getline(word, 80);
        if (*word) cout << word << endl;
    }
}

void cin_string(){
    char word[80];
    // *word is false on /0 or NULL which is ctrl+z
    while (*word){
        cout << "word> ";
        cin >> word;
        if (*word) cout << "\t\"" << word << "\"\n";
    }
}

void array_of_char(){
    cout << "ARRAY OF CHARACTARS" << endl;
    char s[] = "ABCD";
    for (int i=0; i<5; i++){
        cout  << "\t index [" << i << "]: " << s[i] << endl;
    }
}
