#include <iostream>
#include <ctime>
using namespace std;
char spelfält[3][3] = { 
{ ' ', ' ', ' ', },
{ ' ', ' ', ' ', },
{ ' ', ' ', ' ', },
};
// Här skapas själva spelfältet.
int inbalance = 0;
int balance = 0;
int bet = 0;
int vinst = 0;
// Här deklareras globala variabler.
void errormsg() {
	// ett standardmeddelande för alla felsteg i programmet.
	cout << "There has been an error, please try again after restarting." <<
		endl;
}
void snurra()
/*
En funktion för att slumpa nummer som konverteras
till bokstäverna A, O eller X.
*/
{
	int Random = 0; //Deklarerar Random.
	srand(time(0));
	for (int l = 0; l < 3; l++)
		/* For loopar som slumpmässigt
		ger nummer d refter symboler till 
		arrayen spelfält tills alla är fyllda. */
	{
	for (int b = 0; b < 3; b++)
	{
	Random = rand() % 3;
	if (Random == 0)
	{
	spelfält[l][b] = 'A'; 
		// ex: Om slumpat nummer 0 så blir det A.
		}
		else if (Random == 1)
		{
		spelfält[l][b] = 'O'; 
		}
		else if (Random == 2)
		{
		spelfält[l][b] = 'X'; 
		}
		cout << spelfält[l][b] << "\t"; 
			// skapar "linjer" mellan spelrutor.
			}
			cout << "\n";
			//skapar "rader" mellan spelrutor.
	}
}
int calc(int bet) {
	//en funktion där vinster beräknas.
	int matchanderader = 0;
	int vinst = 0;
	/* variabler  återställs för
	användare som spelar  flera gånger */
	for (int l = 0; l < 3; ++l) {
		if (spelfält[l][0] == spelfält[l][1] && spelfält[l][1] == spelfält[l]
			[2]) {
			matchanderader = matchanderader + 1;
		}
	}
	for (int b = 0; b < 3; ++b) {
		if (spelfält[0][b] == spelfält[1][b] && spelfält[1][b] == spelfält[2]
			[b]) {
			matchanderader = matchanderader + 1;
		}
	}
	if (spelfält[0][0] == spelfält[1][1] && spelfält[1][1] == spelfält[2][2]) {
		
			matchanderader = matchanderader + 1;
	}
	else if (spelfält[2][0] == spelfält[1][1] && spelfält[1][1] == spelfält[0]
		[2]) {
		matchanderader = matchanderader + 1;
	}
	if (matchanderader == 0)
		//Om inga matchande rader.
	{
		vinst = 0;
	}
	else if (matchanderader == 1)
		// Om 1 matchande rad.
	{
		bet = bet * 2;
		vinst = vinst + bet;
		balance = balance + vinst;
	}
	else if (matchanderader == 2) {
		bet = bet * 3;
		vinst = vinst + bet;
		balance = balance + vinst;
		cout << bet;
	}
	else if (matchanderader == 3) {
		bet = bet * 4;
		vinst = vinst + bet;
		balance = balance + vinst;
	}
	else if (matchanderader == 4) {
		bet = bet * 5;
		vinst = vinst + bet;
		balance = balance + vinst;
	}
	else if (matchanderader == 5) {
		bet = bet * 7;
		vinst = vinst + bet;
		balance = balance + vinst;
	}
	else if (matchanderader == 8) {
		bet = bet * 10;
		vinst = vinst + bet;
		balance = balance + vinst;
	}
	return vinst;
	//Returnerar vinst.
}
int main()
{
	bool omspel = true;
	/* Boolen omspel sätts till true för att senare kolla om de vill spela igen
	eller inte, därmed loopa eller inte. */
		cout << "How much do you want to put in your balance?" << endl;
	cout << "100, 300 or  500 kr." << endl;
	cin >> inbalance;
	balance = balance + inbalance;
	if (inbalance != 100 && inbalance != 300 && inbalance != 500)
		/* om inmatning av saldo (balance)
		inte accepterat antal så stängs det 
		av med error meddelande..*/
	{
		errormsg();
		exit;
	}
	while (omspel = true) {
		//Här börjar spelet om för de som spelar mer  nåen gång.
		int bet = 0;
		int vinst = 0;
		// Här återställs de relevanta variablernas värde till 0.
		cout << "How much do you want to bet?" << endl;
		cin >> bet;
		cout << "You have bet " << bet << "kr" << endl;
		cout << "The wheel is now spinning..." << endl;
		snurra();
		vinst = calc(bet);
		/*
		kallar på calc att
		beräkna vad vinst är
		och  överför bet dit.*/
	balance = balance - bet;
		// satsning tas bort från balance.
		if (vinst == 0)
			/* om vinsten returnerad av
			funktionen calc  är 0 kr 
			så har man förlorat
			*/
		{
			cout << "You lost " << bet << "kr." << endl;
			cout << "Your balance is now " << balance << "kr." << endl;
		}
		else if (vinst != 0) {
			cout << "You won " << vinst << "kr." << endl;
			cout << "Your balance is now " << balance << "kr." << endl;
		}
		string spelaigen;
		cout << "Do you want to play again?" << endl;
		cin >> spelaigen;
		if (spelaigen == "yes")
			//om användaren vill spela igen.
		{
			omspel = true;
		}
		else if (spelaigen == "no" || balance == 0 || balance < 0)
			//om användare inte vill spela igen.�
		{
			cout << "Thank you for playing!" << endl;
			omspel = false;
			return (0);
		}
	}
}