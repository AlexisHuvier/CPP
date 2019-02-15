#include <iostream>

bool win(char *L1, char *L2, char *L3, char player)
{
    if(L1[0] == player)
    {
        if(L1[1] == player && L1[2] == player) return true;
        if(L2[0] == player && L3[0] == player) return true;
        if(L2[1] == player && L3[2] == player) return true;
    }
    if(L1[1] == player && L2[1] == player && L3[1] == player) return true;
    if(L1[2] == player)
    {
        if(L2[1] == player && L3[0] == player) return true;
        if(L2[2] == player && L3[2] == player) return true;
    }
    if(L2[0] == player && L2[1] == player && L2[2] == player) return true;
    if(L3[0] == player && L3[1] == player && L3[2] == player) return true;
    return false;
}

void afficheJeu(char *L1, char *L2, char *L3)
{
    std::cout << std::endl << "    1   2   3" << std::endl;
    std::cout << "  |===|===|===|" << std::endl;
    std::cout << "1 | " << L1[0] << " | " << L1[1] << " | " << L1[2] << " |" << std::endl;
    std::cout << "  |===|===|===|" << std::endl;
    std::cout << "2 | " << L2[0] << " | " << L2[1] << " | " << L2[2] << " |" << std::endl;
    std::cout << "  |===|===|===|" << std::endl;
    std::cout << "3 | " << L3[0] << " | " << L3[1] << " | " << L3[2] << " |" << std::endl;
    std::cout << "  |===|===|===|" << std::endl << std::endl;
}

bool setSign(char *L1, char *L2, char *L3, char player, int ligne, int colonne)
{
    if(ligne == 1)
    {
        if(L1[colonne - 1] == '-')
        {
            L1[colonne - 1] = player;
            return true;
        }
    }
    else if(ligne == 2)
    {
        if(L2[colonne - 1] == '-')
        {
            L2[colonne - 1] = player;
            return true;
        }
    }
    else if(ligne == 3)
    {
        if(L3[colonne - 1] == '-')
        {
            L3[colonne - 1] = player;
            return true;
        }
    }
    return false;
}

int main()
{
    char L1[3] {'-', '-', '-'};
    char L2[3] {'-', '-', '-'};
    char L3[3] {'-', '-', '-'};
    int ligne = 4, colonne;
    bool valide = false;
    afficheJeu(L1, L2, L3);
    while(true)
    {
        std::cout << "Joueur 1, a vous de jouer :" << std::endl;
        ligne = 4;
        valide = false;
        while(!valide)
        {
            std::cout << "Ligne : ";
            std::cin >> ligne;
            std::cout << "Colonne : ";
            std::cin >> colonne;
            valide = setSign(L1, L2, L3, 'X', ligne, colonne);
            if(!valide)
            {
                std::cout << "Ligne et/ou Colonne invalide ou déjà prise." << std::endl;
            }
        }
        afficheJeu(L1, L2, L3);
        if(win(L1, L2, L3, 'X'))
        {
            std::cout << "Fin du jeu : Joueur 1 gagnant" << std::endl;
            break;
        }
        std::cout << "Joueur 2, a vous de jouer :" << std::endl;
        ligne = 4;
        valide = false;
        while(!valide)
        {
            std::cout << "Ligne : ";
            std::cin >> ligne;
            std::cout << "Colonne : ";
            std::cin >> colonne;
            valide = setSign(L1, L2, L3, '0', ligne, colonne);
            if(!valide)
            {
                std::cout << "Ligne et/ou Colonne invalide ou déjà prise." << std::endl;
            }
        }
        afficheJeu(L1, L2, L3);
        if(win(L1, L2, L3, '0'))
        {
            std::cout << "Fin du jeu : Joueur 2 gagnant" << std::endl;
            break;
        }
    }
    return 0;
}
