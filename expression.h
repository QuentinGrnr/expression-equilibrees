/****************************************/
/* Auteur : S. Gueye			*/
/* Date dernière maj : 19/09/2019	*/
/****************************************/

/****************************************/
/* Objectif : Classe représentant une expression
/****************************************/
class expression
{
	friend class evaluate;
	// Variables utilisées dans "equilibre"
	stack<char> pile;
	ifstream file;
	char c;
	bool stop;
	bool fin;


	public :
		bool equilibre(char* filename);
};