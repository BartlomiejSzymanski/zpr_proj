// Ultimate cpp.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!";
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

#include <iostream>
#include "Game.h"

void test_controler(int size,int x, int y){
	PBoard sisiak(new Board(size, Board(size, sign::nic)));
	Controler controler(sisiak);
	controler.move(x, y, sign::igrek);
	try {
		if (std::get<sign>(controler.GetField(x, y)) == sign::igrek)
		{
			std::cout << "move i getField działa";
		}
		else
			std::cout << "move i getField nie działa";
	}
	catch (std::bad_variant_access e) {
		std::cout << "move i getField nie działa";
	}
}

int main()
{
	test_controler(5,2,1);
	
	return 0;
};


