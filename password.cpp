#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>
using namespace std;

int criaSenha()
{
	unsigned seed = time(0);
	srand(seed);

	int digito1, digito2, digito3, digito4;

	digito1 = 1 + rand() % 6;
	digito2 = 1 + rand() % 6;
	digito3 = 1 + rand() % 6;
	digito4 = 1 + rand() % 6;

	int senha = (digito1 * 1000) + (digito2 * 100) + (digito3 * 10) + (digito4);

	return senha;
}

void comparaSenhas(int milharUsuario,
                   int milharSenha,
                   int centenaUsuario,
                   int centenaSenha,
                   int dezenaUsuario,
                   int dezenaSenha,
                   int unidadeUsuario,
                   int unidadeSenha)
{
	if (milharUsuario == milharSenha)
	{
		cout << "o";
	}
	else
	{
		if (milharUsuario == centenaSenha)
		{
			cout << "x";
		}
		else if (milharUsuario == dezenaSenha)
		{
			cout << "x";
		}
		else if (milharUsuario == unidadeSenha)
		{
			cout << "x";
		}
		else if (milharUsuario != milharSenha &&
		         milharUsuario != centenaSenha &&
		         milharUsuario != dezenaSenha &&
		         milharUsuario != unidadeSenha)
		{
			cout << "_";
		}
	}

	if (centenaUsuario == centenaSenha)
	{
		cout << "o";
	}
	else
	{
		if (centenaUsuario == milharSenha)
		{
			cout << "x";
		}
		else if (centenaUsuario == dezenaSenha)
		{
			cout << "x";
		}
		else if (centenaUsuario == unidadeSenha)
		{
			cout << "x";
		}
		else if (centenaUsuario != milharSenha &&
		         centenaUsuario != centenaSenha &&
		         centenaUsuario != dezenaSenha &&
		         centenaUsuario != unidadeSenha)
		{
			cout << "_";
		}
	}

	if (dezenaUsuario == dezenaSenha)
	{
		cout << "o";
	}
	else
	{
		if (dezenaUsuario == milharSenha)
		{
			cout << "x";
		}
		else if (dezenaUsuario == centenaSenha)
		{
			cout << "x";
		}
		else if (dezenaUsuario == unidadeSenha)
		{
			cout << "x";
		}
		else if (dezenaUsuario != milharSenha &&
		         dezenaUsuario != centenaSenha &&
		         dezenaUsuario != dezenaSenha &&
		         dezenaUsuario != unidadeSenha)
		{
			cout << "_";
		}
	}

	if (unidadeUsuario == unidadeSenha)
	{
		cout << "o";
	}
	else
	{
		if (unidadeUsuario == milharSenha)
		{
			cout << "x";
		}
		else if (unidadeUsuario == centenaSenha)
		{
			cout << "x";
		}
		else if (unidadeUsuario == dezenaSenha)
		{
			cout << "x";
		}
		else if (unidadeUsuario != milharSenha &&
		         unidadeUsuario != centenaSenha &&
		         unidadeUsuario != dezenaSenha &&
		         unidadeUsuario != unidadeSenha)
		{
			cout << "_";
		}
	}

	cout << endl;
}

void separaSenhaUsuario(int senhaUsuario, int senha)
{
	int milharUsuario, milharSenha;
	int centenaUsuario, centenaSenha;
	int dezenaUsuario, dezenaSenha;
	int unidadeUsuario, unidadeSenha;

	milharUsuario = senhaUsuario / 1000;
	centenaUsuario = (senhaUsuario % 1000) / 100;
	dezenaUsuario = (senhaUsuario % 100) / 10;
	unidadeUsuario = (senhaUsuario % 10);

	milharSenha = senha / 1000;
	centenaSenha = (senha % 1000) / 100;
	dezenaSenha = (senha % 100) / 10;
	unidadeSenha = (senha % 10);

	if ((milharUsuario >= 1 && milharUsuario <= 6) &&
	        (centenaUsuario >= 1 && centenaUsuario <= 6) &&
	        (dezenaUsuario >= 1 && dezenaUsuario <= 6) &&
	        (unidadeUsuario >= 1 && unidadeUsuario <= 6))
	{
		comparaSenhas(milharUsuario,
		              milharSenha,
		              centenaUsuario,
		              centenaSenha,
		              dezenaUsuario,
		              dezenaSenha,
		              unidadeUsuario,
		              unidadeSenha);
	}
	else
	{
		cout << "A senha precisa conter 4 dígitos que devem estar no intervalo de 1 a 6. Tente novamente." << endl;
	}
}

int main()
{
	int senha = criaSenha(), senhaUsuario, i = 0;

	cout << "---------------- BEM-VINDO(A) AO JOGO DA SENHA ----------------------" << endl;
	cout << "O jogo consiste em acertar a senha criada pelo computador." << endl;
	cout <<"Você deverá digitar uma senha de 4 dígitos, sendo estes presentes no intervalo de 1 a 6." << endl;
	cout <<"Além disso, você terá 10 tentativas!" << endl;
	cout << "-------------------------- BOM JOGO! ----- --------------------------" << endl;

	while (i < 10)
	{
		cout << endl << "Digite a senha: " << endl;

		cin >> senhaUsuario;

		if (cin.fail())
		{
			cout << "Senha com símbolo não permitido. Tente novamente." << endl;

			cin.clear();
			cin.ignore(1000, '\n');
		}

		else
		{
			if (senhaUsuario < 1111 || senhaUsuario > 6666)
			{
				cout << "Os dígitos devem estar no intervalo de 1 a 6. Tente novamente." << endl;
				i--;
			}

			separaSenhaUsuario(senhaUsuario, senha);
			i++;

			if (senhaUsuario == senha)
				break;

			cout << "Tentativa " << i << " de 10." << endl;
		}
	}

	if (senhaUsuario == senha)
		cout << "Parabéns! Você venceu!";
	else
		cout << "Você perdeu!";

	return 0;
}