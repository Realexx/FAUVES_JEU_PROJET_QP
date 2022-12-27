#include "fauve.h"

fauve::fauve() : d_pos{}, d_est_vivant{true}
{}

fauve::fauve(int ligne, int colonne) : d_pos{ligne, colonne}, d_est_vivant{true}
{}