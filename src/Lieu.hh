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
Lieu(std::string nom,std::size_t numero,std::string rue,std::size_t code_p,int prix,std::size_t capacite, std::size_t nb_ecran );
operator std::string() const {
    return nom + "\n" + "Adresse : "+ std::to_string(adresse.numero) + adresse.rue + std::to_string(adresse.code_p) + "\n" + "Capacite humaine : " + std::to_string(capacite) + "\n" + "Nombre d'ecrans : " + std::to_string(nb_ecran);
}
/* Fonctions */

void affiche_lieu();



/* setter */
void setNom(std::string n);
void setPrix(int prix);
void setCapacite(std::size_t capacite);
void setNb_ecran(std::size_t nb);
void setAdresse(std::size_t num, std::string rue,std::size_t code_p);


/* getter */
std::string getNom();
int getPrix();
std::size_t getCapacite();
std::size_t getNb_ecran();
std::string getAdresse();


/* Attributs */
protected:
	std::string nom;
	struct adresse adresse ;
	int prix;
	std::size_t capacite;
	std::size_t nb_ecran;

};
