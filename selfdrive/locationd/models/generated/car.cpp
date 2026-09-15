#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7499019697074073600) {
   out_7499019697074073600[0] = delta_x[0] + nom_x[0];
   out_7499019697074073600[1] = delta_x[1] + nom_x[1];
   out_7499019697074073600[2] = delta_x[2] + nom_x[2];
   out_7499019697074073600[3] = delta_x[3] + nom_x[3];
   out_7499019697074073600[4] = delta_x[4] + nom_x[4];
   out_7499019697074073600[5] = delta_x[5] + nom_x[5];
   out_7499019697074073600[6] = delta_x[6] + nom_x[6];
   out_7499019697074073600[7] = delta_x[7] + nom_x[7];
   out_7499019697074073600[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8422684140360355869) {
   out_8422684140360355869[0] = -nom_x[0] + true_x[0];
   out_8422684140360355869[1] = -nom_x[1] + true_x[1];
   out_8422684140360355869[2] = -nom_x[2] + true_x[2];
   out_8422684140360355869[3] = -nom_x[3] + true_x[3];
   out_8422684140360355869[4] = -nom_x[4] + true_x[4];
   out_8422684140360355869[5] = -nom_x[5] + true_x[5];
   out_8422684140360355869[6] = -nom_x[6] + true_x[6];
   out_8422684140360355869[7] = -nom_x[7] + true_x[7];
   out_8422684140360355869[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6196860334201773793) {
   out_6196860334201773793[0] = 1.0;
   out_6196860334201773793[1] = 0.0;
   out_6196860334201773793[2] = 0.0;
   out_6196860334201773793[3] = 0.0;
   out_6196860334201773793[4] = 0.0;
   out_6196860334201773793[5] = 0.0;
   out_6196860334201773793[6] = 0.0;
   out_6196860334201773793[7] = 0.0;
   out_6196860334201773793[8] = 0.0;
   out_6196860334201773793[9] = 0.0;
   out_6196860334201773793[10] = 1.0;
   out_6196860334201773793[11] = 0.0;
   out_6196860334201773793[12] = 0.0;
   out_6196860334201773793[13] = 0.0;
   out_6196860334201773793[14] = 0.0;
   out_6196860334201773793[15] = 0.0;
   out_6196860334201773793[16] = 0.0;
   out_6196860334201773793[17] = 0.0;
   out_6196860334201773793[18] = 0.0;
   out_6196860334201773793[19] = 0.0;
   out_6196860334201773793[20] = 1.0;
   out_6196860334201773793[21] = 0.0;
   out_6196860334201773793[22] = 0.0;
   out_6196860334201773793[23] = 0.0;
   out_6196860334201773793[24] = 0.0;
   out_6196860334201773793[25] = 0.0;
   out_6196860334201773793[26] = 0.0;
   out_6196860334201773793[27] = 0.0;
   out_6196860334201773793[28] = 0.0;
   out_6196860334201773793[29] = 0.0;
   out_6196860334201773793[30] = 1.0;
   out_6196860334201773793[31] = 0.0;
   out_6196860334201773793[32] = 0.0;
   out_6196860334201773793[33] = 0.0;
   out_6196860334201773793[34] = 0.0;
   out_6196860334201773793[35] = 0.0;
   out_6196860334201773793[36] = 0.0;
   out_6196860334201773793[37] = 0.0;
   out_6196860334201773793[38] = 0.0;
   out_6196860334201773793[39] = 0.0;
   out_6196860334201773793[40] = 1.0;
   out_6196860334201773793[41] = 0.0;
   out_6196860334201773793[42] = 0.0;
   out_6196860334201773793[43] = 0.0;
   out_6196860334201773793[44] = 0.0;
   out_6196860334201773793[45] = 0.0;
   out_6196860334201773793[46] = 0.0;
   out_6196860334201773793[47] = 0.0;
   out_6196860334201773793[48] = 0.0;
   out_6196860334201773793[49] = 0.0;
   out_6196860334201773793[50] = 1.0;
   out_6196860334201773793[51] = 0.0;
   out_6196860334201773793[52] = 0.0;
   out_6196860334201773793[53] = 0.0;
   out_6196860334201773793[54] = 0.0;
   out_6196860334201773793[55] = 0.0;
   out_6196860334201773793[56] = 0.0;
   out_6196860334201773793[57] = 0.0;
   out_6196860334201773793[58] = 0.0;
   out_6196860334201773793[59] = 0.0;
   out_6196860334201773793[60] = 1.0;
   out_6196860334201773793[61] = 0.0;
   out_6196860334201773793[62] = 0.0;
   out_6196860334201773793[63] = 0.0;
   out_6196860334201773793[64] = 0.0;
   out_6196860334201773793[65] = 0.0;
   out_6196860334201773793[66] = 0.0;
   out_6196860334201773793[67] = 0.0;
   out_6196860334201773793[68] = 0.0;
   out_6196860334201773793[69] = 0.0;
   out_6196860334201773793[70] = 1.0;
   out_6196860334201773793[71] = 0.0;
   out_6196860334201773793[72] = 0.0;
   out_6196860334201773793[73] = 0.0;
   out_6196860334201773793[74] = 0.0;
   out_6196860334201773793[75] = 0.0;
   out_6196860334201773793[76] = 0.0;
   out_6196860334201773793[77] = 0.0;
   out_6196860334201773793[78] = 0.0;
   out_6196860334201773793[79] = 0.0;
   out_6196860334201773793[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_6277255670269225220) {
   out_6277255670269225220[0] = state[0];
   out_6277255670269225220[1] = state[1];
   out_6277255670269225220[2] = state[2];
   out_6277255670269225220[3] = state[3];
   out_6277255670269225220[4] = state[4];
   out_6277255670269225220[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_6277255670269225220[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_6277255670269225220[7] = state[7];
   out_6277255670269225220[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7160284402765973969) {
   out_7160284402765973969[0] = 1;
   out_7160284402765973969[1] = 0;
   out_7160284402765973969[2] = 0;
   out_7160284402765973969[3] = 0;
   out_7160284402765973969[4] = 0;
   out_7160284402765973969[5] = 0;
   out_7160284402765973969[6] = 0;
   out_7160284402765973969[7] = 0;
   out_7160284402765973969[8] = 0;
   out_7160284402765973969[9] = 0;
   out_7160284402765973969[10] = 1;
   out_7160284402765973969[11] = 0;
   out_7160284402765973969[12] = 0;
   out_7160284402765973969[13] = 0;
   out_7160284402765973969[14] = 0;
   out_7160284402765973969[15] = 0;
   out_7160284402765973969[16] = 0;
   out_7160284402765973969[17] = 0;
   out_7160284402765973969[18] = 0;
   out_7160284402765973969[19] = 0;
   out_7160284402765973969[20] = 1;
   out_7160284402765973969[21] = 0;
   out_7160284402765973969[22] = 0;
   out_7160284402765973969[23] = 0;
   out_7160284402765973969[24] = 0;
   out_7160284402765973969[25] = 0;
   out_7160284402765973969[26] = 0;
   out_7160284402765973969[27] = 0;
   out_7160284402765973969[28] = 0;
   out_7160284402765973969[29] = 0;
   out_7160284402765973969[30] = 1;
   out_7160284402765973969[31] = 0;
   out_7160284402765973969[32] = 0;
   out_7160284402765973969[33] = 0;
   out_7160284402765973969[34] = 0;
   out_7160284402765973969[35] = 0;
   out_7160284402765973969[36] = 0;
   out_7160284402765973969[37] = 0;
   out_7160284402765973969[38] = 0;
   out_7160284402765973969[39] = 0;
   out_7160284402765973969[40] = 1;
   out_7160284402765973969[41] = 0;
   out_7160284402765973969[42] = 0;
   out_7160284402765973969[43] = 0;
   out_7160284402765973969[44] = 0;
   out_7160284402765973969[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7160284402765973969[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7160284402765973969[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7160284402765973969[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7160284402765973969[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7160284402765973969[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7160284402765973969[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7160284402765973969[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7160284402765973969[53] = -9.8100000000000005*dt;
   out_7160284402765973969[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7160284402765973969[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7160284402765973969[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7160284402765973969[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7160284402765973969[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7160284402765973969[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7160284402765973969[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7160284402765973969[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7160284402765973969[62] = 0;
   out_7160284402765973969[63] = 0;
   out_7160284402765973969[64] = 0;
   out_7160284402765973969[65] = 0;
   out_7160284402765973969[66] = 0;
   out_7160284402765973969[67] = 0;
   out_7160284402765973969[68] = 0;
   out_7160284402765973969[69] = 0;
   out_7160284402765973969[70] = 1;
   out_7160284402765973969[71] = 0;
   out_7160284402765973969[72] = 0;
   out_7160284402765973969[73] = 0;
   out_7160284402765973969[74] = 0;
   out_7160284402765973969[75] = 0;
   out_7160284402765973969[76] = 0;
   out_7160284402765973969[77] = 0;
   out_7160284402765973969[78] = 0;
   out_7160284402765973969[79] = 0;
   out_7160284402765973969[80] = 1;
}
void h_25(double *state, double *unused, double *out_8149413165682410599) {
   out_8149413165682410599[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1724477698772086012) {
   out_1724477698772086012[0] = 0;
   out_1724477698772086012[1] = 0;
   out_1724477698772086012[2] = 0;
   out_1724477698772086012[3] = 0;
   out_1724477698772086012[4] = 0;
   out_1724477698772086012[5] = 0;
   out_1724477698772086012[6] = 1;
   out_1724477698772086012[7] = 0;
   out_1724477698772086012[8] = 0;
}
void h_24(double *state, double *unused, double *out_3520377357547632824) {
   out_3520377357547632824[0] = state[4];
   out_3520377357547632824[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8378683156880271769) {
   out_8378683156880271769[0] = 0;
   out_8378683156880271769[1] = 0;
   out_8378683156880271769[2] = 0;
   out_8378683156880271769[3] = 0;
   out_8378683156880271769[4] = 1;
   out_8378683156880271769[5] = 0;
   out_8378683156880271769[6] = 0;
   out_8378683156880271769[7] = 0;
   out_8378683156880271769[8] = 0;
   out_8378683156880271769[9] = 0;
   out_8378683156880271769[10] = 0;
   out_8378683156880271769[11] = 0;
   out_8378683156880271769[12] = 0;
   out_8378683156880271769[13] = 0;
   out_8378683156880271769[14] = 1;
   out_8378683156880271769[15] = 0;
   out_8378683156880271769[16] = 0;
   out_8378683156880271769[17] = 0;
}
void h_30(double *state, double *unused, double *out_8424607227966916488) {
   out_8424607227966916488[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2803218631355522186) {
   out_2803218631355522186[0] = 0;
   out_2803218631355522186[1] = 0;
   out_2803218631355522186[2] = 0;
   out_2803218631355522186[3] = 0;
   out_2803218631355522186[4] = 1;
   out_2803218631355522186[5] = 0;
   out_2803218631355522186[6] = 0;
   out_2803218631355522186[7] = 0;
   out_2803218631355522186[8] = 0;
}
void h_26(double *state, double *unused, double *out_7417731524933937477) {
   out_7417731524933937477[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2017025620101970212) {
   out_2017025620101970212[0] = 0;
   out_2017025620101970212[1] = 0;
   out_2017025620101970212[2] = 0;
   out_2017025620101970212[3] = 0;
   out_2017025620101970212[4] = 0;
   out_2017025620101970212[5] = 0;
   out_2017025620101970212[6] = 0;
   out_2017025620101970212[7] = 1;
   out_2017025620101970212[8] = 0;
}
void h_27(double *state, double *unused, double *out_5071423692191816070) {
   out_5071423692191816070[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4977981943155947097) {
   out_4977981943155947097[0] = 0;
   out_4977981943155947097[1] = 0;
   out_4977981943155947097[2] = 0;
   out_4977981943155947097[3] = 1;
   out_4977981943155947097[4] = 0;
   out_4977981943155947097[5] = 0;
   out_4977981943155947097[6] = 0;
   out_4977981943155947097[7] = 0;
   out_4977981943155947097[8] = 0;
}
void h_29(double *state, double *unused, double *out_5020463578081789483) {
   out_5020463578081789483[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2292987287041130002) {
   out_2292987287041130002[0] = 0;
   out_2292987287041130002[1] = 1;
   out_2292987287041130002[2] = 0;
   out_2292987287041130002[3] = 0;
   out_2292987287041130002[4] = 0;
   out_2292987287041130002[5] = 0;
   out_2292987287041130002[6] = 0;
   out_2292987287041130002[7] = 0;
   out_2292987287041130002[8] = 0;
}
void h_28(double *state, double *unused, double *out_3591495587617469110) {
   out_3591495587617469110[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7375386304110660576) {
   out_7375386304110660576[0] = 1;
   out_7375386304110660576[1] = 0;
   out_7375386304110660576[2] = 0;
   out_7375386304110660576[3] = 0;
   out_7375386304110660576[4] = 0;
   out_7375386304110660576[5] = 0;
   out_7375386304110660576[6] = 0;
   out_7375386304110660576[7] = 0;
   out_7375386304110660576[8] = 0;
}
void h_31(double *state, double *unused, double *out_4511963637428388249) {
   out_4511963637428388249[0] = state[8];
}
void H_31(double *state, double *unused, double *out_2643233722335321688) {
   out_2643233722335321688[0] = 0;
   out_2643233722335321688[1] = 0;
   out_2643233722335321688[2] = 0;
   out_2643233722335321688[3] = 0;
   out_2643233722335321688[4] = 0;
   out_2643233722335321688[5] = 0;
   out_2643233722335321688[6] = 0;
   out_2643233722335321688[7] = 0;
   out_2643233722335321688[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_7499019697074073600) {
  err_fun(nom_x, delta_x, out_7499019697074073600);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8422684140360355869) {
  inv_err_fun(nom_x, true_x, out_8422684140360355869);
}
void car_H_mod_fun(double *state, double *out_6196860334201773793) {
  H_mod_fun(state, out_6196860334201773793);
}
void car_f_fun(double *state, double dt, double *out_6277255670269225220) {
  f_fun(state,  dt, out_6277255670269225220);
}
void car_F_fun(double *state, double dt, double *out_7160284402765973969) {
  F_fun(state,  dt, out_7160284402765973969);
}
void car_h_25(double *state, double *unused, double *out_8149413165682410599) {
  h_25(state, unused, out_8149413165682410599);
}
void car_H_25(double *state, double *unused, double *out_1724477698772086012) {
  H_25(state, unused, out_1724477698772086012);
}
void car_h_24(double *state, double *unused, double *out_3520377357547632824) {
  h_24(state, unused, out_3520377357547632824);
}
void car_H_24(double *state, double *unused, double *out_8378683156880271769) {
  H_24(state, unused, out_8378683156880271769);
}
void car_h_30(double *state, double *unused, double *out_8424607227966916488) {
  h_30(state, unused, out_8424607227966916488);
}
void car_H_30(double *state, double *unused, double *out_2803218631355522186) {
  H_30(state, unused, out_2803218631355522186);
}
void car_h_26(double *state, double *unused, double *out_7417731524933937477) {
  h_26(state, unused, out_7417731524933937477);
}
void car_H_26(double *state, double *unused, double *out_2017025620101970212) {
  H_26(state, unused, out_2017025620101970212);
}
void car_h_27(double *state, double *unused, double *out_5071423692191816070) {
  h_27(state, unused, out_5071423692191816070);
}
void car_H_27(double *state, double *unused, double *out_4977981943155947097) {
  H_27(state, unused, out_4977981943155947097);
}
void car_h_29(double *state, double *unused, double *out_5020463578081789483) {
  h_29(state, unused, out_5020463578081789483);
}
void car_H_29(double *state, double *unused, double *out_2292987287041130002) {
  H_29(state, unused, out_2292987287041130002);
}
void car_h_28(double *state, double *unused, double *out_3591495587617469110) {
  h_28(state, unused, out_3591495587617469110);
}
void car_H_28(double *state, double *unused, double *out_7375386304110660576) {
  H_28(state, unused, out_7375386304110660576);
}
void car_h_31(double *state, double *unused, double *out_4511963637428388249) {
  h_31(state, unused, out_4511963637428388249);
}
void car_H_31(double *state, double *unused, double *out_2643233722335321688) {
  H_31(state, unused, out_2643233722335321688);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
