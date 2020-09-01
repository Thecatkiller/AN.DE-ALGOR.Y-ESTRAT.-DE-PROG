#include <iostream>

using namespace std;

int main() {
	
	string clave = "AMO";
	int INI = 65, FIN = 90;
	string resp = "";
	
	for(int i= INI; i <= FIN;i++){	
		for(int j= INI; j <= FIN;j++)
		{
			for(int k= INI; k <= FIN;k++){
				resp = char(i);
				resp += char(j);
				resp += char(k);
				
				if(resp.compare(clave) == 0){
					cout << "encontrado" << endl;
					cout << resp << endl;
					
				}
				
			}
		}
		
	}
	
	return 0;
}
