#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
	{'1', '2', '3', '+'},
	{'4', '5', '6', '-'},
	{'7', '8', '9', '*'},
	{'C', '0', '=', '/'}
};

byte rowPins[ROWS] = {7, 6, 5, 4};
byte colPins[COLS] = {3, 2, 1, 0};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

long first = 0;
long second = 0;
double result = 0;
char op = '\0';
bool enteringSecond = false;
bool justCalculated = false;

void setup()
{
	lcd.init();
	lcd.backlight();
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("Calculatrice");
	delay(1000);
	lcd.clear();
}

void loop()
{
	char key = keypad.getKey();

	if (key)
	{
		if (key >= '0' && key <= '9')
		{
			if (justCalculated)
			{
				first = 0;
				second = 0;
				result = 0;
				op = '\0';
				enteringSecond = false;
				justCalculated = false;
				lcd.clear();
			}

			if (!enteringSecond)
			{
				first = first * 10 + (key - '0');
				lcd.setCursor(0, 0);
				lcd.print(first);
			}
			else
			{
				second = second * 10 + (key - '0');
				lcd.setCursor(0, 1);
				lcd.print(second);
			}
		}
		else if (key == '+' || key == '-' || key == '*' || key == '/')
		{
			if (enteringSecond)
			{
				calculate();
				first = result;
				second = 0;
				lcd.clear();
				lcd.setCursor(0, 0);
				lcd.print(first);
			}

			op = key;
			enteringSecond = true;
			justCalculated = false;
			lcd.setCursor(15, 0);
			lcd.print(op);
		}
		else if (key == '=')
		{
			if (enteringSecond)
			{
				if (op == '/' && second == 0)
				{
					lcd.clear();
					lcd.setCursor(0, 0);
					lcd.print("Erreur:");
					lcd.setCursor(0, 1);
					lcd.print("Division par 0");
					delay(2000);
					lcd.clear();

					first = 0;
					second = 0;
					result = 0;
					op = '\0';
					enteringSecond = false;
					justCalculated = false;
				}
				else
				{
					calculate();
					lcd.clear();
					lcd.setCursor(0, 0);
					lcd.print(result);

					first = result;
					second = 0;
					enteringSecond = false;
					justCalculated = true;
				}
			}
		}
		else if (key == 'C')
		{
			lcd.clear();
			first = 0;
			second = 0;
			result = 0;
			op = '\0';
			enteringSecond = false;
			justCalculated = false;
		}
	}
}

void calculate()
{
	switch (op)
	{
		case '+':
			result = first + second;
			break;
		case '-':
			result = first - second;
			break;
		case '*':
			result = first * second;
			break;
		case '/':
			result = (float)first / second;
			break;
		default:
			result = first;
	}
}
