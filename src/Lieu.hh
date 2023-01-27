#include <string>



struct adresse
{
	std::size_t numero = 0 ;
    std::string rue = "" ;
    std::size_t code_p = 0;
   // std::string ville= "" ;
   // std::string pays= "" ;   par défaut on dira que toutes les fanzones sont à Paris en France
};

class Lieu{

public:
/* Constructor */
Lieu();
Lieu(std::string nom,std::size_t numero,std::string rue,std::size_t code_p,float prix,std::size_t capacite, std::size_t nb_ecran );

/* Fonctions */

void affiche_lieu();



/* setter */
void setNom(std::string n);
void setPrix(float prix);
void setCapacite(std::size_t capacite);
void setNb_ecran(std::size_t nb);
void setAdresse(std::size_t num, std::string rue,std::size_t code_p);


/* getter */
std::string getNom();
float getPrix();
std::size_t getCapacite();
std::size_t getNb_ecran();
std::string getAdresse();


/* Attributs */
protected:
	std::string nom;
	struct adresse adresse ;
	float prix;
	std::size_t capacite;
	std::size_t nb_ecran;

	
	

    
};
