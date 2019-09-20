#include "Pila.cpp"

int sacarResultado(Pila*,int);

using namespace std;
string cadena_ingresada, operador, value;
int valor;

int main(){
	char respuesta;
	Pila* pila = new Pila();
	//INICIO
	cout<<"NOTA: No hay archivos de texto, ni te molestes en buscar xd"<<endl;
	do{
		cout<<"Ingrese su cadena: "<<endl;
		cin>>cadena_ingresada;
		//
		for(int i=0;i<cadena_ingresada.size();i++){
			//SUMAS
			if(cadena_ingresada[i]=='+'){
				value+=cadena_ingresada[i];
				pila->push(value);
				value="";
			} else {
				//DIVISIONES
				if(cadena_ingresada[i]=='/') {
					value+=cadena_ingresada[i];
					pila->push(value);
					value="";
				} else {
					//SI HAY MENOS
					if(cadena_ingresada[i]=='-'){
						int cont=0;
						for(int j=i+1;j<cadena_ingresada.size();j++){
							if(cadena_ingresada[j]=='+'|| cadena_ingresada[j]=='-'|| cadena_ingresada[j]=='*' || cadena_ingresada[j]=='/'){
								i+=cont;
								break;
							}else{
									cont++;
									value+=cadena_ingresada[j];	
							}
						}
						pila->push("+");
						pila->push("-"+value);
						value="";
						if(i+1==cadena_ingresada.length()-1){
							break;
						}
					} else {
						//MULTIPLICACIONES
						if(cadena_ingresada[i]=='*'){
							value+=cadena_ingresada[i];
							pila->push(value);
							value="";
						} else {
							value+=cadena_ingresada[i];
							if(cadena_ingresada[i+1]=='+'|| cadena_ingresada[i+1]=='-'|| cadena_ingresada[i+1]=='*' || cadena_ingresada[i+1]=='/'){
								pila->push(value);
								value="";
							}else if(i==cadena_ingresada.length()-1){
								pila->push(value);
								value="";
							}
						}
					}	
				}	
			}	
		}
		Node* resultado;
		while(true) {
			resultado = pila->pop();
			if(pila->isEmpty()){
				break;
			}
			Node* operador = pila->pop();
			Node* numero2 = pila->pop();
			//OPERACIONES
			if(operador->getValue()=="+"){ //SUM
				valor=atoi(resultado->getValue().c_str())+atoi(numero2->getValue().c_str());
				stringstream ssTemp;
				ssTemp << valor;
				string nuevaCadena = ssTemp.str();
				pila->push(nuevaCadena);
			} else {
				if(operador->getValue()=="*"){ //MULT
					valor=atoi(resultado->getValue().c_str())*atoi(numero2->getValue().c_str());
					stringstream ssTemp;
					ssTemp << valor;
					string nuevaCadena = ssTemp.str();
					pila->push(nuevaCadena);
				}else{ //DIV
					valor=(atoi(resultado->getValue().c_str()))/(atoi(numero2->getValue().c_str()));
					stringstream ssTemp;
					ssTemp << valor;
					string nuevaCadena = ssTemp.str();
					pila->push(nuevaCadena);
				}
			}
		}
		//IMPRESION DEL RESULTADO
		resultado->print();
		//
		system("pause");
		system("cls");
		cout<<"Ingresar otra cadena? [S/N]"<<endl;
		cin>>respuesta;
		system("cls");
	} while (respuesta=='s' || respuesta=='S');
	//FIN
	return 0;
}

