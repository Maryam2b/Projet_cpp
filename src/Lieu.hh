#include <string>


class Lieu{

public:
/* Constructor */
Lieu();
Lieu(std::size_t superficie, float prix,std::size_t capacite, std::size_t nb_ecran );

/* Fonctions */




/* setter */
void setSuperficie(std::size_t superficie);
void setPrix(float prix);
void setCapacite(std::size_t capacite);
void setNb_ecran(std::size_t nb);

/* getter */
std::string getSuperficie();
std::string getPrix();
std::string getCapacite();
std::string getNb_ecran();


/* Attributs */
private:
	std::size_t superficie;
	float prix;
	std::size_t capacite;
	std::size_t nb_ecran;
    
    
};
