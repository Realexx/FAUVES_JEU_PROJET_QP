#ifndef FAUVES_JEU_PROJET_QP_APPLICATION_H
#define FAUVES_JEU_PROJET_QP_APPLICATION_H


class application {
public:
    void run();
private:
    static int menu_principal();

    void jouer();
    void creation_terrain();
    void edition_terrain();
};


#endif //FAUVES_JEU_PROJET_QP_APPLICATION_H
