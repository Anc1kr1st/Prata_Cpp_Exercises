/*
Chapter 03 Exercise 02

Napište krátký program, který se zeptá na vaši výšku ve stopách a palcích a váhu v librách. 
(Zadané informace uložte do tří proměnných.) V programu vypočítejte a vypište váš BMI (Body 
Mass Index - index tělesné hmotnosti.) Abyste mohli vypočítat BMI, nejprve převeďte výšku ve 
stopách a palcích pouze na palce. Potom převeďte palce na metry vynásobením 0,0254. Dále 
konvertujte váhu v librách na kilogramy dělením 2,2. Nakonec vypočítejte BMI dělením váhy 
v kg výškou v m na druhou. Pro rúzné konverzní faktory použijte symbolické konstanty. 
*/

#include <iostream>

using namespace std;

int main() {

	float highFeet, highInch, weight, BMI;

	float const feetToInches = 12;
	float const inchesToM = 0.0254;
	float const poundsToKg = 2.2;

	cout << "Please, insert your heigh in feet and inches and your weight in pounds. \n";
	cout << "Your high in whole feet: ";
	cin >> highFeet;
	cout << "Your high in inches: ";
	cin >> highInch;
	cout << "Your weight in pounds: ";
	cin >> weight;

	highInch = (highFeet * feetToInches + highInch) * inchesToM;
	weight = weight / poundsToKg;
	BMI = weight / (highInch * highInch);

	cout << "Your BMI is: " << BMI;

	return 0;
}
