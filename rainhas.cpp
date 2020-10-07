#include <iostream>
#include <vector>
using namespace std;


		int contSolucoes = 0;

		void mostrarTabuleiro(vector<vector<int> > & tab, int N)
		{
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					if(tab[i][j] == 1)
						cout << "*\t";
					else
						cout << "|\t";
		}
		cout << "\n\n";
		}
		cout << "\n";
		}

		bool valido(vector<vector<int> > & tab, int N, int linha, int coluna){

			for(int i = 0; i < N; i++){
				if(tab[linha][i] == 1)
					return false;
		}

			for(int i = 0; i < N; i++){
				if(tab[i][coluna] == 1)
					return false;
		}

			for(int i = linha, j = coluna; i >= 0 && j >= 0; i--, j--){
				if(tab[i][j] == 1)
					return false;
		}
			for(int i = linha, j = coluna; i < N && j < N; i++, j++){
				if(tab[i][j] == 1)
					return false;
		}


			
			for(int i = linha,  j = coluna; i >= 0 && j < N; i--, j++){
				if(tab[i][j] == 1)
					return false;
		}
			for(int i = linha,  j = coluna; i < N && j >= 0; i++, j--){
				if(tab[i][j] == 1)
					return false;
		}
		return true;
	}	


		void algoritmo(vector<vector<int> > & tab, int N, int coluna){
			if(coluna == N){
				cout << "Solucao " << contSolucoes + 1 << ":\n\n";
				mostrarTabuleiro(tab, N);
				contSolucoes++;
				return;
		}

			for(int i = 0; i < N; i++){
				if(valido(tab, N, i, coluna)){
					tab[i][coluna] = 1;
					algoritmo(tab, N, coluna + 1);
					tab[i][coluna] = 0;
		}
		}
	}

		int main(int argc, char *argv[]){
	
		int N = 8;
		vector<vector<int> > tab;


			for(int i = 0; i < N; i++){
				vector<int> linha(N);
				tab.push_back(linha);
		}
		algoritmo(tab, N, 0);
		cout << "\n " << contSolucoes  << "Possiveis resolucoes\n";
		system("pause");
		return 0;
	}
