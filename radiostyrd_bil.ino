// Include statementet lägger till DIYables_IRcontroller bibloteket som sedan ska använda IR-kontrollen
#include <DIYables_IRcontroller.h> // DIYables_IRcontroller library

// Define statementerna definierar konstanter för stiftnumren för Ir-mottagaren och två reläer
#define IR_RECEIVER_PIN 8
#define RELAY_PIN 7
#define RELAY_PINN 6

// Skapar ett objekt av typen DIYables_IRcontroller_17 med namnet irController och använder sedan stiftnumret för IR-mottagaren och en debouncing tid därmed på 200ms
DIYables_IRcontroller_17 irController(IR_RECEIVER_PIN, 200); // debounce time is 200ms

// Själva setup funktionen körs endast en gång när Arduino startar
void setup() {
  Serial.begin(9600); // Denna kod initierar kommunikation via den seriella porten med hastigheten 9600
  irController.begin(); // Initierar DIYables_IRcontroller bibloteket
  pinMode(IR_RECEIVER_PIN, INPUT); // Alla spinmode kommandon ätter stiftlägen för IR-mottagaren, både relä 1 och relä 2 som antingen ingång eller utgång
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(RELAY_PINN, OUTPUT);
}

// Void loopen körs upprepande gånger så länge Arduino är igång
void loop() {
  Key17 command = irController.getKey(); // Denna koden läser in en nycket från IR-kontrollen
  if (command != Key17::NONE) {
    switch (command) { // Denna switch satts utför olika åtgärder beroende på vilken knapp på kontrollen som tryckts

      case Key17::KEY_2: // Slår på båda reläerna och skriver ut "Fram" i terminalen till den serieporten
        Serial.println("Fram");
        digitalWrite(RELAY_PIN, HIGH);
        digitalWrite(RELAY_PINN, HIGH);
        delay(100);
        
        break;

      case Key17::KEY_4: // Slår på båda reläerna och skriver ut "Vänster" i terminalen till den serieporten
        Serial.println("Vänster");
        digitalWrite(RELAY_PIN, HIGH);
        delay(100);
        // TODO: YOUR CONTROL


        break;


      case Key17::KEY_6: // Slår på båda reläerna och skriver ut "Höger" i terminalen till den serieporten
        Serial.println("Höger");
        digitalWrite(RELAY_PINN, HIGH);
        delay(100);


        // TODO: YOUR CONTROL


        break;

      // Denna kod skriver en varning till den seriella porten om en okänd knapptryckning
      default:
        Serial.println("WARNING: undefined command:");
        break;
    }
  } else { // Om ingenting händer eller om ingen knapp trycks så slår den av båda reläerna
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(RELAY_PINN, LOW);
    
  }
}
