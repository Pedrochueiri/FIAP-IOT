const int buzzer = 13;

const char* dic_morse[][2] = {
    {"a", ".-"}, {"b", "-..."}, {"c", "-.-."}, {"d", "-.."}, {"e", "."}, {"f", "..-."}, {"g", "--."}, {"h", "...."},
    {"i", ".."}, {"j", ".---"}, {"k", "-.-"}, {"l", ".-.."}, {"m", "--"}, {"n", "-."}, {"o", "---"}, {"p", ".--."},
    {"q", "--.-"}, {"r", ".-."}, {"s", "..."}, {"t", "-"}, {"u", "..-"}, {"v", "...-"}, {"w", ".--"}, {"x", "-..-"},
    {"y", "-.--"}, {"z", "--.."}
};

void setup() {
    pinMode(buzzer, OUTPUT);
}

void loop() {
    String palavra = "sos";
    palavra.toLowerCase();
    
    int palavraLength = palavra.length();
    for (int i = 0; i < palavraLength; i++) {
        char letter = palavra[i];
        const char* morseCode = NULL;
        
        for (int j = 0; j < sizeof(dic_morse) / sizeof(dic_morse[0]); j++) {
            if (letter == dic_morse[j][0][0]) {
                morseCode = dic_morse[j][1];
                break;
            }
        }
        
        if (morseCode != NULL) {
            for (int i = 0; morseCode[i]; i++) {
                char simbolo = morseCode[i];
                if (simbolo == '.') {
                    tone(buzzer, 1000, 100);
                } else if (simbolo == '-') {
                    tone(buzzer, 1000, 300);
                }
                delay(200);
            }
            delay(400);
        }
        delay(250);
    }
    delay(1000);
}
