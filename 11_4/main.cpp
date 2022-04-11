//
// Created by nistor on 11.04.2022.
//
int main()
{
    Catalog c;
    c += {"Andrei"}; // Se adauga studentul cu numele "Andrei" in catalog
    c += {"Roxana"}; // Se adauga studenta cu numele "Roxana" in catalog
    c += {"Sorin"}; // Se adauga studentul cu numele "Sorin" in catalog
    c["Andrei"]["matematica"] = 8;
    c["Andrei"]["romana"] = 7;
    c["Andrei"]["franceza"] = 6;
    c["Roxana"]["matematica"] = 9;
    c["Roxana"]["romana"] = 10;
    c["Sorin"]["sport"] = 5;
    c["Sorin"]["romana"] = 9;
    std::cout << "Total studenti: " << c.GetCount() << std::endl;
    for (int index = 0; index < c.GetCount(); index++)
    {
        std::cout << "Nume: " << c[index].GetName() << std::endl;
        std::cout << "Media: " << (float)c[index] << std::endl;
        c[index].PrintNote();
    }
    return 1;
}

