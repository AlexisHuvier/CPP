#include <iostream>

int main()
{
    std::string phrase;
    std::cout << "Entrez la phrase à dire : " << std::endl;
    std::getline(std::cin, phrase);
    if(phrase.length() >= 30)
    {
        std::string egals = "";
        for(unsigned int i=0; i<30; i++)
        {
            egals += "=";
        }
        std::cout << "/=" << egals << "=\\" << std::endl;
        std::cout << "| " << phrase.substr(0, 30) << " |" << std::endl;
        int left = phrase.length() - 30, now = 30;
        while(left > 0)
        {
            if(left > 30)
            {
                std::cout << "| " << phrase.substr(now, 30) << " |" << std::endl;
                now += 30;
                left -= 30;
            }
            else
            {
                std::string egals = "";
                for(unsigned int i=0; i<30-left; i++)
                {
                    egals += " ";
                }
                std::cout << "| " << phrase.substr(now, left) << egals << " |" << std::endl;
                left = 0;
            }
        }
        std::cout << "\\=" << egals << "=/" << std::endl;
    }
    else
    {
        std::string egals {""};
        for(unsigned int i=0; i<phrase.length(); i++)
        {
            egals += "=";
        }
        std::cout << "/=" << egals << "=\\" << std::endl;
        std::cout << "| " << phrase << " |" << std::endl;
        std::cout << "\\=" << egals << "=/" << std::endl;
    }
    std::cout << "   \\  () ()" << std::endl;
    std::cout << "    \\ ()_()" << std::endl;
    std::cout << "      (O.O)" << std::endl;
    std::cout << "      (___)" << std::endl;
    std::cout << "      (   )" << std::endl;
    std::cout << "      () ()" << std::endl;
    std::cout << "      (   )" << std::endl;
    std::cout << "      ()^()" << std::endl;
}
