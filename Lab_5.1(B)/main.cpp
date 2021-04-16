#include <iostream>

#include "FuzzyNumber.h"
#include "Me_Error_size_memorry.h"
#include "My_Error_Range.h"


int main(void) {
	using std::cout;

	std::cout << "\n\n////////////////////////////////////////////////////////////1111111\n";

	//визначається власний виняток
	try {	//захищений(контрольований) блок
		FuzzyNumber A(12.0, 6.0, 7.0),
					B(2.0, 3.0, 4.0),
					C(0.0, 0.0, 0.0);

		cout << "\nDani(value) chusla A: " << A;
		cout << A.operator std::string();

		cout << "\n\nDani(value) chusla B: " << B;
		cout << B.operator std::string();

		C = A + B;
		cout << "\n\nAddit object A i B: ";
		cout << C.operator std::string();

		C = A * B;
		cout << "\n\nMulti object A i B: ";
		cout << C.operator std::string();
	}
	catch (My_Error_Range* a) {		//зловлює помилку "My_Error_Range"
		std::cout << a->What();
	}

	std::cout << "\n\n";
	system("pause");
	std::cout << "\n\n////////////////////////////////////////////////////////////////////2222222\n";

	//використання стандартного винятка
	try { //захищений(контрольований) блок
		FuzzyNumber a, b, c;

		cout << "\nVvedit dani(value) object a: ";
		std::cin >> a;

		cout << "\n\nDani(value) chusla a: " << a;
		cout << a.operator std::string();

		cout << "\n\nVvedit dani(value) object b: ";
		std::cin >> b;

		cout << "\n\nDani(value) chusla b: " << b;
		cout << b.operator std::string();

		c = a + b;
		cout << "\n\nAddit object a i b: ";
		cout << c.operator std::string();

		c = a * b;
		cout << "\nMulti object a i b: ";
		cout << c.operator std::string();
	}
	catch (std::out_of_range obj_1) {		// зловлює помилку "out_of_range"
		std::cout << obj_1.what();
	}

	std::cout << "\n\n";
	system("pause");
	std::cout << "\n\n////////////////////////////////////////////////////////////////////33333333\n";

	//використання винятків - нащадки від стандартних винятків;
	try { //захищений(контрольований) блок
		int size(0);
		std::cout << "\n\nVvedit size masuva: ";  std::cin >> size;

		if ((size < 2) || (size > 80'000'000))
			throw Me_Error_size_memorry("!!!Incorrectly allocated memory!!!");		//генерування об'єкта винятка
		FuzzyNumber* masuv = new FuzzyNumber[size];

		//визначається власний виняток
		try {	//захищений(контрольований) блок
			cout << "\nVvedit dani(value) object a: ";
			std::cin >> masuv[0];

			cout << "\n\nDani(value) chusla a: " << masuv[0];
			cout << masuv[0].operator std::string();

			cout << "\n\nVvedit dani(value) object b: ";
			std::cin >> masuv[(unsigned int)1];

			cout << "\n\nDani(value) chusla b: " << masuv[1];
			cout << masuv[1].operator std::string();

			masuv[3] = masuv[0] + masuv[1];
			cout << "\n\nAddit object a i b: ";
			cout << masuv[3].operator std::string();

			masuv[3] = masuv[0] * masuv[1];
			cout << "\nMulti object a i b: ";
			cout << masuv[3].operator std::string();
		}
		catch (std::out_of_range obj_1) {		// зловлює помилку "out_of_range"
			std::cout << obj_1.what();
		}
	}
	catch (Me_Error_size_memorry& obj_2) {		// зловлює помилку "Me_Error_size_memorry"
		std::cout << obj_2.What();
	}

	std::cout << "\n\n";
	system("pause");
	return 0;
}