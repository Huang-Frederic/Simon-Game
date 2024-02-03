// include for melodies
#include <pitches.h>

// leds define
#define LED_GREEN 7
#define LED_YELLOW 3
#define LED_BLUE 4
#define LED_RED A1
#define LED_WHITE 6

// buttons define
#define BUTTON_GREEN 2
#define BUTTON_YELLOW 8
#define BUTTON_BLUE 12
#define BUTTON_RED 13
#define BUTTON_WHITE A0

// Others
#define BUZZER A4
#define BUTTON_START A3

// Initialize functions
void light_button();
void game();
int game_check_if_correct(int tab[], int size);
void buzz_win();
void buzz_lose();
void buzz_count();

void setup()
{
  // leds setup
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_WHITE, OUTPUT);

  // buttons setup
  pinMode(BUTTON_GREEN, INPUT_PULLUP);
  pinMode(BUTTON_YELLOW, INPUT_PULLUP);
  pinMode(BUTTON_BLUE, INPUT_PULLUP);
  pinMode(BUTTON_RED, INPUT_PULLUP);
  pinMode(BUTTON_WHITE, INPUT_PULLUP);

  // Others
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON_START, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(BUTTON_START) == 0)
  {
    buzz_count();
    game();
  }
}

void light_button(int desired_light, int duration)
{
  switch (desired_light)
  {
  case 1: // GREEN
    digitalWrite(LED_GREEN, HIGH);
    delay(duration);
    digitalWrite(LED_GREEN, LOW);
    break;
  case 2: // YELLOW
    digitalWrite(LED_YELLOW, HIGH);
    delay(duration);
    digitalWrite(LED_YELLOW, LOW);
    break;
  case 3: // BLUE
    digitalWrite(LED_BLUE, HIGH);
    delay(duration);
    digitalWrite(LED_BLUE, LOW);
    break;
  case 4: // RED
    digitalWrite(LED_RED, HIGH);
    delay(duration);
    digitalWrite(LED_RED, LOW);
    break;
  case 5: // WHITE
    digitalWrite(LED_WHITE, HIGH);
    delay(duration);
    digitalWrite(LED_WHITE, LOW);
    break;
  case 6: // ALL
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_WHITE, HIGH);
    buzz_lose();
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_WHITE, LOW);
  }
}

void game()
{
  int count = 1;
  int exit = 1;

  while (exit != 0)
  {
    int tab[count];

    for (int i = 0; i < count; i++)
    {
      randomSeed(analogRead(A5));
      tab[i] = random(1, 6);

      light_button(tab[i], 1000);
      delay(100);
    }

    int result = game_check_if_correct(tab, count);

    if (result == 0)
    {
      Serial.print("YOU LOST THE ROUND \nYou survived for ");
      Serial.print(count);
      Serial.println(" round(s)");
      light_button(6, 1000);
      exit = 0;
    }
    else
    {
      Serial.println("YOU WON THE ROUND");
      buzz_win();
      count++;
    }

    delay(1000);
  }
}

int game_check_if_correct(int tab[], int size)
{
  for (int i = 0; i < size; i++)
  {
    int loop = 1;

    while (loop != 0)
    {
      // GREEN
      int valeur = digitalRead(BUTTON_GREEN);
      if (valeur == 0)
      {
        if (tab[i] == 1)
        {
          light_button(1, 500);
          loop = 0;
        }
        else
        {
          return 0;
        }
      }
      // YELLOW
      valeur = digitalRead(BUTTON_YELLOW);
      if (valeur == 0)
      {
        if (tab[i] == 2)
        {
          light_button(2, 500);
          loop = 0;
        }
        else
        {
          return 0;
        }
      }
      // BLUE
      valeur = digitalRead(BUTTON_BLUE);
      if (valeur == 0)
      {
        if (tab[i] == 3)
        {
          light_button(3, 500);
          loop = 0;
        }
        else
        {
          return 0;
        }
      }
      // RED
      valeur = digitalRead(BUTTON_RED);
      if (valeur == 0)
      {
        if (tab[i] == 4)
        {
          light_button(4, 500);
          loop = 0;
        }
        else
        {
          return 0;
        }
      }
      // WHITE
      valeur = digitalRead(BUTTON_WHITE);
      if (valeur == 0)
      {
        if (tab[i] == 5)
        {
          light_button(5, 500);
          loop = 0;
        }
        else
        {
          return 0;
        }
      }
    }
  }
  return 1;
}

void buzz_win()
{
  int melody[] = {
      NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3,
      0, NOTE_B3, NOTE_C4};

  int durations[] = {
      4, 8, 8, 4, 4,
      4, 4, 4};

  int color = 1;
  for (int thisNote = 0; thisNote < 8; thisNote++)
  {
    int noteDuration = 1000 / durations[thisNote];
    int pause = noteDuration * 1.30;
    tone(BUZZER, melody[thisNote], pause);
    light_button(color, pause);
    noTone(BUZZER);
    if (color >= 5)
    {
      color--;
    }
    else
    {
      color++;
    }
  }
}

void buzz_lose()
{
  int melody[] = {
      NOTE_A3, NOTE_G3, NOTE_E3, NOTE_D3, NOTE_E3,
      NOTE_A2, NOTE_A2, NOTE_D3, NOTE_FS3, NOTE_D3};

  int durations[] = {
      4, 4, 8, 8, 4,
      4, 8, 8, 4, 2};

  for (int thisNote = 0; thisNote < 10; thisNote++)
  {
    int noteDuration = 1000 / durations[thisNote];
    int pause = noteDuration * 1.30;
    tone(BUZZER, melody[thisNote], noteDuration);
    delay(pause);
    noTone(BUZZER);
  }
}

void buzz_count()
{
  int melody[] = {
      NOTE_A4, NOTE_A4, NOTE_A4, NOTE_E5};

  int durations[] = {
      4, 4, 4, 3};

  int color = 1;
  for (int thisNote = 0; thisNote < 4; thisNote++)
  {
    int noteDuration = 1000 / durations[thisNote];
    int pause = noteDuration * 1.30;
    tone(BUZZER, melody[thisNote], noteDuration);
    light_button(color, pause);
    delay(pause);
    noTone(BUZZER);
    color++;
  }
}